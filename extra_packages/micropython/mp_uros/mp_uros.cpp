extern "C" {
#include <mp_uros_module.h>


mp_obj_t publishMsg(mp_obj_t a_obj, mp_obj_t b_obj) {

    // Prove we have (at least) C++11 features.
    const auto a = mp_obj_get_int(a_obj);
    const auto typeb = mp_obj_get_type(b_obj);

    size_t len = 0;
    mp_obj_t* values[10];
    mp_obj_get_array(b_obj, &len, values);

    if (typeb != NULL) { printf("Hello World"); }

//    const auto sum = [&]() { 
//        return mp_obj_new_int(a + b);
//   } ();

    
    const auto sum = mp_obj_new_int(100);
    mp_obj_t tup[] = {sum, MP_ROM_QSTR(MP_QSTR_publishMsg)};
    return mp_obj_new_tuple(2, tup);
}
}

