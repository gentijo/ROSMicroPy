#include "JSONForms_LVGL_Renderer.h"
#include "mp_helpers.h"

#include <list>

/**
 * 

 * 
*/
std:list<lv_obj_t> g_last_parent_lvobj;

/**
 * Parse the Data Definition schema and create a list of instructions
 * that are needed to serialize / deserialize the data type passed into
 * ROS
*/
mp_obj_t parseLayoutDefinition(mp_obj_t obj_in, bool debug) {

    if (&mp_type_dict != mp_obj_get_type(obj_in) ) {
        mp_raise_ValueError(MP_ERROR_TEXT("Top Level object must be of type Dict."));
        return mp_const_none;
    }
    // Import the Dict object into a map to locate values.
    mp_map_t *map = mp_obj_dict_get_map(obj_in);
    lv_obj_t lvobj = init_lvgl_screen();
    
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    if (NULL == lvobj ) {
        mp_raise_ValueError(MP_ERROR_TEXT("Error Creating Root level screen"));
        return mp_const_none;
    }


    g_last_parent_lvobj.push_front(lvobj);

    processLvObject(lvobj, debug);
}

void init_lvgl_screen(lv_disp_t *disp) {
    lv_theme_t *theme = lv_theme_default_init(
      disp, 
      lv_palette_main(LV_PALETTE_BLUE), 
      lv_palette_main(LV_PALETTE_RED),
      false, LV_FONT_DEFAULT);
  
    lv_disp_set_theme(disp, theme);
  ui_Screen1_screen_init();
  ui____initial_actions0 = lv_obj_create(NULL);
  lv_disp_load_scr(ui_Screen1);
}

mp_obj_t processLvObject(mp_obj_t objIn, bool debug) {

    if (&mp_type_dict != mp_obj_get_type(obj_in) ) {
        mp_raise_ValueError(MP_ERROR_TEXT("Element must be an Object of type dict"));
        return mp_const_none;
    }
    
    mp_map_t *Lv_ObjMap = mp_obj_dict_get_map(obj_in);
    
    char* type = getStrFieldFromMap(Lv_ObjMap, "type");
    char* name = getStrFieldFromMap(Lv_ObjMap, "name");
    char* scope = getStrFieldFromMap(Lv_ObjMap, "scope");

    WIDGET_T widget_type = rmp_widget_stype2type(type);
    
    if (widget_type == WIDGET_TYPE.Unknown) {
        // Utilize the Compressed ROM macro.
        char error_mesg[61] = MP_ERROR_TEXT("Unknown Widget type: ");
        strncat(error_mesg, type, 60 );
        mp_raise_ValueError(error_mesg);
        return mp_const_none;
    }

    lv_obj_t lv_parent = NULL; 
    
    if (!g_last_parent_lvobj.empty()) lv_parent = g_last_parent_lvobj.front();
    rmp_widget_t widget = rmp_load_widget(name, widget_type,  lv_parent);
    g_last_parent_lv_obj.push_front(widget);

    mp_obj_list_t elements = getListFieldFromMap(obj_in, "elements");
    if (elements != null) {
        size_t   ElementListLen;
        mp_obj_t *ElementList;
        mp_obj_list_get(obComponentList, &componentListLen, &componentList);
        
        for (size_t i = 0; i < ElementListLen; ++i) {
            mp_obj_t element = componentList[i];
            processLvObject(element, debug);
        }
    }

    g_last_parent_lv_obj.pop_front();
}