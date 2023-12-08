  ## Development environment supported by this project. 
  
  Everything is based on containers and should work seemly on Linux / Mac hosts. On Windows it should also work seemlessly under WSL2 and with a couple of adjustments work on Windows directly.

  Containers definitions supplied:

  ***ROSNode***, this is a container to launch a ROS envirnment with support for XWindows to allow execution of rqt and other ROS visualization tools

  ***MicroROS agent***, this container runs the MicroROS agent exposing the udp port 8888 to allow the container to participate on the ROS network allowing the MicroROS agent to connect to MicroROS devices. 

  ***MicroROS Teleop Agent***, this runs the ROS Telop Agent to send messages to ROSNodes.

  ***Dev Environment Container*** this container contains the build tools for the ESP platform. This container is used to build the source code and flash it to the device. There is a Host platform dependancy for this container that the /dev file system exists so the container can access the Host serial ports (USB or Phyiscal)

![Development Environment](./Development%20Environment.svg)