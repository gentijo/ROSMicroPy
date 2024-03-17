#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c" for configuration "Release"
set_property(TARGET rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librosidl_typesupport_introspection_c.a"
  )

list(APPEND _cmake_import_check_targets rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c )
list(APPEND _cmake_import_check_files_for_rosidl_typesupport_introspection_c::rosidl_typesupport_introspection_c "${_IMPORT_PREFIX}/lib/librosidl_typesupport_introspection_c.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
