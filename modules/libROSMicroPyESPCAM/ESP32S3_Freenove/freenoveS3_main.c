#define CAMERA_MODEL_ESP32S3_EYE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "esp_camera.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <micro_ros_utilities/string_utilities.h>
#include <micro_ros_utilities/type_utilities.h>


#include <sensor_msgs/msg/compressed_image.h>
#include <std_msgs/msg/header.h>
#include <rosidl_typesupport_introspection_c/message_introspection.h>

#include "py/runtime.h"
#include "py/mpconfig.h"
#include "mp_uros_sdk.h"
#include "sdkconfig.h"
#include "freenoveS3_pins.h"

#define ledPin 4

rcl_timer_t                       espcam_timer;
rcl_publisher_t                   img_publisher;
sensor_msgs__msg__CompressedImage img_msg;
micro_ros_utilities_memory_conf_t conf = {};
rcl_service_t                    service;
std_msgs__msg__Header            req_header;
std_msg__srv__Header_Response    a;

char    CAM_TopicName[32] = "image/compressed";

struct timespec ts;
extern int clock_gettime(clockid_t unused, struct timespec *tp);

void init_camera_service();

camera_config_t config;

mp_obj_t rmp_cam_init(void)
{
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.frame_size = FRAMESIZE_QVGA;
  config.pixel_format = PIXFORMAT_JPEG; // for streaming
  config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;
  config.fb_location = CAMERA_FB_IN_PSRAM;
  config.jpeg_quality = 12;
  config.fb_count = 1;

  config.jpeg_quality = 10;
  config.fb_count = 2;
  config.grab_mode = CAMERA_GRAB_LATEST;

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK)
  {
    printf("Camera init failed with error 0x%x", err);
    return mp_const_none;
  }

  sensor_t *s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  s->set_vflip(s, 1);      // flip it back
  s->set_brightness(s, 1); // up the brightness just a bit
  s->set_saturation(s, 0); // lower the saturation

  printf("Camera configuration complete!\r\n");
  return mp_const_none;
}

void blink_esp32_led()
{
  //  pinMode(ledPin, OUTPUT);
  //  digitalWrite(ledPin, HIGH);
  //  delay(300);
  // digitalWrite(ledPin, LOW);
}


/** 
 * 
 * 
*/
mp_obj_t rmp_cam_set_topic_name(mp_obj_t obj_in)
{
    if (&mp_type_str != mp_obj_get_type(obj_in)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Topic name must be a str"));
		return obj_in;
    }

    const char* cstr = mp_obj_str_get_str(obj_in);
    if ((cstr == NULL) || strlen(cstr)==0) {
		mp_raise_ValueError(MP_ERROR_TEXT("Topic must be a string"));
		return obj_in;
    }

	strncpy(CAM_TopicName, cstr, 31);
	return obj_in;
}


/***
 * 
 * 
 * 
*/
size_t _jpg_buf_len = 0;
//uint8_t *_jpg_buf = NULL;
int x = 0;

void publish_cam_image()
{

  camera_fb_t *img = esp_camera_fb_get();

  if (img != NULL)
  {
    int len = img->len;
    //  len=20;
    img_msg.data.size = len;
    clock_gettime(CLOCK_REALTIME, &ts);
    img_msg.header.stamp.sec = ts.tv_sec;
    img_msg.header.stamp.nanosec = ts.tv_nsec;
    img_msg.header.frame_id = micro_ros_string_utilities_set(img_msg.header.frame_id, "cam_frame");
    img_msg.format = micro_ros_string_utilities_set(img_msg.format, "jpeg");
    memcpy(img_msg.data.data, img->buf, len);

    // bool jpeg_converted = frame2jpg(img, 80, &_jpg_buf, &_jpg_buf_len);
    // if (jpeg_converted) {
    //   uint8_t (*ptr)[_jpg_buf_len];
    //   ptr = (uint8_t(*)[_jpg_buf_len])_jpg_buf;
    //   img_msg.data.data = *ptr;
    // }
    // img_msg.data.data = (uint8_t *) img->buf;

    RCSOFTCHECK(rcl_publish(&img_publisher, &img_msg, NULL));

    x++; 
    if ((x%20) == 0) printf("20 Frames Size: %d\r\n", img->len);
    
    esp_camera_fb_return(img);
    // free(_jpg_buf);
  }
}



