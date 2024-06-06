from LVGL_Driver import LVGL_Driver
from LVGL_Style import LVGL_Style

class LVGL_MockDriver(LVGL_Driver):

    def __init__():
        pass

    def init_lvgl_screen()->object:
        print("Init LVGL Screen")
        return "root-screen"


    def createLvObject(type, scope, name, properties, parent) -> object:
        styles:dict = LVGL_Style.buildCompositeStyle(type, scope, name, properties )

        fqon:str = f"Type:{type}-Scope:{scope}-Name:{name}"
        
        print(f"\r\n---------------------------------------------------")
        print(f"Creating LV Object, {fqon}")
        print(f"Style Data: {styles}")
        print(f"---------------------------------------------------\r\n")
        return fqon

        

    def set_FormObject_Style(self, style:dict):
        pass



