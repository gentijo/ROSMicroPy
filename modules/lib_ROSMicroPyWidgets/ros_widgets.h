#ifndef __MPY_LV_BASE_OBJECTS_H__
#define __MPY_LV_BASE_OBJECTS_H__

#include "mpy_LvObject.h"

class rmp_ROSVideo : public mpy_LvObject {

    public:
        rmp_ROSVideo(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
            lv_obj_set_layout(this->lvObject, LV_LAYOUT_FLEX);
            lv_obj_set_flex_flow(this->lvObject, LV_FLEX_FLOW_ROW);
            lv_obj_clear_flag(this->lvObject, LV_OBJ_FLAG_SCROLLABLE); 
            lv_obj_set_size(lvObject, lv_pct(100), lv_pct(100));
        };
};

#endif
