#include "rmp_cam_main.h"


/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 *
 */

MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_init_obj, rmp_cam_init);
MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_start_obj, rmp_cam_start);
MP_DEFINE_CONST_FUN_OBJ_0(rmp_publish_cam_image_obj, rmp_publish_cam_image);
MP_DEFINE_CONST_FUN_OBJ_0(rmp_cam_takepic_obj, rmp_cam_takepic);
MP_DEFINE_CONST_FUN_OBJ_1(rmp_cam_set_topic_name_obj, rmp_cam_set_topic_name);

/**
 * Register the microros class and map the functions from Micropython to MicroROS
 */
const mp_rom_map_elem_t mp_uros_cam_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPyCAM)},

    {MP_ROM_QSTR(MP_QSTR_rmp_cam_init), MP_ROM_PTR(&rmp_cam_init_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_cam_takepic), MP_ROM_PTR(&rmp_cam_takepic_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_publish_cam_image), MP_ROM_PTR(&rmp_publish_cam_image_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_cam_start), MP_ROM_PTR(&rmp_cam_start_obj)},
    {MP_ROM_QSTR(MP_QSTR_rmp_cam_set_topic_name), MP_ROM_PTR(&rmp_cam_set_topic_name_obj)}

};

MP_DEFINE_CONST_DICT(mp_uros_cam_module_globals, mp_uros_cam_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_cam_user_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_uros_cam_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_ROSMicroPyCAM, mp_uros_cam_user_cmodule);
