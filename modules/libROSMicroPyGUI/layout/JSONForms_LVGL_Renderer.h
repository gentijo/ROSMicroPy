#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "py/runtime.h"
#include "py/obj.h"


mp_obj_t     getListFieldFromMap(mp_map_t *dataMap, mp_obj_t fieldName);
const char * getStrFieldFromMap(mp_map_t *dataMap, mp_obj_t fieldName);
