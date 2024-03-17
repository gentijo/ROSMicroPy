
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "lvgl.h"
#include "sdkconfig.h"
#include <stdio.h>
#include "lcd-display-drivers/ESP32S3_8048S070C/Display.h"

#include "ui/ui.h"
#include "py/runtime.h"
#include "py/mpconfig.h"


  mp_obj_t init_gui()
  {

    lv_disp_t *disp = initDisplay();
    ui_init(disp);

    printf("Enter LCD While\r\n");
    while (1)
    {
      // raise the task priority of LVGL and/or reduce the handler period can
      // improve the performance
      vTaskDelay(pdMS_TO_TICKS(10));
      // The task running lv_timer_handler should have lower priority than that
      // running `lv_tick_inc`
      lv_timer_handler();
    }
    printf("Exit LCD While\r\n");

    return mp_const_none;
  }


/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 * 
*/
STATIC MP_DEFINE_CONST_FUN_OBJ_0(init_gui_obj, init_gui);


/**
 * Register the microros class and map the functions from Micropython to MicroROS
*/
STATIC const mp_rom_map_elem_t mp_uros_gui_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPyGUI)},

    {MP_ROM_QSTR(MP_QSTR_init_gui), MP_ROM_PTR(&init_gui_obj)}
};

STATIC MP_DEFINE_CONST_DICT(mp_uros_gui_module_globals, mp_uros_gui_module_globals_table);

// Define module object.
const mp_obj_module_t mp_uros_gui_user_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_uros_gui_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_ROSMicroPyGUI, mp_uros_gui_user_cmodule);


