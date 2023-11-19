from rostype.Vector3 import Vector3
#from ROSTypeSupport import ROSTypeSupport

class Twist():
    
    def __init__(self):
        self.dataMap = [
            {
            "name":"linear",
            "type":"Vector3",
            "components": [
            {"name":"x", "type":"Double"},
            {"name":"y", "type":"Double"},
            {"name":"z", "type":"Double"}]
            },
                        
            {
            "name":"angular",
            "type":"Vector3",
            "components":[
            {"name":"x", "type":"Double"},
            {"name":"y", "type":"Double"},
            {"name":"z", "type":"Double"}]

            }
        ]


