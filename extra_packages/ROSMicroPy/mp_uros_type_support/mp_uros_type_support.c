
#include "mp_uros_type_support.h"
#include "mp_uros_dataTypeParser.h"
#include "uros_mesg_func.h"
#include "rosidl_runtime_c/message_type_support_struct.h"



bool mpy_uros_typesupport_cdr_serialize(int slot, const void *untyped_ros_message, ucdrBuffer *cdr);
bool mpy_uros_typesupport_cdr_deserialize(int slot, ucdrBuffer *cdr, void *untyped_ros_message);
size_t mpy_uros_typesupport_get_serialized_size(int slot, const void *mp_obj, size_t current_alignment);
uint32_t mpy_uros_typesupport_get_initial_serialized_size(int slot, const void *mp_obj);
size_t mpy_uros_typesupport_get_max_serialized_size(int slot, bool *full_bounded, size_t current_alignment);

#define mpy_uros_type_support_slots 20
dxc_cb_t *g_typeSupportCtrlBlks[mpy_uros_type_support_slots];

/**
 * This specialized #define macro utilizes a feature in GCC where you can define functions in a function.
 * We will use this to define the Type Support functions but append a number that corresponds to an entry
 * in the typeSupport array entry. The functions defined call the real function and passes along a
 * slot number allowing the type support functions to have access to the schema data needed to process
 * data from Micropython to ROS
 */
