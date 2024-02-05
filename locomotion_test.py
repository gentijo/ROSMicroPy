from mbits_Maqueen_locomotion import mbits_maqueen_drive
from machine import SoftI2C, Pin

i2c = SoftI2C(scl=Pin(19), sda=Pin(20), freq=400000)

test = mbits_maqueen_drive(i2c)
test.drive_forward(40, 40)
