#include "sdkconfig.h"

#include "mp_uros_sdk.h"
#include "uros_base_func.h"

#include "mp_obj_tools.h"
#include "mp_uros_type_support.h"
#include "mp_uros_thread.h"
#include "mp_uros_dataTypeParser.h"
#include "uros_mesg_func.h"


#include "esp_wifi.h"
#include "esp_netif.h"


esp_err_t uros_network_interface_initialize(void);


rclc_executor_t		ros_rclc_executor;
rcl_node_t 			ros_rcl_node;
rcl_allocator_t		ros_rcl_allocator;
rclc_support_t		support;
rcl_init_options_t init_options;
rmw_init_options_t *rmw_options;

size_t				domain_id = DOMAIN_ID;
char				node_name[64] = "turtle2";
char				namespace[64] = "";

char				ROS_AgentIP[64] = "192.168.4.100"; //CONFIG_MICRO_ROS_AGENT_IP;
char				ROS_AgentPort[64] = "8888"; //CONFIG_MICRO_ROS_AGENT_PORT;

/**
 * 
 * 
*/
mp_obj_t setDomainID(mp_obj_t obj_in)
{
    if (&mp_type_int != mp_obj_get_type(obj_in)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Domain ID must be a number"));
		return obj_in;
    }

    int  id = mp_obj_get_int(obj_in);
	domain_id = id;

    return obj_in;
}


/** 
 * 
 * 
*/
mp_obj_t setNamespace(mp_obj_t obj_in)
{
    if (&mp_type_str != mp_obj_get_type(obj_in)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Namespace must be a str"));
		return obj_in;
    }

    const char* cstr = mp_obj_str_get_str(obj_in);
    if ((cstr == NULL) || strlen(cstr)==0) {
		mp_raise_ValueError(MP_ERROR_TEXT("Namespace name can not be an null / empty string"));
		return obj_in;
    }

	strncpy(namespace, cstr, 63);
	return obj_in;
}


/**
 * 
 * 
*/
mp_obj_t setNodeName(mp_obj_t obj_in)
{
    if (&mp_type_str != mp_obj_get_type(obj_in)) {
		mp_raise_TypeError(MP_ERROR_TEXT("Node name must be a str"));
		return obj_in;
    }

    const char* cstr = mp_obj_str_get_str(obj_in);
    if ((cstr == NULL) || strlen(cstr)==0) {
		mp_raise_ValueError(MP_ERROR_TEXT("Node name can not be an null / empty string"));
		return obj_in;
    }

	strncpy(node_name, cstr, 63);

	return obj_in;
}

/**
 * 
 * INitialize the ROS Stack creating the base objects needed
 */
mp_obj_t init_ROS_Stack()
{
    printf("\r\nInitializing ROS Stack\r\n");

    init_ROS_Subscriptions();
	init_ROS_Publishers();
    init_mpy_ROS_TypeSupport();

	ros_rcl_allocator = rcl_get_default_allocator();

	init_options= rcl_get_zero_initialized_init_options();
	RCCHECK(rcl_init_options_init(&init_options, ros_rcl_allocator));
	RCCHECK(rcl_init_options_set_domain_id(&init_options, domain_id));

#ifdef CONFIG_MICRO_ROS_ESP_XRCE_DDS_MIDDLEWARE
	rmw_options = rcl_init_options_get_rmw_init_options(&init_options);

	// Static Agent IP and port can be used instead of auto disvery.
	RCCHECK(rmw_uros_options_set_udp_address((const char*)ROS_AgentIP, (const char *)ROS_AgentPort, rmw_options));
	// RCCHECK(rmw_uros_discover_agent(rmw_options));
#endif

	// create init_options
	RCCHECK(rclc_support_init_with_options(&support, 0, NULL, &init_options, &ros_rcl_allocator));
	
	// create node
	RCCHECK(rclc_node_init_default(&ros_rcl_node, node_name, namespace, &support));
	
	// create executor
	RCCHECK(rclc_executor_init(&ros_rclc_executor, &support.context, 20, &ros_rcl_allocator));


	return mp_const_none;
}




/**
 * This is a wrapper function that runs the ROS Stack in a separate MP thread
 * 
 */
  
mp_obj_t mp_run_ROS_Stack()
{
    start_new_ROS_thread(run_ROS_Stack);
    return mp_const_none;
}


/**
 * 
 * 
 * 
*/
void run_ROS_Stack() {

	printf("\r\nROS Task running task\r\n");
	rclc_executor_spin(&ros_rclc_executor);
}


/**
 * Register a data type which will build a data type instruction set
 * used to marshal data between MicrpROS and Micropython
*/
mp_obj_t registerDataType(mp_obj_t dataMap) {

	mp_obj_t typeName = parseDataTypeDefinition(dataMap, true);

	if  (typeName == NULL) {
		mp_raise_ValueError(MP_ERROR_TEXT("Error registering data type"));
		return mp_const_none;
	}

	return typeName;
}

/**
 * 
 * Diagnostic: Output the instruction list for a registered data type
 * 
*/
mp_obj_t dumpDataType(mp_obj_t dataTypeName) {

	dumpDataTypeMap(dataTypeName);
	return mp_const_none;
}