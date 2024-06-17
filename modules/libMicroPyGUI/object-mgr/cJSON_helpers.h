#ifndef __CJSON_HELPERS_H__
#define __CJSON_HELPERS_H__


extern "C" {
#include <stdio.h>
#include <string.h>

#include "py/obj.h"
#include "py/runtime.h"

#include "cJSON.h"
}

bool getcJSON_IntProperty(const cJSON *properties, const char *name, int* retVal);
bool getcJSON_StringProperty(const cJSON *properties, const char *name, char ** retVal);

#endif
