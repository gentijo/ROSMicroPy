#ifndef __MP_UROS_TYPE_SUPPORT_H__
#define __MP_UROS_TYPE_SUPPORT_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "mp_uros_type_support_visibility_control.h"
#include "mp_uros.h"
//#include "common_internal.h"
#include <ucdr/microcdr.h>
#include "py/obj.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

#define cnt_ros_type_support_slots 25
extern rosidl_message_type_support_t* mpy_uros_type_support_slots[cnt_ros_type_support_slots];
void init_mpy_uros_typesupport(void); 

#endif