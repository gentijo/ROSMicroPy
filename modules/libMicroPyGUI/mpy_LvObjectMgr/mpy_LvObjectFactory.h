#ifndef __MPY_LV_OBJECT_FACTORY_H__
#define __MPY_LV_OBJECT_FACTORY_H__

#include <map>
#include <vector>

#include "mpy_LvObject.h"
//
// For objects that have a name tag, store a pointer to that element here
extern std::map<const char *, mpy_LvObject *> g_namedObject;

//
// List of all objects created named or not.
extern std::vector<mpy_LvObject *> g_lvObjectList;

class mpy_LvObjectFactory {

    public:
        static mpy_LvObject* create(const char * type, mpy_LvObject* parent);
};

#endif