
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
#include "display-config/ESP32S3_8048S070C/Display.h"


extern "C"
{

  void lcd_main(void)
  {

    lv_disp_t *disp = initDisplay();
    ui_init(disp);

    while (1)
    {
      // raise the task priority of LVGL and/or reduce the handler period can
      // improve the performance
      vTaskDelay(pdMS_TO_TICKS(10));
      // The task running lv_timer_handler should have lower priority than that
      // running `lv_tick_inc`
      lv_timer_handler();
    }
  }
}
