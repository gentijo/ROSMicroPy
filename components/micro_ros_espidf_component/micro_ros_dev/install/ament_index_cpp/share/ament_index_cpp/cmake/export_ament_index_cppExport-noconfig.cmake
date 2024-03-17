#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ament_index_cpp::ament_index_cpp" for configuration ""
set_property(TARGET ament_index_cpp::ament_index_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(ament_index_cpp::ament_index_cpp PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libament_index_cpp.so"
  IMPORTED_SONAME_NOCONFIG "libament_index_cpp.so"
  )

list(APPEND _cmake_import_check_targets ament_index_cpp::ament_index_cpp )
list(APPEND _cmake_import_check_files_for_ament_index_cpp::ament_index_cpp "${_IMPORT_PREFIX}/lib/libament_index_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
