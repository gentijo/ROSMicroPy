#ifndef __DISPLAY_8048S070C_H__
#define __DISPLAY_8048S070C_H__

#include "driver/gpio.h"
#include "driver/i2c.h"

#include "esp_err.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_lcd_touch_gt911.h"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "lvgl.h"
#include "sdkconfig.h"
#include <stdio.h>

lv_disp_t *init_lcd_display();

// Proper settings for the Sunton devboard LCD
#define LCD_PIXEL_CLOCK_HZ (12*1000*1000) //(14 * 1000 * 1000)
#define LCD_BK_LIGHT_ON_LEVEL 1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL

// The pixel number in horizontal and vertical
#define LCD_H_RES 800
#define LCD_V_RES 480

#if CONFIG_EXAMPLE_DOUBLE_FB
#define LCD_NUM_FB 2
#else
#define LCD_NUM_FB 1
#endif // CONFIG_EXAMPLE_DOUBLE_FB

#define LVGL_TICK_PERIOD_MS 2

#define CONFIG_EXAMPLE_LCD_TOUCH_ENABLED 1

#endif
