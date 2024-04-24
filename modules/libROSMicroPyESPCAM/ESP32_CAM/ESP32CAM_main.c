
#include "esp_camera.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <micro_ros_utilities/string_utilities.h>
#include <micro_ros_utilities/type_utilities.h>

#include <rosidl_typesupport_introspection_c/message_introspection.h>

#include <std_msgs/msg/int32.h>
#include <sensor_msgs/msg/compressed_image.h>

#include "py/runtime.h"
#include "py/mpconfig.h"
#include "mp_uros_sdk.h"

#define RCCHECK(fn)                                                                \
  {                                                                                \
    rcl_ret_t temp_rc = fn;                                                        \
    if ((temp_rc != RCL_RET_OK))                                                   \
    {                                                                              \
      printf("Failed status on line %d: %d. Aborting.\n", __LINE__, (int)temp_rc); \
      return;                                                                      \
    }                                                                              \
  }
#define RCSOFTCHECK(fn)                                                              \
  {                                                                                  \
    rcl_ret_t temp_rc = fn;                                                          \
    if ((temp_rc != RCL_RET_OK))                                                     \
    {                                                                                \
      printf("Failed status on line %d: %d. Continuing.\n", __LINE__, (int)temp_rc); \
    }                                                                                \
  }
#define RUNWAIT(fn) \
  {                 \
    fn;             \
    delay(10);      \
  }
#define RUNWAIT_LONG(fn) \
  {                      \
    fn;                  \
    delay(100);          \
  }

#define ledPin 4

#define BOARD_ESP32CAM_AITHINKER 1

// WROVER-KIT PIN Map
#ifdef BOARD_WROVER_KIT

#define CAM_PIN_PWDN -1  // power down is not used
#define CAM_PIN_RESET -1 // software reset will be performed
#define CAM_PIN_XCLK 21
#define CAM_PIN_SIOD 26
#define CAM_PIN_SIOC 27

#define CAM_PIN_D7 35
#define CAM_PIN_D6 34
#define CAM_PIN_D5 39
#define CAM_PIN_D4 36
#define CAM_PIN_D3 19
#define CAM_PIN_D2 18
#define CAM_PIN_D1 5
#define CAM_PIN_D0 4
#define CAM_PIN_VSYNC 25
#define CAM_PIN_HREF 23
#define CAM_PIN_PCLK 22

#endif

// ESP32Cam (AiThinker) PIN Map
#ifdef BOARD_ESP32CAM_AITHINKER

#define CAM_PIN_PWDN 32
#define CAM_PIN_RESET -1 // software reset will be performed
#define CAM_PIN_XCLK 0
#define CAM_PIN_SIOD 26
#define CAM_PIN_SIOC 27

#define CAM_PIN_D7 35
#define CAM_PIN_D6 34
#define CAM_PIN_D5 39
#define CAM_PIN_D4 36
#define CAM_PIN_D3 21
#define CAM_PIN_D2 19
#define CAM_PIN_D1 18
#define CAM_PIN_D0 5
#define CAM_PIN_VSYNC 25
#define CAM_PIN_HREF 23
#define CAM_PIN_PCLK 22

#endif

rcl_timer_t timer;
rcl_publisher_t img_publisher;
sensor_msgs__msg__CompressedImage img_msg;

// rosidl_message_type_support_t *type_support;

struct timespec ts;
extern int clock_gettime(clockid_t unused, struct timespec *tp);

unsigned int num_handles = 1; // 1 subscriber, 1 publisher, 1 server

static camera_config_t camera_config = {
    .pin_pwdn = CAM_PIN_PWDN,
    .pin_reset = CAM_PIN_RESET,
    .pin_xclk = CAM_PIN_XCLK,
    .pin_sccb_sda = CAM_PIN_SIOD,
    .pin_sccb_scl = CAM_PIN_SIOC,

    .pin_d7 = CAM_PIN_D7,
    .pin_d6 = CAM_PIN_D6,
    .pin_d5 = CAM_PIN_D5,
    .pin_d4 = CAM_PIN_D4,
    .pin_d3 = CAM_PIN_D3,
    .pin_d2 = CAM_PIN_D2,
    .pin_d1 = CAM_PIN_D1,
    .pin_d0 = CAM_PIN_D0,
    .pin_vsync = CAM_PIN_VSYNC,
    .pin_href = CAM_PIN_HREF,
    .pin_pclk = CAM_PIN_PCLK,
    .xclk_freq_hz = 20000000,
    .frame_size = FRAMESIZE_UXGA,
    .pixel_format = PIXFORMAT_JPEG, // for streaming
    // config.pixel_format = PIXFORMAT_RGB565; // for face detection/recognition
    .grab_mode = CAMERA_GRAB_WHEN_EMPTY,
    .fb_location = CAMERA_FB_IN_PSRAM,
    .jpeg_quality = 1,
    .fb_count = 2,

};

