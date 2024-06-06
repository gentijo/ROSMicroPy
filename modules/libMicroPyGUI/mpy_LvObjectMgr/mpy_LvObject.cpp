#include "mpy_LvObject.h"

extern "C" {
#include <stdio.h>
#include <string.h>

#include "py/obj.h"
#include "py/runtime.h"
}

/***
 * 
 * 
 * 
*/
void mpy_LvObject::addLvObjectStyle(cJSON *properties)
{
    cJSON *iterator = NULL;

    cJSON_ArrayForEach(iterator, properties)
    {
        if (cJSON_IsObject(iterator))
        {

            if (strcmp(iterator->valuestring, "size"))
            {
                this->setSize(iterator);
                return;
            }
        }
    }
};

/**
 * 
 * 
 * 
*/
void mpy_LvObject::setSize(cJSON *properties)
{
    int height = this->getIntStyleProperty(properties, "height");
    int width = this->getIntStyleProperty(properties, "width");
    lv_obj_set_size(lvObject, height, width);
};

/**
 * 
 * 
 * 
*/
int mpy_LvObject::getIntStyleProperty(const cJSON *properties, const char *name)
{

    cJSON* obj = cJSON_GetObjectItem(properties, name);
    if (obj != NULL)
    {
        return obj->valueint;
    }
    mp_raise_TypeError(MP_ERROR_TEXT("Property is required"));
    return 0;
};


/***
 * 
 * 
 * 
*/
char *mpy_LvObject::getStringStyleProperty(const cJSON *properties, const char *name)
{

    cJSON* obj = cJSON_GetObjectItem(properties, name);
    if (obj != NULL)
    {
        return obj->valuestring;
    }
    mp_raise_TypeError(MP_ERROR_TEXT("property is required"));
    return NULL;
};
