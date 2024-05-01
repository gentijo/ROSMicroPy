#pragma once

#include "rmp_widget.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

// #include <micro_ros_utilities/string_utilities.h>
// #include <micro_ros_utilities/type_utilities.h>

#include <sensor_msgs/msg/compressed_image.h>

void init(char *topicName);
