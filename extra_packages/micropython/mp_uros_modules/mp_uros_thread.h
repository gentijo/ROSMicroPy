#ifndef __MP_UROS_THREAD_H__
#define __MP_UROS_THREAD_H__
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"


#include "py/stackctrl.h"
#include "py/mpthread.h"
#include "py/runtime.h"
#include "py/mpconfig.h"

#include "sdkconfig.h"

#define DEBUG 0
#if DEBUG
#define DEBUG_printf(...) ESP_LOGI("ros_mp_thread", __VA_ARGS__)
#else
#define DEBUG_printf(...) (void)0
#endif

    mp_obj_t start_new_ROS_thread(void (*entry_point_fun)());
    mp_obj_t init_ROS_System();
    
    void init_ROS_Main_Task();

    typedef struct _ros_thread_entry_args_t
    {
        mp_obj_dict_t *dict_locals;
        mp_obj_dict_t *dict_globals;
        size_t stack_size;
        void (*fun_ptr)();
        size_t n_args;
        size_t n_kw;
        mp_obj_t args[];
    } ros_thread_entry_args_t;

#endif
