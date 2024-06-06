#ifndef __MPY_LVOBJECT_H__
#define __MPY_LVOBJECT_H__

#include "lvgl.h"

extern "C" {
#include "cJSON.h"
}

class mpy_LvObject {

    public:
        mpy_LvObject(mpy_LvObject* parent) {
            lvObject = lv_obj_create(parent->lvObject);
        };

        void  addLvObjectStyle(cJSON* properties);

        void  setSize(cJSON* properties);


        int   getIntStyleProperty(const cJSON *properties, const char *name);
        char* getStringStyleProperty(const cJSON *properties, const char *name );
    
    public: 
        lv_obj_t *lvObject;
};

#endif
