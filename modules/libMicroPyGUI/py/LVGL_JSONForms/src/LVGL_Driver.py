#From LVGL_C_Driver import LVGL_C_Driver

class LVGL_Driver:
    
    #c_driver = LVGL_C_Driver()

    def init_lvgl_screen(self)->object:
        return None #LVGL_C_Driver.init_lvgl_screen()


    def createLvObject(type, scope, name, properties, parent) -> object:
        styles:dict = LVGL_Style.buildCompositeStyle(type, scope, name, properties )
        lvgl_c_Driver.createLvObject(type, scope, name, styles.__str__(), parent)