#define typeSupportEntry(n)                                                                                                            \
  bool mpy_uros_ts##n##_serialize(const void *untyped_ros_message, ucdrBuffer *cdr)                                                    \
  {                                                                                                                                    \
    return mpy_uros_typesupport_cdr_serialize(n, untyped_ros_message, cdr);                                                            \
  }                                                                                                                                    \
  bool mpy_uros_ts##n##_deserialize(ucdrBuffer *cdr, void *untyped_ros_message)                                                        \
  {                                                                                                                                    \
    return mpy_uros_typesupport_cdr_deserialize(n, cdr, untyped_ros_message);                                                          \
  }                                                                                                                                    \
  size_t mpy_uros_ts##n##_get_serialized_size(const void *mp_obj, size_t current_alignment)                                            \
  {                                                                                                                                    \
    return mpy_uros_typesupport_get_serialized_size(n, mp_obj, current_alignment);                                                     \
  }                                                                                                                                    \
  uint32_t mpy_uros_ts##n##_get_initial_serialized_size(const void *mp_obj)                                                            \
  {                                                                                                                                    \
    return mpy_uros_typesupport_get_initial_serialized_size(n, mp_obj);                                                                \
  }                                                                                                                                    \
  size_t mpy_uros_ts##n##_get_max_serialized_size(bool *full_bounded, size_t current_alignment)                                        \
  {                                                                                                                                    \
    return mpy_uros_typesupport_get_max_serialized_size(n, full_bounded, current_alignment);                                           \
  }                                                                                                                                    \
                                                                                                                                       \
  dxc_cb_t *typeSupportCtrlBlk_##n = malloc(sizeof(dxc_cb_t));                                                                         \
  printf("ctrlblk %p\r\n", (void *)typeSupportCtrlBlk_##n);                                                                            \
                                                                                                                                       \
  typeSupportCtrlBlk_##n->ros_mesg_type_support = malloc(sizeof(rosidl_message_type_support_t));                                       \
  printf("type support %p\r\n", (void *)typeSupportCtrlBlk_##n->ros_mesg_type_support);                                                \
                                                                                                                                       \
  /* The DXIL will be allocated when a type is registered */                                                                           \
                                                                                                                                       \
  message_type_support_callbacks_t *mpy_uros_ts##n##_cb = malloc(sizeof(message_type_support_callbacks_t));                            \
  printf("type support cb %p\r\n", (void *)mpy_uros_ts##n##_cb);                                                                       \
                                                                                                                                       \
  mpy_uros_ts##n##_cb->cdr_serialize = mpy_uros_ts##n##_serialize;                                                                     \
  mpy_uros_ts##n##_cb->cdr_deserialize = mpy_uros_ts##n##_deserialize;                                                                 \
  mpy_uros_ts##n##_cb->get_serialized_size = mpy_uros_ts##n##_get_initial_serialized_size;                                             \
  mpy_uros_ts##n##_cb->get_serialized_size_with_initial_alignment = mpy_uros_ts##n##_get_serialized_size;                              \
  mpy_uros_ts##n##_cb->max_serialized_size = mpy_uros_ts##n##_get_max_serialized_size;                                                 \
                                                                                                                                       \
  typeSupportCtrlBlk_##n->ros_mesg_type_support->typesupport_identifier = strdup(ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE); \
  typeSupportCtrlBlk_##n->ros_mesg_type_support->data = mpy_uros_ts##n##_cb;                                                           \
  typeSupportCtrlBlk_##n->ros_mesg_type_support->func = get_message_typesupport_handle_function; \
  g_typeSupportCtrlBlks[n] = typeSupportCtrlBlk_##n; 


void init_mpy_ROS_TypeSupport(void)
{

  //    g_typeSupportCtrlBlks=malloc( (sizeof(dxc_cb_t) +4) * mpy_uros_type_support_slots);

  typeSupportEntry(0);
  typeSupportEntry(1);
  typeSupportEntry(2);
  typeSupportEntry(3);
  typeSupportEntry(4);
  typeSupportEntry(5);
  typeSupportEntry(6);
  typeSupportEntry(7);
  typeSupportEntry(8);
  typeSupportEntry(9);
  typeSupportEntry(10);
  typeSupportEntry(11);
  typeSupportEntry(12);
  typeSupportEntry(13);
  typeSupportEntry(14);
  typeSupportEntry(15);
  typeSupportEntry(16);
  typeSupportEntry(17);
  typeSupportEntry(18);
  typeSupportEntry(19);

  for (int x = 0; x < mpy_uros_type_support_slots; x++)
  {
    g_typeSupportCtrlBlks[x]->type = NULL;
    g_typeSupportCtrlBlks[x]->dxil = NULL;

    g_typeSupportCtrlBlks[x]->componentCount = 0;
    g_typeSupportCtrlBlks[x]->index = 0;
  }

  printf("Type support init complete\r\n");
}

dxc_cb_t *findTypeByName(const char *type)
{

  for (int x = 0; x < mpy_uros_type_support_slots; x++)
  {

    if (type == NULL)
      return NULL;
    if (strlen(type) == 0)
      return NULL;

    // See if we hit the end of the allocated blocks
    if (g_typeSupportCtrlBlks[x]->type == NULL)
      return NULL;

    if (strcmp(g_typeSupportCtrlBlks[x]->dxil->type, type) == 0)
      return g_typeSupportCtrlBlks[x];
  }

  return NULL;
}

dxc_cb_t *findAvailTypeSlot()
{

  for (int x = 0; x < mpy_uros_type_support_slots; x++)
  {
    if (g_typeSupportCtrlBlks[x]->type == NULL)
      return g_typeSupportCtrlBlks[x];
  }

  return NULL;
}
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


/**
 *
 *
 */
bool mpy_uros_typesupport_cdr_deserialize(int slot, ucdrBuffer *cdr, void *untyped_ros_message)
{
  (void)cdr;
  bool rv = true;
  mp_obj_stk_t obj_stack;

  if (!untyped_ros_message) {return false;}

  void **ros_mesg = untyped_ros_message;

  ros_subscription *rsub = get_ROS_Subscription(slot);
  dxil_t *dxil = rsub->dataTypeCtrlBlk->dxil;
  mp_obj_t mp_obj = mp_obj_new_dict(dxil->instructionList[0].shallowComponentCount);
  obj_stack.objects[0] = mp_obj;
  obj_stack.stkPtr=1;
  for (int x=0;  x < dxil->component_len; x++)  {
    dxil->instructionList[x].deserialize(slot, cdr, &dxil->instructionList[x], &obj_stack);
      if (dxil->instructionList[x].islastBlk) obj_stack.stkPtr--;
      if (obj_stack.stkPtr < 0) obj_stack.stkPtr=0;

  }

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



void deserializeROSType(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
  mp_obj_t dict = mp_obj_new_dict(inst->shallowComponentCount);
  mp_obj_t parent_obj = obj_stack->objects[obj_stack->stkPtr-1];
  mp_obj_dict_store(parent_obj, mp_obj_new_str(inst->name, strlen(inst->name)), dict);
  obj_stack->objects[obj_stack->stkPtr++]=dict;
}

void serializeROSType(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void serializeBool(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void deserializeBool(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void serializeInt(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void deserializeInt(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void serializeFloat(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}


void deserializeFloat(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
  float floatVal;

  bool rc = ucdr_deserialize_float(cdr, &floatVal);
  mp_obj_dict_store(obj_stack->objects[obj_stack->stkPtr], mp_obj_new_str(inst->name, sizeof(inst->name)), mp_obj_new_float(floatVal));
}

void deserializeDouble(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}

void serializeDouble(int slot, ucdrBuffer *cdr,   dxi_t* inst, mp_obj_stk_t *obj_stack)
{
}


// UCDR_BASIC_TYPE_DECLARATIONS(_char, char)
// UCDR_BASIC_TYPE_DECLARATIONS(_bool, bool)
// UCDR_BASIC_TYPE_DECLARATIONS(_uint8_t, uint8_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_uint16_t, uint16_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_uint32_t, uint32_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_uint64_t, uint64_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_int8_t, int8_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_int16_t, int16_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_int32_t, int32_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_int64_t, int64_t)
// UCDR_BASIC_TYPE_DECLARATIONS(_float, float)
// UCDR_BASIC_TYPE_DECLARATIONS(_double, double)

// cdr
// dxi
