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
mp_obj_t mp_dumpDataType(mp_obj_t dataTypeName);


mp_obj_t mp_run_ROS_Stack();
mp_obj_t mp_init_ROS_Stack();

#endif
