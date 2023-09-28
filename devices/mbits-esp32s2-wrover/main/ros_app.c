#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"

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

#include "py/runtime.h"

#include "ros_app.h"
#include "mp_uros.h"
#include "mp_uros_thread.h"

extern rosidl_message_type_support_t mpy_uros_type_support;

void mp_app_main(void);

#ifdef CONFIG_MICRO_ROS_ESP_XRCE_DDS_MIDDLEWARE
#include <rmw_microros/rmw_microros.h>
#endif

#define RCCHECK(fn)                                                                      \
	{                                                                                    \
		rcl_ret_t temp_rc = fn;                                                          \
		if ((temp_rc != RCL_RET_OK))                                                     \
		{                                                                                \
			printf("Failed status on line %d: %d. Aborting.\n", __LINE__, (int)temp_rc); \
			vTaskDelete(NULL);                                                           \
		}                                                                                \
	}

#define RCSOFTCHECK(fn)                                                                    \
	{                                                                                      \
		rcl_ret_t temp_rc = fn;                                                            \
		if ((temp_rc != RCL_RET_OK))                                                       \
		{                                                                                  \
			printf("Failed status on line %d: %d. Continuing.\n", __LINE__, (int)temp_rc); \
		}                                                                                  \
	}

#define DOMAIN_ID 0

rclc_executor_t		executor;
rcl_node_t 			node;


rcl_publisher_t		publisher;
rcl_subscription_t  subscription;
rcl_timer_t			timer;

rcl_allocator_t		allocator;
rclc_support_t		support;
rcl_init_options_t init_options;
rmw_init_options_t *rmw_options;

/**
 *
 *
 *
 * */
void timer_callback(rcl_timer_t *timer, int64_t last_call_time)
{
	RCLC_UNUSED(last_call_time);

	printf("Timer Task \r\n");

	// if (timer != NULL)
	// {
	// 	dispatch_ROSMsg();
	// }
}

geometry_msgs__msg__Twist   m_velocity_msg;
void sub_velocity_callback(const void *msgin)
{
	printf("Vel Callback\r\n");
}


/**
 *
 *
 */
void init_ROS_Stack()
{
	vTaskDelay( 3 );

	printf("\r\nStarting ROS Task\r\n");

	allocator = rcl_get_default_allocator();

	init_options= rcl_get_zero_initialized_init_options();
	RCCHECK(rcl_init_options_init(&init_options, allocator));
	RCCHECK(rcl_init_options_set_domain_id(&init_options, DOMAIN_ID));

#ifdef CONFIG_MICRO_ROS_ESP_XRCE_DDS_MIDDLEWARE
	rmw_options = rcl_init_options_get_rmw_init_options(&init_options);

	// Static Agent IP and port can be used instead of autodisvery.
	RCCHECK(rmw_uros_options_set_udp_address(CONFIG_MICRO_ROS_AGENT_IP, CONFIG_MICRO_ROS_AGENT_PORT, rmw_options));
	// RCCHECK(rmw_uros_discover_agent(rmw_options));
#endif

	// create init_options
	RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &allocator));

	// create node
	RCCHECK(rclc_node_init_default(&node, "turtle2", "", &support));

	// create executor
	RCCHECK(rclc_executor_init(&executor, &support.context, 20, &allocator));

	int freeMem = esp_get_free_heap_size();
	printf("\r\nFree memory %d\r\n", freeMem);

	// create timer,
	const unsigned int timer_timeout = 10000;
	RCCHECK(rclc_timer_init_default(
		&timer,
		&support,
		RCL_MS_TO_NS(timer_timeout),
		timer_callback));

	// char full_name[40];
	// strcpy(full_name, "turtle1");
	// strcat(full_name, "/cmd_vel");

	// printf("Init command velocity subscription Name=%s\r\n", full_name);
	// RCCHECK(rclc_subscription_init_default(
	//  	&subscription,
	// 	&node,
	// 	ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
	// 	full_name)
	// );


	// printf("Add command velocity subscription\r\n");
	// RCCHECK(rclc_executor_add_subscription(
	// 	&executor, 
	// 	&subscription, 
	// 	&m_velocity_msg, 
	// 	&sub_velocity_callback, ON_NEW_DATA));


	RCCHECK(rclc_executor_add_timer(&executor, &timer));

	//rclc_executor_spin(&executor);

	// while(1) {
	// 	rclc_executor_spin_some(&executor, RCL_MS_TO_NS(200));
	// 	vTaskDelay( 100 );
	// }

}

void run_ROS_Stack() {
	printf("\r\nROS Task running spin\r\n");

	while(1) {
		rclc_executor_spin_some(&executor, RCL_MS_TO_NS(200));
		vTaskDelay( 100 );
		printf("Spinning\r\n");
	}

}


void add_ROS_service_Listener(ros_subscription* sub) {

	char full_name[40] = "";
	strcpy(full_name, "/turtle1");
	strcat(full_name, "/cmd_vel");

	printf("Init command velocity subscription Name=%s\r\n", full_name);
	RCSOFTCHECK(rclc_subscription_init_default(
	 	&sub->rcl_service_subscription,
		&node,
		// ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
		&mpy_uros_type_support,
		full_name)
	);
	

	printf("Add command velocity subscription\r\n");
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
void app_main(void)
{

#if defined(CONFIG_MICRO_ROS_ESP_NETIF_WLAN) || defined(CONFIG_MICRO_ROS_ESP_NETIF_ENET)
	ESP_ERROR_CHECK(uros_network_interface_initialize());
#endif

	printf("\r\nInitializing Micropython Stack\r\n");
	mp_app_main();
}

