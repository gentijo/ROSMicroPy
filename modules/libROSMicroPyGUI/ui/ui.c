
#include "ui.h"
#include "ui_helpers.h"


void ui_init(lv_disp_t *disp) {
  lv_theme_t *theme = lv_theme_default_init(
      disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
      false, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, theme);
  
  //ui_Screen1_screen_init();
  //ui____initial_actions0 = lv_obj_create(NULL);
  //lv_disp_load_scr(ui_Screen1);
}
