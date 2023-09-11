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

mp_obj_t    init_ROS_System();
mp_obj_t    registerEventSubscription(mp_obj_t eventName, mp_obj_t eventType, mp_obj_t eventCallback);
mp_obj_t    publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data);

void        dispatch_ROSMsg();


mp_obj_t readObjFromThread();
mp_obj_t createObjFromThread();

#endif