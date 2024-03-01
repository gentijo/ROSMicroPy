message(DEBUG "Begining of ROSMicroPy CMake")

set(MICROPY_ARCH esp32)

get_filename_component(ROS_MICROPY_DIR      ${PROJECT_DIR}/../../extra_packages/ROSMicroPy ABSOLUTE)
get_filename_component(MICROROS_INC_DIR     ${PROJECT_DIR}/../../extra_packages/libmicroros/include ABSOLUTE)


get_filename_component(MICROPY_UROS_MODULE_DIR ${ROS_MICROPY_DIR}/mp_uros_modules ABSOLUTE)
get_filename_component(MICROPY_UROS_TYPE_SUPPORT_DIR ${ROS_MICROPY_DIR}/mp_uros_type_support ABSOLUTE)

get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
message("MicroPy Dir: ${MICROPY_DIR}")

get_filename_component(MICROPY_ARCH_DIR ${MICROPY_DIR}/ports/${MICROPY_ARCH} ABSOLUTE)
message("MicroPy Arch Dir: ${MICROPY_ARCH_DIR}")

# Set the board if it's not already set.
if(NOT MICROPY_BOARD)
    set(MICROPY_BOARD ESP32_GENERIC)
endif()

# Set the board directory and check that it exists.
if(NOT MICROPY_BOARD_DIR)
    set(MICROPY_BOARD_DIR ${MICROPY_ARCH_DIR}/boards/${MICROPY_BOARD})
endif()


#get_filename_component(MICROPY_BOARD_DIR $(MICROPY_DIR)/ports/esp32

# Set the board if it's not already set.
if(NOT MICROPY_BOARD)
    set(MICROPY_BOARD ESP32_GENERIC)
endif()

message("Board: ${MICROPY_DIR}/ports/$IDF_TARGET/boards/${MICROPY_BOARD} ")
# Set the board directory and check that it exists.
if(NOT MICROPY_BOARD_DIR)
    set(MICROPY_BOARD_DIR ${MICROPY_DIR}/ports/$IDF_TARGET/boards/${MICROPY_BOARD})
endif()

set(ROS_MICROPY_MODULES
    #
    # Bind Python to ROS
    ${MICROPY_UROS_MODULE_DIR}/uros_mesg_func.c
    ${MICROPY_UROS_MODULE_DIR}/uros_base_func.c

    ${MICROPY_UROS_MODULE_DIR}/mp_uros_thread.c
    ${MICROPY_UROS_MODULE_DIR}/uros_mp_reg.c

    ${MICROPY_UROS_TYPE_SUPPORT_DIR}/mp_uros_type_support.c
    ${MICROPY_UROS_TYPE_SUPPORT_DIR}/mp_uros_dataTypeParser.c
    ${MICROPY_UROS_TYPE_SUPPORT_DIR}/mp_uros_type_support.c

)

list(APPEND MICROPY_SOURCE_QSTR
    ${ROS_MICROPY_MODULES}

)

list(APPEND MICROPY_SOURCE_EXTMOD
    ${MICROPY_UROS_MODULES}
)



list(APPEND ROS_MICROPY_INC_DIR
    ${MICROROS_INC_DIR}/rcl_action
    ${MICROROS_INC_DIR}/action_msgs
    ${MICROROS_INC_DIR}/unique_identifier_msgs
    ${MICROROS_INC_DIR}/builtin_interfaces
    ${MICROROS_INC_DIR}
    ${MICROROS_INC_DIR}/rcl
    ${MICROROS_INC_DIR}/rcutils
    ${MICROROS_INC_DIR}/rmw
    ${MICROROS_INC_DIR}/rosidl_runtime_c
    ${MICROROS_INC_DIR}/rosidl_typesupport_interface
    ${ROS_MICROPY_DIR}/mp_uros_modules
    ${ROS_MICROPY_DIR}/mp_uros_type_support


)

list(APPEND IDF_COMPONENTS libmicroros ROSMicroPy)



message ("Project Dir: ${PROJECT_DIR}")
message ("CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("Micropython Dir: ${MICROPY_DIR}")
message ("ROS MicroPy Dir: ${ROS_MICROPY_DIR}")

include( ${ROS_MICROPY_DIR}/micropython.cmake.txt )

