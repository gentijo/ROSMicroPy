from  MicroPyGUI import create_LvObject, init_lvgl_screen
from LVGL_Style import LVGL_Style

class LVGL_Driver:
    
    @staticmethod
    def init_lvgl_screen()->object:
        return init_lvgl_screen()

    @staticmethod
    def createLvObject(type, scope, name, properties, parent) -> object:
        
        styles:dict = LVGL_Style.buildCompositeStyle(type, scope, name, properties )
        
#        print("Type: ", type)
#        print("Scope: ", scope)
#        print("NAme: ", name)
#        print("Properties: ", properties)
        
        if (not scope): scope=""
        if (not name): name=""
        
        objInfo = {
            "type": type,
            "scope": scope,
            "name":  name
        }
        
        tObjStr =  str(objInfo);
        tObjStr = tObjStr.replace("'", '"');

        tStyleStr = str(styles)
        tStyleStr = tStyleStr.replace("'", '"');
        return create_LvObject(tObjStr, tStyleStr, parent)

