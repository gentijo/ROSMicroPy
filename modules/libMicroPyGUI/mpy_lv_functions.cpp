#ifndef __MPY_LV_FUNCTIONS_H__
#define __MPY_LV_FUNCTIONS_H__


#include <stdio.h>
#include <string.h>

#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

#include <iostream>
#include <sstream>

#include "mpy_LvBaseObjects.h"

#include "mpy_lv_functions.h"
#include "cJSON_helpers.h"

//
//
std::list<mpy_LvObjectFactory *> lvObjectFactories;

//
// List of all objects created named or not.
std::vector<mpy_LvObject *> g_lvObjectList;

//
// For objects that have a name tag, store a pointer to that element here
std::map<const char *, mpy_LvObject *> g_namedObject;

//
// HAndle to the LCD Display
lv_disp_t *g_lcd_display = NULL;
lv_obj_t* ui_Screen1 = NULL;

mp_obj_t init_lvgl_screen() {
  
    printf("Init lvgl screen\r\n");

    lv_theme_t *theme = lv_theme_default_init(
      g_lcd_display, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
      false, LV_FONT_DEFAULT);
    
    lv_disp_set_theme(g_lcd_display, theme);
  
    ui_Screen1 = lv_obj_create(NULL);
    printf("(screen) lv_obj_create(NULL); = [%p]\r\n",  ui_Screen1);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_size (ui_Screen1, 800, 480);/// Flags

    lv_obj_set_x(ui_Screen1, 0);
    lv_obj_set_y(ui_Screen1, 0);
        
    static lv_style_t style;
    lv_style_init(&style);
    // //lv_style_set_radius(&style, 3);
    lv_style_set_outline_width(&style, 0);
    lv_style_set_outline_pad(&style, 0);

    lv_style_set_pad_all(&style, 1);

    lv_obj_add_style(ui_Screen1, &style, 0);
    
    lv_obj_set_style_border_color(ui_Screen1, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_border_width(ui_Screen1, 0, LV_PART_MAIN);
    lv_obj_set_align(ui_Screen1, LV_ALIGN_CENTER);

    mpy_LvObject* mpy_LvObj = new mpy_LvObject(ui_Screen1);
    g_lvObjectList.push_back(mpy_LvObj);

    lv_disp_load_scr(ui_Screen1);

    
    std::string str = std::to_string((unsigned long long)(void**)mpy_LvObj);
  //  printf("Init Lv Screen complete: Lv[%p] [%p] mpyObj[%p] str[%s]\r\n", ui_Screen1, mpy_LvObj->lvObject, mpy_LvObj,  str.c_str());
    mp_obj_t mp_str_ptr = mp_obj_new_str(str.c_str(), str.size());

    return mp_str_ptr;
}

mp_obj_t display_lvgl_screen() {

    lv_disp_load_scr(ui_Screen1);
    return mp_const_none;

}

/**
 *
 *
 *
 */
mp_obj_t add_LvObjectFactory(const mp_obj_t*f)
{
    if (f != NULL)
    {
        lvObjectFactories.push_front((mpy_LvObjectFactory *)MP_OBJ_TO_PTR(f));
    }

    return mp_const_none;
}

/**
 *
 *
 *
 */
mp_obj_t create_LvObject(const mp_obj_t objInfoIn, const mp_obj_t propertiesIn, const mp_obj_t parentIn)
{    
    char emptyString[2] = "";

    cJSON *cJSONObjInfo = NULL;
    if (&mp_type_str != mp_obj_get_type(objInfoIn) && mp_const_none != objInfoIn)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("ObjInfo field must be a string"));
        return mp_const_none;
    }
    else if (mp_const_none != objInfoIn)
    {
        const char* c = mp_obj_str_get_str(objInfoIn);
        if ((c != NULL) && (strlen(c)>0)) {

            cJSONObjInfo = cJSON_Parse(c);
            if (cJSONObjInfo == NULL) {
                mp_raise_ValueError(MP_ERROR_TEXT("Error parsing ObjInfo"));
                return mp_const_none;           
            }
        }
        else 
        {
            mp_raise_TypeError(MP_ERROR_TEXT("ObjInfo field must be a string"));
            return mp_const_none;           
        }
    }

