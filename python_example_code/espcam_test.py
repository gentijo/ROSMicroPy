import gc
import time
import wifi
from ROSMicroPy import registerDataType, dumpDataType, registerEventSubscription, run_ROS_Stack, init_ROS_Stack, registerROSPublisher, publishMsg


print("\r\nInit ROS Stack\r\n")
init_ROS_Stack()

