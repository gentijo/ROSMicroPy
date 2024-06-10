
from ROSMicroPyGUI import rmp_init_lcd_display
import time

rmp_init_lcd_display()
print("return from init display")

while True:
    print("Main Loop\r\n")
    time.sleep(2)
