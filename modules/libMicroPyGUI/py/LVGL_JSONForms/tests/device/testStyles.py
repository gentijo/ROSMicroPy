

from LVGL_Style import LVGL_Style

def test_LVGLStyle():
    LVGL_Style.parseStyleDefinitionFromJSONFile("/schema.json")
    properties = LVGL_Style.buildCompositeStyle("BUTTON")
    print(properties)

    properties = LVGL_Style.buildCompositeStyle("BUTTON", None, "lbutton1")
    print(properties)

if __name__ == "__main__":
    test_LVGLStyle()