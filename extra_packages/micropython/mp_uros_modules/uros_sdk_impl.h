#ifndef __MP_SDK_IMPL_H__
#define __MP_SDK_IMPL_H__

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "rcl/rcl.h"
#include "rcl/error_handling.h"
#include "rclc/rclc.h"
#include "rclc/executor.h"

#include "py/runtime.h"
#include "py/gc.h"
#include "mphalport.h"
#include "py/mpthread.h"
#include "py/mpconfig.h"
#include "py/stackctrl.h"

#include "shared/runtime/pyexec.h"



void service_callback(const void *resp, const void *context);
ros_subscription* get_ROS_Sub_from_slot(int slot);

void dispatch_ROSMsg();

#endif