
#define CAMERA_MODEL_ESP32S3_EYE 1

#include "esp_camera.h"
#include "sdkconfig.h"

//#include <micro_ros_utilities/string_utilities.h>
//#include <micro_ros_utilities/type_utilities.h>

#include <sensor_msgs/msg/compressed_image.h>
#include <std_msgs/msg/header.h>
#include <rosidl_typesupport_introspection_c/message_introspection.h>

#include "py/runtime.h"
#include "py/mpconfig.h"

#include "mp_uros_sdk.h"
#include "freenoveS3_pins.h"

#include "publisher/rmp_cam_publisher.h"

char    CAM_TopicName[32] = "image/compressed";

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

  printf("\r\nESP Sensor get\r\n");
  sensor_t *s = esp_camera_sensor_get();

  // initial sensors are flipped vertically and colors are a bit saturated
  s->set_vflip(s, 1);      // flip it back
  s->set_brightness(s, 1); // up the brightness just a bit
  s->set_saturation(s, 0); // lower the saturation


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
    s->set_framesize(s, FRAMESIZE_QVGA);
  }


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




/**
 * 
 * 
 * 
*/
mp_obj_t rmp_publish_cam_image()
{
  // publish_cam_image();
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

