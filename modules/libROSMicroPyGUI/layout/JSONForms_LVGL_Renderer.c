#include "JSONForms_LVGL_Renderer.h"

/**
 * 
 * There are Styles / Object / Elements
 * 
 * Styles are standalone and can be applied anywhere there is a property list
 * 
 * Objects are top level containers typically describing a layout that may or may not
 * have a visual presence.
 * 
 * Objects contain Elements, Elements define the size and location of a visual element.
 * 
 * Elements can contain objects that contain other elements.
 * 
*/

/**
 * Parse the Data Definition schema and create a list of instructions
 * that are needed to serialize / deserialize the data type passed into
 * ROS
*/
mp_obj_t parseLayoutDefinition(mp_obj_t obj_in, bool debug) {

    // Import the Dict object into a map to locate values.
    mp_map_t *dataMap = mp_obj_dict_get_map(obj_in);
    mp_obj_t dataMapEntry = mp_const_none;


    // MP_OBJ_NEW_SMALL_INT
    // mp_obj_t mp_obj_dict_get(mp_obj_t self_in, mp_obj_t index) {
    // void mp_obj_list_get(mp_obj_t self_in, size_t *len, mp_obj_t **items);
    // size_t mp_obj_dict_len(mp_obj_t self_in);

    // while ( (dataMapEntry = map_iternext(dataMap)) != MP_OBJ_STOP_ITERATION) {

    // }
}
