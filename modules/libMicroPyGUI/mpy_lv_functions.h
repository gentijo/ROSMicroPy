#ifndef __MPY_LV_FUNCS_H__
#define __MPY_LV_FUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "py/runtime.h"
#include "py/obj.h"

mp_obj_t create_LvObject(
    const mp_obj_t typeIn, const mp_obj_t scopeIn, const mp_obj_t nameIn, 
    const mp_obj_t propertiesIn, const mp_obj_t parentIn);

mp_obj_t  add_LvObjectFactory(const mp_obj_t* f);

#ifdef __cplusplus
}
#endif

#endif


