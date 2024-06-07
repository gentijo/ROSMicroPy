#ifndef __MPY_LV_OBJECT_FACTORY_H__
#define __MPY_LV_OBJECT_FACTORY_H__

#include "mpy_LvObject.h"



class mpy_LvObjectFactory {

    public:
        mpy_LvObject* create(const char * type, mpy_LvObject* parent);
};

#endif