#ifndef __RMP_VIDEO_WIDGET_H__
#define __RMP_VIDEO_WIDGET_H__

#include "../rmp_widget.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <sensor_msgs/msg/compressed_image.h>

class rmp_video_widget: public rmp_widget {

    public:
        void init();

    protected:
        rcl_subscription_t rcl_subscription;
        sensor_msgs__msg__CompressedImage image;
};

#endif
