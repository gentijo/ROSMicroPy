#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "mp_uros_type_support_visibility_control.h"


// #ifndef _WIN32
// # pragma GCC diagnostic push
// # pragma GCC diagnostic ignored "-Wunused-parameter"
// # ifdef __clang__
// #  pragma clang diagnostic ignored "-Wdeprecated-register"
// #  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
// # endif
// #endif
// #ifndef _WIN32
// # pragma GCC diagnostic pop
// #endif

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

/**
 * 
 * 
*/
static bool mpy_uros_typesupport_cdr_serialize( const void * untyped_ros_message, ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  return rv;
}


/**
 * 
 * 
 * 
*/
static bool mpy_uros_typesupport_cdr_deserialize(ucdrBuffer * cdr, void * untyped_ros_message)
{
  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  // // Field name: x
  // rv = ucdr_deserialize_double(cdr, &ros_message->x);
  // // Field name: y
  // rv = ucdr_deserialize_double(cdr, &ros_message->y);
  // // Field name: z
  // rv = ucdr_deserialize_double(cdr, &ros_message->z);
  return rv;
}

/**
 * 
 * 
 * 
*/
//ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_EXPORT_mpy_uros_msgs
size_t mpy_uros_typesupport_get_serialized_size(const void * mp_obj, size_t current_alignment)
{
  bool rv = false;

  if (!mp_obj) {
    return 0;
  }

  const size_t initial_alignment = current_alignment;

  // // Member: x
  // {
  //   const size_t item_size = sizeof(ros_message->x);
  //   current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  // }
  // // Member: y
  // {
  //   const size_t item_size = sizeof(ros_message->y);
  //   current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  // }
  // // Member: z
  // {
  //   const size_t item_size = sizeof(ros_message->z);
  //   current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  // }

  return current_alignment - initial_alignment;

}


/**
 * 
 * 
 * 
*/
// ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_EXPORT_mpy_uros_msgs
static uint32_t mpy_uros_typesupport_get_initial_serialized_size(const void * mp_obj)
{
  return (uint32_t)(
    mpy_uros_typesupport_get_serialized_size(mp_obj, 0));
}


/**
 * 
 * 
 * 
*/
size_t mpy_uros_typesupport_get_max_serialized_size(bool * full_bounded, size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // // Member: linear
  // current_alignment +=
  //   max_serialized_size_geometry_msgs__msg__Vector3(full_bounded, current_alignment);
  // // Member: angular
  // current_alignment +=
  //   max_serialized_size_geometry_msgs__msg__Vector3(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

/**
 * 
 * 
 * 
*/
// static size_t mpy_uros_typesupport_get_initial_max_serialized_size()
// {
//   // bool full_bounded;
//   // return mpy_uros_typesupport_max_serialized_size(&full_bounded, 0);
//   // return 0;
// }

/*
*
*
*/
message_type_support_callbacks_t callbacks_mpy_uros_type_support = {
  "micropython",
  "object",
  mpy_uros_typesupport_cdr_serialize,
  mpy_uros_typesupport_cdr_deserialize,
  mpy_uros_typesupport_get_initial_serialized_size,
  mpy_uros_typesupport_get_serialized_size,
  mpy_uros_typesupport_get_max_serialized_size
};

/**
 * 
*/
rosidl_message_type_support_t mpy_uros_type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &callbacks_mpy_uros_type_support,
  get_message_typesupport_handle_function,
};


#if defined(__cplusplus)
}
#endif
