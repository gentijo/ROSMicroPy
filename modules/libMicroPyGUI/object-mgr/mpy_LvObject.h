#ifndef __MPY_LVOBJECT_H__
#define __MPY_LVOBJECT_H__


#include <stdio.h>
#include "lvgl.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "cJSON.h"

#ifdef __cplusplus
}
#endif

class mpy_LvObject
{

public:
    mpy_LvObject() {
    };


    mpy_LvObject(mpy_LvObject *parent)
    {

        if (parent == NULL)
        {
            printf("Creating LvObject NULL parent:");
            lvObject = lv_obj_create(NULL);
        }
        else
        {
            lvObject = lv_obj_create(parent->lvObject);
        }

        lv_obj_clear_flag(this->lvObject, LV_OBJ_FLAG_SCROLLABLE); 

        lv_style_init(&style);

        /*Set a background color and a radius*/
        lv_style_set_radius(&style, 3);

        lv_style_set_pad_all(&style, 1);
        lv_style_set_outline_pad(&style, 0);

        /*Add outline*/
        lv_style_set_outline_width(&style, 0);

        lv_obj_add_style(lvObject, &style, 0);

        lv_obj_set_style_border_color(lvObject, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_border_width(lvObject, 1, LV_PART_MAIN);
    }
    //
    // Create an mpy_LvObject from existing lv_obj
    mpy_LvObject(lv_obj_t *node)
    {
        lvObject = node;
    }

public:
    void addLvObjectStyle(cJSON *properties);
    
    void setSize(cJSON *properties);
    void setPadAll(cJSON *properties);

    int getIntStyleProperty(const cJSON *properties, const char *name);
    char *getStringStyleProperty(const cJSON *properties, const char *name);

    lv_obj_t *lvObject;
    lv_style_t style;
};

#endif
