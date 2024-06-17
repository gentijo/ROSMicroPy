# Create an INTERFACE library for our C module.
add_library(ROS_MICROPY_WIDGETS INTERFACE)


get_filename_component(MICROPY_WIDGET_DIR ../../../../modules/lib_ROSMicroPyWidgets ABSOLUTE)


set (MICROPY_WIDGET_SRC
    ${MICROPY_WIDGET_DIR}/main.c
    ${MICROPY_WIDGET_DIR}/widgets/ros-video/ros_video_widget.cpp
)


set (MICROPY_WIDGET_INC  
    "."
)

# Add our source files to the lib
target_sources(ROS_MICROPY_WIDGETS INTERFACE
    ${MICROPY_WIDGET_SRC}
)

# Add the current directory as an include directory.
target_include_directories(ROS_MICROPY_WIDGETS INTERFACE
    ${MICROPY_WIDGET_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE ROS_MICROPY_WIDGETS)

