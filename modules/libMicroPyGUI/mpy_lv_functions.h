#pragma once

extern "C" {
#include "py/runtime.h"
#include "py/obj.h"
#include "cJSON.h"
}

#include "mpy_LvObject.h"
#include "mpy_LvObjectFactory.h"
#include "mpy_LvBaseObjects.h"


mpy_LvObject*  createLvObject(mp_obj_t type, mp_obj_t scope, mp_obj_t name, mp_obj_t properties, mp_obj_t parent);
void           add_LvObjectFactory(mpy_LvObjectFactory* f);

