message("Begining of MP CMake")

# Set location of base MicroPython directory.
get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)

get_filename_component(MICROPY_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)

get_filename_component(MICROPY_UROS_BASE_DIR ${PROJECT_DIR}/../../extra_packages/micropython ABSOLUTE)
get_filename_component(MICROPY_UROS_MODULE_DIR ${MICROPY_UROS_BASE_DIR}/mp_uros_modules ABSOLUTE)
get_filename_component(MICROPY_UROS_TYPE_SUPPORT_DIR ${MICROPY_UROS_BASE_DIR}/mp_uros_type_support ABSOLUTE)
get_filename_component(MICROPY_UROS_PORT_DIR ${MICROPY_DIR}/ports/esp32 ABSOLUTE)

get_filename_component(MICROROS_INC_DIR ${PROJECT_DIR}/../../extra_packages/libmicroros/include ABSOLUTE)

message ("Project Dir: ${PROJECT_DIR}")
message ("CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("Micropython Dir: ${MICROPY_DIR}")
message ("Micropython Port Dir: ${MICROPY_PORT_DIR}")
message ("MicroROS INC Dir: ${MICROROS_INC_DIR}")
message ("MICROPY_UROS_BASE_DIR : ${MICROPY_UROS_BASE_DIR}")
message ("MICROPY_UROS_MODULE_DIR : ${MICROPY_UROS_MODULE_DIR}")
message ("MICROPY_UROS_TYPE_SUPPORT_DIR : ${MICROPY_UROS_TYPE_SUPPORT_DIR}")
message ("IDF_TARGET : ${IDF_TARGET}")
message ("EXTRA_COMPONENT_DIRS: ${EXTRA_COMPONENT_DIRS} ")