void blink_esp32_led()
{
  //  pinMode(ledPin, OUTPUT);
  //  digitalWrite(ledPin, HIGH);
  //  delay(300);
  // digitalWrite(ledPin, LOW);
}

size_t _jpg_buf_len = 0;
uint8_t *_jpg_buf = NULL;

void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  printf("Timer callback\r\n");
  RCLC_UNUSED(last_call_time);
  if (timer != NULL)
  {
    camera_fb_t *img = esp_camera_fb_get();

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
      printf("Publish Image\r\n");
      RCSOFTCHECK(rcl_publish(&img_publisher, &img_msg, NULL));
      esp_camera_fb_return(img);
      free(_jpg_buf);
    }
  }
}

static mp_obj_t rmp_cam_init(void)
{
  // for larger pre-allocated frame buffer.
  if (camera_config.pixel_format == PIXFORMAT_JPEG)
  {
    camera_config.jpeg_quality = 10;
    camera_config.fb_count = 2;
    camera_config.grab_mode = CAMERA_GRAB_LATEST;
  }
  else
  {
    // Best option for face detection/recognition
    camera_config.frame_size = FRAMESIZE_240X240;
#if CONFIG_IDF_TARGET_ESP32S3
    camera_config.fb_count = 2;
#endif
  }

  // initialize the camera
  esp_err_t err = esp_camera_init(&camera_config);
  if (err != ESP_OK)
  {
    printf("\r\nCamera Init Failed\r\n");
    return mp_const_none;
  }

  printf("Camera Init Success\r\n");
  return mp_const_none;
}

mp_obj_t rmp_cam_takepic(void)
{
  printf("Taking picture...\r\n");
  camera_fb_t *pic = esp_camera_fb_get();

  // use pic->buf to access the image
  printf("Picture taken! Its size was: %zu bytes\r\n", pic->len);
  esp_camera_fb_return(pic);

  return mp_const_none;
}

mp_obj_t rmp_cam_start()
{
  int rc;
  // create publisher and subscriber
  printf("Pub Init\r\n");
  rc = rclc_publisher_init_default(&img_publisher, &rmp_rcl_node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage), "image/compressed");
  if (rc != RCL_RET_OK)
  {
    printf("Failed to init pub %d\r\n", rc);
  }

  // create timer,
  printf("Timer Init\r\n");
  const unsigned int timer_timeout = 1000;
  rc = rclc_timer_init_default(&timer, &rmp_rclc_support, RCL_MS_TO_NS(timer_timeout), timer_callback);
  if (rc != RCL_RET_OK)
  {
    printf("Failed to init Timer\r\n");
  }

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
  if (camera_config.pixel_format == PIXFORMAT_JPEG)
  {
    s->set_framesize(s, FRAMESIZE_QVGA);
  }

  static micro_ros_utilities_memory_conf_t conf = {};

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

  // Blink LED once the server is up
  blink_esp32_led();

  return mp_const_none;
}

/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 *
 */

MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_init_obj, rmp_cam_init);
MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_start_obj, rmp_cam_start);
MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_takepic_obj, rmp_cam_takepic);

/**
 * Register the microros class and map the functions from Micropython to MicroROS
 */
const mp_rom_map_elem_t mp_uros_cam_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPyCAM)},

    {MP_ROM_QSTR(MP_QSTR_rmp_cam_init), MP_ROM_PTR(&rmp_cam_init_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_cam_takepic), MP_ROM_PTR(&rmp_cam_takepic_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_cam_start), MP_ROM_PTR(&rmp_cam_start_obj)}};

MP_DEFINE_CONST_DICT(mp_uros_cam_module_globals, mp_uros_cam_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_cam_user_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_uros_cam_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_ROSMicroPyCAM, mp_uros_cam_user_cmodule);
