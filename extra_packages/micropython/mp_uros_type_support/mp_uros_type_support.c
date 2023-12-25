#include "mp_uros_type_support.h"


#define MICROXRCEDDS_PADDING sizeof(uint32_t)

rosidl_message_type_support_t* mpy_uros_type_support_slots[25];

  /**
   *
   *
   */
  bool mpy_uros_typesupport_cdr_serialize(int slot, const void *untyped_ros_message, ucdrBuffer *cdr)
  {
    (void)untyped_ros_message;
    (void)cdr;

    bool rv = false;

    if (!untyped_ros_message)
    {
      return false;
    }
    return rv;
  }

  ros_subscription* ros_sub_test(ros_subscription* sub )
  {
    sub->eventName = NULL;
    return sub;
  }
  
  ros_subscription* ros_sub;
  mp_obj_t type;

//   size_t mp_obj_namedtuple_find_field(const mp_obj_namedtuple_type_t *type, qstr name) {
//     for (size_t i = 0; i < type->n_fields; i++) {
//         if (type->fields[i] == name) {
//             return i;
//         }
//     }
//     return (size_t)-1;
// }

  /**
   *
   *
   */
  bool mpy_uros_typesupport_cdr_deserialize(int slot, ucdrBuffer *cdr, void *untyped_ros_message)
  {
    (void)cdr;

    bool rv = true;

    if (!untyped_ros_message)
    {
      return false;
    }

    void **ros_mesg = untyped_ros_message;

    ros_sub = get_ROS_Sub_from_slot(slot);

    double double_val;
    
    mp_obj_t linear = mp_obj_new_dict(3);

    rv = ucdr_deserialize_double(cdr, &double_val);
    printf("X: %lf", double_val);
    linear = mp_obj_dict_store(linear, mp_obj_new_str("x", 1), mp_obj_new_float(double_val));
    
    rv = ucdr_deserialize_double(cdr, &double_val);
    printf("y: %lf", double_val);
    linear = mp_obj_dict_store(linear, mp_obj_new_str("y", 1), mp_obj_new_float(double_val));

    rv = ucdr_deserialize_double(cdr, &double_val);
    printf("z: %lf", double_val);
    linear = mp_obj_dict_store(linear, mp_obj_new_str("z", 1), mp_obj_new_float(double_val));

    mp_obj_t angular = mp_obj_new_dict(3);
    rv = ucdr_deserialize_double(cdr, &double_val);
    angular = mp_obj_dict_store(angular, mp_obj_new_str("x", 1), mp_obj_new_float(double_val));
    
    rv = ucdr_deserialize_double(cdr, &double_val);
    angular = mp_obj_dict_store(angular, mp_obj_new_str("y", 1), mp_obj_new_float(double_val));

    rv = ucdr_deserialize_double(cdr, &double_val);
    angular = mp_obj_dict_store(angular, mp_obj_new_str("z", 1), mp_obj_new_float(double_val));

    mp_obj_t message = mp_obj_new_dict(2);
    message = mp_obj_dict_store(message, mp_obj_new_str("linear", 6), linear);
    message = mp_obj_dict_store(message, mp_obj_new_str("angular", 7), angular);
    *ros_mesg = message;

    //    mp_store_global(MP_QSTR_make_dict, MP_OBJ_FROM_PTR(&make_dict_obj));

    return rv;
  }

  /**
   *
   *
   *
   */
  size_t mpy_uros_typesupport_get_serialized_size(int slot, const void *mp_obj, size_t current_alignment)
  {
    bool rv = false;

    if (!mp_obj)
    {
      return 0;
    }

    const size_t initial_alignment = current_alignment;

    return current_alignment - initial_alignment;
  }

  /**
   *
   *
   *
   */
  uint32_t mpy_uros_typesupport_get_initial_serialized_size(int slot, const void *mp_obj)
  {
    return (uint32_t)(mpy_uros_typesupport_get_serialized_size(slot, mp_obj, 0));
  }

  /**
   *
   *
   *
   */
  size_t mpy_uros_typesupport_get_max_serialized_size(int slot, bool *full_bounded, size_t current_alignment)
  {
    (void)current_alignment;
    *full_bounded = true;

    const size_t initial_alignment = current_alignment;

    return current_alignment - initial_alignment;
  }

  void init_mpy_uros_typesupport(void) 
  {
    
    for(int x=0; x<cnt_ros_type_support_slots; x++) {
      mpy_uros_type_support_slots[x]=NULL;
    }

    bool mpy_uros_ts0_serialize(const void *untyped_ros_message, ucdrBuffer *cdr) {
      return mpy_uros_typesupport_cdr_serialize(0, untyped_ros_message, cdr);
    }

    bool mpy_uros_ts0_deserialize(ucdrBuffer *cdr, void *untyped_ros_message) {
      return mpy_uros_typesupport_cdr_deserialize(0, cdr, untyped_ros_message);
    }

    size_t mpy_uros_ts0_get_serialized_size(const void *mp_obj, size_t current_alignment) {
      return mpy_uros_typesupport_get_serialized_size(0, mp_obj, current_alignment);
    }

    uint32_t mpy_uros_ts0_get_initial_serialized_size(const void *mp_obj) {
      return mpy_uros_typesupport_get_initial_serialized_size(0, mp_obj);
    }

    size_t mpy_uros_ts0_get_max_serialized_size(bool *full_bounded, size_t current_alignment){
      return mpy_uros_typesupport_get_max_serialized_size(0, full_bounded, current_alignment);
    }

    message_type_support_callbacks_t *mpy_uros_ts1_cb = 
      malloc(sizeof(message_type_support_callbacks_t));
    
    char *str = "geometry_msgs::msg";
    char *data = strdup(str);
    mpy_uros_ts1_cb->message_namespace_ = data;
    str = "Twist";
    data = strdup(str);
    mpy_uros_ts1_cb->message_name_ = data;

    mpy_uros_ts1_cb->cdr_serialize = mpy_uros_ts0_serialize;
    mpy_uros_ts1_cb->cdr_deserialize = mpy_uros_ts0_deserialize;
    mpy_uros_ts1_cb->get_serialized_size = mpy_uros_ts0_get_initial_serialized_size;
    mpy_uros_ts1_cb->get_serialized_size_with_initial_alignment = mpy_uros_ts0_get_serialized_size;
    mpy_uros_ts1_cb->max_serialized_size = mpy_uros_ts0_get_max_serialized_size;
    
    mpy_uros_type_support_slots[0]=malloc(sizeof(rosidl_message_type_support_t));
    mpy_uros_type_support_slots[0]->typesupport_identifier = strdup(ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE);
    mpy_uros_type_support_slots[0]->data = mpy_uros_ts1_cb;
    mpy_uros_type_support_slots[0]->func = get_message_typesupport_handle_function;

  }
