#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_system.h"

#include <uros_network_interfaces.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <std_msgs/msg/int32.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <geometry_msgs/geometry_msgs/msg/twist.h>
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"

// #include "py/runtime.h"

extern rosidl_message_type_support_t mpy_uros_type_support;

void mp_app_main(void);


#ifdef CONFIG_MICRO_ROS_ESP_XRCE_DDS_MIDDLEWARE
#include <rmw_microros/rmw_microros.h>
#endif

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Aborting.\n",__LINE__,(int)temp_rc);vTaskDelete(NULL);}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printf("Failed status on line %d: %d. Continuing.\n",__LINE__,(int)temp_rc);}}

#define DOMAIN_ID 3

rcl_publisher_t publisher;


void timer_callback(rcl_timer_t * timer, int64_t last_call_time)
{
	RCLC_UNUSED(last_call_time);

//	printf("Timer Task \r\n");

	// if (timer != NULL) {

	// 	printf("Publishing: ROS_MP Msg\n");

	// 	mp_obj_dict_t *linear = mp_obj_new_dict(3);	
	// 	linear = mp_obj_dict_store(linear, mp_obj_new_str("x",1), mp_obj_new_float(0x40));
	// 	linear = mp_obj_dict_store(linear, mp_obj_new_str("x",1), mp_obj_new_float(0x40));
	// 	linear = mp_obj_dict_store(linear, mp_obj_new_str("x",1), mp_obj_new_float(0x40));

	// 	mp_obj_dict_t *angular = mp_obj_new_dict(3);
	// 	angular = mp_obj_dict_store(angular, mp_obj_new_str("x",1), mp_obj_new_float(0x40));
	// 	angular = mp_obj_dict_store(angular, mp_obj_new_str("x",1), mp_obj_new_float(0x40));
	// 	angular = mp_obj_dict_store(angular, mp_obj_new_str("x",1), mp_obj_new_float(0x40));

	// 	mp_obj_dict_t *twist = mp_obj_new_dict(2);
	// 	twist = mp_obj_dict_store(twist, mp_obj_new_str("linear",6), linear);
	// 	twist = mp_obj_dict_store(twist, mp_obj_new_str("angular",7), angular);

	// 	RCSOFTCHECK(rcl_publish(&publisher, &twist, NULL));

//	}
}

void micro_ros_task(void * arg)
{
	rcl_allocator_t allocator = rcl_get_default_allocator();
	rclc_support_t support;

	rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
	RCCHECK(rcl_init_options_init(&init_options, allocator));
	RCCHECK(rcl_init_options_set_domain_id(&init_options, DOMAIN_ID));

#ifdef CONFIG_MICRO_ROS_ESP_XRCE_DDS_MIDDLEWARE
	rmw_init_options_t* rmw_options = rcl_init_options_get_rmw_init_options(&init_options);

	// Static Agent IP and port can be used instead of autodisvery.
	RCCHECK(rmw_uros_options_set_udp_address(CONFIG_MICRO_ROS_AGENT_IP, CONFIG_MICRO_ROS_AGENT_PORT, rmw_options));
	//RCCHECK(rmw_uros_discover_agent(rmw_options));
#endif

	// create init_options
	RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator));

	// create node
	rcl_node_t node;
	RCCHECK(rclc_node_init_default(&node, "rosbot", "", &support));

	// create publisher
	// RCCHECK(rclc_publisher_init_default(
	// 	&publisher,
	// 	&node,
	// 	ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
	// 	"rosbot_twist_publisher"));
	// 		&mpy_uros_type_support,

	// create publisher
	// rclc_publisher_init_default(
	// 	&publisher,
	// 	&node,
	// 	&mpy_uros_type_support,
	// 	"rosbot_twist_publisher");


	int freeMem = esp_get_free_heap_size();
	printf("\r\nFree memory %d\r\n", freeMem);
	
//	mp_obj_dict_t *linear = mp_obj_new_dict(3);

	// create timer,
	// rcl_timer_t timer;
	// const unsigned int timer_timeout = 1000;
	// RCCHECK(rclc_timer_init_default(
	// 	&timer,
	// 	&support,
	// 	RCL_MS_TO_NS(timer_timeout),
	// 	timer_callback));

	// create executor
	rclc_executor_t executor;
	RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
	// RCCHECK(rclc_executor_add_timer(&executor, &timer));

	while(1){
		rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
		usleep(10000);
	}

	// free resources
	RCCHECK(rcl_publisher_fini(&publisher, &node));
	RCCHECK(rcl_node_fini(&node));

  	vTaskDelete(NULL);
}

void app_main(void)
{
#if defined(CONFIG_MICRO_ROS_ESP_NETIF_WLAN) || defined(CONFIG_MICRO_ROS_ESP_NETIF_ENET)
    ESP_ERROR_CHECK(uros_network_interface_initialize());
#endif
//	mp_app_main();

	const TickType_t xDelay = 2000 / portTICK_PERIOD_MS;
	vTaskDelay( xDelay );
    //pin micro-ros task in APP_CPU to make PRO_CPU to deal with wifi:
    xTaskCreate(micro_ros_task,
            "uros_task",
            CONFIG_MICRO_ROS_APP_STACK,
            NULL,
            CONFIG_MICRO_ROS_APP_TASK_PRIO,
            NULL);


}
