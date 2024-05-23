/**
 * @file disp_backlight.h
 */

#ifndef __MP_HELPERS_H__
#define __MP_HELPERS_H__

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "py/obj.h"
#include "py/runtime.h"

#ifdef __cplusplus
extern "C" { /* extern "C" */
#endif
mp_map_elem_t*  getElementFromMap(mp_map_t *dataMap, mp_obj_t fieldName);
const char*     getStrFieldFromMap(mp_map_t *dataMap, mp_obj_t fieldName);
mp_obj_list_t   getListFieldFromMap(mp_map_t *dataMap, mp_obj_t fieldName);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif 