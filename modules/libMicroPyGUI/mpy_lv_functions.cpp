#ifndef __MPY_LV_FUNCTIONS_H__
#define __MPY_LV_FUNCTIONS_H__

#include <stdio.h>
#include <string.h>
#include <list>
#include <algorithm>

#include "mpy_lv_functions.h"
//
//
std::list<mpy_LvObjectFactory *> lvObjectFactories;

/**
 *
 *
 *
 */
void add_LvObjectFactory(mpy_LvObjectFactory *f)
{
    if (f != NULL)
    {
        lvObjectFactories.push_back(f);
    }
}

/**
 *
 *
 *
 */
mpy_LvObject *createLvObject(mp_obj_t typeIn, mp_obj_t scopeIn, mp_obj_t nameIn, mp_obj_t propertiesIn, mp_obj_t parentIn)
{

    const char *cType = NULL;
    if (&mp_type_str != mp_obj_get_type(typeIn))
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Type is a required field and must be a string"));
        return NULL;
    }
    else
    {
        cType = mp_obj_str_get_str(typeIn);
    }

    const char *cScope = NULL;
    if (&mp_type_str != mp_obj_get_type(scopeIn) && mp_const_none != scopeIn)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Scope field must be a string"));
        return NULL;
    }
    else if (mp_const_none != scopeIn)
    {
        cType = mp_obj_get_type_str(scopeIn);
    }

    const char *cName = NULL;
    if (&mp_type_str != mp_obj_get_type(nameIn) && mp_const_none != nameIn)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Name field must be a string"));
        return NULL;
    }
    else if (mp_const_none != nameIn)
    {
        cType = mp_obj_get_type_str(nameIn);
    }

    cJSON *cJSONProps = NULL;
    const char *cProperties = NULL;

    if (&mp_type_str != mp_obj_get_type(propertiesIn) && mp_const_none != propertiesIn)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Properties field must be a string"));
        return NULL;
    }
    else if (mp_const_none != propertiesIn)
    {
        cProperties = mp_obj_get_type_str(cProperties);
        cJSONProps = NULL; //cJSON_Parse(cProperties);
    }

    // For safety, let's validate that the parent object is an object we created in the past.
    mpy_LvObject *cParent = NULL; //(mpy_LvObject *)MP_OBJ_TO_PTR(parentIn);
    if (cParent != NULL)
    { 
        // NULL is a valid parent, attaches to screen
        // It's not NULL so let's validate that it is an existing pointer.
        if (auto it = std::find(g_lvObjectList.begin(), g_lvObjectList.end(), cParent); it == g_lvObjectList.end())
        {
            // MP Error
            return NULL;
        }
    }

    mpy_LvObject *mpy_lvobj = NULL;

    mpy_lvobj = mpy_LvObjectFactory::create(cType, cParent);

    if (mpy_lvobj == NULL)
    {
        // for (auto it = lvObjectFactories.begin(); it != lvObjectFactories.end(); ++it)
        // {
        //     mpy_LvObject *obj = (*it)->create(cType, cParent);
        //     if (obj != NULL)
        //         return obj;
        // }
    }

    if (mpy_lvobj == NULL)
    {
        {
            mp_raise_TypeError(MP_ERROR_TEXT("Unknown Element type"));
            return NULL;
        }
    }

    mpy_lvobj->addLvObjectStyle(cJSONProps);

    if (cName != NULL)
    {
        g_namedObject[cName] = mpy_lvobj;
    }
    g_lvObjectList.push_back(mpy_lvobj);

 //   cJSON_Delete(cJSONProps);

    return (mpy_lvobj);
};


#endif