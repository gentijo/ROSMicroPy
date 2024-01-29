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
        
        self.onButtonUp = None
        self.onButtonDown = None
        self.onButtonLeft = None
        self.onButtonRight = None
        self.onY = None
        self.onX = None

    def onButtonUp(self, func):
        self.onButtonUp = func
        
    def onButtonDown(self, func):
        self.onButtonDown = func
        
    def onButtonLeft(self, func):
        self.onButtonLeft = func
        
    def onButtonRight(self, func):
        self.onButtonRight = func
    
    def onY(self, func):
        self.onY = func
        
    def onX(self, func):
        self.onX = func
        
    def loop(self):
        
        #
        #
        # Grab new values
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

    def print(self):
        print(f"x axis {self.xval}")
        print(f"y axis {self.yval}")
        
        print(f"Up {self.bUpVal}")
        print(f"Down {self.bDownVal}")
        print(f"left {self.bRightVal}")
        print(f"right {self.bLeftVal}")
            
    def test(self):
        while True:
            self.loop()
            self.print()
            sleep(0.1)


    #def Vibration_Motor(time: number) -> None: 
    #    pins.digitalWritePin(DigitalPin.P16, 0)
    #    basic.pause(time)
    #    pins.digitalWritePin(DigitalPin.P16, 1)
 
def _onButtonChange(val:int):
    print("On Button Change")
    
def _onJoystickChange(val:int):
    print("On Joystick Change")
    

foo = mbits_joystickbit()
foo.onButtonUp(_onButtonChange)
foo.onX(_onJoystickChange)
_onButtonChange(10)

#foo.test()
