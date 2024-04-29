#include "esp_camera.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include "py/runtime.h"
#include "py/mpconfig.h"
#include "mp_uros_sdk.h"

mp_obj_t rmp_cam_init(void);
mp_obj_t rmp_cam_set_topic_name(mp_obj_t obj_in);
mp_obj_t rmp_publish_cam_image();
mp_obj_t rmp_cam_takepic(void);
mp_obj_t rmp_cam_start();


