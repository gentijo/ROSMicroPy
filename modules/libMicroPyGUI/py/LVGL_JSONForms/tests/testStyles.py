import sys
import os.path
import os

os.chdir(os.path.dirname(__file__))
path = os.path.abspath("../src")
sys.path.append(path)


from LVGL_Style import LVGL_Style

def test_LVGLStyle():
    LVGL_Style.parseStyleDefinitionFromJSONFile("./styles.json")
    properties = LVGL_Style.buildCompositeStyle("BUTTON")
    print(properties)

    properties = LVGL_Style.buildCompositeStyle("BUTTON", None, "lbutton1")
    print(properties)

if __name__ == "__main__":
    test_LVGLStyle()