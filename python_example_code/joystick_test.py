from mbits_JoystickBit import mbits_joystickbit

def _onButtonChange(val):
    print("On Button Change")
    
def _onJoystickChange(val:int) -> None:
    print("On Joystick Change")
    

foo = mbits_joystickbit()
foo.onButtonUp( _onButtonChange )
foo.onX(_onJoystickChange)


