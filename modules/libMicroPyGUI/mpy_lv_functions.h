#ifndef __MPY_LV_FUNCS_H__
#define __MPY_LV_FUNCS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "py/runtime.h"
#include "py/obj.h"

extern lv_disp_t *g_lcd_display;

mp_obj_t init_lvgl_screen();
mp_obj_t create_LvObject(const mp_obj_t objInfoIn, const mp_obj_t propertiesIn, const mp_obj_t parentIn);
mp_obj_t add_LvObjectFactory(const mp_obj_t* f);
mp_obj_t display_lvgl_screen();
mp_obj_t lv_example_flex_1(void);

#ifdef __cplusplus
}
#endif

#endif


