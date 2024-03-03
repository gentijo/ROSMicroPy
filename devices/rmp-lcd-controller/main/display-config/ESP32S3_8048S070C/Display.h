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

extern "C"
{

    extern void ui_init(lv_disp_t *disp);
    lv_disp_t *initDisplay();


// Proper settings for the Sunton devboard LCD
#define LCD_PIXEL_CLOCK_HZ (16 * 1000 * 1000)
#define LCD_BK_LIGHT_ON_LEVEL 1
#define LCD_BK_LIGHT_OFF_LEVEL !LCD_BK_LIGHT_ON_LEVEL
    const gpio_num_t PIN_NUM_BK_LIGHT = GPIO_NUM_2;
    const gpio_num_t PIN_NUM_HSYNC = GPIO_NUM_39;
    const gpio_num_t PIN_NUM_VSYNC = GPIO_NUM_40;
    const gpio_num_t PIN_NUM_DE = GPIO_NUM_41;
    const gpio_num_t PIN_NUM_PCLK = GPIO_NUM_42;
    const gpio_num_t PIN_NUM_DATA0 = GPIO_NUM_15;  // B0
    const gpio_num_t PIN_NUM_DATA1 = GPIO_NUM_7;   // B1
    const gpio_num_t PIN_NUM_DATA2 = GPIO_NUM_6;   // B2
    const gpio_num_t PIN_NUM_DATA3 = GPIO_NUM_5;   // B3
    const gpio_num_t PIN_NUM_DATA4 = GPIO_NUM_4;   // B4
    const gpio_num_t PIN_NUM_DATA5 = GPIO_NUM_9;   // G0
    const gpio_num_t PIN_NUM_DATA6 = GPIO_NUM_46;  // G1
    const gpio_num_t PIN_NUM_DATA7 = GPIO_NUM_3;   // G2
    const gpio_num_t PIN_NUM_DATA8 = GPIO_NUM_8;   // G3
    const gpio_num_t PIN_NUM_DATA9 = GPIO_NUM_16;  // G4
    const gpio_num_t PIN_NUM_DATA10 = GPIO_NUM_1;  // G5
    const gpio_num_t PIN_NUM_DATA11 = GPIO_NUM_14; // R0
    const gpio_num_t PIN_NUM_DATA12 = GPIO_NUM_21; // R1
    const gpio_num_t PIN_NUM_DATA13 = GPIO_NUM_47; // R2
    const gpio_num_t PIN_NUM_DATA14 = GPIO_NUM_48; // R3
    const gpio_num_t PIN_NUM_DATA15 = GPIO_NUM_45; // R4
    const gpio_num_t PIN_NUM_DISP_EN = GPIO_NUM_NC;

// The pixel number in horizontal and vertical
#define LCD_H_RES 800
#define LCD_V_RES 480

#if CONFIG_EXAMPLE_DOUBLE_FB
#define LCD_NUM_FB 2
#else
#define LCD_NUM_FB 1
#endif // CONFIG_EXAMPLE_DOUBLE_FB

#define LVGL_TICK_PERIOD_MS 2

// Proper settings for the Sunton devboard touch driver
#if CONFIG_EXAMPLE_LCD_TOUCH_ENABLED
    const gpio_num_t TOUCH_GT911_SCL = GPIO_NUM_20;
    const gpio_num_t TOUCH_GT911_SDA = GPIO_NUM_19;
    const gpio_num_t TOUCH_GT911_INT = GPIO_NUM_NC;
    const gpio_num_t TOUCH_GT911_RST = GPIO_NUM_38;
#endif

#endif
}