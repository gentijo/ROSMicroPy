#ifndef __MPY_LV_BASE_OBJECTS_H__
#define __MPY_LV_BASE_OBJECTS_H__

#include "mpy_LvObject.h"
#include "mpy_LvObjectFactory.h"

class mpy_LvHorizontalLayout : public mpy_LvObject {

    public:
        mpy_LvHorizontalLayout(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
            lv_obj_set_layout(this->lvObject, LV_LAYOUT_FLEX);
            lv_obj_set_flex_flow(this->lvObject, LV_FLEX_FLOW_ROW);
            lv_obj_clear_flag(this->lvObject, LV_OBJ_FLAG_SCROLLABLE); 
        };
};

class mpy_LvVerticalLayout : public mpy_LvObject {

    public:
        mpy_LvVerticalLayout(mpy_LvObject *parent)
        : mpy_LvObject(parent) {

            lv_obj_set_layout(this->lvObject, LV_LAYOUT_FLEX);
            lv_obj_set_flex_flow(this->lvObject, LV_FLEX_FLOW_COLUMN);
            lv_obj_clear_flag(this->lvObject, LV_OBJ_FLAG_SCROLLABLE); 
        };
};

class mpy_LvContainer : public mpy_LvObject {

    public:
        mpy_LvContainer(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
        };
};


class mpy_LvButton: public  mpy_LvObject {

    protected:
        mpy_LvButton() {

        };

    public:
        mpy_LvButton(mpy_LvObject *parent) {

            lvObject = lv_btn_create(parent->lvObject);
            lv_obj_set_align(lvObject, LV_ALIGN_CENTER);
            lv_obj_add_flag(lvObject, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
            lv_obj_clear_flag(lvObject, LV_OBJ_FLAG_SCROLLABLE);  
            lv_obj_set_size(lvObject, lv_pct(100), lv_pct(100));
        };

};

#endif
