#ifndef __MPY_ROS_WIDGET_FACTORY_H__
#define __MPY_ROS_WIDGET_FACTORY_H__

#include "mpy_LvObject.h"



class rosWidgetFactory: public mpy_LvObjectFactory {
    public:
        mpy_LvObject *create(const char *type, mpy_LvObject *parent);

};

#endif