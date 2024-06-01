import LVGL_MockDriver
import LVGL_Driver
import LVGL_Style

schema = {
    "type": "HorizontalLayout",
    "elements": [
      {
        "type": "VerticalLayout",
        "elements": [
          {
            "type": "Container",
            "scope": "#/properties/name"
          },
          {
            "type": "Container",
            "scope": "#/properties/birthDate"
          },
          {
            "type": "Container",
            "scope": "#/properties/occupation"
          }
        ]
      },
      {
        "type": "VerticalLayout",
        "elements": []
      }
    ]
  }

class JSONFormRenderer:

    def __init__(self, isTest:bool):
        self.type:str = ""
        self.scope:str = ""
        self.name:str = ""
        self.properties:dict = {}
        self.parentlvObjects:list = []
        self.elements:list = []
        self.isTest:bool = False
        self.driver:LVGL_Driver = None

        if isTest:
            self.driver = LVGL_MockDriver()
            self.isTest = True


    def parseLayoutDefinition(self, map:dict):

        screen = self.driver.init_lvgl_screen()
        self.parentlvObjects.append(screen)
        self.parseFormObject(dict)

        #ui_Screen1 = lv_obj_create(NULL);
        #lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        #g_last_parent_lvobj.push_front(lvobj);
        #processLvObject(lvobj, debug);
        pass


    def parseFormObject(self, schema:dict, parent:object=None) -> object:

        if 'type' in schema:
            self.type= schema.type

        if 'name' in schema:
            self.name= schema.name
        
        if 'scope' in schema:
            self.scope= schema.scope
            
        if 'properties' in schema:
            self.properties= schema.properties

        if 'elements' in schema:
            self.elements= schema.elements

        styles:dict = LVGL_Style(self.type, self.scope, self.name, self.properties )
        lvObject = self.driver.createLvObject(self, styles)

        for element in self.elements:
            self.parseFormObject(element, self.parentlvObjects[-1])

        del self.parentlvObjects[-1]