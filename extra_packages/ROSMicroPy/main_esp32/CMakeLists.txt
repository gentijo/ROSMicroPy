# Set location of base MicroPython directory.
if(NOT MICROPY_DIR)
    get_filename_component(MICROPY_DIR ${CMAKE_CURRENT_LIST_DIR}/../../.. ABSOLUTE)
endif()

# Set location of the ESP32 port directory.
if(NOT MICROPY_PORT_DIR)
    get_filename_component(MICROPY_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)
endif()

message("Including common dir [${ROS_MICROPY_DIR}] ${PROJECT_DIR}")

get_filename_component(ROS_MICROPY_DIR ${PROJECT_DIR}/../../extra_packages/ROSMicroPy ABSOLUTE)

message("MicroPy Dir: ${MICROPY_DIR}")
get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
message("MicroPy Dir: ${MICROPY_DIR}")

include(${ROS_MICROPY_DIR}/esp32_common.cmake)
