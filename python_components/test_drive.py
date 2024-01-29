from mbits_maqueen_drive import mbits_maqueen_drive
from machine import I2C, Pin

i2c = I2C(0,scl=Pin(21), sda=Pin(22), freq=10000)

test = mbits_maqueen_drive(i2c)
test.forward(40)
