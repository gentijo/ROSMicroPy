cmake_minimum_required(VERSION 3.16)
message ("In Main CMake File")

get_filename_component(PROJECT_DIR "./" ABSOLUTE)
message("Project Dir is ${PROJECT_DIR}")  

get_filename_component(COMPONENT_DIR ${PROJECT_DIR}/../../extra_packages ABSOLUTE)
message("Component Dir is ${COMPONENT_DIR}") 

get_filename_component(MICROPY_DIR ${PROJECT_DIR}/../../libs/micropython ABSOLUTE)
message("MicroPy Dir: ${MICROPY_DIR}")

set(MICROPY_ARCH esp32)
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

list(APPEND EXTRA_COMPONENT_DIRS 
    ${COMPONENT_DIR}/libmicroros
    ${COMPONENT_DIR}/ROSMicroPy
)


file(WRITE ${CMAKE_BINARY_DIR}/sdkconfig.combined.in "")

#
# Project Config
#
file(READ   ${PROJECT_DIR}/sdkconfig CONTENTS)
file(APPEND ${CMAKE_BINARY_DIR}/sdkconfig.combined.in "${CONTENTS}")


#
# Micropython Config
#
message("\r\n\nSDK Defaults ${SDKCONFIG_DEFAULTS}")
message("MICROPY Archdir: ${MICROPY_ARCH_DIR}")
include(${MICROPY_BOARD_DIR}/mpconfigboard.cmake)

foreach(SDKCONFIG_DEFAULT ${SDKCONFIG_DEFAULTS})
    set(SDKCONFIG_DEFAULT_FULLPATH ${MICROPY_ARCH_DIR}/${SDKCONFIG_DEFAULT})
    message("SDK DEFAULT: ${SDK_DEFAULT_FULLPATH}")
    file(READ ${SDKCONFIG_DEFAULT_FULLPATH} CONTENTS)
    file(APPEND ${CMAKE_BINARY_DIR}/sdkconfig.combined.in "${CONTENTS}")
endforeach()
configure_file(${CMAKE_BINARY_DIR}/sdkconfig.combined.in ${CMAKE_BINARY_DIR}/sdkconfig COPYONLY)
set(SDKCONFIG_DEFAULTS ${CMAKE_BINARY_DIR}/sdkconfig)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(mbits-esp32s2-wrover)



