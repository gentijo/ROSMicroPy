import json


class LVGL_Style:

    styles:dict = {}

    def __init__(self):
        self.properties:dict = {}
        pass

    def parseStyleDefinition(self, definition:dict) -> None:
        for key in definition:
            self.styles[key]=definition[key]

    def parseStyleDefinitionFromJSONFile(self, filename:str) -> None:
        with open(filename) as f:
            definition = json.load(f)
        self.parseStyleDefinition(definition)
        
    def applyProperties(self, properties:dict):
        for key in properties:
            self.properties[key]=properties[key];

    def buildCompositeStyle(self, type:str, scope:str, name:str, properties:dict ) -> dict:
        
        self.properties = {}

        if type in self.styles:
            self.applyStyles(self.styles[type])

        if scope in self.styles:
            self.applyStyles(self.styles[scope])

        if name in self.styles:
            self.applyStyles(self.styles[type])

        if properties and len(properties):
            self.applyProperties(properties)

        return self.properties;


    def dump(self):
        print (self.properties)

