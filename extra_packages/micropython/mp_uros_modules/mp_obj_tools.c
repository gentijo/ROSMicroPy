
#include "py/runtime.h"
#include "py/obj.h"

mp_obj_t mpt_getNamedObjFrom(mp_obj_t obj_in, qstr attr)
{

    mp_obj_t obj_out = mp_load_attr(obj_in, attr);
    size_t data_map_len;
    mp_obj_t *data_map_items;
    
    type = mp_obj_get_type(data_map);
    type_str = qstr_str(type->name);
    printf ("Type: %s\r\n", type_str);
    
    mp_obj_list_get(data_map, &data_map_len, &data_map_items);
    for (size_t i = 0; i < data_map_len; ++i) {
        mp_obj_t data_map_elem = data_map_items[i];
        type = mp_obj_get_type(data_map_elem);
        type_str = qstr_str(type->name);

        parseDataMapDict(data_map_elem);
    }

}

mp_obj_t mpt_getIndexedObjFrom(mp_obj_t objin, size_t index)
{

}

//#getNextObj

char *mpt_obj_to_cstr(mp_obj_t objin)
{

}

/**
 *
 */
mp_obj_t createObjFromThread()
{

    mp_obj_t linear = mp_obj_new_dict(3);
    linear = mp_obj_dict_store(linear, mp_obj_new_str("x", 1), mp_obj_new_float(0x40));
    linear = mp_obj_dict_store(linear, mp_obj_new_str("y", 1), mp_obj_new_float(0x50));
    linear = mp_obj_dict_store(linear, mp_obj_new_str("z", 1), mp_obj_new_float(0x60));

    mp_obj_t angular = mp_obj_new_dict(3);
    angular = mp_obj_dict_store(angular, mp_obj_new_str("x", 1), mp_obj_new_float(0x70));
    angular = mp_obj_dict_store(angular, mp_obj_new_str("y", 1), mp_obj_new_float(0x80));
    angular = mp_obj_dict_store(angular, mp_obj_new_str("z", 1), mp_obj_new_float(0x90));

    mp_obj_t twist = mp_obj_new_dict(2);
    twist = mp_obj_dict_store(twist, mp_obj_new_str("linear", 6), linear);
    twist = mp_obj_dict_store(twist, mp_obj_new_str("angular", 7), angular);

    //    mp_store_global(MP_QSTR_make_dict, MP_OBJ_FROM_PTR(&make_dict_obj));

    return (twist);
}



typedef struct _mp_obj_enumerate_t {
    mp_obj_base_t base;
    mp_obj_t iter;
    mp_int_t cur;
} mp_obj_enumerate_t;

const mp_obj_base_t *type_obj;
const mp_obj_type_t *type;
const char * type_str;

const mp_obj_base_t *name_obj;
const mp_obj_type_t *name;
const char * name_str;

mp_obj_base_t *objptr;
const mp_obj_base_t *type_obj;

mp_obj_t dict_map_elem;

//    self->data = mp_obj_dict_get(uasyncio_context, MP_OBJ_NEW_QSTR(MP_QSTR_CancelledError));

mp_obj_t parseDataMapDict(mp_obj_t dict) {
    mp_map_t *named_map = mp_obj_dict_get_map(dict);
    mp_map_elem_t *named_elem = mp_map_lookup(named_map, MP_OBJ_NEW_QSTR(MP_QSTR_name), MP_MAP_LOOKUP);
    if (named_elem != NULL && named_elem->value != NULL) {

        char * key = mp_obj_get_type_str(named_elem->key );
        char * value = mp_obj_get_type_str( named_elem->value );
        printf("Value type: %s  Key type: %s\r\n", value, key);

        key = mp_obj_str_get_str(named_elem->key);
        value = mp_obj_str_get_str(named_elem->value);
        printf("Value type: %s  Key type: %s\r\n", value, key);



        return named_elem->value;
         
    }
    return NULL;
}
