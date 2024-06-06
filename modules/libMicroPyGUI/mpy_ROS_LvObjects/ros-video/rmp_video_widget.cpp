#include "mp_uros_sdk.h"
#include "rmp_video_widget.h"
#include "../rmp_widget_mgr.h"

void service_callback( const void *response, void *context) {
    printf("in Service callback\r\n");
    const sensor_msgs__msg__CompressedImage *image = (const sensor_msgs__msg__CompressedImage  *) response;
    printf("Image received, size = %d", image->data.size);
};


void rmp_video_widget::init() {

    int rc;
    char topicName[32] = "image/compressed";

	RCSOFTCHECK(rclc_subscription_init_default(
	    &this->rcl_subscription,
		&rmp_rcl_node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, CompressedImage), 
        topicName)
	);
	
	RCSOFTCHECK(rclc_executor_add_subscription_with_context(
		&rmp_rclc_executor,
		&this->rcl_subscription,
	    &this->image,
		&service_callback, 
        NULL,
		ON_NEW_DATA));

    // widget = lv_btn_create(ui_Screen1);
    // lv_obj_set_width(widget, 100);
    // lv_obj_set_height(widget, 50);
    // lv_obj_set_x(widget, -340);
    // lv_obj_set_y(widget, 207);
    
    // lv_obj_set_align(widget, LV_ALIGN_CENTER);
    // lv_obj_add_flag(widget, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(widget, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

};


