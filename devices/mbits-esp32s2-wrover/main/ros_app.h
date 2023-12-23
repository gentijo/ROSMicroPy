#ifndef __ROS_APP_H__
#define __ROS_APP_H__

#include "sdkconfig.h"
#include "uros_sdk_api.h"


void init_ROS_Stack();
void run_ROS_Stack();

void add_ROS_service_Listener(ros_subscription* sub);

#endif