/***
 * 
 * 
 * 
*/
void cam_timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  RCLC_UNUSED(last_call_time);
  if (timer != NULL)
  {
    publish_cam_image();
  }
}


/**
 * 
 * 
 * 
*/
mp_obj_t rmp_publish_cam_image()
{
  publish_cam_image();
  return mp_const_none;
}

/**
 * 
 * 
 * 
*/
mp_obj_t rmp_cam_takepic(void)
{
  printf("Taking picture...\r\n");
  camera_fb_t *pic = esp_camera_fb_get();

  // use pic->buf to access the image
  printf("Picture taken! Its size was: %zu bytes\r\n", pic->len);
  esp_camera_fb_return(pic);

  return mp_const_none;
}

/**
 * 
 * 
 * 
 * 
*/
mp_obj_t rmp_cam_start()
{
  printf("\r\nESP Sensor get\r\n");
  sensor_t *s = esp_camera_sensor_get();
  // initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID)
  {
    s->set_vflip(s, 1);       // flip it back
    s->set_brightness(s, 1);  // up the brightness just a bit
    s->set_saturation(s, -2); // lower the saturation
  }
  // drop down frame size for higher initial frame rate
  if (config.pixel_format == PIXFORMAT_JPEG)
  {
    s->set_framesize(s, FRAMESIZE_96X96); //FRAMESIZE_QVGA);
  }

 

  // OPTIONALLY this struct can configure the default size of strings, basic sequences and composed sequences

  conf.max_string_capacity = 50;
  conf.max_ros2_type_sequence_capacity = 5;
  conf.max_basic_type_sequence_capacity = 5;

  // OPTIONALLY this struct can store rules for specific members
  // !! Using the API with rules will use dynamic memory allocations for handling strings !!

  micro_ros_utilities_memory_rule_t rules[] = {
      {"header.frame_id", 30},
      {"format", 4},
      {"data", 80000}};
  conf.rules = rules;
  conf.n_rules = sizeof(rules) / sizeof(rules[0]);

  printf("Create Message Memory\r\n");
  micro_ros_utilities_create_message_memory(
      ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage),
      &img_msg,
      conf);

  init_camera_service();

  return mp_const_none;
}


void service_callback(const void *req, void *res)
{
  const std_msgs__msg__Header *request = (const std_msgs__msg__Header *)req;
  sensor_msgs__msg__CompressedImage *response = &img_msg;

  printf("Received request with frame_id: %s\n", request->frame_id.data);

  camera_fb_t *img = esp_camera_fb_get();

  if (img != NULL)
  {
    int len = img->len;
    //  len=20;
    img_msg.data.size = len;
    clock_gettime(CLOCK_REALTIME, &ts);
    img_msg.header.stamp.sec = ts.tv_sec;
    img_msg.header.stamp.nanosec = ts.tv_nsec;
    img_msg.header.frame_id = micro_ros_string_utilities_set(img_msg.header.frame_id, "cam_frame");
    img_msg.format = micro_ros_string_utilities_set(img_msg.format, "jpeg");
    memcpy(img_msg.data.data, img->buf, len);

  }
}

void init_camera_service()
{

  service = rcl_get_zero_initialized_service();
  rclc_service_init_default(
    &service,
    &rmp_rcl_node,
    ROSIDL_GET_SRV_TYPE_SUPPORT(std_msgs, msg, Header),
    CAM_TopicName);
  
  rclc_executor_add_service(
    &rmp_rclc_executor, &service, 
    &req_header,
    &img_msg, 
    service_callback);

  printf("Image service server is ready.\n");
}

void init_image_Publisher()
{
  int rc;

  // create timer,
  const unsigned int timer_timeout = 2000;
  rc = rclc_timer_init_default(&espcam_timer, &rmp_rclc_support, RCL_MS_TO_NS(timer_timeout), cam_timer_callback);
  if (rc != RCL_RET_OK)
  {
    printf("Failed to init Timer\r\n");
  }
  RCCHECK(rclc_executor_add_timer(&rmp_rclc_executor, &espcam_timer));


  // create publisher 
  rc = rclc_publisher_init_default(&img_publisher, &rmp_rcl_node,
          ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage), 
          CAM_TopicName);
  
  if (rc != RCL_RET_OK)
  {
    printf("Failed to init pub %d\r\n", rc);
  }
}