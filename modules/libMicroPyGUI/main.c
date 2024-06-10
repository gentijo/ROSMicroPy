#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "py/runtime.h"
#include "py/obj.h"

#include "esp_task.h"

#include "lvgl.h"
#include "sdkconfig.h"

#include "mpy_lv_functions.h"
#include "sdkconfig.h"

#define MP_LV_TASK_PRIORITY (ESP_TASK_PRIO_MIN)
lv_disp_t *init_lcd_display();

TaskHandle_t mp_lcd_display_task_handle;


/***
 * 
 * 
 * 
*/
void run_lcd_display_loop()
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
    // lv_task_handler();

    if ((timerTaskDelay++ % 3) == 0)
    {
      lv_timer_handler();
    }
  }
}


/**
 * 
 * 
 * 
*/
mp_obj_t mp_init_lcd_display()
{
  //
  // init_lcd_display comes from the lvgl driver component
  g_lcd_display = init_lcd_display();

  xTaskCreate(run_lcd_display_loop, "mpy_lcd_task",
              MICROPY_TASK_STACK_SIZE / sizeof(StackType_t), NULL, MP_LV_TASK_PRIORITY,
              &mp_lcd_display_task_handle);

  return mp_const_none;
}

mp_obj_t mp_init_lvgl_screen() {
  return(init_lvgl_screen());
}
/**
 * Create MP objects that can be registered with Micropython from MicroROS
 * This will represent the microros builtin class, with the functions that make up the MicroROS SDK
 *
 */
MP_DEFINE_CONST_FUN_OBJ_0(init_lcd_display_obj, mp_init_lcd_display);
MP_DEFINE_CONST_FUN_OBJ_3(create_LvObject_obj, create_LvObject);
MP_DEFINE_CONST_FUN_OBJ_1(add_LvObjectFactory_obj, add_LvObjectFactory);
MP_DEFINE_CONST_FUN_OBJ_0(init_lvgl_screen_obj, mp_init_lvgl_screen);
MP_DEFINE_CONST_FUN_OBJ_0(display_lvgl_screen_obj, display_lvgl_screen);
MP_DEFINE_CONST_FUN_OBJ_0(lv_example_flex_1_obj, lv_example_flex_1);



const mp_rom_map_elem_t mp_gui_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_MicroPyGUI)},
    {MP_ROM_QSTR(MP_QSTR_init_lcd_display), MP_ROM_PTR(&init_lcd_display_obj)},
    {MP_ROM_QSTR(MP_QSTR_create_LvObject), MP_ROM_PTR(&create_LvObject_obj)},
    {MP_ROM_QSTR(MP_QSTR_init_lvgl_screen), MP_ROM_PTR(&init_lvgl_screen_obj)},
    {MP_ROM_QSTR(MP_QSTR_display_lvgl_screen), MP_ROM_PTR(&display_lvgl_screen_obj)},
    {MP_ROM_QSTR(MP_QSTR_lv_example_flex_1), MP_ROM_PTR(&lv_example_flex_1_obj)},
    {MP_ROM_QSTR(MP_QSTR_add_LvObjectFactory), MP_ROM_PTR(&add_LvObjectFactory_obj)}
};

MP_DEFINE_CONST_DICT(mp_gui_module_globals, mp_gui_module_globals_table);

const mp_obj_module_t mp_gui_cmodule = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mp_gui_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_MicroPyGUI, mp_gui_cmodule);
