#ifndef __RMP_WIDGET_H__
#define __RMP_WIDGET_H__

#include "rmp_widget.h"

#include <map>
#include <string>
#include <exception>

#include "../ui/ui.h"

class rmp_widget {

    public:
        virtual void init() = 0;

        void setParameter(std::string name, std::string value) {
            parameters[name]=value;
        };

        std::string getParameter(std::string name) {
            if (auto search = parameters.find(name); search != parameters.end())
                return search->second;
            else return "";
        }

    public: 
        lv_obj_t *widget;
        std::map<std::string, std::string> parameters;
};

#endif
