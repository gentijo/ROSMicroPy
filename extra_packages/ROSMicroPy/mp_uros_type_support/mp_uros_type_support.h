#ifndef __MP_UROS_TYPE_SUPPORT_H__
#define __MP_UROS_TYPE_SUPPORT_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "mp_uros_type_support_visibility_control.h"

#include "uros_sdk.h"

#include "mp_uros_dataTypeParser.h"

#include <ucdr/microcdr.h>
#include "py/obj.h"

#define MICROXRCEDDS_PADDING sizeof(uint32_t)


void init_mpy_ROS_TypeSupport(void); 
dxc_cb_t* findAvailTypeSlot();
dxc_cb_t* findTypeByName(const char *type);


void serializeBool(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void deserializeBool(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void serializeInt(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void deserializeInt(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void serializeFloat(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void deserializeFloat(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);

void deserializeDouble(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void serializeDouble(int slot, ucdrBuffer *cdr,   dxi_t* inst,  mp_obj_stk_t *obj_stack);

void deserializeROSType(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);
void serializeROSType(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack);


#endif