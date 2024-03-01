# ROSMicroPy LCD Controller.

## Goals
* Create an ESP32 based device using cost effective LCD Displays
* Have a Drag and Drop development experience where ROS Wodgets can be added to a screen and participte with the ROS ecosystem
* Utilize Switch JoyCons as extra input sources. 
* Have Fun

## Theroy
### Based on ROSMicroPy
Add support for LVGL on cost effictive LCD displays such as https://www.aliexpress.us/item/3256804913729039.htm

### Layout manager that provides a data driven layout definition
 Providing an interfsace to allow screen design developed externally (Web Based) then upload the Display definiton to the device.

### Display definition can produce actions 
That can be tied to Micropython functions to allow for sending a ROS Message onEvent

### Display definition
 Input based i.e. a button that will trigger a ROS routine or output based, subscribing to ROS events. i.e. a Video widget that can attach to an RTSP video stream that can be displayed in realtime on the screen

### Screen Layout Definitiosn
Current canidate for managing Layouts is [JSON Forms](https://jsonforms.io/)

### Screen Builder IDE's
* [JSON Forms Editor](https://jsonforms-editor.netlify.app)
* [Form.io's Aurelia editor](https://github.com/formio/aurelia-formio) see [Demo](https://formio.github.io/aurelia-formio/)

## Prototype

![Front](../../docs/images/SwitchFrontv2.png)
![Back](../../docs/images/SwitchBackv2.png)
