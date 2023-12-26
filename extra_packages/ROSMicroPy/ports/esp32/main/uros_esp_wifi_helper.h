#ifndef __UROS_ESP_WIFI_HELPERS_H__
#define __UROS_ESP_WIFI_HELPERS_H__

#include "py/runtime.h"
#include "py/mpconfig.h"

mp_obj_t set_ROS_Wifi_Config(mp_obj_t sta_id, mp_obj_t pass);

#endif