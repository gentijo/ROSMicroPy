
#include "uros_sdk.h"
#include "uros_base_func.h"
#include "uros_mesg_func.h"
#include "mp_uros_type_support.h"
#include "mp_obj_tools.h"
#include "mp_uros_dataTypeParser.h"

// MicroPython runs as a task under FreeRTOS
#define MP_TASK_PRIORITY (ESP_TASK_PRIO_MIN + 1)
#define MP_TASK_STACK_SIZE (16 * 1024)

#if CONFIG_IDF_TARGET_ESP32C3
#define MP_TASK_STACK_LIMIT_MARGIN (2048)
#else
#define MP_TASK_STACK_LIMIT_MARGIN (1024)
#endif

#define             ros_subscription_slots 10
ros_subscription    *g_ros_subscriptions;




/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
/***********************************************************************************************/
mp_obj_t publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data)
{
    return mp_const_none;
}



/**
 *
 *
 *
 */
mp_obj_t registerEventSubscription(
    mp_obj_t eventName,
    mp_obj_t eventType,
    mp_obj_t eventCallback) {

    int cnt = ros_subscription_slots;

    if (&mp_type_str != mp_obj_get_type(eventType)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Event type must be of type str"));
        return mp_const_none;
    }

    const char* cstr_eventType = mp_obj_str_get_str(eventType);
    if ((cstr_eventType == NULL) || strlen(cstr_eventType) == 0) {
        mp_raise_ValueError(MP_ERROR_TEXT("Event type can not be an null / empty string"));
        return mp_const_none;
	}

    dxc_cb_t* eventType_CtrlBlk = findTypeByName(cstr_eventType);

    if (eventType_CtrlBlk == NULL) {
        mp_raise_ValueError(MP_ERROR_TEXT("You must first register type before registering for the Event Subscription"));
        return mp_const_none;
    }

    if (&mp_type_str != mp_obj_get_type(eventName)) {
        mp_raise_ValueError(MP_ERROR_TEXT("eventName is not a String"));
        return mp_const_none;
    }

    const char* cstr_eventName = mp_obj_str_get_str(eventName);
    if ((cstr_eventName == NULL) || strlen(cstr_eventName)==0) {
        mp_raise_ValueError(MP_ERROR_TEXT("Event name can not be an null / empty string"));
        return mp_const_none;
    }


    // Find first available subscription slot.
    //
    for (int x = 0; x < cnt; x++)
    {
        if (g_ros_subscriptions[x].index == 0)
        {
            g_ros_subscriptions[x].eventName = strdup(eventName);
            g_ros_subscriptions[x].mpEventCallback = eventCallback;
            g_ros_subscriptions[x].dataTypeCtrlBlk = eventType_CtrlBlk;

            g_ros_subscriptions[x].index = x+1;
            g_ros_subscriptions[x].resp = malloc(1000); //  malloc(rti.sizeResp);
            add_ROS_Service_Listener(&g_ros_subscriptions[x]);
            return eventName;
        }

    }

    return mp_const_none;
}

ros_subscription * get_ROS_Subscription(int slot) {
    
    if (slot >= ros_subscription_slots) return NULL;
    return &g_ros_subscriptions[slot];
}

/**
 *
 *
 */
void init_ROS_Subscriptions() {
    g_ros_subscriptions = malloc( (sizeof(ros_subscription) + 4) * ros_subscription_slots);

    for (int x=0; x<ros_subscription_slots; x++) {
        g_ros_subscriptions[x].index=0;
    };
}



/***
 * 
 * 
 * 
*/
void add_ROS_Service_Listener(ros_subscription* sub) {


	printf("Init Subscription Name=%s\r\n", sub->eventName);
	RCSOFTCHECK(rclc_subscription_init_default(
	 	&sub->rcl_service_subscription,
		&node,
		sub->dataTypeCtrlBlk->ros_mesg_type_support,
		sub->eventName);
	);
	
	RCSOFTCHECK(rclc_executor_add_subscription_with_context(
		&executor,
		&sub->rcl_service_subscription,
		sub->resp,
		&service_callback, 
		sub,
		ON_NEW_DATA));

}



/**
 *
 *
 *
 */
void service_callback(const void *response, void *context) {
    printf("in Service callback\r\n");

    const void **mp_data = response;
    ros_subscription* ros_sub = (ros_subscription *)context;
 
    MP_THREAD_GIL_ENTER();
    // mp_obj_t data = createObjFromThread();
    mp_call_function_1(ros_sub->mpEventCallback, *mp_data);
    MP_THREAD_GIL_EXIT();
}

