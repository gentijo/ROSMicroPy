#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "py/runtime.h"
#include "py/obj.h"

#include "esp_task.h"

#include "lvgl.h"
#include "sdkconfig.h"

#include "sdkconfig.h"



/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 *
 */
//MP_DEFINE_CONST_FUN_OBJ_0(init_lcd_display_obj, mp_init_lcd_display);



const mp_rom_map_elem_t mp_ROS_Widget_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPyWidgets)},
//    {MP_ROM_QSTR(MP_QSTR_init_lcd_display), MP_ROM_PTR(&init_lcd_display_obj)},
};

MP_DEFINE_CONST_DICT(mp_ROS_Widget_module_globals, mp_ROS_Widget_module_globals_table);

const mp_obj_module_t mp_ros_widgets_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_ROS_Widget_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_ROSMicroPyWidgets, mp_ros_widgets_cmodule);
