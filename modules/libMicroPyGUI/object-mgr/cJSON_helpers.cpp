#include "cJSON_helpers.h"


/**
 * 
 * 
 * 
*/
bool getcJSON_IntProperty(const cJSON *properties, const char *name, int* retVal)
{

    cJSON* obj = cJSON_GetObjectItem(properties, name);
    if (obj != NULL)
    {
        *retVal = obj->valueint;
        return true;
    }
    return false;
};


/***
 * 
 * 
 * 
*/
bool getcJSON_StringProperty(const cJSON *properties, const char *name, char ** retVal)
{

    cJSON* obj = cJSON_GetObjectItem(properties, name);
    if (obj != NULL)
    {
        printf("cJSON Str value: %s for %s\r\n", obj->valuestring,name);
        *retVal = obj->valuestring;
        return true;
    }

    printf("Error in string look up");
    return false;
};
