#define CAMERA_MODEL_ESP32S3_EYE 1

#include "rmp_cam_publisher.h"
#include "sdkconfig.h"

#include <micro_ros_utilities/string_utilities.h>
#include <micro_ros_utilities/type_utilities.h>

#include <sensor_msgs/msg/compressed_image.h>
#include <std_msgs/msg/header.h>
#include <rosidl_typesupport_introspection_c/message_introspection.h>

#include "py/runtime.h"
#include "py/mpconfig.h"

#include "mp_uros_sdk.h"

#include "esp_camera.h"
#include "../freenoveS3_pins.h"
#include "../rmp_cam_common.h"


#define ledPin 4

rcl_timer_t                       espcam_timer;
rcl_publisher_t                   img_publisher;
sensor_msgs__msg__CompressedImage img_msg;
micro_ros_utilities_memory_conf_t conf = {};

struct timespec ts;
extern int clock_gettime(clockid_t unused, struct timespec *tp);

void init_camera_service();

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



void init_image_Publisher()
{
  int rc;
 
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