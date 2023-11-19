
class ROSTypeSupport:
    
    def __init__:
        if not dataMap: self.dataMap = []
        
    def getDataMap():
        return self.dataMap
    
    def getValueByName(name=""):
        for data in dataMap:
            if (data.name == name):
                return data
        return None
    
    def getValueByIndex(index=0):
        return dataMap[index]