#include "rmp_widget.h"
#include "rmp_widget_mgr.h"
#include "./ros-video/rmp_video_widget.h"

#include <map>
#include <string>

std::map<char *, rmp_widget_t> g_widgets_by_id;

mp_obj_t createWidgetInfoBlock(rmp_widget_t widget);

extern "C" mp_obj_t rmp_load_widget( char* widget_id, RMP_WIDGET_TYPE widget_type ) {
    
    rmp_widget_t widget = NULL;

    auto widget_iter = g_widgets_by_id.find(widget_id); 
    if ( widget_iter != g_widgets_by_id.end())
        return createWidgetInfoBlock(widget_iter->second);

    switch (widget_type) {
        case RMP_ROS_VIDEO_WIDGET:
            widget = new rmp_video_widget();    
            break;

        case RMP_BUTTON_WIDGET:
            break;

    };

    if (widget != NULL) {
        g_widgets_by_id[widget_id] = widget;
        return createWidgetInfoBlock(widget);
    }

    return NULL;
};


extern "C" void rmp_set_widget_parameter(char *widget_name, char* parameter_name, char* value ) {
 }

extern "C" mp_obj_t rmp_get_widget_parameter(char *widget_name, char* parameter_name) {
      return mp_const_none; 
}

mp_obj_t createWidgetInfoBlock(rmp_widget_t widget)  {
    return NULL;
}