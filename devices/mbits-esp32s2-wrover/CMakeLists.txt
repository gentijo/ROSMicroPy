cmake_minimum_required(VERSION 3.16)

set(IDF_TARGET esp32)

get_filename_component(PROJECT_DIR "./" ABSOLUTE)
message("Project Dir is ${PROJECT_DIR}")  

get_filename_component(COMPONENT_DIR ${PROJECT_DIR}/../../extra_packages ABSOLUTE)
message("Component Dir is ${COMPONENT_DIR}")  

list(APPEND EXTRA_COMPONENT_DIRS 
    ${COMPONENT_DIR}/libmicroros
    ${COMPONENT_DIR}/ROSMicroPy
)

 list(APPEND IDF_COMPONENTS
#    ${COMPONENT_DIR}/libmicroros
#    ${COMPONENT_DIR}/ROSMicroPy
 )

#include($ENV{IDF_PATH}/tools/cmake/component.cmake)
#include($ENV{IDF_PATH}/tools/cmake/idf.cmake)
#include($ENV{IDF_PATH}/tools/cmake/targets.cmake)
#include($ENV{IDF_PATH}/tools/cmake/utilities.cmake)

#include(ExternalProject )

# Define the output sdkconfig so it goes in the build directory.
#set(SDKCONFIG ${CMAKE_BINARY_DIR}/sdkconfig)

set(SDK_CONFIG_FILE_IN          ${PROJECT_DIR}/sdkconfig.defaults)
set(SDK_CONFIG_FILE             ${PROJECT_DIR}/sdkconfig.combined)
set(SDK_CONFIG_FILE_BUILD       ${CMAKE_BINARY_DIR}/sdkconfig.combined)

# Concatenate all sdkconfig files into a combined one for the IDF to use.
#file(WRITE ${SDK_CONFIG_FILE} "")

#file(READ ${MICROPY_SDK_CONFIG_FILE_IN} CONTENTS)
#file(APPEND ${SDK_CONFIG_FILE} "${CONTENTS}")

#file(READ ${SDK_CONFIG_FILE_IN} CONTENTS)
#file(APPEND ${SDK_CONFIG_FILE} "${CONTENTS}")

#configure_file(${SDK_CONFIG_FILE_IN} ${SDK_CONFIG_FILE_BUILD} )

#set(SDK_CONFIG_DEFAULTS ${SDK_CONFIG_FILE_BUILD})
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(mbits-esp32s2-wrover)



