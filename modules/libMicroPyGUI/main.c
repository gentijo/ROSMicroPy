
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_task.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "lvgl.h"
#include "sdkconfig.h"
#include <stdio.h>

#include "py/runtime.h"
#include "py/mpconfig.h"
#include "mpconfigport.h"


lv_disp_t *init_lcd_display();

#define MP_TASK_PRIORITY        (ESP_TASK_PRIO_MIN)
TaskHandle_t                    mp_lcd_display_task_handle;
lv_disp_t*                      g_lcd_display = NULL;


void  run_lcd_display_loop()
{
  mp_thread_init(pxTaskGetStackStart(NULL), MICROPY_TASK_STACK_SIZE / sizeof(uintptr_t));

  while (1)
  {
    int timerTaskDelay = 0;
    // raise the task priority of LVGL and/or reduce the handler period can
    // improve the performance
    vTaskDelay(pdMS_TO_TICKS(10));
  
    // The task running lv_timer_handler should have lower priority than that
    // running `lv_tick_inc`
    lv_tick_inc(10);
    //lv_task_handler();

    if ((timerTaskDelay++ % 3) == 0)
    {
      lv_timer_handler();
    }
  }
}

mp_obj_t mp_init_lcd_display()
{  
  //
  // init_lcd_display comes from the lvgl driver component
  g_lcd_display = init_lcd_display();

  xTaskCreate(run_lcd_display_loop, "rmp_lcd_task", 
    MICROPY_TASK_STACK_SIZE / sizeof(StackType_t), NULL, MP_TASK_PRIORITY, 
    &mp_lcd_display_task_handle);

  return mp_const_none;
}

/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 *
 */
MP_DEFINE_CONST_FUN_OBJ_0(init_lcd_display_obj, mp_init_lcd_display);

const mp_rom_map_elem_t mp_uros_gui_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ROSMicroPyGUI)},
    {MP_ROM_QSTR(MP_QSTR_rmp_init_lcd_display), MP_ROM_PTR(&init_lcd_display_obj)}};

MP_DEFINE_CONST_DICT(mp_uros_gui_module_globals, mp_uros_gui_module_globals_table);

const mp_obj_module_t mp_uros_gui_user_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_uros_gui_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_ROSMicroPyGUI, mp_uros_gui_user_cmodule);

/**
 * 
 * 
 * 
*/
const mp_rom_map_elem_t rmp_widget_types_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_RMP_GUI_Widgets)},
//    {MP_ROM_QSTR(MP_QSTR_RMP_ROS_VIDEO), MP_ROM_INT(RMP_ROS_VIDEO_WIDGET) },
//    {MP_ROM_QSTR(MP_QSTR_RMP_BUTTON), MP_ROM_INT(RMP_BUTTON_WIDGET) },

};
MP_DEFINE_CONST_DICT(rmp_widget_types, rmp_widget_types_table);
// Define module object.
const mp_obj_module_t rmp_widget_types_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&rmp_widget_types,
};
MP_REGISTER_MODULE(MP_QSTR_RMP_GUI_Widgets, rmp_widget_types_cmodule);

