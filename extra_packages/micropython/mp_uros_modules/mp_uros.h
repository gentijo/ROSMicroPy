#ifndef __MP_UROS_H__
#define __MP_UROS_H__


#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"

#include "py/runtime.h"
#include "py/gc.h"
#include "mphalport.h"
#include "py/mpthread.h"
#include "py/mpconfig.h"
#include "py/stackctrl.h"

#include "shared/runtime/pyexec.h"

// extern QueueHandle_t 	mp_uros_queue;

mp_obj_t publishMsg(mp_obj_t a_obj, mp_obj_t b_obj);
mp_obj_t registerEventSubscription(mp_obj_t eventName, mp_obj_t eventType, mp_obj_t eventCallback);
mp_obj_t init_ros_mp_event_system(void);
mp_obj_t readROSMsg();
mp_obj_t init_event_queue(void);
#endif