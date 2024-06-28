#ifndef __espcam_server_h__
#define __espcam_server_h__

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
#include "rmp_cam_common.h"

#define CAMERA_MODEL_ESP32S3_EYE 1
#include "freenoveS3_pins.h"


void service_callback(const void *req, void *res);
void init_camera_service();

#endif