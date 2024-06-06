#ifndef __MPY_LV_BASE_OBJECTS_H__
#define __MPY_LV_BASE_OBJECTS_H__

#include "mpy_LvObject.h"
#include "mpy_LvObjectFactory.h"

class mpy_LvHorizontalLayout : public mpy_LvObject {

    public:
        mpy_LvHorizontalLayout(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
            lv_obj_set_flex_flow(this->lvObject, LV_FLEX_FLOW_ROW);
        };
};

class mpy_LvVerticalLayout : public mpy_LvObject {

    public:
        mpy_LvVerticalLayout(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
            lv_obj_set_flex_flow(this->lvObject, LV_FLEX_FLOW_COLUMN);
        };
};

class mpy_LvContainer : public mpy_LvObject {

    public:
        mpy_LvContainer(mpy_LvObject *parent)
        : mpy_LvObject(parent) {
        };
};

#endif
