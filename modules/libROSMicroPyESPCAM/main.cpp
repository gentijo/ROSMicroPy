#include "esp_camera.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>
#include <micro_ros_utilities/string_utilities.h>
#include <micro_ros_utilities/type_utilities.h>
#include <rosidl_typesupport_introspection_c/message_introspection.h>

#include <sensor_msgs/msg/compressed_image.h>

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc); return;}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}
#define RUNWAIT(fn) {fn; delay(10);}
#define RUNWAIT_LONG(fn) {fn; delay(100);}


#define CAMERA_MODEL_AI_THINKER // Has PSRAM
#include "camera_pins.h"
#define ledPin      4

extern rclc_executor_t executor;
extern rcl_allocator_t allocator;
extern rclc_support_t support;
extern rcl_node_t node;

rcl_timer_t timer;
rcl_publisher_t img_publisher;
sensor_msgs__msg__CompressedImage img_msg;

const rosidl_message_type_support_t * type_support = ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage);

struct timespec ts;
extern int clock_gettime(clockid_t unused, struct timespec *tp);

unsigned int num_handles = 1;   // 1 subscriber, 1 publisher, 1 server

void blink_esp32_led() {
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, HIGH);
//  delay(300);
// digitalWrite(ledPin, LOW);
}

size_t _jpg_buf_len = 0;
uint8_t * _jpg_buf = NULL;

void timer_callback(rcl_timer_t * timer, int64_t last_call_time) {
  RCLC_UNUSED(last_call_time);
  if (timer != NULL) {
    camera_fb_t *img =  esp_camera_fb_get();

    if (img != NULL)
    {
      img_msg.data.size = img->len;
      clock_gettime(CLOCK_REALTIME, &ts);
      img_msg.header.stamp.sec = ts.tv_sec;
      img_msg.header.stamp.nanosec = ts.tv_nsec;
      img_msg.header.frame_id = micro_ros_string_utilities_set(img_msg.header.frame_id, "cam_frame");
      img_msg.format = micro_ros_string_utilities_set(img_msg.format, "jpeg");
      memcpy(img_msg.data.data, img->buf, img->len);
      
      // bool jpeg_converted = frame2jpg(img, 80, &_jpg_buf, &_jpg_buf_len);
      // if (jpeg_converted) {
      //   uint8_t (*ptr)[_jpg_buf_len];
      //   ptr = (uint8_t(*)[_jpg_buf_len])_jpg_buf;
      //   img_msg.data.data = *ptr;
      // }
      // img_msg.data.data = (uint8_t *) img->buf;
      RCSOFTCHECK(rcl_publish(&img_publisher, &img_msg, NULL));
      esp_camera_fb_return(img);
      free(_jpg_buf);
    }
  }
}

void setup() {
  // WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
  // Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // Serial.println();

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;config.fb_count = 2;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_UXGA;
  config.pixel_format = PIXFORMAT_JPEG; // for streaming
  //config.pixel_format = PIXFORMAT_RGB565; // for face detection/recognition
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 1;
  config.fb_count = 2;
  
  // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
  //                      for larger pre-allocated frame buffer.
  if(config.pixel_format == PIXFORMAT_JPEG){
  //  if(psramFound()){
      config.jpeg_quality = 10;
      config.fb_count = 2;
      config.grab_mode = CAMERA_GRAB_LATEST;
  //  } else {
      // Limit the frame size when PSRAM is not available
  //    config.frame_size = FRAMESIZE_SVGA;
  //    config.fb_count = 1;
  //    config.fb_location = CAMERA_FB_IN_DRAM;
  //  }
  } else {
    // Best option for face detection/recognition
    config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    config.fb_count = 2;
#endif
  }

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    // Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1); // flip it back
    s->set_brightness(s, 1); // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  if(config.pixel_format == PIXFORMAT_JPEG){
    s->set_framesize(s, FRAMESIZE_QVGA);
  }

  //allocator = rcl_get_default_allocator();

  // Init node
  // RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  // RCCHECK(rclc_node_init_default(&node, "esp32cam", "", &support));

  // create publisher and subscriber
  RCCHECK(rclc_publisher_init_default(&img_publisher, &node, type_support, "esp32_img/compressed"));

  // create timer,
  const unsigned int timer_timeout = 10;
  RCCHECK(rclc_timer_init_default(&timer, &support, RCL_MS_TO_NS(timer_timeout), timer_callback));

  // create executor, one for publisher and one for subscriber.
  // RCCHECK(rclc_executor_init(&executor, &support.context, num_handles, &allocator));
  // RCCHECK(rclc_executor_add_timer(&executor, &timer));

  static micro_ros_utilities_memory_conf_t conf = {};

	// OPTIONALLY this struct can configure the default size of strings, basic sequences and composed sequences

	conf.max_string_capacity = 50;
	conf.max_ros2_type_sequence_capacity = 5;
	conf.max_basic_type_sequence_capacity = 5;

	// OPTIONALLY this struct can store rules for specific members
	// !! Using the API with rules will use dynamic memory allocations for handling strings !!

	micro_ros_utilities_memory_rule_t rules[] = {
		{"header.frame_id", 30},
		{"format",4},
		{"data", 80000}
	};
	conf.rules = rules;
	conf.n_rules = sizeof(rules) / sizeof(rules[0]);
	
	micro_ros_utilities_create_message_memory(
		ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage),
		&img_msg,
		conf
	);

  // Blink LED once the server is up
  blink_esp32_led();
}

