import json
from LVGL_MockDriver   import LVGL_MockDriver
from LVGL_Driver       import LVGL_Driver


class JSONFormRenderer:

    driver:LVGL_Driver = LVGL_Driver


    @staticmethod
    def enableTestMode():
        print("Entering test mode")
        JSONFormRenderer.driver = LVGL_MockDriver


    @staticmethod
    def parseLayoutDefinitionFromJSONFile(filename:str) -> None:
        with open(filename) as f:
            definition = json.load(f)
            JSONFormRenderer.parseLayoutDefinition(definition)
    
    @staticmethod
    def parseLayoutDefinition(map:dict):
        
        screen = JSONFormRenderer.driver.init_lvgl_screen()
        parentObjects:list = []
        parentObjects.append(screen);
        JSONFormRenderer.parseFormObject(map, parentObjects)

        #ui_Screen1 = lv_obj_create(NULL);
        #lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        #g_last_parent_lvobj.push_front(lvobj);
        #processLvObject(lvobj, debug);
        pass


    @staticmethod
    def parseFormObject(schema:dict, parentLvObjects:list=None) -> object:

        type:str = None
        name:str = None
        scope:str = None
        properties:dict = {}
        elements:dict = {}

        if 'type' in schema:
            type= schema['type']

        if 'name' in schema:
            name= schema['name']
        
        if 'scope' in schema:
            scope= schema['scope']
            
        if 'properties' in schema:
            properties= schema['properties']

        if 'elements' in schema:
            elements= schema['elements']

        parent = None
        if len(parentLvObjects) > 0:
            parent = parentLvObjects[-1]

        lvObject = JSONFormRenderer.driver.createLvObject(type, scope, name, properties, parent)
        parentLvObjects.append(lvObject)

        for element in elements:
            JSONFormRenderer.parseFormObject(element, parentLvObjects)

        del parentLvObjects[-1]