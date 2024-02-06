# ROSMicroPy

## [Click here to view ROSMicroPy source code repository](https://github.com/gentijo/ROSMicroPy)

**ROSMicroPy is a tightly coupled integration of MicroROS and Micropython, multithreaded, async message, Python based ROS2 firmware for embedded microprocessor devices** 

## Features Include

### [SDK to control the ROS Stack](./extra_packages/ROSMicroPy/README.md)
+ Start / Stop ROS Stack
+ Set the Address of the ROS Agent
+ Set the Node name of the device
+ Publish messages
+ Subscribe to messages
+ Run a server process
+ Support for all standard ROS and Custom Types
+ On device, dynamic on-the-fly, type creation

### Full Container Support
 How to's on creating the supporting containers include:
 + **[Creating a container for Firmware development](./docs/containerSupport/containerDevEnv.md)**
 + **[Creating a container to run the ROS Agent](./docs/containerSupport/containerROSAgent.md)**
 + **[Creating a container to run TeleopKey from Turtlesim](./docs/containerSupport/containerTeleopKey.md)**
 + **[Creating a container to run graphical ROS apps](./docs/containerSupport/containerROSConsole.md)**

### How to get started 
+ **[Flash device and run](./docs/procudures/flashDevice.md)**
+ **[Introduction do Python / ROS Robot Coder Development](./docs/python-dev/welcome.md)**

+ **[*Advanced:* How to setup the firmware development environment](docs/procudures/firmwareDeveloperEnvironment.md)**

### Thonny Support
    - **[Plugin to compile ROS Types and store to the device](/docs/thonny/thonnyROSTypeSupportPlugin.md)**

### ROSMicro Type Support

+ **[Running the ROS Type Python generator ](./docs/procudures/typeSupport-Parser.md)**

### Compiling ROSMicroPy
 
### Micropython ROS Intergration Details
+ [Build System](./docs/implementation/buildSystem.md)
+ [Connecting the different Threading Models](./docs/implementation/threadingModels.md)
+ [Type Support](./docs/implementation/typeSupport.md)
+ [Subscribing to an event](./docs/implementation/eventSubscription.md)
+ [Callback functions on Message Receive events](./docs/implementation/messageCallback.md)
+ [Publishing ROS messages](./docs/implementation/messagePublishing.md)
+ [ROS Server support](./docs/implementation/rosServer.md)