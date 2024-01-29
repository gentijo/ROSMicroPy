from ROSMicroPy import registerDataType, dumpDataType,  registerEventSubscription, run_ROS_Stack, init_ROS_Stack
import gc
import time
from rostype.Twist import Twist

def ros_event_callback(data):
    print("Ros did something")
    print(data)
 
print("\r\nInit ROS Stack\r\n")
init_ROS_Stack()

print("Registgering Data Type\r\n")
typeName = registerDataType(Twist.dataMap)
dumpDataType(typeName)

print("Registgering Event Subscription\r\n")
registerEventSubscription("/turtle1/cmd_vel", typeName, ros_event_callback)

print("Run ROS Stack\r\n")
run_ROS_Stack()  

#while True:
#    print("In Main Thread")
#    time.sleep(2)
    
    
    
    
    
    