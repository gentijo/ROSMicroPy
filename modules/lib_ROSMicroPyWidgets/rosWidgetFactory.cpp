#include <map>
#include <string>
#include <vector>
#include <list>


extern "C" {

#include "cJSON.h"

}

#include "mpy_LvObjectFactory.h"
#include "mpy_LvObject.h"
#include "rosWidgetFactory.h"
#include "ros_video_widget.h"


extern "C" void registerROSWidgetFactory() {
    rosWidgetFactory *f = new rosWidgetFactory();
    add_LvObjectFactory(f);    
}
/**
 * 
 * 
 * 
*/
mpy_LvObject *rosWidgetFactory::create(const char *type, mpy_LvObject *parent)
{

    if (strcmp(type, "ROSVideo")==0)
    {
        printf("ROSVideo Widget\r\n");
        return new ros_video_widget(parent);
    }

    return NULL;
};


