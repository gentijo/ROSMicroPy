import json


class LVGL_Style:

    styles:dict = {}

    @staticmethod
    def parseStyleDefinition(definitionIn:dict) -> None:
        for name in definitionIn:
            styleDef=definitionIn[name]
            if ("properties" in styleDef):
                properties = styleDef["properties"]
                styles = styleDef["properties"]
                LVGL_Style.styles[name]=styles

    @staticmethod
    def parseStyleDefinitionFromJSONFile(filename:str) -> None:
        with open(filename) as f:
            definition = json.load(f)
            LVGL_Style.parseStyleDefinition(definition)

    @staticmethod
    def addStyleToDict(properties:dict, style:dict) -> None:
        for key in style:
            properties[key]=style[key]

    @staticmethod
    def buildCompositeStyle(type:str=None, scope:str=None, name:str=None, propertiesIn:dict={} ) -> dict:
        
        properties = {}

        if type and (type in LVGL_Style.styles):
            LVGL_Style.addStyleToDict(properties, LVGL_Style.styles[type])

        if scope and (scope in LVGL_Style.styles):
            LVGL_Style.addStyleToDict(properties, LVGL_Style.styles[scope])

        if name and (name in LVGL_Style.styles) :
            LVGL_Style.addStyleToDict(properties, LVGL_Style.styles[name])

        if propertiesIn and len(propertiesIn):
            for key in propertiesIn:
                properties[key]=propertiesIn[key];

        return properties;


    @classmethod
    def dumpParsedStyles():
        print (LVGL_Style.styles)

