message ("\r\nIn main component cmake file")

message ("\r\n Project Dir: ${PROJECT_DIR}")
message ("\r\n CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("\r\n Micropython Dir: ${MICROPY_DIR}")
message ("\r\n Micropython Port Dir: ${MICROPY_PORT_DIR}")
message ("\r\n Component Dir is ${COMPONENT_DIR}")  


idf_component_register (
    SRCS 

    INCLUDE_DIRS 
        ${CMAKE_BINARY_DIR}
    REQUIRES 
 #       micropython 
)
