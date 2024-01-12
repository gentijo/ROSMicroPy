from ROSMicroPy import registerDataType, dumpDataType, registerEventSubscription, run_ROS_Stack, init_ROS_Stack
from rostype.Twist import Twist

dataMap = {
    "type": "Twist",
    "components": [
        {
            "name": "linear",
            "type": "Vector3",
            "components": [
                {
                    "name": "x",
                    "type": "float64"
                },
                {
                    "name": "y",
                    "type": "float64"
                },
                {
                    "name": "z",
                    "type": "float64"
                }
            ]
        },
        {
            "name": "angular",
            "type": "Vector3",
            "components": [
                {
                    "name": "x",
                    "type": "float64"
                },
                {
                    "name": "y",
                    "type": "float64"
                },
                {
                    "name": "z",
                    "type": "float64"
                }
            ]
        }
    ]
}

init_ROS_Stack()

type = registerDataType(dataMap)

dumpDataType(type)



