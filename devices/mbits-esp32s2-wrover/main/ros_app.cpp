
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ros_app.h"

extern "C" {
#include "py/builtin.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "shared/runtime/pyexec.h"

}


void ros_app::initialize() {
    
    printf("\r\nInit Subsystems");


};
