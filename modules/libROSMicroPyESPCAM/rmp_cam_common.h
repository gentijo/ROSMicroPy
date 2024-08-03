#ifndef __ESPCAM_COMMON_H__
#define __ESPCAM_COMMON_H__


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#define ledPin 4

extern char    CAM_TopicName[32];

mp_obj_t rmp_cam_init(void);
void blink_esp32_led();
mp_obj_t rmp_cam_set_topic_name(mp_obj_t obj_in);
mp_obj_t rmp_publish_cam_image();
mp_obj_t rmp_cam_takepic(void);

#endif