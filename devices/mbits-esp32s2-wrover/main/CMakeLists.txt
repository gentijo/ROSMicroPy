message ("\r\nIn main component cmake file")

message ("\r\n Project Dir: ${PROJECT_DIR}")
message ("\r\n CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("\r\n Micropython Dir: ${MICROPY_DIR}")
message ("\r\n Micropython Port Dir: ${MICROPY_PORT_DIR}")
message ("\r\n Component Dir is ${COMPONENT_DIR}")  

idf_component_register (
    SRCS 
        "ros_app.cpp" 

    INCLUDE_DIRS 
        "./"
        ${PROJECT_DIR}../../../libs/micropython/
#        ${PROJECT_DIR}../../../extra_packages/microros/include
        ${CMAKE_BINARY_DIR}

        
    REQUIRES 
 #       micropython 
)

