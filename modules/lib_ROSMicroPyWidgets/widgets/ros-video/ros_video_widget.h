#ifndef __RMP_VIDEO_WIDGET_H__
#define __RMP_VIDEO_WIDGET_H__


#include <stdio.h>

#include "mpy_LvObject.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <sensor_msgs/msg/compressed_image.h>

class ros_video_widget: public mpy_LvObject {

    private:
        ros_video_widget();

    public:
        ros_video_widget(mpy_LvObject *parent);

        void init();
        static void service_callback( const void *response, void *context);

        rcl_subscription_t rcl_subscription;
        sensor_msgs__msg__CompressedImage image;
        
        lv_obj_t *img;
        lv_img_dsc_t img_dsc;

};

#endif
