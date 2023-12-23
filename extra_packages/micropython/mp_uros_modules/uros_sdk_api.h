
#ifndef __UROS_SDK_API_H__
#define __UROS_SDK_API_H__

#include "py/runtime.h"
#include "py/mpconfig.h"

#include "rcl/rcl.h"
#include "rcl/error_handling.h"
#include "rclc/rclc.h"
#include "rclc/executor.h"


typedef struct _ros_subscription
{
    int index;
    mp_obj_t eventName;
    mp_obj_t eventType;
    void *resp;
    mp_obj_t mpEventCallback;

    rcl_subscription_t rcl_service_subscription;

} ros_subscription;

mp_obj_t mp_init_ROS_Stack();
mp_obj_t mp_run_ROS_Stack();

mp_obj_t registerEventSubscription(mp_obj_t eventName, mp_obj_t eventType, mp_obj_t eventCallback);
mp_obj_t publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data);


#endif