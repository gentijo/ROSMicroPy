
from LVGL_JSONForms import JSONFormRenderer
from LVGL_Style import LVGL_Style
from MicroPyGUI import init_lcd_display

def test_LVGL_UISchema():
    init_lcd_display()
    
    #JSONFormRenderer.enableTestMode()
    LVGL_Style.parseStyleDefinitionFromJSONFile("schema.json")
    LVGL_Style.parseStyleDefinitionFromJSONFile("styles.json")
    #LVGL_Style.dumpParsedStyles()
    
    JSONFormRenderer.parseLayoutDefinitionFromJSONFile("ui-schema.json")
    pass

if __name__ == "__main__":
    test_LVGL_UISchema()