#ifndef __RMP_WIDGET_MGR_H__
#define __RMP_WIDGET_MGR_H__

#include "py/runtime.h"

typedef void *rmp_widget_t;

typedef enum _RMP_WIDGET_TYPE_
{
    RMP_ROS_VIDEO_WIDGET=3,
    RMP_BUTTON_WIDGET=4
} RMP_WIDGET_TYPE;

#ifdef __cplusplus
extern "C" {
#endif
mp_obj_t rmp_load_widget( char* widget_id, RMP_WIDGET_TYPE widget_type );
void     rmp_set_widget_parameter(char *widget_name, char *parameter_name, char *value);
mp_obj_t rmp_get_widget_parameter(char *widget_name, char *parameter_name);
#ifdef __cplusplus
}
#endif

#endif

