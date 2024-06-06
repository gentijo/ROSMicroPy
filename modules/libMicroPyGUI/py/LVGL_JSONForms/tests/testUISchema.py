import sys
import os.path
import os

os.chdir(os.path.dirname(__file__))
path = os.path.abspath("../src")
sys.path.append(path)


from LVGL_JSONForms import JSONFormRenderer
from LVGL_Style import LVGL_Style

def test_LVGL_UISchema():
    LVGL_Style.parseStyleDefinitionFromJSONFile("./schema.json")
    LVGL_Style.parseStyleDefinitionFromJSONFile("./styles.json")

    JSONFormRenderer.enableTestMode()
    JSONFormRenderer.parseLayoutDefinitionFromJSONFile ("./ui-schema.json")
    pass

if __name__ == "__main__":
    test_LVGL_UISchema()