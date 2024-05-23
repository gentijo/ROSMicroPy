#include "rmp_widget.h"
#include "rmp_widget_mgr.h"
#include "./ros-video/rmp_video_widget.h"

#include <map>
#include <string>
#include <list>

std::map<char *, widget_t> g_widgets_by_id;

/**
 * 
 * 
 * 
*/
mp_obj_t createWidgetInfoBlock(widget_t widget);

extern "C" rmp_widget_t rmp_load_widget(char* widget_id, RMP_WIDGET_TYPE widget_type ) {
    
    rmp_widget_t widget = NULL;

    auto widget_iter = g_widgets_by_id.find(widget_id); 
    if ( widget_iter != g_widgets_by_id.end())
        return widget_iter->second;

    switch (widget_type) {
        case ROS_VIDEO_WIDGET:
            widget = new rmp_video_widget();    
            break;

        case BUTTON_WIDGET:
            break;

    };

    if (widget != NULL) {
        g_widgets_by_id[widget_id] = widget;
        widget;
    }

    return NULL;
};

/**
 * 
 * 
 * 
*/
extern "C" void rmp_set_widget_parameter(char *widget_type, char* parameter_type, char* value ) {
 }

extern "C" mp_obj_t rmp_get_widget_parameter(char *widget_type, char* parameter_type) {
      return mp_const_none; 
}

/**
 * 
 * 
 * 
*/
mp_obj_t createWidgetInfoBlock(rmp_widget_t widget)  {
    return NULL;
}

WIDGET_TYPE rmp_widget_stype2type(char *type) {
    if (type == NULL || strlen(type)==0) return WIDGET_TYPE.UNKNOWN;

    if (strcmp(type, "HorizontalLayout") == 0) return WIDGET_TYPE.HorizontalLayout;
    if (strcmp(type, "VerticalLayout") == 0) return WIDGET_TYPE.VerticalLayout;
    if (strcmp(type, "ROSVideo") == 0) return WIDGET_TYPE.ROSVideo;
    if (strcmp(type, "ROSAttitude") == 0) return WIDGET_TYPE.ROSAttitude;
    if (strcmp(type, "ROSHeading") == 0) return WIDGET_TYPE.ROSHeading;
    if (strcmp(type, "Button") == 0) return WIDGET_TYPE.Button;
    
    return WIDGET_TYPE.UNKNOWN;
}

bool  rmp_widget_is_container(WIDGET_TYPE type) {

    switch(type) {
        case HorizontalLayout:
        case VerticalLayout:
            return true;

        default:
            return false;
    }
}
