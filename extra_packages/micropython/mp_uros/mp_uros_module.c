#include "mp_uros_module.h"

// Define a Python reference to the function we'll make available.
// See example.cpp for the definition.
STATIC MP_DEFINE_CONST_FUN_OBJ_2(publishMsg_obj, publishMsg);

// Define all properties of the module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimized to word-sized integers by the build system (interned strings).

STATIC const mp_rom_map_elem_t mp_uros_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_microros) },
    { MP_ROM_QSTR(MP_QSTR_publishMsg), MP_ROM_PTR(&publishMsg_obj) },
};

STATIC MP_DEFINE_CONST_DICT(mp_uros_module_globals, mp_uros_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mp_uros_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_microros, mp_uros_user_cmodule);
