#ifndef __RMP_WIDGET_MGR_H__
#define __RMP_WIDGET_MGR_H__

#include "py/runtime.h"

typedef void* widget_t;

typedef enum WIDGET_TYPE_
{
    UNKNOWN=0,
    HorizontalLayout=1,
    VerticalLayout =2,
    NamedContainer=3,
    ROSVideo=4,
    ROSAttitude=5.
    ROSHeading=6,
    Button=7

} WIDGET_TYPE;

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t rmp_load_widget( char* widget_id, WIDGET_TYPE widget_type );
void     rmp_set_widget_parameter(char *widget_name, char *parameter_name, char *value);
mp_obj_t rmp_get_widget_parameter(char *widget_name, char *parameter_name);

WIDGET_TYPE rmp_widget_stype2type(char *type);
bool        rmp_widget_is_container(WIDGET_TYPE type);

#ifdef __cplusplus
}
#endif

#endif

