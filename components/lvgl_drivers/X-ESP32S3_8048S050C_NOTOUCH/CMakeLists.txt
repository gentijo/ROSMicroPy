# Component directive
idf_component_register(
    SRCS "Display.c"
    INCLUDE_DIRS .
    REQUIRES lvgl esp_lcd esp_lcd_touch_gt911
)