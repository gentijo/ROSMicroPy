#ifndef __UROS_BASE_FUNC_H__
#define __UROS_BASE_FUNC_H__

#include "py/runtime.h"
#include "py/obj.h"

#include "rcl/rcl.h"
#include "rcl/error_handling.h"
#include "rclc/rclc.h"
#include "rclc/executor.h"



mp_obj_t init_ROS_Stack();
void     run_ROS_Stack();

void init_event_subscription_callbacks();

void add_ROS_service_Listener(ros_subscription* sub);
void service_callback(const void *response, void *context);


mp_obj_t mp_run_ROS_Stack();
mp_obj_t mp_init_ROS_Stack();

#endif
