import json
from LVGL_MockDriver   import LVGL_MockDriver
from LVGL_Driver       import LVGL_Driver
from MicroPyGUI        import init_lvgl_screen, display_lvgl_screen

class JSONFormRenderer:

    driver:LVGL_Driver = LVGL_Driver

#
#
#
    @staticmethod
    def enableTestMode():
        print("Entering test mode")
        JSONFormRenderer.driver = LVGL_MockDriver

#
#
#
    @staticmethod
    def parseLayoutDefinitionFromJSONFile(filename:str) -> None:
        print(filename)    
        with open(filename) as f:
            definition = json.load(f)
            print(definition)
            JSONFormRenderer.parseLayoutDefinition(definition)
#
#
#
    @staticmethod
    def parseLayoutDefinition(definition:dict):
        
        screen = init_lvgl_screen()
        parentObjects:list = []
        parentObjects.append(screen);
        JSONFormRenderer.parseFormObject(definition, parentObjects)
        display_lvgl_screen()

#
#
#
    @staticmethod
    def parseFormObject(schema:dict, parentLvObjects:list=None) -> object:

        print("\r\n\nParse Form Object\r\n")
        objType:str = None
        name:str = None
        scope:str = None
        properties:dict = {}
        elements:dict = {}

        if 'type' in schema:
            objType= schema['type']

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
            
        #print("Parent Object size: ", len(parentLvObjects), parent)
        
        lvObject = JSONFormRenderer.driver.createLvObject(objType, scope, name, properties, parent)
        parentLvObjects.append(lvObject)
        #print("Parent Objects ", parentLvObjects)

        for element in elements:
            JSONFormRenderer.parseFormObject(element, parentLvObjects)

        del parentLvObjects[-1]