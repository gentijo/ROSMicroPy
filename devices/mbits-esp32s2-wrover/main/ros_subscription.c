#include "mp_uros.h"
#include "mp_uros_module.h"

typedef struct _ros_subscription {
    int index = 0;
    mp_obj_t g_eventName = NULL;
    mp_obj_t g_eventType = NULL;
    mp_obj_t g_eventCallback = NULL;
    mp_obj_t (*callback_fun)() = {
        service_callback(req, res, ros_subs[index - 1]);
};


ros_subscription ros_subs[25];

void service_callback(const void *req, ros_subscription *sub)
{
}

/**
 *
 *
 *
 */
mp_obj_t registerEventSubscription(mp_obj_t eventName, mp_obj_t eventType, mp_obj_t eventCallback)
{
    for (int x = 0; x < sizeof(ros_subs); x++)
    {
        if (ros_subs[x].index == 0)
        {
            ros_subs[x].index = x;
            ros_subs[x].eventName = eventName;
            ros_subs[x].eventType = eventType;
            ros_subs[x].eventCallback = eventCallback;
        }
    }

    return eventName;
}