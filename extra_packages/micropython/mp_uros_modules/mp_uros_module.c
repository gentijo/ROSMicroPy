#include "mp_uros_module.h"
#include "mp_uros.h"

// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(publishMsg_obj, publishMsg);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(registerEventSubscription_obj, registerEventSubscription);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(init_ros_mp_event_system_obj, init_ros_mp_event_system);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(readROSMsg_obj, readROSMsg);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(init_event_queue_obj, init_event_queue);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(readObjFromThread_obj, readObjFromThread);
STATIC MP_DEFINE_CONST_FUN_OBJ_0(createObjFromThread_obj, createObjFromThread);



// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).

STATIC const mp_rom_map_elem_t mp_uros_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_microros) },
    { MP_ROM_QSTR(MP_QSTR_publishMsg), MP_ROM_PTR(&publishMsg_obj) },
    { MP_ROM_QSTR(MP_QSTR_registerEventSubscription), MP_ROM_PTR(&registerEventSubscription_obj) },
    { MP_ROM_QSTR(MP_QSTR_init_ros_mp_event_system), MP_ROM_PTR(&init_ros_mp_event_system_obj) },
    { MP_ROM_QSTR(MP_QSTR_readROSMsg), MP_ROM_PTR(&readROSMsg_obj) },
    { MP_ROM_QSTR(MP_QSTR_init_event_queue), MP_ROM_PTR(&init_event_queue_obj) },
    { MP_ROM_QSTR(MP_QSTR_readObjFromThread), MP_ROM_PTR(&readObjFromThread_obj) },
    { MP_ROM_QSTR(MP_QSTR_createObjFromThread), MP_ROM_PTR(&createObjFromThread_obj) }

};

STATIC MP_DEFINE_CONST_DICT(mp_uros_module_globals, mp_uros_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mp_uros_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_microros, mp_uros_user_cmodule);
