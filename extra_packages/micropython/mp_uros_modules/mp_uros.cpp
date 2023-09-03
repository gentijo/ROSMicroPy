extern "C" {

#include "mp_uros.h"
#include <mp_uros_module.h>

// MicroPython runs as a task under FreeRTOS
#define MP_TASK_PRIORITY        (ESP_TASK_PRIO_MIN + 1)
#define MP_TASK_STACK_SIZE      (16 * 1024)

#if CONFIG_IDF_TARGET_ESP32C3
#define MP_TASK_STACK_LIMIT_MARGIN (2048)
#else
#define MP_TASK_STACK_LIMIT_MARGIN (1024)
#endif

mp_obj_t publishMsg(mp_obj_t a_obj, mp_obj_t b_obj) {
    return NULL;
}

TaskHandle_t ros_mp_event_task_handle;
QueueHandle_t 	mp_uros_queue = NULL;

mp_obj_t g_eventName = NULL;
mp_obj_t g_eventType = NULL;
mp_obj_t g_eventCallback = NULL;

mp_obj_t registerEventSubscription(mp_obj_t eventName, mp_obj_t eventType, mp_obj_t eventCallback) {
    g_eventName = eventName;
    g_eventType = eventType; 
    g_eventCallback = eventCallback;

    return eventName;
}


mp_obj_t readROSMsg() {

    const TickType_t xDelay = 100 / portTICK_PERIOD_MS;
    unsigned long value;

    if (xQueueReceive(mp_uros_queue, &value, 0 )== pdTRUE) {
        if (g_eventCallback != NULL) {
            mp_call_function_1(g_eventCallback, NULL);
        }
    }
   

    return NULL;
}

void* ros_mp_event_task(void *pvParameter) {

    volatile uint32_t sp = (uint32_t)get_sp();
    #if MICROPY_PY_THREAD
    mp_thread_init(pxTaskGetStackStart(NULL), MP_TASK_STACK_SIZE / sizeof(uintptr_t));
    #endif

    size_t mp_task_heap_size;
    void *mp_task_heap = NULL;

    printf("In ROS MP event Task");
    
    #if CONFIG_SPIRAM_USE_MALLOC
    // SPIRAM is issued using MALLOC, fallback to normal allocation rules
    mp_task_heap = NULL;
    #elif CONFIG_ESP32_SPIRAM_SUPPORT
    // Try to use the entire external SPIRAM directly for the heap
    mp_task_heap = (void *)SOC_EXTRAM_DATA_LOW;
    switch (esp_spiram_get_chip_size()) {
        case ESP_SPIRAM_SIZE_16MBITS:
            mp_task_heap_size = 2 * 1024 * 1024;
            break;
        case ESP_SPIRAM_SIZE_32MBITS:
        case ESP_SPIRAM_SIZE_64MBITS:
            mp_task_heap_size = 4 * 1024 * 1024;
            break;
        default:
            // No SPIRAM, fallback to normal allocation
            mp_task_heap = NULL;
            break;
    }
    #elif CONFIG_ESP32S2_SPIRAM_SUPPORT || CONFIG_ESP32S3_SPIRAM_SUPPORT
    // Try to use the entire external SPIRAM directly for the heap
    size_t esp_spiram_size = esp_spiram_get_size();
    if (esp_spiram_size > 0) {
        mp_task_heap = (void *)SOC_EXTRAM_DATA_HIGH - esp_spiram_size;
        mp_task_heap_size = esp_spiram_size;
    }
    #endif

    if (mp_task_heap == NULL) {
        // Allocate the uPy heap using malloc and get the largest available region,
        // limiting to 1/2 total available memory to leave memory for the OS.
        #if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL(4, 1, 0)
        size_t heap_total = heap_caps_get_total_size(MALLOC_CAP_8BIT);
        #else
        multi_heap_info_t info;
        heap_caps_get_info(&info, MALLOC_CAP_8BIT);
        size_t heap_total = info.total_free_bytes + info.total_allocated_bytes;
        #endif
        mp_task_heap_size = MIN(heap_caps_get_largest_free_block(MALLOC_CAP_8BIT), heap_total / 2);
        mp_task_heap = malloc(mp_task_heap_size);
    }
    
    mp_stack_set_top((void *)sp);
    mp_stack_set_limit(MP_TASK_STACK_SIZE - MP_TASK_STACK_LIMIT_MARGIN);
    gc_init(mp_task_heap, mp_task_heap + mp_task_heap_size);
    
    // pyexec_file_if_exists("callbackTest.py");
    
    const TickType_t xDelay = 100 / portTICK_PERIOD_MS;
    unsigned long value;
    while(true) {
        if (xQueueReceive(mp_uros_queue, &value, 0 )== pdTRUE) {
            mp_call_function_1(g_eventCallback, NULL);
        }
        taskYIELD();
    }   


//    mp_call_function_1(g_eventCallback, twist);
//    mp_obj_t gc_module_obj = mp_module_get(MP_QSTR_ros_event_callback

    return NULL;
}

void on_ros_mp_event(void) {
//
// Create a seperate MP compatiable thread to convey the ROS message to the Python code
// All python code processing this event will run in this thread. 
//

}


mp_obj_t init_event_queue(void) {
    printf("Init ROS MP Event Quwue");
    mp_uros_queue = xQueueCreate( 1, sizeof( unsigned long ) );
    return NULL;
}

mp_obj_t init_ros_mp_event_system(void) {

    printf("Init ROS MP Event System");
    /* Create a queue capable of containing 10 unsigned long values. */
    mp_uros_queue = xQueueCreate( 1, sizeof( unsigned long ) );

    // xTaskCreatePinnedToCore(ros_mp_event_task, "ros_mp_event_task", 
    //   MP_TASK_STACK_SIZE / sizeof(StackType_t), NULL, 
    //   CONFIG_MICRO_ROS_APP_TASK_PRIO, &ros_mp_event_task_handle, MP_TASK_COREID);
 
    size_t stack_size = MP_TASK_STACK_SIZE / sizeof(StackType_t);
    mp_thread_create(ros_mp_event_task, NULL, &stack_size);
    return NULL;
}



    // mp_obj_t linear = mp_obj_new_dict(3);	
    // linear = mp_obj_dict_store(linear, mp_obj_new_str("x",1), mp_obj_new_float(0x40));
    // linear = mp_obj_dict_store(linear, mp_obj_new_str("y",1), mp_obj_new_float(0x50));
    // linear = mp_obj_dict_store(linear, mp_obj_new_str("z",1), mp_obj_new_float(0x60));

    // mp_obj_t angular = mp_obj_new_dict(3);
    // angular = mp_obj_dict_store(angular, mp_obj_new_str("x",1), mp_obj_new_float(0x70));
    // angular = mp_obj_dict_store(angular, mp_obj_new_str("y",1), mp_obj_new_float(0x80));
    // angular = mp_obj_dict_store(angular, mp_obj_new_str("z",1), mp_obj_new_float(0x90));

    // mp_obj_t twist = mp_obj_new_dict(2);
    // twist = mp_obj_dict_store(twist, mp_obj_new_str("linear",6), linear);
    // twist = mp_obj_dict_store(twist, mp_obj_new_str("angular",7), angular);

}
