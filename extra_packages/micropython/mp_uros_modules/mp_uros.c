#include "ros_app.h"

#include "mp_uros.h"
#include "mp_uros_module.h"
#include "mp_uros_thread.h"
#include "mp_uros_type_support.h"

//#include "common_internal.h"
#include <ucdr/microcdr.h>
#include "py/runtime.h"
#include "py/obj.h"

// MicroPython runs as a task under FreeRTOS
#define MP_TASK_PRIORITY (ESP_TASK_PRIO_MIN + 1)
#define MP_TASK_STACK_SIZE (16 * 1024)

#if CONFIG_IDF_TARGET_ESP32C3
#define MP_TASK_STACK_LIMIT_MARGIN (2048)
#else
#define MP_TASK_STACK_LIMIT_MARGIN (1024)
#endif

int ros_subscription_slots = 10;
ros_subscription* g_ros_subs;

/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
mp_obj_t publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data)
{
    return NULL;
}

/**
 *
 */
mp_obj_t createObjFromThread()
{

    mp_obj_t linear = mp_obj_new_dict(3);
    linear = mp_obj_dict_store(linear, mp_obj_new_str("x", 1), mp_obj_new_float(0x40));
    linear = mp_obj_dict_store(linear, mp_obj_new_str("y", 1), mp_obj_new_float(0x50));
    linear = mp_obj_dict_store(linear, mp_obj_new_str("z", 1), mp_obj_new_float(0x60));

    mp_obj_t angular = mp_obj_new_dict(3);
    angular = mp_obj_dict_store(angular, mp_obj_new_str("x", 1), mp_obj_new_float(0x70));
    angular = mp_obj_dict_store(angular, mp_obj_new_str("y", 1), mp_obj_new_float(0x80));
    angular = mp_obj_dict_store(angular, mp_obj_new_str("z", 1), mp_obj_new_float(0x90));

    mp_obj_t twist = mp_obj_new_dict(2);
    twist = mp_obj_dict_store(twist, mp_obj_new_str("linear", 6), linear);
    twist = mp_obj_dict_store(twist, mp_obj_new_str("angular", 7), angular);

    //    mp_store_global(MP_QSTR_make_dict, MP_OBJ_FROM_PTR(&make_dict_obj));

    return (twist);
}

/**
 *
 *
 *
 */
void service_callback(const void *response, const void *context)
{
    printf("in Service callback\r\n");

    void **mp_data = response;
    ros_subscription* ros_sub = (ros_subscription *)context;
    // ucdrBuffer temp_buffer;
    // ucdr_init_buffer(
    //     &temp_buffer,
    //     NULL,
    //     0);
    
    MP_THREAD_GIL_ENTER();
    // mp_obj_t data = createObjFromThread();
    mp_call_function_1(ros_sub->mpEventCallback, *mp_data);
    MP_THREAD_GIL_EXIT();
}

/**
 *
 *
 */
void init_event_subscription_callbacks()
{
    g_ros_subs = malloc(sizeof(ros_subscription) * ros_subscription_slots);

    ros_subscription* rsubs = g_ros_subs;
    for (int x=0; x<ros_subscription_slots; x++) {
        rsubs->index=0;
        rsubs++;
    };
}

typedef struct _mp_obj_enumerate_t {
    mp_obj_base_t base;
    mp_obj_t iter;
    mp_int_t cur;
} mp_obj_enumerate_t;

const mp_obj_base_t *type_obj;
const mp_obj_type_t *type;
const char * type_str;

const mp_obj_base_t *name_obj;
const mp_obj_type_t *name;
const char * name_str;

mp_obj_base_t *objptr;
const mp_obj_base_t *type_obj;

mp_obj_t dict_map_elem;

//    self->data = mp_obj_dict_get(uasyncio_context, MP_OBJ_NEW_QSTR(MP_QSTR_CancelledError));

mp_obj_t parseDataMapDict(mp_obj_t dict) {
    mp_map_t *named_map = mp_obj_dict_get_map(dict);
    mp_map_elem_t *named_elem = mp_map_lookup(named_map, MP_OBJ_NEW_QSTR(MP_QSTR_name), MP_MAP_LOOKUP);
    if (named_elem != NULL && named_elem->value != NULL) {

        char * key = mp_obj_get_type_str(named_elem->key );
        char * value = mp_obj_get_type_str( named_elem->value );
        printf("Value type: %s  Key type: %s\r\n", value, key);

        key = mp_obj_str_get_str(named_elem->key);
        value = mp_obj_str_get_str(named_elem->value);
        printf("Value type: %s  Key type: %s\r\n", value, key);



        return named_elem->value;
         
    }
    return NULL;
}

/**
 *
 *
 *
 */
mp_obj_t registerEventSubscription(
    mp_obj_t eventName,
    mp_obj_t eventType,
    mp_obj_t eventCallback)
{
    int cnt = ros_subscription_slots;
    ros_subscription* rsubs = g_ros_subs;


    mp_obj_t data_map = mp_load_attr(eventType, MP_QSTR_dataMap);
    size_t data_map_len;
    mp_obj_t *data_map_items;
    
    type = mp_obj_get_type(data_map);
    type_str = qstr_str(type->name);
    printf ("Type: %s\r\n", type_str);
    
    mp_obj_list_get(data_map, &data_map_len, &data_map_items);
    for (size_t i = 0; i < data_map_len; ++i) {
        mp_obj_t data_map_elem = data_map_items[i];
        type = mp_obj_get_type(data_map_elem);
        type_str = qstr_str(type->name);

        parseDataMapDict(data_map_elem);
    }


    for (int x = 0; x < cnt; x++)
    {
        if (rsubs->index == 0)
        {
            rsubs->eventName = eventName;
            rsubs->eventType = eventType;
            rsubs->mpEventCallback = eventCallback;

            rsubs->index = x;
            rsubs->resp = malloc(1000); //  malloc(rti.sizeResp);
            add_ROS_service_Listener(rsubs);
            return eventName;
        }

        rsubs++;
    }

    return mp_const_none;
}

/**
 *
 */
mp_obj_t mp_init_ROS_Stack()
{
    printf("\r\nInitializing ROS Stack\r\n");
    init_event_subscription_callbacks();
    init_mpy_uros_typesupport();
    init_ROS_Stack();

    return mp_const_none;
}

mp_obj_t mp_run_ROS_Stack()
{
    start_new_ROS_thread(run_ROS_Stack);
    return mp_const_none;
}

ros_subscription * get_ROS_Sub_from_slot(int slot)
{
    if (slot >= ros_subscription_slots) return NULL;
    return &g_ros_subs[slot];

}
