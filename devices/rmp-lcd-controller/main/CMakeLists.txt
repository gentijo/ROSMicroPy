message ("\r\nIn main component cmake file")

message ("\r\n Project Dir: ${PROJECT_DIR}")
message ("\r\n CMake Source Dir: ${CMAKE_SOURCE_DIR}")
message ("\r\n Component Dir is ${COMPONENT_DIR}")
  
idf_component_register(
    SRCS 
    "main.cpp" 
    "ui/ui.c" 
    "ui/ui_helpers.c" 
    "ui/screens/ui_Screen1.c"
    "display-config/ESP32S3_8048S070C/Display.cpp"
   
    INCLUDE_DIRS 
    "."
    "display-config/ESP32S3_8048S070C")
