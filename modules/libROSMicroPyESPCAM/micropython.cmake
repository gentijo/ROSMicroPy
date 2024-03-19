# Create an INTERFACE library for our C module.
add_library(libROSMicroPyESPCAM INTERFACE)


get_filename_component(MICROROS_INC_DIR ../../../../components/micro_ros_espidf_component/include ABSOLUTE)
message("MicroRos ${MICROROS_INC_DIR}")

set (ROS_MICROPY_ESPCAM_SRC
    ${MOD_ROS_MICROPY_ESPCAM_DIR}/main.cpp

)

set (ROS_MICROPY_ESPCAM_INC  
    "."
    ${MICROROS_INC_DIR}/std_msgs
    ${MICROROS_INC_DIR}/sensor_msgs
    ${MICROROS_INC_DIR}/sensor_msgs
    ${MICROROS_INC_DIR}/rosidl_typesupport_introspection_c
)

# Add our source files to the lib
target_sources(libROSMicroPyESPCAM INTERFACE
    ${ROS_MICROPY_ESPCAM_SRC}
)

# Add the current directory as an include directory.
target_include_directories(libROSMicroPyESPCAM INTERFACE
    ${ROS_MICROPY_ESPCAM_INC}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE libROSMicroPyESPCAM)

