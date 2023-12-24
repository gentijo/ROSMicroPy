#include "uros_support.h"


rclc_executor_t		executor;
rcl_node_t 			node;

rcl_timer_t			timer;

rcl_allocator_t		allocator;
rclc_support_t		support;
rcl_init_options_t init_options;
rmw_init_options_t *rmw_options;

/**
 *
 *
 */
mp_obj_t init_ROS_Stack()
{
	printf("\r\nInitializing ROS Stack\r\n");

	init_event_subscription_callbacks();
    init_mpy_uros_typesupport();
	
	
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

	return mp_const_none;
}

mp_obj_t run_ROS_Stack() {

	printf("\r\nROS Task running task\r\n");
	while(1) {
		rclc_executor_spin_some(&executor, RCL_MS_TO_NS(200));
		vTaskDelay( 100 );
		printf("Spinning\r\n");
	}
	
	return mp_const_none;
}



/***
 * 
 * 
 * 
*/
void add_ROS_service_Listener(ros_subscription* sub) {

	char full_name[40] = "";
	strcpy(full_name, "/turtle1");
	strcat(full_name, "/cmd_vel");

	printf("Init command velocity subscription Name=%s\r\n", full_name);
	RCSOFTCHECK(rclc_subscription_init_default(
	 	&sub->rcl_service_subscription,
		&node,
		//ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
		mpy_uros_type_support_slots[0],
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
void service_callback(const void *response, void *context)
{
    printf("in Service callback\r\n");

    void **mp_data = response;
    ros_subscription* ros_sub = (ros_subscription *)context;
 
    MP_THREAD_GIL_ENTER();
    // mp_obj_t data = createObjFromThread();
    mp_call_function_1(ros_sub->mpEventCallback, *mp_data);
    MP_THREAD_GIL_EXIT();
}

