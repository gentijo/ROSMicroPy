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

#define DEBUG 0

#if DEBUG
#define DEBUG_printf(...) ESP_LOGI("ros_mp_thread", __VA_ARGS__)
#else
#define DEBUG_printf(...) (void)0
#endif


#define RCCHECK(fn)                                                                      \
	{                                                                                    \
		rcl_ret_t temp_rc = fn;                                                          \
		if ((temp_rc != RCL_RET_OK))                                                     \
		{                                                                                \
			printf("Failed status on line %d: %d. Aborting.\n", __LINE__, (int)temp_rc); \
			vTaskDelete(NULL);                                                           \
		}                                                                                \
	}

#define RCSOFTCHECK(fn)                                                                    \
	{                                                                                      \
		rcl_ret_t temp_rc = fn;                                                            \
		if ((temp_rc != RCL_RET_OK))                                                       \
		{                                                                                  \
			printf("Failed status on line %d: %d. Continuing.\n", __LINE__, (int)temp_rc); \
		}                                                                                  \
	}


typedef struct _ros_subscription
{
    int index;
    mp_obj_t eventName;
    mp_obj_t eventType;
    void *resp;
    mp_obj_t mpEventCallback;

    rcl_subscription_t rcl_service_subscription;

} ros_subscription;

ros_subscription* get_ROS_Sub_from_slot(int slot);

void dispatch_ROSMsg();

void init_event_subscription_callbacks();

mp_obj_t publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data);

mp_obj_t registerEventSubscription(
    mp_obj_t eventName,
    mp_obj_t eventType,
    mp_obj_t eventCallback);


#endif