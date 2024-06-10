#include <map>
#include <string>
#include <vector>
#include <list>


extern "C" {

#include "cJSON.h"

}

#include "mpy_LvObjectFactory.h"
#include "mpy_LvBaseObjects.h"


/**
 * 
 * 
 * 
*/
mpy_LvObject *mpy_LvObjectFactory::create(const char *type, mpy_LvObject *parent)
{

    if (strcmp(type, "HorizontalLayout")==0)
    {
        return new mpy_LvHorizontalLayout(parent);
    }

    if (strcmp(type, "VerticalLayout")==0)
    {
        return new mpy_LvVerticalLayout(parent);
    }

    if (strcmp(type, "Container")==0)
    {
        return new mpy_LvContainer(parent);
    }

    return NULL;
}
