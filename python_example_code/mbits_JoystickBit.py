from machine import Pin, ADC
import machine
from time import sleep

class mbits_joystickbit():
    
    def __init__(self) -> None:
        self.xaxis = ADC(Pin(32))
        self.xaxis.atten(ADC.ATTN_11DB)

        self.yaxis = ADC(Pin(25))
        self.yaxis.atten(ADC.ATTN_11DB)
        
        self.bUp =    machine.Pin(18, machine.Pin.IN, machine.Pin.PULL_UP)
        self.bDown =  machine.Pin(19, machine.Pin.IN, machine.Pin.PULL_UP)
        self.bRight = machine.Pin(15, machine.Pin.IN, machine.Pin.PULL_UP)
        self.bLeft  = machine.Pin(23, machine.Pin.IN, machine.Pin.PULL_UP)
                       
        self.xval:int = None
        self.yval:int = None
        self.bUpVal:int = None
        self.bDownVal:int = None
        self.bRightVal:int = None
        self.bLeftVal:int = None
        
        self.onButtonUp: callable[[int], None] = None
        self.onButtonDown: callable[[int], None] = None
        self.onButtonLeft: callable[[int], None] = None
        self.onButtonRight: callable[[int], None] = None
        self.onY: callable[[int], None] = None
        self.onX: callable[[int], None] = None

    def test2(self):
        pass
    
    def setbuttonUp(self, func):
        self.onButtonUp = func
        
    def set_onButtonDown(self, func: callable[[int], None]):
        self.onButtonDown = func
        
    def onButtonLeft(self, func: callable[[int], None]):
        self.onButtonLeft = func
        
    def onButtonRight(self, func: callable[[int], None]):
        self.onButtonRight = func
    
    def onY(self, func: callable[[int], None]):
        self.onY = func
        
    def onX(self, func: callable[[int], None]):
        self.onX = func
        
    def loop(self):
        
        #
        # Grab new values
        #
        xval:int = self.xaxis.read_u16() >> 8
        yval:int = self.yaxis.read_u16() >> 8
        
        bUpVal:int = self.bUp.value()
        bDownVal:int = self.bDown.value()
        bRightVal:int = self.bRight.value()
        bLeftVal:int = self.bLeft.value()
        
        #
        # Detect change and call back
        #
        if (self.xval):
            xdiff:int = self.xval - xval
            if ( abs(xdiff) > 10):
                if(self.onX):
                    self.onX(xval)
                
        if (self.yval):
            ydiff:int = self.yval - yval        
            if ( abs(ydiff) > 10):
                if(self.onY):
                    self.onY(yval)
        
        if (self.bUpVal):
            if (self.bUpVal != bUpVal):
                if (self.onButtonUp):
                    self.onButtonUp(bUpVal)

        if (self.bDownVal):
            if (self.bDownVal != bDownVal):
                if (self.onButtonDown):
                    self.onButtonDown(bDownVal)
                
        if (self.bRightVal):
            if (self.bRightVal != bRightVal):
                if (self.onButtonRight):
                    self.onButtonRight(bRightVal)
                
        if (self.bLeftVal):
            if (self.bLeftVal != bLeftVal):
                if (self.onButtonLeft):
                    self.onButtonLeft(bLeftVal)
        
        #
        # Store last read values in self.
        #
        self.xval = xval
        self.yval = yval
        
        self.bUpVal = bUpVal
        self.bDownVal = bDownVal
        self.bRightVal = bRightVal
        self.bLeftVal = bLeftVal

    def printValues(self):
        print(f"x axis {self.xval}")
        print(f"y axis {self.yval}")
        
        print(f"Up {self.bUpVal}")
        print(f"Down {self.bDownVal}")
        print(f"left {self.bRightVal}")
        print(f"right {self.bLeftVal}")
            
    def test(self):
        while True:
            self.loop()
            self.printValues()
            sleep(0.1)


    #def Vibration_Motor(time: number) -> None: 
    #    pins.digitalWritePin(DigitalPin.P16, 0)
    #    basic.pause(time)
    #    pins.digitalWritePin(DigitalPin.P16, 1)
    
