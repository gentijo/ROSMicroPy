#include "mp_uros_sdk.h"
#include "ros_video_widget.h"

#include "lvgl.h"
//#include "lv_jpg.h"


void ros_video_widget::service_callback( const void *response, void *context) {

    const sensor_msgs__msg__CompressedImage *image = (const sensor_msgs__msg__CompressedImage  *) response;
    printf("Image received, size = %d", image->data.size);

    // ros_video_widget *instance  = (ros_video_widget *)context;
    // instance->img_dsc.data = (const u_int8_t *)&image->data.data;
    // instance->img_dsc.data_size = image->data.size;
    // lv_img_set_src(instance->img, &instance->img_dsc);
    // lv_obj_center(instance->img);

};


ros_video_widget::ros_video_widget() {
};


ros_video_widget::ros_video_widget(mpy_LvObject* parent) {

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
        this,
		ON_NEW_DATA));

 
    lv_obj_clear_flag(lvObject, LV_OBJ_FLAG_SCROLLABLE); 
    init();

    lvObject = lv_img_create(parent->lvObject);
    lv_obj_set_size(lvObject, lv_pct(100), lv_pct(100));

    img_dsc.header.always_zero = 0;
    img_dsc.header.w = LV_IMG_CF_UNKNOWN;
    img_dsc.header.h = LV_IMG_CF_UNKNOWN;
    img_dsc.header.cf = LV_IMG_CF_RAW;  

};


