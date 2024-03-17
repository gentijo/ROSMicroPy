# Create an INTERFACE library for our C module.
add_library(libROSMicroPyGUI INTERFACE)


get_filename_component(ROS_MICROPY_GUI_DIR ../../../../modules/libROSMicroPyGUI ABSOLUTE)
set (ROS_MICROPY_GUI_SRC
    ${ROS_MICROPY_GUI_DIR}/main.c
    ${ROS_MICROPY_GUI_DIR}/ui/ui.c 
    ${ROS_MICROPY_GUI_DIR}/ui/ui_helpers.c 
    ${ROS_MICROPY_GUI_DIR}/ui/screens/ui_Screen1.c
    ${ROS_MICROPY_GUI_DIR}/lcd-display-drivers/ESP32S3_8048S070C/Display.c
#    ${ROS_MICROPY_GUI_DIR}/mp/lv_mp.c
#    ${ROS_MICROPY_GUI_DIR}/mp/lv_espidf.c

)

set (ROS_MICROPY_GUI_INC  
    "."
#    ${ROS_MICROPY_GUI_DIR}/lcd-display-drivers/
)

# Add our source files to the lib
target_sources(libROSMicroPyGUI INTERFACE
    ${ROS_MICROPY_GUI_SRC}
)

# Add the current directory as an include directory.
target_include_directories(libROSMicroPyGUI INTERFACE
    ${ROS_MICROPY_GUI_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE libROSMicroPyGUI)

