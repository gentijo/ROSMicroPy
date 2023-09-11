#include "mp_uros.h"
#include "mp_uros_module.h"

// MicroPython runs as a task under FreeRTOS
#define MP_TASK_PRIORITY (ESP_TASK_PRIO_MIN + 1)
#define MP_TASK_STACK_SIZE (16 * 1024)

#if CONFIG_IDF_TARGET_ESP32C3
#define MP_TASK_STACK_LIMIT_MARGIN (2048)
#else
#define MP_TASK_STACK_LIMIT_MARGIN (1024)
#endif


    /***********************************************************************************************/
    /***********************************************************************************************/
    /***********************************************************************************************/
    /***********************************************************************************************/

    mp_obj_t publishMsg(mp_obj_t publisher_ID, mp_obj_t dataType, mp_obj_t data)
    {
        return NULL;
    }

    /***********************************************************************************************/
    /***********************************************************************************************/
    /***********************************************************************************************/
    /***********************************************************************************************/


	void dispatch_ROSMsg(){
        
        MP_THREAD_GIL_ENTER();
        printf("\r\nDispatch ROS Message\r\n");
        if (g_eventCallback != NULL) {
            mp_obj_t data = createObjFromThread();
            mp_call_function_1(g_eventCallback, data);
        }
        
        MP_THREAD_GIL_EXIT();
    }

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
