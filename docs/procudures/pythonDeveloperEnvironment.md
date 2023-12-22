# The Python Development Environment

 A device loaded with ROSMicroPy can opeate as a stand alone device where it can read sensor values and perform operations like turning on a light or fan.  In this Mode, you are only taking advantage of the Micropython section of the product. When you start to couple that to the larger ROS system, magic starts to happen because it's both possible to run a simpler setup where a remote control can send messages to operate a remote device along with particpating in a larger installation utilizing more ROS services, or combine a RC remote that performs basic manuavers then in conjuction with a ROS Service that is using Machine Learning to recognize a situation and react as a copilot. ROSMicroPy allows you to grow from small setup targeted to children 10 years old and above and alos allow a broad range of expansion to provide follow on growth opurtunity for the Python developer interested in robotics.  

 To participate in the ROS network, there are some prerequsits that need to be configured and running to support the whole system. This project has included container definitions that allow the end user to launch these service without needing to learn about the networking of ROS. 

 ## Prerequsits:
  + A compute platform with Docker or other Container systems installed. This project currently only supports Docker with the legacy build system.
  + At a miniumn, the [Agent](../containerSupport/containerROSAgent.md) container needs to be running. This is the component that acts as the message router and a gateway other ROS services possibably living in the cloud.  
  + Optional Components, the TeleopKey service. This is a simple service to setup that will send cmd_vel messages when the arrow keys are hit and will route them to your ROSMicroPy device. 
    + The TeleopKey service elements the need to build a custom service or controller, so the developer can focus on the device and how it interact with other real world devices.
    + The ROSConsole, this is a service that will allow you to run ROS's graphical UI compontnts such as rqt that help you visualize the topagraphical make up of your ROS system and capture debug information 