//
//
    char *cType = NULL;
    if (!getcJSON_StringProperty(cJSONObjInfo, "type", &cType) || (NULL == cType) || (strlen(cType) ==0)) {
        mp_raise_ValueError(MP_ERROR_TEXT("Type property in ObjInfo is required"));
        return mp_const_none;
    }

    char *cScope = NULL;
    getcJSON_StringProperty(cJSONObjInfo, "scope", &cScope);
    if (cScope == NULL) cScope=emptyString;

    char *cName = NULL;
    getcJSON_StringProperty(cJSONObjInfo, "name", &cName);
    if (cName == NULL) cName=emptyString;


  //
  //
    cJSON *cJSONProps = NULL;
   
    if (&mp_type_str != mp_obj_get_type(propertiesIn) && mp_const_none != propertiesIn)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Properties field must be a string"));
        return mp_const_none;
    }
    else if (mp_const_none != propertiesIn)
    {
         const char *cProperties = mp_obj_str_get_str(propertiesIn);
        printf("Properties %s\r\n", cProperties);
        cJSONProps = cJSON_Parse(cProperties);
    }

//
//

    // For safety, let's validate that the parent object is an object we created in the past.
    mpy_LvObject *cParent = NULL;

    const char *cParentStr = emptyString;

    if (parentIn != mp_const_none) {
        cParentStr = mp_obj_str_get_str(parentIn);
        std::stringstream ss;
        ss << cParentStr;
        int tmp(0);
        ss >> tmp ;
        cParent = reinterpret_cast<mpy_LvObject*>(tmp);
    }
    else {
        printf("Parent Object is NULL\r\n");
    }

    if (cParent != NULL)
    { 
        // printf("In Create LV Object parent:[%p] parentStr:[%s] parent lvObj:[%p]\r\n", cParent, cParentStr, cParent->lvObject);
        // NULL is a valid parent, attaches to screen
        // It's not NULL so let's validate that it is an existing pointer.
        // if (auto it = std::find(g_lvObjectList.begin(), g_lvObjectList.end(), cParent); it == g_lvObjectList.end())
        // {
        //     // MP Error
        //     return mp_const_none;
        // }
    }

    mpy_LvObject *mpy_lvobj = NULL;

    mpy_lvobj = mpy_LvObjectFactory::create(cType, cParent);

    //
    // Object type was not a base object, so let's other Factories if they know this object
    if (mpy_lvobj == NULL)
    {
        for (auto it = lvObjectFactories.begin(); it != lvObjectFactories.end(); ++it)
        {
            mpy_LvObject *mpy_lvobj = (*it)->create(cType, cParent);
            if (mpy_lvobj != NULL) break;
        }
    }

    if (mpy_lvobj == NULL)
    {
        mp_raise_TypeError(MP_ERROR_TEXT("Unknown Element type"));
        return mp_const_none;
    }

    mpy_lvobj->addLvObjectStyle(cJSONProps);

    if (cName != NULL)
    {
        g_namedObject[cName] = mpy_lvobj;
    }

    g_lvObjectList.push_back(mpy_lvobj);

    cJSON_Delete(cJSONProps);

    if (mpy_lvobj != NULL)
    {
        std::string str = std::to_string((unsigned long long)(void**)mpy_lvobj);
       // printf("Create Lv Object complete: Lv[%p] str[%s]\r\n", mpy_lvobj, str.c_str());
        mp_obj_t mp_str_ptr = mp_obj_new_str(str.c_str(), str.size());
        return mp_str_ptr;
    }
    else return mp_const_none;
};


mp_obj_t lv_example_flex_1(void)
{
    /*Create a container with ROW flex direction*/
    lv_obj_t * cont_row = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont_row, 300, 75);
    lv_obj_align(cont_row, LV_ALIGN_TOP_MID, 0, 5);
    lv_obj_set_flex_flow(cont_row, LV_FLEX_FLOW_ROW);

    /*Create a container with COLUMN flex direction*/
    lv_obj_t * cont_col = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont_col, 200, 150);
    lv_obj_align_to(cont_col, cont_row, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);

    int i;
    for(i = 0; i < 10; i++) {
        lv_obj_t * obj;
        lv_obj_t * label;

        /*Add items to the row*/
        obj= lv_btn_create(cont_row);
        lv_obj_set_size(obj, 100, LV_PCT(100));

        label = lv_label_create(obj);
        lv_label_set_text_fmt(label, "Item: %d", i);
        lv_obj_center(label);

        /*Add items to the column*/
        // obj = lv_btn_create(cont_col);
        obj = lv_obj_create(cont_col);
        lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);

        lv_obj_set_style_border_color(obj, lv_color_black(), LV_PART_MAIN);
        lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN);

        // label = lv_label_create(obj);
        // lv_label_set_text_fmt(label, "Item: ");
        // lv_obj_center(label);
    }

    return mp_const_none;
}
#endif