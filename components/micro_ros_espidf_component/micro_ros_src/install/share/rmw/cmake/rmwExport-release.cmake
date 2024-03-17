#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rmw::rmw" for configuration "Release"
set_property(TARGET rmw::rmw APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rmw::rmw PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librmw.a"
  )

list(APPEND _cmake_import_check_targets rmw::rmw )
list(APPEND _cmake_import_check_files_for_rmw::rmw "${_IMPORT_PREFIX}/lib/librmw.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
