#include "py/runtime.h"
#include "py/mpconfig.h"

#include "rcl/rcl.h"
#include "rcl/error_handling.h"
#include "rclc/rclc.h"
#include "rclc/executor.h"

#include "uros_sdk.h"
#include "uros_base_func.h"



/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 * 
*/
STATIC MP_DEFINE_CONST_FUN_OBJ_0(init_ROS_Stack_obj, init_ROS_Stack);

// A little indirection here to allow for thread creation
STATIC MP_DEFINE_CONST_FUN_OBJ_0(run_ROS_Stack_obj,  mp_run_ROS_Stack);

STATIC MP_DEFINE_CONST_FUN_OBJ_3(publishMsg_obj, publishMsg);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(registerEventSubscription_obj, registerEventSubscription);

STATIC MP_DEFINE_CONST_FUN_OBJ_1(setDomainID_obj, setDomainID);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(setNamespace_obj, setNamespace);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(setNodeName_obj, setNodeName);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(setWifiConfig_obj, setWifiConfig);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(registerDataType_obj, registerDataType);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(dumpDataType_obj, mp_dumpDataType);


/**
 * Register the microros class and map the functions from Micropython to MicroROS
*/
STATIC const mp_rom_map_elem_t mp_uros_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPy)},

    {MP_ROM_QSTR(MP_QSTR_init_ROS_Stack), MP_ROM_PTR(&init_ROS_Stack_obj)},
    {MP_ROM_QSTR(MP_QSTR_run_ROS_Stack), MP_ROM_PTR(&run_ROS_Stack_obj)},

    {MP_ROM_QSTR(MP_QSTR_setDomainID), MP_ROM_PTR(&setDomainID_obj)},
    {MP_ROM_QSTR(MP_QSTR_setNamespace), MP_ROM_PTR(&setNamespace_obj)},
    {MP_ROM_QSTR(MP_QSTR_setNodeName), MP_ROM_PTR(&setNodeName_obj)},
    {MP_ROM_QSTR(MP_QSTR_setWifiConfig), MP_ROM_PTR(&setWifiConfig_obj)},

    {MP_ROM_QSTR(MP_QSTR_registerDataType), MP_ROM_PTR(&registerDataType_obj)},
    {MP_ROM_QSTR(MP_QSTR_dumpDataType), MP_ROM_PTR(&dumpDataType_obj)},


    {MP_ROM_QSTR(MP_QSTR_publishMsg), MP_ROM_PTR(&publishMsg_obj)},
    {MP_ROM_QSTR(MP_QSTR_registerEventSubscription), MP_ROM_PTR(&registerEventSubscription_obj)},



};

STATIC MP_DEFINE_CONST_DICT(mp_uros_module_globals, mp_uros_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_user_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_uros_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_ROSMicroPy, mp_uros_user_cmodule);
