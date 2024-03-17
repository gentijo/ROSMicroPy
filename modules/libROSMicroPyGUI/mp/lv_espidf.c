
/*
 * Auto-Generated file, DO NOT EDIT!
 *
 * Command line:
 * /opt/lv_micropython/lib/lv_bindings/gen/gen_mpy.py -M espidf -MD /opt/lv_micropython/ports/esp32/build/lv_espidf.c.json -E /opt/lv_micropython/ports/esp32/build/lv_espidf.c.pp.filtered /opt/lv_micropython/lib/lv_bindings/driver/esp32/espidf.h
 *
 * Preprocessing command:
 * Preprocessing was disabled.
 *
 * Generating Objects: 
 */

/*
 * Mpy includes
 */

#include <stdlib.h>
#include <string.h>
#include "py/obj.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/runtime.h"
#include "py/binary.h"
#include "py/objarray.h"
#include "py/objtype.h"
#include "py/objexcept.h"



/*
 * Helper functions
 */

#ifndef GENMPY_UNUSED
#ifdef __GNUC__
#define GENMPY_UNUSED __attribute__ ((unused))
#else
#define GENMPY_UNUSED
#endif // __GNUC__
#endif // GENMPY_UNUSED

// Custom function mp object

typedef mp_obj_t (*mp_fun_ptr_var_t)(size_t n, const mp_obj_t *, void *ptr);

typedef struct mp_lv_obj_fun_builtin_var_t {
    mp_obj_base_t base;
    mp_uint_t n_args;
    mp_fun_ptr_var_t mp_fun;
    void *lv_fun;
} mp_lv_obj_fun_builtin_var_t;

STATIC mp_obj_t lv_fun_builtin_var_call(mp_obj_t self_in, size_t n_args, size_t n_kw, const mp_obj_t *args);
STATIC mp_int_t mp_func_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags);

GENMPY_UNUSED STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_type_fun_builtin_var,
    MP_QSTR_function,
    MP_TYPE_FLAG_BINDS_SELF | MP_TYPE_FLAG_BUILTIN_FUN,
    call, lv_fun_builtin_var_call,
    unary_op, mp_generic_unary_op,
    buffer, mp_func_get_buffer
);

GENMPY_UNUSED STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_type_fun_builtin_static_var,
    MP_QSTR_function,
    MP_TYPE_FLAG_BUILTIN_FUN,
    call, lv_fun_builtin_var_call,
    unary_op, mp_generic_unary_op,
    buffer, mp_func_get_buffer
);

STATIC mp_obj_t lv_fun_builtin_var_call(mp_obj_t self_in, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    assert(MP_OBJ_IS_TYPE(self_in, &mp_lv_type_fun_builtin_var) ||
           MP_OBJ_IS_TYPE(self_in, &mp_lv_type_fun_builtin_static_var));
    mp_lv_obj_fun_builtin_var_t *self = MP_OBJ_TO_PTR(self_in);
    mp_arg_check_num(n_args, n_kw, self->n_args, self->n_args, false);
    return self->mp_fun(n_args, args, self->lv_fun);
}

STATIC mp_int_t mp_func_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags) {
    (void)flags;
    assert(MP_OBJ_IS_TYPE(self_in, &mp_lv_type_fun_builtin_var) ||
           MP_OBJ_IS_TYPE(self_in, &mp_lv_type_fun_builtin_static_var));
    mp_lv_obj_fun_builtin_var_t *self = MP_OBJ_TO_PTR(self_in);

    bufinfo->buf = &self->lv_fun;
    bufinfo->len = sizeof(self->lv_fun);
    bufinfo->typecode = BYTEARRAY_TYPECODE;
    return 0;
}

#define MP_DEFINE_CONST_LV_FUN_OBJ_VAR(obj_name, n_args, mp_fun, lv_fun) \
    const mp_lv_obj_fun_builtin_var_t obj_name = \
        {{&mp_lv_type_fun_builtin_var}, n_args, mp_fun, lv_fun}

#define MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(obj_name, n_args, mp_fun, lv_fun) \
    const mp_lv_obj_fun_builtin_var_t obj_name = \
        {{&mp_lv_type_fun_builtin_static_var}, n_args, mp_fun, lv_fun}

// Casting

typedef struct mp_lv_struct_t
{
    mp_obj_base_t base;
    void *data;
} mp_lv_struct_t;

STATIC const mp_lv_struct_t mp_lv_null_obj;

#ifdef LV_OBJ_T
STATIC mp_int_t mp_lv_obj_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags);
#else
STATIC mp_int_t mp_lv_obj_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags){ return 0; }
#endif

STATIC mp_int_t mp_blob_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags);

STATIC mp_obj_t get_native_obj(mp_obj_t mp_obj)
{
    if (!MP_OBJ_IS_OBJ(mp_obj)) return mp_obj;
    const mp_obj_type_t *native_type = ((mp_obj_base_t*)mp_obj)->type;
    if (native_type == NULL)
        return NULL;
    if (MP_OBJ_TYPE_GET_SLOT_OR_NULL(native_type, parent) == NULL ||
        (MP_OBJ_TYPE_GET_SLOT_OR_NULL(native_type, buffer) == mp_blob_get_buffer) ||
        (MP_OBJ_TYPE_GET_SLOT_OR_NULL(native_type, buffer) == mp_lv_obj_get_buffer))
       return mp_obj;
    while (MP_OBJ_TYPE_GET_SLOT_OR_NULL(native_type, parent)) native_type = MP_OBJ_TYPE_GET_SLOT(native_type, parent);
    return mp_obj_cast_to_native_base(mp_obj, MP_OBJ_FROM_PTR(native_type));
}

STATIC mp_obj_t dict_to_struct(mp_obj_t dict, const mp_obj_type_t *type);

STATIC mp_obj_t make_new_lv_struct(
    const mp_obj_type_t *type,
    size_t n_args,
    size_t n_kw,
    const mp_obj_t *args);

STATIC mp_obj_t cast(mp_obj_t mp_obj, const mp_obj_type_t *mp_type)
{
    mp_obj_t res = NULL;
    if (mp_obj == mp_const_none && MP_OBJ_TYPE_GET_SLOT_OR_NULL(mp_type, make_new) == &make_new_lv_struct) {
        res = MP_OBJ_FROM_PTR(&mp_lv_null_obj);
    } else if (MP_OBJ_IS_OBJ(mp_obj)) {
        res = get_native_obj(mp_obj);
        if (res){
            const mp_obj_type_t *res_type = ((mp_obj_base_t*)res)->type;
            if (res_type != mp_type){
                if (res_type == &mp_type_dict &&
                    MP_OBJ_TYPE_GET_SLOT_OR_NULL(mp_type, make_new) == &make_new_lv_struct)
                        res = dict_to_struct(res, mp_type);
                else res = NULL;
            }
        }
    }
    if (res == NULL) nlr_raise(
        mp_obj_new_exception_msg_varg(
            &mp_type_SyntaxError, MP_ERROR_TEXT("Can't convert %s to %s!"), mp_obj_get_type_str(mp_obj), qstr_str(mp_type->name)));
    return res;
}

// object handling
// This section is enabled only when objects are supported

#ifdef LV_OBJ_T

typedef struct mp_lv_obj_t {
    mp_obj_base_t base;
    LV_OBJ_T *lv_obj;
    LV_OBJ_T *callbacks;
} mp_lv_obj_t;

STATIC inline LV_OBJ_T *mp_to_lv(mp_obj_t mp_obj)
{
    if (mp_obj == NULL || mp_obj == mp_const_none) return NULL;
    mp_obj_t native_obj = get_native_obj(mp_obj);
    if (MP_OBJ_TYPE_GET_SLOT_OR_NULL(mp_obj_get_type(native_obj), buffer) != mp_lv_obj_get_buffer)
        return NULL;
    mp_lv_obj_t *mp_lv_obj = MP_OBJ_TO_PTR(native_obj);
    if (mp_lv_obj->lv_obj == NULL) {
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_LvReferenceError, MP_ERROR_TEXT("Referenced object was deleted!")));
    }
    return mp_lv_obj->lv_obj;
}

STATIC inline LV_OBJ_T *mp_get_callbacks(mp_obj_t mp_obj)
{
    if (mp_obj == NULL || mp_obj == mp_const_none) return NULL;
    mp_lv_obj_t *mp_lv_obj = MP_OBJ_TO_PTR(get_native_obj(mp_obj));
    if (mp_lv_obj == NULL)
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("'user_data' argument must be either a dict or None!")));
    if (!mp_lv_obj->callbacks) mp_lv_obj->callbacks = mp_obj_new_dict(0);
    return mp_lv_obj->callbacks;
}

STATIC inline const mp_obj_type_t *get_BaseObj_type();

STATIC void mp_lv_delete_cb(lv_event_t * e)
{
    LV_OBJ_T *lv_obj = e->current_target;
    if (lv_obj){
        mp_lv_obj_t *self = lv_obj->user_data;
        if (self) {
            self->lv_obj = NULL;
        }
    }
}

STATIC inline mp_obj_t lv_to_mp(LV_OBJ_T *lv_obj)
{
    if (lv_obj == NULL) return mp_const_none;
    mp_lv_obj_t *self = (mp_lv_obj_t*)lv_obj->user_data;
    if (!self)
    {
        // Find the object type
        const mp_obj_type_t *mp_obj_type = get_BaseObj_type();
        const lv_obj_class_t *lv_obj_class = lv_obj_get_class(lv_obj);
        const mp_lv_obj_type_t **iter = &mp_lv_obj_types[0];
        for (; *iter; iter++) {
            if ((*iter)->lv_obj_class == lv_obj_class) {
                mp_obj_type = (*iter)->mp_obj_type;
                break;
            }
        }

        // Create the MP object
        self = m_new_obj(mp_lv_obj_t);
        *self = (mp_lv_obj_t){
            .base = {(const mp_obj_type_t *)mp_obj_type},
            .lv_obj = lv_obj,
            .callbacks = NULL,
        };

        // Register the Python object in user_data
        lv_obj->user_data = self;

        // Register a "Delete" event callback
        lv_obj_add_event_cb(lv_obj, mp_lv_delete_cb, LV_EVENT_DELETE, NULL);
    }
    return MP_OBJ_FROM_PTR(self);
}

STATIC void* mp_to_ptr(mp_obj_t self_in);

STATIC mp_obj_t cast_obj_type(const mp_obj_type_t* type, mp_obj_t obj)
{
    mp_lv_obj_t *self = m_new_obj(mp_lv_obj_t);
    *self = (mp_lv_obj_t){
        .base = {type},
        .lv_obj = mp_to_ptr(obj),
        .callbacks = NULL,
    };
    if (!self->lv_obj) return mp_const_none;
    return MP_OBJ_FROM_PTR(self);
}

STATIC mp_obj_t cast_obj(mp_obj_t type_obj, mp_obj_t obj)
{
    return cast_obj_type((const mp_obj_type_t *)type_obj, obj);
}

STATIC mp_obj_t make_new(
    const mp_lv_obj_fun_builtin_var_t *lv_obj_var,
    const mp_obj_type_t *type,
    size_t n_args,
    size_t n_kw,
    const mp_obj_t *args)
{
    mp_obj_t lv_obj;
    if (n_args == 0 && n_kw == 0) // allow no args, and pass NULL as parent in such case
    {
        const mp_obj_t no_args[] = {mp_const_none};
        lv_obj = mp_call_function_n_kw(MP_OBJ_FROM_PTR(lv_obj_var), 1, 0, no_args);
    }
    else
    {
        lv_obj = mp_call_function_n_kw(MP_OBJ_FROM_PTR(lv_obj_var), n_args, n_kw, args);
    }

    if (!lv_obj) return mp_const_none;

    mp_lv_obj_t *self = MP_OBJ_TO_PTR(lv_obj);
    if (self->base.type != type)
        return cast_obj_type(type, lv_obj);
    return lv_obj;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_2(cast_obj_obj, cast_obj);
STATIC MP_DEFINE_CONST_CLASSMETHOD_OBJ(cast_obj_class_method, MP_ROM_PTR(&cast_obj_obj));

STATIC mp_int_t mp_lv_obj_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags) {
    (void)flags;
    mp_lv_obj_t *self = MP_OBJ_TO_PTR(self_in);

    bufinfo->buf = &self->lv_obj;
    bufinfo->len = sizeof(self->lv_obj);
    bufinfo->typecode = BYTEARRAY_TYPECODE;
    return 0;
}

STATIC mp_obj_t mp_lv_obj_binary_op(mp_binary_op_t op, mp_obj_t lhs_in, mp_obj_t rhs_in)
{
    mp_lv_obj_t *lhs = MP_OBJ_TO_PTR(lhs_in);
    mp_lv_obj_t *rhs = MP_OBJ_TO_PTR(rhs_in);
    switch (op)
    {
        case MP_BINARY_OP_EQUAL:
            return mp_obj_new_bool(lhs->lv_obj == rhs->lv_obj);
        case MP_BINARY_OP_NOT_EQUAL:
            return mp_obj_new_bool(lhs->lv_obj != rhs->lv_obj);
        default:
            return MP_OBJ_NULL;
    }
}

// Register LVGL root pointers
MP_REGISTER_ROOT_POINTER(void *mp_lv_roots);
MP_REGISTER_ROOT_POINTER(void *mp_lv_user_data);

void *mp_lv_roots;

void mp_lv_init_gc()
{
    static bool mp_lv_roots_initialized = false;
    if (!mp_lv_roots_initialized) {
        mp_lv_roots = MP_STATE_VM(mp_lv_roots) = m_new0(lv_global_t, 1);
        mp_lv_roots_initialized = true;
    }
}

#else // LV_OBJ_T

typedef struct mp_lv_obj_type_t {
    mp_obj_type_t *mp_obj_type;
} mp_lv_obj_type_t;

#endif

STATIC inline mp_obj_t convert_to_bool(bool b)
{
    return b? mp_const_true: mp_const_false;
}

STATIC inline mp_obj_t convert_to_str(const char *str)
{
    return str? mp_obj_new_str(str, strlen(str)): mp_const_none;
}

STATIC inline const char *convert_from_str(mp_obj_t str)
{
    if (str == NULL || str == mp_const_none)
        return NULL;

    if (MP_OBJ_IS_TYPE(str, &mp_type_bytearray) ||
        MP_OBJ_IS_TYPE(str, &mp_type_memoryview)) {
            mp_buffer_info_t buffer_info;
            if (mp_get_buffer(str, &buffer_info, MP_BUFFER_READ)) {
                return buffer_info.buf;
            }
    }

    return mp_obj_str_get_str(str);
}

// struct handling

STATIC mp_lv_struct_t *mp_to_lv_struct(mp_obj_t mp_obj)
{
    if (mp_obj == NULL || mp_obj == mp_const_none) return NULL;
    mp_obj_t native_obj = get_native_obj(mp_obj);
    if ( (!MP_OBJ_IS_OBJ(native_obj)) || (MP_OBJ_TYPE_GET_SLOT_OR_NULL(mp_obj_get_type(native_obj), make_new) != &make_new_lv_struct) ) nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("Expected Struct object!")));
    mp_lv_struct_t *mp_lv_struct = MP_OBJ_TO_PTR(native_obj);
    return mp_lv_struct;
}

STATIC inline size_t get_lv_struct_size(const mp_obj_type_t *type)
{
    mp_obj_dict_t *self = MP_OBJ_TO_PTR(MP_OBJ_TYPE_GET_SLOT(type, locals_dict));
    mp_map_elem_t *elem = mp_map_lookup(&self->map, MP_OBJ_NEW_QSTR(MP_QSTR___SIZE__), MP_MAP_LOOKUP);
    if (elem == NULL) {
        return 0;
    } else {
        return (size_t)mp_obj_get_int(elem->value);
    }
}

STATIC mp_obj_t make_new_lv_struct(
    const mp_obj_type_t *type,
    size_t n_args,
    size_t n_kw,
    const mp_obj_t *args)
{
    if ((!MP_OBJ_IS_TYPE(type, &mp_type_type)) || MP_OBJ_TYPE_GET_SLOT_OR_NULL(type, make_new) != &make_new_lv_struct)
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("Argument is not a struct type!")));
    size_t size = get_lv_struct_size(type);
    mp_arg_check_num(n_args, n_kw, 0, 1, false);
    mp_lv_struct_t *self = m_new_obj(mp_lv_struct_t);
    mp_lv_struct_t *other = (n_args > 0) && (!mp_obj_is_int(args[0])) ? mp_to_lv_struct(cast(args[0], type)): NULL;
    size_t count = (n_args > 0) && (mp_obj_is_int(args[0]))? mp_obj_get_int(args[0]): 1;
    *self = (mp_lv_struct_t){
        .base = {type},
        .data = (size == 0 || (other && other->data == NULL))? NULL: m_malloc(size * count)
    };
    if (self->data) {
        if (other) {
            memcpy(self->data, other->data, size * count);
        } else {
            memset(self->data, 0, size * count);
        }
    }
    return MP_OBJ_FROM_PTR(self);
}

STATIC mp_obj_t lv_struct_binary_op(mp_binary_op_t op, mp_obj_t lhs_in, mp_obj_t rhs_in)
{
    mp_lv_struct_t *lhs = MP_OBJ_TO_PTR(lhs_in);
    mp_lv_struct_t *rhs = MP_OBJ_TO_PTR(rhs_in);
    switch (op)
    {
        case MP_BINARY_OP_EQUAL:
            return mp_obj_new_bool(lhs->data == rhs->data);
        case MP_BINARY_OP_NOT_EQUAL:
            return mp_obj_new_bool(lhs->data != rhs->data);
        default:
            return MP_OBJ_NULL;
    }
}

STATIC mp_obj_t lv_struct_subscr(mp_obj_t self_in, mp_obj_t index, mp_obj_t value)
{
    mp_lv_struct_t *self = mp_to_lv_struct(self_in);

    if ((!self) || (!self->data))
        return NULL;
    if (!mp_obj_is_int(index)) {
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("Subscript index must be an integer!")));
    }

    const mp_obj_type_t *type = mp_obj_get_type(self_in);
    size_t element_size = get_lv_struct_size(type);
    if (element_size == 0) return mp_const_none;
    size_t element_index = mp_obj_get_int(index);
    void *element_addr = (byte*)self->data + element_size*element_index;

    if (value == MP_OBJ_NULL) {
        memset(element_addr, 0, element_size);
        return self_in;
    }

    mp_lv_struct_t *element_at_index = m_new_obj(mp_lv_struct_t);
    *element_at_index = (mp_lv_struct_t){
        .base = {type},
        .data = element_addr
    };

    if (value != MP_OBJ_SENTINEL){
        mp_lv_struct_t *other = mp_to_lv_struct(cast(value, type));
        if ((!other) || (!other->data))
            return NULL;
        memcpy(element_at_index->data, other->data, element_size);
    }

    return MP_OBJ_FROM_PTR(element_at_index);
}

GENMPY_UNUSED STATIC void *copy_buffer(const void *buffer, size_t size)
{
    void *new_buffer = m_malloc(size);
    memcpy(new_buffer, buffer, size);
    return new_buffer;
}

// Reference an existing lv struct (or part of it)

STATIC mp_obj_t lv_to_mp_struct(const mp_obj_type_t *type, void *lv_struct)
{
    if (lv_struct == NULL) return mp_const_none;
    mp_lv_struct_t *self = m_new_obj(mp_lv_struct_t);
    *self = (mp_lv_struct_t){
        .base = {type},
        .data = lv_struct
    };
    return MP_OBJ_FROM_PTR(self);
}

STATIC void call_parent_methods(mp_obj_t obj, qstr attr, mp_obj_t *dest)
{
    const mp_obj_type_t *type = mp_obj_get_type(obj);
    while (MP_OBJ_TYPE_HAS_SLOT(type, locals_dict)) {
        // generic method lookup
        // this is a lookup in the object (ie not class or type)
        assert(MP_OBJ_TYPE_GET_SLOT(type, locals_dict)->base.type == &mp_type_dict); // MicroPython restriction, for now
        mp_map_t *locals_map = &MP_OBJ_TYPE_GET_SLOT(type, locals_dict)->map;
        mp_map_elem_t *elem = mp_map_lookup(locals_map, MP_OBJ_NEW_QSTR(attr), MP_MAP_LOOKUP);
        if (elem != NULL) {
            mp_convert_member_lookup(obj, type, elem->value, dest);
            break;
        }
        if (MP_OBJ_TYPE_GET_SLOT_OR_NULL(type, parent) == NULL) {
            break;
        }
        // search parents
        type = MP_OBJ_TYPE_GET_SLOT(type, parent);
    }
}

// Convert dict to struct

STATIC mp_obj_t dict_to_struct(mp_obj_t dict, const mp_obj_type_t *type)
{
    mp_obj_t mp_struct = make_new_lv_struct(type, 0, 0, NULL);
    mp_obj_t native_dict = cast(dict, &mp_type_dict);
    mp_map_t *map = mp_obj_dict_get_map(native_dict);
    if (map == NULL) return mp_const_none;
    for (uint i = 0; i < map->alloc; i++) {
        mp_obj_t key = map->table[i].key;
        mp_obj_t value = map->table[i].value;
        if (key != MP_OBJ_NULL) {
            mp_obj_t dest[] = {MP_OBJ_SENTINEL, value};
            MP_OBJ_TYPE_GET_SLOT(type, attr)(mp_struct, mp_obj_str_get_qstr(key), dest);
            if (dest[0]) nlr_raise(
                mp_obj_new_exception_msg_varg(
                    &mp_type_SyntaxError, MP_ERROR_TEXT("Cannot set field %s on struct %s!"), qstr_str(mp_obj_str_get_qstr(key)), qstr_str(type->name)));
        }
    }
    return mp_struct;
}

// Convert mp object to ptr

STATIC void* mp_to_ptr(mp_obj_t self_in)
{
    mp_buffer_info_t buffer_info;
    if (self_in == NULL || self_in == mp_const_none)
        return NULL;

//    if (MP_OBJ_IS_INT(self_in))
//        return (void*)mp_obj_get_int(self_in);

    // If an object is user instance, take it as is so it could be used as user_data
    if (mp_obj_is_instance_type(mp_obj_get_type(self_in))){
        return MP_OBJ_TO_PTR(self_in);
    }

    if (!mp_get_buffer(self_in, &buffer_info, MP_BUFFER_READ)) {
        // No buffer protocol - this is not a Struct or a Blob, it's some other mp object.
        // We only allow setting dict directly, since it's useful to setting user_data for passing data to C.
        // On other cases throw an exception, to avoid a crash later
        if (MP_OBJ_IS_TYPE(self_in, &mp_type_dict))
            return MP_OBJ_TO_PTR(self_in);
        else nlr_raise(
                mp_obj_new_exception_msg_varg(
                    &mp_type_SyntaxError, MP_ERROR_TEXT("Cannot convert '%s' to pointer!"), mp_obj_get_type_str(self_in)));
    }

    if (MP_OBJ_IS_STR_OR_BYTES(self_in) ||
        MP_OBJ_IS_TYPE(self_in, &mp_type_bytearray) ||
        MP_OBJ_IS_TYPE(self_in, &mp_type_memoryview))
            return buffer_info.buf;
    else
    {
        void *result;
        if (buffer_info.len != sizeof(result) || buffer_info.typecode != BYTEARRAY_TYPECODE){
            nlr_raise(
                mp_obj_new_exception_msg_varg(
                    &mp_type_SyntaxError, MP_ERROR_TEXT("Cannot convert %s to pointer! (buffer does not represent a pointer)"), mp_obj_get_type_str(self_in)));
        }
        memcpy(&result, buffer_info.buf, sizeof(result));
        return result;
    }
}

// Blob is a wrapper for void*

STATIC void mp_blob_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "Blob");
}

STATIC mp_int_t mp_blob_get_buffer(mp_obj_t self_in, mp_buffer_info_t *bufinfo, mp_uint_t flags) {
    (void)flags;
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);

    bufinfo->buf = &self->data;
    bufinfo->len = sizeof(self->data);
    bufinfo->typecode = BYTEARRAY_TYPECODE;
    return 0;
}

STATIC const mp_obj_fun_builtin_var_t mp_lv_dereference_obj;

// Sometimes (but not always!) Blob represents a Micropython object.
// In such cases it's safe to cast the Blob back to the Micropython object
// cast argument is the underlying object type, and it's optional.

STATIC mp_obj_t mp_blob_cast(size_t argc, const mp_obj_t *argv)
{
    mp_obj_t self = argv[0];
    void *ptr = mp_to_ptr(self);
    if (argc == 1) return MP_OBJ_FROM_PTR(ptr);
    mp_obj_t type = argv[1];
    if (!MP_OBJ_IS_TYPE(type, &mp_type_type))
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("Cast argument must be a type!")));
    return cast(MP_OBJ_FROM_PTR(ptr), type);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_blob_cast_obj, 1, 2, mp_blob_cast);

STATIC const mp_rom_map_elem_t mp_blob_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___dereference__), MP_ROM_PTR(&mp_lv_dereference_obj) },
    { MP_ROM_QSTR(MP_QSTR___cast__), MP_ROM_PTR(&mp_blob_cast_obj) },
};

STATIC MP_DEFINE_CONST_DICT(mp_blob_locals_dict, mp_blob_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_blob_type,
    MP_QSTR_Blob,
    MP_TYPE_FLAG_NONE,
    binary_op, lv_struct_binary_op,
    print, mp_blob_print,
    locals_dict, &mp_blob_locals_dict,
    buffer, mp_blob_get_buffer
);

STATIC const mp_lv_struct_t mp_lv_null_obj = { {&mp_blob_type}, NULL };

STATIC inline mp_obj_t ptr_to_mp(void *data)
{
    return lv_to_mp_struct(&mp_blob_type, data);
}

// Cast pointer to struct

STATIC mp_obj_t mp_lv_cast(mp_obj_t type_obj, mp_obj_t ptr_obj)
{
    void *ptr = mp_to_ptr(ptr_obj);
    if (!ptr) return mp_const_none;
    mp_lv_struct_t *self = m_new_obj(mp_lv_struct_t);
    *self = (mp_lv_struct_t){
        .base = {(const mp_obj_type_t*)type_obj},
        .data = ptr
    };
    return MP_OBJ_FROM_PTR(self);
}

// Cast instance. Can be used in ISR when memory allocation is prohibited

STATIC inline mp_obj_t mp_lv_cast_instance(mp_obj_t self_in, mp_obj_t ptr_obj)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    self->data = mp_to_ptr(ptr_obj);
    return self_in;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_2(mp_lv_cast_obj, mp_lv_cast);
STATIC MP_DEFINE_CONST_CLASSMETHOD_OBJ(mp_lv_cast_class_method, MP_ROM_PTR(&mp_lv_cast_obj));

STATIC MP_DEFINE_CONST_FUN_OBJ_2(mp_lv_cast_instance_obj, mp_lv_cast_instance);

// Dereference a struct/blob. This allows access to the raw data the struct holds

STATIC mp_obj_t mp_lv_dereference(size_t argc, const mp_obj_t *argv)
{
    mp_obj_t self_in = argv[0];
    mp_obj_t size_in = argc > 1? argv[1]: mp_const_none;
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    size_t size = 0;
    if (size_in == mp_const_none){
        const mp_obj_type_t *type = self->base.type;
        size = get_lv_struct_size(type);
    } else {
        size = (size_t)mp_obj_get_int(size_in);
    }
    if (size == 0) return mp_const_none;
    mp_obj_array_t *view = MP_OBJ_TO_PTR(mp_obj_new_memoryview(BYTEARRAY_TYPECODE,
        size, self->data));
    view->typecode |= 0x80; // used to indicate writable buffer
    return MP_OBJ_FROM_PTR(view);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_lv_dereference_obj, 1, 2, mp_lv_dereference);

// Callback function handling
// Callback is either a callable object or a pointer. If it's a callable object, set user_data to the callback.
// Multiple callbacks are kept per object/struct using a dict that associate callback name with callback object
// In case of an lv_obj_t, user_data is mp_lv_obj_t which contains a member "callbacks" for that dict.
// In case of a struct, user_data is a pointer to that dict directly

STATIC mp_obj_t get_callback_dict_from_user_data(void *user_data)
{
    if (user_data){
        mp_obj_t obj = MP_OBJ_FROM_PTR(user_data);
#ifdef LV_OBJ_T
        return
            MP_OBJ_IS_TYPE(obj, &mp_type_dict)? obj: // Handle the case of dict for a struct
            mp_get_callbacks(obj); // Handle the case of mp_lv_obj_t for an lv_obj_t
#else
        return obj;
#endif
    }
    return NULL;
}

typedef void *(*mp_lv_get_user_data)(void *);
typedef void (*mp_lv_set_user_data)(void *, void *);

STATIC void *mp_lv_callback(mp_obj_t mp_callback, void *lv_callback, qstr callback_name,
     void **user_data_ptr, void *containing_struct, mp_lv_get_user_data get_user_data, mp_lv_set_user_data set_user_data)
{
    if (lv_callback && mp_obj_is_callable(mp_callback)) {
        void *user_data = NULL;
        if (user_data_ptr) {
            // user_data is either a dict of callbacks in case of struct, or a pointer to mp_lv_obj_t in case of lv_obj_t
            if (! (*user_data_ptr) ) *user_data_ptr = MP_OBJ_TO_PTR(mp_obj_new_dict(0)); // if it's NULL - it's a dict for a struct
            user_data = *user_data_ptr;
        }
        else if (get_user_data && set_user_data) {
            user_data = get_user_data(containing_struct);
            if (!user_data) {
                user_data = MP_OBJ_TO_PTR(mp_obj_new_dict(0));
                set_user_data(containing_struct, user_data);
            }
        }

        if (user_data) {
            mp_obj_t callbacks = get_callback_dict_from_user_data(user_data);
            mp_obj_dict_store(callbacks, MP_OBJ_NEW_QSTR(callback_name), mp_callback);
        }
        return lv_callback;
    } else {
        return mp_to_ptr(mp_callback);
    }
}

static int _nesting = 0;

// Function pointers wrapper

STATIC mp_obj_t mp_lv_funcptr(const mp_lv_obj_fun_builtin_var_t *mp_fun, void *lv_fun, void *lv_callback, qstr func_name, void *user_data)
{
    if (lv_fun == NULL)
        return mp_const_none;
    if (lv_fun == lv_callback) {
        mp_obj_t callbacks = get_callback_dict_from_user_data(user_data);
        if (callbacks)
            return mp_obj_dict_get(callbacks, MP_OBJ_NEW_QSTR(func_name));
    }
    mp_lv_obj_fun_builtin_var_t *funcptr = m_new_obj(mp_lv_obj_fun_builtin_var_t);
    *funcptr = *mp_fun;
    funcptr->lv_fun = lv_fun;
    return MP_OBJ_FROM_PTR(funcptr);
}

// Missing implementation for 64bit integer conversion

STATIC unsigned long long mp_obj_get_ull(mp_obj_t obj)
{
    if (mp_obj_is_small_int(obj))
        return MP_OBJ_SMALL_INT_VALUE(obj);

    unsigned long long val = 0;
    bool big_endian = !(__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__);
    mp_obj_int_to_bytes_impl(obj, big_endian, sizeof(val), (byte*)&val);
    return val;
}


// Array of natives

typedef struct mp_lv_array_t
{
    mp_lv_struct_t base;
    size_t element_size;
    bool is_signed;
} mp_lv_array_t;

STATIC void mp_lv_array_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_lv_array_t *self = MP_OBJ_TO_PTR(self_in);
    size_t element_size = self->element_size;
    bool is_signed = self->is_signed;
    mp_printf(print, "C Array (%sint%d[])", is_signed? "": "u", element_size*8);
}

STATIC mp_obj_t lv_array_subscr(mp_obj_t self_in, mp_obj_t index, mp_obj_t value)
{
    mp_lv_array_t *self = MP_OBJ_TO_PTR(self_in);

    if ((!self) || (!self->base.data))
        return NULL;
    if (!mp_obj_is_int(index)) {
        nlr_raise(
            mp_obj_new_exception_msg(
                &mp_type_SyntaxError, MP_ERROR_TEXT("Subscript index must be an integer!")));
    }

    size_t element_size = self->element_size;
    size_t element_index = mp_obj_get_int(index);
    void *element_addr = (byte*)self->base.data + element_size*element_index;
    bool is_signed = self->is_signed;
    union {
        long long val;
        unsigned long long uval;
    } element;
    memset(&element, 0, sizeof(element));

    if (value == MP_OBJ_NULL){
        memset(element_addr, 0, element_size);
    }
    else if (value == MP_OBJ_SENTINEL){
        memcpy(&element, element_addr, element_size);
        return is_signed? mp_obj_new_int_from_ll(element.val): mp_obj_new_int_from_ull(element.uval);
    } else {
        if (!mp_obj_is_int(value)) {
            nlr_raise(
                mp_obj_new_exception_msg_varg(
                    &mp_type_SyntaxError, MP_ERROR_TEXT("Value '%s' must be an integer!"), mp_obj_get_type_str(value)));
        }
        element.uval = mp_obj_get_ull(value);
        memcpy(element_addr, &element, element_size);
    }

    return self_in;
}

STATIC const mp_rom_map_elem_t mp_base_struct_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___cast__), MP_ROM_PTR(&mp_lv_cast_class_method) },
    { MP_ROM_QSTR(MP_QSTR___cast_instance__), MP_ROM_PTR(&mp_lv_cast_instance_obj) },
    { MP_ROM_QSTR(MP_QSTR___dereference__), MP_ROM_PTR(&mp_lv_dereference_obj) },
};

STATIC MP_DEFINE_CONST_DICT(mp_base_struct_locals_dict, mp_base_struct_locals_dict_table);

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_base_struct_type,
    MP_QSTR_Struct,
    MP_TYPE_FLAG_NONE,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    buffer, mp_blob_get_buffer,
    locals_dict, &mp_base_struct_locals_dict
);

// TODO: provide constructor
STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_array_type,
    MP_QSTR_C_Array,
    MP_TYPE_FLAG_NONE,
    print, mp_lv_array_print,
    binary_op, lv_struct_binary_op,
    subscr, lv_array_subscr,
    buffer, mp_blob_get_buffer,
    locals_dict, &mp_base_struct_locals_dict
);

GENMPY_UNUSED STATIC mp_obj_t mp_array_from_ptr(void *lv_arr, size_t element_size, bool is_signed)
{
    mp_lv_array_t *self = m_new_obj(mp_lv_array_t);
    *self = (mp_lv_array_t){
        { {&mp_lv_array_type}, lv_arr },
        element_size,
        is_signed
    };
    return MP_OBJ_FROM_PTR(self);
}

GENMPY_UNUSED STATIC void *mp_array_to_ptr(mp_obj_t *mp_arr, size_t element_size, GENMPY_UNUSED bool is_signed)
{
    if (MP_OBJ_IS_STR_OR_BYTES(mp_arr) ||
        MP_OBJ_IS_TYPE(mp_arr, &mp_type_bytearray) ||
        MP_OBJ_IS_TYPE(mp_arr, &mp_type_memoryview)){
            return mp_to_ptr(mp_arr);
    }

    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    void *lv_arr = m_malloc(len * element_size);
    byte *element_addr = (byte*)lv_arr;
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        union {
            long long val;
            unsigned long long uval;
        } element;
        if (!mp_obj_is_int(item)) {
            nlr_raise(
                mp_obj_new_exception_msg_varg(
                    &mp_type_SyntaxError, MP_ERROR_TEXT("Value '%s' must be an integer!"), mp_obj_get_type_str(item)));
        }
        element.uval = mp_obj_get_ull(item);
        memcpy(element_addr, &element, element_size);
        element_addr += element_size;
    }
    return lv_arr;
}

#define MP_ARRAY_CONVERTOR(name, size, is_signed) GENMPY_UNUSED STATIC mp_obj_t mp_array_from_ ## name(void *lv_arr){    return mp_array_from_ptr(lv_arr, size, is_signed);}GENMPY_UNUSED STATIC void *mp_array_to_ ## name(mp_obj_t mp_arr){    return mp_array_to_ptr(mp_arr, size, is_signed);}

MP_ARRAY_CONVERTOR(u8ptr, 1, false)
MP_ARRAY_CONVERTOR(i8ptr, 1, true)
MP_ARRAY_CONVERTOR(u16ptr, 2, false)
MP_ARRAY_CONVERTOR(i16ptr, 2, true)
MP_ARRAY_CONVERTOR(u32ptr, 4, false)
MP_ARRAY_CONVERTOR(i32ptr, 4, true)
MP_ARRAY_CONVERTOR(u64ptr, 8, false)
MP_ARRAY_CONVERTOR(i64ptr, 8, true)



/*
 * LVGL string constants
 */


/*
 * Helper Structs
 */
        

typedef union {
    void*           ptr_val;
    const char*     str_val;
    int             int_val;
    unsigned int    uint_val;
} C_Pointer;


/*
 * Struct C_Pointer
 */

STATIC inline const mp_obj_type_t *get_mp_C_Pointer_type();

STATIC inline void* mp_write_ptr_C_Pointer(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_C_Pointer_type()));
    return (C_Pointer*)self->data;
}

#define mp_write_C_Pointer(struct_obj) *((C_Pointer*)mp_write_ptr_C_Pointer(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_C_Pointer(void *field)
{
    return lv_to_mp_struct(get_mp_C_Pointer_type(), field);
}

#define mp_read_C_Pointer(field) mp_read_ptr_C_Pointer(copy_buffer(&field, sizeof(C_Pointer)))
#define mp_read_byref_C_Pointer(field) mp_read_ptr_C_Pointer(&field)

STATIC void mp_C_Pointer_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED C_Pointer *data = (C_Pointer*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ptr_val: dest[0] = ptr_to_mp((void*)data->ptr_val); break; // converting from void *;
            case MP_QSTR_str_val: dest[0] = convert_to_str((void*)data->str_val); break; // converting from char *;
            case MP_QSTR_int_val: dest[0] = mp_obj_new_int(data->int_val); break; // converting from int;
            case MP_QSTR_uint_val: dest[0] = mp_obj_new_int_from_uint(data->uint_val); break; // converting from unsigned int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ptr_val: data->ptr_val = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_str_val: data->str_val = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_int_val: data->int_val = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_uint_val: data->uint_val = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_C_Pointer_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct C_Pointer");
}

STATIC const mp_obj_dict_t mp_C_Pointer_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_C_Pointer_type,
    MP_QSTR_C_Pointer,
    MP_TYPE_FLAG_NONE,
    print, mp_C_Pointer_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_C_Pointer_attr,
    locals_dict, &mp_C_Pointer_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_C_Pointer_type()
{
    return &mp_C_Pointer_type;
}
    

/*
 * espidf IP6 object definitions
 */
    

STATIC const mp_rom_map_elem_t IP6_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(IP6_UNKNOWN)) },
    { MP_ROM_QSTR(MP_QSTR_UNICAST), MP_ROM_PTR(MP_ROM_INT(IP6_UNICAST)) },
    { MP_ROM_QSTR(MP_QSTR_MULTICAST), MP_ROM_PTR(MP_ROM_INT(IP6_MULTICAST)) }
};

STATIC MP_DEFINE_CONST_DICT(IP6_locals_dict, IP6_locals_dict_table);

STATIC void IP6_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf IP6");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_IP6_type_base,
    MP_QSTR_IP6,
    MP_TYPE_FLAG_NONE,
    print, IP6_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &IP6_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_IP6_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_IP6_type_base,
};
    

/*
 * espidf IPADDR_TYPE object definitions
 */
    

STATIC const mp_rom_map_elem_t IPADDR_TYPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_V4), MP_ROM_PTR(MP_ROM_INT(IPADDR_TYPE_V4)) },
    { MP_ROM_QSTR(MP_QSTR_V6), MP_ROM_PTR(MP_ROM_INT(IPADDR_TYPE_V6)) },
    { MP_ROM_QSTR(MP_QSTR_ANY), MP_ROM_PTR(MP_ROM_INT(IPADDR_TYPE_ANY)) }
};

STATIC MP_DEFINE_CONST_DICT(IPADDR_TYPE_locals_dict, IPADDR_TYPE_locals_dict_table);

STATIC void IPADDR_TYPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf IPADDR_TYPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_IPADDR_TYPE_type_base,
    MP_QSTR_IPADDR_TYPE,
    MP_TYPE_FLAG_NONE,
    print, IPADDR_TYPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &IPADDR_TYPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_IPADDR_TYPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_IPADDR_TYPE_type_base,
};
    

/*
 * espidf OFFER object definitions
 */
    

STATIC const mp_rom_map_elem_t OFFER_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_START), MP_ROM_PTR(MP_ROM_INT(OFFER_START)) },
    { MP_ROM_QSTR(MP_QSTR_ROUTER), MP_ROM_PTR(MP_ROM_INT(OFFER_ROUTER)) },
    { MP_ROM_QSTR(MP_QSTR_DNS), MP_ROM_PTR(MP_ROM_INT(OFFER_DNS)) },
    { MP_ROM_QSTR(MP_QSTR_END), MP_ROM_PTR(MP_ROM_INT(OFFER_END)) }
};

STATIC MP_DEFINE_CONST_DICT(OFFER_locals_dict, OFFER_locals_dict_table);

STATIC void OFFER_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf OFFER");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_OFFER_type_base,
    MP_QSTR_OFFER,
    MP_TYPE_FLAG_NONE,
    print, OFFER_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &OFFER_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_OFFER_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_OFFER_type_base,
};
    

/*
 * espidf HTTP object definitions
 */
    

STATIC const mp_rom_map_elem_t HTTP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DELETE), MP_ROM_PTR(MP_ROM_INT(HTTP_DELETE)) },
    { MP_ROM_QSTR(MP_QSTR_GET), MP_ROM_PTR(MP_ROM_INT(HTTP_GET)) },
    { MP_ROM_QSTR(MP_QSTR_HEAD), MP_ROM_PTR(MP_ROM_INT(HTTP_HEAD)) },
    { MP_ROM_QSTR(MP_QSTR_POST), MP_ROM_PTR(MP_ROM_INT(HTTP_POST)) },
    { MP_ROM_QSTR(MP_QSTR_PUT), MP_ROM_PTR(MP_ROM_INT(HTTP_PUT)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECT), MP_ROM_PTR(MP_ROM_INT(HTTP_CONNECT)) },
    { MP_ROM_QSTR(MP_QSTR_OPTIONS), MP_ROM_PTR(MP_ROM_INT(HTTP_OPTIONS)) },
    { MP_ROM_QSTR(MP_QSTR_TRACE), MP_ROM_PTR(MP_ROM_INT(HTTP_TRACE)) },
    { MP_ROM_QSTR(MP_QSTR_COPY), MP_ROM_PTR(MP_ROM_INT(HTTP_COPY)) },
    { MP_ROM_QSTR(MP_QSTR_LOCK), MP_ROM_PTR(MP_ROM_INT(HTTP_LOCK)) },
    { MP_ROM_QSTR(MP_QSTR_MKCOL), MP_ROM_PTR(MP_ROM_INT(HTTP_MKCOL)) },
    { MP_ROM_QSTR(MP_QSTR_MOVE), MP_ROM_PTR(MP_ROM_INT(HTTP_MOVE)) },
    { MP_ROM_QSTR(MP_QSTR_PROPFIND), MP_ROM_PTR(MP_ROM_INT(HTTP_PROPFIND)) },
    { MP_ROM_QSTR(MP_QSTR_PROPPATCH), MP_ROM_PTR(MP_ROM_INT(HTTP_PROPPATCH)) },
    { MP_ROM_QSTR(MP_QSTR_SEARCH), MP_ROM_PTR(MP_ROM_INT(HTTP_SEARCH)) },
    { MP_ROM_QSTR(MP_QSTR_UNLOCK), MP_ROM_PTR(MP_ROM_INT(HTTP_UNLOCK)) },
    { MP_ROM_QSTR(MP_QSTR_BIND), MP_ROM_PTR(MP_ROM_INT(HTTP_BIND)) },
    { MP_ROM_QSTR(MP_QSTR_REBIND), MP_ROM_PTR(MP_ROM_INT(HTTP_REBIND)) },
    { MP_ROM_QSTR(MP_QSTR_UNBIND), MP_ROM_PTR(MP_ROM_INT(HTTP_UNBIND)) },
    { MP_ROM_QSTR(MP_QSTR_ACL), MP_ROM_PTR(MP_ROM_INT(HTTP_ACL)) },
    { MP_ROM_QSTR(MP_QSTR_REPORT), MP_ROM_PTR(MP_ROM_INT(HTTP_REPORT)) },
    { MP_ROM_QSTR(MP_QSTR_MKACTIVITY), MP_ROM_PTR(MP_ROM_INT(HTTP_MKACTIVITY)) },
    { MP_ROM_QSTR(MP_QSTR_CHECKOUT), MP_ROM_PTR(MP_ROM_INT(HTTP_CHECKOUT)) },
    { MP_ROM_QSTR(MP_QSTR_MERGE), MP_ROM_PTR(MP_ROM_INT(HTTP_MERGE)) },
    { MP_ROM_QSTR(MP_QSTR_MSEARCH), MP_ROM_PTR(MP_ROM_INT(HTTP_MSEARCH)) },
    { MP_ROM_QSTR(MP_QSTR_NOTIFY), MP_ROM_PTR(MP_ROM_INT(HTTP_NOTIFY)) },
    { MP_ROM_QSTR(MP_QSTR_SUBSCRIBE), MP_ROM_PTR(MP_ROM_INT(HTTP_SUBSCRIBE)) },
    { MP_ROM_QSTR(MP_QSTR_UNSUBSCRIBE), MP_ROM_PTR(MP_ROM_INT(HTTP_UNSUBSCRIBE)) },
    { MP_ROM_QSTR(MP_QSTR_PATCH), MP_ROM_PTR(MP_ROM_INT(HTTP_PATCH)) },
    { MP_ROM_QSTR(MP_QSTR_PURGE), MP_ROM_PTR(MP_ROM_INT(HTTP_PURGE)) },
    { MP_ROM_QSTR(MP_QSTR_MKCALENDAR), MP_ROM_PTR(MP_ROM_INT(HTTP_MKCALENDAR)) },
    { MP_ROM_QSTR(MP_QSTR_LINK), MP_ROM_PTR(MP_ROM_INT(HTTP_LINK)) },
    { MP_ROM_QSTR(MP_QSTR_UNLINK), MP_ROM_PTR(MP_ROM_INT(HTTP_UNLINK)) },
    { MP_ROM_QSTR(MP_QSTR_REQUEST), MP_ROM_PTR(MP_ROM_INT(HTTP_REQUEST)) },
    { MP_ROM_QSTR(MP_QSTR_RESPONSE), MP_ROM_PTR(MP_ROM_INT(HTTP_RESPONSE)) },
    { MP_ROM_QSTR(MP_QSTR_BOTH), MP_ROM_PTR(MP_ROM_INT(HTTP_BOTH)) }
};

STATIC MP_DEFINE_CONST_DICT(HTTP_locals_dict, HTTP_locals_dict_table);

STATIC void HTTP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HTTP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HTTP_type_base,
    MP_QSTR_HTTP,
    MP_TYPE_FLAG_NONE,
    print, HTTP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HTTP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HTTP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HTTP_type_base,
};
    

/*
 * espidf F object definitions
 */
    

STATIC const mp_rom_map_elem_t F_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_CHUNKED), MP_ROM_PTR(MP_ROM_INT(F_CHUNKED)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECTION_KEEP_ALIVE), MP_ROM_PTR(MP_ROM_INT(F_CONNECTION_KEEP_ALIVE)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECTION_CLOSE), MP_ROM_PTR(MP_ROM_INT(F_CONNECTION_CLOSE)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECTION_UPGRADE), MP_ROM_PTR(MP_ROM_INT(F_CONNECTION_UPGRADE)) },
    { MP_ROM_QSTR(MP_QSTR_TRAILING), MP_ROM_PTR(MP_ROM_INT(F_TRAILING)) },
    { MP_ROM_QSTR(MP_QSTR_UPGRADE), MP_ROM_PTR(MP_ROM_INT(F_UPGRADE)) },
    { MP_ROM_QSTR(MP_QSTR_SKIPBODY), MP_ROM_PTR(MP_ROM_INT(F_SKIPBODY)) },
    { MP_ROM_QSTR(MP_QSTR_CONTENTLENGTH), MP_ROM_PTR(MP_ROM_INT(F_CONTENTLENGTH)) }
};

STATIC MP_DEFINE_CONST_DICT(F_locals_dict, F_locals_dict_table);

STATIC void F_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf F");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_F_type_base,
    MP_QSTR_F,
    MP_TYPE_FLAG_NONE,
    print, F_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &F_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_F_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_F_type_base,
};
    

/*
 * espidf HPE object definitions
 */
    

STATIC const mp_rom_map_elem_t HPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_OK), MP_ROM_PTR(MP_ROM_INT(HPE_OK)) },
    { MP_ROM_QSTR(MP_QSTR_CB_message_begin), MP_ROM_PTR(MP_ROM_INT(HPE_CB_message_begin)) },
    { MP_ROM_QSTR(MP_QSTR_CB_url), MP_ROM_PTR(MP_ROM_INT(HPE_CB_url)) },
    { MP_ROM_QSTR(MP_QSTR_CB_header_field), MP_ROM_PTR(MP_ROM_INT(HPE_CB_header_field)) },
    { MP_ROM_QSTR(MP_QSTR_CB_header_value), MP_ROM_PTR(MP_ROM_INT(HPE_CB_header_value)) },
    { MP_ROM_QSTR(MP_QSTR_CB_headers_complete), MP_ROM_PTR(MP_ROM_INT(HPE_CB_headers_complete)) },
    { MP_ROM_QSTR(MP_QSTR_CB_body), MP_ROM_PTR(MP_ROM_INT(HPE_CB_body)) },
    { MP_ROM_QSTR(MP_QSTR_CB_message_complete), MP_ROM_PTR(MP_ROM_INT(HPE_CB_message_complete)) },
    { MP_ROM_QSTR(MP_QSTR_CB_status), MP_ROM_PTR(MP_ROM_INT(HPE_CB_status)) },
    { MP_ROM_QSTR(MP_QSTR_CB_chunk_header), MP_ROM_PTR(MP_ROM_INT(HPE_CB_chunk_header)) },
    { MP_ROM_QSTR(MP_QSTR_CB_chunk_complete), MP_ROM_PTR(MP_ROM_INT(HPE_CB_chunk_complete)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_EOF_STATE), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_EOF_STATE)) },
    { MP_ROM_QSTR(MP_QSTR_HEADER_OVERFLOW), MP_ROM_PTR(MP_ROM_INT(HPE_HEADER_OVERFLOW)) },
    { MP_ROM_QSTR(MP_QSTR_CLOSED_CONNECTION), MP_ROM_PTR(MP_ROM_INT(HPE_CLOSED_CONNECTION)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_VERSION), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_VERSION)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_STATUS), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_STATUS)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_METHOD), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_METHOD)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_URL), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_URL)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_HOST), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_PORT), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_PORT)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_PATH), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_PATH)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_QUERY_STRING), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_QUERY_STRING)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_FRAGMENT), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_FRAGMENT)) },
    { MP_ROM_QSTR(MP_QSTR_LF_EXPECTED), MP_ROM_PTR(MP_ROM_INT(HPE_LF_EXPECTED)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_HEADER_TOKEN), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_HEADER_TOKEN)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_CONTENT_LENGTH), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_CONTENT_LENGTH)) },
    { MP_ROM_QSTR(MP_QSTR_UNEXPECTED_CONTENT_LENGTH), MP_ROM_PTR(MP_ROM_INT(HPE_UNEXPECTED_CONTENT_LENGTH)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_CHUNK_SIZE), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_CHUNK_SIZE)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_CONSTANT), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_CONSTANT)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_INTERNAL_STATE), MP_ROM_PTR(MP_ROM_INT(HPE_INVALID_INTERNAL_STATE)) },
    { MP_ROM_QSTR(MP_QSTR_STRICT), MP_ROM_PTR(MP_ROM_INT(HPE_STRICT)) },
    { MP_ROM_QSTR(MP_QSTR_PAUSED), MP_ROM_PTR(MP_ROM_INT(HPE_PAUSED)) },
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(HPE_UNKNOWN)) }
};

STATIC MP_DEFINE_CONST_DICT(HPE_locals_dict, HPE_locals_dict_table);

STATIC void HPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HPE_type_base,
    MP_QSTR_HPE,
    MP_TYPE_FLAG_NONE,
    print, HPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HPE_type_base,
};
    

/*
 * espidf UF object definitions
 */
    

STATIC const mp_rom_map_elem_t UF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SCHEMA), MP_ROM_PTR(MP_ROM_INT(UF_SCHEMA)) },
    { MP_ROM_QSTR(MP_QSTR_HOST), MP_ROM_PTR(MP_ROM_INT(UF_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_PORT), MP_ROM_PTR(MP_ROM_INT(UF_PORT)) },
    { MP_ROM_QSTR(MP_QSTR_PATH), MP_ROM_PTR(MP_ROM_INT(UF_PATH)) },
    { MP_ROM_QSTR(MP_QSTR_QUERY), MP_ROM_PTR(MP_ROM_INT(UF_QUERY)) },
    { MP_ROM_QSTR(MP_QSTR_FRAGMENT), MP_ROM_PTR(MP_ROM_INT(UF_FRAGMENT)) },
    { MP_ROM_QSTR(MP_QSTR_USERINFO), MP_ROM_PTR(MP_ROM_INT(UF_USERINFO)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(UF_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(UF_locals_dict, UF_locals_dict_table);

STATIC void UF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf UF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_UF_type_base,
    MP_QSTR_UF,
    MP_TYPE_FLAG_NONE,
    print, UF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &UF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_UF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_UF_type_base,
};
    

/*
 * espidf ENUM_SPI_DEVICE object definitions
 */
    

STATIC const mp_rom_map_elem_t ENUM_SPI_DEVICE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_TXBIT_LSBFIRST), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_TXBIT_LSBFIRST)) },
    { MP_ROM_QSTR(MP_QSTR_RXBIT_LSBFIRST), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_RXBIT_LSBFIRST)) },
    { MP_ROM_QSTR(MP_QSTR_BIT_LSBFIRST), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_BIT_LSBFIRST)) },
    { MP_ROM_QSTR(MP_QSTR__3WIRE), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_3WIRE)) },
    { MP_ROM_QSTR(MP_QSTR_POSITIVE_CS), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_POSITIVE_CS)) },
    { MP_ROM_QSTR(MP_QSTR_HALFDUPLEX), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_HALFDUPLEX)) },
    { MP_ROM_QSTR(MP_QSTR_NO_DUMMY), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_NO_DUMMY)) },
    { MP_ROM_QSTR(MP_QSTR_CLK_AS_CS), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_DEVICE_CLK_AS_CS)) }
};

STATIC MP_DEFINE_CONST_DICT(ENUM_SPI_DEVICE_locals_dict, ENUM_SPI_DEVICE_locals_dict_table);

STATIC void ENUM_SPI_DEVICE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ENUM_SPI_DEVICE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ENUM_SPI_DEVICE_type_base,
    MP_QSTR_ENUM_SPI_DEVICE,
    MP_TYPE_FLAG_NONE,
    print, ENUM_SPI_DEVICE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ENUM_SPI_DEVICE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ENUM_SPI_DEVICE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ENUM_SPI_DEVICE_type_base,
};
    

/*
 * espidf ENUM_SPI_TRANS object definitions
 */
    

STATIC const mp_rom_map_elem_t ENUM_SPI_TRANS_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MODE_DIO), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_MODE_DIO)) },
    { MP_ROM_QSTR(MP_QSTR_MODE_QIO), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_MODE_QIO)) },
    { MP_ROM_QSTR(MP_QSTR_MODE_DIOQIO_ADDR), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_MODE_DIOQIO_ADDR)) },
    { MP_ROM_QSTR(MP_QSTR_USE_RXDATA), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_USE_RXDATA)) },
    { MP_ROM_QSTR(MP_QSTR_USE_TXDATA), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_USE_TXDATA)) },
    { MP_ROM_QSTR(MP_QSTR_VARIABLE_CMD), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_VARIABLE_CMD)) },
    { MP_ROM_QSTR(MP_QSTR_VARIABLE_ADDR), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_TRANS_VARIABLE_ADDR)) }
};

STATIC MP_DEFINE_CONST_DICT(ENUM_SPI_TRANS_locals_dict, ENUM_SPI_TRANS_locals_dict_table);

STATIC void ENUM_SPI_TRANS_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ENUM_SPI_TRANS");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ENUM_SPI_TRANS_type_base,
    MP_QSTR_ENUM_SPI_TRANS,
    MP_TYPE_FLAG_NONE,
    print, ENUM_SPI_TRANS_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ENUM_SPI_TRANS_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ENUM_SPI_TRANS_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ENUM_SPI_TRANS_type_base,
};
    

/*
 * espidf ENUM_MALLOC_CAP object definitions
 */
    

STATIC const mp_rom_map_elem_t ENUM_MALLOC_CAP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_EXEC), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_EXEC)) },
    { MP_ROM_QSTR(MP_QSTR__32BIT), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_32BIT)) },
    { MP_ROM_QSTR(MP_QSTR__8BIT), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_8BIT)) },
    { MP_ROM_QSTR(MP_QSTR_DMA), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_DMA)) },
    { MP_ROM_QSTR(MP_QSTR_SPIRAM), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_SPIRAM)) },
    { MP_ROM_QSTR(MP_QSTR_INTERNAL), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_INTERNAL)) },
    { MP_ROM_QSTR(MP_QSTR_DEFAULT), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_DEFAULT)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID), MP_ROM_PTR(MP_ROM_INT(ENUM_MALLOC_CAP_INVALID)) }
};

STATIC MP_DEFINE_CONST_DICT(ENUM_MALLOC_CAP_locals_dict, ENUM_MALLOC_CAP_locals_dict_table);

STATIC void ENUM_MALLOC_CAP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ENUM_MALLOC_CAP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ENUM_MALLOC_CAP_type_base,
    MP_QSTR_ENUM_MALLOC_CAP,
    MP_TYPE_FLAG_NONE,
    print, ENUM_MALLOC_CAP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ENUM_MALLOC_CAP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ENUM_MALLOC_CAP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ENUM_MALLOC_CAP_type_base,
};
    

/*
 * espidf ENUM_ESP_TASK_PRIO object definitions
 */
    

STATIC const mp_rom_map_elem_t ENUM_ESP_TASK_PRIO_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ENUM_ESP_TASK_PRIO_MAX)) },
    { MP_ROM_QSTR(MP_QSTR_MIN), MP_ROM_PTR(MP_ROM_INT(ENUM_ESP_TASK_PRIO_MIN)) }
};

STATIC MP_DEFINE_CONST_DICT(ENUM_ESP_TASK_PRIO_locals_dict, ENUM_ESP_TASK_PRIO_locals_dict_table);

STATIC void ENUM_ESP_TASK_PRIO_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ENUM_ESP_TASK_PRIO");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ENUM_ESP_TASK_PRIO_type_base,
    MP_QSTR_ENUM_ESP_TASK_PRIO,
    MP_TYPE_FLAG_NONE,
    print, ENUM_ESP_TASK_PRIO_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ENUM_ESP_TASK_PRIO_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ENUM_ESP_TASK_PRIO_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ENUM_ESP_TASK_PRIO_type_base,
};
    

/*
 * espidf GPIO_PORT object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_PORT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(GPIO_PORT_0)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(GPIO_PORT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_PORT_locals_dict, GPIO_PORT_locals_dict_table);

STATIC void GPIO_PORT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_PORT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_PORT_type_base,
    MP_QSTR_GPIO_PORT,
    MP_TYPE_FLAG_NONE,
    print, GPIO_PORT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_PORT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_PORT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_PORT_type_base,
};
    

/*
 * espidf GPIO_NUM object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_NUM_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NC), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_NC)) },
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_2)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_3)) },
    { MP_ROM_QSTR(MP_QSTR__4), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_4)) },
    { MP_ROM_QSTR(MP_QSTR__5), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_5)) },
    { MP_ROM_QSTR(MP_QSTR__6), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_6)) },
    { MP_ROM_QSTR(MP_QSTR__7), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_7)) },
    { MP_ROM_QSTR(MP_QSTR__8), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_8)) },
    { MP_ROM_QSTR(MP_QSTR__9), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_9)) },
    { MP_ROM_QSTR(MP_QSTR__10), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_10)) },
    { MP_ROM_QSTR(MP_QSTR__11), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_11)) },
    { MP_ROM_QSTR(MP_QSTR__12), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_12)) },
    { MP_ROM_QSTR(MP_QSTR__13), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_13)) },
    { MP_ROM_QSTR(MP_QSTR__14), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_14)) },
    { MP_ROM_QSTR(MP_QSTR__15), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_15)) },
    { MP_ROM_QSTR(MP_QSTR__16), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_16)) },
    { MP_ROM_QSTR(MP_QSTR__17), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_17)) },
    { MP_ROM_QSTR(MP_QSTR__18), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_18)) },
    { MP_ROM_QSTR(MP_QSTR__19), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_19)) },
    { MP_ROM_QSTR(MP_QSTR__20), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_20)) },
    { MP_ROM_QSTR(MP_QSTR__21), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_21)) },
    { MP_ROM_QSTR(MP_QSTR__22), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_22)) },
    { MP_ROM_QSTR(MP_QSTR__23), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_23)) },
    { MP_ROM_QSTR(MP_QSTR__25), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_25)) },
    { MP_ROM_QSTR(MP_QSTR__26), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_26)) },
    { MP_ROM_QSTR(MP_QSTR__27), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_27)) },
    { MP_ROM_QSTR(MP_QSTR__28), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_28)) },
    { MP_ROM_QSTR(MP_QSTR__29), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_29)) },
    { MP_ROM_QSTR(MP_QSTR__30), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_30)) },
    { MP_ROM_QSTR(MP_QSTR__31), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_31)) },
    { MP_ROM_QSTR(MP_QSTR__32), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_32)) },
    { MP_ROM_QSTR(MP_QSTR__33), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_33)) },
    { MP_ROM_QSTR(MP_QSTR__34), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_34)) },
    { MP_ROM_QSTR(MP_QSTR__35), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_35)) },
    { MP_ROM_QSTR(MP_QSTR__36), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_36)) },
    { MP_ROM_QSTR(MP_QSTR__37), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_37)) },
    { MP_ROM_QSTR(MP_QSTR__38), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_38)) },
    { MP_ROM_QSTR(MP_QSTR__39), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_39)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(GPIO_NUM_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_NUM_locals_dict, GPIO_NUM_locals_dict_table);

STATIC void GPIO_NUM_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_NUM");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_NUM_type_base,
    MP_QSTR_GPIO_NUM,
    MP_TYPE_FLAG_NONE,
    print, GPIO_NUM_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_NUM_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_NUM_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_NUM_type_base,
};
    

/*
 * espidf GPIO_INTR object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_INTR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_POSEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_POSEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_NEGEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_NEGEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_ANYEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_ANYEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_LOW_LEVEL), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_LOW_LEVEL)) },
    { MP_ROM_QSTR(MP_QSTR_HIGH_LEVEL), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_HIGH_LEVEL)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(GPIO_INTR_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_INTR_locals_dict, GPIO_INTR_locals_dict_table);

STATIC void GPIO_INTR_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_INTR");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_INTR_type_base,
    MP_QSTR_GPIO_INTR,
    MP_TYPE_FLAG_NONE,
    print, GPIO_INTR_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_INTR_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_INTR_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_INTR_type_base,
};
    

/*
 * espidf GPIO_MODE object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_MODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_INPUT), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_INPUT)) },
    { MP_ROM_QSTR(MP_QSTR_OUTPUT), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_OUTPUT)) },
    { MP_ROM_QSTR(MP_QSTR_OUTPUT_OD), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_OUTPUT_OD)) },
    { MP_ROM_QSTR(MP_QSTR_INPUT_OUTPUT_OD), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_INPUT_OUTPUT_OD)) },
    { MP_ROM_QSTR(MP_QSTR_INPUT_OUTPUT), MP_ROM_PTR(MP_ROM_INT(GPIO_MODE_INPUT_OUTPUT)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_MODE_locals_dict, GPIO_MODE_locals_dict_table);

STATIC void GPIO_MODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_MODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_MODE_type_base,
    MP_QSTR_GPIO_MODE,
    MP_TYPE_FLAG_NONE,
    print, GPIO_MODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_MODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_MODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_MODE_type_base,
};
    

/*
 * espidf GPIO_PULLUP object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_PULLUP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLUP_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_ENABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLUP_ENABLE)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_PULLUP_locals_dict, GPIO_PULLUP_locals_dict_table);

STATIC void GPIO_PULLUP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_PULLUP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_PULLUP_type_base,
    MP_QSTR_GPIO_PULLUP,
    MP_TYPE_FLAG_NONE,
    print, GPIO_PULLUP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_PULLUP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_PULLUP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_PULLUP_type_base,
};
    

/*
 * espidf GPIO_PULLDOWN object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_PULLDOWN_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLDOWN_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_ENABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLDOWN_ENABLE)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_PULLDOWN_locals_dict, GPIO_PULLDOWN_locals_dict_table);

STATIC void GPIO_PULLDOWN_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_PULLDOWN");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_PULLDOWN_type_base,
    MP_QSTR_GPIO_PULLDOWN,
    MP_TYPE_FLAG_NONE,
    print, GPIO_PULLDOWN_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_PULLDOWN_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_PULLDOWN_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_PULLDOWN_type_base,
};
    

/*
 * espidf GPIO object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_PULLUP_ONLY), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLUP_ONLY)) },
    { MP_ROM_QSTR(MP_QSTR_PULLDOWN_ONLY), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLDOWN_ONLY)) },
    { MP_ROM_QSTR(MP_QSTR_PULLUP_PULLDOWN), MP_ROM_PTR(MP_ROM_INT(GPIO_PULLUP_PULLDOWN)) },
    { MP_ROM_QSTR(MP_QSTR_FLOATING), MP_ROM_PTR(MP_ROM_INT(GPIO_FLOATING)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_locals_dict, GPIO_locals_dict_table);

STATIC void GPIO_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_type_base,
    MP_QSTR_GPIO,
    MP_TYPE_FLAG_NONE,
    print, GPIO_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_type_base,
};
    

/*
 * espidf GPIO_DRIVE_CAP object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_DRIVE_CAP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_2)) },
    { MP_ROM_QSTR(MP_QSTR_DEFAULT), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_DEFAULT)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_3)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(GPIO_DRIVE_CAP_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_DRIVE_CAP_locals_dict, GPIO_DRIVE_CAP_locals_dict_table);

STATIC void GPIO_DRIVE_CAP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_DRIVE_CAP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_DRIVE_CAP_type_base,
    MP_QSTR_GPIO_DRIVE_CAP,
    MP_TYPE_FLAG_NONE,
    print, GPIO_DRIVE_CAP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_DRIVE_CAP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_DRIVE_CAP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_DRIVE_CAP_type_base,
};
    

/*
 * espidf GPIO_PIN_INTR object definitions
 */
    

STATIC const mp_rom_map_elem_t GPIO_PIN_INTR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_POSEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_POSEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_NEGEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_NEGEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_ANYEDGE), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_ANYEDGE)) },
    { MP_ROM_QSTR(MP_QSTR_LOLEVEL), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_LOLEVEL)) },
    { MP_ROM_QSTR(MP_QSTR_HILEVEL), MP_ROM_PTR(MP_ROM_INT(GPIO_PIN_INTR_HILEVEL)) }
};

STATIC MP_DEFINE_CONST_DICT(GPIO_PIN_INTR_locals_dict, GPIO_PIN_INTR_locals_dict_table);

STATIC void GPIO_PIN_INTR_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf GPIO_PIN_INTR");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_GPIO_PIN_INTR_type_base,
    MP_QSTR_GPIO_PIN_INTR,
    MP_TYPE_FLAG_NONE,
    print, GPIO_PIN_INTR_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &GPIO_PIN_INTR_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_GPIO_PIN_INTR_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_GPIO_PIN_INTR_type_base,
};
    

/*
 * espidf PERIPH object definitions
 */
    

STATIC const mp_rom_map_elem_t PERIPH_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_LEDC_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_LEDC_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_UART0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_UART0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_UART1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_UART1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_UART2_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_UART2_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_I2C0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_I2C0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_I2C1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_I2C1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_I2S0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_I2S0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_I2S1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_I2S1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_TIMG0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_TIMG0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_TIMG1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_TIMG1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_PWM0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_PWM0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_PWM1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_PWM1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_UHCI0_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_UHCI0_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_UHCI1_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_UHCI1_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_RMT_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_RMT_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_PCNT_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SPI_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SPI_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_HSPI_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_HSPI_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_VSPI_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_VSPI_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SPI_DMA_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SPI_DMA_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SDMMC_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SDMMC_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SDIO_SLAVE_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SDIO_SLAVE_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_TWAI_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_TWAI_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_CAN_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_CAN_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_EMAC_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_EMAC_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_RNG_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_RNG_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_WIFI_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_BT_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_BT_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_BT_COMMON_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_WIFI_BT_COMMON_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_BT_BASEBAND_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_BT_BASEBAND_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_BT_LC_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_BT_LC_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_AES_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_AES_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SHA_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SHA_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_RSA_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_RSA_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_SARADC_MODULE), MP_ROM_PTR(MP_ROM_INT(PERIPH_SARADC_MODULE)) },
    { MP_ROM_QSTR(MP_QSTR_MODULE_MAX), MP_ROM_PTR(MP_ROM_INT(PERIPH_MODULE_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(PERIPH_locals_dict, PERIPH_locals_dict_table);

STATIC void PERIPH_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PERIPH");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PERIPH_type_base,
    MP_QSTR_PERIPH,
    MP_TYPE_FLAG_NONE,
    print, PERIPH_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PERIPH_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PERIPH_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PERIPH_type_base,
};
    

/*
 * espidf SPI_EV object definitions
 */
    

STATIC const mp_rom_map_elem_t SPI_EV_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_BUF_TX), MP_ROM_PTR(MP_ROM_INT(SPI_EV_BUF_TX)) },
    { MP_ROM_QSTR(MP_QSTR_BUF_RX), MP_ROM_PTR(MP_ROM_INT(SPI_EV_BUF_RX)) },
    { MP_ROM_QSTR(MP_QSTR_SEND_DMA_READY), MP_ROM_PTR(MP_ROM_INT(SPI_EV_SEND_DMA_READY)) },
    { MP_ROM_QSTR(MP_QSTR_SEND), MP_ROM_PTR(MP_ROM_INT(SPI_EV_SEND)) },
    { MP_ROM_QSTR(MP_QSTR_RECV_DMA_READY), MP_ROM_PTR(MP_ROM_INT(SPI_EV_RECV_DMA_READY)) },
    { MP_ROM_QSTR(MP_QSTR_RECV), MP_ROM_PTR(MP_ROM_INT(SPI_EV_RECV)) },
    { MP_ROM_QSTR(MP_QSTR_CMD9), MP_ROM_PTR(MP_ROM_INT(SPI_EV_CMD9)) },
    { MP_ROM_QSTR(MP_QSTR_CMDA), MP_ROM_PTR(MP_ROM_INT(SPI_EV_CMDA)) },
    { MP_ROM_QSTR(MP_QSTR_TRANS), MP_ROM_PTR(MP_ROM_INT(SPI_EV_TRANS)) }
};

STATIC MP_DEFINE_CONST_DICT(SPI_EV_locals_dict, SPI_EV_locals_dict_table);

STATIC void SPI_EV_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SPI_EV");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SPI_EV_type_base,
    MP_QSTR_SPI_EV,
    MP_TYPE_FLAG_NONE,
    print, SPI_EV_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SPI_EV_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SPI_EV_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SPI_EV_type_base,
};
    

/*
 * espidf SPI_CMD_HD object definitions
 */
    

STATIC const mp_rom_map_elem_t SPI_CMD_HD_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_WRBUF), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_WRBUF)) },
    { MP_ROM_QSTR(MP_QSTR_RDBUF), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_RDBUF)) },
    { MP_ROM_QSTR(MP_QSTR_WRDMA), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_WRDMA)) },
    { MP_ROM_QSTR(MP_QSTR_RDDMA), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_RDDMA)) },
    { MP_ROM_QSTR(MP_QSTR_SEG_END), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_SEG_END)) },
    { MP_ROM_QSTR(MP_QSTR_EN_QPI), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_EN_QPI)) },
    { MP_ROM_QSTR(MP_QSTR_WR_END), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_WR_END)) },
    { MP_ROM_QSTR(MP_QSTR_INT0), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_INT0)) },
    { MP_ROM_QSTR(MP_QSTR_INT1), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_INT1)) },
    { MP_ROM_QSTR(MP_QSTR_INT2), MP_ROM_PTR(MP_ROM_INT(SPI_CMD_HD_INT2)) }
};

STATIC MP_DEFINE_CONST_DICT(SPI_CMD_HD_locals_dict, SPI_CMD_HD_locals_dict_table);

STATIC void SPI_CMD_HD_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SPI_CMD_HD");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SPI_CMD_HD_type_base,
    MP_QSTR_SPI_CMD_HD,
    MP_TYPE_FLAG_NONE,
    print, SPI_CMD_HD_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SPI_CMD_HD_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SPI_CMD_HD_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SPI_CMD_HD_type_base,
};
    

/*
 * espidf SPI_DMA object definitions
 */
    

STATIC const mp_rom_map_elem_t SPI_DMA_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLED), MP_ROM_PTR(MP_ROM_INT(SPI_DMA_DISABLED)) },
    { MP_ROM_QSTR(MP_QSTR_CH1), MP_ROM_PTR(MP_ROM_INT(SPI_DMA_CH1)) },
    { MP_ROM_QSTR(MP_QSTR_CH2), MP_ROM_PTR(MP_ROM_INT(SPI_DMA_CH2)) },
    { MP_ROM_QSTR(MP_QSTR_CH_AUTO), MP_ROM_PTR(MP_ROM_INT(SPI_DMA_CH_AUTO)) }
};

STATIC MP_DEFINE_CONST_DICT(SPI_DMA_locals_dict, SPI_DMA_locals_dict_table);

STATIC void SPI_DMA_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SPI_DMA");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SPI_DMA_type_base,
    MP_QSTR_SPI_DMA,
    MP_TYPE_FLAG_NONE,
    print, SPI_DMA_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SPI_DMA_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SPI_DMA_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SPI_DMA_type_base,
};
    

/*
 * espidf RESET_REASON object definitions
 */
    

STATIC const mp_rom_map_elem_t RESET_REASON_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_CHIP_POWER_ON), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CHIP_POWER_ON)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_SW), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_SW)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_DEEP_SLEEP), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_DEEP_SLEEP)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_SDIO), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_SDIO)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_MWDT0), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_MWDT0)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_MWDT1), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_MWDT1)) },
    { MP_ROM_QSTR(MP_QSTR_CORE_RTC_WDT), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CORE_RTC_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_CPU0_MWDT0), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU0_MWDT0)) },
    { MP_ROM_QSTR(MP_QSTR_CPU1_MWDT1), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU1_MWDT1)) },
    { MP_ROM_QSTR(MP_QSTR_CPU0_SW), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU0_SW)) },
    { MP_ROM_QSTR(MP_QSTR_CPU1_SW), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU1_SW)) },
    { MP_ROM_QSTR(MP_QSTR_CPU0_RTC_WDT), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU0_RTC_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_CPU1_RTC_WDT), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU1_RTC_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_CPU1_CPU0), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_CPU1_CPU0)) },
    { MP_ROM_QSTR(MP_QSTR_SYS_BROWN_OUT), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_SYS_BROWN_OUT)) },
    { MP_ROM_QSTR(MP_QSTR_SYS_RTC_WDT), MP_ROM_PTR(MP_ROM_INT(RESET_REASON_SYS_RTC_WDT)) }
};

STATIC MP_DEFINE_CONST_DICT(RESET_REASON_locals_dict, RESET_REASON_locals_dict_table);

STATIC void RESET_REASON_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf RESET_REASON");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_RESET_REASON_type_base,
    MP_QSTR_RESET_REASON,
    MP_TYPE_FLAG_NONE,
    print, RESET_REASON_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &RESET_REASON_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_RESET_REASON_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_RESET_REASON_type_base,
};
    

/*
 * espidf ESP_LOG object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_LOG_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_ERROR), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_ERROR)) },
    { MP_ROM_QSTR(MP_QSTR_WARN), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_WARN)) },
    { MP_ROM_QSTR(MP_QSTR_INFO), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_INFO)) },
    { MP_ROM_QSTR(MP_QSTR_DEBUG), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_DEBUG)) },
    { MP_ROM_QSTR(MP_QSTR_VERBOSE), MP_ROM_PTR(MP_ROM_INT(ESP_LOG_VERBOSE)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_LOG_locals_dict, ESP_LOG_locals_dict_table);

STATIC void ESP_LOG_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_LOG");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_LOG_type_base,
    MP_QSTR_ESP_LOG,
    MP_TYPE_FLAG_NONE,
    print, ESP_LOG_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_LOG_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_LOG_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_LOG_type_base,
};
    

/*
 * espidf ADC_UNIT object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_UNIT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(ADC_UNIT_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(ADC_UNIT_2)) },
    { MP_ROM_QSTR(MP_QSTR_BOTH), MP_ROM_PTR(MP_ROM_INT(ADC_UNIT_BOTH)) },
    { MP_ROM_QSTR(MP_QSTR_ALTER), MP_ROM_PTR(MP_ROM_INT(ADC_UNIT_ALTER)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_UNIT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_UNIT_locals_dict, ADC_UNIT_locals_dict_table);

STATIC void ADC_UNIT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_UNIT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_UNIT_type_base,
    MP_QSTR_ADC_UNIT,
    MP_TYPE_FLAG_NONE,
    print, ADC_UNIT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_UNIT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_UNIT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_UNIT_type_base,
};
    

/*
 * espidf ADC_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_2)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_3)) },
    { MP_ROM_QSTR(MP_QSTR__4), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_4)) },
    { MP_ROM_QSTR(MP_QSTR__5), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_5)) },
    { MP_ROM_QSTR(MP_QSTR__6), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_6)) },
    { MP_ROM_QSTR(MP_QSTR__7), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_7)) },
    { MP_ROM_QSTR(MP_QSTR__8), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_8)) },
    { MP_ROM_QSTR(MP_QSTR__9), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_9)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_CHANNEL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_CHANNEL_locals_dict, ADC_CHANNEL_locals_dict_table);

STATIC void ADC_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_CHANNEL_type_base,
    MP_QSTR_ADC_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, ADC_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_CHANNEL_type_base,
};
    

/*
 * espidf ADC_ATTEN object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_ATTEN_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DB_0), MP_ROM_PTR(MP_ROM_INT(ADC_ATTEN_DB_0)) },
    { MP_ROM_QSTR(MP_QSTR_DB_2_5), MP_ROM_PTR(MP_ROM_INT(ADC_ATTEN_DB_2_5)) },
    { MP_ROM_QSTR(MP_QSTR_DB_6), MP_ROM_PTR(MP_ROM_INT(ADC_ATTEN_DB_6)) },
    { MP_ROM_QSTR(MP_QSTR_DB_11), MP_ROM_PTR(MP_ROM_INT(ADC_ATTEN_DB_11)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_ATTEN_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_ATTEN_locals_dict, ADC_ATTEN_locals_dict_table);

STATIC void ADC_ATTEN_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_ATTEN");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_ATTEN_type_base,
    MP_QSTR_ADC_ATTEN,
    MP_TYPE_FLAG_NONE,
    print, ADC_ATTEN_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_ATTEN_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_ATTEN_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_ATTEN_type_base,
};
    

/*
 * espidf ADC_WIDTH object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_WIDTH_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_BIT_9), MP_ROM_PTR(MP_ROM_INT(ADC_WIDTH_BIT_9)) },
    { MP_ROM_QSTR(MP_QSTR_BIT_10), MP_ROM_PTR(MP_ROM_INT(ADC_WIDTH_BIT_10)) },
    { MP_ROM_QSTR(MP_QSTR_BIT_11), MP_ROM_PTR(MP_ROM_INT(ADC_WIDTH_BIT_11)) },
    { MP_ROM_QSTR(MP_QSTR_BIT_12), MP_ROM_PTR(MP_ROM_INT(ADC_WIDTH_BIT_12)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_WIDTH_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_WIDTH_locals_dict, ADC_WIDTH_locals_dict_table);

STATIC void ADC_WIDTH_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_WIDTH");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_WIDTH_type_base,
    MP_QSTR_ADC_WIDTH,
    MP_TYPE_FLAG_NONE,
    print, ADC_WIDTH_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_WIDTH_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_WIDTH_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_WIDTH_type_base,
};
    

/*
 * espidf ADC_CONV object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_CONV_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SINGLE_UNIT_1), MP_ROM_PTR(MP_ROM_INT(ADC_CONV_SINGLE_UNIT_1)) },
    { MP_ROM_QSTR(MP_QSTR_SINGLE_UNIT_2), MP_ROM_PTR(MP_ROM_INT(ADC_CONV_SINGLE_UNIT_2)) },
    { MP_ROM_QSTR(MP_QSTR_BOTH_UNIT), MP_ROM_PTR(MP_ROM_INT(ADC_CONV_BOTH_UNIT)) },
    { MP_ROM_QSTR(MP_QSTR_ALTER_UNIT), MP_ROM_PTR(MP_ROM_INT(ADC_CONV_ALTER_UNIT)) },
    { MP_ROM_QSTR(MP_QSTR_UNIT_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_CONV_UNIT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_CONV_locals_dict, ADC_CONV_locals_dict_table);

STATIC void ADC_CONV_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_CONV");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_CONV_type_base,
    MP_QSTR_ADC_CONV,
    MP_TYPE_FLAG_NONE,
    print, ADC_CONV_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_CONV_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_CONV_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_CONV_type_base,
};
    

/*
 * espidf ADC_DIGI object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_DIGI_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_FORMAT_12BIT), MP_ROM_PTR(MP_ROM_INT(ADC_DIGI_FORMAT_12BIT)) },
    { MP_ROM_QSTR(MP_QSTR_FORMAT_11BIT), MP_ROM_PTR(MP_ROM_INT(ADC_DIGI_FORMAT_11BIT)) },
    { MP_ROM_QSTR(MP_QSTR_FORMAT_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_DIGI_FORMAT_MAX)) },
    { MP_ROM_QSTR(MP_QSTR_OUTPUT_FORMAT_TYPE1), MP_ROM_PTR(MP_ROM_INT(ADC_DIGI_OUTPUT_FORMAT_TYPE1)) },
    { MP_ROM_QSTR(MP_QSTR_OUTPUT_FORMAT_TYPE2), MP_ROM_PTR(MP_ROM_INT(ADC_DIGI_OUTPUT_FORMAT_TYPE2)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_DIGI_locals_dict, ADC_DIGI_locals_dict_table);

STATIC void ADC_DIGI_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_DIGI");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_DIGI_type_base,
    MP_QSTR_ADC_DIGI,
    MP_TYPE_FLAG_NONE,
    print, ADC_DIGI_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_DIGI_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_DIGI_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_DIGI_type_base,
};
    

/*
 * espidf ADC_I2S_DATA_SRC object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_I2S_DATA_SRC_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_IO_SIG), MP_ROM_PTR(MP_ROM_INT(ADC_I2S_DATA_SRC_IO_SIG)) },
    { MP_ROM_QSTR(MP_QSTR_ADC), MP_ROM_PTR(MP_ROM_INT(ADC_I2S_DATA_SRC_ADC)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_I2S_DATA_SRC_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_I2S_DATA_SRC_locals_dict, ADC_I2S_DATA_SRC_locals_dict_table);

STATIC void ADC_I2S_DATA_SRC_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_I2S_DATA_SRC");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_I2S_DATA_SRC_type_base,
    MP_QSTR_ADC_I2S_DATA_SRC,
    MP_TYPE_FLAG_NONE,
    print, ADC_I2S_DATA_SRC_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_I2S_DATA_SRC_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_I2S_DATA_SRC_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_I2S_DATA_SRC_type_base,
};
    

/*
 * espidf ADC1_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC1_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_2)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_3)) },
    { MP_ROM_QSTR(MP_QSTR__4), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_4)) },
    { MP_ROM_QSTR(MP_QSTR__5), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_5)) },
    { MP_ROM_QSTR(MP_QSTR__6), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_6)) },
    { MP_ROM_QSTR(MP_QSTR__7), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_7)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC1_CHANNEL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC1_CHANNEL_locals_dict, ADC1_CHANNEL_locals_dict_table);

STATIC void ADC1_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC1_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC1_CHANNEL_type_base,
    MP_QSTR_ADC1_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, ADC1_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC1_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC1_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC1_CHANNEL_type_base,
};
    

/*
 * espidf ADC2_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC2_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_2)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_3)) },
    { MP_ROM_QSTR(MP_QSTR__4), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_4)) },
    { MP_ROM_QSTR(MP_QSTR__5), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_5)) },
    { MP_ROM_QSTR(MP_QSTR__6), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_6)) },
    { MP_ROM_QSTR(MP_QSTR__7), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_7)) },
    { MP_ROM_QSTR(MP_QSTR__8), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_8)) },
    { MP_ROM_QSTR(MP_QSTR__9), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_9)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC2_CHANNEL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC2_CHANNEL_locals_dict, ADC2_CHANNEL_locals_dict_table);

STATIC void ADC2_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC2_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC2_CHANNEL_type_base,
    MP_QSTR_ADC2_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, ADC2_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC2_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC2_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC2_CHANNEL_type_base,
};
    

/*
 * espidf ADC_ENCODE object definitions
 */
    

STATIC const mp_rom_map_elem_t ADC_ENCODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__12BIT), MP_ROM_PTR(MP_ROM_INT(ADC_ENCODE_12BIT)) },
    { MP_ROM_QSTR(MP_QSTR__11BIT), MP_ROM_PTR(MP_ROM_INT(ADC_ENCODE_11BIT)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ADC_ENCODE_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ADC_ENCODE_locals_dict, ADC_ENCODE_locals_dict_table);

STATIC void ADC_ENCODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ADC_ENCODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ADC_ENCODE_type_base,
    MP_QSTR_ADC_ENCODE,
    MP_TYPE_FLAG_NONE,
    print, ADC_ENCODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ADC_ENCODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ADC_ENCODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ADC_ENCODE_type_base,
};
    

/*
 * espidf I2S_BITS_PER_SAMPLE object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_BITS_PER_SAMPLE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__8BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_SAMPLE_8BIT)) },
    { MP_ROM_QSTR(MP_QSTR__16BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_SAMPLE_16BIT)) },
    { MP_ROM_QSTR(MP_QSTR__24BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_SAMPLE_24BIT)) },
    { MP_ROM_QSTR(MP_QSTR__32BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_SAMPLE_32BIT)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_BITS_PER_SAMPLE_locals_dict, I2S_BITS_PER_SAMPLE_locals_dict_table);

STATIC void I2S_BITS_PER_SAMPLE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_BITS_PER_SAMPLE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_BITS_PER_SAMPLE_type_base,
    MP_QSTR_I2S_BITS_PER_SAMPLE,
    MP_TYPE_FLAG_NONE,
    print, I2S_BITS_PER_SAMPLE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_BITS_PER_SAMPLE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_BITS_PER_SAMPLE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_BITS_PER_SAMPLE_type_base,
};
    

/*
 * espidf I2S_BITS_PER_CHAN object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_BITS_PER_CHAN_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DEFAULT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_CHAN_DEFAULT)) },
    { MP_ROM_QSTR(MP_QSTR__8BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_CHAN_8BIT)) },
    { MP_ROM_QSTR(MP_QSTR__16BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_CHAN_16BIT)) },
    { MP_ROM_QSTR(MP_QSTR__24BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_CHAN_24BIT)) },
    { MP_ROM_QSTR(MP_QSTR__32BIT), MP_ROM_PTR(MP_ROM_INT(I2S_BITS_PER_CHAN_32BIT)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_BITS_PER_CHAN_locals_dict, I2S_BITS_PER_CHAN_locals_dict_table);

STATIC void I2S_BITS_PER_CHAN_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_BITS_PER_CHAN");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_BITS_PER_CHAN_type_base,
    MP_QSTR_I2S_BITS_PER_CHAN,
    MP_TYPE_FLAG_NONE,
    print, I2S_BITS_PER_CHAN_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_BITS_PER_CHAN_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_BITS_PER_CHAN_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_BITS_PER_CHAN_type_base,
};
    

/*
 * espidf I2S_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MONO), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_MONO)) },
    { MP_ROM_QSTR(MP_QSTR_STEREO), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_STEREO)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_CHANNEL_locals_dict, I2S_CHANNEL_locals_dict_table);

STATIC void I2S_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_CHANNEL_type_base,
    MP_QSTR_I2S_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, I2S_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_CHANNEL_type_base,
};
    

/*
 * espidf I2S_COMM_FORMAT object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_COMM_FORMAT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_STAND_I2S), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_STAND_I2S)) },
    { MP_ROM_QSTR(MP_QSTR_STAND_MSB), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_STAND_MSB)) },
    { MP_ROM_QSTR(MP_QSTR_STAND_PCM_SHORT), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_STAND_PCM_SHORT)) },
    { MP_ROM_QSTR(MP_QSTR_STAND_PCM_LONG), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_STAND_PCM_LONG)) },
    { MP_ROM_QSTR(MP_QSTR_STAND_MAX), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_STAND_MAX)) },
    { MP_ROM_QSTR(MP_QSTR_I2S), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_I2S)) },
    { MP_ROM_QSTR(MP_QSTR_I2S_MSB), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_I2S_MSB)) },
    { MP_ROM_QSTR(MP_QSTR_I2S_LSB), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_I2S_LSB)) },
    { MP_ROM_QSTR(MP_QSTR_PCM), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_PCM)) },
    { MP_ROM_QSTR(MP_QSTR_PCM_SHORT), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_PCM_SHORT)) },
    { MP_ROM_QSTR(MP_QSTR_PCM_LONG), MP_ROM_PTR(MP_ROM_INT(I2S_COMM_FORMAT_PCM_LONG)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_COMM_FORMAT_locals_dict, I2S_COMM_FORMAT_locals_dict_table);

STATIC void I2S_COMM_FORMAT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_COMM_FORMAT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_COMM_FORMAT_type_base,
    MP_QSTR_I2S_COMM_FORMAT,
    MP_TYPE_FLAG_NONE,
    print, I2S_COMM_FORMAT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_COMM_FORMAT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_COMM_FORMAT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_COMM_FORMAT_type_base,
};
    

/*
 * espidf I2S_CHANNEL_FMT object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_CHANNEL_FMT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_RIGHT_LEFT), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_FMT_RIGHT_LEFT)) },
    { MP_ROM_QSTR(MP_QSTR_ALL_RIGHT), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_FMT_ALL_RIGHT)) },
    { MP_ROM_QSTR(MP_QSTR_ALL_LEFT), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_FMT_ALL_LEFT)) },
    { MP_ROM_QSTR(MP_QSTR_ONLY_RIGHT), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_FMT_ONLY_RIGHT)) },
    { MP_ROM_QSTR(MP_QSTR_ONLY_LEFT), MP_ROM_PTR(MP_ROM_INT(I2S_CHANNEL_FMT_ONLY_LEFT)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_CHANNEL_FMT_locals_dict, I2S_CHANNEL_FMT_locals_dict_table);

STATIC void I2S_CHANNEL_FMT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_CHANNEL_FMT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_CHANNEL_FMT_type_base,
    MP_QSTR_I2S_CHANNEL_FMT,
    MP_TYPE_FLAG_NONE,
    print, I2S_CHANNEL_FMT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_CHANNEL_FMT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_CHANNEL_FMT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_CHANNEL_FMT_type_base,
};
    

/*
 * espidf I2S_MODE object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_MODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MASTER), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_MASTER)) },
    { MP_ROM_QSTR(MP_QSTR_SLAVE), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_SLAVE)) },
    { MP_ROM_QSTR(MP_QSTR_TX), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_TX)) },
    { MP_ROM_QSTR(MP_QSTR_RX), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_RX)) },
    { MP_ROM_QSTR(MP_QSTR_DAC_BUILT_IN), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_DAC_BUILT_IN)) },
    { MP_ROM_QSTR(MP_QSTR_ADC_BUILT_IN), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_ADC_BUILT_IN)) },
    { MP_ROM_QSTR(MP_QSTR_PDM), MP_ROM_PTR(MP_ROM_INT(I2S_MODE_PDM)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_MODE_locals_dict, I2S_MODE_locals_dict_table);

STATIC void I2S_MODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_MODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_MODE_type_base,
    MP_QSTR_I2S_MODE,
    MP_TYPE_FLAG_NONE,
    print, I2S_MODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_MODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_MODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_MODE_type_base,
};
    

/*
 * espidf I2S_CLK object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_CLK_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_D2CLK), MP_ROM_PTR(MP_ROM_INT(I2S_CLK_D2CLK)) },
    { MP_ROM_QSTR(MP_QSTR_APLL), MP_ROM_PTR(MP_ROM_INT(I2S_CLK_APLL)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_CLK_locals_dict, I2S_CLK_locals_dict_table);

STATIC void I2S_CLK_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_CLK");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_CLK_type_base,
    MP_QSTR_I2S_CLK,
    MP_TYPE_FLAG_NONE,
    print, I2S_CLK_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_CLK_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_CLK_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_CLK_type_base,
};
    

/*
 * espidf I2S_MCLK_MULTIPLE object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_MCLK_MULTIPLE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DEFAULT), MP_ROM_PTR(MP_ROM_INT(I2S_MCLK_MULTIPLE_DEFAULT)) },
    { MP_ROM_QSTR(MP_QSTR__128), MP_ROM_PTR(MP_ROM_INT(I2S_MCLK_MULTIPLE_128)) },
    { MP_ROM_QSTR(MP_QSTR__256), MP_ROM_PTR(MP_ROM_INT(I2S_MCLK_MULTIPLE_256)) },
    { MP_ROM_QSTR(MP_QSTR__384), MP_ROM_PTR(MP_ROM_INT(I2S_MCLK_MULTIPLE_384)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_MCLK_MULTIPLE_locals_dict, I2S_MCLK_MULTIPLE_locals_dict_table);

STATIC void I2S_MCLK_MULTIPLE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_MCLK_MULTIPLE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_MCLK_MULTIPLE_type_base,
    MP_QSTR_I2S_MCLK_MULTIPLE,
    MP_TYPE_FLAG_NONE,
    print, I2S_MCLK_MULTIPLE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_MCLK_MULTIPLE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_MCLK_MULTIPLE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_MCLK_MULTIPLE_type_base,
};
    

/*
 * espidf I2S_DAC_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_DAC_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DISABLE), MP_ROM_PTR(MP_ROM_INT(I2S_DAC_CHANNEL_DISABLE)) },
    { MP_ROM_QSTR(MP_QSTR_RIGHT_EN), MP_ROM_PTR(MP_ROM_INT(I2S_DAC_CHANNEL_RIGHT_EN)) },
    { MP_ROM_QSTR(MP_QSTR_LEFT_EN), MP_ROM_PTR(MP_ROM_INT(I2S_DAC_CHANNEL_LEFT_EN)) },
    { MP_ROM_QSTR(MP_QSTR_BOTH_EN), MP_ROM_PTR(MP_ROM_INT(I2S_DAC_CHANNEL_BOTH_EN)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(I2S_DAC_CHANNEL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_DAC_CHANNEL_locals_dict, I2S_DAC_CHANNEL_locals_dict_table);

STATIC void I2S_DAC_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_DAC_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_DAC_CHANNEL_type_base,
    MP_QSTR_I2S_DAC_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, I2S_DAC_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_DAC_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_DAC_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_DAC_CHANNEL_type_base,
};
    

/*
 * espidf I2S_PDM_DSR object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_PDM_DSR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__8S), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_DSR_8S)) },
    { MP_ROM_QSTR(MP_QSTR__16S), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_DSR_16S)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_DSR_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_PDM_DSR_locals_dict, I2S_PDM_DSR_locals_dict_table);

STATIC void I2S_PDM_DSR_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_PDM_DSR");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_PDM_DSR_type_base,
    MP_QSTR_I2S_PDM_DSR,
    MP_TYPE_FLAG_NONE,
    print, I2S_PDM_DSR_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_PDM_DSR_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_PDM_DSR_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_PDM_DSR_type_base,
};
    

/*
 * espidf I2S_PDM_SIG_SCALING object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_PDM_SIG_SCALING_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DIV_2), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_SIG_SCALING_DIV_2)) },
    { MP_ROM_QSTR(MP_QSTR_MUL_1), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_SIG_SCALING_MUL_1)) },
    { MP_ROM_QSTR(MP_QSTR_MUL_2), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_SIG_SCALING_MUL_2)) },
    { MP_ROM_QSTR(MP_QSTR_MUL_4), MP_ROM_PTR(MP_ROM_INT(I2S_PDM_SIG_SCALING_MUL_4)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_PDM_SIG_SCALING_locals_dict, I2S_PDM_SIG_SCALING_locals_dict_table);

STATIC void I2S_PDM_SIG_SCALING_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_PDM_SIG_SCALING");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_PDM_SIG_SCALING_type_base,
    MP_QSTR_I2S_PDM_SIG_SCALING,
    MP_TYPE_FLAG_NONE,
    print, I2S_PDM_SIG_SCALING_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_PDM_SIG_SCALING_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_PDM_SIG_SCALING_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_PDM_SIG_SCALING_type_base,
};
    

/*
 * espidf I2S_NUM object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_NUM_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(I2S_NUM_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(I2S_NUM_1)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(I2S_NUM_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_NUM_locals_dict, I2S_NUM_locals_dict_table);

STATIC void I2S_NUM_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_NUM");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_NUM_type_base,
    MP_QSTR_I2S_NUM,
    MP_TYPE_FLAG_NONE,
    print, I2S_NUM_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_NUM_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_NUM_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_NUM_type_base,
};
    

/*
 * espidf I2S_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t I2S_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DMA_ERROR), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_DMA_ERROR)) },
    { MP_ROM_QSTR(MP_QSTR_TX_DONE), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_TX_DONE)) },
    { MP_ROM_QSTR(MP_QSTR_RX_DONE), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_RX_DONE)) },
    { MP_ROM_QSTR(MP_QSTR_TX_Q_OVF), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_TX_Q_OVF)) },
    { MP_ROM_QSTR(MP_QSTR_RX_Q_OVF), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_RX_Q_OVF)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(I2S_EVENT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(I2S_EVENT_locals_dict, I2S_EVENT_locals_dict_table);

STATIC void I2S_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf I2S_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_I2S_EVENT_type_base,
    MP_QSTR_I2S_EVENT,
    MP_TYPE_FLAG_NONE,
    print, I2S_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &I2S_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_I2S_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_I2S_EVENT_type_base,
};
    

/*
 * espidf PCNT_CHANNEL_LEVEL_ACTION object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_CHANNEL_LEVEL_ACTION_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_KEEP), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_LEVEL_ACTION_KEEP)) },
    { MP_ROM_QSTR(MP_QSTR_INVERSE), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_LEVEL_ACTION_INVERSE)) },
    { MP_ROM_QSTR(MP_QSTR_HOLD), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_LEVEL_ACTION_HOLD)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_CHANNEL_LEVEL_ACTION_locals_dict, PCNT_CHANNEL_LEVEL_ACTION_locals_dict_table);

STATIC void PCNT_CHANNEL_LEVEL_ACTION_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_CHANNEL_LEVEL_ACTION");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_CHANNEL_LEVEL_ACTION_type_base,
    MP_QSTR_PCNT_CHANNEL_LEVEL_ACTION,
    MP_TYPE_FLAG_NONE,
    print, PCNT_CHANNEL_LEVEL_ACTION_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_CHANNEL_LEVEL_ACTION_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_CHANNEL_LEVEL_ACTION_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_CHANNEL_LEVEL_ACTION_type_base,
};
    

/*
 * espidf PCNT_CHANNEL_EDGE_ACTION object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_CHANNEL_EDGE_ACTION_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_HOLD), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_EDGE_ACTION_HOLD)) },
    { MP_ROM_QSTR(MP_QSTR_INCREASE), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_EDGE_ACTION_INCREASE)) },
    { MP_ROM_QSTR(MP_QSTR_DECREASE), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_EDGE_ACTION_DECREASE)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_CHANNEL_EDGE_ACTION_locals_dict, PCNT_CHANNEL_EDGE_ACTION_locals_dict_table);

STATIC void PCNT_CHANNEL_EDGE_ACTION_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_CHANNEL_EDGE_ACTION");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_CHANNEL_EDGE_ACTION_type_base,
    MP_QSTR_PCNT_CHANNEL_EDGE_ACTION,
    MP_TYPE_FLAG_NONE,
    print, PCNT_CHANNEL_EDGE_ACTION_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_CHANNEL_EDGE_ACTION_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_CHANNEL_EDGE_ACTION_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_CHANNEL_EDGE_ACTION_type_base,
};
    

/*
 * espidf PCNT_UNIT_COUNT_SIGN object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_UNIT_COUNT_SIGN_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ZERO_POS), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_COUNT_SIGN_ZERO_POS)) },
    { MP_ROM_QSTR(MP_QSTR_ZERO_NEG), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_COUNT_SIGN_ZERO_NEG)) },
    { MP_ROM_QSTR(MP_QSTR_NEG), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_COUNT_SIGN_NEG)) },
    { MP_ROM_QSTR(MP_QSTR_POS), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_COUNT_SIGN_POS)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_UNIT_COUNT_SIGN_locals_dict, PCNT_UNIT_COUNT_SIGN_locals_dict_table);

STATIC void PCNT_UNIT_COUNT_SIGN_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_UNIT_COUNT_SIGN");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_UNIT_COUNT_SIGN_type_base,
    MP_QSTR_PCNT_UNIT_COUNT_SIGN,
    MP_TYPE_FLAG_NONE,
    print, PCNT_UNIT_COUNT_SIGN_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_UNIT_COUNT_SIGN_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_UNIT_COUNT_SIGN_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_UNIT_COUNT_SIGN_type_base,
};
    

/*
 * espidf PCNT_PORT object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_PORT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(PCNT_PORT_0)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(PCNT_PORT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_PORT_locals_dict, PCNT_PORT_locals_dict_table);

STATIC void PCNT_PORT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_PORT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_PORT_type_base,
    MP_QSTR_PCNT_PORT,
    MP_TYPE_FLAG_NONE,
    print, PCNT_PORT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_PORT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_PORT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_PORT_type_base,
};
    

/*
 * espidf PCNT_UNIT object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_UNIT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_1)) },
    { MP_ROM_QSTR(MP_QSTR__2), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_2)) },
    { MP_ROM_QSTR(MP_QSTR__3), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_3)) },
    { MP_ROM_QSTR(MP_QSTR__4), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_4)) },
    { MP_ROM_QSTR(MP_QSTR__5), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_5)) },
    { MP_ROM_QSTR(MP_QSTR__6), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_6)) },
    { MP_ROM_QSTR(MP_QSTR__7), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_7)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(PCNT_UNIT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_UNIT_locals_dict, PCNT_UNIT_locals_dict_table);

STATIC void PCNT_UNIT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_UNIT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_UNIT_type_base,
    MP_QSTR_PCNT_UNIT,
    MP_TYPE_FLAG_NONE,
    print, PCNT_UNIT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_UNIT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_UNIT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_UNIT_type_base,
};
    

/*
 * espidf PCNT_CHANNEL object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_CHANNEL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_1)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(PCNT_CHANNEL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_CHANNEL_locals_dict, PCNT_CHANNEL_locals_dict_table);

STATIC void PCNT_CHANNEL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_CHANNEL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_CHANNEL_type_base,
    MP_QSTR_PCNT_CHANNEL,
    MP_TYPE_FLAG_NONE,
    print, PCNT_CHANNEL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_CHANNEL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_CHANNEL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_CHANNEL_type_base,
};
    

/*
 * espidf PCNT_EVT object definitions
 */
    

STATIC const mp_rom_map_elem_t PCNT_EVT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_THRES_1), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_THRES_1)) },
    { MP_ROM_QSTR(MP_QSTR_THRES_0), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_THRES_0)) },
    { MP_ROM_QSTR(MP_QSTR_L_LIM), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_L_LIM)) },
    { MP_ROM_QSTR(MP_QSTR_H_LIM), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_H_LIM)) },
    { MP_ROM_QSTR(MP_QSTR_ZERO), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_ZERO)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(PCNT_EVT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(PCNT_EVT_locals_dict, PCNT_EVT_locals_dict_table);

STATIC void PCNT_EVT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf PCNT_EVT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_PCNT_EVT_type_base,
    MP_QSTR_PCNT_EVT,
    MP_TYPE_FLAG_NONE,
    print, PCNT_EVT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &PCNT_EVT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_PCNT_EVT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_PCNT_EVT_type_base,
};
    

/*
 * espidf ESP_IF object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_IF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_WIFI_STA), MP_ROM_PTR(MP_ROM_INT(ESP_IF_WIFI_STA)) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_AP), MP_ROM_PTR(MP_ROM_INT(ESP_IF_WIFI_AP)) },
    { MP_ROM_QSTR(MP_QSTR_ETH), MP_ROM_PTR(MP_ROM_INT(ESP_IF_ETH)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ESP_IF_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_IF_locals_dict, ESP_IF_locals_dict_table);

STATIC void ESP_IF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_IF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_IF_type_base,
    MP_QSTR_ESP_IF,
    MP_TYPE_FLAG_NONE,
    print, ESP_IF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_IF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_IF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_IF_type_base,
};
    

/*
 * espidf WIFI_MODE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_MODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NULL), MP_ROM_PTR(MP_ROM_INT(WIFI_MODE_NULL)) },
    { MP_ROM_QSTR(MP_QSTR_STA), MP_ROM_PTR(MP_ROM_INT(WIFI_MODE_STA)) },
    { MP_ROM_QSTR(MP_QSTR_AP), MP_ROM_PTR(MP_ROM_INT(WIFI_MODE_AP)) },
    { MP_ROM_QSTR(MP_QSTR_APSTA), MP_ROM_PTR(MP_ROM_INT(WIFI_MODE_APSTA)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_MODE_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_MODE_locals_dict, WIFI_MODE_locals_dict_table);

STATIC void WIFI_MODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_MODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_MODE_type_base,
    MP_QSTR_WIFI_MODE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_MODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_MODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_MODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_MODE_type_base,
};
    

/*
 * espidf WIFI_IF object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_IF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_STA), MP_ROM_PTR(MP_ROM_INT(WIFI_IF_STA)) },
    { MP_ROM_QSTR(MP_QSTR_AP), MP_ROM_PTR(MP_ROM_INT(WIFI_IF_AP)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_IF_locals_dict, WIFI_IF_locals_dict_table);

STATIC void WIFI_IF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_IF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_IF_type_base,
    MP_QSTR_WIFI_IF,
    MP_TYPE_FLAG_NONE,
    print, WIFI_IF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_IF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_IF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_IF_type_base,
};
    

/*
 * espidf WIFI_COUNTRY_POLICY object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_COUNTRY_POLICY_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_AUTO), MP_ROM_PTR(MP_ROM_INT(WIFI_COUNTRY_POLICY_AUTO)) },
    { MP_ROM_QSTR(MP_QSTR_MANUAL), MP_ROM_PTR(MP_ROM_INT(WIFI_COUNTRY_POLICY_MANUAL)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_COUNTRY_POLICY_locals_dict, WIFI_COUNTRY_POLICY_locals_dict_table);

STATIC void WIFI_COUNTRY_POLICY_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_COUNTRY_POLICY");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_COUNTRY_POLICY_type_base,
    MP_QSTR_WIFI_COUNTRY_POLICY,
    MP_TYPE_FLAG_NONE,
    print, WIFI_COUNTRY_POLICY_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_COUNTRY_POLICY_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_COUNTRY_POLICY_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_COUNTRY_POLICY_type_base,
};
    

/*
 * espidf WIFI_AUTH object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_AUTH_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_OPEN), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_OPEN)) },
    { MP_ROM_QSTR(MP_QSTR_WEP), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WEP)) },
    { MP_ROM_QSTR(MP_QSTR_WPA_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_WPA2_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA2_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_WPA_WPA2_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA_WPA2_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_WPA2_ENTERPRISE), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA2_ENTERPRISE)) },
    { MP_ROM_QSTR(MP_QSTR_WPA3_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA3_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_WPA2_WPA3_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WPA2_WPA3_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_WAPI_PSK), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_WAPI_PSK)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_AUTH_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_AUTH_locals_dict, WIFI_AUTH_locals_dict_table);

STATIC void WIFI_AUTH_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_AUTH");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_AUTH_type_base,
    MP_QSTR_WIFI_AUTH,
    MP_TYPE_FLAG_NONE,
    print, WIFI_AUTH_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_AUTH_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_AUTH_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_AUTH_type_base,
};
    

/*
 * espidf WIFI_REASON object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_REASON_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNSPECIFIED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_UNSPECIFIED)) },
    { MP_ROM_QSTR(MP_QSTR_AUTH_EXPIRE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AUTH_EXPIRE)) },
    { MP_ROM_QSTR(MP_QSTR_AUTH_LEAVE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AUTH_LEAVE)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_EXPIRE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_EXPIRE)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_TOOMANY), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_TOOMANY)) },
    { MP_ROM_QSTR(MP_QSTR_NOT_AUTHED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NOT_AUTHED)) },
    { MP_ROM_QSTR(MP_QSTR_NOT_ASSOCED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NOT_ASSOCED)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_LEAVE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_LEAVE)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_NOT_AUTHED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_NOT_AUTHED)) },
    { MP_ROM_QSTR(MP_QSTR_DISASSOC_PWRCAP_BAD), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_DISASSOC_PWRCAP_BAD)) },
    { MP_ROM_QSTR(MP_QSTR_DISASSOC_SUPCHAN_BAD), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_DISASSOC_SUPCHAN_BAD)) },
    { MP_ROM_QSTR(MP_QSTR_BSS_TRANSITION_DISASSOC), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_BSS_TRANSITION_DISASSOC)) },
    { MP_ROM_QSTR(MP_QSTR_IE_INVALID), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_IE_INVALID)) },
    { MP_ROM_QSTR(MP_QSTR_MIC_FAILURE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_MIC_FAILURE)) },
    { MP_ROM_QSTR(MP_QSTR__4WAY_HANDSHAKE_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_4WAY_HANDSHAKE_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_GROUP_KEY_UPDATE_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_GROUP_KEY_UPDATE_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_IE_IN_4WAY_DIFFERS), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_IE_IN_4WAY_DIFFERS)) },
    { MP_ROM_QSTR(MP_QSTR_GROUP_CIPHER_INVALID), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_GROUP_CIPHER_INVALID)) },
    { MP_ROM_QSTR(MP_QSTR_PAIRWISE_CIPHER_INVALID), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_PAIRWISE_CIPHER_INVALID)) },
    { MP_ROM_QSTR(MP_QSTR_AKMP_INVALID), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AKMP_INVALID)) },
    { MP_ROM_QSTR(MP_QSTR_UNSUPP_RSN_IE_VERSION), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_UNSUPP_RSN_IE_VERSION)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_RSN_IE_CAP), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_INVALID_RSN_IE_CAP)) },
    { MP_ROM_QSTR(MP_QSTR__802_1X_AUTH_FAILED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_802_1X_AUTH_FAILED)) },
    { MP_ROM_QSTR(MP_QSTR_CIPHER_SUITE_REJECTED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_CIPHER_SUITE_REJECTED)) },
    { MP_ROM_QSTR(MP_QSTR_TDLS_PEER_UNREACHABLE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_TDLS_PEER_UNREACHABLE)) },
    { MP_ROM_QSTR(MP_QSTR_TDLS_UNSPECIFIED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_TDLS_UNSPECIFIED)) },
    { MP_ROM_QSTR(MP_QSTR_SSP_REQUESTED_DISASSOC), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_SSP_REQUESTED_DISASSOC)) },
    { MP_ROM_QSTR(MP_QSTR_NO_SSP_ROAMING_AGREEMENT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NO_SSP_ROAMING_AGREEMENT)) },
    { MP_ROM_QSTR(MP_QSTR_BAD_CIPHER_OR_AKM), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_BAD_CIPHER_OR_AKM)) },
    { MP_ROM_QSTR(MP_QSTR_NOT_AUTHORIZED_THIS_LOCATION), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NOT_AUTHORIZED_THIS_LOCATION)) },
    { MP_ROM_QSTR(MP_QSTR_SERVICE_CHANGE_PERCLUDES_TS), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_SERVICE_CHANGE_PERCLUDES_TS)) },
    { MP_ROM_QSTR(MP_QSTR_UNSPECIFIED_QOS), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_UNSPECIFIED_QOS)) },
    { MP_ROM_QSTR(MP_QSTR_NOT_ENOUGH_BANDWIDTH), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NOT_ENOUGH_BANDWIDTH)) },
    { MP_ROM_QSTR(MP_QSTR_MISSING_ACKS), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_MISSING_ACKS)) },
    { MP_ROM_QSTR(MP_QSTR_EXCEEDED_TXOP), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_EXCEEDED_TXOP)) },
    { MP_ROM_QSTR(MP_QSTR_STA_LEAVING), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_STA_LEAVING)) },
    { MP_ROM_QSTR(MP_QSTR_END_BA), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_END_BA)) },
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN_BA), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_UNKNOWN_BA)) },
    { MP_ROM_QSTR(MP_QSTR_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_PEER_INITIATED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_PEER_INITIATED)) },
    { MP_ROM_QSTR(MP_QSTR_AP_INITIATED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AP_INITIATED)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_FT_ACTION_FRAME_COUNT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_INVALID_FT_ACTION_FRAME_COUNT)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_PMKID), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_INVALID_PMKID)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_MDE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_INVALID_MDE)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_FTE), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_INVALID_FTE)) },
    { MP_ROM_QSTR(MP_QSTR_TRANSMISSION_LINK_ESTABLISH_FAILED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_TRANSMISSION_LINK_ESTABLISH_FAILED)) },
    { MP_ROM_QSTR(MP_QSTR_ALTERATIVE_CHANNEL_OCCUPIED), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ALTERATIVE_CHANNEL_OCCUPIED)) },
    { MP_ROM_QSTR(MP_QSTR_BEACON_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_BEACON_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_NO_AP_FOUND), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_NO_AP_FOUND)) },
    { MP_ROM_QSTR(MP_QSTR_AUTH_FAIL), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AUTH_FAIL)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_FAIL), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_FAIL)) },
    { MP_ROM_QSTR(MP_QSTR_HANDSHAKE_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_HANDSHAKE_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECTION_FAIL), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_CONNECTION_FAIL)) },
    { MP_ROM_QSTR(MP_QSTR_AP_TSF_RESET), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_AP_TSF_RESET)) },
    { MP_ROM_QSTR(MP_QSTR_ROAMING), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ROAMING)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_COMEBACK_TIME_TOO_LONG), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_ASSOC_COMEBACK_TIME_TOO_LONG)) },
    { MP_ROM_QSTR(MP_QSTR_SA_QUERY_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_REASON_SA_QUERY_TIMEOUT)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_REASON_locals_dict, WIFI_REASON_locals_dict_table);

STATIC void WIFI_REASON_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_REASON");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_REASON_type_base,
    MP_QSTR_WIFI_REASON,
    MP_TYPE_FLAG_NONE,
    print, WIFI_REASON_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_REASON_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_REASON_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_REASON_type_base,
};
    

/*
 * espidf WIFI_SECOND_CHAN object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_SECOND_CHAN_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(WIFI_SECOND_CHAN_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_ABOVE), MP_ROM_PTR(MP_ROM_INT(WIFI_SECOND_CHAN_ABOVE)) },
    { MP_ROM_QSTR(MP_QSTR_BELOW), MP_ROM_PTR(MP_ROM_INT(WIFI_SECOND_CHAN_BELOW)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_SECOND_CHAN_locals_dict, WIFI_SECOND_CHAN_locals_dict_table);

STATIC void WIFI_SECOND_CHAN_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_SECOND_CHAN");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_SECOND_CHAN_type_base,
    MP_QSTR_WIFI_SECOND_CHAN,
    MP_TYPE_FLAG_NONE,
    print, WIFI_SECOND_CHAN_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_SECOND_CHAN_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_SECOND_CHAN_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_SECOND_CHAN_type_base,
};
    

/*
 * espidf WIFI_SCAN_TYPE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_SCAN_TYPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ACTIVE), MP_ROM_PTR(MP_ROM_INT(WIFI_SCAN_TYPE_ACTIVE)) },
    { MP_ROM_QSTR(MP_QSTR_PASSIVE), MP_ROM_PTR(MP_ROM_INT(WIFI_SCAN_TYPE_PASSIVE)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_SCAN_TYPE_locals_dict, WIFI_SCAN_TYPE_locals_dict_table);

STATIC void WIFI_SCAN_TYPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_SCAN_TYPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_SCAN_TYPE_type_base,
    MP_QSTR_WIFI_SCAN_TYPE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_SCAN_TYPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_SCAN_TYPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_SCAN_TYPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_SCAN_TYPE_type_base,
};
    

/*
 * espidf WIFI_CIPHER_TYPE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_CIPHER_TYPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_WEP40), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_WEP40)) },
    { MP_ROM_QSTR(MP_QSTR_WEP104), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_WEP104)) },
    { MP_ROM_QSTR(MP_QSTR_TKIP), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_TKIP)) },
    { MP_ROM_QSTR(MP_QSTR_CCMP), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_CCMP)) },
    { MP_ROM_QSTR(MP_QSTR_TKIP_CCMP), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_TKIP_CCMP)) },
    { MP_ROM_QSTR(MP_QSTR_AES_CMAC128), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_AES_CMAC128)) },
    { MP_ROM_QSTR(MP_QSTR_SMS4), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_SMS4)) },
    { MP_ROM_QSTR(MP_QSTR_GCMP), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_GCMP)) },
    { MP_ROM_QSTR(MP_QSTR_GCMP256), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_GCMP256)) },
    { MP_ROM_QSTR(MP_QSTR_AES_GMAC128), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_AES_GMAC128)) },
    { MP_ROM_QSTR(MP_QSTR_AES_GMAC256), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_AES_GMAC256)) },
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(WIFI_CIPHER_TYPE_UNKNOWN)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_CIPHER_TYPE_locals_dict, WIFI_CIPHER_TYPE_locals_dict_table);

STATIC void WIFI_CIPHER_TYPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_CIPHER_TYPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_CIPHER_TYPE_type_base,
    MP_QSTR_WIFI_CIPHER_TYPE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_CIPHER_TYPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_CIPHER_TYPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_CIPHER_TYPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_CIPHER_TYPE_type_base,
};
    

/*
 * espidf WIFI_ANT object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_ANT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ANT0), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_ANT0)) },
    { MP_ROM_QSTR(MP_QSTR_ANT1), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_ANT1)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_ANT_locals_dict, WIFI_ANT_locals_dict_table);

STATIC void WIFI_ANT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_ANT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_ANT_type_base,
    MP_QSTR_WIFI_ANT,
    MP_TYPE_FLAG_NONE,
    print, WIFI_ANT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_ANT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_ANT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_ANT_type_base,
};
    

/*
 * espidf WIFI object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_FAST_SCAN), MP_ROM_PTR(MP_ROM_INT(WIFI_FAST_SCAN)) },
    { MP_ROM_QSTR(MP_QSTR_ALL_CHANNEL_SCAN), MP_ROM_PTR(MP_ROM_INT(WIFI_ALL_CHANNEL_SCAN)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_locals_dict, WIFI_locals_dict_table);

STATIC void WIFI_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_type_base,
    MP_QSTR_WIFI,
    MP_TYPE_FLAG_NONE,
    print, WIFI_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_type_base,
};
    

/*
 * espidf WIFI_CONNECT_AP_BY object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_CONNECT_AP_BY_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SIGNAL), MP_ROM_PTR(MP_ROM_INT(WIFI_CONNECT_AP_BY_SIGNAL)) },
    { MP_ROM_QSTR(MP_QSTR_SECURITY), MP_ROM_PTR(MP_ROM_INT(WIFI_CONNECT_AP_BY_SECURITY)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_CONNECT_AP_BY_locals_dict, WIFI_CONNECT_AP_BY_locals_dict_table);

STATIC void WIFI_CONNECT_AP_BY_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_CONNECT_AP_BY");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_CONNECT_AP_BY_type_base,
    MP_QSTR_WIFI_CONNECT_AP_BY,
    MP_TYPE_FLAG_NONE,
    print, WIFI_CONNECT_AP_BY_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_CONNECT_AP_BY_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_CONNECT_AP_BY_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_CONNECT_AP_BY_type_base,
};
    

/*
 * espidf WIFI_PS object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_PS_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(WIFI_PS_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_MIN_MODEM), MP_ROM_PTR(MP_ROM_INT(WIFI_PS_MIN_MODEM)) },
    { MP_ROM_QSTR(MP_QSTR_MAX_MODEM), MP_ROM_PTR(MP_ROM_INT(WIFI_PS_MAX_MODEM)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_PS_locals_dict, WIFI_PS_locals_dict_table);

STATIC void WIFI_PS_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_PS");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_PS_type_base,
    MP_QSTR_WIFI_PS,
    MP_TYPE_FLAG_NONE,
    print, WIFI_PS_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_PS_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_PS_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_PS_type_base,
};
    

/*
 * espidf WIFI_BW object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_BW_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_HT20), MP_ROM_PTR(MP_ROM_INT(WIFI_BW_HT20)) },
    { MP_ROM_QSTR(MP_QSTR_HT40), MP_ROM_PTR(MP_ROM_INT(WIFI_BW_HT40)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_BW_locals_dict, WIFI_BW_locals_dict_table);

STATIC void WIFI_BW_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_BW");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_BW_type_base,
    MP_QSTR_WIFI_BW,
    MP_TYPE_FLAG_NONE,
    print, WIFI_BW_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_BW_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_BW_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_BW_type_base,
};
    

/*
 * espidf WPA3_SAE_PWE object definitions
 */
    

STATIC const mp_rom_map_elem_t WPA3_SAE_PWE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNSPECIFIED), MP_ROM_PTR(MP_ROM_INT(WPA3_SAE_PWE_UNSPECIFIED)) },
    { MP_ROM_QSTR(MP_QSTR_HUNT_AND_PECK), MP_ROM_PTR(MP_ROM_INT(WPA3_SAE_PWE_HUNT_AND_PECK)) },
    { MP_ROM_QSTR(MP_QSTR_HASH_TO_ELEMENT), MP_ROM_PTR(MP_ROM_INT(WPA3_SAE_PWE_HASH_TO_ELEMENT)) },
    { MP_ROM_QSTR(MP_QSTR_BOTH), MP_ROM_PTR(MP_ROM_INT(WPA3_SAE_PWE_BOTH)) }
};

STATIC MP_DEFINE_CONST_DICT(WPA3_SAE_PWE_locals_dict, WPA3_SAE_PWE_locals_dict_table);

STATIC void WPA3_SAE_PWE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WPA3_SAE_PWE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WPA3_SAE_PWE_type_base,
    MP_QSTR_WPA3_SAE_PWE,
    MP_TYPE_FLAG_NONE,
    print, WPA3_SAE_PWE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WPA3_SAE_PWE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WPA3_SAE_PWE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WPA3_SAE_PWE_type_base,
};
    

/*
 * espidf WIFI_STORAGE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_STORAGE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_FLASH), MP_ROM_PTR(MP_ROM_INT(WIFI_STORAGE_FLASH)) },
    { MP_ROM_QSTR(MP_QSTR_RAM), MP_ROM_PTR(MP_ROM_INT(WIFI_STORAGE_RAM)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_STORAGE_locals_dict, WIFI_STORAGE_locals_dict_table);

STATIC void WIFI_STORAGE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_STORAGE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_STORAGE_type_base,
    MP_QSTR_WIFI_STORAGE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_STORAGE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_STORAGE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_STORAGE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_STORAGE_type_base,
};
    

/*
 * espidf WIFI_VND_IE_TYPE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_VND_IE_TYPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_BEACON), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_TYPE_BEACON)) },
    { MP_ROM_QSTR(MP_QSTR_PROBE_REQ), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_TYPE_PROBE_REQ)) },
    { MP_ROM_QSTR(MP_QSTR_PROBE_RESP), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_TYPE_PROBE_RESP)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_REQ), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_TYPE_ASSOC_REQ)) },
    { MP_ROM_QSTR(MP_QSTR_ASSOC_RESP), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_TYPE_ASSOC_RESP)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_VND_IE_TYPE_locals_dict, WIFI_VND_IE_TYPE_locals_dict_table);

STATIC void WIFI_VND_IE_TYPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_VND_IE_TYPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_VND_IE_TYPE_type_base,
    MP_QSTR_WIFI_VND_IE_TYPE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_VND_IE_TYPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_VND_IE_TYPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_VND_IE_TYPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_VND_IE_TYPE_type_base,
};
    

/*
 * espidf WIFI_VND_IE_ID object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_VND_IE_ID_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__0), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_ID_0)) },
    { MP_ROM_QSTR(MP_QSTR__1), MP_ROM_PTR(MP_ROM_INT(WIFI_VND_IE_ID_1)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_VND_IE_ID_locals_dict, WIFI_VND_IE_ID_locals_dict_table);

STATIC void WIFI_VND_IE_ID_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_VND_IE_ID");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_VND_IE_ID_type_base,
    MP_QSTR_WIFI_VND_IE_ID,
    MP_TYPE_FLAG_NONE,
    print, WIFI_VND_IE_ID_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_VND_IE_ID_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_VND_IE_ID_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_VND_IE_ID_type_base,
};
    

/*
 * espidf WIFI_PHY_MODE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_PHY_MODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_LR), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_LR)) },
    { MP_ROM_QSTR(MP_QSTR__11B), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_11B)) },
    { MP_ROM_QSTR(MP_QSTR__11G), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_11G)) },
    { MP_ROM_QSTR(MP_QSTR_HT20), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_HT20)) },
    { MP_ROM_QSTR(MP_QSTR_HT40), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_HT40)) },
    { MP_ROM_QSTR(MP_QSTR_HE20), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_MODE_HE20)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_PHY_MODE_locals_dict, WIFI_PHY_MODE_locals_dict_table);

STATIC void WIFI_PHY_MODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_PHY_MODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_PHY_MODE_type_base,
    MP_QSTR_WIFI_PHY_MODE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_PHY_MODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_PHY_MODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_PHY_MODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_PHY_MODE_type_base,
};
    

/*
 * espidf WIFI_PKT object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_PKT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MGMT), MP_ROM_PTR(MP_ROM_INT(WIFI_PKT_MGMT)) },
    { MP_ROM_QSTR(MP_QSTR_CTRL), MP_ROM_PTR(MP_ROM_INT(WIFI_PKT_CTRL)) },
    { MP_ROM_QSTR(MP_QSTR_DATA), MP_ROM_PTR(MP_ROM_INT(WIFI_PKT_DATA)) },
    { MP_ROM_QSTR(MP_QSTR_MISC), MP_ROM_PTR(MP_ROM_INT(WIFI_PKT_MISC)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_PKT_locals_dict, WIFI_PKT_locals_dict_table);

STATIC void WIFI_PKT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_PKT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_PKT_type_base,
    MP_QSTR_WIFI_PKT,
    MP_TYPE_FLAG_NONE,
    print, WIFI_PKT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_PKT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_PKT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_PKT_type_base,
};
    

/*
 * espidf WIFI_ANT_MODE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_ANT_MODE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ANT0), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_MODE_ANT0)) },
    { MP_ROM_QSTR(MP_QSTR_ANT1), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_MODE_ANT1)) },
    { MP_ROM_QSTR(MP_QSTR_AUTO), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_MODE_AUTO)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_ANT_MODE_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_ANT_MODE_locals_dict, WIFI_ANT_MODE_locals_dict_table);

STATIC void WIFI_ANT_MODE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_ANT_MODE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_ANT_MODE_type_base,
    MP_QSTR_WIFI_ANT_MODE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_ANT_MODE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_ANT_MODE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_ANT_MODE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_ANT_MODE_type_base,
};
    

/*
 * espidf WIFI_PHY_RATE object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_PHY_RATE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__1M_L), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_1M_L)) },
    { MP_ROM_QSTR(MP_QSTR__2M_L), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_2M_L)) },
    { MP_ROM_QSTR(MP_QSTR__5M_L), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_5M_L)) },
    { MP_ROM_QSTR(MP_QSTR__11M_L), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_11M_L)) },
    { MP_ROM_QSTR(MP_QSTR__2M_S), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_2M_S)) },
    { MP_ROM_QSTR(MP_QSTR__5M_S), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_5M_S)) },
    { MP_ROM_QSTR(MP_QSTR__11M_S), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_11M_S)) },
    { MP_ROM_QSTR(MP_QSTR__48M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_48M)) },
    { MP_ROM_QSTR(MP_QSTR__24M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_24M)) },
    { MP_ROM_QSTR(MP_QSTR__12M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_12M)) },
    { MP_ROM_QSTR(MP_QSTR__6M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_6M)) },
    { MP_ROM_QSTR(MP_QSTR__54M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_54M)) },
    { MP_ROM_QSTR(MP_QSTR__36M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_36M)) },
    { MP_ROM_QSTR(MP_QSTR__18M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_18M)) },
    { MP_ROM_QSTR(MP_QSTR__9M), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_9M)) },
    { MP_ROM_QSTR(MP_QSTR_MCS0_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS0_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS1_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS1_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS2_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS2_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS3_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS3_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS4_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS4_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS5_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS5_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS6_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS6_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS7_LGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS7_LGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS0_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS0_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS1_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS1_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS2_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS2_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS3_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS3_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS4_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS4_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS5_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS5_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS6_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS6_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_MCS7_SGI), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MCS7_SGI)) },
    { MP_ROM_QSTR(MP_QSTR_LORA_250K), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_LORA_250K)) },
    { MP_ROM_QSTR(MP_QSTR_LORA_500K), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_LORA_500K)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_PHY_RATE_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_PHY_RATE_locals_dict, WIFI_PHY_RATE_locals_dict_table);

STATIC void WIFI_PHY_RATE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_PHY_RATE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_PHY_RATE_type_base,
    MP_QSTR_WIFI_PHY_RATE,
    MP_TYPE_FLAG_NONE,
    print, WIFI_PHY_RATE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_PHY_RATE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_PHY_RATE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_PHY_RATE_type_base,
};
    

/*
 * espidf WIFI_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t WIFI_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_WIFI_READY), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_WIFI_READY)) },
    { MP_ROM_QSTR(MP_QSTR_SCAN_DONE), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_SCAN_DONE)) },
    { MP_ROM_QSTR(MP_QSTR_STA_START), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_START)) },
    { MP_ROM_QSTR(MP_QSTR_STA_STOP), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_STOP)) },
    { MP_ROM_QSTR(MP_QSTR_STA_CONNECTED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_CONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_STA_DISCONNECTED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_DISCONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_STA_AUTHMODE_CHANGE), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_AUTHMODE_CHANGE)) },
    { MP_ROM_QSTR(MP_QSTR_STA_WPS_ER_SUCCESS), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_WPS_ER_SUCCESS)) },
    { MP_ROM_QSTR(MP_QSTR_STA_WPS_ER_FAILED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_WPS_ER_FAILED)) },
    { MP_ROM_QSTR(MP_QSTR_STA_WPS_ER_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_WPS_ER_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_STA_WPS_ER_PIN), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_WPS_ER_PIN)) },
    { MP_ROM_QSTR(MP_QSTR_STA_WPS_ER_PBC_OVERLAP), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_WPS_ER_PBC_OVERLAP)) },
    { MP_ROM_QSTR(MP_QSTR_AP_START), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_AP_START)) },
    { MP_ROM_QSTR(MP_QSTR_AP_STOP), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_AP_STOP)) },
    { MP_ROM_QSTR(MP_QSTR_AP_STACONNECTED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_AP_STACONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_AP_STADISCONNECTED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_AP_STADISCONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_AP_PROBEREQRECVED), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_AP_PROBEREQRECVED)) },
    { MP_ROM_QSTR(MP_QSTR_FTM_REPORT), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_FTM_REPORT)) },
    { MP_ROM_QSTR(MP_QSTR_STA_BSS_RSSI_LOW), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_BSS_RSSI_LOW)) },
    { MP_ROM_QSTR(MP_QSTR_ACTION_TX_STATUS), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_ACTION_TX_STATUS)) },
    { MP_ROM_QSTR(MP_QSTR_ROC_DONE), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_ROC_DONE)) },
    { MP_ROM_QSTR(MP_QSTR_STA_BEACON_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_STA_BEACON_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WIFI_EVENT_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WIFI_EVENT_locals_dict, WIFI_EVENT_locals_dict_table);

STATIC void WIFI_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WIFI_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WIFI_EVENT_type_base,
    MP_QSTR_WIFI_EVENT,
    MP_TYPE_FLAG_NONE,
    print, WIFI_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WIFI_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WIFI_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WIFI_EVENT_type_base,
};
    

/*
 * espidf WPS_FAIL_REASON object definitions
 */
    

STATIC const mp_rom_map_elem_t WPS_FAIL_REASON_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NORMAL), MP_ROM_PTR(MP_ROM_INT(WPS_FAIL_REASON_NORMAL)) },
    { MP_ROM_QSTR(MP_QSTR_RECV_M2D), MP_ROM_PTR(MP_ROM_INT(WPS_FAIL_REASON_RECV_M2D)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(WPS_FAIL_REASON_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(WPS_FAIL_REASON_locals_dict, WPS_FAIL_REASON_locals_dict_table);

STATIC void WPS_FAIL_REASON_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf WPS_FAIL_REASON");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_WPS_FAIL_REASON_type_base,
    MP_QSTR_WPS_FAIL_REASON,
    MP_TYPE_FLAG_NONE,
    print, WPS_FAIL_REASON_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &WPS_FAIL_REASON_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_WPS_FAIL_REASON_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_WPS_FAIL_REASON_type_base,
};
    

/*
 * espidf FTM_STATUS object definitions
 */
    

STATIC const mp_rom_map_elem_t FTM_STATUS_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SUCCESS), MP_ROM_PTR(MP_ROM_INT(FTM_STATUS_SUCCESS)) },
    { MP_ROM_QSTR(MP_QSTR_UNSUPPORTED), MP_ROM_PTR(MP_ROM_INT(FTM_STATUS_UNSUPPORTED)) },
    { MP_ROM_QSTR(MP_QSTR_CONF_REJECTED), MP_ROM_PTR(MP_ROM_INT(FTM_STATUS_CONF_REJECTED)) },
    { MP_ROM_QSTR(MP_QSTR_NO_RESPONSE), MP_ROM_PTR(MP_ROM_INT(FTM_STATUS_NO_RESPONSE)) },
    { MP_ROM_QSTR(MP_QSTR_FAIL), MP_ROM_PTR(MP_ROM_INT(FTM_STATUS_FAIL)) }
};

STATIC MP_DEFINE_CONST_DICT(FTM_STATUS_locals_dict, FTM_STATUS_locals_dict_table);

STATIC void FTM_STATUS_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf FTM_STATUS");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_FTM_STATUS_type_base,
    MP_QSTR_FTM_STATUS,
    MP_TYPE_FLAG_NONE,
    print, FTM_STATUS_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &FTM_STATUS_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_FTM_STATUS_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_FTM_STATUS_type_base,
};
    

/*
 * espidf ESP_IP6_ADDR_IS object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_IP6_ADDR_IS_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_UNKNOWN)) },
    { MP_ROM_QSTR(MP_QSTR_GLOBAL), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_GLOBAL)) },
    { MP_ROM_QSTR(MP_QSTR_LINK_LOCAL), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_LINK_LOCAL)) },
    { MP_ROM_QSTR(MP_QSTR_SITE_LOCAL), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_SITE_LOCAL)) },
    { MP_ROM_QSTR(MP_QSTR_UNIQUE_LOCAL), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_UNIQUE_LOCAL)) },
    { MP_ROM_QSTR(MP_QSTR_IPV4_MAPPED_IPV6), MP_ROM_PTR(MP_ROM_INT(ESP_IP6_ADDR_IS_IPV4_MAPPED_IPV6)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_IP6_ADDR_IS_locals_dict, ESP_IP6_ADDR_IS_locals_dict_table);

STATIC void ESP_IP6_ADDR_IS_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_IP6_ADDR_IS");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_IP6_ADDR_IS_type_base,
    MP_QSTR_ESP_IP6_ADDR_IS,
    MP_TYPE_FLAG_NONE,
    print, ESP_IP6_ADDR_IS_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_IP6_ADDR_IS_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_IP6_ADDR_IS_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_IP6_ADDR_IS_type_base,
};
    

/*
 * espidf ESP_NETIF_DNS object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_NETIF_DNS_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_MAIN), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DNS_MAIN)) },
    { MP_ROM_QSTR(MP_QSTR_BACKUP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DNS_BACKUP)) },
    { MP_ROM_QSTR(MP_QSTR_FALLBACK), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DNS_FALLBACK)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DNS_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_NETIF_DNS_locals_dict, ESP_NETIF_DNS_locals_dict_table);

STATIC void ESP_NETIF_DNS_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_NETIF_DNS");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_NETIF_DNS_type_base,
    MP_QSTR_ESP_NETIF_DNS,
    MP_TYPE_FLAG_NONE,
    print, ESP_NETIF_DNS_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_NETIF_DNS_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_NETIF_DNS_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_NETIF_DNS_type_base,
};
    

/*
 * espidf ESP_NETIF_DHCP object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_NETIF_DHCP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_INIT), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_INIT)) },
    { MP_ROM_QSTR(MP_QSTR_STARTED), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_STARTED)) },
    { MP_ROM_QSTR(MP_QSTR_STOPPED), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_STOPPED)) },
    { MP_ROM_QSTR(MP_QSTR_STATUS_MAX), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_STATUS_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_NETIF_DHCP_locals_dict, ESP_NETIF_DHCP_locals_dict_table);

STATIC void ESP_NETIF_DHCP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_NETIF_DHCP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_NETIF_DHCP_type_base,
    MP_QSTR_ESP_NETIF_DHCP,
    MP_TYPE_FLAG_NONE,
    print, ESP_NETIF_DHCP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_NETIF_DHCP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_NETIF_DHCP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_NETIF_DHCP_type_base,
};
    

/*
 * espidf ESP_NETIF_OP object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_NETIF_OP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_START), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_OP_START)) },
    { MP_ROM_QSTR(MP_QSTR_SET), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_OP_SET)) },
    { MP_ROM_QSTR(MP_QSTR_GET), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_OP_GET)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_OP_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_NETIF_OP_locals_dict, ESP_NETIF_OP_locals_dict_table);

STATIC void ESP_NETIF_OP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_NETIF_OP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_NETIF_OP_type_base,
    MP_QSTR_ESP_NETIF_OP,
    MP_TYPE_FLAG_NONE,
    print, ESP_NETIF_OP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_NETIF_OP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_NETIF_OP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_NETIF_OP_type_base,
};
    

/*
 * espidf ESP_NETIF object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_NETIF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SUBNET_MASK), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_SUBNET_MASK)) },
    { MP_ROM_QSTR(MP_QSTR_DOMAIN_NAME_SERVER), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DOMAIN_NAME_SERVER)) },
    { MP_ROM_QSTR(MP_QSTR_ROUTER_SOLICITATION_ADDRESS), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_ROUTER_SOLICITATION_ADDRESS)) },
    { MP_ROM_QSTR(MP_QSTR_REQUESTED_IP_ADDRESS), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_REQUESTED_IP_ADDRESS)) },
    { MP_ROM_QSTR(MP_QSTR_IP_ADDRESS_LEASE_TIME), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_IP_ADDRESS_LEASE_TIME)) },
    { MP_ROM_QSTR(MP_QSTR_IP_REQUEST_RETRY_TIME), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_IP_REQUEST_RETRY_TIME)) },
    { MP_ROM_QSTR(MP_QSTR_VENDOR_CLASS_IDENTIFIER), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_VENDOR_CLASS_IDENTIFIER)) },
    { MP_ROM_QSTR(MP_QSTR_VENDOR_SPECIFIC_INFO), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_VENDOR_SPECIFIC_INFO)) },
    { MP_ROM_QSTR(MP_QSTR_DHCP_CLIENT), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_CLIENT)) },
    { MP_ROM_QSTR(MP_QSTR_DHCP_SERVER), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_DHCP_SERVER)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_AUTOUP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_AUTOUP)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_GARP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_GARP)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_EVENT_IP_MODIFIED), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_EVENT_IP_MODIFIED)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_IS_PPP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_IS_PPP)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_IS_SLIP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_IS_SLIP)) },
    { MP_ROM_QSTR(MP_QSTR_FLAG_MLDV6_REPORT), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_FLAG_MLDV6_REPORT)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_NETIF_locals_dict, ESP_NETIF_locals_dict_table);

STATIC void ESP_NETIF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_NETIF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_NETIF_type_base,
    MP_QSTR_ESP_NETIF,
    MP_TYPE_FLAG_NONE,
    print, ESP_NETIF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_NETIF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_NETIF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_NETIF_type_base,
};
    

/*
 * espidf IP_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t IP_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_STA_GOT_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_STA_GOT_IP)) },
    { MP_ROM_QSTR(MP_QSTR_STA_LOST_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_STA_LOST_IP)) },
    { MP_ROM_QSTR(MP_QSTR_AP_STAIPASSIGNED), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_AP_STAIPASSIGNED)) },
    { MP_ROM_QSTR(MP_QSTR_GOT_IP6), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_GOT_IP6)) },
    { MP_ROM_QSTR(MP_QSTR_ETH_GOT_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_ETH_GOT_IP)) },
    { MP_ROM_QSTR(MP_QSTR_ETH_LOST_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_ETH_LOST_IP)) },
    { MP_ROM_QSTR(MP_QSTR_PPP_GOT_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_PPP_GOT_IP)) },
    { MP_ROM_QSTR(MP_QSTR_PPP_LOST_IP), MP_ROM_PTR(MP_ROM_INT(IP_EVENT_PPP_LOST_IP)) }
};

STATIC MP_DEFINE_CONST_DICT(IP_EVENT_locals_dict, IP_EVENT_locals_dict_table);

STATIC void IP_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf IP_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_IP_EVENT_type_base,
    MP_QSTR_IP_EVENT,
    MP_TYPE_FLAG_NONE,
    print, IP_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &IP_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_IP_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_IP_EVENT_type_base,
};
    

/*
 * espidf ESP_NETIF_IP_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_NETIF_IP_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_GOT_IP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_IP_EVENT_GOT_IP)) },
    { MP_ROM_QSTR(MP_QSTR_LOST_IP), MP_ROM_PTR(MP_ROM_INT(ESP_NETIF_IP_EVENT_LOST_IP)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_NETIF_IP_EVENT_locals_dict, ESP_NETIF_IP_EVENT_locals_dict_table);

STATIC void ESP_NETIF_IP_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_NETIF_IP_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_NETIF_IP_EVENT_type_base,
    MP_QSTR_ESP_NETIF_IP_EVENT,
    MP_TYPE_FLAG_NONE,
    print, ESP_NETIF_IP_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_NETIF_IP_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_NETIF_IP_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_NETIF_IP_EVENT_type_base,
};
    

/*
 * espidf EMAC_DATA_INTERFACE object definitions
 */
    

STATIC const mp_rom_map_elem_t EMAC_DATA_INTERFACE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_RMII), MP_ROM_PTR(MP_ROM_INT(EMAC_DATA_INTERFACE_RMII)) },
    { MP_ROM_QSTR(MP_QSTR_MII), MP_ROM_PTR(MP_ROM_INT(EMAC_DATA_INTERFACE_MII)) }
};

STATIC MP_DEFINE_CONST_DICT(EMAC_DATA_INTERFACE_locals_dict, EMAC_DATA_INTERFACE_locals_dict_table);

STATIC void EMAC_DATA_INTERFACE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf EMAC_DATA_INTERFACE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_EMAC_DATA_INTERFACE_type_base,
    MP_QSTR_EMAC_DATA_INTERFACE,
    MP_TYPE_FLAG_NONE,
    print, EMAC_DATA_INTERFACE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &EMAC_DATA_INTERFACE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_EMAC_DATA_INTERFACE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_EMAC_DATA_INTERFACE_type_base,
};
    

/*
 * espidf ETH_LINK object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_LINK_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UP), MP_ROM_PTR(MP_ROM_INT(ETH_LINK_UP)) },
    { MP_ROM_QSTR(MP_QSTR_DOWN), MP_ROM_PTR(MP_ROM_INT(ETH_LINK_DOWN)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_LINK_locals_dict, ETH_LINK_locals_dict_table);

STATIC void ETH_LINK_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_LINK");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_LINK_type_base,
    MP_QSTR_ETH_LINK,
    MP_TYPE_FLAG_NONE,
    print, ETH_LINK_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_LINK_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_LINK_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_LINK_type_base,
};
    

/*
 * espidf ETH_SPEED object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_SPEED_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR__10M), MP_ROM_PTR(MP_ROM_INT(ETH_SPEED_10M)) },
    { MP_ROM_QSTR(MP_QSTR__100M), MP_ROM_PTR(MP_ROM_INT(ETH_SPEED_100M)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(ETH_SPEED_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_SPEED_locals_dict, ETH_SPEED_locals_dict_table);

STATIC void ETH_SPEED_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_SPEED");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_SPEED_type_base,
    MP_QSTR_ETH_SPEED,
    MP_TYPE_FLAG_NONE,
    print, ETH_SPEED_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_SPEED_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_SPEED_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_SPEED_type_base,
};
    

/*
 * espidf ETH_DUPLEX object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_DUPLEX_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_HALF), MP_ROM_PTR(MP_ROM_INT(ETH_DUPLEX_HALF)) },
    { MP_ROM_QSTR(MP_QSTR_FULL), MP_ROM_PTR(MP_ROM_INT(ETH_DUPLEX_FULL)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_DUPLEX_locals_dict, ETH_DUPLEX_locals_dict_table);

STATIC void ETH_DUPLEX_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_DUPLEX");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_DUPLEX_type_base,
    MP_QSTR_ETH_DUPLEX,
    MP_TYPE_FLAG_NONE,
    print, ETH_DUPLEX_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_DUPLEX_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_DUPLEX_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_DUPLEX_type_base,
};
    

/*
 * espidf ETH_CHECKSUM object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_CHECKSUM_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_SW), MP_ROM_PTR(MP_ROM_INT(ETH_CHECKSUM_SW)) },
    { MP_ROM_QSTR(MP_QSTR_HW), MP_ROM_PTR(MP_ROM_INT(ETH_CHECKSUM_HW)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_CHECKSUM_locals_dict, ETH_CHECKSUM_locals_dict_table);

STATIC void ETH_CHECKSUM_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_CHECKSUM");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_CHECKSUM_type_base,
    MP_QSTR_ETH_CHECKSUM,
    MP_TYPE_FLAG_NONE,
    print, ETH_CHECKSUM_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_CHECKSUM_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_CHECKSUM_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_CHECKSUM_type_base,
};
    

/*
 * espidf ETH_STATE object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_STATE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_LLINIT), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_LLINIT)) },
    { MP_ROM_QSTR(MP_QSTR_DEINIT), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_DEINIT)) },
    { MP_ROM_QSTR(MP_QSTR_LINK), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_LINK)) },
    { MP_ROM_QSTR(MP_QSTR_SPEED), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_SPEED)) },
    { MP_ROM_QSTR(MP_QSTR_DUPLEX), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_DUPLEX)) },
    { MP_ROM_QSTR(MP_QSTR_PAUSE), MP_ROM_PTR(MP_ROM_INT(ETH_STATE_PAUSE)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_STATE_locals_dict, ETH_STATE_locals_dict_table);

STATIC void ETH_STATE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_STATE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_STATE_type_base,
    MP_QSTR_ETH_STATE,
    MP_TYPE_FLAG_NONE,
    print, ETH_STATE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_STATE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_STATE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_STATE_type_base,
};
    

/*
 * espidf ETH_CMD object definitions
 */
    

STATIC const mp_rom_map_elem_t ETH_CMD_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_G_MAC_ADDR), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_G_MAC_ADDR)) },
    { MP_ROM_QSTR(MP_QSTR_S_MAC_ADDR), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_S_MAC_ADDR)) },
    { MP_ROM_QSTR(MP_QSTR_G_PHY_ADDR), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_G_PHY_ADDR)) },
    { MP_ROM_QSTR(MP_QSTR_S_PHY_ADDR), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_S_PHY_ADDR)) },
    { MP_ROM_QSTR(MP_QSTR_G_SPEED), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_G_SPEED)) },
    { MP_ROM_QSTR(MP_QSTR_S_PROMISCUOUS), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_S_PROMISCUOUS)) },
    { MP_ROM_QSTR(MP_QSTR_S_FLOW_CTRL), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_S_FLOW_CTRL)) },
    { MP_ROM_QSTR(MP_QSTR_G_DUPLEX_MODE), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_G_DUPLEX_MODE)) },
    { MP_ROM_QSTR(MP_QSTR_S_PHY_LOOPBACK), MP_ROM_PTR(MP_ROM_INT(ETH_CMD_S_PHY_LOOPBACK)) }
};

STATIC MP_DEFINE_CONST_DICT(ETH_CMD_locals_dict, ETH_CMD_locals_dict_table);

STATIC void ETH_CMD_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETH_CMD");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETH_CMD_type_base,
    MP_QSTR_ETH_CMD,
    MP_TYPE_FLAG_NONE,
    print, ETH_CMD_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETH_CMD_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETH_CMD_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETH_CMD_type_base,
};
    

/*
 * espidf ETHERNET_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t ETHERNET_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_START), MP_ROM_PTR(MP_ROM_INT(ETHERNET_EVENT_START)) },
    { MP_ROM_QSTR(MP_QSTR_STOP), MP_ROM_PTR(MP_ROM_INT(ETHERNET_EVENT_STOP)) },
    { MP_ROM_QSTR(MP_QSTR_CONNECTED), MP_ROM_PTR(MP_ROM_INT(ETHERNET_EVENT_CONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_DISCONNECTED), MP_ROM_PTR(MP_ROM_INT(ETHERNET_EVENT_DISCONNECTED)) }
};

STATIC MP_DEFINE_CONST_DICT(ETHERNET_EVENT_locals_dict, ETHERNET_EVENT_locals_dict_table);

STATIC void ETHERNET_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ETHERNET_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ETHERNET_EVENT_type_base,
    MP_QSTR_ETHERNET_EVENT,
    MP_TYPE_FLAG_NONE,
    print, ETHERNET_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ETHERNET_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ETHERNET_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ETHERNET_EVENT_type_base,
};
    

/*
 * espidf EMAC_CLK object definitions
 */
    

STATIC const mp_rom_map_elem_t EMAC_CLK_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DEFAULT), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_DEFAULT)) },
    { MP_ROM_QSTR(MP_QSTR_EXT_IN), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_EXT_IN)) },
    { MP_ROM_QSTR(MP_QSTR_OUT), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_OUT)) }
};

STATIC MP_DEFINE_CONST_DICT(EMAC_CLK_locals_dict, EMAC_CLK_locals_dict_table);

STATIC void EMAC_CLK_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf EMAC_CLK");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_EMAC_CLK_type_base,
    MP_QSTR_EMAC_CLK,
    MP_TYPE_FLAG_NONE,
    print, EMAC_CLK_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &EMAC_CLK_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_EMAC_CLK_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_EMAC_CLK_type_base,
};
    

/*
 * espidf EMAC object definitions
 */
    

STATIC const mp_rom_map_elem_t EMAC_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_CLK_IN_GPIO), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_IN_GPIO)) },
    { MP_ROM_QSTR(MP_QSTR_APPL_CLK_OUT_GPIO), MP_ROM_PTR(MP_ROM_INT(EMAC_APPL_CLK_OUT_GPIO)) },
    { MP_ROM_QSTR(MP_QSTR_CLK_OUT_GPIO), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_OUT_GPIO)) },
    { MP_ROM_QSTR(MP_QSTR_CLK_OUT_180_GPIO), MP_ROM_PTR(MP_ROM_INT(EMAC_CLK_OUT_180_GPIO)) }
};

STATIC MP_DEFINE_CONST_DICT(EMAC_locals_dict, EMAC_locals_dict_table);

STATIC void EMAC_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf EMAC");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_EMAC_type_base,
    MP_QSTR_EMAC,
    MP_TYPE_FLAG_NONE,
    print, EMAC_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &EMAC_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_EMAC_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_EMAC_type_base,
};
    

/*
 * espidf ESP_MAC object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_MAC_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_WIFI_STA), MP_ROM_PTR(MP_ROM_INT(ESP_MAC_WIFI_STA)) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_SOFTAP), MP_ROM_PTR(MP_ROM_INT(ESP_MAC_WIFI_SOFTAP)) },
    { MP_ROM_QSTR(MP_QSTR_BT), MP_ROM_PTR(MP_ROM_INT(ESP_MAC_BT)) },
    { MP_ROM_QSTR(MP_QSTR_ETH), MP_ROM_PTR(MP_ROM_INT(ESP_MAC_ETH)) },
    { MP_ROM_QSTR(MP_QSTR_IEEE802154), MP_ROM_PTR(MP_ROM_INT(ESP_MAC_IEEE802154)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_MAC_locals_dict, ESP_MAC_locals_dict_table);

STATIC void ESP_MAC_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_MAC");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_MAC_type_base,
    MP_QSTR_ESP_MAC,
    MP_TYPE_FLAG_NONE,
    print, ESP_MAC_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_MAC_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_MAC_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_MAC_type_base,
};
    

/*
 * espidf CHIP object definitions
 */
    

STATIC const mp_rom_map_elem_t CHIP_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ESP32), MP_ROM_PTR(MP_ROM_INT(CHIP_ESP32)) },
    { MP_ROM_QSTR(MP_QSTR_ESP32S2), MP_ROM_PTR(MP_ROM_INT(CHIP_ESP32S2)) },
    { MP_ROM_QSTR(MP_QSTR_ESP32S3), MP_ROM_PTR(MP_ROM_INT(CHIP_ESP32S3)) },
    { MP_ROM_QSTR(MP_QSTR_ESP32C3), MP_ROM_PTR(MP_ROM_INT(CHIP_ESP32C3)) },
    { MP_ROM_QSTR(MP_QSTR_ESP32H2), MP_ROM_PTR(MP_ROM_INT(CHIP_ESP32H2)) }
};

STATIC MP_DEFINE_CONST_DICT(CHIP_locals_dict, CHIP_locals_dict_table);

STATIC void CHIP_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf CHIP");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_CHIP_type_base,
    MP_QSTR_CHIP,
    MP_TYPE_FLAG_NONE,
    print, CHIP_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &CHIP_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_CHIP_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_CHIP_type_base,
};
    

/*
 * espidf ESP_RST object definitions
 */
    

STATIC const mp_rom_map_elem_t ESP_RST_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(ESP_RST_UNKNOWN)) },
    { MP_ROM_QSTR(MP_QSTR_POWERON), MP_ROM_PTR(MP_ROM_INT(ESP_RST_POWERON)) },
    { MP_ROM_QSTR(MP_QSTR_EXT), MP_ROM_PTR(MP_ROM_INT(ESP_RST_EXT)) },
    { MP_ROM_QSTR(MP_QSTR_SW), MP_ROM_PTR(MP_ROM_INT(ESP_RST_SW)) },
    { MP_ROM_QSTR(MP_QSTR_PANIC), MP_ROM_PTR(MP_ROM_INT(ESP_RST_PANIC)) },
    { MP_ROM_QSTR(MP_QSTR_INT_WDT), MP_ROM_PTR(MP_ROM_INT(ESP_RST_INT_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_TASK_WDT), MP_ROM_PTR(MP_ROM_INT(ESP_RST_TASK_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_WDT), MP_ROM_PTR(MP_ROM_INT(ESP_RST_WDT)) },
    { MP_ROM_QSTR(MP_QSTR_DEEPSLEEP), MP_ROM_PTR(MP_ROM_INT(ESP_RST_DEEPSLEEP)) },
    { MP_ROM_QSTR(MP_QSTR_BROWNOUT), MP_ROM_PTR(MP_ROM_INT(ESP_RST_BROWNOUT)) },
    { MP_ROM_QSTR(MP_QSTR_SDIO), MP_ROM_PTR(MP_ROM_INT(ESP_RST_SDIO)) }
};

STATIC MP_DEFINE_CONST_DICT(ESP_RST_locals_dict, ESP_RST_locals_dict_table);

STATIC void ESP_RST_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ESP_RST");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ESP_RST_type_base,
    MP_QSTR_ESP_RST,
    MP_TYPE_FLAG_NONE,
    print, ESP_RST_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ESP_RST_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ESP_RST_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ESP_RST_type_base,
};
    

/*
 * espidf ERR object definitions
 */
    

STATIC const mp_rom_map_elem_t ERR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_OK), MP_ROM_PTR(MP_ROM_INT(ERR_OK)) },
    { MP_ROM_QSTR(MP_QSTR_MEM), MP_ROM_PTR(MP_ROM_INT(ERR_MEM)) },
    { MP_ROM_QSTR(MP_QSTR_BUF), MP_ROM_PTR(MP_ROM_INT(ERR_BUF)) },
    { MP_ROM_QSTR(MP_QSTR_TIMEOUT), MP_ROM_PTR(MP_ROM_INT(ERR_TIMEOUT)) },
    { MP_ROM_QSTR(MP_QSTR_RTE), MP_ROM_PTR(MP_ROM_INT(ERR_RTE)) },
    { MP_ROM_QSTR(MP_QSTR_INPROGRESS), MP_ROM_PTR(MP_ROM_INT(ERR_INPROGRESS)) },
    { MP_ROM_QSTR(MP_QSTR_VAL), MP_ROM_PTR(MP_ROM_INT(ERR_VAL)) },
    { MP_ROM_QSTR(MP_QSTR_WOULDBLOCK), MP_ROM_PTR(MP_ROM_INT(ERR_WOULDBLOCK)) },
    { MP_ROM_QSTR(MP_QSTR_USE), MP_ROM_PTR(MP_ROM_INT(ERR_USE)) },
    { MP_ROM_QSTR(MP_QSTR_ALREADY), MP_ROM_PTR(MP_ROM_INT(ERR_ALREADY)) },
    { MP_ROM_QSTR(MP_QSTR_ISCONN), MP_ROM_PTR(MP_ROM_INT(ERR_ISCONN)) },
    { MP_ROM_QSTR(MP_QSTR_CONN), MP_ROM_PTR(MP_ROM_INT(ERR_CONN)) },
    { MP_ROM_QSTR(MP_QSTR_IF), MP_ROM_PTR(MP_ROM_INT(ERR_IF)) },
    { MP_ROM_QSTR(MP_QSTR_ABRT), MP_ROM_PTR(MP_ROM_INT(ERR_ABRT)) },
    { MP_ROM_QSTR(MP_QSTR_RST), MP_ROM_PTR(MP_ROM_INT(ERR_RST)) },
    { MP_ROM_QSTR(MP_QSTR_CLSD), MP_ROM_PTR(MP_ROM_INT(ERR_CLSD)) },
    { MP_ROM_QSTR(MP_QSTR_ARG), MP_ROM_PTR(MP_ROM_INT(ERR_ARG)) }
};

STATIC MP_DEFINE_CONST_DICT(ERR_locals_dict, ERR_locals_dict_table);

STATIC void ERR_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf ERR");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_ERR_type_base,
    MP_QSTR_ERR,
    MP_TYPE_FLAG_NONE,
    print, ERR_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &ERR_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_ERR_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_ERR_type_base,
};
    

/*
 * espidf TCPIP_ADAPTER_IF object definitions
 */
    

STATIC const mp_rom_map_elem_t TCPIP_ADAPTER_IF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_STA), MP_ROM_PTR(MP_ROM_INT(TCPIP_ADAPTER_IF_STA)) },
    { MP_ROM_QSTR(MP_QSTR_AP), MP_ROM_PTR(MP_ROM_INT(TCPIP_ADAPTER_IF_AP)) },
    { MP_ROM_QSTR(MP_QSTR_ETH), MP_ROM_PTR(MP_ROM_INT(TCPIP_ADAPTER_IF_ETH)) },
    { MP_ROM_QSTR(MP_QSTR_TEST), MP_ROM_PTR(MP_ROM_INT(TCPIP_ADAPTER_IF_TEST)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(TCPIP_ADAPTER_IF_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(TCPIP_ADAPTER_IF_locals_dict, TCPIP_ADAPTER_IF_locals_dict_table);

STATIC void TCPIP_ADAPTER_IF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf TCPIP_ADAPTER_IF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_TCPIP_ADAPTER_IF_type_base,
    MP_QSTR_TCPIP_ADAPTER_IF,
    MP_TYPE_FLAG_NONE,
    print, TCPIP_ADAPTER_IF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &TCPIP_ADAPTER_IF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_TCPIP_ADAPTER_IF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_TCPIP_ADAPTER_IF_type_base,
};
    

/*
 * espidf MDNS_IP_PROTOCOL object definitions
 */
    

STATIC const mp_rom_map_elem_t MDNS_IP_PROTOCOL_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_V4), MP_ROM_PTR(MP_ROM_INT(MDNS_IP_PROTOCOL_V4)) },
    { MP_ROM_QSTR(MP_QSTR_V6), MP_ROM_PTR(MP_ROM_INT(MDNS_IP_PROTOCOL_V6)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(MDNS_IP_PROTOCOL_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(MDNS_IP_PROTOCOL_locals_dict, MDNS_IP_PROTOCOL_locals_dict_table);

STATIC void MDNS_IP_PROTOCOL_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf MDNS_IP_PROTOCOL");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_MDNS_IP_PROTOCOL_type_base,
    MP_QSTR_MDNS_IP_PROTOCOL,
    MP_TYPE_FLAG_NONE,
    print, MDNS_IP_PROTOCOL_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &MDNS_IP_PROTOCOL_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_MDNS_IP_PROTOCOL_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_MDNS_IP_PROTOCOL_type_base,
};
    

/*
 * espidf MDNS_IF object definitions
 */
    

STATIC const mp_rom_map_elem_t MDNS_IF_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_STA), MP_ROM_PTR(MP_ROM_INT(MDNS_IF_STA)) },
    { MP_ROM_QSTR(MP_QSTR_AP), MP_ROM_PTR(MP_ROM_INT(MDNS_IF_AP)) },
    { MP_ROM_QSTR(MP_QSTR_ETH), MP_ROM_PTR(MP_ROM_INT(MDNS_IF_ETH)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(MDNS_IF_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(MDNS_IF_locals_dict, MDNS_IF_locals_dict_table);

STATIC void MDNS_IF_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf MDNS_IF");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_MDNS_IF_type_base,
    MP_QSTR_MDNS_IF,
    MP_TYPE_FLAG_NONE,
    print, MDNS_IF_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &MDNS_IF_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_MDNS_IF_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_MDNS_IF_type_base,
};
    

/*
 * espidf HTTP_EVENT object definitions
 */
    

STATIC const mp_rom_map_elem_t HTTP_EVENT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_ERROR), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_ERROR)) },
    { MP_ROM_QSTR(MP_QSTR_ON_CONNECTED), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_ON_CONNECTED)) },
    { MP_ROM_QSTR(MP_QSTR_HEADERS_SENT), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_HEADERS_SENT)) },
    { MP_ROM_QSTR(MP_QSTR_HEADER_SENT), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_HEADER_SENT)) },
    { MP_ROM_QSTR(MP_QSTR_ON_HEADER), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_ON_HEADER)) },
    { MP_ROM_QSTR(MP_QSTR_ON_DATA), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_ON_DATA)) },
    { MP_ROM_QSTR(MP_QSTR_ON_FINISH), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_ON_FINISH)) },
    { MP_ROM_QSTR(MP_QSTR_DISCONNECTED), MP_ROM_PTR(MP_ROM_INT(HTTP_EVENT_DISCONNECTED)) }
};

STATIC MP_DEFINE_CONST_DICT(HTTP_EVENT_locals_dict, HTTP_EVENT_locals_dict_table);

STATIC void HTTP_EVENT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HTTP_EVENT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HTTP_EVENT_type_base,
    MP_QSTR_HTTP_EVENT,
    MP_TYPE_FLAG_NONE,
    print, HTTP_EVENT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HTTP_EVENT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HTTP_EVENT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HTTP_EVENT_type_base,
};
    

/*
 * espidf HTTP_TRANSPORT object definitions
 */
    

STATIC const mp_rom_map_elem_t HTTP_TRANSPORT_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_UNKNOWN), MP_ROM_PTR(MP_ROM_INT(HTTP_TRANSPORT_UNKNOWN)) },
    { MP_ROM_QSTR(MP_QSTR_OVER_TCP), MP_ROM_PTR(MP_ROM_INT(HTTP_TRANSPORT_OVER_TCP)) },
    { MP_ROM_QSTR(MP_QSTR_OVER_SSL), MP_ROM_PTR(MP_ROM_INT(HTTP_TRANSPORT_OVER_SSL)) }
};

STATIC MP_DEFINE_CONST_DICT(HTTP_TRANSPORT_locals_dict, HTTP_TRANSPORT_locals_dict_table);

STATIC void HTTP_TRANSPORT_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HTTP_TRANSPORT");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HTTP_TRANSPORT_type_base,
    MP_QSTR_HTTP_TRANSPORT,
    MP_TYPE_FLAG_NONE,
    print, HTTP_TRANSPORT_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HTTP_TRANSPORT_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HTTP_TRANSPORT_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HTTP_TRANSPORT_type_base,
};
    

/*
 * espidf HTTP_METHOD object definitions
 */
    

STATIC const mp_rom_map_elem_t HTTP_METHOD_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_GET), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_GET)) },
    { MP_ROM_QSTR(MP_QSTR_POST), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_POST)) },
    { MP_ROM_QSTR(MP_QSTR_PUT), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_PUT)) },
    { MP_ROM_QSTR(MP_QSTR_PATCH), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_PATCH)) },
    { MP_ROM_QSTR(MP_QSTR_DELETE), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_DELETE)) },
    { MP_ROM_QSTR(MP_QSTR_HEAD), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_HEAD)) },
    { MP_ROM_QSTR(MP_QSTR_NOTIFY), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_NOTIFY)) },
    { MP_ROM_QSTR(MP_QSTR_SUBSCRIBE), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_SUBSCRIBE)) },
    { MP_ROM_QSTR(MP_QSTR_UNSUBSCRIBE), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_UNSUBSCRIBE)) },
    { MP_ROM_QSTR(MP_QSTR_OPTIONS), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_OPTIONS)) },
    { MP_ROM_QSTR(MP_QSTR_COPY), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_COPY)) },
    { MP_ROM_QSTR(MP_QSTR_MOVE), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_MOVE)) },
    { MP_ROM_QSTR(MP_QSTR_LOCK), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_LOCK)) },
    { MP_ROM_QSTR(MP_QSTR_UNLOCK), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_UNLOCK)) },
    { MP_ROM_QSTR(MP_QSTR_PROPFIND), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_PROPFIND)) },
    { MP_ROM_QSTR(MP_QSTR_PROPPATCH), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_PROPPATCH)) },
    { MP_ROM_QSTR(MP_QSTR_MKCOL), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_MKCOL)) },
    { MP_ROM_QSTR(MP_QSTR_MAX), MP_ROM_PTR(MP_ROM_INT(HTTP_METHOD_MAX)) }
};

STATIC MP_DEFINE_CONST_DICT(HTTP_METHOD_locals_dict, HTTP_METHOD_locals_dict_table);

STATIC void HTTP_METHOD_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HTTP_METHOD");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HTTP_METHOD_type_base,
    MP_QSTR_HTTP_METHOD,
    MP_TYPE_FLAG_NONE,
    print, HTTP_METHOD_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HTTP_METHOD_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HTTP_METHOD_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HTTP_METHOD_type_base,
};
    

/*
 * espidf HTTP_AUTH_TYPE object definitions
 */
    

STATIC const mp_rom_map_elem_t HTTP_AUTH_TYPE_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(HTTP_AUTH_TYPE_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_BASIC), MP_ROM_PTR(MP_ROM_INT(HTTP_AUTH_TYPE_BASIC)) },
    { MP_ROM_QSTR(MP_QSTR_DIGEST), MP_ROM_PTR(MP_ROM_INT(HTTP_AUTH_TYPE_DIGEST)) }
};

STATIC MP_DEFINE_CONST_DICT(HTTP_AUTH_TYPE_locals_dict, HTTP_AUTH_TYPE_locals_dict_table);

STATIC void HTTP_AUTH_TYPE_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HTTP_AUTH_TYPE");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HTTP_AUTH_TYPE_type_base,
    MP_QSTR_HTTP_AUTH_TYPE,
    MP_TYPE_FLAG_NONE,
    print, HTTP_AUTH_TYPE_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HTTP_AUTH_TYPE_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HTTP_AUTH_TYPE_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HTTP_AUTH_TYPE_type_base,
};
    

/*
 * espidf HttpStatus object definitions
 */
    

STATIC const mp_rom_map_elem_t HttpStatus_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_Ok), MP_ROM_PTR(MP_ROM_INT(HttpStatus_Ok)) },
    { MP_ROM_QSTR(MP_QSTR_MultipleChoices), MP_ROM_PTR(MP_ROM_INT(HttpStatus_MultipleChoices)) },
    { MP_ROM_QSTR(MP_QSTR_MovedPermanently), MP_ROM_PTR(MP_ROM_INT(HttpStatus_MovedPermanently)) },
    { MP_ROM_QSTR(MP_QSTR_Found), MP_ROM_PTR(MP_ROM_INT(HttpStatus_Found)) },
    { MP_ROM_QSTR(MP_QSTR_SeeOther), MP_ROM_PTR(MP_ROM_INT(HttpStatus_SeeOther)) },
    { MP_ROM_QSTR(MP_QSTR_TemporaryRedirect), MP_ROM_PTR(MP_ROM_INT(HttpStatus_TemporaryRedirect)) },
    { MP_ROM_QSTR(MP_QSTR_PermanentRedirect), MP_ROM_PTR(MP_ROM_INT(HttpStatus_PermanentRedirect)) },
    { MP_ROM_QSTR(MP_QSTR_BadRequest), MP_ROM_PTR(MP_ROM_INT(HttpStatus_BadRequest)) },
    { MP_ROM_QSTR(MP_QSTR_Unauthorized), MP_ROM_PTR(MP_ROM_INT(HttpStatus_Unauthorized)) },
    { MP_ROM_QSTR(MP_QSTR_Forbidden), MP_ROM_PTR(MP_ROM_INT(HttpStatus_Forbidden)) },
    { MP_ROM_QSTR(MP_QSTR_NotFound), MP_ROM_PTR(MP_ROM_INT(HttpStatus_NotFound)) },
    { MP_ROM_QSTR(MP_QSTR_InternalError), MP_ROM_PTR(MP_ROM_INT(HttpStatus_InternalError)) }
};

STATIC MP_DEFINE_CONST_DICT(HttpStatus_locals_dict, HttpStatus_locals_dict_table);

STATIC void HttpStatus_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf HttpStatus");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_HttpStatus_type_base,
    MP_QSTR_HttpStatus,
    MP_TYPE_FLAG_NONE,
    print, HttpStatus_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &HttpStatus_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_HttpStatus_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_HttpStatus_type_base,
};
    

/*
 * espidf SH2LIB_ERR object definitions
 */
    

STATIC const mp_rom_map_elem_t SH2LIB_ERR_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_INVALID_ARGUMENT), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_ARGUMENT)) },
    { MP_ROM_QSTR(MP_QSTR_BUFFER_ERROR), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_BUFFER_ERROR)) },
    { MP_ROM_QSTR(MP_QSTR_UNSUPPORTED_VERSION), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_UNSUPPORTED_VERSION)) },
    { MP_ROM_QSTR(MP_QSTR_WOULDBLOCK), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_WOULDBLOCK)) },
    { MP_ROM_QSTR(MP_QSTR_PROTO), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_PROTO)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_FRAME), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_FRAME)) },
    { MP_ROM_QSTR(MP_QSTR_EOF), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_EOF)) },
    { MP_ROM_QSTR(MP_QSTR_DEFERRED), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_DEFERRED)) },
    { MP_ROM_QSTR(MP_QSTR_STREAM_ID_NOT_AVAILABLE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_STREAM_ID_NOT_AVAILABLE)) },
    { MP_ROM_QSTR(MP_QSTR_STREAM_CLOSED), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_STREAM_CLOSED)) },
    { MP_ROM_QSTR(MP_QSTR_STREAM_CLOSING), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_STREAM_CLOSING)) },
    { MP_ROM_QSTR(MP_QSTR_STREAM_SHUT_WR), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_STREAM_SHUT_WR)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_STREAM_ID), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_STREAM_ID)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_STREAM_STATE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_STREAM_STATE)) },
    { MP_ROM_QSTR(MP_QSTR_DEFERRED_DATA_EXIST), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_DEFERRED_DATA_EXIST)) },
    { MP_ROM_QSTR(MP_QSTR_START_STREAM_NOT_ALLOWED), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_START_STREAM_NOT_ALLOWED)) },
    { MP_ROM_QSTR(MP_QSTR_GOAWAY_ALREADY_SENT), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_GOAWAY_ALREADY_SENT)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_HEADER_BLOCK), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_HEADER_BLOCK)) },
    { MP_ROM_QSTR(MP_QSTR_INVALID_STATE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INVALID_STATE)) },
    { MP_ROM_QSTR(MP_QSTR_TEMPORAL_CALLBACK_FAILURE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_TEMPORAL_CALLBACK_FAILURE)) },
    { MP_ROM_QSTR(MP_QSTR_FRAME_SIZE_ERROR), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_FRAME_SIZE_ERROR)) },
    { MP_ROM_QSTR(MP_QSTR_HEADER_COMP), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_HEADER_COMP)) },
    { MP_ROM_QSTR(MP_QSTR_FLOW_CONTROL), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_FLOW_CONTROL)) },
    { MP_ROM_QSTR(MP_QSTR_INSUFF_BUFSIZE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INSUFF_BUFSIZE)) },
    { MP_ROM_QSTR(MP_QSTR_PAUSE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_PAUSE)) },
    { MP_ROM_QSTR(MP_QSTR_TOO_MANY_INFLIGHT_SETTINGS), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_TOO_MANY_INFLIGHT_SETTINGS)) },
    { MP_ROM_QSTR(MP_QSTR_PUSH_DISABLED), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_PUSH_DISABLED)) },
    { MP_ROM_QSTR(MP_QSTR_DATA_EXIST), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_DATA_EXIST)) },
    { MP_ROM_QSTR(MP_QSTR_SESSION_CLOSING), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_SESSION_CLOSING)) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_HEADER), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_HTTP_HEADER)) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_MESSAGING), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_HTTP_MESSAGING)) },
    { MP_ROM_QSTR(MP_QSTR_REFUSED_STREAM), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_REFUSED_STREAM)) },
    { MP_ROM_QSTR(MP_QSTR_INTERNAL), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_INTERNAL)) },
    { MP_ROM_QSTR(MP_QSTR_CANCEL), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_CANCEL)) },
    { MP_ROM_QSTR(MP_QSTR_FATAL), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_FATAL)) },
    { MP_ROM_QSTR(MP_QSTR_NOMEM), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_NOMEM)) },
    { MP_ROM_QSTR(MP_QSTR_CALLBACK_FAILURE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_CALLBACK_FAILURE)) },
    { MP_ROM_QSTR(MP_QSTR_BAD_CLIENT_MAGIC), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_BAD_CLIENT_MAGIC)) },
    { MP_ROM_QSTR(MP_QSTR_FLOODED), MP_ROM_PTR(MP_ROM_INT(SH2LIB_ERR_FLOODED)) }
};

STATIC MP_DEFINE_CONST_DICT(SH2LIB_ERR_locals_dict, SH2LIB_ERR_locals_dict_table);

STATIC void SH2LIB_ERR_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SH2LIB_ERR");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SH2LIB_ERR_type_base,
    MP_QSTR_SH2LIB_ERR,
    MP_TYPE_FLAG_NONE,
    print, SH2LIB_ERR_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SH2LIB_ERR_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SH2LIB_ERR_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SH2LIB_ERR_type_base,
};
    

/*
 * espidf SH2LIB_NV_FLAG object definitions
 */
    

STATIC const mp_rom_map_elem_t SH2LIB_NV_FLAG_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_NV_FLAG_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_NO_INDEX), MP_ROM_PTR(MP_ROM_INT(SH2LIB_NV_FLAG_NO_INDEX)) },
    { MP_ROM_QSTR(MP_QSTR_NO_COPY_NAME), MP_ROM_PTR(MP_ROM_INT(SH2LIB_NV_FLAG_NO_COPY_NAME)) },
    { MP_ROM_QSTR(MP_QSTR_NO_COPY_VALUE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_NV_FLAG_NO_COPY_VALUE)) }
};

STATIC MP_DEFINE_CONST_DICT(SH2LIB_NV_FLAG_locals_dict, SH2LIB_NV_FLAG_locals_dict_table);

STATIC void SH2LIB_NV_FLAG_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SH2LIB_NV_FLAG");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SH2LIB_NV_FLAG_type_base,
    MP_QSTR_SH2LIB_NV_FLAG,
    MP_TYPE_FLAG_NONE,
    print, SH2LIB_NV_FLAG_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SH2LIB_NV_FLAG_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SH2LIB_NV_FLAG_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SH2LIB_NV_FLAG_type_base,
};
    

/*
 * espidf SH2LIB_DATA_FLAG object definitions
 */
    

STATIC const mp_rom_map_elem_t SH2LIB_DATA_FLAG_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_FLAG_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_EOF), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_FLAG_EOF)) },
    { MP_ROM_QSTR(MP_QSTR_NO_END_STREAM), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_FLAG_NO_END_STREAM)) },
    { MP_ROM_QSTR(MP_QSTR_NO_COPY), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_FLAG_NO_COPY)) }
};

STATIC MP_DEFINE_CONST_DICT(SH2LIB_DATA_FLAG_locals_dict, SH2LIB_DATA_FLAG_locals_dict_table);

STATIC void SH2LIB_DATA_FLAG_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SH2LIB_DATA_FLAG");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SH2LIB_DATA_FLAG_type_base,
    MP_QSTR_SH2LIB_DATA_FLAG,
    MP_TYPE_FLAG_NONE,
    print, SH2LIB_DATA_FLAG_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SH2LIB_DATA_FLAG_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SH2LIB_DATA_FLAG_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SH2LIB_DATA_FLAG_type_base,
};
    

/*
 * espidf SH2LIB_DATA_RECV object definitions
 */
    

STATIC const mp_rom_map_elem_t SH2LIB_DATA_RECV_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_RECV_NONE)) },
    { MP_ROM_QSTR(MP_QSTR_RST_STREAM), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_RECV_RST_STREAM)) },
    { MP_ROM_QSTR(MP_QSTR_FRAME_COMPLETE), MP_ROM_PTR(MP_ROM_INT(SH2LIB_DATA_RECV_FRAME_COMPLETE)) }
};

STATIC MP_DEFINE_CONST_DICT(SH2LIB_DATA_RECV_locals_dict, SH2LIB_DATA_RECV_locals_dict_table);

STATIC void SH2LIB_DATA_RECV_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "espidf SH2LIB_DATA_RECV");
}



STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_lv_SH2LIB_DATA_RECV_type_base,
    MP_QSTR_SH2LIB_DATA_RECV,
    MP_TYPE_FLAG_NONE,
    print, SH2LIB_DATA_RECV_print,
    
    
    attr, call_parent_methods,
    
    
    locals_dict, &SH2LIB_DATA_RECV_locals_dict
);

GENMPY_UNUSED STATIC const mp_lv_obj_type_t mp_lv_SH2LIB_DATA_RECV_type = {
#ifdef LV_OBJ_T
    .lv_obj_class = NULL,
#endif
    .mp_obj_type = &mp_lv_SH2LIB_DATA_RECV_type_base,
};
    
/* Global struct wrapper for int */

typedef struct {
    int value;
} _lv_mp_int_wrapper;
        

/*
 * Struct _lv_mp_int_wrapper
 */

STATIC inline const mp_obj_type_t *get_mp__lv_mp_int_wrapper_type();

STATIC inline void* mp_write_ptr__lv_mp_int_wrapper(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp__lv_mp_int_wrapper_type()));
    return (_lv_mp_int_wrapper*)self->data;
}

#define mp_write__lv_mp_int_wrapper(struct_obj) *((_lv_mp_int_wrapper*)mp_write_ptr__lv_mp_int_wrapper(struct_obj))

STATIC inline mp_obj_t mp_read_ptr__lv_mp_int_wrapper(void *field)
{
    return lv_to_mp_struct(get_mp__lv_mp_int_wrapper_type(), field);
}

#define mp_read__lv_mp_int_wrapper(field) mp_read_ptr__lv_mp_int_wrapper(copy_buffer(&field, sizeof(_lv_mp_int_wrapper)))
#define mp_read_byref__lv_mp_int_wrapper(field) mp_read_ptr__lv_mp_int_wrapper(&field)

STATIC void mp__lv_mp_int_wrapper_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED _lv_mp_int_wrapper *data = (_lv_mp_int_wrapper*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_value: dest[0] = mp_obj_new_int(data->value); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_value: data->value = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp__lv_mp_int_wrapper_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct _lv_mp_int_wrapper");
}

STATIC const mp_obj_dict_t mp__lv_mp_int_wrapper_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp__lv_mp_int_wrapper_type,
    MP_QSTR__lv_mp_int_wrapper,
    MP_TYPE_FLAG_NONE,
    print, mp__lv_mp_int_wrapper_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp__lv_mp_int_wrapper_attr,
    locals_dict, &mp__lv_mp_int_wrapper_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp__lv_mp_int_wrapper_type()
{
    return &mp__lv_mp_int_wrapper_type;
}
    

/*
 * espidf esp_log_default_level global definitions
 */

STATIC const mp_lv_struct_t mp_esp_log_default_level = {
    { &mp__lv_mp_int_wrapper_type },
    (esp_log_level_t*)&esp_log_default_level
};
    
/* Global struct wrapper for char* */

typedef struct {
    char* value;
} _lv_mp_char_ptr_wrapper;
        

/*
 * Struct _lv_mp_char_ptr_wrapper
 */

STATIC inline const mp_obj_type_t *get_mp__lv_mp_char_ptr_wrapper_type();

STATIC inline void* mp_write_ptr__lv_mp_char_ptr_wrapper(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp__lv_mp_char_ptr_wrapper_type()));
    return (_lv_mp_char_ptr_wrapper*)self->data;
}

#define mp_write__lv_mp_char_ptr_wrapper(struct_obj) *((_lv_mp_char_ptr_wrapper*)mp_write_ptr__lv_mp_char_ptr_wrapper(struct_obj))

STATIC inline mp_obj_t mp_read_ptr__lv_mp_char_ptr_wrapper(void *field)
{
    return lv_to_mp_struct(get_mp__lv_mp_char_ptr_wrapper_type(), field);
}

#define mp_read__lv_mp_char_ptr_wrapper(field) mp_read_ptr__lv_mp_char_ptr_wrapper(copy_buffer(&field, sizeof(_lv_mp_char_ptr_wrapper)))
#define mp_read_byref__lv_mp_char_ptr_wrapper(field) mp_read_ptr__lv_mp_char_ptr_wrapper(&field)

STATIC void mp__lv_mp_char_ptr_wrapper_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED _lv_mp_char_ptr_wrapper *data = (_lv_mp_char_ptr_wrapper*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_value: dest[0] = convert_to_str((void*)data->value); break; // converting from char *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_value: data->value = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp__lv_mp_char_ptr_wrapper_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct _lv_mp_char_ptr_wrapper");
}

STATIC const mp_obj_dict_t mp__lv_mp_char_ptr_wrapper_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp__lv_mp_char_ptr_wrapper_type,
    MP_QSTR__lv_mp_char_ptr_wrapper,
    MP_TYPE_FLAG_NONE,
    print, mp__lv_mp_char_ptr_wrapper_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp__lv_mp_char_ptr_wrapper_attr,
    locals_dict, &mp__lv_mp_char_ptr_wrapper_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp__lv_mp_char_ptr_wrapper_type()
{
    return &mp__lv_mp_char_ptr_wrapper_type;
}
    

/*
 * espidf WIFI_EVENT global definitions
 */

STATIC const mp_lv_struct_t mp_WIFI_EVENT = {
    { &mp__lv_mp_char_ptr_wrapper_type },
    (esp_event_base_t*)&WIFI_EVENT
};
    

/*
 * espidf IP_EVENT global definitions
 */

STATIC const mp_lv_struct_t mp_IP_EVENT = {
    { &mp__lv_mp_char_ptr_wrapper_type },
    (esp_event_base_t*)&IP_EVENT
};
    

/*
 * espidf ETH_EVENT global definitions
 */

STATIC const mp_lv_struct_t mp_ETH_EVENT = {
    { &mp__lv_mp_char_ptr_wrapper_type },
    (esp_event_base_t*)&ETH_EVENT
};
    
typedef __typeof__( ((ip_addr_t*)(0))->u_addr ) ip_addr_u_addr_t;

/*
 * Array convertors for u32_t [4]
 */

GENMPY_UNUSED STATIC u32_t *mp_arr_to_u32_t___4__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    u32_t *lv_arr = (u32_t*)m_malloc(len * sizeof(u32_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint32_t)mp_obj_get_int(item);
    }
    return (u32_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_u32_t___4__(u32_t *arr)
{
    mp_obj_t obj_arr[4];
    for (size_t i=0; i<4; i++){
        obj_arr[i] = mp_obj_new_int_from_uint(arr[i]);
    }
    return mp_obj_new_list(4, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct ip6_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_ip6_addr_t_type();

STATIC inline void* mp_write_ptr_ip6_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_ip6_addr_t_type()));
    return (ip6_addr_t*)self->data;
}

#define mp_write_ip6_addr_t(struct_obj) *((ip6_addr_t*)mp_write_ptr_ip6_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_ip6_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_ip6_addr_t_type(), field);
}

#define mp_read_ip6_addr_t(field) mp_read_ptr_ip6_addr_t(copy_buffer(&field, sizeof(ip6_addr_t)))
#define mp_read_byref_ip6_addr_t(field) mp_read_ptr_ip6_addr_t(&field)

STATIC void mp_ip6_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED ip6_addr_t *data = (ip6_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_addr: dest[0] = mp_arr_from_u32_t___4__(data->addr); break; // converting from u32_t [4];
            case MP_QSTR_zone: dest[0] = mp_obj_new_int_from_uint(data->zone); break; // converting from u8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_addr: memcpy((void*)&data->addr, mp_arr_to_u32_t___4__(dest[1]), sizeof(u32_t)*4); break; // converting to u32_t [4];
                case MP_QSTR_zone: data->zone = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to u8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_ip6_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct ip6_addr_t");
}

STATIC const mp_obj_dict_t mp_ip6_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_ip6_addr_t_type,
    MP_QSTR_ip6_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_ip6_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_ip6_addr_t_attr,
    locals_dict, &mp_ip6_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_ip6_addr_t_type()
{
    return &mp_ip6_addr_t_type;
}
    

/*
 * Struct ip4_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_ip4_addr_t_type();

STATIC inline void* mp_write_ptr_ip4_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_ip4_addr_t_type()));
    return (ip4_addr_t*)self->data;
}

#define mp_write_ip4_addr_t(struct_obj) *((ip4_addr_t*)mp_write_ptr_ip4_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_ip4_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_ip4_addr_t_type(), field);
}

#define mp_read_ip4_addr_t(field) mp_read_ptr_ip4_addr_t(copy_buffer(&field, sizeof(ip4_addr_t)))
#define mp_read_byref_ip4_addr_t(field) mp_read_ptr_ip4_addr_t(&field)

STATIC void mp_ip4_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED ip4_addr_t *data = (ip4_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_addr: dest[0] = mp_obj_new_int_from_uint(data->addr); break; // converting from u32_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_addr: data->addr = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to u32_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_ip4_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct ip4_addr_t");
}

STATIC const mp_obj_dict_t mp_ip4_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_ip4_addr_t_type,
    MP_QSTR_ip4_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_ip4_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_ip4_addr_t_attr,
    locals_dict, &mp_ip4_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_ip4_addr_t_type()
{
    return &mp_ip4_addr_t_type;
}
    

/*
 * Struct ip_addr_u_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_ip_addr_u_addr_t_type();

STATIC inline void* mp_write_ptr_ip_addr_u_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_ip_addr_u_addr_t_type()));
    return (ip_addr_u_addr_t*)self->data;
}

#define mp_write_ip_addr_u_addr_t(struct_obj) *((ip_addr_u_addr_t*)mp_write_ptr_ip_addr_u_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_ip_addr_u_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_ip_addr_u_addr_t_type(), field);
}

#define mp_read_ip_addr_u_addr_t(field) mp_read_ptr_ip_addr_u_addr_t(copy_buffer(&field, sizeof(ip_addr_u_addr_t)))
#define mp_read_byref_ip_addr_u_addr_t(field) mp_read_ptr_ip_addr_u_addr_t(&field)

STATIC void mp_ip_addr_u_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED ip_addr_u_addr_t *data = (ip_addr_u_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ip6: dest[0] = mp_read_byref_ip6_addr_t(data->ip6); break; // converting from ip6_addr_t;
            case MP_QSTR_ip4: dest[0] = mp_read_byref_ip4_addr_t(data->ip4); break; // converting from ip4_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ip6: data->ip6 = mp_write_ip6_addr_t(dest[1]); break; // converting to ip6_addr_t;
                case MP_QSTR_ip4: data->ip4 = mp_write_ip4_addr_t(dest[1]); break; // converting to ip4_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_ip_addr_u_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct ip_addr_u_addr_t");
}

STATIC const mp_obj_dict_t mp_ip_addr_u_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_ip_addr_u_addr_t_type,
    MP_QSTR_ip_addr_u_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_ip_addr_u_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_ip_addr_u_addr_t_attr,
    locals_dict, &mp_ip_addr_u_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_ip_addr_u_addr_t_type()
{
    return &mp_ip_addr_u_addr_t_type;
}
    

/*
 * Struct ip_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_ip_addr_t_type();

STATIC inline void* mp_write_ptr_ip_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_ip_addr_t_type()));
    return (ip_addr_t*)self->data;
}

#define mp_write_ip_addr_t(struct_obj) *((ip_addr_t*)mp_write_ptr_ip_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_ip_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_ip_addr_t_type(), field);
}

#define mp_read_ip_addr_t(field) mp_read_ptr_ip_addr_t(copy_buffer(&field, sizeof(ip_addr_t)))
#define mp_read_byref_ip_addr_t(field) mp_read_ptr_ip_addr_t(&field)

STATIC void mp_ip_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED ip_addr_t *data = (ip_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_u_addr: dest[0] = mp_read_byref_ip_addr_u_addr_t(data->u_addr); break; // converting from ip_addr_u_addr_t;
            case MP_QSTR_type: dest[0] = mp_obj_new_int_from_uint(data->type); break; // converting from u8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_u_addr: data->u_addr = mp_write_ip_addr_u_addr_t(dest[1]); break; // converting to ip_addr_u_addr_t;
                case MP_QSTR_type: data->type = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to u8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_ip_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct ip_addr_t");
}

STATIC const mp_obj_dict_t mp_ip_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_ip_addr_t_type,
    MP_QSTR_ip_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_ip_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_ip_addr_t_attr,
    locals_dict, &mp_ip_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_ip_addr_t_type()
{
    return &mp_ip_addr_t_type;
}
    

/*
 * espidf ip_addr_any_type global definitions
 */

STATIC const mp_lv_struct_t mp_ip_addr_any_type = {
    { &mp_ip_addr_t_type },
    (ip_addr_t*)&ip_addr_any_type
};
    

/*
 * espidf ip_addr_any global definitions
 */

STATIC const mp_lv_struct_t mp_ip_addr_any = {
    { &mp_ip_addr_t_type },
    (ip_addr_t*)&ip_addr_any
};
    

/*
 * espidf ip_addr_broadcast global definitions
 */

STATIC const mp_lv_struct_t mp_ip_addr_broadcast = {
    { &mp_ip_addr_t_type },
    (ip_addr_t*)&ip_addr_broadcast
};
    

/*
 * espidf ip6_addr_any global definitions
 */

STATIC const mp_lv_struct_t mp_ip6_addr_any = {
    { &mp_ip_addr_t_type },
    (ip_addr_t*)&ip6_addr_any
};
    

/*
 * espidf _nesting global definitions
 */

STATIC const mp_lv_struct_t mp__nesting = {
    { &mp__lv_mp_int_wrapper_type },
    (int*)&_nesting
};
    
typedef __typeof__( ((esp_ip_addr_t*)(0))->u_addr ) esp_ip_addr_u_addr_t;

/*
 * Array convertors for uint32_t [4]
 */

GENMPY_UNUSED STATIC uint32_t *mp_arr_to_uint32_t___4__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    uint32_t *lv_arr = (uint32_t*)m_malloc(len * sizeof(uint32_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint32_t)mp_obj_get_int(item);
    }
    return (uint32_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_uint32_t___4__(uint32_t *arr)
{
    mp_obj_t obj_arr[4];
    for (size_t i=0; i<4; i++){
        obj_arr[i] = mp_obj_new_int_from_uint(arr[i]);
    }
    return mp_obj_new_list(4, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct esp_ip6_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_ip6_addr_t_type();

STATIC inline void* mp_write_ptr_esp_ip6_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_ip6_addr_t_type()));
    return (esp_ip6_addr_t*)self->data;
}

#define mp_write_esp_ip6_addr_t(struct_obj) *((esp_ip6_addr_t*)mp_write_ptr_esp_ip6_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_ip6_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_ip6_addr_t_type(), field);
}

#define mp_read_esp_ip6_addr_t(field) mp_read_ptr_esp_ip6_addr_t(copy_buffer(&field, sizeof(esp_ip6_addr_t)))
#define mp_read_byref_esp_ip6_addr_t(field) mp_read_ptr_esp_ip6_addr_t(&field)

STATIC void mp_esp_ip6_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_ip6_addr_t *data = (esp_ip6_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_addr: dest[0] = mp_arr_from_uint32_t___4__(data->addr); break; // converting from uint32_t [4];
            case MP_QSTR_zone: dest[0] = mp_obj_new_int_from_uint(data->zone); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_addr: memcpy((void*)&data->addr, mp_arr_to_uint32_t___4__(dest[1]), sizeof(uint32_t)*4); break; // converting to uint32_t [4];
                case MP_QSTR_zone: data->zone = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_ip6_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_ip6_addr_t");
}

STATIC const mp_obj_dict_t mp_esp_ip6_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_ip6_addr_t_type,
    MP_QSTR_esp_ip6_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_ip6_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_ip6_addr_t_attr,
    locals_dict, &mp_esp_ip6_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_ip6_addr_t_type()
{
    return &mp_esp_ip6_addr_t_type;
}
    

/*
 * Struct esp_ip4_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_ip4_addr_t_type();

STATIC inline void* mp_write_ptr_esp_ip4_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_ip4_addr_t_type()));
    return (esp_ip4_addr_t*)self->data;
}

#define mp_write_esp_ip4_addr_t(struct_obj) *((esp_ip4_addr_t*)mp_write_ptr_esp_ip4_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_ip4_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_ip4_addr_t_type(), field);
}

#define mp_read_esp_ip4_addr_t(field) mp_read_ptr_esp_ip4_addr_t(copy_buffer(&field, sizeof(esp_ip4_addr_t)))
#define mp_read_byref_esp_ip4_addr_t(field) mp_read_ptr_esp_ip4_addr_t(&field)

STATIC void mp_esp_ip4_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_ip4_addr_t *data = (esp_ip4_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_addr: dest[0] = mp_obj_new_int_from_uint(data->addr); break; // converting from uint32_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_addr: data->addr = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_ip4_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_ip4_addr_t");
}

STATIC const mp_obj_dict_t mp_esp_ip4_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_ip4_addr_t_type,
    MP_QSTR_esp_ip4_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_ip4_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_ip4_addr_t_attr,
    locals_dict, &mp_esp_ip4_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_ip4_addr_t_type()
{
    return &mp_esp_ip4_addr_t_type;
}
    

/*
 * Struct esp_ip_addr_u_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_ip_addr_u_addr_t_type();

STATIC inline void* mp_write_ptr_esp_ip_addr_u_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_ip_addr_u_addr_t_type()));
    return (esp_ip_addr_u_addr_t*)self->data;
}

#define mp_write_esp_ip_addr_u_addr_t(struct_obj) *((esp_ip_addr_u_addr_t*)mp_write_ptr_esp_ip_addr_u_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_ip_addr_u_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_ip_addr_u_addr_t_type(), field);
}

#define mp_read_esp_ip_addr_u_addr_t(field) mp_read_ptr_esp_ip_addr_u_addr_t(copy_buffer(&field, sizeof(esp_ip_addr_u_addr_t)))
#define mp_read_byref_esp_ip_addr_u_addr_t(field) mp_read_ptr_esp_ip_addr_u_addr_t(&field)

STATIC void mp_esp_ip_addr_u_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_ip_addr_u_addr_t *data = (esp_ip_addr_u_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ip6: dest[0] = mp_read_byref_esp_ip6_addr_t(data->ip6); break; // converting from esp_ip6_addr_t;
            case MP_QSTR_ip4: dest[0] = mp_read_byref_esp_ip4_addr_t(data->ip4); break; // converting from esp_ip4_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ip6: data->ip6 = mp_write_esp_ip6_addr_t(dest[1]); break; // converting to esp_ip6_addr_t;
                case MP_QSTR_ip4: data->ip4 = mp_write_esp_ip4_addr_t(dest[1]); break; // converting to esp_ip4_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_ip_addr_u_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_ip_addr_u_addr_t");
}

STATIC const mp_obj_dict_t mp_esp_ip_addr_u_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_ip_addr_u_addr_t_type,
    MP_QSTR_esp_ip_addr_u_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_ip_addr_u_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_ip_addr_u_addr_t_attr,
    locals_dict, &mp_esp_ip_addr_u_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_ip_addr_u_addr_t_type()
{
    return &mp_esp_ip_addr_u_addr_t_type;
}
    

/*
 * Struct esp_ip_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_ip_addr_t_type();

STATIC inline void* mp_write_ptr_esp_ip_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_ip_addr_t_type()));
    return (esp_ip_addr_t*)self->data;
}

#define mp_write_esp_ip_addr_t(struct_obj) *((esp_ip_addr_t*)mp_write_ptr_esp_ip_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_ip_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_ip_addr_t_type(), field);
}

#define mp_read_esp_ip_addr_t(field) mp_read_ptr_esp_ip_addr_t(copy_buffer(&field, sizeof(esp_ip_addr_t)))
#define mp_read_byref_esp_ip_addr_t(field) mp_read_ptr_esp_ip_addr_t(&field)

STATIC void mp_esp_ip_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_ip_addr_t *data = (esp_ip_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_u_addr: dest[0] = mp_read_byref_esp_ip_addr_u_addr_t(data->u_addr); break; // converting from esp_ip_addr_u_addr_t;
            case MP_QSTR_type: dest[0] = mp_obj_new_int_from_uint(data->type); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_u_addr: data->u_addr = mp_write_esp_ip_addr_u_addr_t(dest[1]); break; // converting to esp_ip_addr_u_addr_t;
                case MP_QSTR_type: data->type = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_ip_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_ip_addr_t");
}

STATIC const mp_obj_dict_t mp_esp_ip_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_ip_addr_t_type,
    MP_QSTR_esp_ip_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_ip_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_ip_addr_t_attr,
    locals_dict, &mp_esp_ip_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_ip_addr_t_type()
{
    return &mp_esp_ip_addr_t_type;
}
    

/*
 * Struct eth_phy_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_eth_phy_config_t_type();

STATIC inline void* mp_write_ptr_eth_phy_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_eth_phy_config_t_type()));
    return (eth_phy_config_t*)self->data;
}

#define mp_write_eth_phy_config_t(struct_obj) *((eth_phy_config_t*)mp_write_ptr_eth_phy_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_eth_phy_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_eth_phy_config_t_type(), field);
}

#define mp_read_eth_phy_config_t(field) mp_read_ptr_eth_phy_config_t(copy_buffer(&field, sizeof(eth_phy_config_t)))
#define mp_read_byref_eth_phy_config_t(field) mp_read_ptr_eth_phy_config_t(&field)

STATIC void mp_eth_phy_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED eth_phy_config_t *data = (eth_phy_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_phy_addr: dest[0] = mp_obj_new_int(data->phy_addr); break; // converting from int32_t;
            case MP_QSTR_reset_timeout_ms: dest[0] = mp_obj_new_int_from_uint(data->reset_timeout_ms); break; // converting from uint32_t;
            case MP_QSTR_autonego_timeout_ms: dest[0] = mp_obj_new_int_from_uint(data->autonego_timeout_ms); break; // converting from uint32_t;
            case MP_QSTR_reset_gpio_num: dest[0] = mp_obj_new_int(data->reset_gpio_num); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_phy_addr: data->phy_addr = (int32_t)mp_obj_get_int(dest[1]); break; // converting to int32_t;
                case MP_QSTR_reset_timeout_ms: data->reset_timeout_ms = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_autonego_timeout_ms: data->autonego_timeout_ms = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_reset_gpio_num: data->reset_gpio_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_eth_phy_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct eth_phy_config_t");
}

STATIC const mp_obj_dict_t mp_eth_phy_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_eth_phy_config_t_type,
    MP_QSTR_eth_phy_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_eth_phy_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_eth_phy_config_t_attr,
    locals_dict, &mp_eth_phy_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_eth_phy_config_t_type()
{
    return &mp_eth_phy_config_t_type;
}
    
#define funcptr_http_event_handle_cb NULL


/*
 * Struct esp_http_client_event_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_http_client_event_t_type();

STATIC inline void* mp_write_ptr_esp_http_client_event_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_http_client_event_t_type()));
    return (esp_http_client_event_t*)self->data;
}

#define mp_write_esp_http_client_event_t(struct_obj) *((esp_http_client_event_t*)mp_write_ptr_esp_http_client_event_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_http_client_event_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_http_client_event_t_type(), field);
}

#define mp_read_esp_http_client_event_t(field) mp_read_ptr_esp_http_client_event_t(copy_buffer(&field, sizeof(esp_http_client_event_t)))
#define mp_read_byref_esp_http_client_event_t(field) mp_read_ptr_esp_http_client_event_t(&field)

STATIC void mp_esp_http_client_event_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_http_client_event_t *data = (esp_http_client_event_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_event_id: dest[0] = mp_obj_new_int(data->event_id); break; // converting from esp_http_client_event_id_t;
            case MP_QSTR_client: dest[0] = ptr_to_mp(data->client); break; // converting from esp_http_client_handle_t;
            case MP_QSTR_data: dest[0] = ptr_to_mp((void*)data->data); break; // converting from void *;
            case MP_QSTR_data_len: dest[0] = mp_obj_new_int(data->data_len); break; // converting from int;
            case MP_QSTR_user_data: dest[0] = ptr_to_mp((void*)data->user_data); break; // converting from void *;
            case MP_QSTR_header_key: dest[0] = convert_to_str((void*)data->header_key); break; // converting from char *;
            case MP_QSTR_header_value: dest[0] = convert_to_str((void*)data->header_value); break; // converting from char *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_event_id: data->event_id = (int)mp_obj_get_int(dest[1]); break; // converting to esp_http_client_event_id_t;
                case MP_QSTR_client: data->client = mp_to_ptr(dest[1]); break; // converting to esp_http_client_handle_t;
                case MP_QSTR_data: data->data = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_data_len: data->data_len = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_user_data: data->user_data = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_header_key: data->header_key = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_header_value: data->header_value = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_http_client_event_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_http_client_event_t");
}

STATIC const mp_obj_dict_t mp_esp_http_client_event_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_http_client_event_t_type,
    MP_QSTR_esp_http_client_event_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_http_client_event_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_http_client_event_t_attr,
    locals_dict, &mp_esp_http_client_event_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_http_client_event_t_type()
{
    return &mp_esp_http_client_event_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t http_event_handle_cb(esp_http_client_event_t *evt)
 */

STATIC mp_obj_t mp_funcptr_http_event_handle_cb(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_event_t *evt = mp_write_ptr_esp_http_client_event_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_event_t *))lv_func_ptr)(evt);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_http_event_handle_cb_mpobj, 1, mp_funcptr_http_event_handle_cb, funcptr_http_event_handle_cb);
    
STATIC inline mp_obj_t mp_lv_funcptr_http_event_handle_cb(void *func){ return mp_lv_funcptr(&mp_funcptr_http_event_handle_cb_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_http_client_config_t_event_handler_callback'
 * http_event_handle_cb event_handler
 */
    
#define funcptr_crt_bundle_attach NULL


/*
 * espidf extension definition for:
 * esp_err_t crt_bundle_attach(void *conf)
 */

STATIC mp_obj_t mp_funcptr_crt_bundle_attach(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *conf = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(void *))lv_func_ptr)(conf);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_crt_bundle_attach_mpobj, 1, mp_funcptr_crt_bundle_attach, funcptr_crt_bundle_attach);
    
STATIC inline mp_obj_t mp_lv_funcptr_crt_bundle_attach(void *func){ return mp_lv_funcptr(&mp_funcptr_crt_bundle_attach_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_http_client_config_t_crt_bundle_attach_callback'
 * esp_err_t (*crt_bundle_attach)(void *conf)
 */
    

/*
 * Struct esp_http_client_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_http_client_config_t_type();

STATIC inline void* mp_write_ptr_esp_http_client_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_http_client_config_t_type()));
    return (esp_http_client_config_t*)self->data;
}

#define mp_write_esp_http_client_config_t(struct_obj) *((esp_http_client_config_t*)mp_write_ptr_esp_http_client_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_http_client_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_http_client_config_t_type(), field);
}

#define mp_read_esp_http_client_config_t(field) mp_read_ptr_esp_http_client_config_t(copy_buffer(&field, sizeof(esp_http_client_config_t)))
#define mp_read_byref_esp_http_client_config_t(field) mp_read_ptr_esp_http_client_config_t(&field)

STATIC void mp_esp_http_client_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_http_client_config_t *data = (esp_http_client_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_url: dest[0] = convert_to_str((void*)data->url); break; // converting from char *;
            case MP_QSTR_host: dest[0] = convert_to_str((void*)data->host); break; // converting from char *;
            case MP_QSTR_port: dest[0] = mp_obj_new_int(data->port); break; // converting from int;
            case MP_QSTR_username: dest[0] = convert_to_str((void*)data->username); break; // converting from char *;
            case MP_QSTR_password: dest[0] = convert_to_str((void*)data->password); break; // converting from char *;
            case MP_QSTR_auth_type: dest[0] = mp_obj_new_int(data->auth_type); break; // converting from esp_http_client_auth_type_t;
            case MP_QSTR_path: dest[0] = convert_to_str((void*)data->path); break; // converting from char *;
            case MP_QSTR_query: dest[0] = convert_to_str((void*)data->query); break; // converting from char *;
            case MP_QSTR_cert_pem: dest[0] = convert_to_str((void*)data->cert_pem); break; // converting from char *;
            case MP_QSTR_cert_len: dest[0] = mp_obj_new_int_from_uint(data->cert_len); break; // converting from size_t;
            case MP_QSTR_client_cert_pem: dest[0] = convert_to_str((void*)data->client_cert_pem); break; // converting from char *;
            case MP_QSTR_client_cert_len: dest[0] = mp_obj_new_int_from_uint(data->client_cert_len); break; // converting from size_t;
            case MP_QSTR_client_key_pem: dest[0] = convert_to_str((void*)data->client_key_pem); break; // converting from char *;
            case MP_QSTR_client_key_len: dest[0] = mp_obj_new_int_from_uint(data->client_key_len); break; // converting from size_t;
            case MP_QSTR_client_key_password: dest[0] = convert_to_str((void*)data->client_key_password); break; // converting from char *;
            case MP_QSTR_client_key_password_len: dest[0] = mp_obj_new_int_from_uint(data->client_key_password_len); break; // converting from size_t;
            case MP_QSTR_user_agent: dest[0] = convert_to_str((void*)data->user_agent); break; // converting from char *;
            case MP_QSTR_method: dest[0] = mp_obj_new_int(data->method); break; // converting from esp_http_client_method_t;
            case MP_QSTR_timeout_ms: dest[0] = mp_obj_new_int(data->timeout_ms); break; // converting from int;
            case MP_QSTR_disable_auto_redirect: dest[0] = convert_to_bool(data->disable_auto_redirect); break; // converting from bool;
            case MP_QSTR_max_redirection_count: dest[0] = mp_obj_new_int(data->max_redirection_count); break; // converting from int;
            case MP_QSTR_max_authorization_retries: dest[0] = mp_obj_new_int(data->max_authorization_retries); break; // converting from int;
            case MP_QSTR_event_handler: dest[0] = mp_lv_funcptr(&mp_funcptr_http_event_handle_cb_mpobj, data->event_handler, NULL ,MP_QSTR_esp_http_client_config_t_event_handler, NULL); break; // converting from callback http_event_handle_cb;
            case MP_QSTR_transport_type: dest[0] = mp_obj_new_int(data->transport_type); break; // converting from esp_http_client_transport_t;
            case MP_QSTR_buffer_size: dest[0] = mp_obj_new_int(data->buffer_size); break; // converting from int;
            case MP_QSTR_buffer_size_tx: dest[0] = mp_obj_new_int(data->buffer_size_tx); break; // converting from int;
            case MP_QSTR_user_data: dest[0] = ptr_to_mp((void*)data->user_data); break; // converting from void *;
            case MP_QSTR_is_async: dest[0] = convert_to_bool(data->is_async); break; // converting from bool;
            case MP_QSTR_use_global_ca_store: dest[0] = convert_to_bool(data->use_global_ca_store); break; // converting from bool;
            case MP_QSTR_skip_cert_common_name_check: dest[0] = convert_to_bool(data->skip_cert_common_name_check); break; // converting from bool;
            case MP_QSTR_crt_bundle_attach: dest[0] = mp_lv_funcptr(&mp_funcptr_crt_bundle_attach_mpobj, (void*)data->crt_bundle_attach, NULL ,MP_QSTR_esp_http_client_config_t_crt_bundle_attach, NULL); break; // converting from callback esp_err_t (*)(void *conf);
            case MP_QSTR_keep_alive_enable: dest[0] = convert_to_bool(data->keep_alive_enable); break; // converting from bool;
            case MP_QSTR_keep_alive_idle: dest[0] = mp_obj_new_int(data->keep_alive_idle); break; // converting from int;
            case MP_QSTR_keep_alive_interval: dest[0] = mp_obj_new_int(data->keep_alive_interval); break; // converting from int;
            case MP_QSTR_keep_alive_count: dest[0] = mp_obj_new_int(data->keep_alive_count); break; // converting from int;
            case MP_QSTR_if_name: dest[0] = ptr_to_mp((void*)data->if_name); break; // converting from struct ifreq *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_url: data->url = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_host: data->host = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_port: data->port = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_username: data->username = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_password: data->password = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_auth_type: data->auth_type = (int)mp_obj_get_int(dest[1]); break; // converting to esp_http_client_auth_type_t;
                case MP_QSTR_path: data->path = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_query: data->query = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_cert_pem: data->cert_pem = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_cert_len: data->cert_len = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_client_cert_pem: data->client_cert_pem = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_client_cert_len: data->client_cert_len = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_client_key_pem: data->client_key_pem = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_client_key_len: data->client_key_len = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_client_key_password: data->client_key_password = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_client_key_password_len: data->client_key_password_len = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_user_agent: data->user_agent = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_method: data->method = (int)mp_obj_get_int(dest[1]); break; // converting to esp_http_client_method_t;
                case MP_QSTR_timeout_ms: data->timeout_ms = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_disable_auto_redirect: data->disable_auto_redirect = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_max_redirection_count: data->max_redirection_count = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_max_authorization_retries: data->max_authorization_retries = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_event_handler: data->event_handler = mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_http_client_config_t_event_handler, NULL, NULL, NULL, NULL); break; // converting to callback http_event_handle_cb;
                case MP_QSTR_transport_type: data->transport_type = (int)mp_obj_get_int(dest[1]); break; // converting to esp_http_client_transport_t;
                case MP_QSTR_buffer_size: data->buffer_size = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_buffer_size_tx: data->buffer_size_tx = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_user_data: data->user_data = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_is_async: data->is_async = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_use_global_ca_store: data->use_global_ca_store = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_skip_cert_common_name_check: data->skip_cert_common_name_check = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_crt_bundle_attach: data->crt_bundle_attach = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_http_client_config_t_crt_bundle_attach, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(void *conf);
                case MP_QSTR_keep_alive_enable: data->keep_alive_enable = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_keep_alive_idle: data->keep_alive_idle = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_keep_alive_interval: data->keep_alive_interval = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_keep_alive_count: data->keep_alive_count = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_if_name: data->if_name = (void*)mp_to_ptr(dest[1]); break; // converting to struct ifreq *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_http_client_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_http_client_config_t");
}

STATIC const mp_obj_dict_t mp_esp_http_client_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_http_client_config_t_type,
    MP_QSTR_esp_http_client_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_http_client_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_http_client_config_t_attr,
    locals_dict, &mp_esp_http_client_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_http_client_config_t_type()
{
    return &mp_esp_http_client_config_t_type;
}
    

/*
 * Array convertors for uint8_t [4]
 */

GENMPY_UNUSED STATIC uint8_t *mp_arr_to_uint8_t___4__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    uint8_t *lv_arr = (uint8_t*)m_malloc(len * sizeof(uint8_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint8_t)mp_obj_get_int(item);
    }
    return (uint8_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_uint8_t___4__(uint8_t *arr)
{
    mp_obj_t obj_arr[4];
    for (size_t i=0; i<4; i++){
        obj_arr[i] = mp_obj_new_int_from_uint(arr[i]);
    }
    return mp_obj_new_list(4, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct spi_transaction_t
 */

STATIC inline const mp_obj_type_t *get_mp_spi_transaction_t_type();

STATIC inline void* mp_write_ptr_spi_transaction_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_spi_transaction_t_type()));
    return (struct spi_transaction_t*)self->data;
}

#define mp_write_spi_transaction_t(struct_obj) *((struct spi_transaction_t*)mp_write_ptr_spi_transaction_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_spi_transaction_t(void *field)
{
    return lv_to_mp_struct(get_mp_spi_transaction_t_type(), field);
}

#define mp_read_spi_transaction_t(field) mp_read_ptr_spi_transaction_t(copy_buffer(&field, sizeof(struct spi_transaction_t)))
#define mp_read_byref_spi_transaction_t(field) mp_read_ptr_spi_transaction_t(&field)

STATIC void mp_spi_transaction_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED struct spi_transaction_t *data = (struct spi_transaction_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from uint32_t;
            case MP_QSTR_cmd: dest[0] = mp_obj_new_int_from_uint(data->cmd); break; // converting from uint16_t;
            case MP_QSTR_addr: dest[0] = mp_obj_new_int_from_ull(data->addr); break; // converting from uint64_t;
            case MP_QSTR_length: dest[0] = mp_obj_new_int_from_uint(data->length); break; // converting from size_t;
            case MP_QSTR_rxlength: dest[0] = mp_obj_new_int_from_uint(data->rxlength); break; // converting from size_t;
            case MP_QSTR_user: dest[0] = ptr_to_mp((void*)data->user); break; // converting from void *;
            case MP_QSTR_tx_buffer: dest[0] = ptr_to_mp((void*)data->tx_buffer); break; // converting from void *;
            case MP_QSTR_tx_data: dest[0] = mp_arr_from_uint8_t___4__(data->tx_data); break; // converting from uint8_t [4];
            case MP_QSTR_rx_buffer: dest[0] = ptr_to_mp((void*)data->rx_buffer); break; // converting from void *;
            case MP_QSTR_rx_data: dest[0] = mp_arr_from_uint8_t___4__(data->rx_data); break; // converting from uint8_t [4];
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_flags: data->flags = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_cmd: data->cmd = (uint16_t)mp_obj_get_int(dest[1]); break; // converting to uint16_t;
                case MP_QSTR_addr: data->addr = (uint64_t)mp_obj_get_ull(dest[1]); break; // converting to uint64_t;
                case MP_QSTR_length: data->length = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_rxlength: data->rxlength = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_user: data->user = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_tx_buffer: data->tx_buffer = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_tx_data: memcpy((void*)&data->tx_data, mp_arr_to_uint8_t___4__(dest[1]), sizeof(uint8_t)*4); break; // converting to uint8_t [4];
                case MP_QSTR_rx_buffer: data->rx_buffer = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_rx_data: memcpy((void*)&data->rx_data, mp_arr_to_uint8_t___4__(dest[1]), sizeof(uint8_t)*4); break; // converting to uint8_t [4];
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_spi_transaction_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct spi_transaction_t");
}

STATIC const mp_obj_dict_t mp_spi_transaction_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_spi_transaction_t_type,
    MP_QSTR_spi_transaction_t,
    MP_TYPE_FLAG_NONE,
    print, mp_spi_transaction_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_spi_transaction_t_attr,
    locals_dict, &mp_spi_transaction_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_spi_transaction_t_type()
{
    return &mp_spi_transaction_t_type;
}
    

/*
 * Struct spi_transaction_ext_t
 */

STATIC inline const mp_obj_type_t *get_mp_spi_transaction_ext_t_type();

STATIC inline void* mp_write_ptr_spi_transaction_ext_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_spi_transaction_ext_t_type()));
    return (spi_transaction_ext_t*)self->data;
}

#define mp_write_spi_transaction_ext_t(struct_obj) *((spi_transaction_ext_t*)mp_write_ptr_spi_transaction_ext_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_spi_transaction_ext_t(void *field)
{
    return lv_to_mp_struct(get_mp_spi_transaction_ext_t_type(), field);
}

#define mp_read_spi_transaction_ext_t(field) mp_read_ptr_spi_transaction_ext_t(copy_buffer(&field, sizeof(spi_transaction_ext_t)))
#define mp_read_byref_spi_transaction_ext_t(field) mp_read_ptr_spi_transaction_ext_t(&field)

STATIC void mp_spi_transaction_ext_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED spi_transaction_ext_t *data = (spi_transaction_ext_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_base: dest[0] = mp_read_byref_spi_transaction_t(data->base); break; // converting from spi_transaction_t;
            case MP_QSTR_command_bits: dest[0] = mp_obj_new_int_from_uint(data->command_bits); break; // converting from uint8_t;
            case MP_QSTR_address_bits: dest[0] = mp_obj_new_int_from_uint(data->address_bits); break; // converting from uint8_t;
            case MP_QSTR_dummy_bits: dest[0] = mp_obj_new_int_from_uint(data->dummy_bits); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_base: data->base = mp_write_spi_transaction_t(dest[1]); break; // converting to spi_transaction_t;
                case MP_QSTR_command_bits: data->command_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_address_bits: data->address_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_dummy_bits: data->dummy_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_spi_transaction_ext_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct spi_transaction_ext_t");
}

STATIC const mp_obj_dict_t mp_spi_transaction_ext_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_spi_transaction_ext_t_type,
    MP_QSTR_spi_transaction_ext_t,
    MP_TYPE_FLAG_NONE,
    print, mp_spi_transaction_ext_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_spi_transaction_ext_t_attr,
    locals_dict, &mp_spi_transaction_ext_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_spi_transaction_ext_t_type()
{
    return &mp_spi_transaction_ext_t_type;
}
    
#define funcptr_gpio_intr_handler_fn_t NULL


/*
 * espidf extension definition for:
 * void gpio_intr_handler_fn_t(uint32_t intr_mask, bool high, void *arg)
 */

STATIC mp_obj_t mp_funcptr_gpio_intr_handler_fn_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t intr_mask = (uint32_t)mp_obj_get_int(mp_args[0]);
    bool high = mp_obj_is_true(mp_args[1]);
    void *arg = mp_to_ptr(mp_args[2]);
    ((void (*)(uint32_t, bool, void *))lv_func_ptr)(intr_mask, high, arg);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_gpio_intr_handler_fn_t_mpobj, 3, mp_funcptr_gpio_intr_handler_fn_t, funcptr_gpio_intr_handler_fn_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_gpio_intr_handler_fn_t(void *func){ return mp_lv_funcptr(&mp_funcptr_gpio_intr_handler_fn_t_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Struct gpio_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_gpio_config_t_type();

STATIC inline void* mp_write_ptr_gpio_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_gpio_config_t_type()));
    return (gpio_config_t*)self->data;
}

#define mp_write_gpio_config_t(struct_obj) *((gpio_config_t*)mp_write_ptr_gpio_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_gpio_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_gpio_config_t_type(), field);
}

#define mp_read_gpio_config_t(field) mp_read_ptr_gpio_config_t(copy_buffer(&field, sizeof(gpio_config_t)))
#define mp_read_byref_gpio_config_t(field) mp_read_ptr_gpio_config_t(&field)

STATIC void mp_gpio_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED gpio_config_t *data = (gpio_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_pin_bit_mask: dest[0] = mp_obj_new_int_from_ull(data->pin_bit_mask); break; // converting from uint64_t;
            case MP_QSTR_mode: dest[0] = mp_obj_new_int(data->mode); break; // converting from gpio_mode_t;
            case MP_QSTR_pull_up_en: dest[0] = mp_obj_new_int(data->pull_up_en); break; // converting from gpio_pullup_t;
            case MP_QSTR_pull_down_en: dest[0] = mp_obj_new_int(data->pull_down_en); break; // converting from gpio_pulldown_t;
            case MP_QSTR_intr_type: dest[0] = mp_obj_new_int(data->intr_type); break; // converting from gpio_int_type_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_pin_bit_mask: data->pin_bit_mask = (uint64_t)mp_obj_get_ull(dest[1]); break; // converting to uint64_t;
                case MP_QSTR_mode: data->mode = (int)mp_obj_get_int(dest[1]); break; // converting to gpio_mode_t;
                case MP_QSTR_pull_up_en: data->pull_up_en = (int)mp_obj_get_int(dest[1]); break; // converting to gpio_pullup_t;
                case MP_QSTR_pull_down_en: data->pull_down_en = (int)mp_obj_get_int(dest[1]); break; // converting to gpio_pulldown_t;
                case MP_QSTR_intr_type: data->intr_type = (int)mp_obj_get_int(dest[1]); break; // converting to gpio_int_type_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_gpio_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct gpio_config_t");
}

STATIC const mp_obj_dict_t mp_gpio_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_gpio_config_t_type,
    MP_QSTR_gpio_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_gpio_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_gpio_config_t_attr,
    locals_dict, &mp_gpio_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_gpio_config_t_type()
{
    return &mp_gpio_config_t_type;
}
    
#define funcptr_fn NULL


/*
 * espidf extension definition for:
 * void fn(void *)
 */

STATIC mp_obj_t mp_funcptr_fn(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *arg0 = mp_to_ptr(mp_args[0]);
    ((void (*)(void *))lv_func_ptr)(arg0);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_fn_mpobj, 1, mp_funcptr_fn, funcptr_fn);
    
STATIC inline mp_obj_t mp_lv_funcptr_fn(void *func){ return mp_lv_funcptr(&mp_funcptr_fn_mpobj, func, NULL, MP_QSTR_, NULL); }

#define funcptr_esp_alloc_failed_hook_t NULL


/*
 * espidf extension definition for:
 * void esp_alloc_failed_hook_t(size_t size, uint32_t caps, const char *function_name)
 */

STATIC mp_obj_t mp_funcptr_esp_alloc_failed_hook_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    size_t size = (size_t)mp_obj_get_int(mp_args[0]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[1]);
    const char *function_name = (const char *)(char*)convert_from_str(mp_args[2]);
    ((void (*)(size_t, uint32_t, const char *))lv_func_ptr)(size, caps, function_name);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_esp_alloc_failed_hook_t_mpobj, 3, mp_funcptr_esp_alloc_failed_hook_t, funcptr_esp_alloc_failed_hook_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_esp_alloc_failed_hook_t(void *func){ return mp_lv_funcptr(&mp_funcptr_esp_alloc_failed_hook_t_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Struct multi_heap_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_multi_heap_info_t_type();

STATIC inline void* mp_write_ptr_multi_heap_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_multi_heap_info_t_type()));
    return (multi_heap_info_t*)self->data;
}

#define mp_write_multi_heap_info_t(struct_obj) *((multi_heap_info_t*)mp_write_ptr_multi_heap_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_multi_heap_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_multi_heap_info_t_type(), field);
}

#define mp_read_multi_heap_info_t(field) mp_read_ptr_multi_heap_info_t(copy_buffer(&field, sizeof(multi_heap_info_t)))
#define mp_read_byref_multi_heap_info_t(field) mp_read_ptr_multi_heap_info_t(&field)

STATIC void mp_multi_heap_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED multi_heap_info_t *data = (multi_heap_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_total_free_bytes: dest[0] = mp_obj_new_int_from_uint(data->total_free_bytes); break; // converting from size_t;
            case MP_QSTR_total_allocated_bytes: dest[0] = mp_obj_new_int_from_uint(data->total_allocated_bytes); break; // converting from size_t;
            case MP_QSTR_largest_free_block: dest[0] = mp_obj_new_int_from_uint(data->largest_free_block); break; // converting from size_t;
            case MP_QSTR_minimum_free_bytes: dest[0] = mp_obj_new_int_from_uint(data->minimum_free_bytes); break; // converting from size_t;
            case MP_QSTR_allocated_blocks: dest[0] = mp_obj_new_int_from_uint(data->allocated_blocks); break; // converting from size_t;
            case MP_QSTR_free_blocks: dest[0] = mp_obj_new_int_from_uint(data->free_blocks); break; // converting from size_t;
            case MP_QSTR_total_blocks: dest[0] = mp_obj_new_int_from_uint(data->total_blocks); break; // converting from size_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_total_free_bytes: data->total_free_bytes = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_total_allocated_bytes: data->total_allocated_bytes = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_largest_free_block: data->largest_free_block = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_minimum_free_bytes: data->minimum_free_bytes = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_allocated_blocks: data->allocated_blocks = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_free_blocks: data->free_blocks = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_total_blocks: data->total_blocks = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_multi_heap_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct multi_heap_info_t");
}

STATIC const mp_obj_dict_t mp_multi_heap_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_multi_heap_info_t_type,
    MP_QSTR_multi_heap_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_multi_heap_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_multi_heap_info_t_attr,
    locals_dict, &mp_multi_heap_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_multi_heap_info_t_type()
{
    return &mp_multi_heap_info_t_type;
}
    
#define funcptr_vprintf_like_t NULL


/*
 * Function NOT generated:
 * Missing conversion to va_list
 * int vprintf_like_t(const char *, va_list)
 */
    

/*
 * Struct adc_digi_init_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_adc_digi_init_config_t_type();

STATIC inline void* mp_write_ptr_adc_digi_init_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_adc_digi_init_config_t_type()));
    return (adc_digi_init_config_t*)self->data;
}

#define mp_write_adc_digi_init_config_t(struct_obj) *((adc_digi_init_config_t*)mp_write_ptr_adc_digi_init_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_adc_digi_init_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_adc_digi_init_config_t_type(), field);
}

#define mp_read_adc_digi_init_config_t(field) mp_read_ptr_adc_digi_init_config_t(copy_buffer(&field, sizeof(adc_digi_init_config_t)))
#define mp_read_byref_adc_digi_init_config_t(field) mp_read_ptr_adc_digi_init_config_t(&field)

STATIC void mp_adc_digi_init_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED adc_digi_init_config_t *data = (adc_digi_init_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_max_store_buf_size: dest[0] = mp_obj_new_int_from_uint(data->max_store_buf_size); break; // converting from uint32_t;
            case MP_QSTR_conv_num_each_intr: dest[0] = mp_obj_new_int_from_uint(data->conv_num_each_intr); break; // converting from uint32_t;
            case MP_QSTR_adc1_chan_mask: dest[0] = mp_obj_new_int_from_uint(data->adc1_chan_mask); break; // converting from uint32_t;
            case MP_QSTR_adc2_chan_mask: dest[0] = mp_obj_new_int_from_uint(data->adc2_chan_mask); break; // converting from uint32_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_max_store_buf_size: data->max_store_buf_size = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_conv_num_each_intr: data->conv_num_each_intr = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_adc1_chan_mask: data->adc1_chan_mask = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_adc2_chan_mask: data->adc2_chan_mask = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_adc_digi_init_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct adc_digi_init_config_t");
}

STATIC const mp_obj_dict_t mp_adc_digi_init_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_adc_digi_init_config_t_type,
    MP_QSTR_adc_digi_init_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_adc_digi_init_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_adc_digi_init_config_t_attr,
    locals_dict, &mp_adc_digi_init_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_adc_digi_init_config_t_type()
{
    return &mp_adc_digi_init_config_t_type;
}
    

/*
 * Struct adc_digi_pattern_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_adc_digi_pattern_config_t_type();

STATIC inline void* mp_write_ptr_adc_digi_pattern_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_adc_digi_pattern_config_t_type()));
    return (adc_digi_pattern_config_t*)self->data;
}

#define mp_write_adc_digi_pattern_config_t(struct_obj) *((adc_digi_pattern_config_t*)mp_write_ptr_adc_digi_pattern_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_adc_digi_pattern_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_adc_digi_pattern_config_t_type(), field);
}

#define mp_read_adc_digi_pattern_config_t(field) mp_read_ptr_adc_digi_pattern_config_t(copy_buffer(&field, sizeof(adc_digi_pattern_config_t)))
#define mp_read_byref_adc_digi_pattern_config_t(field) mp_read_ptr_adc_digi_pattern_config_t(&field)

STATIC void mp_adc_digi_pattern_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED adc_digi_pattern_config_t *data = (adc_digi_pattern_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_atten: dest[0] = mp_obj_new_int_from_uint(data->atten); break; // converting from uint8_t;
            case MP_QSTR_channel: dest[0] = mp_obj_new_int_from_uint(data->channel); break; // converting from uint8_t;
            case MP_QSTR_unit: dest[0] = mp_obj_new_int_from_uint(data->unit); break; // converting from uint8_t;
            case MP_QSTR_bit_width: dest[0] = mp_obj_new_int_from_uint(data->bit_width); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_atten: data->atten = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_channel: data->channel = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_unit: data->unit = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_bit_width: data->bit_width = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_adc_digi_pattern_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct adc_digi_pattern_config_t");
}

STATIC const mp_obj_dict_t mp_adc_digi_pattern_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_adc_digi_pattern_config_t_type,
    MP_QSTR_adc_digi_pattern_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_adc_digi_pattern_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_adc_digi_pattern_config_t_attr,
    locals_dict, &mp_adc_digi_pattern_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_adc_digi_pattern_config_t_type()
{
    return &mp_adc_digi_pattern_config_t_type;
}
    

/*
 * Struct adc_digi_configuration_t
 */

STATIC inline const mp_obj_type_t *get_mp_adc_digi_configuration_t_type();

STATIC inline void* mp_write_ptr_adc_digi_configuration_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_adc_digi_configuration_t_type()));
    return (adc_digi_configuration_t*)self->data;
}

#define mp_write_adc_digi_configuration_t(struct_obj) *((adc_digi_configuration_t*)mp_write_ptr_adc_digi_configuration_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_adc_digi_configuration_t(void *field)
{
    return lv_to_mp_struct(get_mp_adc_digi_configuration_t_type(), field);
}

#define mp_read_adc_digi_configuration_t(field) mp_read_ptr_adc_digi_configuration_t(copy_buffer(&field, sizeof(adc_digi_configuration_t)))
#define mp_read_byref_adc_digi_configuration_t(field) mp_read_ptr_adc_digi_configuration_t(&field)

STATIC void mp_adc_digi_configuration_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED adc_digi_configuration_t *data = (adc_digi_configuration_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_conv_limit_en: dest[0] = convert_to_bool(data->conv_limit_en); break; // converting from bool;
            case MP_QSTR_conv_limit_num: dest[0] = mp_obj_new_int_from_uint(data->conv_limit_num); break; // converting from uint32_t;
            case MP_QSTR_pattern_num: dest[0] = mp_obj_new_int_from_uint(data->pattern_num); break; // converting from uint32_t;
            case MP_QSTR_adc_pattern: dest[0] = mp_read_ptr_adc_digi_pattern_config_t((void*)data->adc_pattern); break; // converting from adc_digi_pattern_config_t *;
            case MP_QSTR_sample_freq_hz: dest[0] = mp_obj_new_int_from_uint(data->sample_freq_hz); break; // converting from uint32_t;
            case MP_QSTR_conv_mode: dest[0] = mp_obj_new_int(data->conv_mode); break; // converting from adc_digi_convert_mode_t;
            case MP_QSTR_format: dest[0] = mp_obj_new_int(data->format); break; // converting from adc_digi_output_format_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_conv_limit_en: data->conv_limit_en = mp_obj_is_true(dest[1]); break; // converting to bool;
                case MP_QSTR_conv_limit_num: data->conv_limit_num = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_pattern_num: data->pattern_num = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_adc_pattern: data->adc_pattern = (void*)mp_write_ptr_adc_digi_pattern_config_t(dest[1]); break; // converting to adc_digi_pattern_config_t *;
                case MP_QSTR_sample_freq_hz: data->sample_freq_hz = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_conv_mode: data->conv_mode = (int)mp_obj_get_int(dest[1]); break; // converting to adc_digi_convert_mode_t;
                case MP_QSTR_format: data->format = (int)mp_obj_get_int(dest[1]); break; // converting to adc_digi_output_format_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_adc_digi_configuration_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct adc_digi_configuration_t");
}

STATIC const mp_obj_dict_t mp_adc_digi_configuration_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_adc_digi_configuration_t_type,
    MP_QSTR_adc_digi_configuration_t,
    MP_TYPE_FLAG_NONE,
    print, mp_adc_digi_configuration_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_adc_digi_configuration_t_attr,
    locals_dict, &mp_adc_digi_configuration_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_adc_digi_configuration_t_type()
{
    return &mp_adc_digi_configuration_t_type;
}
    

/*
 * Struct pcnt_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_pcnt_config_t_type();

STATIC inline void* mp_write_ptr_pcnt_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_pcnt_config_t_type()));
    return (pcnt_config_t*)self->data;
}

#define mp_write_pcnt_config_t(struct_obj) *((pcnt_config_t*)mp_write_ptr_pcnt_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_pcnt_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_pcnt_config_t_type(), field);
}

#define mp_read_pcnt_config_t(field) mp_read_ptr_pcnt_config_t(copy_buffer(&field, sizeof(pcnt_config_t)))
#define mp_read_byref_pcnt_config_t(field) mp_read_ptr_pcnt_config_t(&field)

STATIC void mp_pcnt_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED pcnt_config_t *data = (pcnt_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_pulse_gpio_num: dest[0] = mp_obj_new_int(data->pulse_gpio_num); break; // converting from int;
            case MP_QSTR_ctrl_gpio_num: dest[0] = mp_obj_new_int(data->ctrl_gpio_num); break; // converting from int;
            case MP_QSTR_lctrl_mode: dest[0] = mp_obj_new_int(data->lctrl_mode); break; // converting from pcnt_ctrl_mode_t;
            case MP_QSTR_hctrl_mode: dest[0] = mp_obj_new_int(data->hctrl_mode); break; // converting from pcnt_ctrl_mode_t;
            case MP_QSTR_pos_mode: dest[0] = mp_obj_new_int(data->pos_mode); break; // converting from pcnt_count_mode_t;
            case MP_QSTR_neg_mode: dest[0] = mp_obj_new_int(data->neg_mode); break; // converting from pcnt_count_mode_t;
            case MP_QSTR_counter_h_lim: dest[0] = mp_obj_new_int(data->counter_h_lim); break; // converting from int16_t;
            case MP_QSTR_counter_l_lim: dest[0] = mp_obj_new_int(data->counter_l_lim); break; // converting from int16_t;
            case MP_QSTR_unit: dest[0] = mp_obj_new_int(data->unit); break; // converting from pcnt_unit_t;
            case MP_QSTR_channel: dest[0] = mp_obj_new_int(data->channel); break; // converting from pcnt_channel_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_pulse_gpio_num: data->pulse_gpio_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_ctrl_gpio_num: data->ctrl_gpio_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_lctrl_mode: data->lctrl_mode = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_ctrl_mode_t;
                case MP_QSTR_hctrl_mode: data->hctrl_mode = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_ctrl_mode_t;
                case MP_QSTR_pos_mode: data->pos_mode = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_count_mode_t;
                case MP_QSTR_neg_mode: data->neg_mode = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_count_mode_t;
                case MP_QSTR_counter_h_lim: data->counter_h_lim = (int16_t)mp_obj_get_int(dest[1]); break; // converting to int16_t;
                case MP_QSTR_counter_l_lim: data->counter_l_lim = (int16_t)mp_obj_get_int(dest[1]); break; // converting to int16_t;
                case MP_QSTR_unit: data->unit = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_unit_t;
                case MP_QSTR_channel: data->channel = (int)mp_obj_get_int(dest[1]); break; // converting to pcnt_channel_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_pcnt_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct pcnt_config_t");
}

STATIC const mp_obj_dict_t mp_pcnt_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_pcnt_config_t_type,
    MP_QSTR_pcnt_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_pcnt_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_pcnt_config_t_attr,
    locals_dict, &mp_pcnt_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_pcnt_config_t_type()
{
    return &mp_pcnt_config_t_type;
}
    
#define funcptr_phy_reg_read NULL


/*
 * espidf extension definition for:
 * esp_err_t phy_reg_read(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */

STATIC mp_obj_t mp_funcptr_phy_reg_read(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mediator_t *eth = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t *reg_value = mp_array_to_u32ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mediator_t *, uint32_t, uint32_t, uint32_t *))lv_func_ptr)(eth, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_phy_reg_read_mpobj, 4, mp_funcptr_phy_reg_read, funcptr_phy_reg_read);
    
STATIC inline mp_obj_t mp_lv_funcptr_phy_reg_read(void *func){ return mp_lv_funcptr(&mp_funcptr_phy_reg_read_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mediator_t_phy_reg_read_callback'
 * esp_err_t (*phy_reg_read)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    
#define funcptr_phy_reg_write NULL


/*
 * espidf extension definition for:
 * esp_err_t phy_reg_write(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */

STATIC mp_obj_t mp_funcptr_phy_reg_write(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mediator_t *eth = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t reg_value = (uint32_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mediator_t *, uint32_t, uint32_t, uint32_t))lv_func_ptr)(eth, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_phy_reg_write_mpobj, 4, mp_funcptr_phy_reg_write, funcptr_phy_reg_write);
    
STATIC inline mp_obj_t mp_lv_funcptr_phy_reg_write(void *func){ return mp_lv_funcptr(&mp_funcptr_phy_reg_write_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mediator_t_phy_reg_write_callback'
 * esp_err_t (*phy_reg_write)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    
#define funcptr_stack_input NULL


/*
 * espidf extension definition for:
 * esp_err_t stack_input(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length)
 */

STATIC mp_obj_t mp_funcptr_stack_input(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mediator_t *eth = mp_to_ptr(mp_args[0]);
    uint8_t *buffer = mp_array_to_u8ptr(mp_args[1]);
    uint32_t length = (uint32_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mediator_t *, uint8_t *, uint32_t))lv_func_ptr)(eth, buffer, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_stack_input_mpobj, 3, mp_funcptr_stack_input, funcptr_stack_input);
    
STATIC inline mp_obj_t mp_lv_funcptr_stack_input(void *func){ return mp_lv_funcptr(&mp_funcptr_stack_input_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mediator_t_stack_input_callback'
 * esp_err_t (*stack_input)(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length)
 */
    
#define funcptr_on_state_changed NULL


/*
 * espidf extension definition for:
 * esp_err_t on_state_changed(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args)
 */

STATIC mp_obj_t mp_funcptr_on_state_changed(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mediator_t *eth = mp_to_ptr(mp_args[0]);
    esp_eth_state_t state = (int)mp_obj_get_int(mp_args[1]);
    void *args = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mediator_t *, esp_eth_state_t, void *))lv_func_ptr)(eth, state, args);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_on_state_changed_mpobj, 3, mp_funcptr_on_state_changed, funcptr_on_state_changed);
    
STATIC inline mp_obj_t mp_lv_funcptr_on_state_changed(void *func){ return mp_lv_funcptr(&mp_funcptr_on_state_changed_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mediator_t_on_state_changed_callback'
 * esp_err_t (*on_state_changed)(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args)
 */
    

/*
 * Struct esp_eth_mediator_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_eth_mediator_t_type();

STATIC inline void* mp_write_ptr_esp_eth_mediator_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_eth_mediator_t_type()));
    return (esp_eth_mediator_t*)self->data;
}

#define mp_write_esp_eth_mediator_t(struct_obj) *((esp_eth_mediator_t*)mp_write_ptr_esp_eth_mediator_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_eth_mediator_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_eth_mediator_t_type(), field);
}

#define mp_read_esp_eth_mediator_t(field) mp_read_ptr_esp_eth_mediator_t(copy_buffer(&field, sizeof(esp_eth_mediator_t)))
#define mp_read_byref_esp_eth_mediator_t(field) mp_read_ptr_esp_eth_mediator_t(&field)

STATIC void mp_esp_eth_mediator_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_eth_mediator_t *data = (esp_eth_mediator_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_phy_reg_read: dest[0] = mp_lv_funcptr(&mp_funcptr_phy_reg_read_mpobj, (void*)data->phy_reg_read, NULL ,MP_QSTR_esp_eth_mediator_t_phy_reg_read, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
            case MP_QSTR_phy_reg_write: dest[0] = mp_lv_funcptr(&mp_funcptr_phy_reg_write_mpobj, (void*)data->phy_reg_write, NULL ,MP_QSTR_esp_eth_mediator_t_phy_reg_write, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
            case MP_QSTR_stack_input: dest[0] = mp_lv_funcptr(&mp_funcptr_stack_input_mpobj, (void*)data->stack_input, NULL ,MP_QSTR_esp_eth_mediator_t_stack_input, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length);
            case MP_QSTR_on_state_changed: dest[0] = mp_lv_funcptr(&mp_funcptr_on_state_changed_mpobj, (void*)data->on_state_changed, NULL ,MP_QSTR_esp_eth_mediator_t_on_state_changed, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args);
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_phy_reg_read: data->phy_reg_read = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mediator_t_phy_reg_read, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
                case MP_QSTR_phy_reg_write: data->phy_reg_write = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mediator_t_phy_reg_write, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
                case MP_QSTR_stack_input: data->stack_input = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mediator_t_stack_input, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length);
                case MP_QSTR_on_state_changed: data->on_state_changed = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mediator_t_on_state_changed, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args);
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_eth_mediator_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_eth_mediator_t");
}

STATIC const mp_obj_dict_t mp_esp_eth_mediator_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_eth_mediator_t_type,
    MP_QSTR_esp_eth_mediator_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_eth_mediator_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_eth_mediator_t_attr,
    locals_dict, &mp_esp_eth_mediator_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_eth_mediator_t_type()
{
    return &mp_esp_eth_mediator_t_type;
}
    
typedef __typeof__( ((eth_mac_clock_config_t*)(0))->mii ) eth_mac_clock_config_mii_t;

/*
 * Struct eth_mac_clock_config_mii_t
 */

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_mii_t_type();

STATIC inline void* mp_write_ptr_eth_mac_clock_config_mii_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_eth_mac_clock_config_mii_t_type()));
    return (eth_mac_clock_config_mii_t*)self->data;
}

#define mp_write_eth_mac_clock_config_mii_t(struct_obj) *((eth_mac_clock_config_mii_t*)mp_write_ptr_eth_mac_clock_config_mii_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_eth_mac_clock_config_mii_t(void *field)
{
    return lv_to_mp_struct(get_mp_eth_mac_clock_config_mii_t_type(), field);
}

#define mp_read_eth_mac_clock_config_mii_t(field) mp_read_ptr_eth_mac_clock_config_mii_t(copy_buffer(&field, sizeof(eth_mac_clock_config_mii_t)))
#define mp_read_byref_eth_mac_clock_config_mii_t(field) mp_read_ptr_eth_mac_clock_config_mii_t(&field)

STATIC void mp_eth_mac_clock_config_mii_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED eth_mac_clock_config_mii_t *data = (eth_mac_clock_config_mii_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_eth_mac_clock_config_mii_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct eth_mac_clock_config_mii_t");
}

STATIC const mp_obj_dict_t mp_eth_mac_clock_config_mii_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_eth_mac_clock_config_mii_t_type,
    MP_QSTR_eth_mac_clock_config_mii_t,
    MP_TYPE_FLAG_NONE,
    print, mp_eth_mac_clock_config_mii_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_eth_mac_clock_config_mii_t_attr,
    locals_dict, &mp_eth_mac_clock_config_mii_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_mii_t_type()
{
    return &mp_eth_mac_clock_config_mii_t_type;
}
    
typedef __typeof__( ((eth_mac_clock_config_t*)(0))->rmii ) eth_mac_clock_config_rmii_t;

/*
 * Struct eth_mac_clock_config_rmii_t
 */

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_rmii_t_type();

STATIC inline void* mp_write_ptr_eth_mac_clock_config_rmii_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_eth_mac_clock_config_rmii_t_type()));
    return (eth_mac_clock_config_rmii_t*)self->data;
}

#define mp_write_eth_mac_clock_config_rmii_t(struct_obj) *((eth_mac_clock_config_rmii_t*)mp_write_ptr_eth_mac_clock_config_rmii_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_eth_mac_clock_config_rmii_t(void *field)
{
    return lv_to_mp_struct(get_mp_eth_mac_clock_config_rmii_t_type(), field);
}

#define mp_read_eth_mac_clock_config_rmii_t(field) mp_read_ptr_eth_mac_clock_config_rmii_t(copy_buffer(&field, sizeof(eth_mac_clock_config_rmii_t)))
#define mp_read_byref_eth_mac_clock_config_rmii_t(field) mp_read_ptr_eth_mac_clock_config_rmii_t(&field)

STATIC void mp_eth_mac_clock_config_rmii_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED eth_mac_clock_config_rmii_t *data = (eth_mac_clock_config_rmii_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_clock_mode: dest[0] = mp_obj_new_int(data->clock_mode); break; // converting from emac_rmii_clock_mode_t;
            case MP_QSTR_clock_gpio: dest[0] = mp_obj_new_int(data->clock_gpio); break; // converting from emac_rmii_clock_gpio_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_clock_mode: data->clock_mode = (int)mp_obj_get_int(dest[1]); break; // converting to emac_rmii_clock_mode_t;
                case MP_QSTR_clock_gpio: data->clock_gpio = (int)mp_obj_get_int(dest[1]); break; // converting to emac_rmii_clock_gpio_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_eth_mac_clock_config_rmii_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct eth_mac_clock_config_rmii_t");
}

STATIC const mp_obj_dict_t mp_eth_mac_clock_config_rmii_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_eth_mac_clock_config_rmii_t_type,
    MP_QSTR_eth_mac_clock_config_rmii_t,
    MP_TYPE_FLAG_NONE,
    print, mp_eth_mac_clock_config_rmii_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_eth_mac_clock_config_rmii_t_attr,
    locals_dict, &mp_eth_mac_clock_config_rmii_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_rmii_t_type()
{
    return &mp_eth_mac_clock_config_rmii_t_type;
}
    

/*
 * Struct eth_mac_clock_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_t_type();

STATIC inline void* mp_write_ptr_eth_mac_clock_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_eth_mac_clock_config_t_type()));
    return (eth_mac_clock_config_t*)self->data;
}

#define mp_write_eth_mac_clock_config_t(struct_obj) *((eth_mac_clock_config_t*)mp_write_ptr_eth_mac_clock_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_eth_mac_clock_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_eth_mac_clock_config_t_type(), field);
}

#define mp_read_eth_mac_clock_config_t(field) mp_read_ptr_eth_mac_clock_config_t(copy_buffer(&field, sizeof(eth_mac_clock_config_t)))
#define mp_read_byref_eth_mac_clock_config_t(field) mp_read_ptr_eth_mac_clock_config_t(&field)

STATIC void mp_eth_mac_clock_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED eth_mac_clock_config_t *data = (eth_mac_clock_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mii: dest[0] = mp_read_byref_eth_mac_clock_config_mii_t(data->mii); break; // converting from eth_mac_clock_config_mii_t;
            case MP_QSTR_rmii: dest[0] = mp_read_byref_eth_mac_clock_config_rmii_t(data->rmii); break; // converting from eth_mac_clock_config_rmii_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mii: data->mii = mp_write_eth_mac_clock_config_mii_t(dest[1]); break; // converting to eth_mac_clock_config_mii_t;
                case MP_QSTR_rmii: data->rmii = mp_write_eth_mac_clock_config_rmii_t(dest[1]); break; // converting to eth_mac_clock_config_rmii_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_eth_mac_clock_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct eth_mac_clock_config_t");
}

STATIC const mp_obj_dict_t mp_eth_mac_clock_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_eth_mac_clock_config_t_type,
    MP_QSTR_eth_mac_clock_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_eth_mac_clock_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_eth_mac_clock_config_t_attr,
    locals_dict, &mp_eth_mac_clock_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_eth_mac_clock_config_t_type()
{
    return &mp_eth_mac_clock_config_t_type;
}
    

/*
 * Struct eth_mac_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_eth_mac_config_t_type();

STATIC inline void* mp_write_ptr_eth_mac_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_eth_mac_config_t_type()));
    return (eth_mac_config_t*)self->data;
}

#define mp_write_eth_mac_config_t(struct_obj) *((eth_mac_config_t*)mp_write_ptr_eth_mac_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_eth_mac_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_eth_mac_config_t_type(), field);
}

#define mp_read_eth_mac_config_t(field) mp_read_ptr_eth_mac_config_t(copy_buffer(&field, sizeof(eth_mac_config_t)))
#define mp_read_byref_eth_mac_config_t(field) mp_read_ptr_eth_mac_config_t(&field)

STATIC void mp_eth_mac_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED eth_mac_config_t *data = (eth_mac_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_sw_reset_timeout_ms: dest[0] = mp_obj_new_int_from_uint(data->sw_reset_timeout_ms); break; // converting from uint32_t;
            case MP_QSTR_rx_task_stack_size: dest[0] = mp_obj_new_int_from_uint(data->rx_task_stack_size); break; // converting from uint32_t;
            case MP_QSTR_rx_task_prio: dest[0] = mp_obj_new_int_from_uint(data->rx_task_prio); break; // converting from uint32_t;
            case MP_QSTR_smi_mdc_gpio_num: dest[0] = mp_obj_new_int(data->smi_mdc_gpio_num); break; // converting from int;
            case MP_QSTR_smi_mdio_gpio_num: dest[0] = mp_obj_new_int(data->smi_mdio_gpio_num); break; // converting from int;
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from uint32_t;
            case MP_QSTR_interface: dest[0] = mp_obj_new_int(data->interface); break; // converting from eth_data_interface_t;
            case MP_QSTR_clock_config: dest[0] = mp_read_byref_eth_mac_clock_config_t(data->clock_config); break; // converting from eth_mac_clock_config_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_sw_reset_timeout_ms: data->sw_reset_timeout_ms = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_rx_task_stack_size: data->rx_task_stack_size = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_rx_task_prio: data->rx_task_prio = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_smi_mdc_gpio_num: data->smi_mdc_gpio_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_smi_mdio_gpio_num: data->smi_mdio_gpio_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_flags: data->flags = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_interface: data->interface = (int)mp_obj_get_int(dest[1]); break; // converting to eth_data_interface_t;
                case MP_QSTR_clock_config: data->clock_config = mp_write_eth_mac_clock_config_t(dest[1]); break; // converting to eth_mac_clock_config_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_eth_mac_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct eth_mac_config_t");
}

STATIC const mp_obj_dict_t mp_eth_mac_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_eth_mac_config_t_type,
    MP_QSTR_eth_mac_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_eth_mac_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_eth_mac_config_t_attr,
    locals_dict, &mp_eth_mac_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_eth_mac_config_t_type()
{
    return &mp_eth_mac_config_t_type;
}
    
#define funcptr_set_mediator NULL


/*
 * espidf extension definition for:
 * esp_err_t set_mediator(esp_eth_mac_t *mac, esp_eth_mediator_t *eth)
 */

STATIC mp_obj_t mp_funcptr_set_mediator(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    esp_eth_mediator_t *eth = mp_write_ptr_esp_eth_mediator_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, esp_eth_mediator_t *))lv_func_ptr)(mac, eth);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_mediator_mpobj, 2, mp_funcptr_set_mediator, funcptr_set_mediator);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_mediator(void *func){ return mp_lv_funcptr(&mp_funcptr_set_mediator_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_mediator_callback'
 * esp_err_t (*set_mediator)(esp_eth_mac_t *mac, esp_eth_mediator_t *eth)
 */
    
#define funcptr_init NULL


/*
 * espidf extension definition for:
 * esp_err_t init(esp_eth_mac_t *mac)
 */

STATIC mp_obj_t mp_funcptr_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *))lv_func_ptr)(mac);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_init_mpobj, 1, mp_funcptr_init, funcptr_init);
    
STATIC inline mp_obj_t mp_lv_funcptr_init(void *func){ return mp_lv_funcptr(&mp_funcptr_init_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_init_callback'
 * esp_err_t (*init)(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_deinit_callback'
 * esp_err_t (*deinit)(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_start_callback'
 * esp_err_t (*start)(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_stop_callback'
 * esp_err_t (*stop)(esp_eth_mac_t *mac)
 */
    
#define funcptr_transmit NULL


/*
 * espidf extension definition for:
 * esp_err_t transmit(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length)
 */

STATIC mp_obj_t mp_funcptr_transmit(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint8_t *buf = mp_array_to_u8ptr(mp_args[1]);
    uint32_t length = (uint32_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint8_t *, uint32_t))lv_func_ptr)(mac, buf, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_transmit_mpobj, 3, mp_funcptr_transmit, funcptr_transmit);
    
STATIC inline mp_obj_t mp_lv_funcptr_transmit(void *func){ return mp_lv_funcptr(&mp_funcptr_transmit_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_transmit_callback'
 * esp_err_t (*transmit)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length)
 */
    
#define funcptr_receive NULL


/*
 * espidf extension definition for:
 * esp_err_t receive(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length)
 */

STATIC mp_obj_t mp_funcptr_receive(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint8_t *buf = mp_array_to_u8ptr(mp_args[1]);
    uint32_t *length = mp_array_to_u32ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint8_t *, uint32_t *))lv_func_ptr)(mac, buf, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_receive_mpobj, 3, mp_funcptr_receive, funcptr_receive);
    
STATIC inline mp_obj_t mp_lv_funcptr_receive(void *func){ return mp_lv_funcptr(&mp_funcptr_receive_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_receive_callback'
 * esp_err_t (*receive)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length)
 */
    
#define funcptr_read_phy_reg NULL


/*
 * espidf extension definition for:
 * esp_err_t read_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */

STATIC mp_obj_t mp_funcptr_read_phy_reg(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t *reg_value = mp_array_to_u32ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint32_t, uint32_t, uint32_t *))lv_func_ptr)(mac, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_read_phy_reg_mpobj, 4, mp_funcptr_read_phy_reg, funcptr_read_phy_reg);
    
STATIC inline mp_obj_t mp_lv_funcptr_read_phy_reg(void *func){ return mp_lv_funcptr(&mp_funcptr_read_phy_reg_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_read_phy_reg_callback'
 * esp_err_t (*read_phy_reg)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    
#define funcptr_write_phy_reg NULL


/*
 * espidf extension definition for:
 * esp_err_t write_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */

STATIC mp_obj_t mp_funcptr_write_phy_reg(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t reg_value = (uint32_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint32_t, uint32_t, uint32_t))lv_func_ptr)(mac, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_write_phy_reg_mpobj, 4, mp_funcptr_write_phy_reg, funcptr_write_phy_reg);
    
STATIC inline mp_obj_t mp_lv_funcptr_write_phy_reg(void *func){ return mp_lv_funcptr(&mp_funcptr_write_phy_reg_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_write_phy_reg_callback'
 * esp_err_t (*write_phy_reg)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    
#define funcptr_set_addr NULL


/*
 * espidf extension definition for:
 * esp_err_t set_addr(esp_eth_mac_t *mac, uint8_t *addr)
 */

STATIC mp_obj_t mp_funcptr_set_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint8_t *addr = mp_array_to_u8ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint8_t *))lv_func_ptr)(mac, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_addr_mpobj, 2, mp_funcptr_set_addr, funcptr_set_addr);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_addr(void *func){ return mp_lv_funcptr(&mp_funcptr_set_addr_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_addr_callback'
 * esp_err_t (*set_addr)(esp_eth_mac_t *mac, uint8_t *addr)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_get_addr_callback'
 * esp_err_t (*get_addr)(esp_eth_mac_t *mac, uint8_t *addr)
 */
    
#define funcptr_set_speed NULL


/*
 * espidf extension definition for:
 * esp_err_t set_speed(esp_eth_mac_t *mac, eth_speed_t speed)
 */

STATIC mp_obj_t mp_funcptr_set_speed(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    eth_speed_t speed = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, eth_speed_t))lv_func_ptr)(mac, speed);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_speed_mpobj, 2, mp_funcptr_set_speed, funcptr_set_speed);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_speed(void *func){ return mp_lv_funcptr(&mp_funcptr_set_speed_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_speed_callback'
 * esp_err_t (*set_speed)(esp_eth_mac_t *mac, eth_speed_t speed)
 */
    
#define funcptr_set_duplex NULL


/*
 * espidf extension definition for:
 * esp_err_t set_duplex(esp_eth_mac_t *mac, eth_duplex_t duplex)
 */

STATIC mp_obj_t mp_funcptr_set_duplex(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    eth_duplex_t duplex = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, eth_duplex_t))lv_func_ptr)(mac, duplex);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_duplex_mpobj, 2, mp_funcptr_set_duplex, funcptr_set_duplex);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_duplex(void *func){ return mp_lv_funcptr(&mp_funcptr_set_duplex_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_duplex_callback'
 * esp_err_t (*set_duplex)(esp_eth_mac_t *mac, eth_duplex_t duplex)
 */
    
#define funcptr_set_link NULL


/*
 * espidf extension definition for:
 * esp_err_t set_link(esp_eth_mac_t *mac, eth_link_t link)
 */

STATIC mp_obj_t mp_funcptr_set_link(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    eth_link_t link = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, eth_link_t))lv_func_ptr)(mac, link);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_link_mpobj, 2, mp_funcptr_set_link, funcptr_set_link);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_link(void *func){ return mp_lv_funcptr(&mp_funcptr_set_link_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_link_callback'
 * esp_err_t (*set_link)(esp_eth_mac_t *mac, eth_link_t link)
 */
    
#define funcptr_set_promiscuous NULL


/*
 * espidf extension definition for:
 * esp_err_t set_promiscuous(esp_eth_mac_t *mac, bool enable)
 */

STATIC mp_obj_t mp_funcptr_set_promiscuous(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    bool enable = mp_obj_is_true(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, bool))lv_func_ptr)(mac, enable);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_promiscuous_mpobj, 2, mp_funcptr_set_promiscuous, funcptr_set_promiscuous);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_promiscuous(void *func){ return mp_lv_funcptr(&mp_funcptr_set_promiscuous_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_promiscuous_callback'
 * esp_err_t (*set_promiscuous)(esp_eth_mac_t *mac, bool enable)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_enable_flow_ctrl_callback'
 * esp_err_t (*enable_flow_ctrl)(esp_eth_mac_t *mac, bool enable)
 */
    
#define funcptr_set_peer_pause_ability NULL


/*
 * espidf extension definition for:
 * esp_err_t set_peer_pause_ability(esp_eth_mac_t *mac, uint32_t ability)
 */

STATIC mp_obj_t mp_funcptr_set_peer_pause_ability(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mac_t *mac = mp_to_ptr(mp_args[0]);
    uint32_t ability = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mac_t *, uint32_t))lv_func_ptr)(mac, ability);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_peer_pause_ability_mpobj, 2, mp_funcptr_set_peer_pause_ability, funcptr_set_peer_pause_ability);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_peer_pause_ability(void *func){ return mp_lv_funcptr(&mp_funcptr_set_peer_pause_ability_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_set_peer_pause_ability_callback'
 * esp_err_t (*set_peer_pause_ability)(esp_eth_mac_t *mac, uint32_t ability)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_mac_t_del_callback'
 * esp_err_t (*del)(esp_eth_mac_t *mac)
 */
    

/*
 * Struct esp_eth_mac_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_eth_mac_t_type();

STATIC inline void* mp_write_ptr_esp_eth_mac_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_eth_mac_t_type()));
    return (esp_eth_mac_t*)self->data;
}

#define mp_write_esp_eth_mac_t(struct_obj) *((esp_eth_mac_t*)mp_write_ptr_esp_eth_mac_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_eth_mac_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_eth_mac_t_type(), field);
}

#define mp_read_esp_eth_mac_t(field) mp_read_ptr_esp_eth_mac_t(copy_buffer(&field, sizeof(esp_eth_mac_t)))
#define mp_read_byref_esp_eth_mac_t(field) mp_read_ptr_esp_eth_mac_t(&field)

STATIC void mp_esp_eth_mac_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_eth_mac_t *data = (esp_eth_mac_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_set_mediator: dest[0] = mp_lv_funcptr(&mp_funcptr_set_mediator_mpobj, (void*)data->set_mediator, NULL ,MP_QSTR_esp_eth_mac_t_set_mediator, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, esp_eth_mediator_t *eth);
            case MP_QSTR_init: dest[0] = mp_lv_funcptr(&mp_funcptr_init_mpobj, (void*)data->init, NULL ,MP_QSTR_esp_eth_mac_t_init, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac);
            case MP_QSTR_deinit: dest[0] = mp_lv_funcptr(&mp_funcptr_init_mpobj, (void*)data->deinit, NULL ,MP_QSTR_esp_eth_mac_t_deinit, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac);
            case MP_QSTR_start: dest[0] = mp_lv_funcptr(&mp_funcptr_init_mpobj, (void*)data->start, NULL ,MP_QSTR_esp_eth_mac_t_start, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac);
            case MP_QSTR_stop: dest[0] = mp_lv_funcptr(&mp_funcptr_init_mpobj, (void*)data->stop, NULL ,MP_QSTR_esp_eth_mac_t_stop, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac);
            case MP_QSTR_transmit: dest[0] = mp_lv_funcptr(&mp_funcptr_transmit_mpobj, (void*)data->transmit, NULL ,MP_QSTR_esp_eth_mac_t_transmit, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length);
            case MP_QSTR_receive: dest[0] = mp_lv_funcptr(&mp_funcptr_receive_mpobj, (void*)data->receive, NULL ,MP_QSTR_esp_eth_mac_t_receive, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length);
            case MP_QSTR_read_phy_reg: dest[0] = mp_lv_funcptr(&mp_funcptr_read_phy_reg_mpobj, (void*)data->read_phy_reg, NULL ,MP_QSTR_esp_eth_mac_t_read_phy_reg, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
            case MP_QSTR_write_phy_reg: dest[0] = mp_lv_funcptr(&mp_funcptr_write_phy_reg_mpobj, (void*)data->write_phy_reg, NULL ,MP_QSTR_esp_eth_mac_t_write_phy_reg, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
            case MP_QSTR_set_addr: dest[0] = mp_lv_funcptr(&mp_funcptr_set_addr_mpobj, (void*)data->set_addr, NULL ,MP_QSTR_esp_eth_mac_t_set_addr, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *addr);
            case MP_QSTR_get_addr: dest[0] = mp_lv_funcptr(&mp_funcptr_set_addr_mpobj, (void*)data->get_addr, NULL ,MP_QSTR_esp_eth_mac_t_get_addr, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *addr);
            case MP_QSTR_set_speed: dest[0] = mp_lv_funcptr(&mp_funcptr_set_speed_mpobj, (void*)data->set_speed, NULL ,MP_QSTR_esp_eth_mac_t_set_speed, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, eth_speed_t speed);
            case MP_QSTR_set_duplex: dest[0] = mp_lv_funcptr(&mp_funcptr_set_duplex_mpobj, (void*)data->set_duplex, NULL ,MP_QSTR_esp_eth_mac_t_set_duplex, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, eth_duplex_t duplex);
            case MP_QSTR_set_link: dest[0] = mp_lv_funcptr(&mp_funcptr_set_link_mpobj, (void*)data->set_link, NULL ,MP_QSTR_esp_eth_mac_t_set_link, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, eth_link_t link);
            case MP_QSTR_set_promiscuous: dest[0] = mp_lv_funcptr(&mp_funcptr_set_promiscuous_mpobj, (void*)data->set_promiscuous, NULL ,MP_QSTR_esp_eth_mac_t_set_promiscuous, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, bool enable);
            case MP_QSTR_enable_flow_ctrl: dest[0] = mp_lv_funcptr(&mp_funcptr_set_promiscuous_mpobj, (void*)data->enable_flow_ctrl, NULL ,MP_QSTR_esp_eth_mac_t_enable_flow_ctrl, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, bool enable);
            case MP_QSTR_set_peer_pause_ability: dest[0] = mp_lv_funcptr(&mp_funcptr_set_peer_pause_ability_mpobj, (void*)data->set_peer_pause_ability, NULL ,MP_QSTR_esp_eth_mac_t_set_peer_pause_ability, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t ability);
            case MP_QSTR__del: dest[0] = mp_lv_funcptr(&mp_funcptr_init_mpobj, (void*)data->del, NULL ,MP_QSTR_esp_eth_mac_t__del, NULL); break; // converting from callback esp_err_t (*)(esp_eth_mac_t *mac);
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_set_mediator: data->set_mediator = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_mediator, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, esp_eth_mediator_t *eth);
                case MP_QSTR_init: data->init = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_init, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac);
                case MP_QSTR_deinit: data->deinit = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_deinit, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac);
                case MP_QSTR_start: data->start = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_start, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac);
                case MP_QSTR_stop: data->stop = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_stop, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac);
                case MP_QSTR_transmit: data->transmit = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_transmit, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length);
                case MP_QSTR_receive: data->receive = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_receive, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length);
                case MP_QSTR_read_phy_reg: data->read_phy_reg = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_read_phy_reg, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
                case MP_QSTR_write_phy_reg: data->write_phy_reg = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_write_phy_reg, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
                case MP_QSTR_set_addr: data->set_addr = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_addr, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *addr);
                case MP_QSTR_get_addr: data->get_addr = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_get_addr, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint8_t *addr);
                case MP_QSTR_set_speed: data->set_speed = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_speed, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, eth_speed_t speed);
                case MP_QSTR_set_duplex: data->set_duplex = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_duplex, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, eth_duplex_t duplex);
                case MP_QSTR_set_link: data->set_link = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_link, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, eth_link_t link);
                case MP_QSTR_set_promiscuous: data->set_promiscuous = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_promiscuous, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, bool enable);
                case MP_QSTR_enable_flow_ctrl: data->enable_flow_ctrl = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_enable_flow_ctrl, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, bool enable);
                case MP_QSTR_set_peer_pause_ability: data->set_peer_pause_ability = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t_set_peer_pause_ability, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac, uint32_t ability);
                case MP_QSTR__del: data->del = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_mac_t__del, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_mac_t *mac);
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_eth_mac_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_eth_mac_t");
}

STATIC const mp_obj_dict_t mp_esp_eth_mac_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_eth_mac_t_type,
    MP_QSTR_esp_eth_mac_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_eth_mac_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_eth_mac_t_attr,
    locals_dict, &mp_esp_eth_mac_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_eth_mac_t_type()
{
    return &mp_esp_eth_mac_t_type;
}
    
#define funcptr_set_mediator_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t set_mediator(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator)
 */

STATIC mp_obj_t mp_funcptr_set_mediator_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_phy_t *phy = mp_to_ptr(mp_args[0]);
    esp_eth_mediator_t *mediator = mp_write_ptr_esp_eth_mediator_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_phy_t *, esp_eth_mediator_t *))lv_func_ptr)(phy, mediator);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_mediator_1_mpobj, 2, mp_funcptr_set_mediator_1, funcptr_set_mediator_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_mediator_1(void *func){ return mp_lv_funcptr(&mp_funcptr_set_mediator_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_set_mediator_callback'
 * esp_err_t (*set_mediator)(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator)
 */
    
#define funcptr_reset NULL


/*
 * espidf extension definition for:
 * esp_err_t reset(esp_eth_phy_t *phy)
 */

STATIC mp_obj_t mp_funcptr_reset(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_phy_t *phy = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_phy_t *))lv_func_ptr)(phy);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_reset_mpobj, 1, mp_funcptr_reset, funcptr_reset);
    
STATIC inline mp_obj_t mp_lv_funcptr_reset(void *func){ return mp_lv_funcptr(&mp_funcptr_reset_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_reset_callback'
 * esp_err_t (*reset)(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_reset_hw_callback'
 * esp_err_t (*reset_hw)(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_init_callback'
 * esp_err_t (*init)(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_deinit_callback'
 * esp_err_t (*deinit)(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_negotiate_callback'
 * esp_err_t (*negotiate)(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_get_link_callback'
 * esp_err_t (*get_link)(esp_eth_phy_t *phy)
 */
    
#define funcptr_pwrctl NULL


/*
 * espidf extension definition for:
 * esp_err_t pwrctl(esp_eth_phy_t *phy, bool enable)
 */

STATIC mp_obj_t mp_funcptr_pwrctl(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_phy_t *phy = mp_to_ptr(mp_args[0]);
    bool enable = mp_obj_is_true(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_phy_t *, bool))lv_func_ptr)(phy, enable);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_pwrctl_mpobj, 2, mp_funcptr_pwrctl, funcptr_pwrctl);
    
STATIC inline mp_obj_t mp_lv_funcptr_pwrctl(void *func){ return mp_lv_funcptr(&mp_funcptr_pwrctl_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_pwrctl_callback'
 * esp_err_t (*pwrctl)(esp_eth_phy_t *phy, bool enable)
 */
    
#define funcptr_set_addr_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t set_addr(esp_eth_phy_t *phy, uint32_t addr)
 */

STATIC mp_obj_t mp_funcptr_set_addr_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_phy_t *phy = mp_to_ptr(mp_args[0]);
    uint32_t addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_phy_t *, uint32_t))lv_func_ptr)(phy, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_set_addr_1_mpobj, 2, mp_funcptr_set_addr_1, funcptr_set_addr_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_set_addr_1(void *func){ return mp_lv_funcptr(&mp_funcptr_set_addr_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_set_addr_callback'
 * esp_err_t (*set_addr)(esp_eth_phy_t *phy, uint32_t addr)
 */
    
#define funcptr_get_addr NULL


/*
 * espidf extension definition for:
 * esp_err_t get_addr(esp_eth_phy_t *phy, uint32_t *addr)
 */

STATIC mp_obj_t mp_funcptr_get_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_phy_t *phy = mp_to_ptr(mp_args[0]);
    uint32_t *addr = mp_array_to_u32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_phy_t *, uint32_t *))lv_func_ptr)(phy, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_get_addr_mpobj, 2, mp_funcptr_get_addr, funcptr_get_addr);
    
STATIC inline mp_obj_t mp_lv_funcptr_get_addr(void *func){ return mp_lv_funcptr(&mp_funcptr_get_addr_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_get_addr_callback'
 * esp_err_t (*get_addr)(esp_eth_phy_t *phy, uint32_t *addr)
 */
    
#define funcptr_advertise_pause_ability NULL

/* Reusing funcptr_set_addr_1 for funcptr_advertise_pause_ability */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_advertise_pause_ability_mpobj, 2, mp_funcptr_set_addr_1, funcptr_advertise_pause_ability);
    
STATIC inline mp_obj_t mp_lv_funcptr_advertise_pause_ability(void *func){ return mp_lv_funcptr(&mp_funcptr_advertise_pause_ability_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_advertise_pause_ability_callback'
 * esp_err_t (*advertise_pause_ability)(esp_eth_phy_t *phy, uint32_t ability)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_loopback_callback'
 * esp_err_t (*loopback)(esp_eth_phy_t *phy, bool enable)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_phy_t_del_callback'
 * esp_err_t (*del)(esp_eth_phy_t *phy)
 */
    

/*
 * Struct esp_eth_phy_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_eth_phy_t_type();

STATIC inline void* mp_write_ptr_esp_eth_phy_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_eth_phy_t_type()));
    return (esp_eth_phy_t*)self->data;
}

#define mp_write_esp_eth_phy_t(struct_obj) *((esp_eth_phy_t*)mp_write_ptr_esp_eth_phy_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_eth_phy_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_eth_phy_t_type(), field);
}

#define mp_read_esp_eth_phy_t(field) mp_read_ptr_esp_eth_phy_t(copy_buffer(&field, sizeof(esp_eth_phy_t)))
#define mp_read_byref_esp_eth_phy_t(field) mp_read_ptr_esp_eth_phy_t(&field)

STATIC void mp_esp_eth_phy_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_eth_phy_t *data = (esp_eth_phy_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_set_mediator: dest[0] = mp_lv_funcptr(&mp_funcptr_set_mediator_1_mpobj, (void*)data->set_mediator, NULL ,MP_QSTR_esp_eth_phy_t_set_mediator, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator);
            case MP_QSTR_reset: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->reset, NULL ,MP_QSTR_esp_eth_phy_t_reset, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_reset_hw: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->reset_hw, NULL ,MP_QSTR_esp_eth_phy_t_reset_hw, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_init: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->init, NULL ,MP_QSTR_esp_eth_phy_t_init, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_deinit: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->deinit, NULL ,MP_QSTR_esp_eth_phy_t_deinit, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_negotiate: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->negotiate, NULL ,MP_QSTR_esp_eth_phy_t_negotiate, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_get_link: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->get_link, NULL ,MP_QSTR_esp_eth_phy_t_get_link, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            case MP_QSTR_pwrctl: dest[0] = mp_lv_funcptr(&mp_funcptr_pwrctl_mpobj, (void*)data->pwrctl, NULL ,MP_QSTR_esp_eth_phy_t_pwrctl, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, bool enable);
            case MP_QSTR_set_addr: dest[0] = mp_lv_funcptr(&mp_funcptr_set_addr_1_mpobj, (void*)data->set_addr, NULL ,MP_QSTR_esp_eth_phy_t_set_addr, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t addr);
            case MP_QSTR_get_addr: dest[0] = mp_lv_funcptr(&mp_funcptr_get_addr_mpobj, (void*)data->get_addr, NULL ,MP_QSTR_esp_eth_phy_t_get_addr, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t *addr);
            case MP_QSTR_advertise_pause_ability: dest[0] = mp_lv_funcptr(&mp_funcptr_advertise_pause_ability_mpobj, (void*)data->advertise_pause_ability, NULL ,MP_QSTR_esp_eth_phy_t_advertise_pause_ability, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t ability);
            case MP_QSTR_loopback: dest[0] = mp_lv_funcptr(&mp_funcptr_pwrctl_mpobj, (void*)data->loopback, NULL ,MP_QSTR_esp_eth_phy_t_loopback, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy, bool enable);
            case MP_QSTR__del: dest[0] = mp_lv_funcptr(&mp_funcptr_reset_mpobj, (void*)data->del, NULL ,MP_QSTR_esp_eth_phy_t__del, NULL); break; // converting from callback esp_err_t (*)(esp_eth_phy_t *phy);
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_set_mediator: data->set_mediator = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_set_mediator, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator);
                case MP_QSTR_reset: data->reset = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_reset, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_reset_hw: data->reset_hw = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_reset_hw, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_init: data->init = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_init, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_deinit: data->deinit = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_deinit, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_negotiate: data->negotiate = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_negotiate, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_get_link: data->get_link = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_get_link, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                case MP_QSTR_pwrctl: data->pwrctl = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_pwrctl, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, bool enable);
                case MP_QSTR_set_addr: data->set_addr = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_set_addr, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t addr);
                case MP_QSTR_get_addr: data->get_addr = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_get_addr, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t *addr);
                case MP_QSTR_advertise_pause_ability: data->advertise_pause_ability = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_advertise_pause_ability, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, uint32_t ability);
                case MP_QSTR_loopback: data->loopback = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t_loopback, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy, bool enable);
                case MP_QSTR__del: data->del = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_phy_t__del, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_phy_t *phy);
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_eth_phy_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_eth_phy_t");
}

STATIC const mp_obj_dict_t mp_esp_eth_phy_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_eth_phy_t_type,
    MP_QSTR_esp_eth_phy_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_eth_phy_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_eth_phy_t_attr,
    locals_dict, &mp_esp_eth_phy_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_eth_phy_t_type()
{
    return &mp_esp_eth_phy_t_type;
}
    
#define funcptr_stack_input_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t stack_input(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv)
 */

STATIC mp_obj_t mp_funcptr_stack_input_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t eth_handle = mp_to_ptr(mp_args[0]);
    uint8_t *buffer = mp_array_to_u8ptr(mp_args[1]);
    uint32_t length = (uint32_t)mp_obj_get_int(mp_args[2]);
    void *priv = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, uint8_t *, uint32_t, void *))lv_func_ptr)(eth_handle, buffer, length, priv);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_stack_input_1_mpobj, 4, mp_funcptr_stack_input_1, funcptr_stack_input_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_stack_input_1(void *func){ return mp_lv_funcptr(&mp_funcptr_stack_input_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_config_t_stack_input_callback'
 * esp_err_t (*stack_input)(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv)
 */
    
#define funcptr_on_lowlevel_init_done NULL


/*
 * espidf extension definition for:
 * esp_err_t on_lowlevel_init_done(esp_eth_handle_t eth_handle)
 */

STATIC mp_obj_t mp_funcptr_on_lowlevel_init_done(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t eth_handle = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t))lv_func_ptr)(eth_handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_on_lowlevel_init_done_mpobj, 1, mp_funcptr_on_lowlevel_init_done, funcptr_on_lowlevel_init_done);
    
STATIC inline mp_obj_t mp_lv_funcptr_on_lowlevel_init_done(void *func){ return mp_lv_funcptr(&mp_funcptr_on_lowlevel_init_done_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_config_t_on_lowlevel_init_done_callback'
 * esp_err_t (*on_lowlevel_init_done)(esp_eth_handle_t eth_handle)
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_config_t_on_lowlevel_deinit_done_callback'
 * esp_err_t (*on_lowlevel_deinit_done)(esp_eth_handle_t eth_handle)
 */
    
#define funcptr_read_phy_reg_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t read_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */

STATIC mp_obj_t mp_funcptr_read_phy_reg_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t eth_handle = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t *reg_value = mp_array_to_u32ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, uint32_t, uint32_t, uint32_t *))lv_func_ptr)(eth_handle, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_read_phy_reg_1_mpobj, 4, mp_funcptr_read_phy_reg_1, funcptr_read_phy_reg_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_read_phy_reg_1(void *func){ return mp_lv_funcptr(&mp_funcptr_read_phy_reg_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_config_t_read_phy_reg_callback'
 * esp_err_t (*read_phy_reg)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    
#define funcptr_write_phy_reg_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t write_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */

STATIC mp_obj_t mp_funcptr_write_phy_reg_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t eth_handle = mp_to_ptr(mp_args[0]);
    uint32_t phy_addr = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t phy_reg = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t reg_value = (uint32_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, uint32_t, uint32_t, uint32_t))lv_func_ptr)(eth_handle, phy_addr, phy_reg, reg_value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_write_phy_reg_1_mpobj, 4, mp_funcptr_write_phy_reg_1, funcptr_write_phy_reg_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_write_phy_reg_1(void *func){ return mp_lv_funcptr(&mp_funcptr_write_phy_reg_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_eth_config_t_write_phy_reg_callback'
 * esp_err_t (*write_phy_reg)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    

/*
 * Struct esp_eth_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_eth_config_t_type();

STATIC inline void* mp_write_ptr_esp_eth_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_eth_config_t_type()));
    return (esp_eth_config_t*)self->data;
}

#define mp_write_esp_eth_config_t(struct_obj) *((esp_eth_config_t*)mp_write_ptr_esp_eth_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_eth_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_eth_config_t_type(), field);
}

#define mp_read_esp_eth_config_t(field) mp_read_ptr_esp_eth_config_t(copy_buffer(&field, sizeof(esp_eth_config_t)))
#define mp_read_byref_esp_eth_config_t(field) mp_read_ptr_esp_eth_config_t(&field)

STATIC void mp_esp_eth_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_eth_config_t *data = (esp_eth_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mac: dest[0] = mp_read_ptr_esp_eth_mac_t((void*)data->mac); break; // converting from esp_eth_mac_t *;
            case MP_QSTR_phy: dest[0] = mp_read_ptr_esp_eth_phy_t((void*)data->phy); break; // converting from esp_eth_phy_t *;
            case MP_QSTR_check_link_period_ms: dest[0] = mp_obj_new_int_from_uint(data->check_link_period_ms); break; // converting from uint32_t;
            case MP_QSTR_stack_input: dest[0] = mp_lv_funcptr(&mp_funcptr_stack_input_1_mpobj, (void*)data->stack_input, NULL ,MP_QSTR_esp_eth_config_t_stack_input, NULL); break; // converting from callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv);
            case MP_QSTR_on_lowlevel_init_done: dest[0] = mp_lv_funcptr(&mp_funcptr_on_lowlevel_init_done_mpobj, (void*)data->on_lowlevel_init_done, NULL ,MP_QSTR_esp_eth_config_t_on_lowlevel_init_done, NULL); break; // converting from callback esp_err_t (*)(esp_eth_handle_t eth_handle);
            case MP_QSTR_on_lowlevel_deinit_done: dest[0] = mp_lv_funcptr(&mp_funcptr_on_lowlevel_init_done_mpobj, (void*)data->on_lowlevel_deinit_done, NULL ,MP_QSTR_esp_eth_config_t_on_lowlevel_deinit_done, NULL); break; // converting from callback esp_err_t (*)(esp_eth_handle_t eth_handle);
            case MP_QSTR_read_phy_reg: dest[0] = mp_lv_funcptr(&mp_funcptr_read_phy_reg_1_mpobj, (void*)data->read_phy_reg, NULL ,MP_QSTR_esp_eth_config_t_read_phy_reg, NULL); break; // converting from callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
            case MP_QSTR_write_phy_reg: dest[0] = mp_lv_funcptr(&mp_funcptr_write_phy_reg_1_mpobj, (void*)data->write_phy_reg, NULL ,MP_QSTR_esp_eth_config_t_write_phy_reg, NULL); break; // converting from callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mac: data->mac = (void*)mp_write_ptr_esp_eth_mac_t(dest[1]); break; // converting to esp_eth_mac_t *;
                case MP_QSTR_phy: data->phy = (void*)mp_write_ptr_esp_eth_phy_t(dest[1]); break; // converting to esp_eth_phy_t *;
                case MP_QSTR_check_link_period_ms: data->check_link_period_ms = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_stack_input: data->stack_input = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_config_t_stack_input, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv);
                case MP_QSTR_on_lowlevel_init_done: data->on_lowlevel_init_done = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_config_t_on_lowlevel_init_done, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_handle_t eth_handle);
                case MP_QSTR_on_lowlevel_deinit_done: data->on_lowlevel_deinit_done = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_config_t_on_lowlevel_deinit_done, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_handle_t eth_handle);
                case MP_QSTR_read_phy_reg: data->read_phy_reg = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_config_t_read_phy_reg, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value);
                case MP_QSTR_write_phy_reg: data->write_phy_reg = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_eth_config_t_write_phy_reg, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value);
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_eth_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_eth_config_t");
}

STATIC const mp_obj_dict_t mp_esp_eth_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_eth_config_t_type,
    MP_QSTR_esp_eth_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_eth_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_eth_config_t_attr,
    locals_dict, &mp_esp_eth_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_eth_config_t_type()
{
    return &mp_esp_eth_config_t_type;
}
    

/*
 * Struct esp_chip_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_chip_info_t_type();

STATIC inline void* mp_write_ptr_esp_chip_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_chip_info_t_type()));
    return (esp_chip_info_t*)self->data;
}

#define mp_write_esp_chip_info_t(struct_obj) *((esp_chip_info_t*)mp_write_ptr_esp_chip_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_chip_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_chip_info_t_type(), field);
}

#define mp_read_esp_chip_info_t(field) mp_read_ptr_esp_chip_info_t(copy_buffer(&field, sizeof(esp_chip_info_t)))
#define mp_read_byref_esp_chip_info_t(field) mp_read_ptr_esp_chip_info_t(&field)

STATIC void mp_esp_chip_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_chip_info_t *data = (esp_chip_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_model: dest[0] = mp_obj_new_int(data->model); break; // converting from esp_chip_model_t;
            case MP_QSTR_features: dest[0] = mp_obj_new_int_from_uint(data->features); break; // converting from uint32_t;
            case MP_QSTR_full_revision: dest[0] = mp_obj_new_int_from_uint(data->full_revision); break; // converting from uint16_t;
            case MP_QSTR_cores: dest[0] = mp_obj_new_int_from_uint(data->cores); break; // converting from uint8_t;
            case MP_QSTR_revision: dest[0] = mp_obj_new_int_from_uint(data->revision); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_model: data->model = (int)mp_obj_get_int(dest[1]); break; // converting to esp_chip_model_t;
                case MP_QSTR_features: data->features = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_full_revision: data->full_revision = (uint16_t)mp_obj_get_int(dest[1]); break; // converting to uint16_t;
                case MP_QSTR_cores: data->cores = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_revision: data->revision = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_chip_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_chip_info_t");
}

STATIC const mp_obj_dict_t mp_esp_chip_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_chip_info_t_type,
    MP_QSTR_esp_chip_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_chip_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_chip_info_t_attr,
    locals_dict, &mp_esp_chip_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_chip_info_t_type()
{
    return &mp_esp_chip_info_t_type;
}
    
#define funcptr_shutdown_handler_t NULL


/*
 * espidf extension definition for:
 * void shutdown_handler_t(void)
 */

STATIC mp_obj_t mp_funcptr_shutdown_handler_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    ((void (*)(void))lv_func_ptr)();
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_shutdown_handler_t_mpobj, 0, mp_funcptr_shutdown_handler_t, funcptr_shutdown_handler_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_shutdown_handler_t(void *func){ return mp_lv_funcptr(&mp_funcptr_shutdown_handler_t_mpobj, func, NULL, MP_QSTR_, NULL); }

#define funcptr_dhcps_cb_t NULL


/*
 * Array convertors for u8_t [4]
 */

GENMPY_UNUSED STATIC u8_t *mp_arr_to_u8_t___4__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    u8_t *lv_arr = (u8_t*)m_malloc(len * sizeof(u8_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint8_t)mp_obj_get_int(item);
    }
    return (u8_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_u8_t___4__(u8_t *arr)
{
    mp_obj_t obj_arr[4];
    for (size_t i=0; i<4; i++){
        obj_arr[i] = mp_obj_new_int_from_uint(arr[i]);
    }
    return mp_obj_new_list(4, obj_arr); // TODO: return custom iterable object!
}


/*
 * espidf extension definition for:
 * void dhcps_cb_t(u8_t client_ip[4])
 */

STATIC mp_obj_t mp_funcptr_dhcps_cb_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u8_t *client_ip = mp_arr_to_u8_t___4__(mp_args[0]);
    ((void (*)(u8_t [4]))lv_func_ptr)(client_ip);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_dhcps_cb_t_mpobj, 1, mp_funcptr_dhcps_cb_t, funcptr_dhcps_cb_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_dhcps_cb_t(void *func){ return mp_lv_funcptr(&mp_funcptr_dhcps_cb_t_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Array convertors for uint8_t [6]
 */

GENMPY_UNUSED STATIC uint8_t *mp_arr_to_uint8_t___6__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    uint8_t *lv_arr = (uint8_t*)m_malloc(len * sizeof(uint8_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint8_t)mp_obj_get_int(item);
    }
    return (uint8_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_uint8_t___6__(uint8_t *arr)
{
    mp_obj_t obj_arr[6];
    for (size_t i=0; i<6; i++){
        obj_arr[i] = mp_obj_new_int_from_uint(arr[i]);
    }
    return mp_obj_new_list(6, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct wifi_sta_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_wifi_sta_info_t_type();

STATIC inline void* mp_write_ptr_wifi_sta_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_wifi_sta_info_t_type()));
    return (wifi_sta_info_t*)self->data;
}

#define mp_write_wifi_sta_info_t(struct_obj) *((wifi_sta_info_t*)mp_write_ptr_wifi_sta_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_wifi_sta_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_wifi_sta_info_t_type(), field);
}

#define mp_read_wifi_sta_info_t(field) mp_read_ptr_wifi_sta_info_t(copy_buffer(&field, sizeof(wifi_sta_info_t)))
#define mp_read_byref_wifi_sta_info_t(field) mp_read_ptr_wifi_sta_info_t(&field)

STATIC void mp_wifi_sta_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED wifi_sta_info_t *data = (wifi_sta_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mac: dest[0] = mp_arr_from_uint8_t___6__(data->mac); break; // converting from uint8_t [6];
            case MP_QSTR_rssi: dest[0] = mp_obj_new_int(data->rssi); break; // converting from int8_t;
            case MP_QSTR_phy_11b: dest[0] = mp_obj_new_int_from_uint(data->phy_11b); break; // converting from uint32_t;
            case MP_QSTR_phy_11g: dest[0] = mp_obj_new_int_from_uint(data->phy_11g); break; // converting from uint32_t;
            case MP_QSTR_phy_11n: dest[0] = mp_obj_new_int_from_uint(data->phy_11n); break; // converting from uint32_t;
            case MP_QSTR_phy_lr: dest[0] = mp_obj_new_int_from_uint(data->phy_lr); break; // converting from uint32_t;
            case MP_QSTR_is_mesh_child: dest[0] = mp_obj_new_int_from_uint(data->is_mesh_child); break; // converting from uint32_t;
            case MP_QSTR_reserved: dest[0] = mp_obj_new_int_from_uint(data->reserved); break; // converting from uint32_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mac: memcpy((void*)&data->mac, mp_arr_to_uint8_t___6__(dest[1]), sizeof(uint8_t)*6); break; // converting to uint8_t [6];
                case MP_QSTR_rssi: data->rssi = (int8_t)mp_obj_get_int(dest[1]); break; // converting to int8_t;
                case MP_QSTR_phy_11b: data->phy_11b = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_phy_11g: data->phy_11g = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_phy_11n: data->phy_11n = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_phy_lr: data->phy_lr = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_is_mesh_child: data->is_mesh_child = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_reserved: data->reserved = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_wifi_sta_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct wifi_sta_info_t");
}

STATIC const mp_obj_dict_t mp_wifi_sta_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_wifi_sta_info_t_type,
    MP_QSTR_wifi_sta_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_wifi_sta_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_wifi_sta_info_t_attr,
    locals_dict, &mp_wifi_sta_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_wifi_sta_info_t_type()
{
    return &mp_wifi_sta_info_t_type;
}
    

/*
 * Array convertors for wifi_sta_info_t [15]
 */

GENMPY_UNUSED STATIC wifi_sta_info_t *mp_arr_to_wifi_sta_info_t___15__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    wifi_sta_info_t *lv_arr = (wifi_sta_info_t*)m_malloc(len * sizeof(wifi_sta_info_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = mp_write_wifi_sta_info_t(item);
    }
    return (wifi_sta_info_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_wifi_sta_info_t___15__(wifi_sta_info_t *arr)
{
    mp_obj_t obj_arr[15];
    for (size_t i=0; i<15; i++){
        obj_arr[i] = mp_read_wifi_sta_info_t(arr[i]);
    }
    return mp_obj_new_list(15, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct wifi_sta_list_t
 */

STATIC inline const mp_obj_type_t *get_mp_wifi_sta_list_t_type();

STATIC inline void* mp_write_ptr_wifi_sta_list_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_wifi_sta_list_t_type()));
    return (wifi_sta_list_t*)self->data;
}

#define mp_write_wifi_sta_list_t(struct_obj) *((wifi_sta_list_t*)mp_write_ptr_wifi_sta_list_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_wifi_sta_list_t(void *field)
{
    return lv_to_mp_struct(get_mp_wifi_sta_list_t_type(), field);
}

#define mp_read_wifi_sta_list_t(field) mp_read_ptr_wifi_sta_list_t(copy_buffer(&field, sizeof(wifi_sta_list_t)))
#define mp_read_byref_wifi_sta_list_t(field) mp_read_ptr_wifi_sta_list_t(&field)

STATIC void mp_wifi_sta_list_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED wifi_sta_list_t *data = (wifi_sta_list_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_sta: dest[0] = mp_arr_from_wifi_sta_info_t___15__(data->sta); break; // converting from wifi_sta_info_t [15];
            case MP_QSTR_num: dest[0] = mp_obj_new_int(data->num); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_sta: memcpy((void*)&data->sta, mp_arr_to_wifi_sta_info_t___15__(dest[1]), sizeof(wifi_sta_info_t)*15); break; // converting to wifi_sta_info_t [15];
                case MP_QSTR_num: data->num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_wifi_sta_list_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct wifi_sta_list_t");
}

STATIC const mp_obj_dict_t mp_wifi_sta_list_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_wifi_sta_list_t_type,
    MP_QSTR_wifi_sta_list_t,
    MP_TYPE_FLAG_NONE,
    print, mp_wifi_sta_list_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_wifi_sta_list_t_attr,
    locals_dict, &mp_wifi_sta_list_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_wifi_sta_list_t_type()
{
    return &mp_wifi_sta_list_t_type;
}
    

/*
 * Struct esp_netif_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_t_type();

STATIC inline void* mp_write_ptr_esp_netif_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_t_type()));
    return (esp_netif_t*)self->data;
}

#define mp_write_esp_netif_t(struct_obj) *((esp_netif_t*)mp_write_ptr_esp_netif_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_t_type(), field);
}

#define mp_read_esp_netif_t(field) mp_read_ptr_esp_netif_t(copy_buffer(&field, sizeof(esp_netif_t)))
#define mp_read_byref_esp_netif_t(field) mp_read_ptr_esp_netif_t(&field)

STATIC void mp_esp_netif_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_t *data = (esp_netif_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_t_type,
    MP_QSTR_esp_netif_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_t_attr,
    locals_dict, &mp_esp_netif_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_t_type()
{
    return &mp_esp_netif_t_type;
}
    

/*
 * Struct esp_netif_ip_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_ip_info_t_type();

STATIC inline void* mp_write_ptr_esp_netif_ip_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_ip_info_t_type()));
    return (esp_netif_ip_info_t*)self->data;
}

#define mp_write_esp_netif_ip_info_t(struct_obj) *((esp_netif_ip_info_t*)mp_write_ptr_esp_netif_ip_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_ip_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_ip_info_t_type(), field);
}

#define mp_read_esp_netif_ip_info_t(field) mp_read_ptr_esp_netif_ip_info_t(copy_buffer(&field, sizeof(esp_netif_ip_info_t)))
#define mp_read_byref_esp_netif_ip_info_t(field) mp_read_ptr_esp_netif_ip_info_t(&field)

STATIC void mp_esp_netif_ip_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_ip_info_t *data = (esp_netif_ip_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ip: dest[0] = mp_read_byref_esp_ip4_addr_t(data->ip); break; // converting from esp_ip4_addr_t;
            case MP_QSTR_netmask: dest[0] = mp_read_byref_esp_ip4_addr_t(data->netmask); break; // converting from esp_ip4_addr_t;
            case MP_QSTR_gw: dest[0] = mp_read_byref_esp_ip4_addr_t(data->gw); break; // converting from esp_ip4_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ip: data->ip = mp_write_esp_ip4_addr_t(dest[1]); break; // converting to esp_ip4_addr_t;
                case MP_QSTR_netmask: data->netmask = mp_write_esp_ip4_addr_t(dest[1]); break; // converting to esp_ip4_addr_t;
                case MP_QSTR_gw: data->gw = mp_write_esp_ip4_addr_t(dest[1]); break; // converting to esp_ip4_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_ip_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_ip_info_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_ip_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_ip_info_t_type,
    MP_QSTR_esp_netif_ip_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_ip_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_ip_info_t_attr,
    locals_dict, &mp_esp_netif_ip_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_ip_info_t_type()
{
    return &mp_esp_netif_ip_info_t_type;
}
    

/*
 * Struct esp_netif_inherent_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_inherent_config_t_type();

STATIC inline void* mp_write_ptr_esp_netif_inherent_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_inherent_config_t_type()));
    return (esp_netif_inherent_config_t*)self->data;
}

#define mp_write_esp_netif_inherent_config_t(struct_obj) *((esp_netif_inherent_config_t*)mp_write_ptr_esp_netif_inherent_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_inherent_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_inherent_config_t_type(), field);
}

#define mp_read_esp_netif_inherent_config_t(field) mp_read_ptr_esp_netif_inherent_config_t(copy_buffer(&field, sizeof(esp_netif_inherent_config_t)))
#define mp_read_byref_esp_netif_inherent_config_t(field) mp_read_ptr_esp_netif_inherent_config_t(&field)

STATIC void mp_esp_netif_inherent_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_inherent_config_t *data = (esp_netif_inherent_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_flags: dest[0] = mp_obj_new_int(data->flags); break; // converting from esp_netif_flags_t;
            case MP_QSTR_mac: dest[0] = mp_arr_from_uint8_t___6__(data->mac); break; // converting from uint8_t [6];
            case MP_QSTR_ip_info: dest[0] = mp_read_ptr_esp_netif_ip_info_t((void*)data->ip_info); break; // converting from esp_netif_ip_info_t *;
            case MP_QSTR_get_ip_event: dest[0] = mp_obj_new_int_from_uint(data->get_ip_event); break; // converting from uint32_t;
            case MP_QSTR_lost_ip_event: dest[0] = mp_obj_new_int_from_uint(data->lost_ip_event); break; // converting from uint32_t;
            case MP_QSTR_if_key: dest[0] = convert_to_str((void*)data->if_key); break; // converting from char *;
            case MP_QSTR_if_desc: dest[0] = convert_to_str((void*)data->if_desc); break; // converting from char *;
            case MP_QSTR_route_prio: dest[0] = mp_obj_new_int(data->route_prio); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_flags: data->flags = (int)mp_obj_get_int(dest[1]); break; // converting to esp_netif_flags_t;
                case MP_QSTR_mac: memcpy((void*)&data->mac, mp_arr_to_uint8_t___6__(dest[1]), sizeof(uint8_t)*6); break; // converting to uint8_t [6];
                case MP_QSTR_ip_info: data->ip_info = (void*)mp_write_ptr_esp_netif_ip_info_t(dest[1]); break; // converting to esp_netif_ip_info_t *;
                case MP_QSTR_get_ip_event: data->get_ip_event = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_lost_ip_event: data->lost_ip_event = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_if_key: data->if_key = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_if_desc: data->if_desc = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_route_prio: data->route_prio = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_inherent_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_inherent_config_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_inherent_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_inherent_config_t_type,
    MP_QSTR_esp_netif_inherent_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_inherent_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_inherent_config_t_attr,
    locals_dict, &mp_esp_netif_inherent_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_inherent_config_t_type()
{
    return &mp_esp_netif_inherent_config_t_type;
}
    
#define funcptr_transmit_1 NULL


/*
 * espidf extension definition for:
 * esp_err_t transmit(void *h, void *buffer, size_t len)
 */

STATIC mp_obj_t mp_funcptr_transmit_1(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *h = mp_to_ptr(mp_args[0]);
    void *buffer = mp_to_ptr(mp_args[1]);
    size_t len = (size_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(void *, void *, size_t))lv_func_ptr)(h, buffer, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_transmit_1_mpobj, 3, mp_funcptr_transmit_1, funcptr_transmit_1);
    
STATIC inline mp_obj_t mp_lv_funcptr_transmit_1(void *func){ return mp_lv_funcptr(&mp_funcptr_transmit_1_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_netif_driver_ifconfig_t_transmit_callback'
 * esp_err_t (*transmit)(void *h, void *buffer, size_t len)
 */
    
#define funcptr_transmit_wrap NULL


/*
 * espidf extension definition for:
 * esp_err_t transmit_wrap(void *h, void *buffer, size_t len, void *netstack_buffer)
 */

STATIC mp_obj_t mp_funcptr_transmit_wrap(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *h = mp_to_ptr(mp_args[0]);
    void *buffer = mp_to_ptr(mp_args[1]);
    size_t len = (size_t)mp_obj_get_int(mp_args[2]);
    void *netstack_buffer = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(void *, void *, size_t, void *))lv_func_ptr)(h, buffer, len, netstack_buffer);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_transmit_wrap_mpobj, 4, mp_funcptr_transmit_wrap, funcptr_transmit_wrap);
    
STATIC inline mp_obj_t mp_lv_funcptr_transmit_wrap(void *func){ return mp_lv_funcptr(&mp_funcptr_transmit_wrap_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_netif_driver_ifconfig_t_transmit_wrap_callback'
 * esp_err_t (*transmit_wrap)(void *h, void *buffer, size_t len, void *netstack_buffer)
 */
    
#define funcptr_driver_free_rx_buffer NULL


/*
 * espidf extension definition for:
 * void driver_free_rx_buffer(void *h, void *buffer)
 */

STATIC mp_obj_t mp_funcptr_driver_free_rx_buffer(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *h = mp_to_ptr(mp_args[0]);
    void *buffer = mp_to_ptr(mp_args[1]);
    ((void (*)(void *, void *))lv_func_ptr)(h, buffer);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_driver_free_rx_buffer_mpobj, 2, mp_funcptr_driver_free_rx_buffer, funcptr_driver_free_rx_buffer);
    
STATIC inline mp_obj_t mp_lv_funcptr_driver_free_rx_buffer(void *func){ return mp_lv_funcptr(&mp_funcptr_driver_free_rx_buffer_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'esp_netif_driver_ifconfig_t_driver_free_rx_buffer_callback'
 * void (*driver_free_rx_buffer)(void *h, void *buffer)
 */
    

/*
 * Struct esp_netif_driver_ifconfig_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_driver_ifconfig_t_type();

STATIC inline void* mp_write_ptr_esp_netif_driver_ifconfig_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_driver_ifconfig_t_type()));
    return (esp_netif_driver_ifconfig_t*)self->data;
}

#define mp_write_esp_netif_driver_ifconfig_t(struct_obj) *((esp_netif_driver_ifconfig_t*)mp_write_ptr_esp_netif_driver_ifconfig_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_driver_ifconfig_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_driver_ifconfig_t_type(), field);
}

#define mp_read_esp_netif_driver_ifconfig_t(field) mp_read_ptr_esp_netif_driver_ifconfig_t(copy_buffer(&field, sizeof(esp_netif_driver_ifconfig_t)))
#define mp_read_byref_esp_netif_driver_ifconfig_t(field) mp_read_ptr_esp_netif_driver_ifconfig_t(&field)

STATIC void mp_esp_netif_driver_ifconfig_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_driver_ifconfig_t *data = (esp_netif_driver_ifconfig_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_handle: dest[0] = ptr_to_mp(data->handle); break; // converting from esp_netif_iodriver_handle;
            case MP_QSTR_transmit: dest[0] = mp_lv_funcptr(&mp_funcptr_transmit_1_mpobj, (void*)data->transmit, NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_transmit, NULL); break; // converting from callback esp_err_t (*)(void *h, void *buffer, size_t len);
            case MP_QSTR_transmit_wrap: dest[0] = mp_lv_funcptr(&mp_funcptr_transmit_wrap_mpobj, (void*)data->transmit_wrap, NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_transmit_wrap, NULL); break; // converting from callback esp_err_t (*)(void *h, void *buffer, size_t len, void *netstack_buffer);
            case MP_QSTR_driver_free_rx_buffer: dest[0] = mp_lv_funcptr(&mp_funcptr_driver_free_rx_buffer_mpobj, (void*)data->driver_free_rx_buffer, NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_driver_free_rx_buffer, NULL); break; // converting from callback void (*)(void *h, void *buffer);
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_handle: data->handle = mp_to_ptr(dest[1]); break; // converting to esp_netif_iodriver_handle;
                case MP_QSTR_transmit: data->transmit = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_transmit, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(void *h, void *buffer, size_t len);
                case MP_QSTR_transmit_wrap: data->transmit_wrap = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_transmit_wrap, NULL, NULL, NULL, NULL); break; // converting to callback esp_err_t (*)(void *h, void *buffer, size_t len, void *netstack_buffer);
                case MP_QSTR_driver_free_rx_buffer: data->driver_free_rx_buffer = (void*)mp_lv_callback(dest[1], NULL ,MP_QSTR_esp_netif_driver_ifconfig_t_driver_free_rx_buffer, NULL, NULL, NULL, NULL); break; // converting to callback void (*)(void *h, void *buffer);
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_driver_ifconfig_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_driver_ifconfig_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_driver_ifconfig_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_driver_ifconfig_t_type,
    MP_QSTR_esp_netif_driver_ifconfig_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_driver_ifconfig_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_driver_ifconfig_t_attr,
    locals_dict, &mp_esp_netif_driver_ifconfig_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_driver_ifconfig_t_type()
{
    return &mp_esp_netif_driver_ifconfig_t_type;
}
    

/*
 * Struct esp_netif_netstack_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_netstack_config_t_type();

STATIC inline void* mp_write_ptr_esp_netif_netstack_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_netstack_config_t_type()));
    return (esp_netif_netstack_config_t*)self->data;
}

#define mp_write_esp_netif_netstack_config_t(struct_obj) *((esp_netif_netstack_config_t*)mp_write_ptr_esp_netif_netstack_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_netstack_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_netstack_config_t_type(), field);
}

#define mp_read_esp_netif_netstack_config_t(field) mp_read_ptr_esp_netif_netstack_config_t(copy_buffer(&field, sizeof(esp_netif_netstack_config_t)))
#define mp_read_byref_esp_netif_netstack_config_t(field) mp_read_ptr_esp_netif_netstack_config_t(&field)

STATIC void mp_esp_netif_netstack_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_netstack_config_t *data = (esp_netif_netstack_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_netstack_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_netstack_config_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_netstack_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_netstack_config_t_type,
    MP_QSTR_esp_netif_netstack_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_netstack_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_netstack_config_t_attr,
    locals_dict, &mp_esp_netif_netstack_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_netstack_config_t_type()
{
    return &mp_esp_netif_netstack_config_t_type;
}
    

/*
 * Struct esp_netif_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_config_t_type();

STATIC inline void* mp_write_ptr_esp_netif_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_config_t_type()));
    return (esp_netif_config_t*)self->data;
}

#define mp_write_esp_netif_config_t(struct_obj) *((esp_netif_config_t*)mp_write_ptr_esp_netif_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_config_t_type(), field);
}

#define mp_read_esp_netif_config_t(field) mp_read_ptr_esp_netif_config_t(copy_buffer(&field, sizeof(esp_netif_config_t)))
#define mp_read_byref_esp_netif_config_t(field) mp_read_ptr_esp_netif_config_t(&field)

STATIC void mp_esp_netif_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_config_t *data = (esp_netif_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_base: dest[0] = mp_read_ptr_esp_netif_inherent_config_t((void*)data->base); break; // converting from esp_netif_inherent_config_t *;
            case MP_QSTR_driver: dest[0] = mp_read_ptr_esp_netif_driver_ifconfig_t((void*)data->driver); break; // converting from esp_netif_driver_ifconfig_t *;
            case MP_QSTR_stack: dest[0] = mp_read_ptr_esp_netif_netstack_config_t((void*)data->stack); break; // converting from esp_netif_netstack_config_t *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_base: data->base = (void*)mp_write_ptr_esp_netif_inherent_config_t(dest[1]); break; // converting to esp_netif_inherent_config_t *;
                case MP_QSTR_driver: data->driver = (void*)mp_write_ptr_esp_netif_driver_ifconfig_t(dest[1]); break; // converting to esp_netif_driver_ifconfig_t *;
                case MP_QSTR_stack: data->stack = (void*)mp_write_ptr_esp_netif_netstack_config_t(dest[1]); break; // converting to esp_netif_netstack_config_t *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_config_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_config_t_type,
    MP_QSTR_esp_netif_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_config_t_attr,
    locals_dict, &mp_esp_netif_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_config_t_type()
{
    return &mp_esp_netif_config_t_type;
}
    
#define funcptr_esp_netif_callback_fn NULL

/* Reusing funcptr_crt_bundle_attach for funcptr_esp_netif_callback_fn */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_esp_netif_callback_fn_mpobj, 1, mp_funcptr_crt_bundle_attach, funcptr_esp_netif_callback_fn);
    
STATIC inline mp_obj_t mp_lv_funcptr_esp_netif_callback_fn(void *func){ return mp_lv_funcptr(&mp_funcptr_esp_netif_callback_fn_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Struct mdns_search_once_t
 */

STATIC inline const mp_obj_type_t *get_mp_mdns_search_once_t_type();

STATIC inline void* mp_write_ptr_mdns_search_once_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_mdns_search_once_t_type()));
    return (mdns_search_once_t*)self->data;
}

#define mp_write_mdns_search_once_t(struct_obj) *((mdns_search_once_t*)mp_write_ptr_mdns_search_once_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_mdns_search_once_t(void *field)
{
    return lv_to_mp_struct(get_mp_mdns_search_once_t_type(), field);
}

#define mp_read_mdns_search_once_t(field) mp_read_ptr_mdns_search_once_t(copy_buffer(&field, sizeof(mdns_search_once_t)))
#define mp_read_byref_mdns_search_once_t(field) mp_read_ptr_mdns_search_once_t(&field)

STATIC void mp_mdns_search_once_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED mdns_search_once_t *data = (mdns_search_once_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_mdns_search_once_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct mdns_search_once_t");
}

STATIC const mp_obj_dict_t mp_mdns_search_once_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_mdns_search_once_t_type,
    MP_QSTR_mdns_search_once_t,
    MP_TYPE_FLAG_NONE,
    print, mp_mdns_search_once_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_mdns_search_once_t_attr,
    locals_dict, &mp_mdns_search_once_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_mdns_search_once_t_type()
{
    return &mp_mdns_search_once_t_type;
}
    

/*
 * Struct mdns_txt_item_t
 */

STATIC inline const mp_obj_type_t *get_mp_mdns_txt_item_t_type();

STATIC inline void* mp_write_ptr_mdns_txt_item_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_mdns_txt_item_t_type()));
    return (mdns_txt_item_t*)self->data;
}

#define mp_write_mdns_txt_item_t(struct_obj) *((mdns_txt_item_t*)mp_write_ptr_mdns_txt_item_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_mdns_txt_item_t(void *field)
{
    return lv_to_mp_struct(get_mp_mdns_txt_item_t_type(), field);
}

#define mp_read_mdns_txt_item_t(field) mp_read_ptr_mdns_txt_item_t(copy_buffer(&field, sizeof(mdns_txt_item_t)))
#define mp_read_byref_mdns_txt_item_t(field) mp_read_ptr_mdns_txt_item_t(&field)

STATIC void mp_mdns_txt_item_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED mdns_txt_item_t *data = (mdns_txt_item_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_key: dest[0] = convert_to_str((void*)data->key); break; // converting from char *;
            case MP_QSTR_value: dest[0] = convert_to_str((void*)data->value); break; // converting from char *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_key: data->key = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_value: data->value = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_mdns_txt_item_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct mdns_txt_item_t");
}

STATIC const mp_obj_dict_t mp_mdns_txt_item_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_mdns_txt_item_t_type,
    MP_QSTR_mdns_txt_item_t,
    MP_TYPE_FLAG_NONE,
    print, mp_mdns_txt_item_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_mdns_txt_item_t_attr,
    locals_dict, &mp_mdns_txt_item_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_mdns_txt_item_t_type()
{
    return &mp_mdns_txt_item_t_type;
}
    

/*
 * Struct mdns_ip_addr_t
 */

STATIC inline const mp_obj_type_t *get_mp_mdns_ip_addr_t_type();

STATIC inline void* mp_write_ptr_mdns_ip_addr_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_mdns_ip_addr_t_type()));
    return (mdns_ip_addr_t*)self->data;
}

#define mp_write_mdns_ip_addr_t(struct_obj) *((mdns_ip_addr_t*)mp_write_ptr_mdns_ip_addr_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_mdns_ip_addr_t(void *field)
{
    return lv_to_mp_struct(get_mp_mdns_ip_addr_t_type(), field);
}

#define mp_read_mdns_ip_addr_t(field) mp_read_ptr_mdns_ip_addr_t(copy_buffer(&field, sizeof(mdns_ip_addr_t)))
#define mp_read_byref_mdns_ip_addr_t(field) mp_read_ptr_mdns_ip_addr_t(&field)

STATIC void mp_mdns_ip_addr_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED mdns_ip_addr_t *data = (mdns_ip_addr_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_addr: dest[0] = mp_read_byref_esp_ip_addr_t(data->addr); break; // converting from esp_ip_addr_t;
            case MP_QSTR_next: dest[0] = ptr_to_mp((void*)data->next); break; // converting from mdns_ip_addr_t *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_addr: data->addr = mp_write_esp_ip_addr_t(dest[1]); break; // converting to esp_ip_addr_t;
                case MP_QSTR_next: data->next = (void*)mp_to_ptr(dest[1]); break; // converting to mdns_ip_addr_t *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_mdns_ip_addr_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct mdns_ip_addr_t");
}

STATIC const mp_obj_dict_t mp_mdns_ip_addr_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_mdns_ip_addr_t_type,
    MP_QSTR_mdns_ip_addr_t,
    MP_TYPE_FLAG_NONE,
    print, mp_mdns_ip_addr_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_mdns_ip_addr_t_attr,
    locals_dict, &mp_mdns_ip_addr_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_mdns_ip_addr_t_type()
{
    return &mp_mdns_ip_addr_t_type;
}
    

/*
 * Struct mdns_result_t
 */

STATIC inline const mp_obj_type_t *get_mp_mdns_result_t_type();

STATIC inline void* mp_write_ptr_mdns_result_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_mdns_result_t_type()));
    return (mdns_result_t*)self->data;
}

#define mp_write_mdns_result_t(struct_obj) *((mdns_result_t*)mp_write_ptr_mdns_result_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_mdns_result_t(void *field)
{
    return lv_to_mp_struct(get_mp_mdns_result_t_type(), field);
}

#define mp_read_mdns_result_t(field) mp_read_ptr_mdns_result_t(copy_buffer(&field, sizeof(mdns_result_t)))
#define mp_read_byref_mdns_result_t(field) mp_read_ptr_mdns_result_t(&field)

STATIC void mp_mdns_result_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED mdns_result_t *data = (mdns_result_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_next: dest[0] = ptr_to_mp((void*)data->next); break; // converting from mdns_result_t *;
            case MP_QSTR_tcpip_if: dest[0] = mp_obj_new_int(data->tcpip_if); break; // converting from mdns_if_t;
            case MP_QSTR_ttl: dest[0] = mp_obj_new_int_from_uint(data->ttl); break; // converting from uint32_t;
            case MP_QSTR_ip_protocol: dest[0] = mp_obj_new_int(data->ip_protocol); break; // converting from mdns_ip_protocol_t;
            case MP_QSTR_instance_name: dest[0] = convert_to_str((void*)data->instance_name); break; // converting from char *;
            case MP_QSTR_service_type: dest[0] = convert_to_str((void*)data->service_type); break; // converting from char *;
            case MP_QSTR_proto: dest[0] = convert_to_str((void*)data->proto); break; // converting from char *;
            case MP_QSTR_hostname: dest[0] = convert_to_str((void*)data->hostname); break; // converting from char *;
            case MP_QSTR_port: dest[0] = mp_obj_new_int_from_uint(data->port); break; // converting from uint16_t;
            case MP_QSTR_txt: dest[0] = mp_read_ptr_mdns_txt_item_t((void*)data->txt); break; // converting from mdns_txt_item_t *;
            case MP_QSTR_txt_value_len: dest[0] = mp_array_from_u8ptr((void*)data->txt_value_len); break; // converting from uint8_t *;
            case MP_QSTR_txt_count: dest[0] = mp_obj_new_int_from_uint(data->txt_count); break; // converting from size_t;
            case MP_QSTR_addr: dest[0] = mp_read_ptr_mdns_ip_addr_t((void*)data->addr); break; // converting from mdns_ip_addr_t *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_next: data->next = (void*)mp_to_ptr(dest[1]); break; // converting to mdns_result_t *;
                case MP_QSTR_tcpip_if: data->tcpip_if = (int)mp_obj_get_int(dest[1]); break; // converting to mdns_if_t;
                case MP_QSTR_ttl: data->ttl = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_ip_protocol: data->ip_protocol = (int)mp_obj_get_int(dest[1]); break; // converting to mdns_ip_protocol_t;
                case MP_QSTR_instance_name: data->instance_name = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_service_type: data->service_type = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_proto: data->proto = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_hostname: data->hostname = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_port: data->port = (uint16_t)mp_obj_get_int(dest[1]); break; // converting to uint16_t;
                case MP_QSTR_txt: data->txt = (void*)mp_write_ptr_mdns_txt_item_t(dest[1]); break; // converting to mdns_txt_item_t *;
                case MP_QSTR_txt_value_len: data->txt_value_len = (void*)mp_array_to_u8ptr(dest[1]); break; // converting to uint8_t *;
                case MP_QSTR_txt_count: data->txt_count = (size_t)mp_obj_get_int(dest[1]); break; // converting to size_t;
                case MP_QSTR_addr: data->addr = (void*)mp_write_ptr_mdns_ip_addr_t(dest[1]); break; // converting to mdns_ip_addr_t *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_mdns_result_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct mdns_result_t");
}

STATIC const mp_obj_dict_t mp_mdns_result_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_mdns_result_t_type,
    MP_QSTR_mdns_result_t,
    MP_TYPE_FLAG_NONE,
    print, mp_mdns_result_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_mdns_result_t_attr,
    locals_dict, &mp_mdns_result_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_mdns_result_t_type()
{
    return &mp_mdns_result_t_type;
}
    

/*
 * Struct http_parser
 */

STATIC inline const mp_obj_type_t *get_mp_http_parser_type();

STATIC inline void* mp_write_ptr_http_parser(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_http_parser_type()));
    return (struct http_parser*)self->data;
}

#define mp_write_http_parser(struct_obj) *((struct http_parser*)mp_write_ptr_http_parser(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_http_parser(void *field)
{
    return lv_to_mp_struct(get_mp_http_parser_type(), field);
}

#define mp_read_http_parser(field) mp_read_ptr_http_parser(copy_buffer(&field, sizeof(struct http_parser)))
#define mp_read_byref_http_parser(field) mp_read_ptr_http_parser(&field)

STATIC void mp_http_parser_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED struct http_parser *data = (struct http_parser*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_type: dest[0] = mp_obj_new_int_from_uint(data->type); break; // converting from unsigned int;
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from unsigned int;
            case MP_QSTR_state: dest[0] = mp_obj_new_int_from_uint(data->state); break; // converting from unsigned int;
            case MP_QSTR_header_state: dest[0] = mp_obj_new_int_from_uint(data->header_state); break; // converting from unsigned int;
            case MP_QSTR_index: dest[0] = mp_obj_new_int_from_uint(data->index); break; // converting from unsigned int;
            case MP_QSTR_lenient_http_headers: dest[0] = mp_obj_new_int_from_uint(data->lenient_http_headers); break; // converting from unsigned int;
            case MP_QSTR_nread: dest[0] = mp_obj_new_int_from_uint(data->nread); break; // converting from uint32_t;
            case MP_QSTR_content_length: dest[0] = mp_obj_new_int_from_ull(data->content_length); break; // converting from uint64_t;
            case MP_QSTR_http_major: dest[0] = mp_obj_new_int_from_uint(data->http_major); break; // converting from unsigned short;
            case MP_QSTR_http_minor: dest[0] = mp_obj_new_int_from_uint(data->http_minor); break; // converting from unsigned short;
            case MP_QSTR_status_code: dest[0] = mp_obj_new_int_from_uint(data->status_code); break; // converting from unsigned int;
            case MP_QSTR_method: dest[0] = mp_obj_new_int_from_uint(data->method); break; // converting from unsigned int;
            case MP_QSTR_http_errno: dest[0] = mp_obj_new_int_from_uint(data->http_errno); break; // converting from unsigned int;
            case MP_QSTR_upgrade: dest[0] = mp_obj_new_int_from_uint(data->upgrade); break; // converting from unsigned int;
            case MP_QSTR_data: dest[0] = ptr_to_mp((void*)data->data); break; // converting from void *;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_type: data->type = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_flags: data->flags = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_state: data->state = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_header_state: data->header_state = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_index: data->index = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_lenient_http_headers: data->lenient_http_headers = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_nread: data->nread = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_content_length: data->content_length = (uint64_t)mp_obj_get_ull(dest[1]); break; // converting to uint64_t;
                case MP_QSTR_http_major: data->http_major = (unsigned short)mp_obj_get_int(dest[1]); break; // converting to unsigned short;
                case MP_QSTR_http_minor: data->http_minor = (unsigned short)mp_obj_get_int(dest[1]); break; // converting to unsigned short;
                case MP_QSTR_status_code: data->status_code = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_method: data->method = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_http_errno: data->http_errno = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_upgrade: data->upgrade = (unsigned int)mp_obj_get_int(dest[1]); break; // converting to unsigned int;
                case MP_QSTR_data: data->data = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_http_parser_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct http_parser");
}

STATIC const mp_obj_dict_t mp_http_parser_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_http_parser_type,
    MP_QSTR_http_parser,
    MP_TYPE_FLAG_NONE,
    print, mp_http_parser_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_http_parser_attr,
    locals_dict, &mp_http_parser_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_http_parser_type()
{
    return &mp_http_parser_type;
}
    
#define funcptr_http_cb NULL


/*
 * espidf extension definition for:
 * int http_cb(http_parser *)
 */

STATIC mp_obj_t mp_funcptr_http_cb(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser *arg0 = mp_write_ptr_http_parser(mp_args[0]);
    int _res = ((int (*)(http_parser *))lv_func_ptr)(arg0);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_http_cb_mpobj, 1, mp_funcptr_http_cb, funcptr_http_cb);
    
STATIC inline mp_obj_t mp_lv_funcptr_http_cb(void *func){ return mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_message_begin_callback'
 * http_cb on_message_begin
 */
    
#define funcptr_http_data_cb NULL


/*
 * espidf extension definition for:
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */

STATIC mp_obj_t mp_funcptr_http_data_cb(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser *arg0 = mp_write_ptr_http_parser(mp_args[0]);
    const char *at = (const char *)(char*)convert_from_str(mp_args[1]);
    size_t length = (size_t)mp_obj_get_int(mp_args[2]);
    int _res = ((int (*)(http_parser *, const char *, size_t))lv_func_ptr)(arg0, at, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_http_data_cb_mpobj, 3, mp_funcptr_http_data_cb, funcptr_http_data_cb);
    
STATIC inline mp_obj_t mp_lv_funcptr_http_data_cb(void *func){ return mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_url_callback'
 * http_data_cb on_url
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_status_callback'
 * http_data_cb on_status
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_header_field_callback'
 * http_data_cb on_header_field
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_header_value_callback'
 * http_data_cb on_header_value
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_headers_complete_callback'
 * http_cb on_headers_complete
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_body_callback'
 * http_data_cb on_body
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_message_complete_callback'
 * http_cb on_message_complete
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_chunk_header_callback'
 * http_cb on_chunk_header
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'http_parser_settings_on_chunk_complete_callback'
 * http_cb on_chunk_complete
 */
    

/*
 * Struct http_parser_settings
 */

STATIC inline const mp_obj_type_t *get_mp_http_parser_settings_type();

STATIC inline void* mp_write_ptr_http_parser_settings(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_http_parser_settings_type()));
    return (struct http_parser_settings*)self->data;
}

#define mp_write_http_parser_settings(struct_obj) *((struct http_parser_settings*)mp_write_ptr_http_parser_settings(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_http_parser_settings(void *field)
{
    return lv_to_mp_struct(get_mp_http_parser_settings_type(), field);
}

#define mp_read_http_parser_settings(field) mp_read_ptr_http_parser_settings(copy_buffer(&field, sizeof(struct http_parser_settings)))
#define mp_read_byref_http_parser_settings(field) mp_read_ptr_http_parser_settings(&field)

STATIC void mp_http_parser_settings_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED struct http_parser_settings *data = (struct http_parser_settings*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_on_message_begin: dest[0] = mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, data->on_message_begin, NULL ,MP_QSTR_http_parser_settings_on_message_begin, NULL); break; // converting from callback http_cb;
            case MP_QSTR_on_url: dest[0] = mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, data->on_url, NULL ,MP_QSTR_http_parser_settings_on_url, NULL); break; // converting from callback http_data_cb;
            case MP_QSTR_on_status: dest[0] = mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, data->on_status, NULL ,MP_QSTR_http_parser_settings_on_status, NULL); break; // converting from callback http_data_cb;
            case MP_QSTR_on_header_field: dest[0] = mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, data->on_header_field, NULL ,MP_QSTR_http_parser_settings_on_header_field, NULL); break; // converting from callback http_data_cb;
            case MP_QSTR_on_header_value: dest[0] = mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, data->on_header_value, NULL ,MP_QSTR_http_parser_settings_on_header_value, NULL); break; // converting from callback http_data_cb;
            case MP_QSTR_on_headers_complete: dest[0] = mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, data->on_headers_complete, NULL ,MP_QSTR_http_parser_settings_on_headers_complete, NULL); break; // converting from callback http_cb;
            case MP_QSTR_on_body: dest[0] = mp_lv_funcptr(&mp_funcptr_http_data_cb_mpobj, data->on_body, NULL ,MP_QSTR_http_parser_settings_on_body, NULL); break; // converting from callback http_data_cb;
            case MP_QSTR_on_message_complete: dest[0] = mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, data->on_message_complete, NULL ,MP_QSTR_http_parser_settings_on_message_complete, NULL); break; // converting from callback http_cb;
            case MP_QSTR_on_chunk_header: dest[0] = mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, data->on_chunk_header, NULL ,MP_QSTR_http_parser_settings_on_chunk_header, NULL); break; // converting from callback http_cb;
            case MP_QSTR_on_chunk_complete: dest[0] = mp_lv_funcptr(&mp_funcptr_http_cb_mpobj, data->on_chunk_complete, NULL ,MP_QSTR_http_parser_settings_on_chunk_complete, NULL); break; // converting from callback http_cb;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_on_message_begin: data->on_message_begin = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_message_begin, NULL, NULL, NULL, NULL); break; // converting to callback http_cb;
                case MP_QSTR_on_url: data->on_url = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_url, NULL, NULL, NULL, NULL); break; // converting to callback http_data_cb;
                case MP_QSTR_on_status: data->on_status = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_status, NULL, NULL, NULL, NULL); break; // converting to callback http_data_cb;
                case MP_QSTR_on_header_field: data->on_header_field = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_header_field, NULL, NULL, NULL, NULL); break; // converting to callback http_data_cb;
                case MP_QSTR_on_header_value: data->on_header_value = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_header_value, NULL, NULL, NULL, NULL); break; // converting to callback http_data_cb;
                case MP_QSTR_on_headers_complete: data->on_headers_complete = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_headers_complete, NULL, NULL, NULL, NULL); break; // converting to callback http_cb;
                case MP_QSTR_on_body: data->on_body = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_body, NULL, NULL, NULL, NULL); break; // converting to callback http_data_cb;
                case MP_QSTR_on_message_complete: data->on_message_complete = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_message_complete, NULL, NULL, NULL, NULL); break; // converting to callback http_cb;
                case MP_QSTR_on_chunk_header: data->on_chunk_header = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_chunk_header, NULL, NULL, NULL, NULL); break; // converting to callback http_cb;
                case MP_QSTR_on_chunk_complete: data->on_chunk_complete = mp_lv_callback(dest[1], NULL ,MP_QSTR_http_parser_settings_on_chunk_complete, NULL, NULL, NULL, NULL); break; // converting to callback http_cb;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_http_parser_settings_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct http_parser_settings");
}

STATIC const mp_obj_dict_t mp_http_parser_settings_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_http_parser_settings_type,
    MP_QSTR_http_parser_settings,
    MP_TYPE_FLAG_NONE,
    print, mp_http_parser_settings_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_http_parser_settings_attr,
    locals_dict, &mp_http_parser_settings_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_http_parser_settings_type()
{
    return &mp_http_parser_settings_type;
}
    

/*
 * http_parser_url * not generated: Missing conversion to struct 
{
  uint16_t off;
  uint16_t len;
} while generating array type conversion
 */
                

/*
 * Struct nghttp2_session
 */

STATIC inline const mp_obj_type_t *get_mp_nghttp2_session_type();

STATIC inline void* mp_write_ptr_nghttp2_session(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_nghttp2_session_type()));
    return (nghttp2_session*)self->data;
}

#define mp_write_nghttp2_session(struct_obj) *((nghttp2_session*)mp_write_ptr_nghttp2_session(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_nghttp2_session(void *field)
{
    return lv_to_mp_struct(get_mp_nghttp2_session_type(), field);
}

#define mp_read_nghttp2_session(field) mp_read_ptr_nghttp2_session(copy_buffer(&field, sizeof(nghttp2_session)))
#define mp_read_byref_nghttp2_session(field) mp_read_ptr_nghttp2_session(&field)

STATIC void mp_nghttp2_session_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED nghttp2_session *data = (nghttp2_session*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_nghttp2_session_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct nghttp2_session");
}

STATIC const mp_obj_dict_t mp_nghttp2_session_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_nghttp2_session_type,
    MP_QSTR_nghttp2_session,
    MP_TYPE_FLAG_NONE,
    print, mp_nghttp2_session_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_nghttp2_session_attr,
    locals_dict, &mp_nghttp2_session_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_nghttp2_session_type()
{
    return &mp_nghttp2_session_type;
}
    

/*
 * Struct esp_tls
 */

STATIC inline const mp_obj_type_t *get_mp_esp_tls_type();

STATIC inline void* mp_write_ptr_esp_tls(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_tls_type()));
    return (esp_tls*)self->data;
}

#define mp_write_esp_tls(struct_obj) *((esp_tls*)mp_write_ptr_esp_tls(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_tls(void *field)
{
    return lv_to_mp_struct(get_mp_esp_tls_type(), field);
}

#define mp_read_esp_tls(field) mp_read_ptr_esp_tls(copy_buffer(&field, sizeof(esp_tls)))
#define mp_read_byref_esp_tls(field) mp_read_ptr_esp_tls(&field)

STATIC void mp_esp_tls_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_tls *data = (esp_tls*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_tls_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_tls");
}

STATIC const mp_obj_dict_t mp_esp_tls_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_tls_type,
    MP_QSTR_esp_tls,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_tls_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_tls_attr,
    locals_dict, &mp_esp_tls_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_tls_type()
{
    return &mp_esp_tls_type;
}
    

/*
 * Struct esp_tls_cfg
 */

STATIC inline const mp_obj_type_t *get_mp_esp_tls_cfg_type();

STATIC inline void* mp_write_ptr_esp_tls_cfg(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_tls_cfg_type()));
    return (esp_tls_cfg*)self->data;
}

#define mp_write_esp_tls_cfg(struct_obj) *((esp_tls_cfg*)mp_write_ptr_esp_tls_cfg(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_tls_cfg(void *field)
{
    return lv_to_mp_struct(get_mp_esp_tls_cfg_type(), field);
}

#define mp_read_esp_tls_cfg(field) mp_read_ptr_esp_tls_cfg(copy_buffer(&field, sizeof(esp_tls_cfg)))
#define mp_read_byref_esp_tls_cfg(field) mp_read_ptr_esp_tls_cfg(&field)

STATIC void mp_esp_tls_cfg_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_tls_cfg *data = (esp_tls_cfg*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            ;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                ;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_tls_cfg_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_tls_cfg");
}

STATIC const mp_obj_dict_t mp_esp_tls_cfg_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_tls_cfg_type,
    MP_QSTR_esp_tls_cfg,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_tls_cfg_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_tls_cfg_attr,
    locals_dict, &mp_esp_tls_cfg_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_tls_cfg_type()
{
    return &mp_esp_tls_cfg_type;
}
    

/*
 * Struct sh2lib_handle
 */

STATIC inline const mp_obj_type_t *get_mp_sh2lib_handle_type();

STATIC inline void* mp_write_ptr_sh2lib_handle(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_sh2lib_handle_type()));
    return (struct sh2lib_handle*)self->data;
}

#define mp_write_sh2lib_handle(struct_obj) *((struct sh2lib_handle*)mp_write_ptr_sh2lib_handle(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_sh2lib_handle(void *field)
{
    return lv_to_mp_struct(get_mp_sh2lib_handle_type(), field);
}

#define mp_read_sh2lib_handle(field) mp_read_ptr_sh2lib_handle(copy_buffer(&field, sizeof(struct sh2lib_handle)))
#define mp_read_byref_sh2lib_handle(field) mp_read_ptr_sh2lib_handle(&field)

STATIC void mp_sh2lib_handle_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED struct sh2lib_handle *data = (struct sh2lib_handle*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_http2_sess: dest[0] = mp_read_ptr_nghttp2_session((void*)data->http2_sess); break; // converting from nghttp2_session *;
            case MP_QSTR_hostname: dest[0] = convert_to_str((void*)data->hostname); break; // converting from char *;
            case MP_QSTR_http2_tls: dest[0] = mp_read_ptr_esp_tls((void*)data->http2_tls); break; // converting from esp_tls *;
            case MP_QSTR_http2_tls_cfg: dest[0] = mp_read_ptr_esp_tls_cfg((void*)data->http2_tls_cfg); break; // converting from esp_tls_cfg *;
            case MP_QSTR_user_data: dest[0] = ptr_to_mp((void*)data->user_data); break; // converting from void *;
            case MP_QSTR_connect_task_handle: dest[0] = ptr_to_mp(data->connect_task_handle); break; // converting from TaskHandle_t;
            case MP_QSTR_connect_result: dest[0] = mp_obj_new_int(data->connect_result); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_http2_sess: data->http2_sess = (void*)mp_write_ptr_nghttp2_session(dest[1]); break; // converting to nghttp2_session *;
                case MP_QSTR_hostname: data->hostname = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_http2_tls: data->http2_tls = (void*)mp_write_ptr_esp_tls(dest[1]); break; // converting to esp_tls *;
                case MP_QSTR_http2_tls_cfg: data->http2_tls_cfg = (void*)mp_write_ptr_esp_tls_cfg(dest[1]); break; // converting to esp_tls_cfg *;
                case MP_QSTR_user_data: data->user_data = (void*)mp_to_ptr(dest[1]); break; // converting to void *;
                case MP_QSTR_connect_task_handle: data->connect_task_handle = mp_to_ptr(dest[1]); break; // converting to TaskHandle_t;
                case MP_QSTR_connect_result: data->connect_result = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_sh2lib_handle_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct sh2lib_handle");
}

STATIC const mp_obj_dict_t mp_sh2lib_handle_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_sh2lib_handle_type,
    MP_QSTR_sh2lib_handle,
    MP_TYPE_FLAG_NONE,
    print, mp_sh2lib_handle_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_sh2lib_handle_attr,
    locals_dict, &mp_sh2lib_handle_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_sh2lib_handle_type()
{
    return &mp_sh2lib_handle_type;
}
    

STATIC const mp_rom_map_elem_t mp_C_Pointer_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(C_Pointer))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_C_Pointer_locals_dict, mp_C_Pointer_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp__lv_mp_int_wrapper_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(_lv_mp_int_wrapper))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp__lv_mp_int_wrapper_locals_dict, mp__lv_mp_int_wrapper_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp__lv_mp_char_ptr_wrapper_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(_lv_mp_char_ptr_wrapper))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp__lv_mp_char_ptr_wrapper_locals_dict, mp__lv_mp_char_ptr_wrapper_locals_dict_table);
        

/*
 * espidf extension definition for:
 * char *ipaddr_ntoa(const ip_addr_t *addr)
 */

STATIC mp_obj_t mp_ipaddr_ntoa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip_addr_t *addr = (const ip_addr_t *)mp_write_ptr_ip_addr_t(mp_args[0]);
    char * _res = ((char *(*)(const ip_addr_t *))lv_func_ptr)(addr);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ipaddr_ntoa_mpobj, 1, mp_ipaddr_ntoa, ipaddr_ntoa);
    

/*
 * espidf extension definition for:
 * char *ipaddr_ntoa_r(const ip_addr_t *addr, char *buf, int buflen)
 */

STATIC mp_obj_t mp_ipaddr_ntoa_r(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip_addr_t *addr = (const ip_addr_t *)mp_write_ptr_ip_addr_t(mp_args[0]);
    char *buf = (char*)convert_from_str(mp_args[1]);
    int buflen = (int)mp_obj_get_int(mp_args[2]);
    char * _res = ((char *(*)(const ip_addr_t *, char *, int))lv_func_ptr)(addr, buf, buflen);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ipaddr_ntoa_r_mpobj, 3, mp_ipaddr_ntoa_r, ipaddr_ntoa_r);
    

STATIC const mp_rom_map_elem_t mp_ip_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(ip_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_paddr_ntoa), MP_ROM_PTR(&mp_ipaddr_ntoa_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_paddr_ntoa_r), MP_ROM_PTR(&mp_ipaddr_ntoa_r_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_ip_addr_t_locals_dict, mp_ip_addr_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_ip_addr_u_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(ip_addr_u_addr_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_ip_addr_u_addr_t_locals_dict, mp_ip_addr_u_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * char *ip6addr_ntoa(const ip6_addr_t *addr)
 */

STATIC mp_obj_t mp_ip6addr_ntoa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip6_addr_t *addr = (const ip6_addr_t *)mp_write_ptr_ip6_addr_t(mp_args[0]);
    char * _res = ((char *(*)(const ip6_addr_t *))lv_func_ptr)(addr);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ip6addr_ntoa_mpobj, 1, mp_ip6addr_ntoa, ip6addr_ntoa);
    

/*
 * espidf extension definition for:
 * char *ip6addr_ntoa_r(const ip6_addr_t *addr, char *buf, int buflen)
 */

STATIC mp_obj_t mp_ip6addr_ntoa_r(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip6_addr_t *addr = (const ip6_addr_t *)mp_write_ptr_ip6_addr_t(mp_args[0]);
    char *buf = (char*)convert_from_str(mp_args[1]);
    int buflen = (int)mp_obj_get_int(mp_args[2]);
    char * _res = ((char *(*)(const ip6_addr_t *, char *, int))lv_func_ptr)(addr, buf, buflen);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ip6addr_ntoa_r_mpobj, 3, mp_ip6addr_ntoa_r, ip6addr_ntoa_r);
    

STATIC const mp_rom_map_elem_t mp_ip6_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(ip6_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_p6addr_ntoa), MP_ROM_PTR(&mp_ip6addr_ntoa_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_p6addr_ntoa_r), MP_ROM_PTR(&mp_ip6addr_ntoa_r_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_ip6_addr_t_locals_dict, mp_ip6_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * char *ip4addr_ntoa(const ip4_addr_t *addr)
 */

STATIC mp_obj_t mp_ip4addr_ntoa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip4_addr_t *addr = (const ip4_addr_t *)mp_write_ptr_ip4_addr_t(mp_args[0]);
    char * _res = ((char *(*)(const ip4_addr_t *))lv_func_ptr)(addr);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ip4addr_ntoa_mpobj, 1, mp_ip4addr_ntoa, ip4addr_ntoa);
    

/*
 * espidf extension definition for:
 * char *ip4addr_ntoa_r(const ip4_addr_t *addr, char *buf, int buflen)
 */

STATIC mp_obj_t mp_ip4addr_ntoa_r(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip4_addr_t *addr = (const ip4_addr_t *)mp_write_ptr_ip4_addr_t(mp_args[0]);
    char *buf = (char*)convert_from_str(mp_args[1]);
    int buflen = (int)mp_obj_get_int(mp_args[2]);
    char * _res = ((char *(*)(const ip4_addr_t *, char *, int))lv_func_ptr)(addr, buf, buflen);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_ip4addr_ntoa_r_mpobj, 3, mp_ip4addr_ntoa_r, ip4addr_ntoa_r);
    

STATIC const mp_rom_map_elem_t mp_ip4_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(ip4_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_p4addr_ntoa), MP_ROM_PTR(&mp_ip4addr_ntoa_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_p4addr_ntoa_r), MP_ROM_PTR(&mp_ip4addr_ntoa_r_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_ip4_addr_t_locals_dict, mp_ip4_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * inline static void esp_netif_ip_addr_copy(esp_ip_addr_t *dest, const esp_ip_addr_t *src)
 */

STATIC mp_obj_t mp_esp_netif_ip_addr_copy(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_ip_addr_t *dest = mp_write_ptr_esp_ip_addr_t(mp_args[0]);
    const esp_ip_addr_t *src = (const esp_ip_addr_t *)mp_write_ptr_esp_ip_addr_t(mp_args[1]);
    ((void (*)(esp_ip_addr_t *, const esp_ip_addr_t *))lv_func_ptr)(dest, src);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_ip_addr_copy_mpobj, 2, mp_esp_netif_ip_addr_copy, esp_netif_ip_addr_copy);
    

STATIC const mp_rom_map_elem_t mp_esp_ip_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_ip_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_netif_ip_addr_copy), MP_ROM_PTR(&mp_esp_netif_ip_addr_copy_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_ip_addr_t_locals_dict, mp_esp_ip_addr_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_ip_addr_u_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_ip_addr_u_addr_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_ip_addr_u_addr_t_locals_dict, mp_esp_ip_addr_u_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_ip6_addr_type_t esp_netif_ip6_get_addr_type(esp_ip6_addr_t *ip6_addr)
 */

STATIC mp_obj_t mp_esp_netif_ip6_get_addr_type(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_ip6_addr_t *ip6_addr = mp_write_ptr_esp_ip6_addr_t(mp_args[0]);
    esp_ip6_addr_type_t _res = ((esp_ip6_addr_type_t (*)(esp_ip6_addr_t *))lv_func_ptr)(ip6_addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_ip6_get_addr_type_mpobj, 1, mp_esp_netif_ip6_get_addr_type, esp_netif_ip6_get_addr_type);
    

STATIC const mp_rom_map_elem_t mp_esp_ip6_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_ip6_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_netif_ip6_get_addr_type), MP_ROM_PTR(&mp_esp_netif_ip6_get_addr_type_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_ip6_addr_t_locals_dict, mp_esp_ip6_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void esp_netif_set_ip4_addr(esp_ip4_addr_t *addr, uint8_t a, uint8_t b, uint8_t c, uint8_t d)
 */

STATIC mp_obj_t mp_esp_netif_set_ip4_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_ip4_addr_t *addr = mp_write_ptr_esp_ip4_addr_t(mp_args[0]);
    uint8_t a = (uint8_t)mp_obj_get_int(mp_args[1]);
    uint8_t b = (uint8_t)mp_obj_get_int(mp_args[2]);
    uint8_t c = (uint8_t)mp_obj_get_int(mp_args[3]);
    uint8_t d = (uint8_t)mp_obj_get_int(mp_args[4]);
    ((void (*)(esp_ip4_addr_t *, uint8_t, uint8_t, uint8_t, uint8_t))lv_func_ptr)(addr, a, b, c, d);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_ip4_addr_mpobj, 5, mp_esp_netif_set_ip4_addr, esp_netif_set_ip4_addr);
    

/*
 * espidf extension definition for:
 * char *esp_ip4addr_ntoa(const esp_ip4_addr_t *addr, char *buf, int buflen)
 */

STATIC mp_obj_t mp_esp_ip4addr_ntoa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const esp_ip4_addr_t *addr = (const esp_ip4_addr_t *)mp_write_ptr_esp_ip4_addr_t(mp_args[0]);
    char *buf = (char*)convert_from_str(mp_args[1]);
    int buflen = (int)mp_obj_get_int(mp_args[2]);
    char * _res = ((char *(*)(const esp_ip4_addr_t *, char *, int))lv_func_ptr)(addr, buf, buflen);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_ip4addr_ntoa_mpobj, 3, mp_esp_ip4addr_ntoa, esp_ip4addr_ntoa);
    

STATIC const mp_rom_map_elem_t mp_esp_ip4_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_ip4_addr_t))) },
    { MP_ROM_QSTR(MP_QSTR_netif_set_ip4_addr), MP_ROM_PTR(&mp_esp_netif_set_ip4_addr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ip4addr_ntoa), MP_ROM_PTR(&mp_esp_ip4addr_ntoa_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_ip4_addr_t_locals_dict, mp_esp_ip4_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * inline static esp_eth_phy_t *esp_eth_phy_new_lan8720(const eth_phy_config_t *config)
 */

STATIC mp_obj_t mp_esp_eth_phy_new_lan8720(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const eth_phy_config_t *config = (const eth_phy_config_t *)mp_write_ptr_eth_phy_config_t(mp_args[0]);
    esp_eth_phy_t * _res = ((esp_eth_phy_t *(*)(const eth_phy_config_t *))lv_func_ptr)(config);
    return mp_read_ptr_esp_eth_phy_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_lan8720_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_lan8720);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_ip101 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_ip101_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_ip101);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_rtl8201 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_rtl8201_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_rtl8201);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_lan87xx */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_lan87xx_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_lan87xx);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_dp83848 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_dp83848_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_dp83848);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_ksz8041 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_ksz8041_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_ksz8041);
    
/* Reusing esp_eth_phy_new_lan8720 for esp_eth_phy_new_ksz8081 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_phy_new_ksz8081_mpobj, 1, mp_esp_eth_phy_new_lan8720, esp_eth_phy_new_ksz8081);
    

STATIC const mp_rom_map_elem_t mp_eth_phy_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(eth_phy_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_lan8720), MP_ROM_PTR(&mp_esp_eth_phy_new_lan8720_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_ip101), MP_ROM_PTR(&mp_esp_eth_phy_new_ip101_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_rtl8201), MP_ROM_PTR(&mp_esp_eth_phy_new_rtl8201_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_lan87xx), MP_ROM_PTR(&mp_esp_eth_phy_new_lan87xx_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_dp83848), MP_ROM_PTR(&mp_esp_eth_phy_new_dp83848_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_ksz8041), MP_ROM_PTR(&mp_esp_eth_phy_new_ksz8041_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_phy_new_ksz8081), MP_ROM_PTR(&mp_esp_eth_phy_new_ksz8081_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_eth_phy_config_t_locals_dict, mp_eth_phy_config_t_locals_dict_table);
        

/*
 * Callback function esp_http_client_register_event_handler_http_event_handler
 * esp_err_t http_event_handle_cb(esp_http_client_event_t *evt)
 */

GENMPY_UNUSED STATIC esp_err_t esp_http_client_register_event_handler_http_event_handler_callback(esp_http_client_event_t *arg0)
{
    mp_obj_t mp_args[1];
    mp_args[0] = mp_read_ptr_esp_http_client_event_t((void*)arg0);
    mp_obj_t callbacks = get_callback_dict_from_user_data(arg0->user_data);
    _nesting++;
    mp_obj_t callback_result = mp_call_function_n_kw(mp_obj_dict_get(callbacks, MP_OBJ_NEW_QSTR(MP_QSTR_esp_http_client_register_event_handler_http_event_handler)) , 1, 0, mp_args);
    _nesting--;
    return (int)mp_obj_get_int(callback_result);
}


/*
 * espidf extension definition for:
 * inline static void esp_http_client_register_event_handler(esp_http_client_config_t *config, http_event_handle_cb http_event_handler, void *user_data)
 */

STATIC mp_obj_t mp_esp_http_client_register_event_handler(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *user_data = mp_to_ptr(mp_args[2]);
    void *http_event_handler = mp_lv_callback(mp_args[1], &esp_http_client_register_event_handler_http_event_handler_callback, MP_QSTR_esp_http_client_register_event_handler_http_event_handler, &user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    esp_http_client_config_t *config = mp_write_ptr_esp_http_client_config_t(mp_args[0]);
    ((void (*)(esp_http_client_config_t *, http_event_handle_cb, void *))lv_func_ptr)(config, http_event_handler, user_data);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_http_client_register_event_handler_mpobj, 3, mp_esp_http_client_register_event_handler, esp_http_client_register_event_handler);
    

/*
 * espidf extension definition for:
 * esp_http_client_handle_t esp_http_client_init(const esp_http_client_config_t *config)
 */

STATIC mp_obj_t mp_esp_http_client_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const esp_http_client_config_t *config = (const esp_http_client_config_t *)mp_write_ptr_esp_http_client_config_t(mp_args[0]);
    esp_http_client_handle_t _res = ((esp_http_client_handle_t (*)(const esp_http_client_config_t *))lv_func_ptr)(config);
    return ptr_to_mp(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_http_client_init_mpobj, 1, mp_esp_http_client_init, esp_http_client_init);
    

STATIC const mp_rom_map_elem_t mp_esp_http_client_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_http_client_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_register_event_handler), MP_ROM_PTR(&mp_esp_http_client_register_event_handler_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&mp_esp_http_client_init_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_http_client_config_t_locals_dict, mp_esp_http_client_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_http_client_event_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_http_client_event_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_http_client_event_t_locals_dict, mp_esp_http_client_event_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * inline static void set_spi_transaction_ext(spi_transaction_ext_t *ext_trans, spi_transaction_t *trans, uint8_t command_bits, uint8_t address_bits)
 */

STATIC mp_obj_t mp_set_spi_transaction_ext(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_transaction_ext_t *ext_trans = mp_write_ptr_spi_transaction_ext_t(mp_args[0]);
    spi_transaction_t *trans = mp_write_ptr_spi_transaction_t(mp_args[1]);
    uint8_t command_bits = (uint8_t)mp_obj_get_int(mp_args[2]);
    uint8_t address_bits = (uint8_t)mp_obj_get_int(mp_args[3]);
    ((void (*)(spi_transaction_ext_t *, spi_transaction_t *, uint8_t, uint8_t))lv_func_ptr)(ext_trans, trans, command_bits, address_bits);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_set_spi_transaction_ext_mpobj, 4, mp_set_spi_transaction_ext, set_spi_transaction_ext);
    

STATIC const mp_rom_map_elem_t mp_spi_transaction_ext_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(spi_transaction_ext_t))) },
    { MP_ROM_QSTR(MP_QSTR_et_spi_transaction_ext), MP_ROM_PTR(&mp_set_spi_transaction_ext_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_spi_transaction_ext_t_locals_dict, mp_spi_transaction_ext_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_spi_transaction_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(struct spi_transaction_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_spi_transaction_t_locals_dict, mp_spi_transaction_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t gpio_config(const gpio_config_t *pGPIOConfig)
 */

STATIC mp_obj_t mp_gpio_config(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const gpio_config_t *pGPIOConfig = (const gpio_config_t *)mp_write_ptr_gpio_config_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const gpio_config_t *))lv_func_ptr)(pGPIOConfig);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_gpio_config_mpobj, 1, mp_gpio_config, gpio_config);
    

STATIC const mp_rom_map_elem_t mp_gpio_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(gpio_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_config), MP_ROM_PTR(&mp_gpio_config_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_gpio_config_t_locals_dict, mp_gpio_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_multi_heap_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(multi_heap_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_multi_heap_info_t_locals_dict, mp_multi_heap_info_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t adc_digi_initialize(const adc_digi_init_config_t *init_config)
 */

STATIC mp_obj_t mp_adc_digi_initialize(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const adc_digi_init_config_t *init_config = (const adc_digi_init_config_t *)mp_write_ptr_adc_digi_init_config_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const adc_digi_init_config_t *))lv_func_ptr)(init_config);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_adc_digi_initialize_mpobj, 1, mp_adc_digi_initialize, adc_digi_initialize);
    

STATIC const mp_rom_map_elem_t mp_adc_digi_init_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(adc_digi_init_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_initialize), MP_ROM_PTR(&mp_adc_digi_initialize_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_adc_digi_init_config_t_locals_dict, mp_adc_digi_init_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t adc_digi_controller_configure(const adc_digi_configuration_t *config)
 */

STATIC mp_obj_t mp_adc_digi_controller_configure(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const adc_digi_configuration_t *config = (const adc_digi_configuration_t *)mp_write_ptr_adc_digi_configuration_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const adc_digi_configuration_t *))lv_func_ptr)(config);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_adc_digi_controller_configure_mpobj, 1, mp_adc_digi_controller_configure, adc_digi_controller_configure);
    

STATIC const mp_rom_map_elem_t mp_adc_digi_configuration_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(adc_digi_configuration_t))) },
    { MP_ROM_QSTR(MP_QSTR_controller_configure), MP_ROM_PTR(&mp_adc_digi_controller_configure_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_adc_digi_configuration_t_locals_dict, mp_adc_digi_configuration_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_adc_digi_pattern_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(adc_digi_pattern_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_adc_digi_pattern_config_t_locals_dict, mp_adc_digi_pattern_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t pcnt_unit_config(const pcnt_config_t *pcnt_config)
 */

STATIC mp_obj_t mp_pcnt_unit_config(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const pcnt_config_t *pcnt_config = (const pcnt_config_t *)mp_write_ptr_pcnt_config_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const pcnt_config_t *))lv_func_ptr)(pcnt_config);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_pcnt_unit_config_mpobj, 1, mp_pcnt_unit_config, pcnt_unit_config);
    

STATIC const mp_rom_map_elem_t mp_pcnt_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(pcnt_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_unit_config), MP_ROM_PTR(&mp_pcnt_unit_config_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_pcnt_config_t_locals_dict, mp_pcnt_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_detect_phy_addr(esp_eth_mediator_t *eth, int *detected_addr)
 */

STATIC mp_obj_t mp_esp_eth_detect_phy_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_mediator_t *eth = mp_write_ptr_esp_eth_mediator_t(mp_args[0]);
    int *detected_addr = mp_array_to_i32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_mediator_t *, int *))lv_func_ptr)(eth, detected_addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_detect_phy_addr_mpobj, 2, mp_esp_eth_detect_phy_addr, esp_eth_detect_phy_addr);
    

STATIC const mp_rom_map_elem_t mp_esp_eth_mediator_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_eth_mediator_t))) },
    { MP_ROM_QSTR(MP_QSTR_detect_phy_addr), MP_ROM_PTR(&mp_esp_eth_detect_phy_addr_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_eth_mediator_t_locals_dict, mp_esp_eth_mediator_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_eth_mac_t *esp_eth_mac_new_esp32(const eth_mac_config_t *config)
 */

STATIC mp_obj_t mp_esp_eth_mac_new_esp32(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const eth_mac_config_t *config = (const eth_mac_config_t *)mp_write_ptr_eth_mac_config_t(mp_args[0]);
    esp_eth_mac_t * _res = ((esp_eth_mac_t *(*)(const eth_mac_config_t *))lv_func_ptr)(config);
    return mp_read_ptr_esp_eth_mac_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_mac_new_esp32_mpobj, 1, mp_esp_eth_mac_new_esp32, esp_eth_mac_new_esp32);
    

STATIC const mp_rom_map_elem_t mp_eth_mac_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(eth_mac_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_sp_eth_mac_new_esp32), MP_ROM_PTR(&mp_esp_eth_mac_new_esp32_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_eth_mac_config_t_locals_dict, mp_eth_mac_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_eth_mac_clock_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(eth_mac_clock_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_eth_mac_clock_config_t_locals_dict, mp_eth_mac_clock_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_eth_mac_clock_config_mii_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(eth_mac_clock_config_mii_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_eth_mac_clock_config_mii_t_locals_dict, mp_eth_mac_clock_config_mii_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_eth_mac_clock_config_rmii_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(eth_mac_clock_config_rmii_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_eth_mac_clock_config_rmii_t_locals_dict, mp_eth_mac_clock_config_rmii_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_driver_install(const esp_eth_config_t *config, esp_eth_handle_t *out_hdl)
 */

STATIC mp_obj_t mp_esp_eth_driver_install(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const esp_eth_config_t *config = (const esp_eth_config_t *)mp_write_ptr_esp_eth_config_t(mp_args[0]);
    esp_eth_handle_t *out_hdl = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const esp_eth_config_t *, esp_eth_handle_t *))lv_func_ptr)(config, out_hdl);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_eth_driver_install_mpobj, 2, mp_esp_eth_driver_install, esp_eth_driver_install);
    

STATIC const mp_rom_map_elem_t mp_esp_eth_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_eth_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_driver_install), MP_ROM_PTR(&mp_esp_eth_driver_install_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_eth_config_t_locals_dict, mp_esp_eth_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_eth_mac_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_eth_mac_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_eth_mac_t_locals_dict, mp_esp_eth_mac_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_eth_phy_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_eth_phy_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_eth_phy_t_locals_dict, mp_esp_eth_phy_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void esp_chip_info(esp_chip_info_t *out_info)
 */

STATIC mp_obj_t mp_esp_chip_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_chip_info_t *out_info = mp_write_ptr_esp_chip_info_t(mp_args[0]);
    ((void (*)(esp_chip_info_t *))lv_func_ptr)(out_info);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_chip_info_mpobj, 1, mp_esp_chip_info, esp_chip_info);
    

STATIC const mp_rom_map_elem_t mp_esp_chip_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_chip_info_t))) },
    { MP_ROM_QSTR(MP_QSTR_info), MP_ROM_PTR(&mp_esp_chip_info_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_chip_info_t_locals_dict, mp_esp_chip_info_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_wifi_sta_list_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(wifi_sta_list_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_wifi_sta_list_t_locals_dict, mp_wifi_sta_list_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_wifi_sta_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(wifi_sta_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_wifi_sta_info_t_locals_dict, mp_wifi_sta_info_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void esp_netif_destroy(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_destroy(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    ((void (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_destroy_mpobj, 1, mp_esp_netif_destroy, esp_netif_destroy);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_set_driver_config(esp_netif_t *esp_netif, const esp_netif_driver_ifconfig_t *driver_config)
 */

STATIC mp_obj_t mp_esp_netif_set_driver_config(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    const esp_netif_driver_ifconfig_t *driver_config = (const esp_netif_driver_ifconfig_t *)mp_write_ptr_esp_netif_driver_ifconfig_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, const esp_netif_driver_ifconfig_t *))lv_func_ptr)(esp_netif, driver_config);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_driver_config_mpobj, 2, mp_esp_netif_set_driver_config, esp_netif_set_driver_config);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_attach(esp_netif_t *esp_netif, esp_netif_iodriver_handle driver_handle)
 */

STATIC mp_obj_t mp_esp_netif_attach(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_iodriver_handle driver_handle = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_netif_iodriver_handle))lv_func_ptr)(esp_netif, driver_handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_attach_mpobj, 2, mp_esp_netif_attach, esp_netif_attach);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_receive(esp_netif_t *esp_netif, void *buffer, size_t len, void *eb)
 */

STATIC mp_obj_t mp_esp_netif_receive(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    void *buffer = mp_to_ptr(mp_args[1]);
    size_t len = (size_t)mp_obj_get_int(mp_args[2]);
    void *eb = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, void *, size_t, void *))lv_func_ptr)(esp_netif, buffer, len, eb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_receive_mpobj, 4, mp_esp_netif_receive, esp_netif_receive);
    

/*
 * Array convertors for uint8_t []
 */

GENMPY_UNUSED STATIC uint8_t *mp_arr_to_uint8_t_____(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    
    uint8_t *lv_arr = (uint8_t*)m_malloc(len * sizeof(uint8_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = (uint8_t)mp_obj_get_int(item);
    }
    return (uint8_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_uint8_t_____(uint8_t *arr)
{
    return mp_array_from_u8ptr((void*)arr);
}


/*
 * espidf extension definition for:
 * esp_err_t esp_netif_set_mac(esp_netif_t *esp_netif, uint8_t mac[])
 */

STATIC mp_obj_t mp_esp_netif_set_mac(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    uint8_t *mac = mp_arr_to_uint8_t_____(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, uint8_t []))lv_func_ptr)(esp_netif, mac);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_mac_mpobj, 2, mp_esp_netif_set_mac, esp_netif_set_mac);
    
/* Reusing esp_netif_set_mac for esp_netif_get_mac */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_mac_mpobj, 2, mp_esp_netif_set_mac, esp_netif_get_mac);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_set_hostname(esp_netif_t *esp_netif, const char *hostname)
 */

STATIC mp_obj_t mp_esp_netif_set_hostname(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, const char *))lv_func_ptr)(esp_netif, hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_hostname_mpobj, 2, mp_esp_netif_set_hostname, esp_netif_set_hostname);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_get_hostname(esp_netif_t *esp_netif, const char **hostname)
 */

STATIC mp_obj_t mp_esp_netif_get_hostname(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    const char **hostname = (const char **)mp_write_ptr_C_Pointer(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, const char **))lv_func_ptr)(esp_netif, hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_hostname_mpobj, 2, mp_esp_netif_get_hostname, esp_netif_get_hostname);
    

/*
 * espidf extension definition for:
 * bool esp_netif_is_netif_up(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_is_netif_up(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    bool _res = ((bool (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_is_netif_up_mpobj, 1, mp_esp_netif_is_netif_up, esp_netif_is_netif_up);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_get_ip_info(esp_netif_t *esp_netif, esp_netif_ip_info_t *ip_info)
 */

STATIC mp_obj_t mp_esp_netif_get_ip_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_ip_info_t *ip_info = mp_write_ptr_esp_netif_ip_info_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_netif_ip_info_t *))lv_func_ptr)(esp_netif, ip_info);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_ip_info_mpobj, 2, mp_esp_netif_get_ip_info, esp_netif_get_ip_info);
    
/* Reusing esp_netif_get_ip_info for esp_netif_get_old_ip_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_old_ip_info_mpobj, 2, mp_esp_netif_get_ip_info, esp_netif_get_old_ip_info);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_set_ip_info(esp_netif_t *esp_netif, const esp_netif_ip_info_t *ip_info)
 */

STATIC mp_obj_t mp_esp_netif_set_ip_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    const esp_netif_ip_info_t *ip_info = (const esp_netif_ip_info_t *)mp_write_ptr_esp_netif_ip_info_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, const esp_netif_ip_info_t *))lv_func_ptr)(esp_netif, ip_info);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_ip_info_mpobj, 2, mp_esp_netif_set_ip_info, esp_netif_set_ip_info);
    
/* Reusing esp_netif_set_ip_info for esp_netif_set_old_ip_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_old_ip_info_mpobj, 2, mp_esp_netif_set_ip_info, esp_netif_set_old_ip_info);
    

/*
 * espidf extension definition for:
 * int esp_netif_get_netif_impl_index(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_get_netif_impl_index(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    int _res = ((int (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_netif_impl_index_mpobj, 1, mp_esp_netif_get_netif_impl_index, esp_netif_get_netif_impl_index);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_get_netif_impl_name(esp_netif_t *esp_netif, char *name)
 */

STATIC mp_obj_t mp_esp_netif_get_netif_impl_name(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    char *name = (char*)convert_from_str(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, char *))lv_func_ptr)(esp_netif, name);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_netif_impl_name_mpobj, 2, mp_esp_netif_get_netif_impl_name, esp_netif_get_netif_impl_name);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_dhcps_option(esp_netif_t *esp_netif, esp_netif_dhcp_option_mode_t opt_op, esp_netif_dhcp_option_id_t opt_id, void *opt_val, uint32_t opt_len)
 */

STATIC mp_obj_t mp_esp_netif_dhcps_option(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_dhcp_option_mode_t opt_op = (int)mp_obj_get_int(mp_args[1]);
    esp_netif_dhcp_option_id_t opt_id = (int)mp_obj_get_int(mp_args[2]);
    void *opt_val = mp_to_ptr(mp_args[3]);
    uint32_t opt_len = (uint32_t)mp_obj_get_int(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_netif_dhcp_option_mode_t, esp_netif_dhcp_option_id_t, void *, uint32_t))lv_func_ptr)(esp_netif, opt_op, opt_id, opt_val, opt_len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcps_option_mpobj, 5, mp_esp_netif_dhcps_option, esp_netif_dhcps_option);
    
/* Reusing esp_netif_dhcps_option for esp_netif_dhcpc_option */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcpc_option_mpobj, 5, mp_esp_netif_dhcps_option, esp_netif_dhcpc_option);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_dhcpc_start(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_dhcpc_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcpc_start_mpobj, 1, mp_esp_netif_dhcpc_start, esp_netif_dhcpc_start);
    
/* Reusing esp_netif_dhcpc_start for esp_netif_dhcpc_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcpc_stop_mpobj, 1, mp_esp_netif_dhcpc_start, esp_netif_dhcpc_stop);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_dhcpc_get_status(esp_netif_t *esp_netif, esp_netif_dhcp_status_t *status)
 */

STATIC mp_obj_t mp_esp_netif_dhcpc_get_status(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_dhcp_status_t *status = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_netif_dhcp_status_t *))lv_func_ptr)(esp_netif, status);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcpc_get_status_mpobj, 2, mp_esp_netif_dhcpc_get_status, esp_netif_dhcpc_get_status);
    
/* Reusing esp_netif_dhcpc_get_status for esp_netif_dhcps_get_status */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcps_get_status_mpobj, 2, mp_esp_netif_dhcpc_get_status, esp_netif_dhcps_get_status);
    
/* Reusing esp_netif_dhcpc_start for esp_netif_dhcps_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcps_start_mpobj, 1, mp_esp_netif_dhcpc_start, esp_netif_dhcps_start);
    
/* Reusing esp_netif_dhcpc_start for esp_netif_dhcps_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_dhcps_stop_mpobj, 1, mp_esp_netif_dhcpc_start, esp_netif_dhcps_stop);
    

/*
 * Struct esp_netif_dns_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_dns_info_t_type();

STATIC inline void* mp_write_ptr_esp_netif_dns_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_dns_info_t_type()));
    return (esp_netif_dns_info_t*)self->data;
}

#define mp_write_esp_netif_dns_info_t(struct_obj) *((esp_netif_dns_info_t*)mp_write_ptr_esp_netif_dns_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_dns_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_dns_info_t_type(), field);
}

#define mp_read_esp_netif_dns_info_t(field) mp_read_ptr_esp_netif_dns_info_t(copy_buffer(&field, sizeof(esp_netif_dns_info_t)))
#define mp_read_byref_esp_netif_dns_info_t(field) mp_read_ptr_esp_netif_dns_info_t(&field)

STATIC void mp_esp_netif_dns_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_dns_info_t *data = (esp_netif_dns_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ip: dest[0] = mp_read_byref_esp_ip_addr_t(data->ip); break; // converting from esp_ip_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ip: data->ip = mp_write_esp_ip_addr_t(dest[1]); break; // converting to esp_ip_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_dns_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_dns_info_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_dns_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_dns_info_t_type,
    MP_QSTR_esp_netif_dns_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_dns_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_dns_info_t_attr,
    locals_dict, &mp_esp_netif_dns_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_dns_info_t_type()
{
    return &mp_esp_netif_dns_info_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_set_dns_info(esp_netif_t *esp_netif, esp_netif_dns_type_t type, esp_netif_dns_info_t *dns)
 */

STATIC mp_obj_t mp_esp_netif_set_dns_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_dns_type_t type = (int)mp_obj_get_int(mp_args[1]);
    esp_netif_dns_info_t *dns = mp_write_ptr_esp_netif_dns_info_t(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_netif_dns_type_t, esp_netif_dns_info_t *))lv_func_ptr)(esp_netif, type, dns);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_set_dns_info_mpobj, 3, mp_esp_netif_set_dns_info, esp_netif_set_dns_info);
    
/* Reusing esp_netif_set_dns_info for esp_netif_get_dns_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_dns_info_mpobj, 3, mp_esp_netif_set_dns_info, esp_netif_get_dns_info);
    
/* Reusing esp_netif_dhcpc_start for esp_netif_create_ip6_linklocal */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_create_ip6_linklocal_mpobj, 1, mp_esp_netif_dhcpc_start, esp_netif_create_ip6_linklocal);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_get_ip6_linklocal(esp_netif_t *esp_netif, esp_ip6_addr_t *if_ip6)
 */

STATIC mp_obj_t mp_esp_netif_get_ip6_linklocal(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_ip6_addr_t *if_ip6 = mp_write_ptr_esp_ip6_addr_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_t *, esp_ip6_addr_t *))lv_func_ptr)(esp_netif, if_ip6);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_ip6_linklocal_mpobj, 2, mp_esp_netif_get_ip6_linklocal, esp_netif_get_ip6_linklocal);
    
/* Reusing esp_netif_get_ip6_linklocal for esp_netif_get_ip6_global */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_ip6_global_mpobj, 2, mp_esp_netif_get_ip6_linklocal, esp_netif_get_ip6_global);
    

/*
 * Array convertors for esp_ip6_addr_t []
 */

GENMPY_UNUSED STATIC esp_ip6_addr_t *mp_arr_to_esp_ip6_addr_t_____(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    
    esp_ip6_addr_t *lv_arr = (esp_ip6_addr_t*)m_malloc(len * sizeof(esp_ip6_addr_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = mp_write_esp_ip6_addr_t(item);
    }
    return (esp_ip6_addr_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_esp_ip6_addr_t_____(esp_ip6_addr_t *arr)
{
    return mp_read_ptr_esp_ip6_addr_t((void*)arr);
}


/*
 * espidf extension definition for:
 * int esp_netif_get_all_ip6(esp_netif_t *esp_netif, esp_ip6_addr_t if_ip6[])
 */

STATIC mp_obj_t mp_esp_netif_get_all_ip6(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_ip6_addr_t *if_ip6 = mp_arr_to_esp_ip6_addr_t_____(mp_args[1]);
    int _res = ((int (*)(esp_netif_t *, esp_ip6_addr_t []))lv_func_ptr)(esp_netif, if_ip6);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_all_ip6_mpobj, 2, mp_esp_netif_get_all_ip6, esp_netif_get_all_ip6);
    

/*
 * espidf extension definition for:
 * esp_netif_iodriver_handle esp_netif_get_io_driver(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_get_io_driver(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_iodriver_handle _res = ((esp_netif_iodriver_handle (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return ptr_to_mp(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_io_driver_mpobj, 1, mp_esp_netif_get_io_driver, esp_netif_get_io_driver);
    

/*
 * espidf extension definition for:
 * esp_netif_flags_t esp_netif_get_flags(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_get_flags(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_flags_t _res = ((esp_netif_flags_t (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_flags_mpobj, 1, mp_esp_netif_get_flags, esp_netif_get_flags);
    

/*
 * espidf extension definition for:
 * const char *esp_netif_get_ifkey(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_get_ifkey(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    const char * _res = ((const char *(*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_ifkey_mpobj, 1, mp_esp_netif_get_ifkey, esp_netif_get_ifkey);
    
/* Reusing esp_netif_get_ifkey for esp_netif_get_desc */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_desc_mpobj, 1, mp_esp_netif_get_ifkey, esp_netif_get_desc);
    
/* Reusing esp_netif_get_netif_impl_index for esp_netif_get_route_prio */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_route_prio_mpobj, 1, mp_esp_netif_get_netif_impl_index, esp_netif_get_route_prio);
    

/*
 * espidf extension definition for:
 * int32_t esp_netif_get_event_id(esp_netif_t *esp_netif, esp_netif_ip_event_type_t event_type)
 */

STATIC mp_obj_t mp_esp_netif_get_event_id(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_ip_event_type_t event_type = (int)mp_obj_get_int(mp_args[1]);
    int32_t _res = ((int32_t (*)(esp_netif_t *, esp_netif_ip_event_type_t))lv_func_ptr)(esp_netif, event_type);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_get_event_id_mpobj, 2, mp_esp_netif_get_event_id, esp_netif_get_event_id);
    

/*
 * espidf extension definition for:
 * esp_netif_t *esp_netif_next(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_esp_netif_next(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    esp_netif_t * _res = ((esp_netif_t *(*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_read_ptr_esp_netif_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_next_mpobj, 1, mp_esp_netif_next, esp_netif_next);
    

STATIC const mp_rom_map_elem_t mp_esp_netif_t_locals_dict_table[] = {
    
    { MP_ROM_QSTR(MP_QSTR_destroy), MP_ROM_PTR(&mp_esp_netif_destroy_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_driver_config), MP_ROM_PTR(&mp_esp_netif_set_driver_config_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_attach), MP_ROM_PTR(&mp_esp_netif_attach_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_receive), MP_ROM_PTR(&mp_esp_netif_receive_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_mac), MP_ROM_PTR(&mp_esp_netif_set_mac_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_mac), MP_ROM_PTR(&mp_esp_netif_get_mac_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_hostname), MP_ROM_PTR(&mp_esp_netif_set_hostname_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_hostname), MP_ROM_PTR(&mp_esp_netif_get_hostname_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_is_netif_up), MP_ROM_PTR(&mp_esp_netif_is_netif_up_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_ip_info), MP_ROM_PTR(&mp_esp_netif_get_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_old_ip_info), MP_ROM_PTR(&mp_esp_netif_get_old_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_ip_info), MP_ROM_PTR(&mp_esp_netif_set_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_old_ip_info), MP_ROM_PTR(&mp_esp_netif_set_old_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_netif_impl_index), MP_ROM_PTR(&mp_esp_netif_get_netif_impl_index_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_netif_impl_name), MP_ROM_PTR(&mp_esp_netif_get_netif_impl_name_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_option), MP_ROM_PTR(&mp_esp_netif_dhcps_option_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcpc_option), MP_ROM_PTR(&mp_esp_netif_dhcpc_option_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcpc_start), MP_ROM_PTR(&mp_esp_netif_dhcpc_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcpc_stop), MP_ROM_PTR(&mp_esp_netif_dhcpc_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcpc_get_status), MP_ROM_PTR(&mp_esp_netif_dhcpc_get_status_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_get_status), MP_ROM_PTR(&mp_esp_netif_dhcps_get_status_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_start), MP_ROM_PTR(&mp_esp_netif_dhcps_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_stop), MP_ROM_PTR(&mp_esp_netif_dhcps_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_set_dns_info), MP_ROM_PTR(&mp_esp_netif_set_dns_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_dns_info), MP_ROM_PTR(&mp_esp_netif_get_dns_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_create_ip6_linklocal), MP_ROM_PTR(&mp_esp_netif_create_ip6_linklocal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_ip6_linklocal), MP_ROM_PTR(&mp_esp_netif_get_ip6_linklocal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_ip6_global), MP_ROM_PTR(&mp_esp_netif_get_ip6_global_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_all_ip6), MP_ROM_PTR(&mp_esp_netif_get_all_ip6_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_io_driver), MP_ROM_PTR(&mp_esp_netif_get_io_driver_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_flags), MP_ROM_PTR(&mp_esp_netif_get_flags_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_ifkey), MP_ROM_PTR(&mp_esp_netif_get_ifkey_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_desc), MP_ROM_PTR(&mp_esp_netif_get_desc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_route_prio), MP_ROM_PTR(&mp_esp_netif_get_route_prio_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_event_id), MP_ROM_PTR(&mp_esp_netif_get_event_id_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_next), MP_ROM_PTR(&mp_esp_netif_next_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_t_locals_dict, mp_esp_netif_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_netif_t *esp_netif_new(const esp_netif_config_t *esp_netif_config)
 */

STATIC mp_obj_t mp_esp_netif_new(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const esp_netif_config_t *esp_netif_config = (const esp_netif_config_t *)mp_write_ptr_esp_netif_config_t(mp_args[0]);
    esp_netif_t * _res = ((esp_netif_t *(*)(const esp_netif_config_t *))lv_func_ptr)(esp_netif_config);
    return mp_read_ptr_esp_netif_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_esp_netif_new_mpobj, 1, mp_esp_netif_new, esp_netif_new);
    

STATIC const mp_rom_map_elem_t mp_esp_netif_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_config_t))) },
    { MP_ROM_QSTR(MP_QSTR_new), MP_ROM_PTR(&mp_esp_netif_new_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_config_t_locals_dict, mp_esp_netif_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_netif_inherent_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_inherent_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_inherent_config_t_locals_dict, mp_esp_netif_inherent_config_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_netif_ip_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_ip_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_ip_info_t_locals_dict, mp_esp_netif_ip_info_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_netif_driver_ifconfig_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_driver_ifconfig_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_driver_ifconfig_t_locals_dict, mp_esp_netif_driver_ifconfig_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_netif_netstack_config_t_locals_dict_table[] = {
    
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_netstack_config_t_locals_dict, mp_esp_netif_netstack_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t mdns_query_async_delete(mdns_search_once_t *search)
 */

STATIC mp_obj_t mp_mdns_query_async_delete(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    mdns_search_once_t *search = mp_write_ptr_mdns_search_once_t(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(mdns_search_once_t *))lv_func_ptr)(search);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_mdns_query_async_delete_mpobj, 1, mp_mdns_query_async_delete, mdns_query_async_delete);
    

/*
 * espidf extension definition for:
 * bool mdns_query_async_get_results(mdns_search_once_t *search, uint32_t timeout, mdns_result_t **results)
 */

STATIC mp_obj_t mp_mdns_query_async_get_results(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    mdns_search_once_t *search = mp_write_ptr_mdns_search_once_t(mp_args[0]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[1]);
    mdns_result_t **results = mp_to_ptr(mp_args[2]);
    bool _res = ((bool (*)(mdns_search_once_t *, uint32_t, mdns_result_t **))lv_func_ptr)(search, timeout, results);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_mdns_query_async_get_results_mpobj, 3, mp_mdns_query_async_get_results, mdns_query_async_get_results);
    

STATIC const mp_rom_map_elem_t mp_mdns_search_once_t_locals_dict_table[] = {
    
    { MP_ROM_QSTR(MP_QSTR_query_async_delete), MP_ROM_PTR(&mp_mdns_query_async_delete_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_query_async_get_results), MP_ROM_PTR(&mp_mdns_query_async_get_results_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_mdns_search_once_t_locals_dict, mp_mdns_search_once_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void mdns_query_results_free(mdns_result_t *results)
 */

STATIC mp_obj_t mp_mdns_query_results_free(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    mdns_result_t *results = mp_write_ptr_mdns_result_t(mp_args[0]);
    ((void (*)(mdns_result_t *))lv_func_ptr)(results);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_mdns_query_results_free_mpobj, 1, mp_mdns_query_results_free, mdns_query_results_free);
    

STATIC const mp_rom_map_elem_t mp_mdns_result_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(mdns_result_t))) },
    { MP_ROM_QSTR(MP_QSTR_query_results_free), MP_ROM_PTR(&mp_mdns_query_results_free_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_mdns_result_t_locals_dict, mp_mdns_result_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_mdns_txt_item_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(mdns_txt_item_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_mdns_txt_item_t_locals_dict, mp_mdns_txt_item_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_mdns_ip_addr_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(mdns_ip_addr_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_mdns_ip_addr_t_locals_dict, mp_mdns_ip_addr_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void http_parser_init(http_parser *parser, enum http_parser_type type)
 */

STATIC mp_obj_t mp_http_parser_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser *parser = mp_write_ptr_http_parser(mp_args[0]);
    enum http_parser_type type = (int)mp_obj_get_int(mp_args[1]);
    ((void (*)(http_parser *, enum http_parser_type))lv_func_ptr)(parser, type);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_parser_init_mpobj, 2, mp_http_parser_init, http_parser_init);
    

/*
 * espidf extension definition for:
 * size_t http_parser_execute(http_parser *parser, const http_parser_settings *settings, const char *data, size_t len)
 */

STATIC mp_obj_t mp_http_parser_execute(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser *parser = mp_write_ptr_http_parser(mp_args[0]);
    const http_parser_settings *settings = (const http_parser_settings *)mp_write_ptr_http_parser_settings(mp_args[1]);
    const char *data = (const char *)(char*)convert_from_str(mp_args[2]);
    size_t len = (size_t)mp_obj_get_int(mp_args[3]);
    size_t _res = ((size_t (*)(http_parser *, const http_parser_settings *, const char *, size_t))lv_func_ptr)(parser, settings, data, len);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_parser_execute_mpobj, 4, mp_http_parser_execute, http_parser_execute);
    

/*
 * espidf extension definition for:
 * int http_should_keep_alive(const http_parser *parser)
 */

STATIC mp_obj_t mp_http_should_keep_alive(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const http_parser *parser = (const http_parser *)mp_write_ptr_http_parser(mp_args[0]);
    int _res = ((int (*)(const http_parser *))lv_func_ptr)(parser);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_should_keep_alive_mpobj, 1, mp_http_should_keep_alive, http_should_keep_alive);
    

/*
 * espidf extension definition for:
 * void http_parser_pause(http_parser *parser, int paused)
 */

STATIC mp_obj_t mp_http_parser_pause(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser *parser = mp_write_ptr_http_parser(mp_args[0]);
    int paused = (int)mp_obj_get_int(mp_args[1]);
    ((void (*)(http_parser *, int))lv_func_ptr)(parser, paused);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_parser_pause_mpobj, 2, mp_http_parser_pause, http_parser_pause);
    
/* Reusing http_should_keep_alive for http_body_is_final */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_body_is_final_mpobj, 1, mp_http_should_keep_alive, http_body_is_final);
    

STATIC const mp_rom_map_elem_t mp_http_parser_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(struct http_parser))) },
    { MP_ROM_QSTR(MP_QSTR_parser_init), MP_ROM_PTR(&mp_http_parser_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_parser_execute), MP_ROM_PTR(&mp_http_parser_execute_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_should_keep_alive), MP_ROM_PTR(&mp_http_should_keep_alive_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_parser_pause), MP_ROM_PTR(&mp_http_parser_pause_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_body_is_final), MP_ROM_PTR(&mp_http_body_is_final_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_http_parser_locals_dict, mp_http_parser_locals_dict_table);
        

/*
 * espidf extension definition for:
 * void http_parser_settings_init(http_parser_settings *settings)
 */

STATIC mp_obj_t mp_http_parser_settings_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    http_parser_settings *settings = mp_write_ptr_http_parser_settings(mp_args[0]);
    ((void (*)(http_parser_settings *))lv_func_ptr)(settings);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_parser_settings_init_mpobj, 1, mp_http_parser_settings_init, http_parser_settings_init);
    

STATIC const mp_rom_map_elem_t mp_http_parser_settings_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(struct http_parser_settings))) },
    { MP_ROM_QSTR(MP_QSTR_settings_init), MP_ROM_PTR(&mp_http_parser_settings_init_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_http_parser_settings_locals_dict, mp_http_parser_settings_locals_dict_table);
        

/*
 * espidf extension definition for:
 * int sh2lib_connect(struct sh2lib_handle *hd, const char *uri)
 */

STATIC mp_obj_t mp_sh2lib_connect(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const char *uri = (const char *)(char*)convert_from_str(mp_args[1]);
    int _res = ((int (*)(struct sh2lib_handle *, const char *))lv_func_ptr)(hd, uri);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_connect_mpobj, 2, mp_sh2lib_connect, sh2lib_connect);
    

/*
 * espidf extension definition for:
 * int sh2lib_connect_task(struct sh2lib_handle *hd, const char *uri, int priority, int core_id)
 */

STATIC mp_obj_t mp_sh2lib_connect_task(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const char *uri = (const char *)(char*)convert_from_str(mp_args[1]);
    int priority = (int)mp_obj_get_int(mp_args[2]);
    int core_id = (int)mp_obj_get_int(mp_args[3]);
    int _res = ((int (*)(struct sh2lib_handle *, const char *, int, int))lv_func_ptr)(hd, uri, priority, core_id);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_connect_task_mpobj, 4, mp_sh2lib_connect_task, sh2lib_connect_task);
    
/* Reusing sh2lib_connect for sh2lib_connect_async */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_connect_async_mpobj, 2, mp_sh2lib_connect, sh2lib_connect_async);
    

/*
 * espidf extension definition for:
 * void sh2lib_free(struct sh2lib_handle *hd)
 */

STATIC mp_obj_t mp_sh2lib_free(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    ((void (*)(struct sh2lib_handle *))lv_func_ptr)(hd);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_free_mpobj, 1, mp_sh2lib_free, sh2lib_free);
    

/*
 * Callback function sh2lib_handle_recv_cb
 * int sh2lib_frame_data_recv_cb_t(struct sh2lib_handle *handle, const void *data, size_t len, int flags)
 */

GENMPY_UNUSED STATIC int sh2lib_handle_recv_cb_callback(struct sh2lib_handle *arg0, const void *arg1, size_t arg2, int arg3)
{
    mp_obj_t mp_args[4];
    mp_args[0] = mp_read_ptr_sh2lib_handle((void*)arg0);
    mp_args[1] = ptr_to_mp((void*)arg1);
    mp_args[2] = mp_obj_new_int_from_uint(arg2);
    mp_args[3] = mp_obj_new_int(arg3);
    mp_obj_t callbacks = get_callback_dict_from_user_data(arg0->user_data);
    _nesting++;
    mp_obj_t callback_result = mp_call_function_n_kw(mp_obj_dict_get(callbacks, MP_OBJ_NEW_QSTR(MP_QSTR_sh2lib_handle_recv_cb)) , 4, 0, mp_args);
    _nesting--;
    return (int)mp_obj_get_int(callback_result);
}


/*
 * espidf extension definition for:
 * int sh2lib_do_get(struct sh2lib_handle *hd, const char *path, sh2lib_frame_data_recv_cb_t recv_cb)
 */

STATIC mp_obj_t mp_sh2lib_do_get(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const char *path = (const char *)(char*)convert_from_str(mp_args[1]);
    void *recv_cb = mp_lv_callback(mp_args[2], &sh2lib_handle_recv_cb_callback, MP_QSTR_sh2lib_handle_recv_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    int _res = ((int (*)(struct sh2lib_handle *, const char *, sh2lib_frame_data_recv_cb_t))lv_func_ptr)(hd, path, recv_cb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_do_get_mpobj, 3, mp_sh2lib_do_get, sh2lib_do_get);
    

/*
 * Callback function sh2lib_handle_send_cb
 * int sh2lib_putpost_data_cb_t(struct sh2lib_handle *handle, void *data, size_t len, uint32_t *data_flags)
 */

GENMPY_UNUSED STATIC int sh2lib_handle_send_cb_callback(struct sh2lib_handle *arg0, void *arg1, size_t arg2, uint32_t *arg3)
{
    mp_obj_t mp_args[4];
    mp_args[0] = mp_read_ptr_sh2lib_handle((void*)arg0);
    mp_args[1] = ptr_to_mp((void*)arg1);
    mp_args[2] = mp_obj_new_int_from_uint(arg2);
    mp_args[3] = mp_array_from_u32ptr((void*)arg3);
    mp_obj_t callbacks = get_callback_dict_from_user_data(arg0->user_data);
    _nesting++;
    mp_obj_t callback_result = mp_call_function_n_kw(mp_obj_dict_get(callbacks, MP_OBJ_NEW_QSTR(MP_QSTR_sh2lib_handle_send_cb)) , 4, 0, mp_args);
    _nesting--;
    return (int)mp_obj_get_int(callback_result);
}


/*
 * espidf extension definition for:
 * int sh2lib_do_post(struct sh2lib_handle *hd, const char *path, sh2lib_putpost_data_cb_t send_cb, sh2lib_frame_data_recv_cb_t recv_cb)
 */

STATIC mp_obj_t mp_sh2lib_do_post(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const char *path = (const char *)(char*)convert_from_str(mp_args[1]);
    void *send_cb = mp_lv_callback(mp_args[2], &sh2lib_handle_send_cb_callback, MP_QSTR_sh2lib_handle_send_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    void *recv_cb = mp_lv_callback(mp_args[3], &sh2lib_handle_recv_cb_callback, MP_QSTR_sh2lib_handle_recv_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    int _res = ((int (*)(struct sh2lib_handle *, const char *, sh2lib_putpost_data_cb_t, sh2lib_frame_data_recv_cb_t))lv_func_ptr)(hd, path, send_cb, recv_cb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_do_post_mpobj, 4, mp_sh2lib_do_post, sh2lib_do_post);
    
/* Reusing sh2lib_do_post for sh2lib_do_put */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_do_put_mpobj, 4, mp_sh2lib_do_post, sh2lib_do_put);
    

/*
 * espidf extension definition for:
 * int sh2lib_execute(struct sh2lib_handle *hd)
 */

STATIC mp_obj_t mp_sh2lib_execute(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    int _res = ((int (*)(struct sh2lib_handle *))lv_func_ptr)(hd);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_execute_mpobj, 1, mp_sh2lib_execute, sh2lib_execute);
    

/*
 * Struct sh2lib_nv
 */

STATIC inline const mp_obj_type_t *get_mp_sh2lib_nv_type();

STATIC inline void* mp_write_ptr_sh2lib_nv(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_sh2lib_nv_type()));
    return (struct sh2lib_nv*)self->data;
}

#define mp_write_sh2lib_nv(struct_obj) *((struct sh2lib_nv*)mp_write_ptr_sh2lib_nv(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_sh2lib_nv(void *field)
{
    return lv_to_mp_struct(get_mp_sh2lib_nv_type(), field);
}

#define mp_read_sh2lib_nv(field) mp_read_ptr_sh2lib_nv(copy_buffer(&field, sizeof(struct sh2lib_nv)))
#define mp_read_byref_sh2lib_nv(field) mp_read_ptr_sh2lib_nv(&field)

STATIC void mp_sh2lib_nv_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED struct sh2lib_nv *data = (struct sh2lib_nv*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_name: dest[0] = convert_to_str((void*)data->name); break; // converting from char *;
            case MP_QSTR_value: dest[0] = convert_to_str((void*)data->value); break; // converting from char *;
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from uint8_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_name: data->name = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_value: data->value = (void*)(char*)convert_from_str(dest[1]); break; // converting to char *;
                case MP_QSTR_flags: data->flags = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_sh2lib_nv_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct sh2lib_nv");
}

STATIC const mp_obj_dict_t mp_sh2lib_nv_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_sh2lib_nv_type,
    MP_QSTR_sh2lib_nv,
    MP_TYPE_FLAG_NONE,
    print, mp_sh2lib_nv_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_sh2lib_nv_attr,
    locals_dict, &mp_sh2lib_nv_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_sh2lib_nv_type()
{
    return &mp_sh2lib_nv_type;
}
    

/*
 * Array convertors for sh2lib_nv []
 */

GENMPY_UNUSED STATIC struct sh2lib_nv *mp_arr_to_sh2lib_nv_____(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    
    struct sh2lib_nv *lv_arr = (struct sh2lib_nv*)m_malloc(len * sizeof(struct sh2lib_nv));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = mp_write_sh2lib_nv(item);
    }
    return (struct sh2lib_nv *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_sh2lib_nv_____(const struct sh2lib_nv *arr)
{
    return mp_read_ptr_sh2lib_nv((void*)arr);
}


/*
 * espidf extension definition for:
 * int sh2lib_do_get_with_nv(struct sh2lib_handle *hd, const struct sh2lib_nv nva[], size_t nvlen, sh2lib_frame_data_recv_cb_t recv_cb)
 */

STATIC mp_obj_t mp_sh2lib_do_get_with_nv(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const struct sh2lib_nv *nva = (const struct sh2lib_nv *)mp_arr_to_sh2lib_nv_____(mp_args[1]);
    size_t nvlen = (size_t)mp_obj_get_int(mp_args[2]);
    void *recv_cb = mp_lv_callback(mp_args[3], &sh2lib_handle_recv_cb_callback, MP_QSTR_sh2lib_handle_recv_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    int _res = ((int (*)(struct sh2lib_handle *, const struct sh2lib_nv [], size_t, sh2lib_frame_data_recv_cb_t))lv_func_ptr)(hd, nva, nvlen, recv_cb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_do_get_with_nv_mpobj, 4, mp_sh2lib_do_get_with_nv, sh2lib_do_get_with_nv);
    

/*
 * espidf extension definition for:
 * int sh2lib_do_putpost_with_nv(struct sh2lib_handle *hd, const struct sh2lib_nv nva[], size_t nvlen, sh2lib_putpost_data_cb_t send_cb, sh2lib_frame_data_recv_cb_t recv_cb)
 */

STATIC mp_obj_t mp_sh2lib_do_putpost_with_nv(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    const struct sh2lib_nv *nva = (const struct sh2lib_nv *)mp_arr_to_sh2lib_nv_____(mp_args[1]);
    size_t nvlen = (size_t)mp_obj_get_int(mp_args[2]);
    void *send_cb = mp_lv_callback(mp_args[3], &sh2lib_handle_send_cb_callback, MP_QSTR_sh2lib_handle_send_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    void *recv_cb = mp_lv_callback(mp_args[4], &sh2lib_handle_recv_cb_callback, MP_QSTR_sh2lib_handle_recv_cb, &hd->user_data, NULL, (mp_lv_get_user_data)NULL, (mp_lv_set_user_data)NULL);
    int _res = ((int (*)(struct sh2lib_handle *, const struct sh2lib_nv [], size_t, sh2lib_putpost_data_cb_t, sh2lib_frame_data_recv_cb_t))lv_func_ptr)(hd, nva, nvlen, send_cb, recv_cb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_do_putpost_with_nv_mpobj, 5, mp_sh2lib_do_putpost_with_nv, sh2lib_do_putpost_with_nv);
    

/*
 * espidf extension definition for:
 * int sh2lib_session_resume_data(struct sh2lib_handle *hd, int32_t stream_id)
 */

STATIC mp_obj_t mp_sh2lib_session_resume_data(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct sh2lib_handle *hd = mp_write_ptr_sh2lib_handle(mp_args[0]);
    int32_t stream_id = (int32_t)mp_obj_get_int(mp_args[1]);
    int _res = ((int (*)(struct sh2lib_handle *, int32_t))lv_func_ptr)(hd, stream_id);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_sh2lib_session_resume_data_mpobj, 2, mp_sh2lib_session_resume_data, sh2lib_session_resume_data);
    

STATIC const mp_rom_map_elem_t mp_sh2lib_handle_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(struct sh2lib_handle))) },
    { MP_ROM_QSTR(MP_QSTR_connect), MP_ROM_PTR(&mp_sh2lib_connect_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_connect_task), MP_ROM_PTR(&mp_sh2lib_connect_task_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_connect_async), MP_ROM_PTR(&mp_sh2lib_connect_async_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_free), MP_ROM_PTR(&mp_sh2lib_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_do_get), MP_ROM_PTR(&mp_sh2lib_do_get_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_do_post), MP_ROM_PTR(&mp_sh2lib_do_post_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_do_put), MP_ROM_PTR(&mp_sh2lib_do_put_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_execute), MP_ROM_PTR(&mp_sh2lib_execute_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_do_get_with_nv), MP_ROM_PTR(&mp_sh2lib_do_get_with_nv_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_do_putpost_with_nv), MP_ROM_PTR(&mp_sh2lib_do_putpost_with_nv_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_session_resume_data), MP_ROM_PTR(&mp_sh2lib_session_resume_data_mpobj) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_sh2lib_handle_locals_dict, mp_sh2lib_handle_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_nghttp2_session_locals_dict_table[] = {
    
    
};

STATIC MP_DEFINE_CONST_DICT(mp_nghttp2_session_locals_dict, mp_nghttp2_session_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_tls_locals_dict_table[] = {
    
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_tls_locals_dict, mp_esp_tls_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_tls_cfg_locals_dict_table[] = {
    
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_tls_cfg_locals_dict, mp_esp_tls_cfg_locals_dict_table);
        

/*
 *
 * Global Module Functions
 *
 */


/*
 * espidf extension definition for:
 * inline static int lldesc_get_required_num_constrained(int data_size, int max_desc_size)
 */

STATIC mp_obj_t mp_lldesc_get_required_num_constrained(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int data_size = (int)mp_obj_get_int(mp_args[0]);
    int max_desc_size = (int)mp_obj_get_int(mp_args[1]);
    int _res = ((int (*)(int, int))lv_func_ptr)(data_size, max_desc_size);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lldesc_get_required_num_constrained_mpobj, 2, mp_lldesc_get_required_num_constrained, lldesc_get_required_num_constrained);
    

STATIC const mp_rom_map_elem_t mp_esp_netif_dns_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_dns_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_dns_info_t_locals_dict, mp_esp_netif_dns_info_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_sh2lib_nv_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(struct sh2lib_nv))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_sh2lib_nv_locals_dict, mp_sh2lib_nv_locals_dict_table);
        

/*
 * espidf extension definition for:
 * inline static uint32_t timeout_from_offered(uint32_t lease, uint32_t min)
 */

STATIC mp_obj_t mp_timeout_from_offered(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t lease = (uint32_t)mp_obj_get_int(mp_args[0]);
    uint32_t min = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t _res = ((uint32_t (*)(uint32_t, uint32_t))lv_func_ptr)(lease, min);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_timeout_from_offered_mpobj, 2, mp_timeout_from_offered, timeout_from_offered);
    

/*
 * espidf extension definition for:
 * inline static bool dhcps_router_enabled(dhcps_offer_t offer)
 */

STATIC mp_obj_t mp_dhcps_router_enabled(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    dhcps_offer_t offer = (uint8_t)mp_obj_get_int(mp_args[0]);
    bool _res = ((bool (*)(dhcps_offer_t))lv_func_ptr)(offer);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_router_enabled_mpobj, 1, mp_dhcps_router_enabled, dhcps_router_enabled);
    
/* Reusing dhcps_router_enabled for dhcps_dns_enabled */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_dns_enabled_mpobj, 1, mp_dhcps_router_enabled, dhcps_dns_enabled);
    

/*
 * espidf extension definition for:
 * const char *esp_get_idf_version(void)
 */

STATIC mp_obj_t mp_esp_get_idf_version(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    const char * _res = ((const char *(*)(void))lv_func_ptr)();
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_get_idf_version_mpobj, 0, mp_esp_get_idf_version, esp_get_idf_version);
    

/*
 * espidf extension definition for:
 * inline static uint32_t xPortGetCoreID()
 */

STATIC mp_obj_t mp_xPortGetCoreID(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    uint32_t _res = ((uint32_t (*)())lv_func_ptr)();
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_xPortGetCoreID_mpobj, 0, mp_xPortGetCoreID, xPortGetCoreID);
    

/*
 * espidf extension definition for:
 * UBaseType_t uxTaskPriorityGet(TaskHandle_t xTask)
 */

STATIC mp_obj_t mp_uxTaskPriorityGet(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    TaskHandle_t xTask = mp_to_ptr(mp_args[0]);
    UBaseType_t _res = ((UBaseType_t (*)(TaskHandle_t))lv_func_ptr)(xTask);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_uxTaskPriorityGet_mpobj, 1, mp_uxTaskPriorityGet, uxTaskPriorityGet);
    

/*
 * espidf extension definition for:
 * inline static void SPH0645_WORKAROUND(int i2s_num)
 */

STATIC mp_obj_t mp_SPH0645_WORKAROUND(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int i2s_num = (int)mp_obj_get_int(mp_args[0]);
    ((void (*)(int))lv_func_ptr)(i2s_num);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_SPH0645_WORKAROUND_mpobj, 1, mp_SPH0645_WORKAROUND, SPH0645_WORKAROUND);
    

/*
 * espidf extension definition for:
 * inline static void get_ccount(int *ccount)
 */

STATIC mp_obj_t mp_get_ccount(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int *ccount = mp_array_to_i32ptr(mp_args[0]);
    ((void (*)(int *))lv_func_ptr)(ccount);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_get_ccount_mpobj, 1, mp_get_ccount, get_ccount);
    

/*
 * espidf extension definition for:
 * void *memcpy(void *destination, const void *source, size_t num)
 */

STATIC mp_obj_t mp_memcpy(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *destination = mp_to_ptr(mp_args[0]);
    const void *source = (const void *)mp_to_ptr(mp_args[1]);
    size_t num = (size_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(void *, const void *, size_t))lv_func_ptr)(destination, source, num);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_memcpy_mpobj, 3, mp_memcpy, memcpy);
    

/*
 * espidf extension definition for:
 * void *memset(void *ptr, int value, size_t num)
 */

STATIC mp_obj_t mp_memset(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *ptr = mp_to_ptr(mp_args[0]);
    int value = (int)mp_obj_get_int(mp_args[1]);
    size_t num = (size_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(void *, int, size_t))lv_func_ptr)(ptr, value, num);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_memset_mpobj, 3, mp_memset, memset);
    

/*
 * espidf extension definition for:
 * uint32_t esp_clk_slowclk_cal_get(void)
 */

STATIC mp_obj_t mp_esp_clk_slowclk_cal_get(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    uint32_t _res = ((uint32_t (*)(void))lv_func_ptr)();
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_slowclk_cal_get_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_clk_slowclk_cal_get);
    

/*
 * espidf extension definition for:
 * void esp_clk_slowclk_cal_set(uint32_t value)
 */

STATIC mp_obj_t mp_esp_clk_slowclk_cal_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t value = (uint32_t)mp_obj_get_int(mp_args[0]);
    ((void (*)(uint32_t))lv_func_ptr)(value);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_slowclk_cal_set_mpobj, 1, mp_esp_clk_slowclk_cal_set, esp_clk_slowclk_cal_set);
    

/*
 * espidf extension definition for:
 * int esp_clk_cpu_freq(void)
 */

STATIC mp_obj_t mp_esp_clk_cpu_freq(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    int _res = ((int (*)(void))lv_func_ptr)();
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_cpu_freq_mpobj, 0, mp_esp_clk_cpu_freq, esp_clk_cpu_freq);
    
/* Reusing esp_clk_cpu_freq for esp_clk_apb_freq */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_apb_freq_mpobj, 0, mp_esp_clk_cpu_freq, esp_clk_apb_freq);
    
/* Reusing esp_clk_cpu_freq for esp_clk_xtal_freq */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_xtal_freq_mpobj, 0, mp_esp_clk_cpu_freq, esp_clk_xtal_freq);
    

/*
 * espidf extension definition for:
 * uint64_t esp_clk_rtc_time(void)
 */

STATIC mp_obj_t mp_esp_clk_rtc_time(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    uint64_t _res = ((uint64_t (*)(void))lv_func_ptr)();
    return mp_obj_new_int_from_ull(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_rtc_time_mpobj, 0, mp_esp_clk_rtc_time, esp_clk_rtc_time);
    
/* Reusing funcptr_shutdown_handler_t for esp_clk_private_lock */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_private_lock_mpobj, 0, mp_funcptr_shutdown_handler_t, esp_clk_private_lock);
    
/* Reusing funcptr_shutdown_handler_t for esp_clk_private_unlock */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_clk_private_unlock_mpobj, 0, mp_funcptr_shutdown_handler_t, esp_clk_private_unlock);
    

/*
 * espidf extension definition for:
 * const char *esp_err_to_name(esp_err_t code)
 */

STATIC mp_obj_t mp_esp_err_to_name(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_err_t code = (int)mp_obj_get_int(mp_args[0]);
    const char * _res = ((const char *(*)(esp_err_t))lv_func_ptr)(code);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_err_to_name_mpobj, 1, mp_esp_err_to_name, esp_err_to_name);
    

/*
 * espidf extension definition for:
 * const char *esp_err_to_name_r(esp_err_t code, char *buf, size_t buflen)
 */

STATIC mp_obj_t mp_esp_err_to_name_r(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_err_t code = (int)mp_obj_get_int(mp_args[0]);
    char *buf = (char*)convert_from_str(mp_args[1]);
    size_t buflen = (size_t)mp_obj_get_int(mp_args[2]);
    const char * _res = ((const char *(*)(esp_err_t, char *, size_t))lv_func_ptr)(code, buf, buflen);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_err_to_name_r_mpobj, 3, mp_esp_err_to_name_r, esp_err_to_name_r);
    
/* Reusing funcptr_shutdown_handler_t for gpio_init */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_init_mpobj, 0, mp_funcptr_shutdown_handler_t, gpio_init);
    

/*
 * espidf extension definition for:
 * void gpio_output_set(uint32_t set_mask, uint32_t clear_mask, uint32_t enable_mask, uint32_t disable_mask)
 */

STATIC mp_obj_t mp_gpio_output_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t set_mask = (uint32_t)mp_obj_get_int(mp_args[0]);
    uint32_t clear_mask = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t enable_mask = (uint32_t)mp_obj_get_int(mp_args[2]);
    uint32_t disable_mask = (uint32_t)mp_obj_get_int(mp_args[3]);
    ((void (*)(uint32_t, uint32_t, uint32_t, uint32_t))lv_func_ptr)(set_mask, clear_mask, enable_mask, disable_mask);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_output_set_mpobj, 4, mp_gpio_output_set, gpio_output_set);
    
/* Reusing gpio_output_set for gpio_output_set_high */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_output_set_high_mpobj, 4, mp_gpio_output_set, gpio_output_set_high);
    
/* Reusing esp_clk_slowclk_cal_get for gpio_input_get */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_input_get_mpobj, 0, mp_esp_clk_slowclk_cal_get, gpio_input_get);
    
/* Reusing esp_clk_slowclk_cal_get for gpio_input_get_high */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_input_get_high_mpobj, 0, mp_esp_clk_slowclk_cal_get, gpio_input_get_high);
    

/*
 * Function NOT generated:
 * Callback argument 'gpio_intr_handler_fn_t fn' cannot be the first argument! We assume the first argument contains the user_data
 * gpio_intr_handler_fn_t fn
 */
    

/*
 * espidf extension definition for:
 * void gpio_intr_handler_register(gpio_intr_handler_fn_t fn, void *arg)
 */

STATIC mp_obj_t mp_gpio_intr_handler_register(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_intr_handler_fn_t fn = mp_to_ptr(mp_args[0]);
    void *arg = mp_to_ptr(mp_args[1]);
    ((void (*)(gpio_intr_handler_fn_t, void *))lv_func_ptr)(fn, arg);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_handler_register_mpobj, 2, mp_gpio_intr_handler_register, gpio_intr_handler_register);
    
/* Reusing esp_clk_slowclk_cal_get for gpio_intr_pending */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_pending_mpobj, 0, mp_esp_clk_slowclk_cal_get, gpio_intr_pending);
    
/* Reusing esp_clk_slowclk_cal_get for gpio_intr_pending_high */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_pending_high_mpobj, 0, mp_esp_clk_slowclk_cal_get, gpio_intr_pending_high);
    
/* Reusing esp_clk_slowclk_cal_set for gpio_intr_ack */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_ack_mpobj, 1, mp_esp_clk_slowclk_cal_set, gpio_intr_ack);
    
/* Reusing esp_clk_slowclk_cal_set for gpio_intr_ack_high */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_ack_high_mpobj, 1, mp_esp_clk_slowclk_cal_set, gpio_intr_ack_high);
    

/*
 * espidf extension definition for:
 * void gpio_pin_wakeup_enable(uint32_t i, GPIO_INT_TYPE intr_state)
 */

STATIC mp_obj_t mp_gpio_pin_wakeup_enable(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t i = (uint32_t)mp_obj_get_int(mp_args[0]);
    GPIO_INT_TYPE intr_state = (int)mp_obj_get_int(mp_args[1]);
    ((void (*)(uint32_t, GPIO_INT_TYPE))lv_func_ptr)(i, intr_state);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pin_wakeup_enable_mpobj, 2, mp_gpio_pin_wakeup_enable, gpio_pin_wakeup_enable);
    
/* Reusing funcptr_shutdown_handler_t for gpio_pin_wakeup_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pin_wakeup_disable_mpobj, 0, mp_funcptr_shutdown_handler_t, gpio_pin_wakeup_disable);
    

/*
 * espidf extension definition for:
 * void gpio_matrix_in(uint32_t gpio, uint32_t signal_idx, bool inv)
 */

STATIC mp_obj_t mp_gpio_matrix_in(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t gpio = (uint32_t)mp_obj_get_int(mp_args[0]);
    uint32_t signal_idx = (uint32_t)mp_obj_get_int(mp_args[1]);
    bool inv = mp_obj_is_true(mp_args[2]);
    ((void (*)(uint32_t, uint32_t, bool))lv_func_ptr)(gpio, signal_idx, inv);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_matrix_in_mpobj, 3, mp_gpio_matrix_in, gpio_matrix_in);
    

/*
 * espidf extension definition for:
 * void gpio_matrix_out(uint32_t gpio, uint32_t signal_idx, bool out_inv, bool oen_inv)
 */

STATIC mp_obj_t mp_gpio_matrix_out(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t gpio = (uint32_t)mp_obj_get_int(mp_args[0]);
    uint32_t signal_idx = (uint32_t)mp_obj_get_int(mp_args[1]);
    bool out_inv = mp_obj_is_true(mp_args[2]);
    bool oen_inv = mp_obj_is_true(mp_args[3]);
    ((void (*)(uint32_t, uint32_t, bool, bool))lv_func_ptr)(gpio, signal_idx, out_inv, oen_inv);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_matrix_out_mpobj, 4, mp_gpio_matrix_out, gpio_matrix_out);
    

/*
 * espidf extension definition for:
 * void gpio_pad_select_gpio(uint8_t gpio_num)
 */

STATIC mp_obj_t mp_gpio_pad_select_gpio(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t gpio_num = (uint8_t)mp_obj_get_int(mp_args[0]);
    ((void (*)(uint8_t))lv_func_ptr)(gpio_num);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_select_gpio_mpobj, 1, mp_gpio_pad_select_gpio, gpio_pad_select_gpio);
    

/*
 * espidf extension definition for:
 * void gpio_pad_set_drv(uint8_t gpio_num, uint8_t drv)
 */

STATIC mp_obj_t mp_gpio_pad_set_drv(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t gpio_num = (uint8_t)mp_obj_get_int(mp_args[0]);
    uint8_t drv = (uint8_t)mp_obj_get_int(mp_args[1]);
    ((void (*)(uint8_t, uint8_t))lv_func_ptr)(gpio_num, drv);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_set_drv_mpobj, 2, mp_gpio_pad_set_drv, gpio_pad_set_drv);
    
/* Reusing gpio_pad_select_gpio for gpio_pad_pullup */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_pullup_mpobj, 1, mp_gpio_pad_select_gpio, gpio_pad_pullup);
    
/* Reusing gpio_pad_select_gpio for gpio_pad_pulldown */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_pulldown_mpobj, 1, mp_gpio_pad_select_gpio, gpio_pad_pulldown);
    
/* Reusing gpio_pad_select_gpio for gpio_pad_unhold */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_unhold_mpobj, 1, mp_gpio_pad_select_gpio, gpio_pad_unhold);
    
/* Reusing gpio_pad_select_gpio for gpio_pad_hold */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pad_hold_mpobj, 1, mp_gpio_pad_select_gpio, gpio_pad_hold);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_reset_pin(gpio_num_t gpio_num)
 */

STATIC mp_obj_t mp_gpio_reset_pin(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t))lv_func_ptr)(gpio_num);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_reset_pin_mpobj, 1, mp_gpio_reset_pin, gpio_reset_pin);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_set_intr_type(gpio_num_t gpio_num, gpio_int_type_t intr_type)
 */

STATIC mp_obj_t mp_gpio_set_intr_type(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_int_type_t intr_type = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_int_type_t))lv_func_ptr)(gpio_num, intr_type);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_set_intr_type_mpobj, 2, mp_gpio_set_intr_type, gpio_set_intr_type);
    
/* Reusing gpio_reset_pin for gpio_intr_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_enable_mpobj, 1, mp_gpio_reset_pin, gpio_intr_enable);
    
/* Reusing gpio_reset_pin for gpio_intr_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_intr_disable_mpobj, 1, mp_gpio_reset_pin, gpio_intr_disable);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_set_level(gpio_num_t gpio_num, uint32_t level)
 */

STATIC mp_obj_t mp_gpio_set_level(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    uint32_t level = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, uint32_t))lv_func_ptr)(gpio_num, level);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_set_level_mpobj, 2, mp_gpio_set_level, gpio_set_level);
    

/*
 * espidf extension definition for:
 * int gpio_get_level(gpio_num_t gpio_num)
 */

STATIC mp_obj_t mp_gpio_get_level(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    int _res = ((int (*)(gpio_num_t))lv_func_ptr)(gpio_num);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_get_level_mpobj, 1, mp_gpio_get_level, gpio_get_level);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_set_direction(gpio_num_t gpio_num, gpio_mode_t mode)
 */

STATIC mp_obj_t mp_gpio_set_direction(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_mode_t mode = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_mode_t))lv_func_ptr)(gpio_num, mode);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_set_direction_mpobj, 2, mp_gpio_set_direction, gpio_set_direction);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_set_pull_mode(gpio_num_t gpio_num, gpio_pull_mode_t pull)
 */

STATIC mp_obj_t mp_gpio_set_pull_mode(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_pull_mode_t pull = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_pull_mode_t))lv_func_ptr)(gpio_num, pull);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_set_pull_mode_mpobj, 2, mp_gpio_set_pull_mode, gpio_set_pull_mode);
    
/* Reusing gpio_set_intr_type for gpio_wakeup_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_wakeup_enable_mpobj, 2, mp_gpio_set_intr_type, gpio_wakeup_enable);
    
/* Reusing gpio_reset_pin for gpio_wakeup_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_wakeup_disable_mpobj, 1, mp_gpio_reset_pin, gpio_wakeup_disable);
    

/*
 * Function NOT generated:
 * Callback argument 'void (*fn)(void *)' cannot be the first argument! We assume the first argument contains the user_data
 * void (*fn)(void *)
 */
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_isr_register(void (*fn)(void *), void *arg, int intr_alloc_flags, gpio_isr_handle_t *handle)
 */

STATIC mp_obj_t mp_gpio_isr_register(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void (*fn)(void *) = mp_to_ptr(mp_args[0]);
    void *arg = mp_to_ptr(mp_args[1]);
    int intr_alloc_flags = (int)mp_obj_get_int(mp_args[2]);
    gpio_isr_handle_t *handle = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(void (*)(void *), void *, int, gpio_isr_handle_t *))lv_func_ptr)(fn, arg, intr_alloc_flags, handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_isr_register_mpobj, 4, mp_gpio_isr_register, gpio_isr_register);
    
/* Reusing gpio_reset_pin for gpio_pullup_en */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pullup_en_mpobj, 1, mp_gpio_reset_pin, gpio_pullup_en);
    
/* Reusing gpio_reset_pin for gpio_pullup_dis */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pullup_dis_mpobj, 1, mp_gpio_reset_pin, gpio_pullup_dis);
    
/* Reusing gpio_reset_pin for gpio_pulldown_en */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pulldown_en_mpobj, 1, mp_gpio_reset_pin, gpio_pulldown_en);
    
/* Reusing gpio_reset_pin for gpio_pulldown_dis */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_pulldown_dis_mpobj, 1, mp_gpio_reset_pin, gpio_pulldown_dis);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_install_isr_service(int intr_alloc_flags)
 */

STATIC mp_obj_t mp_gpio_install_isr_service(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int intr_alloc_flags = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(int))lv_func_ptr)(intr_alloc_flags);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_install_isr_service_mpobj, 1, mp_gpio_install_isr_service, gpio_install_isr_service);
    
/* Reusing funcptr_shutdown_handler_t for gpio_uninstall_isr_service */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_uninstall_isr_service_mpobj, 0, mp_funcptr_shutdown_handler_t, gpio_uninstall_isr_service);
    

/*
 * Function NOT generated:
 * Callback function 'gpio_isr_t isr_handler' must receive a struct pointer with user_data member as its first argument!
 * gpio_isr_t isr_handler
 */
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_isr_handler_add(gpio_num_t gpio_num, gpio_isr_t isr_handler, void *args)
 */

STATIC mp_obj_t mp_gpio_isr_handler_add(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_isr_t isr_handler = mp_to_ptr(mp_args[1]);
    void *args = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_isr_t, void *))lv_func_ptr)(gpio_num, isr_handler, args);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_isr_handler_add_mpobj, 3, mp_gpio_isr_handler_add, gpio_isr_handler_add);
    
/* Reusing gpio_reset_pin for gpio_isr_handler_remove */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_isr_handler_remove_mpobj, 1, mp_gpio_reset_pin, gpio_isr_handler_remove);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_set_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t strength)
 */

STATIC mp_obj_t mp_gpio_set_drive_capability(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_drive_cap_t strength = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_drive_cap_t))lv_func_ptr)(gpio_num, strength);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_set_drive_capability_mpobj, 2, mp_gpio_set_drive_capability, gpio_set_drive_capability);
    

/*
 * espidf extension definition for:
 * esp_err_t gpio_get_drive_capability(gpio_num_t gpio_num, gpio_drive_cap_t *strength)
 */

STATIC mp_obj_t mp_gpio_get_drive_capability(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    gpio_num_t gpio_num = (int)mp_obj_get_int(mp_args[0]);
    gpio_drive_cap_t *strength = mp_array_to_i32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(gpio_num_t, gpio_drive_cap_t *))lv_func_ptr)(gpio_num, strength);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_get_drive_capability_mpobj, 2, mp_gpio_get_drive_capability, gpio_get_drive_capability);
    
/* Reusing gpio_reset_pin for gpio_hold_en */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_hold_en_mpobj, 1, mp_gpio_reset_pin, gpio_hold_en);
    
/* Reusing gpio_reset_pin for gpio_hold_dis */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_hold_dis_mpobj, 1, mp_gpio_reset_pin, gpio_hold_dis);
    
/* Reusing funcptr_shutdown_handler_t for gpio_deep_sleep_hold_en */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_deep_sleep_hold_en_mpobj, 0, mp_funcptr_shutdown_handler_t, gpio_deep_sleep_hold_en);
    
/* Reusing funcptr_shutdown_handler_t for gpio_deep_sleep_hold_dis */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_deep_sleep_hold_dis_mpobj, 0, mp_funcptr_shutdown_handler_t, gpio_deep_sleep_hold_dis);
    

/*
 * espidf extension definition for:
 * void gpio_iomux_in(uint32_t gpio_num, uint32_t signal_idx)
 */

STATIC mp_obj_t mp_gpio_iomux_in(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t gpio_num = (uint32_t)mp_obj_get_int(mp_args[0]);
    uint32_t signal_idx = (uint32_t)mp_obj_get_int(mp_args[1]);
    ((void (*)(uint32_t, uint32_t))lv_func_ptr)(gpio_num, signal_idx);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_iomux_in_mpobj, 2, mp_gpio_iomux_in, gpio_iomux_in);
    

/*
 * espidf extension definition for:
 * void gpio_iomux_out(uint8_t gpio_num, int func, bool oen_inv)
 */

STATIC mp_obj_t mp_gpio_iomux_out(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t gpio_num = (uint8_t)mp_obj_get_int(mp_args[0]);
    int func = (int)mp_obj_get_int(mp_args[1]);
    bool oen_inv = mp_obj_is_true(mp_args[2]);
    ((void (*)(uint8_t, int, bool))lv_func_ptr)(gpio_num, func, oen_inv);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_iomux_out_mpobj, 3, mp_gpio_iomux_out, gpio_iomux_out);
    
/* Reusing gpio_reset_pin for gpio_sleep_sel_en */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_sleep_sel_en_mpobj, 1, mp_gpio_reset_pin, gpio_sleep_sel_en);
    
/* Reusing gpio_reset_pin for gpio_sleep_sel_dis */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_sleep_sel_dis_mpobj, 1, mp_gpio_reset_pin, gpio_sleep_sel_dis);
    
/* Reusing gpio_set_direction for gpio_sleep_set_direction */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_sleep_set_direction_mpobj, 2, mp_gpio_set_direction, gpio_sleep_set_direction);
    
/* Reusing gpio_set_pull_mode for gpio_sleep_set_pull_mode */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_gpio_sleep_set_pull_mode_mpobj, 2, mp_gpio_set_pull_mode, gpio_sleep_set_pull_mode);
    

/*
 * espidf extension definition for:
 * void lldesc_setup_link_constrained(lldesc_t *out_desc_array, const void *buffer, int size, int max_desc_size, bool isrx)
 */

STATIC mp_obj_t mp_lldesc_setup_link_constrained(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    lldesc_t *out_desc_array = mp_to_ptr(mp_args[0]);
    const void *buffer = (const void *)mp_to_ptr(mp_args[1]);
    int size = (int)mp_obj_get_int(mp_args[2]);
    int max_desc_size = (int)mp_obj_get_int(mp_args[3]);
    bool isrx = mp_obj_is_true(mp_args[4]);
    ((void (*)(lldesc_t *, const void *, int, int, bool))lv_func_ptr)(out_desc_array, buffer, size, max_desc_size, isrx);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lldesc_setup_link_constrained_mpobj, 5, mp_lldesc_setup_link_constrained, lldesc_setup_link_constrained);
    

/*
 * espidf extension definition for:
 * int lldesc_get_received_len(lldesc_t *head, lldesc_t **out_next)
 */

STATIC mp_obj_t mp_lldesc_get_received_len(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    lldesc_t *head = mp_to_ptr(mp_args[0]);
    lldesc_t **out_next = mp_to_ptr(mp_args[1]);
    int _res = ((int (*)(lldesc_t *, lldesc_t **))lv_func_ptr)(head, out_next);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lldesc_get_received_len_mpobj, 2, mp_lldesc_get_received_len, lldesc_get_received_len);
    

/*
 * Struct spi_bus_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_spi_bus_config_t_type();

STATIC inline void* mp_write_ptr_spi_bus_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_spi_bus_config_t_type()));
    return (spi_bus_config_t*)self->data;
}

#define mp_write_spi_bus_config_t(struct_obj) *((spi_bus_config_t*)mp_write_ptr_spi_bus_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_spi_bus_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_spi_bus_config_t_type(), field);
}

#define mp_read_spi_bus_config_t(field) mp_read_ptr_spi_bus_config_t(copy_buffer(&field, sizeof(spi_bus_config_t)))
#define mp_read_byref_spi_bus_config_t(field) mp_read_ptr_spi_bus_config_t(&field)

STATIC void mp_spi_bus_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED spi_bus_config_t *data = (spi_bus_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mosi_io_num: dest[0] = mp_obj_new_int(data->mosi_io_num); break; // converting from int;
            case MP_QSTR_data0_io_num: dest[0] = mp_obj_new_int(data->data0_io_num); break; // converting from int;
            case MP_QSTR_miso_io_num: dest[0] = mp_obj_new_int(data->miso_io_num); break; // converting from int;
            case MP_QSTR_data1_io_num: dest[0] = mp_obj_new_int(data->data1_io_num); break; // converting from int;
            case MP_QSTR_sclk_io_num: dest[0] = mp_obj_new_int(data->sclk_io_num); break; // converting from int;
            case MP_QSTR_quadwp_io_num: dest[0] = mp_obj_new_int(data->quadwp_io_num); break; // converting from int;
            case MP_QSTR_data2_io_num: dest[0] = mp_obj_new_int(data->data2_io_num); break; // converting from int;
            case MP_QSTR_quadhd_io_num: dest[0] = mp_obj_new_int(data->quadhd_io_num); break; // converting from int;
            case MP_QSTR_data3_io_num: dest[0] = mp_obj_new_int(data->data3_io_num); break; // converting from int;
            case MP_QSTR_data4_io_num: dest[0] = mp_obj_new_int(data->data4_io_num); break; // converting from int;
            case MP_QSTR_data5_io_num: dest[0] = mp_obj_new_int(data->data5_io_num); break; // converting from int;
            case MP_QSTR_data6_io_num: dest[0] = mp_obj_new_int(data->data6_io_num); break; // converting from int;
            case MP_QSTR_data7_io_num: dest[0] = mp_obj_new_int(data->data7_io_num); break; // converting from int;
            case MP_QSTR_max_transfer_sz: dest[0] = mp_obj_new_int(data->max_transfer_sz); break; // converting from int;
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from uint32_t;
            case MP_QSTR_intr_flags: dest[0] = mp_obj_new_int(data->intr_flags); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mosi_io_num: data->mosi_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data0_io_num: data->data0_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_miso_io_num: data->miso_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data1_io_num: data->data1_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_sclk_io_num: data->sclk_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_quadwp_io_num: data->quadwp_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data2_io_num: data->data2_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_quadhd_io_num: data->quadhd_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data3_io_num: data->data3_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data4_io_num: data->data4_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data5_io_num: data->data5_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data6_io_num: data->data6_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data7_io_num: data->data7_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_max_transfer_sz: data->max_transfer_sz = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_flags: data->flags = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_intr_flags: data->intr_flags = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_spi_bus_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct spi_bus_config_t");
}

STATIC const mp_obj_dict_t mp_spi_bus_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_spi_bus_config_t_type,
    MP_QSTR_spi_bus_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_spi_bus_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_spi_bus_config_t_attr,
    locals_dict, &mp_spi_bus_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_spi_bus_config_t_type()
{
    return &mp_spi_bus_config_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t spi_bus_initialize(spi_host_device_t host_id, const spi_bus_config_t *bus_config, spi_dma_chan_t dma_chan)
 */

STATIC mp_obj_t mp_spi_bus_initialize(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_host_device_t host_id = (int)mp_obj_get_int(mp_args[0]);
    const spi_bus_config_t *bus_config = (const spi_bus_config_t *)mp_write_ptr_spi_bus_config_t(mp_args[1]);
    spi_dma_chan_t dma_chan = (int)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(spi_host_device_t, const spi_bus_config_t *, spi_dma_chan_t))lv_func_ptr)(host_id, bus_config, dma_chan);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_bus_initialize_mpobj, 3, mp_spi_bus_initialize, spi_bus_initialize);
    

STATIC const mp_rom_map_elem_t mp_spi_bus_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(spi_bus_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_spi_bus_config_t_locals_dict, mp_spi_bus_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t spi_bus_free(spi_host_device_t host_id)
 */

STATIC mp_obj_t mp_spi_bus_free(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_host_device_t host_id = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(spi_host_device_t))lv_func_ptr)(host_id);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_bus_free_mpobj, 1, mp_spi_bus_free, spi_bus_free);
    
#define funcptr_transaction_cb_t NULL


/*
 * espidf extension definition for:
 * void transaction_cb_t(spi_transaction_t *trans)
 */

STATIC mp_obj_t mp_funcptr_transaction_cb_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_transaction_t *trans = mp_write_ptr_spi_transaction_t(mp_args[0]);
    ((void (*)(spi_transaction_t *))lv_func_ptr)(trans);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_transaction_cb_t_mpobj, 1, mp_funcptr_transaction_cb_t, funcptr_transaction_cb_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_transaction_cb_t(void *func){ return mp_lv_funcptr(&mp_funcptr_transaction_cb_t_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'spi_device_interface_config_t_pre_cb_callback'
 * transaction_cb_t pre_cb
 */
    

/*
 * Function NOT generated:
 * Missing 'user_data' as a field of the first parameter of the callback function 'spi_device_interface_config_t_post_cb_callback'
 * transaction_cb_t post_cb
 */
    

/*
 * Struct spi_device_interface_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_spi_device_interface_config_t_type();

STATIC inline void* mp_write_ptr_spi_device_interface_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_spi_device_interface_config_t_type()));
    return (spi_device_interface_config_t*)self->data;
}

#define mp_write_spi_device_interface_config_t(struct_obj) *((spi_device_interface_config_t*)mp_write_ptr_spi_device_interface_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_spi_device_interface_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_spi_device_interface_config_t_type(), field);
}

#define mp_read_spi_device_interface_config_t(field) mp_read_ptr_spi_device_interface_config_t(copy_buffer(&field, sizeof(spi_device_interface_config_t)))
#define mp_read_byref_spi_device_interface_config_t(field) mp_read_ptr_spi_device_interface_config_t(&field)

STATIC void mp_spi_device_interface_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED spi_device_interface_config_t *data = (spi_device_interface_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_command_bits: dest[0] = mp_obj_new_int_from_uint(data->command_bits); break; // converting from uint8_t;
            case MP_QSTR_address_bits: dest[0] = mp_obj_new_int_from_uint(data->address_bits); break; // converting from uint8_t;
            case MP_QSTR_dummy_bits: dest[0] = mp_obj_new_int_from_uint(data->dummy_bits); break; // converting from uint8_t;
            case MP_QSTR_mode: dest[0] = mp_obj_new_int_from_uint(data->mode); break; // converting from uint8_t;
            case MP_QSTR_duty_cycle_pos: dest[0] = mp_obj_new_int_from_uint(data->duty_cycle_pos); break; // converting from uint16_t;
            case MP_QSTR_cs_ena_pretrans: dest[0] = mp_obj_new_int_from_uint(data->cs_ena_pretrans); break; // converting from uint16_t;
            case MP_QSTR_cs_ena_posttrans: dest[0] = mp_obj_new_int_from_uint(data->cs_ena_posttrans); break; // converting from uint8_t;
            case MP_QSTR_clock_speed_hz: dest[0] = mp_obj_new_int(data->clock_speed_hz); break; // converting from int;
            case MP_QSTR_input_delay_ns: dest[0] = mp_obj_new_int(data->input_delay_ns); break; // converting from int;
            case MP_QSTR_spics_io_num: dest[0] = mp_obj_new_int(data->spics_io_num); break; // converting from int;
            case MP_QSTR_flags: dest[0] = mp_obj_new_int_from_uint(data->flags); break; // converting from uint32_t;
            case MP_QSTR_queue_size: dest[0] = mp_obj_new_int(data->queue_size); break; // converting from int;
            case MP_QSTR_pre_cb: dest[0] = mp_lv_funcptr(&mp_funcptr_transaction_cb_t_mpobj, data->pre_cb, NULL ,MP_QSTR_spi_device_interface_config_t_pre_cb, NULL); break; // converting from callback transaction_cb_t;
            case MP_QSTR_post_cb: dest[0] = mp_lv_funcptr(&mp_funcptr_transaction_cb_t_mpobj, data->post_cb, NULL ,MP_QSTR_spi_device_interface_config_t_post_cb, NULL); break; // converting from callback transaction_cb_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_command_bits: data->command_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_address_bits: data->address_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_dummy_bits: data->dummy_bits = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_mode: data->mode = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_duty_cycle_pos: data->duty_cycle_pos = (uint16_t)mp_obj_get_int(dest[1]); break; // converting to uint16_t;
                case MP_QSTR_cs_ena_pretrans: data->cs_ena_pretrans = (uint16_t)mp_obj_get_int(dest[1]); break; // converting to uint16_t;
                case MP_QSTR_cs_ena_posttrans: data->cs_ena_posttrans = (uint8_t)mp_obj_get_int(dest[1]); break; // converting to uint8_t;
                case MP_QSTR_clock_speed_hz: data->clock_speed_hz = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_input_delay_ns: data->input_delay_ns = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_spics_io_num: data->spics_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_flags: data->flags = (uint32_t)mp_obj_get_int(dest[1]); break; // converting to uint32_t;
                case MP_QSTR_queue_size: data->queue_size = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_pre_cb: data->pre_cb = mp_lv_callback(dest[1], NULL ,MP_QSTR_spi_device_interface_config_t_pre_cb, NULL, NULL, NULL, NULL); break; // converting to callback transaction_cb_t;
                case MP_QSTR_post_cb: data->post_cb = mp_lv_callback(dest[1], NULL ,MP_QSTR_spi_device_interface_config_t_post_cb, NULL, NULL, NULL, NULL); break; // converting to callback transaction_cb_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_spi_device_interface_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct spi_device_interface_config_t");
}

STATIC const mp_obj_dict_t mp_spi_device_interface_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_spi_device_interface_config_t_type,
    MP_QSTR_spi_device_interface_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_spi_device_interface_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_spi_device_interface_config_t_attr,
    locals_dict, &mp_spi_device_interface_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_spi_device_interface_config_t_type()
{
    return &mp_spi_device_interface_config_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t spi_bus_add_device(spi_host_device_t host_id, const spi_device_interface_config_t *dev_config, spi_device_handle_t *handle)
 */

STATIC mp_obj_t mp_spi_bus_add_device(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_host_device_t host_id = (int)mp_obj_get_int(mp_args[0]);
    const spi_device_interface_config_t *dev_config = (const spi_device_interface_config_t *)mp_write_ptr_spi_device_interface_config_t(mp_args[1]);
    spi_device_handle_t *handle = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(spi_host_device_t, const spi_device_interface_config_t *, spi_device_handle_t *))lv_func_ptr)(host_id, dev_config, handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_bus_add_device_mpobj, 3, mp_spi_bus_add_device, spi_bus_add_device);
    

STATIC const mp_rom_map_elem_t mp_spi_device_interface_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(spi_device_interface_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_spi_device_interface_config_t_locals_dict, mp_spi_device_interface_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t spi_bus_remove_device(spi_device_handle_t handle)
 */

STATIC mp_obj_t mp_spi_bus_remove_device(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t handle = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(spi_device_handle_t))lv_func_ptr)(handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_bus_remove_device_mpobj, 1, mp_spi_bus_remove_device, spi_bus_remove_device);
    

/*
 * espidf extension definition for:
 * esp_err_t spi_device_queue_trans(spi_device_handle_t handle, spi_transaction_t *trans_desc, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_spi_device_queue_trans(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t handle = mp_to_ptr(mp_args[0]);
    spi_transaction_t *trans_desc = mp_write_ptr_spi_transaction_t(mp_args[1]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(spi_device_handle_t, spi_transaction_t *, TickType_t))lv_func_ptr)(handle, trans_desc, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_queue_trans_mpobj, 3, mp_spi_device_queue_trans, spi_device_queue_trans);
    

/*
 * espidf extension definition for:
 * esp_err_t spi_device_get_trans_result(spi_device_handle_t handle, spi_transaction_t **trans_desc, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_spi_device_get_trans_result(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t handle = mp_to_ptr(mp_args[0]);
    spi_transaction_t **trans_desc = mp_to_ptr(mp_args[1]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(spi_device_handle_t, spi_transaction_t **, TickType_t))lv_func_ptr)(handle, trans_desc, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_get_trans_result_mpobj, 3, mp_spi_device_get_trans_result, spi_device_get_trans_result);
    

/*
 * espidf extension definition for:
 * esp_err_t spi_device_transmit(spi_device_handle_t handle, spi_transaction_t *trans_desc)
 */

STATIC mp_obj_t mp_spi_device_transmit(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t handle = mp_to_ptr(mp_args[0]);
    spi_transaction_t *trans_desc = mp_write_ptr_spi_transaction_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(spi_device_handle_t, spi_transaction_t *))lv_func_ptr)(handle, trans_desc);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_transmit_mpobj, 2, mp_spi_device_transmit, spi_device_transmit);
    
/* Reusing spi_device_queue_trans for spi_device_polling_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_polling_start_mpobj, 3, mp_spi_device_queue_trans, spi_device_polling_start);
    

/*
 * espidf extension definition for:
 * esp_err_t spi_device_polling_end(spi_device_handle_t handle, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_spi_device_polling_end(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t handle = mp_to_ptr(mp_args[0]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(spi_device_handle_t, TickType_t))lv_func_ptr)(handle, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_polling_end_mpobj, 2, mp_spi_device_polling_end, spi_device_polling_end);
    
/* Reusing spi_device_transmit for spi_device_polling_transmit */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_polling_transmit_mpobj, 2, mp_spi_device_transmit, spi_device_polling_transmit);
    
/* Reusing spi_device_polling_end for spi_device_acquire_bus */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_acquire_bus_mpobj, 2, mp_spi_device_polling_end, spi_device_acquire_bus);
    

/*
 * espidf extension definition for:
 * void spi_device_release_bus(spi_device_handle_t dev)
 */

STATIC mp_obj_t mp_spi_device_release_bus(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_device_handle_t dev = mp_to_ptr(mp_args[0]);
    ((void (*)(spi_device_handle_t))lv_func_ptr)(dev);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_device_release_bus_mpobj, 1, mp_spi_device_release_bus, spi_device_release_bus);
    

/*
 * espidf extension definition for:
 * int spi_cal_clock(int fapb, int hz, int duty_cycle, uint32_t *reg_o)
 */

STATIC mp_obj_t mp_spi_cal_clock(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int fapb = (int)mp_obj_get_int(mp_args[0]);
    int hz = (int)mp_obj_get_int(mp_args[1]);
    int duty_cycle = (int)mp_obj_get_int(mp_args[2]);
    uint32_t *reg_o = mp_array_to_u32ptr(mp_args[3]);
    int _res = ((int (*)(int, int, int, uint32_t *))lv_func_ptr)(fapb, hz, duty_cycle, reg_o);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_cal_clock_mpobj, 4, mp_spi_cal_clock, spi_cal_clock);
    

/*
 * espidf extension definition for:
 * int spi_get_actual_clock(int fapb, int hz, int duty_cycle)
 */

STATIC mp_obj_t mp_spi_get_actual_clock(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int fapb = (int)mp_obj_get_int(mp_args[0]);
    int hz = (int)mp_obj_get_int(mp_args[1]);
    int duty_cycle = (int)mp_obj_get_int(mp_args[2]);
    int _res = ((int (*)(int, int, int))lv_func_ptr)(fapb, hz, duty_cycle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_get_actual_clock_mpobj, 3, mp_spi_get_actual_clock, spi_get_actual_clock);
    

/*
 * espidf extension definition for:
 * void spi_get_timing(bool gpio_is_used, int input_delay_ns, int eff_clk, int *dummy_o, int *cycles_remain_o)
 */

STATIC mp_obj_t mp_spi_get_timing(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    bool gpio_is_used = mp_obj_is_true(mp_args[0]);
    int input_delay_ns = (int)mp_obj_get_int(mp_args[1]);
    int eff_clk = (int)mp_obj_get_int(mp_args[2]);
    int *dummy_o = mp_array_to_i32ptr(mp_args[3]);
    int *cycles_remain_o = mp_array_to_i32ptr(mp_args[4]);
    ((void (*)(bool, int, int, int *, int *))lv_func_ptr)(gpio_is_used, input_delay_ns, eff_clk, dummy_o, cycles_remain_o);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_get_timing_mpobj, 5, mp_spi_get_timing, spi_get_timing);
    

/*
 * espidf extension definition for:
 * int spi_get_freq_limit(bool gpio_is_used, int input_delay_ns)
 */

STATIC mp_obj_t mp_spi_get_freq_limit(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    bool gpio_is_used = mp_obj_is_true(mp_args[0]);
    int input_delay_ns = (int)mp_obj_get_int(mp_args[1]);
    int _res = ((int (*)(bool, int))lv_func_ptr)(gpio_is_used, input_delay_ns);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_get_freq_limit_mpobj, 2, mp_spi_get_freq_limit, spi_get_freq_limit);
    

/*
 * espidf extension definition for:
 * esp_err_t spi_bus_get_max_transaction_len(spi_host_device_t host_id, size_t *max_bytes)
 */

STATIC mp_obj_t mp_spi_bus_get_max_transaction_len(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    spi_host_device_t host_id = (int)mp_obj_get_int(mp_args[0]);
    size_t *max_bytes = mp_array_to_u32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(spi_host_device_t, size_t *))lv_func_ptr)(host_id, max_bytes);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_bus_get_max_transaction_len_mpobj, 2, mp_spi_bus_get_max_transaction_len, spi_bus_get_max_transaction_len);
    

/*
 * espidf extension definition for:
 * void *multi_heap_aligned_alloc(multi_heap_handle_t heap, size_t size, size_t alignment)
 */

STATIC mp_obj_t mp_multi_heap_aligned_alloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    size_t size = (size_t)mp_obj_get_int(mp_args[1]);
    size_t alignment = (size_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(multi_heap_handle_t, size_t, size_t))lv_func_ptr)(heap, size, alignment);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_aligned_alloc_mpobj, 3, mp_multi_heap_aligned_alloc, multi_heap_aligned_alloc);
    

/*
 * espidf extension definition for:
 * void *multi_heap_malloc(multi_heap_handle_t heap, size_t size)
 */

STATIC mp_obj_t mp_multi_heap_malloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    size_t size = (size_t)mp_obj_get_int(mp_args[1]);
    void * _res = ((void *(*)(multi_heap_handle_t, size_t))lv_func_ptr)(heap, size);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_malloc_mpobj, 2, mp_multi_heap_malloc, multi_heap_malloc);
    

/*
 * espidf extension definition for:
 * void multi_heap_aligned_free(multi_heap_handle_t heap, void *p)
 */

STATIC mp_obj_t mp_multi_heap_aligned_free(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    void *p = mp_to_ptr(mp_args[1]);
    ((void (*)(multi_heap_handle_t, void *))lv_func_ptr)(heap, p);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_aligned_free_mpobj, 2, mp_multi_heap_aligned_free, multi_heap_aligned_free);
    
/* Reusing multi_heap_aligned_free for multi_heap_free */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_free_mpobj, 2, mp_multi_heap_aligned_free, multi_heap_free);
    

/*
 * espidf extension definition for:
 * void *multi_heap_realloc(multi_heap_handle_t heap, void *p, size_t size)
 */

STATIC mp_obj_t mp_multi_heap_realloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    void *p = mp_to_ptr(mp_args[1]);
    size_t size = (size_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(multi_heap_handle_t, void *, size_t))lv_func_ptr)(heap, p, size);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_realloc_mpobj, 3, mp_multi_heap_realloc, multi_heap_realloc);
    

/*
 * espidf extension definition for:
 * size_t multi_heap_get_allocated_size(multi_heap_handle_t heap, void *p)
 */

STATIC mp_obj_t mp_multi_heap_get_allocated_size(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    void *p = mp_to_ptr(mp_args[1]);
    size_t _res = ((size_t (*)(multi_heap_handle_t, void *))lv_func_ptr)(heap, p);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_get_allocated_size_mpobj, 2, mp_multi_heap_get_allocated_size, multi_heap_get_allocated_size);
    

/*
 * espidf extension definition for:
 * multi_heap_handle_t multi_heap_register(void *start, size_t size)
 */

STATIC mp_obj_t mp_multi_heap_register(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *start = mp_to_ptr(mp_args[0]);
    size_t size = (size_t)mp_obj_get_int(mp_args[1]);
    multi_heap_handle_t _res = ((multi_heap_handle_t (*)(void *, size_t))lv_func_ptr)(start, size);
    return ptr_to_mp(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_register_mpobj, 2, mp_multi_heap_register, multi_heap_register);
    
/* Reusing multi_heap_aligned_free for multi_heap_set_lock */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_set_lock_mpobj, 2, mp_multi_heap_aligned_free, multi_heap_set_lock);
    

/*
 * espidf extension definition for:
 * void multi_heap_dump(multi_heap_handle_t heap)
 */

STATIC mp_obj_t mp_multi_heap_dump(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    ((void (*)(multi_heap_handle_t))lv_func_ptr)(heap);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_dump_mpobj, 1, mp_multi_heap_dump, multi_heap_dump);
    

/*
 * espidf extension definition for:
 * bool multi_heap_check(multi_heap_handle_t heap, bool print_errors)
 */

STATIC mp_obj_t mp_multi_heap_check(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    bool print_errors = mp_obj_is_true(mp_args[1]);
    bool _res = ((bool (*)(multi_heap_handle_t, bool))lv_func_ptr)(heap, print_errors);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_check_mpobj, 2, mp_multi_heap_check, multi_heap_check);
    

/*
 * espidf extension definition for:
 * size_t multi_heap_free_size(multi_heap_handle_t heap)
 */

STATIC mp_obj_t mp_multi_heap_free_size(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    size_t _res = ((size_t (*)(multi_heap_handle_t))lv_func_ptr)(heap);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_free_size_mpobj, 1, mp_multi_heap_free_size, multi_heap_free_size);
    
/* Reusing multi_heap_free_size for multi_heap_minimum_free_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_minimum_free_size_mpobj, 1, mp_multi_heap_free_size, multi_heap_minimum_free_size);
    

/*
 * espidf extension definition for:
 * void multi_heap_get_info(multi_heap_handle_t heap, multi_heap_info_t *info)
 */

STATIC mp_obj_t mp_multi_heap_get_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_handle_t heap = mp_to_ptr(mp_args[0]);
    multi_heap_info_t *info = mp_write_ptr_multi_heap_info_t(mp_args[1]);
    ((void (*)(multi_heap_handle_t, multi_heap_info_t *))lv_func_ptr)(heap, info);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_multi_heap_get_info_mpobj, 2, mp_multi_heap_get_info, multi_heap_get_info);
    

/*
 * Function NOT generated:
 * Callback argument 'esp_alloc_failed_hook_t callback' cannot be the first argument! We assume the first argument contains the user_data
 * esp_alloc_failed_hook_t callback
 */
    

/*
 * espidf extension definition for:
 * esp_err_t heap_caps_register_failed_alloc_callback(esp_alloc_failed_hook_t callback)
 */

STATIC mp_obj_t mp_heap_caps_register_failed_alloc_callback(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_alloc_failed_hook_t callback = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_alloc_failed_hook_t))lv_func_ptr)(callback);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_register_failed_alloc_callback_mpobj, 1, mp_heap_caps_register_failed_alloc_callback, heap_caps_register_failed_alloc_callback);
    

/*
 * espidf extension definition for:
 * void *heap_caps_malloc(size_t size, uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_malloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    size_t size = (size_t)mp_obj_get_int(mp_args[0]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[1]);
    void * _res = ((void *(*)(size_t, uint32_t))lv_func_ptr)(size, caps);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_malloc_mpobj, 2, mp_heap_caps_malloc, heap_caps_malloc);
    
/* Reusing funcptr_fn for heap_caps_free */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_free_mpobj, 1, mp_funcptr_fn, heap_caps_free);
    

/*
 * espidf extension definition for:
 * void *heap_caps_realloc(void *ptr, size_t size, uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_realloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *ptr = mp_to_ptr(mp_args[0]);
    size_t size = (size_t)mp_obj_get_int(mp_args[1]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(void *, size_t, uint32_t))lv_func_ptr)(ptr, size, caps);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_realloc_mpobj, 3, mp_heap_caps_realloc, heap_caps_realloc);
    

/*
 * espidf extension definition for:
 * void *heap_caps_aligned_alloc(size_t alignment, size_t size, uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_aligned_alloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    size_t alignment = (size_t)mp_obj_get_int(mp_args[0]);
    size_t size = (size_t)mp_obj_get_int(mp_args[1]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[2]);
    void * _res = ((void *(*)(size_t, size_t, uint32_t))lv_func_ptr)(alignment, size, caps);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_aligned_alloc_mpobj, 3, mp_heap_caps_aligned_alloc, heap_caps_aligned_alloc);
    
/* Reusing funcptr_fn for heap_caps_aligned_free */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_aligned_free_mpobj, 1, mp_funcptr_fn, heap_caps_aligned_free);
    

/*
 * espidf extension definition for:
 * void *heap_caps_aligned_calloc(size_t alignment, size_t n, size_t size, uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_aligned_calloc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    size_t alignment = (size_t)mp_obj_get_int(mp_args[0]);
    size_t n = (size_t)mp_obj_get_int(mp_args[1]);
    size_t size = (size_t)mp_obj_get_int(mp_args[2]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[3]);
    void * _res = ((void *(*)(size_t, size_t, size_t, uint32_t))lv_func_ptr)(alignment, n, size, caps);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_aligned_calloc_mpobj, 4, mp_heap_caps_aligned_calloc, heap_caps_aligned_calloc);
    
/* Reusing heap_caps_aligned_alloc for heap_caps_calloc */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_calloc_mpobj, 3, mp_heap_caps_aligned_alloc, heap_caps_calloc);
    

/*
 * espidf extension definition for:
 * size_t heap_caps_get_total_size(uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_get_total_size(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[0]);
    size_t _res = ((size_t (*)(uint32_t))lv_func_ptr)(caps);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_total_size_mpobj, 1, mp_heap_caps_get_total_size, heap_caps_get_total_size);
    
/* Reusing heap_caps_get_total_size for heap_caps_get_free_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_free_size_mpobj, 1, mp_heap_caps_get_total_size, heap_caps_get_free_size);
    
/* Reusing heap_caps_get_total_size for heap_caps_get_minimum_free_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_minimum_free_size_mpobj, 1, mp_heap_caps_get_total_size, heap_caps_get_minimum_free_size);
    
/* Reusing heap_caps_get_total_size for heap_caps_get_largest_free_block */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_largest_free_block_mpobj, 1, mp_heap_caps_get_total_size, heap_caps_get_largest_free_block);
    

/*
 * espidf extension definition for:
 * void heap_caps_get_info(multi_heap_info_t *info, uint32_t caps)
 */

STATIC mp_obj_t mp_heap_caps_get_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    multi_heap_info_t *info = mp_write_ptr_multi_heap_info_t(mp_args[0]);
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[1]);
    ((void (*)(multi_heap_info_t *, uint32_t))lv_func_ptr)(info, caps);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_info_mpobj, 2, mp_heap_caps_get_info, heap_caps_get_info);
    
/* Reusing esp_clk_slowclk_cal_set for heap_caps_print_heap_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_print_heap_info_mpobj, 1, mp_esp_clk_slowclk_cal_set, heap_caps_print_heap_info);
    

/*
 * espidf extension definition for:
 * bool heap_caps_check_integrity_all(bool print_errors)
 */

STATIC mp_obj_t mp_heap_caps_check_integrity_all(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    bool print_errors = mp_obj_is_true(mp_args[0]);
    bool _res = ((bool (*)(bool))lv_func_ptr)(print_errors);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_check_integrity_all_mpobj, 1, mp_heap_caps_check_integrity_all, heap_caps_check_integrity_all);
    

/*
 * espidf extension definition for:
 * bool heap_caps_check_integrity(uint32_t caps, bool print_errors)
 */

STATIC mp_obj_t mp_heap_caps_check_integrity(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t caps = (uint32_t)mp_obj_get_int(mp_args[0]);
    bool print_errors = mp_obj_is_true(mp_args[1]);
    bool _res = ((bool (*)(uint32_t, bool))lv_func_ptr)(caps, print_errors);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_check_integrity_mpobj, 2, mp_heap_caps_check_integrity, heap_caps_check_integrity);
    

/*
 * espidf extension definition for:
 * bool heap_caps_check_integrity_addr(intptr_t addr, bool print_errors)
 */

STATIC mp_obj_t mp_heap_caps_check_integrity_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    intptr_t addr = (int)mp_obj_get_int(mp_args[0]);
    bool print_errors = mp_obj_is_true(mp_args[1]);
    bool _res = ((bool (*)(intptr_t, bool))lv_func_ptr)(addr, print_errors);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_check_integrity_addr_mpobj, 2, mp_heap_caps_check_integrity_addr, heap_caps_check_integrity_addr);
    

/*
 * espidf extension definition for:
 * void heap_caps_malloc_extmem_enable(size_t limit)
 */

STATIC mp_obj_t mp_heap_caps_malloc_extmem_enable(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    size_t limit = (size_t)mp_obj_get_int(mp_args[0]);
    ((void (*)(size_t))lv_func_ptr)(limit);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_malloc_extmem_enable_mpobj, 1, mp_heap_caps_malloc_extmem_enable, heap_caps_malloc_extmem_enable);
    

/*
 * Function NOT generated:
 * Cannot convert ellipsis param
 * void *heap_caps_malloc_prefer(size_t size, size_t num, ...)
 */
    

/*
 * Function NOT generated:
 * Cannot convert ellipsis param
 * void *heap_caps_realloc_prefer(void *ptr, size_t size, size_t num, ...)
 */
    

/*
 * Function NOT generated:
 * Cannot convert ellipsis param
 * void *heap_caps_calloc_prefer(size_t n, size_t size, size_t num, ...)
 */
    
/* Reusing esp_clk_slowclk_cal_set for heap_caps_dump */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_dump_mpobj, 1, mp_esp_clk_slowclk_cal_set, heap_caps_dump);
    
/* Reusing funcptr_shutdown_handler_t for heap_caps_dump_all */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_dump_all_mpobj, 0, mp_funcptr_shutdown_handler_t, heap_caps_dump_all);
    

/*
 * espidf extension definition for:
 * size_t heap_caps_get_allocated_size(void *ptr)
 */

STATIC mp_obj_t mp_heap_caps_get_allocated_size(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *ptr = mp_to_ptr(mp_args[0]);
    size_t _res = ((size_t (*)(void *))lv_func_ptr)(ptr);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_heap_caps_get_allocated_size_mpobj, 1, mp_heap_caps_get_allocated_size, heap_caps_get_allocated_size);
    

/*
 * Function NOT generated:
 * Cannot convert ellipsis param
 * int esp_rom_printf(const char *fmt, ...)
 */
    
/* Reusing esp_clk_slowclk_cal_set for esp_rom_delay_us */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_rom_delay_us_mpobj, 1, mp_esp_clk_slowclk_cal_set, esp_rom_delay_us);
    

/*
 * Function NOT generated:
 * Callback function 'void (*putc)(char c)' must receive a struct pointer with user_data member as its first argument!
 * void (*putc)(char c)
 */
    
#define funcptr_putc NULL


/*
 * espidf extension definition for:
 * void putc(char c)
 */

STATIC mp_obj_t mp_funcptr_putc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    char c = (char)mp_obj_get_int(mp_args[0]);
    ((void (*)(char))lv_func_ptr)(c);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_putc_mpobj, 1, mp_funcptr_putc, funcptr_putc);
    
STATIC inline mp_obj_t mp_lv_funcptr_putc(void *func){ return mp_lv_funcptr(&mp_funcptr_putc_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * espidf extension definition for:
 * void esp_rom_install_channel_putc(int channel, void (*putc)(char c))
 */

STATIC mp_obj_t mp_esp_rom_install_channel_putc(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int channel = (int)mp_obj_get_int(mp_args[0]);
    void (*putc)(char c) = mp_to_ptr(mp_args[1]);
    ((void (*)(int, void (*)(char)))lv_func_ptr)(channel, putc);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_rom_install_channel_putc_mpobj, 2, mp_esp_rom_install_channel_putc, esp_rom_install_channel_putc);
    
/* Reusing funcptr_shutdown_handler_t for esp_rom_install_uart_printf */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_rom_install_uart_printf_mpobj, 0, mp_funcptr_shutdown_handler_t, esp_rom_install_uart_printf);
    

/*
 * espidf extension definition for:
 * soc_reset_reason_t esp_rom_get_reset_reason(int cpu_no)
 */

STATIC mp_obj_t mp_esp_rom_get_reset_reason(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    int cpu_no = (int)mp_obj_get_int(mp_args[0]);
    soc_reset_reason_t _res = ((soc_reset_reason_t (*)(int))lv_func_ptr)(cpu_no);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_rom_get_reset_reason_mpobj, 1, mp_esp_rom_get_reset_reason, esp_rom_get_reset_reason);
    

/*
 * espidf extension definition for:
 * void esp_log_level_set(const char *tag, esp_log_level_t level)
 */

STATIC mp_obj_t mp_esp_log_level_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *tag = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_log_level_t level = (int)mp_obj_get_int(mp_args[1]);
    ((void (*)(const char *, esp_log_level_t))lv_func_ptr)(tag, level);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_level_set_mpobj, 2, mp_esp_log_level_set, esp_log_level_set);
    

/*
 * espidf extension definition for:
 * esp_log_level_t esp_log_level_get(const char *tag)
 */

STATIC mp_obj_t mp_esp_log_level_get(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *tag = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_log_level_t _res = ((esp_log_level_t (*)(const char *))lv_func_ptr)(tag);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_level_get_mpobj, 1, mp_esp_log_level_get, esp_log_level_get);
    

/*
 * Function NOT generated:
 * Callback argument 'vprintf_like_t func' cannot be the first argument! We assume the first argument contains the user_data
 * vprintf_like_t func
 */
    

/*
 * espidf extension definition for:
 * vprintf_like_t esp_log_set_vprintf(vprintf_like_t func)
 */

STATIC mp_obj_t mp_esp_log_set_vprintf(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    vprintf_like_t func = mp_to_ptr(mp_args[0]);
    vprintf_like_t _res = ((vprintf_like_t (*)(vprintf_like_t))lv_func_ptr)(func);
    return ptr_to_mp(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_set_vprintf_mpobj, 1, mp_esp_log_set_vprintf, esp_log_set_vprintf);
    
/* Reusing esp_clk_slowclk_cal_get for esp_log_timestamp */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_timestamp_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_log_timestamp);
    

/*
 * espidf extension definition for:
 * char *esp_log_system_timestamp(void)
 */

STATIC mp_obj_t mp_esp_log_system_timestamp(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    char * _res = ((char *(*)(void))lv_func_ptr)();
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_system_timestamp_mpobj, 0, mp_esp_log_system_timestamp, esp_log_system_timestamp);
    
/* Reusing esp_clk_slowclk_cal_get for esp_log_early_timestamp */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_early_timestamp_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_log_early_timestamp);
    

/*
 * Function NOT generated:
 * Cannot convert ellipsis param
 * void esp_log_write(esp_log_level_t level, const char *tag, const char *format, ...)
 */
    

/*
 * Function NOT generated:
 * Missing conversion to va_list
 * void esp_log_writev(esp_log_level_t level, const char *tag, const char *format, va_list args)
 */
    

/*
 * espidf extension definition for:
 * void esp_log_buffer_hex_internal(const char *tag, const void *buffer, uint16_t buff_len, esp_log_level_t level)
 */

STATIC mp_obj_t mp_esp_log_buffer_hex_internal(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *tag = (const char *)(char*)convert_from_str(mp_args[0]);
    const void *buffer = (const void *)mp_to_ptr(mp_args[1]);
    uint16_t buff_len = (uint16_t)mp_obj_get_int(mp_args[2]);
    esp_log_level_t level = (int)mp_obj_get_int(mp_args[3]);
    ((void (*)(const char *, const void *, uint16_t, esp_log_level_t))lv_func_ptr)(tag, buffer, buff_len, level);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_buffer_hex_internal_mpobj, 4, mp_esp_log_buffer_hex_internal, esp_log_buffer_hex_internal);
    
/* Reusing esp_log_buffer_hex_internal for esp_log_buffer_char_internal */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_buffer_char_internal_mpobj, 4, mp_esp_log_buffer_hex_internal, esp_log_buffer_char_internal);
    
/* Reusing esp_log_buffer_hex_internal for esp_log_buffer_hexdump_internal */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_log_buffer_hexdump_internal_mpobj, 4, mp_esp_log_buffer_hex_internal, esp_log_buffer_hexdump_internal);
    
/* Reusing funcptr_shutdown_handler_t for adc_power_on */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_power_on_mpobj, 0, mp_funcptr_shutdown_handler_t, adc_power_on);
    
/* Reusing funcptr_shutdown_handler_t for adc_power_off */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_power_off_mpobj, 0, mp_funcptr_shutdown_handler_t, adc_power_off);
    
/* Reusing funcptr_shutdown_handler_t for adc_power_acquire */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_power_acquire_mpobj, 0, mp_funcptr_shutdown_handler_t, adc_power_acquire);
    
/* Reusing funcptr_shutdown_handler_t for adc_power_release */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_power_release_mpobj, 0, mp_funcptr_shutdown_handler_t, adc_power_release);
    

/*
 * espidf extension definition for:
 * esp_err_t adc1_pad_get_io_num(adc1_channel_t channel, gpio_num_t *gpio_num)
 */

STATIC mp_obj_t mp_adc1_pad_get_io_num(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc1_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    gpio_num_t *gpio_num = mp_array_to_i32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc1_channel_t, gpio_num_t *))lv_func_ptr)(channel, gpio_num);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc1_pad_get_io_num_mpobj, 2, mp_adc1_pad_get_io_num, adc1_pad_get_io_num);
    

/*
 * espidf extension definition for:
 * esp_err_t adc1_config_channel_atten(adc1_channel_t channel, adc_atten_t atten)
 */

STATIC mp_obj_t mp_adc1_config_channel_atten(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc1_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    adc_atten_t atten = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc1_channel_t, adc_atten_t))lv_func_ptr)(channel, atten);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc1_config_channel_atten_mpobj, 2, mp_adc1_config_channel_atten, adc1_config_channel_atten);
    

/*
 * espidf extension definition for:
 * esp_err_t adc1_config_width(adc_bits_width_t width_bit)
 */

STATIC mp_obj_t mp_adc1_config_width(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_bits_width_t width_bit = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(adc_bits_width_t))lv_func_ptr)(width_bit);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc1_config_width_mpobj, 1, mp_adc1_config_width, adc1_config_width);
    

/*
 * espidf extension definition for:
 * int adc1_get_raw(adc1_channel_t channel)
 */

STATIC mp_obj_t mp_adc1_get_raw(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc1_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    int _res = ((int (*)(adc1_channel_t))lv_func_ptr)(channel);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc1_get_raw_mpobj, 1, mp_adc1_get_raw, adc1_get_raw);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_set_data_inv(adc_unit_t adc_unit, bool inv_en)
 */

STATIC mp_obj_t mp_adc_set_data_inv(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_unit_t adc_unit = (int)mp_obj_get_int(mp_args[0]);
    bool inv_en = mp_obj_is_true(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc_unit_t, bool))lv_func_ptr)(adc_unit, inv_en);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_set_data_inv_mpobj, 2, mp_adc_set_data_inv, adc_set_data_inv);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_set_clk_div(uint8_t clk_div)
 */

STATIC mp_obj_t mp_adc_set_clk_div(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t clk_div = (uint8_t)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t))lv_func_ptr)(clk_div);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_set_clk_div_mpobj, 1, mp_adc_set_clk_div, adc_set_clk_div);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_set_data_width(adc_unit_t adc_unit, adc_bits_width_t width_bit)
 */

STATIC mp_obj_t mp_adc_set_data_width(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_unit_t adc_unit = (int)mp_obj_get_int(mp_args[0]);
    adc_bits_width_t width_bit = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc_unit_t, adc_bits_width_t))lv_func_ptr)(adc_unit, width_bit);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_set_data_width_mpobj, 2, mp_adc_set_data_width, adc_set_data_width);
    
/* Reusing funcptr_shutdown_handler_t for adc1_ulp_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc1_ulp_enable_mpobj, 0, mp_funcptr_shutdown_handler_t, adc1_ulp_enable);
    

/*
 * espidf extension definition for:
 * esp_err_t adc2_pad_get_io_num(adc2_channel_t channel, gpio_num_t *gpio_num)
 */

STATIC mp_obj_t mp_adc2_pad_get_io_num(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc2_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    gpio_num_t *gpio_num = mp_array_to_i32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc2_channel_t, gpio_num_t *))lv_func_ptr)(channel, gpio_num);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc2_pad_get_io_num_mpobj, 2, mp_adc2_pad_get_io_num, adc2_pad_get_io_num);
    

/*
 * espidf extension definition for:
 * esp_err_t adc2_config_channel_atten(adc2_channel_t channel, adc_atten_t atten)
 */

STATIC mp_obj_t mp_adc2_config_channel_atten(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc2_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    adc_atten_t atten = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc2_channel_t, adc_atten_t))lv_func_ptr)(channel, atten);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc2_config_channel_atten_mpobj, 2, mp_adc2_config_channel_atten, adc2_config_channel_atten);
    

/*
 * espidf extension definition for:
 * esp_err_t adc2_get_raw(adc2_channel_t channel, adc_bits_width_t width_bit, int *raw_out)
 */

STATIC mp_obj_t mp_adc2_get_raw(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc2_channel_t channel = (int)mp_obj_get_int(mp_args[0]);
    adc_bits_width_t width_bit = (int)mp_obj_get_int(mp_args[1]);
    int *raw_out = mp_array_to_i32ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(adc2_channel_t, adc_bits_width_t, int *))lv_func_ptr)(channel, width_bit, raw_out);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc2_get_raw_mpobj, 3, mp_adc2_get_raw, adc2_get_raw);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_vref_to_gpio(adc_unit_t adc_unit, gpio_num_t gpio)
 */

STATIC mp_obj_t mp_adc_vref_to_gpio(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_unit_t adc_unit = (int)mp_obj_get_int(mp_args[0]);
    gpio_num_t gpio = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc_unit_t, gpio_num_t))lv_func_ptr)(adc_unit, gpio);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_vref_to_gpio_mpobj, 2, mp_adc_vref_to_gpio, adc_vref_to_gpio);
    
/* Reusing gpio_reset_pin for adc2_vref_to_gpio */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc2_vref_to_gpio_mpobj, 1, mp_gpio_reset_pin, adc2_vref_to_gpio);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_digi_read_bytes(uint8_t *buf, uint32_t length_max, uint32_t *out_length, uint32_t timeout_ms)
 */

STATIC mp_obj_t mp_adc_digi_read_bytes(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *buf = mp_array_to_u8ptr(mp_args[0]);
    uint32_t length_max = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t *out_length = mp_array_to_u32ptr(mp_args[2]);
    uint32_t timeout_ms = (uint32_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *, uint32_t, uint32_t *, uint32_t))lv_func_ptr)(buf, length_max, out_length, timeout_ms);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_digi_read_bytes_mpobj, 4, mp_adc_digi_read_bytes, adc_digi_read_bytes);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_digi_start(void)
 */

STATIC mp_obj_t mp_adc_digi_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    esp_err_t _res = ((esp_err_t (*)(void))lv_func_ptr)();
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_digi_start_mpobj, 0, mp_adc_digi_start, adc_digi_start);
    
/* Reusing adc_digi_start for adc_digi_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_digi_stop_mpobj, 0, mp_adc_digi_start, adc_digi_stop);
    
/* Reusing adc_digi_start for adc_digi_deinitialize */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_digi_deinitialize_mpobj, 0, mp_adc_digi_start, adc_digi_deinitialize);
    
/* Reusing esp_clk_cpu_freq for hall_sensor_read */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_hall_sensor_read_mpobj, 0, mp_esp_clk_cpu_freq, hall_sensor_read);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_set_i2s_data_source(adc_i2s_source_t src)
 */

STATIC mp_obj_t mp_adc_set_i2s_data_source(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_i2s_source_t src = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(adc_i2s_source_t))lv_func_ptr)(src);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_set_i2s_data_source_mpobj, 1, mp_adc_set_i2s_data_source, adc_set_i2s_data_source);
    

/*
 * espidf extension definition for:
 * esp_err_t adc_i2s_mode_init(adc_unit_t adc_unit, adc_channel_t channel)
 */

STATIC mp_obj_t mp_adc_i2s_mode_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_unit_t adc_unit = (int)mp_obj_get_int(mp_args[0]);
    adc_channel_t channel = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc_unit_t, adc_channel_t))lv_func_ptr)(adc_unit, channel);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_adc_i2s_mode_init_mpobj, 2, mp_adc_i2s_mode_init, adc_i2s_mode_init);
    

/*
 * Struct i2s_pin_config_t
 */

STATIC inline const mp_obj_type_t *get_mp_i2s_pin_config_t_type();

STATIC inline void* mp_write_ptr_i2s_pin_config_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_i2s_pin_config_t_type()));
    return (i2s_pin_config_t*)self->data;
}

#define mp_write_i2s_pin_config_t(struct_obj) *((i2s_pin_config_t*)mp_write_ptr_i2s_pin_config_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_i2s_pin_config_t(void *field)
{
    return lv_to_mp_struct(get_mp_i2s_pin_config_t_type(), field);
}

#define mp_read_i2s_pin_config_t(field) mp_read_ptr_i2s_pin_config_t(copy_buffer(&field, sizeof(i2s_pin_config_t)))
#define mp_read_byref_i2s_pin_config_t(field) mp_read_ptr_i2s_pin_config_t(&field)

STATIC void mp_i2s_pin_config_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED i2s_pin_config_t *data = (i2s_pin_config_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mck_io_num: dest[0] = mp_obj_new_int(data->mck_io_num); break; // converting from int;
            case MP_QSTR_bck_io_num: dest[0] = mp_obj_new_int(data->bck_io_num); break; // converting from int;
            case MP_QSTR_ws_io_num: dest[0] = mp_obj_new_int(data->ws_io_num); break; // converting from int;
            case MP_QSTR_data_out_num: dest[0] = mp_obj_new_int(data->data_out_num); break; // converting from int;
            case MP_QSTR_data_in_num: dest[0] = mp_obj_new_int(data->data_in_num); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mck_io_num: data->mck_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_bck_io_num: data->bck_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_ws_io_num: data->ws_io_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data_out_num: data->data_out_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_data_in_num: data->data_in_num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_i2s_pin_config_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct i2s_pin_config_t");
}

STATIC const mp_obj_dict_t mp_i2s_pin_config_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_i2s_pin_config_t_type,
    MP_QSTR_i2s_pin_config_t,
    MP_TYPE_FLAG_NONE,
    print, mp_i2s_pin_config_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_i2s_pin_config_t_attr,
    locals_dict, &mp_i2s_pin_config_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_i2s_pin_config_t_type()
{
    return &mp_i2s_pin_config_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_pin(i2s_port_t i2s_num, const i2s_pin_config_t *pin)
 */

STATIC mp_obj_t mp_i2s_set_pin(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    const i2s_pin_config_t *pin = (const i2s_pin_config_t *)mp_write_ptr_i2s_pin_config_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, const i2s_pin_config_t *))lv_func_ptr)(i2s_num, pin);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_pin_mpobj, 2, mp_i2s_set_pin, i2s_set_pin);
    

STATIC const mp_rom_map_elem_t mp_i2s_pin_config_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(i2s_pin_config_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_i2s_pin_config_t_locals_dict, mp_i2s_pin_config_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_pdm_rx_down_sample(i2s_port_t i2s_num, i2s_pdm_dsr_t downsample)
 */

STATIC mp_obj_t mp_i2s_set_pdm_rx_down_sample(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    i2s_pdm_dsr_t downsample = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, i2s_pdm_dsr_t))lv_func_ptr)(i2s_num, downsample);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_pdm_rx_down_sample_mpobj, 2, mp_i2s_set_pdm_rx_down_sample, i2s_set_pdm_rx_down_sample);
    

/*
 * Struct i2s_pdm_tx_upsample_cfg_t
 */

STATIC inline const mp_obj_type_t *get_mp_i2s_pdm_tx_upsample_cfg_t_type();

STATIC inline void* mp_write_ptr_i2s_pdm_tx_upsample_cfg_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_i2s_pdm_tx_upsample_cfg_t_type()));
    return (i2s_pdm_tx_upsample_cfg_t*)self->data;
}

#define mp_write_i2s_pdm_tx_upsample_cfg_t(struct_obj) *((i2s_pdm_tx_upsample_cfg_t*)mp_write_ptr_i2s_pdm_tx_upsample_cfg_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_i2s_pdm_tx_upsample_cfg_t(void *field)
{
    return lv_to_mp_struct(get_mp_i2s_pdm_tx_upsample_cfg_t_type(), field);
}

#define mp_read_i2s_pdm_tx_upsample_cfg_t(field) mp_read_ptr_i2s_pdm_tx_upsample_cfg_t(copy_buffer(&field, sizeof(i2s_pdm_tx_upsample_cfg_t)))
#define mp_read_byref_i2s_pdm_tx_upsample_cfg_t(field) mp_read_ptr_i2s_pdm_tx_upsample_cfg_t(&field)

STATIC void mp_i2s_pdm_tx_upsample_cfg_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED i2s_pdm_tx_upsample_cfg_t *data = (i2s_pdm_tx_upsample_cfg_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_sample_rate: dest[0] = mp_obj_new_int(data->sample_rate); break; // converting from int;
            case MP_QSTR_fp: dest[0] = mp_obj_new_int(data->fp); break; // converting from int;
            case MP_QSTR_fs: dest[0] = mp_obj_new_int(data->fs); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_sample_rate: data->sample_rate = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_fp: data->fp = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                case MP_QSTR_fs: data->fs = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_i2s_pdm_tx_upsample_cfg_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct i2s_pdm_tx_upsample_cfg_t");
}

STATIC const mp_obj_dict_t mp_i2s_pdm_tx_upsample_cfg_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_i2s_pdm_tx_upsample_cfg_t_type,
    MP_QSTR_i2s_pdm_tx_upsample_cfg_t,
    MP_TYPE_FLAG_NONE,
    print, mp_i2s_pdm_tx_upsample_cfg_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_i2s_pdm_tx_upsample_cfg_t_attr,
    locals_dict, &mp_i2s_pdm_tx_upsample_cfg_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_i2s_pdm_tx_upsample_cfg_t_type()
{
    return &mp_i2s_pdm_tx_upsample_cfg_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_pdm_tx_up_sample(i2s_port_t i2s_num, const i2s_pdm_tx_upsample_cfg_t *upsample_cfg)
 */

STATIC mp_obj_t mp_i2s_set_pdm_tx_up_sample(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    const i2s_pdm_tx_upsample_cfg_t *upsample_cfg = (const i2s_pdm_tx_upsample_cfg_t *)mp_write_ptr_i2s_pdm_tx_upsample_cfg_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, const i2s_pdm_tx_upsample_cfg_t *))lv_func_ptr)(i2s_num, upsample_cfg);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_pdm_tx_up_sample_mpobj, 2, mp_i2s_set_pdm_tx_up_sample, i2s_set_pdm_tx_up_sample);
    

STATIC const mp_rom_map_elem_t mp_i2s_pdm_tx_upsample_cfg_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(i2s_pdm_tx_upsample_cfg_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_i2s_pdm_tx_upsample_cfg_t_locals_dict, mp_i2s_pdm_tx_upsample_cfg_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t i2s_driver_install(i2s_port_t i2s_num, const i2s_config_t *i2s_config, int queue_size, void *i2s_queue)
 */

STATIC mp_obj_t mp_i2s_driver_install(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    const i2s_config_t *i2s_config = (const i2s_config_t *)mp_to_ptr(mp_args[1]);
    int queue_size = (int)mp_obj_get_int(mp_args[2]);
    void *i2s_queue = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, const i2s_config_t *, int, void *))lv_func_ptr)(i2s_num, i2s_config, queue_size, i2s_queue);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_driver_install_mpobj, 4, mp_i2s_driver_install, i2s_driver_install);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_driver_uninstall(i2s_port_t i2s_num)
 */

STATIC mp_obj_t mp_i2s_driver_uninstall(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t))lv_func_ptr)(i2s_num);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_driver_uninstall_mpobj, 1, mp_i2s_driver_uninstall, i2s_driver_uninstall);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_write(i2s_port_t i2s_num, const void *src, size_t size, size_t *bytes_written, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_i2s_write(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    const void *src = (const void *)mp_to_ptr(mp_args[1]);
    size_t size = (size_t)mp_obj_get_int(mp_args[2]);
    size_t *bytes_written = mp_array_to_u32ptr(mp_args[3]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, const void *, size_t, size_t *, TickType_t))lv_func_ptr)(i2s_num, src, size, bytes_written, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_write_mpobj, 5, mp_i2s_write, i2s_write);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_write_expand(i2s_port_t i2s_num, const void *src, size_t size, size_t src_bits, size_t aim_bits, size_t *bytes_written, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_i2s_write_expand(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    const void *src = (const void *)mp_to_ptr(mp_args[1]);
    size_t size = (size_t)mp_obj_get_int(mp_args[2]);
    size_t src_bits = (size_t)mp_obj_get_int(mp_args[3]);
    size_t aim_bits = (size_t)mp_obj_get_int(mp_args[4]);
    size_t *bytes_written = mp_array_to_u32ptr(mp_args[5]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[6]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, const void *, size_t, size_t, size_t, size_t *, TickType_t))lv_func_ptr)(i2s_num, src, size, src_bits, aim_bits, bytes_written, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_write_expand_mpobj, 7, mp_i2s_write_expand, i2s_write_expand);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_read(i2s_port_t i2s_num, void *dest, size_t size, size_t *bytes_read, TickType_t ticks_to_wait)
 */

STATIC mp_obj_t mp_i2s_read(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    void *dest = mp_to_ptr(mp_args[1]);
    size_t size = (size_t)mp_obj_get_int(mp_args[2]);
    size_t *bytes_read = mp_array_to_u32ptr(mp_args[3]);
    TickType_t ticks_to_wait = (uint32_t)mp_obj_get_int(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, void *, size_t, size_t *, TickType_t))lv_func_ptr)(i2s_num, dest, size, bytes_read, ticks_to_wait);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_read_mpobj, 5, mp_i2s_read, i2s_read);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_sample_rates(i2s_port_t i2s_num, uint32_t rate)
 */

STATIC mp_obj_t mp_i2s_set_sample_rates(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    uint32_t rate = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, uint32_t))lv_func_ptr)(i2s_num, rate);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_sample_rates_mpobj, 2, mp_i2s_set_sample_rates, i2s_set_sample_rates);
    
/* Reusing i2s_driver_uninstall for i2s_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_stop_mpobj, 1, mp_i2s_driver_uninstall, i2s_stop);
    
/* Reusing i2s_driver_uninstall for i2s_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_start_mpobj, 1, mp_i2s_driver_uninstall, i2s_start);
    
/* Reusing i2s_driver_uninstall for i2s_zero_dma_buffer */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_zero_dma_buffer_mpobj, 1, mp_i2s_driver_uninstall, i2s_zero_dma_buffer);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_clk(i2s_port_t i2s_num, uint32_t rate, uint32_t bits_cfg, i2s_channel_t ch)
 */

STATIC mp_obj_t mp_i2s_set_clk(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    uint32_t rate = (uint32_t)mp_obj_get_int(mp_args[1]);
    uint32_t bits_cfg = (uint32_t)mp_obj_get_int(mp_args[2]);
    i2s_channel_t ch = (int)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(i2s_port_t, uint32_t, uint32_t, i2s_channel_t))lv_func_ptr)(i2s_num, rate, bits_cfg, ch);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_clk_mpobj, 4, mp_i2s_set_clk, i2s_set_clk);
    

/*
 * espidf extension definition for:
 * float i2s_get_clk(i2s_port_t i2s_num)
 */

STATIC mp_obj_t mp_i2s_get_clk(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_port_t i2s_num = (int)mp_obj_get_int(mp_args[0]);
    float _res = ((float (*)(i2s_port_t))lv_func_ptr)(i2s_num);
    return mp_obj_new_float(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_get_clk_mpobj, 1, mp_i2s_get_clk, i2s_get_clk);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_adc_mode(adc_unit_t adc_unit, adc1_channel_t adc_channel)
 */

STATIC mp_obj_t mp_i2s_set_adc_mode(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    adc_unit_t adc_unit = (int)mp_obj_get_int(mp_args[0]);
    adc1_channel_t adc_channel = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(adc_unit_t, adc1_channel_t))lv_func_ptr)(adc_unit, adc_channel);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_adc_mode_mpobj, 2, mp_i2s_set_adc_mode, i2s_set_adc_mode);
    
/* Reusing i2s_driver_uninstall for i2s_adc_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_adc_enable_mpobj, 1, mp_i2s_driver_uninstall, i2s_adc_enable);
    
/* Reusing i2s_driver_uninstall for i2s_adc_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_adc_disable_mpobj, 1, mp_i2s_driver_uninstall, i2s_adc_disable);
    

/*
 * espidf extension definition for:
 * esp_err_t i2s_set_dac_mode(i2s_dac_mode_t dac_mode)
 */

STATIC mp_obj_t mp_i2s_set_dac_mode(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    i2s_dac_mode_t dac_mode = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(i2s_dac_mode_t))lv_func_ptr)(dac_mode);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_i2s_set_dac_mode_mpobj, 1, mp_i2s_set_dac_mode, i2s_set_dac_mode);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_get_counter_value(pcnt_unit_t pcnt_unit, int16_t *count)
 */

STATIC mp_obj_t mp_pcnt_get_counter_value(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t pcnt_unit = (int)mp_obj_get_int(mp_args[0]);
    int16_t *count = mp_array_to_i16ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, int16_t *))lv_func_ptr)(pcnt_unit, count);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_get_counter_value_mpobj, 2, mp_pcnt_get_counter_value, pcnt_get_counter_value);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_counter_pause(pcnt_unit_t pcnt_unit)
 */

STATIC mp_obj_t mp_pcnt_counter_pause(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t pcnt_unit = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t))lv_func_ptr)(pcnt_unit);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_counter_pause_mpobj, 1, mp_pcnt_counter_pause, pcnt_counter_pause);
    
/* Reusing pcnt_counter_pause for pcnt_counter_resume */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_counter_resume_mpobj, 1, mp_pcnt_counter_pause, pcnt_counter_resume);
    
/* Reusing pcnt_counter_pause for pcnt_counter_clear */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_counter_clear_mpobj, 1, mp_pcnt_counter_pause, pcnt_counter_clear);
    
/* Reusing pcnt_counter_pause for pcnt_intr_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_intr_enable_mpobj, 1, mp_pcnt_counter_pause, pcnt_intr_enable);
    
/* Reusing pcnt_counter_pause for pcnt_intr_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_intr_disable_mpobj, 1, mp_pcnt_counter_pause, pcnt_intr_disable);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_event_enable(pcnt_unit_t unit, pcnt_evt_type_t evt_type)
 */

STATIC mp_obj_t mp_pcnt_event_enable(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    pcnt_evt_type_t evt_type = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, pcnt_evt_type_t))lv_func_ptr)(unit, evt_type);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_event_enable_mpobj, 2, mp_pcnt_event_enable, pcnt_event_enable);
    
/* Reusing pcnt_event_enable for pcnt_event_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_event_disable_mpobj, 2, mp_pcnt_event_enable, pcnt_event_disable);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_set_event_value(pcnt_unit_t unit, pcnt_evt_type_t evt_type, int16_t value)
 */

STATIC mp_obj_t mp_pcnt_set_event_value(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    pcnt_evt_type_t evt_type = (int)mp_obj_get_int(mp_args[1]);
    int16_t value = (int16_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, pcnt_evt_type_t, int16_t))lv_func_ptr)(unit, evt_type, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_set_event_value_mpobj, 3, mp_pcnt_set_event_value, pcnt_set_event_value);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_get_event_value(pcnt_unit_t unit, pcnt_evt_type_t evt_type, int16_t *value)
 */

STATIC mp_obj_t mp_pcnt_get_event_value(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    pcnt_evt_type_t evt_type = (int)mp_obj_get_int(mp_args[1]);
    int16_t *value = mp_array_to_i16ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, pcnt_evt_type_t, int16_t *))lv_func_ptr)(unit, evt_type, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_get_event_value_mpobj, 3, mp_pcnt_get_event_value, pcnt_get_event_value);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_get_event_status(pcnt_unit_t unit, uint32_t *status)
 */

STATIC mp_obj_t mp_pcnt_get_event_status(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    uint32_t *status = mp_array_to_u32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, uint32_t *))lv_func_ptr)(unit, status);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_get_event_status_mpobj, 2, mp_pcnt_get_event_status, pcnt_get_event_status);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_isr_unregister(pcnt_isr_handle_t handle)
 */

STATIC mp_obj_t mp_pcnt_isr_unregister(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_isr_handle_t handle = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_isr_handle_t))lv_func_ptr)(handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_unregister_mpobj, 1, mp_pcnt_isr_unregister, pcnt_isr_unregister);
    

/*
 * Function NOT generated:
 * Callback argument 'void (*fn)(void *)' cannot be the first argument! We assume the first argument contains the user_data
 * void (*fn)(void *)
 */
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_isr_register(void (*fn)(void *), void *arg, int intr_alloc_flags, pcnt_isr_handle_t *handle)
 */

STATIC mp_obj_t mp_pcnt_isr_register(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void (*fn)(void *) = mp_to_ptr(mp_args[0]);
    void *arg = mp_to_ptr(mp_args[1]);
    int intr_alloc_flags = (int)mp_obj_get_int(mp_args[2]);
    pcnt_isr_handle_t *handle = mp_to_ptr(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(void (*)(void *), void *, int, pcnt_isr_handle_t *))lv_func_ptr)(fn, arg, intr_alloc_flags, handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_register_mpobj, 4, mp_pcnt_isr_register, pcnt_isr_register);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_set_pin(pcnt_unit_t unit, pcnt_channel_t channel, int pulse_io, int ctrl_io)
 */

STATIC mp_obj_t mp_pcnt_set_pin(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    pcnt_channel_t channel = (int)mp_obj_get_int(mp_args[1]);
    int pulse_io = (int)mp_obj_get_int(mp_args[2]);
    int ctrl_io = (int)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, pcnt_channel_t, int, int))lv_func_ptr)(unit, channel, pulse_io, ctrl_io);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_set_pin_mpobj, 4, mp_pcnt_set_pin, pcnt_set_pin);
    
/* Reusing pcnt_counter_pause for pcnt_filter_enable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_filter_enable_mpobj, 1, mp_pcnt_counter_pause, pcnt_filter_enable);
    
/* Reusing pcnt_counter_pause for pcnt_filter_disable */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_filter_disable_mpobj, 1, mp_pcnt_counter_pause, pcnt_filter_disable);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_set_filter_value(pcnt_unit_t unit, uint16_t filter_val)
 */

STATIC mp_obj_t mp_pcnt_set_filter_value(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    uint16_t filter_val = (uint16_t)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, uint16_t))lv_func_ptr)(unit, filter_val);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_set_filter_value_mpobj, 2, mp_pcnt_set_filter_value, pcnt_set_filter_value);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_get_filter_value(pcnt_unit_t unit, uint16_t *filter_val)
 */

STATIC mp_obj_t mp_pcnt_get_filter_value(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    uint16_t *filter_val = mp_array_to_u16ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, uint16_t *))lv_func_ptr)(unit, filter_val);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_get_filter_value_mpobj, 2, mp_pcnt_get_filter_value, pcnt_get_filter_value);
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_set_mode(pcnt_unit_t unit, pcnt_channel_t channel, pcnt_count_mode_t pos_mode, pcnt_count_mode_t neg_mode, pcnt_ctrl_mode_t hctrl_mode, pcnt_ctrl_mode_t lctrl_mode)
 */

STATIC mp_obj_t mp_pcnt_set_mode(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    pcnt_channel_t channel = (int)mp_obj_get_int(mp_args[1]);
    pcnt_count_mode_t pos_mode = (int)mp_obj_get_int(mp_args[2]);
    pcnt_count_mode_t neg_mode = (int)mp_obj_get_int(mp_args[3]);
    pcnt_ctrl_mode_t hctrl_mode = (int)mp_obj_get_int(mp_args[4]);
    pcnt_ctrl_mode_t lctrl_mode = (int)mp_obj_get_int(mp_args[5]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, pcnt_channel_t, pcnt_count_mode_t, pcnt_count_mode_t, pcnt_ctrl_mode_t, pcnt_ctrl_mode_t))lv_func_ptr)(unit, channel, pos_mode, neg_mode, hctrl_mode, lctrl_mode);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_set_mode_mpobj, 6, mp_pcnt_set_mode, pcnt_set_mode);
    

/*
 * Function NOT generated:
 * Callback function 'void (*isr_handler)(void *)' must receive a struct pointer with user_data member as its first argument!
 * void (*isr_handler)(void *)
 */
    

/*
 * espidf extension definition for:
 * esp_err_t pcnt_isr_handler_add(pcnt_unit_t unit, void (*isr_handler)(void *), void *args)
 */

STATIC mp_obj_t mp_pcnt_isr_handler_add(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    pcnt_unit_t unit = (int)mp_obj_get_int(mp_args[0]);
    void (*isr_handler)(void *) = mp_to_ptr(mp_args[1]);
    void *args = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(pcnt_unit_t, void (*)(void *), void *))lv_func_ptr)(unit, isr_handler, args);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_handler_add_mpobj, 3, mp_pcnt_isr_handler_add, pcnt_isr_handler_add);
    
/* Reusing gpio_install_isr_service for pcnt_isr_service_install */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_service_install_mpobj, 1, mp_gpio_install_isr_service, pcnt_isr_service_install);
    
/* Reusing funcptr_shutdown_handler_t for pcnt_isr_service_uninstall */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_service_uninstall_mpobj, 0, mp_funcptr_shutdown_handler_t, pcnt_isr_service_uninstall);
    
/* Reusing pcnt_counter_pause for pcnt_isr_handler_remove */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_pcnt_isr_handler_remove_mpobj, 1, mp_pcnt_counter_pause, pcnt_isr_handler_remove);
    
/* Reusing funcptr_on_lowlevel_init_done for esp_eth_driver_uninstall */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_driver_uninstall_mpobj, 1, mp_funcptr_on_lowlevel_init_done, esp_eth_driver_uninstall);
    
/* Reusing funcptr_on_lowlevel_init_done for esp_eth_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_start_mpobj, 1, mp_funcptr_on_lowlevel_init_done, esp_eth_start);
    
/* Reusing funcptr_on_lowlevel_init_done for esp_eth_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_stop_mpobj, 1, mp_funcptr_on_lowlevel_init_done, esp_eth_stop);
    

/*
 * Function NOT generated:
 * Callback function 'esp_err_t (*stack_input)(esp_eth_handle_t hdl, uint8_t *buffer, uint32_t length, void *priv)' must receive a struct pointer with user_data member as its first argument!
 * esp_err_t (*stack_input)(esp_eth_handle_t hdl, uint8_t *buffer, uint32_t length, void *priv)
 */
    
#define funcptr_stack_input_2 NULL

/* Reusing funcptr_stack_input_1 for funcptr_stack_input_2 */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_stack_input_2_mpobj, 4, mp_funcptr_stack_input_1, funcptr_stack_input_2);
    
STATIC inline mp_obj_t mp_lv_funcptr_stack_input_2(void *func){ return mp_lv_funcptr(&mp_funcptr_stack_input_2_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * espidf extension definition for:
 * esp_err_t esp_eth_update_input_path(esp_eth_handle_t hdl, esp_err_t (*stack_input)(esp_eth_handle_t hdl, uint8_t *buffer, uint32_t length, void *priv), void *priv)
 */

STATIC mp_obj_t mp_esp_eth_update_input_path(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t hdl = mp_to_ptr(mp_args[0]);
    esp_err_t (*stack_input)(esp_eth_handle_t hdl, uint8_t *buffer, uint32_t length, void *priv) = mp_to_ptr(mp_args[1]);
    void *priv = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, esp_err_t (*)(esp_eth_handle_t, uint8_t *, uint32_t, void *), void *))lv_func_ptr)(hdl, stack_input, priv);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_update_input_path_mpobj, 3, mp_esp_eth_update_input_path, esp_eth_update_input_path);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_transmit(esp_eth_handle_t hdl, void *buf, size_t length)
 */

STATIC mp_obj_t mp_esp_eth_transmit(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t hdl = mp_to_ptr(mp_args[0]);
    void *buf = mp_to_ptr(mp_args[1]);
    size_t length = (size_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, void *, size_t))lv_func_ptr)(hdl, buf, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_transmit_mpobj, 3, mp_esp_eth_transmit, esp_eth_transmit);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_receive(esp_eth_handle_t hdl, uint8_t *buf, uint32_t *length)
 */

STATIC mp_obj_t mp_esp_eth_receive(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t hdl = mp_to_ptr(mp_args[0]);
    uint8_t *buf = mp_array_to_u8ptr(mp_args[1]);
    uint32_t *length = mp_array_to_u32ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, uint8_t *, uint32_t *))lv_func_ptr)(hdl, buf, length);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_receive_mpobj, 3, mp_esp_eth_receive, esp_eth_receive);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_ioctl(esp_eth_handle_t hdl, esp_eth_io_cmd_t cmd, void *data)
 */

STATIC mp_obj_t mp_esp_eth_ioctl(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t hdl = mp_to_ptr(mp_args[0]);
    esp_eth_io_cmd_t cmd = (int)mp_obj_get_int(mp_args[1]);
    void *data = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_handle_t, esp_eth_io_cmd_t, void *))lv_func_ptr)(hdl, cmd, data);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_ioctl_mpobj, 3, mp_esp_eth_ioctl, esp_eth_ioctl);
    
/* Reusing funcptr_on_lowlevel_init_done for esp_eth_increase_reference */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_increase_reference_mpobj, 1, mp_funcptr_on_lowlevel_init_done, esp_eth_increase_reference);
    
/* Reusing funcptr_on_lowlevel_init_done for esp_eth_decrease_reference */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_decrease_reference_mpobj, 1, mp_funcptr_on_lowlevel_init_done, esp_eth_decrease_reference);
    

/*
 * espidf extension definition for:
 * esp_eth_netif_glue_handle_t esp_eth_new_netif_glue(esp_eth_handle_t eth_hdl)
 */

STATIC mp_obj_t mp_esp_eth_new_netif_glue(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_handle_t eth_hdl = mp_to_ptr(mp_args[0]);
    esp_eth_netif_glue_handle_t _res = ((esp_eth_netif_glue_handle_t (*)(esp_eth_handle_t))lv_func_ptr)(eth_hdl);
    return ptr_to_mp(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_new_netif_glue_mpobj, 1, mp_esp_eth_new_netif_glue, esp_eth_new_netif_glue);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_eth_del_netif_glue(esp_eth_netif_glue_handle_t eth_netif_glue)
 */

STATIC mp_obj_t mp_esp_eth_del_netif_glue(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_eth_netif_glue_handle_t eth_netif_glue = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_eth_netif_glue_handle_t))lv_func_ptr)(eth_netif_glue);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_del_netif_glue_mpobj, 1, mp_esp_eth_del_netif_glue, esp_eth_del_netif_glue);
    
/* Reusing funcptr_crt_bundle_attach for esp_eth_set_default_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_set_default_handlers_mpobj, 1, mp_funcptr_crt_bundle_attach, esp_eth_set_default_handlers);
    
/* Reusing funcptr_crt_bundle_attach for esp_eth_clear_default_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_eth_clear_default_handlers_mpobj, 1, mp_funcptr_crt_bundle_attach, esp_eth_clear_default_handlers);
    
/* Reusing esp_clk_cpu_freq for xt_clock_freq */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_xt_clock_freq_mpobj, 0, mp_esp_clk_cpu_freq, xt_clock_freq);
    
/* Reusing funcptr_fn for vPortCleanUpTCB */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_vPortCleanUpTCB_mpobj, 1, mp_funcptr_fn, vPortCleanUpTCB);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_base_mac_addr_set(const uint8_t *mac)
 */

STATIC mp_obj_t mp_esp_base_mac_addr_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const uint8_t *mac = (const uint8_t *)mp_array_to_u8ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const uint8_t *))lv_func_ptr)(mac);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_base_mac_addr_set_mpobj, 1, mp_esp_base_mac_addr_set, esp_base_mac_addr_set);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_base_mac_addr_get(uint8_t *mac)
 */

STATIC mp_obj_t mp_esp_base_mac_addr_get(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *mac = mp_array_to_u8ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *))lv_func_ptr)(mac);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_base_mac_addr_get_mpobj, 1, mp_esp_base_mac_addr_get, esp_base_mac_addr_get);
    
/* Reusing esp_base_mac_addr_get for esp_efuse_mac_get_custom */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_efuse_mac_get_custom_mpobj, 1, mp_esp_base_mac_addr_get, esp_efuse_mac_get_custom);
    
/* Reusing esp_base_mac_addr_get for esp_efuse_mac_get_default */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_efuse_mac_get_default_mpobj, 1, mp_esp_base_mac_addr_get, esp_efuse_mac_get_default);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_read_mac(uint8_t *mac, esp_mac_type_t type)
 */

STATIC mp_obj_t mp_esp_read_mac(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *mac = mp_array_to_u8ptr(mp_args[0]);
    esp_mac_type_t type = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *, esp_mac_type_t))lv_func_ptr)(mac, type);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_read_mac_mpobj, 2, mp_esp_read_mac, esp_read_mac);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_derive_local_mac(uint8_t *local_mac, const uint8_t *universal_mac)
 */

STATIC mp_obj_t mp_esp_derive_local_mac(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *local_mac = mp_array_to_u8ptr(mp_args[0]);
    const uint8_t *universal_mac = (const uint8_t *)mp_array_to_u8ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *, const uint8_t *))lv_func_ptr)(local_mac, universal_mac);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_derive_local_mac_mpobj, 2, mp_esp_derive_local_mac, esp_derive_local_mac);
    
/* Reusing esp_clk_slowclk_cal_get for esp_random */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_random_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_random);
    

/*
 * espidf extension definition for:
 * void esp_fill_random(void *buf, size_t len)
 */

STATIC mp_obj_t mp_esp_fill_random(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *buf = mp_to_ptr(mp_args[0]);
    size_t len = (size_t)mp_obj_get_int(mp_args[1]);
    ((void (*)(void *, size_t))lv_func_ptr)(buf, len);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_fill_random_mpobj, 2, mp_esp_fill_random, esp_fill_random);
    

/*
 * Function NOT generated:
 * Callback argument 'shutdown_handler_t handle' cannot be the first argument! We assume the first argument contains the user_data
 * shutdown_handler_t handle
 */
    

/*
 * espidf extension definition for:
 * esp_err_t esp_register_shutdown_handler(shutdown_handler_t handle)
 */

STATIC mp_obj_t mp_esp_register_shutdown_handler(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    shutdown_handler_t handle = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(shutdown_handler_t))lv_func_ptr)(handle);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_register_shutdown_handler_mpobj, 1, mp_esp_register_shutdown_handler, esp_register_shutdown_handler);
    
/* Reusing esp_register_shutdown_handler for esp_unregister_shutdown_handler */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_unregister_shutdown_handler_mpobj, 1, mp_esp_register_shutdown_handler, esp_unregister_shutdown_handler);
    
/* Reusing funcptr_shutdown_handler_t for esp_restart */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_restart_mpobj, 0, mp_funcptr_shutdown_handler_t, esp_restart);
    

/*
 * espidf extension definition for:
 * esp_reset_reason_t esp_reset_reason(void)
 */

STATIC mp_obj_t mp_esp_reset_reason(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    esp_reset_reason_t _res = ((esp_reset_reason_t (*)(void))lv_func_ptr)();
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_reset_reason_mpobj, 0, mp_esp_reset_reason, esp_reset_reason);
    
/* Reusing esp_clk_slowclk_cal_get for esp_get_free_heap_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_get_free_heap_size_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_get_free_heap_size);
    
/* Reusing esp_clk_slowclk_cal_get for esp_get_free_internal_heap_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_get_free_internal_heap_size_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_get_free_internal_heap_size);
    
/* Reusing esp_clk_slowclk_cal_get for esp_get_minimum_free_heap_size */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_get_minimum_free_heap_size_mpobj, 0, mp_esp_clk_slowclk_cal_get, esp_get_minimum_free_heap_size);
    

/*
 * espidf extension definition for:
 * void esp_system_abort(const char *details)
 */

STATIC mp_obj_t mp_esp_system_abort(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *details = (const char *)(char*)convert_from_str(mp_args[0]);
    ((void (*)(const char *))lv_func_ptr)(details);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_system_abort_mpobj, 1, mp_esp_system_abort, esp_system_abort);
    

/*
 * espidf extension definition for:
 * bool dhcp_ip_addr_restore(void *netif)
 */

STATIC mp_obj_t mp_dhcp_ip_addr_restore(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *netif = mp_to_ptr(mp_args[0]);
    bool _res = ((bool (*)(void *))lv_func_ptr)(netif);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcp_ip_addr_restore_mpobj, 1, mp_dhcp_ip_addr_restore, dhcp_ip_addr_restore);
    
/* Reusing funcptr_fn for dhcp_ip_addr_store */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcp_ip_addr_store_mpobj, 1, mp_funcptr_fn, dhcp_ip_addr_store);
    
/* Reusing funcptr_fn for dhcp_ip_addr_erase */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcp_ip_addr_erase_mpobj, 1, mp_funcptr_fn, dhcp_ip_addr_erase);
    
/* Reusing esp_clk_slowclk_cal_get for sntp_get_sync_interval */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_sntp_get_sync_interval_mpobj, 0, mp_esp_clk_slowclk_cal_get, sntp_get_sync_interval);
    
/* Reusing gpio_iomux_in for sntp_set_system_time */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_sntp_set_system_time_mpobj, 2, mp_gpio_iomux_in, sntp_set_system_time);
    

/*
 * espidf extension definition for:
 * void sntp_get_system_time(uint32_t *sec, uint32_t *us)
 */

STATIC mp_obj_t mp_sntp_get_system_time(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint32_t *sec = mp_array_to_u32ptr(mp_args[0]);
    uint32_t *us = mp_array_to_u32ptr(mp_args[1]);
    ((void (*)(uint32_t *, uint32_t *))lv_func_ptr)(sec, us);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_sntp_get_system_time_mpobj, 2, mp_sntp_get_system_time, sntp_get_system_time);
    

/*
 * espidf extension definition for:
 * u16_t lwip_htons(u16_t x)
 */

STATIC mp_obj_t mp_lwip_htons(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u16_t x = (uint16_t)mp_obj_get_int(mp_args[0]);
    u16_t _res = ((u16_t (*)(u16_t))lv_func_ptr)(x);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_htons_mpobj, 1, mp_lwip_htons, lwip_htons);
    

/*
 * espidf extension definition for:
 * u32_t lwip_htonl(u32_t x)
 */

STATIC mp_obj_t mp_lwip_htonl(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u32_t x = (uint32_t)mp_obj_get_int(mp_args[0]);
    u32_t _res = ((u32_t (*)(u32_t))lv_func_ptr)(x);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_htonl_mpobj, 1, mp_lwip_htonl, lwip_htonl);
    

/*
 * espidf extension definition for:
 * void lwip_itoa(char *result, size_t bufsize, int number)
 */

STATIC mp_obj_t mp_lwip_itoa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    char *result = (char*)convert_from_str(mp_args[0]);
    size_t bufsize = (size_t)mp_obj_get_int(mp_args[1]);
    int number = (int)mp_obj_get_int(mp_args[2]);
    ((void (*)(char *, size_t, int))lv_func_ptr)(result, bufsize, number);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_itoa_mpobj, 3, mp_lwip_itoa, lwip_itoa);
    

/*
 * espidf extension definition for:
 * int lwip_strnicmp(const char *str1, const char *str2, size_t len)
 */

STATIC mp_obj_t mp_lwip_strnicmp(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *str1 = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *str2 = (const char *)(char*)convert_from_str(mp_args[1]);
    size_t len = (size_t)mp_obj_get_int(mp_args[2]);
    int _res = ((int (*)(const char *, const char *, size_t))lv_func_ptr)(str1, str2, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_strnicmp_mpobj, 3, mp_lwip_strnicmp, lwip_strnicmp);
    

/*
 * espidf extension definition for:
 * int lwip_stricmp(const char *str1, const char *str2)
 */

STATIC mp_obj_t mp_lwip_stricmp(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *str1 = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *str2 = (const char *)(char*)convert_from_str(mp_args[1]);
    int _res = ((int (*)(const char *, const char *))lv_func_ptr)(str1, str2);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_stricmp_mpobj, 2, mp_lwip_stricmp, lwip_stricmp);
    

/*
 * espidf extension definition for:
 * char *lwip_strnstr(const char *buffer, const char *token, size_t n)
 */

STATIC mp_obj_t mp_lwip_strnstr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *buffer = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *token = (const char *)(char*)convert_from_str(mp_args[1]);
    size_t n = (size_t)mp_obj_get_int(mp_args[2]);
    char * _res = ((char *(*)(const char *, const char *, size_t))lv_func_ptr)(buffer, token, n);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_lwip_strnstr_mpobj, 3, mp_lwip_strnstr, lwip_strnstr);
    

/*
 * espidf extension definition for:
 * u8_t ip4_addr_isbroadcast_u32(u32_t addr, const struct netif *netif)
 */

STATIC mp_obj_t mp_ip4_addr_isbroadcast_u32(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u32_t addr = (uint32_t)mp_obj_get_int(mp_args[0]);
    const struct netif *netif = (const struct netif *)mp_to_ptr(mp_args[1]);
    u8_t _res = ((u8_t (*)(u32_t, const struct netif *))lv_func_ptr)(addr, netif);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ip4_addr_isbroadcast_u32_mpobj, 2, mp_ip4_addr_isbroadcast_u32, ip4_addr_isbroadcast_u32);
    

/*
 * espidf extension definition for:
 * u8_t ip4_addr_netmask_valid(u32_t netmask)
 */

STATIC mp_obj_t mp_ip4_addr_netmask_valid(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u32_t netmask = (uint32_t)mp_obj_get_int(mp_args[0]);
    u8_t _res = ((u8_t (*)(u32_t))lv_func_ptr)(netmask);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ip4_addr_netmask_valid_mpobj, 1, mp_ip4_addr_netmask_valid, ip4_addr_netmask_valid);
    

/*
 * espidf extension definition for:
 * u32_t ipaddr_addr(const char *cp)
 */

STATIC mp_obj_t mp_ipaddr_addr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *cp = (const char *)(char*)convert_from_str(mp_args[0]);
    u32_t _res = ((u32_t (*)(const char *))lv_func_ptr)(cp);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ipaddr_addr_mpobj, 1, mp_ipaddr_addr, ipaddr_addr);
    

/*
 * espidf extension definition for:
 * int ip4addr_aton(const char *cp, ip4_addr_t *addr)
 */

STATIC mp_obj_t mp_ip4addr_aton(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *cp = (const char *)(char*)convert_from_str(mp_args[0]);
    ip4_addr_t *addr = mp_write_ptr_ip4_addr_t(mp_args[1]);
    int _res = ((int (*)(const char *, ip4_addr_t *))lv_func_ptr)(cp, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ip4addr_aton_mpobj, 2, mp_ip4addr_aton, ip4addr_aton);
    

/*
 * espidf extension definition for:
 * int ip6addr_aton(const char *cp, ip6_addr_t *addr)
 */

STATIC mp_obj_t mp_ip6addr_aton(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *cp = (const char *)(char*)convert_from_str(mp_args[0]);
    ip6_addr_t *addr = mp_write_ptr_ip6_addr_t(mp_args[1]);
    int _res = ((int (*)(const char *, ip6_addr_t *))lv_func_ptr)(cp, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ip6addr_aton_mpobj, 2, mp_ip6addr_aton, ip6addr_aton);
    

/*
 * espidf extension definition for:
 * int ipaddr_aton(const char *cp, ip_addr_t *addr)
 */

STATIC mp_obj_t mp_ipaddr_aton(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *cp = (const char *)(char*)convert_from_str(mp_args[0]);
    ip_addr_t *addr = mp_write_ptr_ip_addr_t(mp_args[1]);
    int _res = ((int (*)(const char *, ip_addr_t *))lv_func_ptr)(cp, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ipaddr_aton_mpobj, 2, mp_ipaddr_aton, ipaddr_aton);
    

/*
 * espidf extension definition for:
 * int err_to_errno(err_t err)
 */

STATIC mp_obj_t mp_err_to_errno(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    err_t err = (int8_t)mp_obj_get_int(mp_args[0]);
    int _res = ((int (*)(err_t))lv_func_ptr)(err);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_err_to_errno_mpobj, 1, mp_err_to_errno, err_to_errno);
    

/*
 * espidf extension definition for:
 * err_t dhcps_start(struct netif *netif, ip4_addr_t ip)
 */

STATIC mp_obj_t mp_dhcps_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct netif *netif = mp_to_ptr(mp_args[0]);
    ip4_addr_t ip = mp_write_ip4_addr_t(mp_args[1]);
    err_t _res = ((err_t (*)(struct netif *, ip4_addr_t))lv_func_ptr)(netif, ip);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_start_mpobj, 2, mp_dhcps_start, dhcps_start);
    

/*
 * espidf extension definition for:
 * void dhcps_stop(struct netif *netif)
 */

STATIC mp_obj_t mp_dhcps_stop(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct netif *netif = mp_to_ptr(mp_args[0]);
    ((void (*)(struct netif *))lv_func_ptr)(netif);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_stop_mpobj, 1, mp_dhcps_stop, dhcps_stop);
    

/*
 * espidf extension definition for:
 * void *dhcps_option_info(u8_t op_id, u32_t opt_len)
 */

STATIC mp_obj_t mp_dhcps_option_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u8_t op_id = (uint8_t)mp_obj_get_int(mp_args[0]);
    u32_t opt_len = (uint32_t)mp_obj_get_int(mp_args[1]);
    void * _res = ((void *(*)(u8_t, u32_t))lv_func_ptr)(op_id, opt_len);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_option_info_mpobj, 2, mp_dhcps_option_info, dhcps_option_info);
    

/*
 * espidf extension definition for:
 * void dhcps_set_option_info(u8_t op_id, void *opt_info, u32_t opt_len)
 */

STATIC mp_obj_t mp_dhcps_set_option_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u8_t op_id = (uint8_t)mp_obj_get_int(mp_args[0]);
    void *opt_info = mp_to_ptr(mp_args[1]);
    u32_t opt_len = (uint32_t)mp_obj_get_int(mp_args[2]);
    ((void (*)(u8_t, void *, u32_t))lv_func_ptr)(op_id, opt_info, opt_len);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_set_option_info_mpobj, 3, mp_dhcps_set_option_info, dhcps_set_option_info);
    

/*
 * espidf extension definition for:
 * bool dhcp_search_ip_on_mac(u8_t *mac, ip4_addr_t *ip)
 */

STATIC mp_obj_t mp_dhcp_search_ip_on_mac(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    u8_t *mac = mp_array_to_u8ptr(mp_args[0]);
    ip4_addr_t *ip = mp_write_ptr_ip4_addr_t(mp_args[1]);
    bool _res = ((bool (*)(u8_t *, ip4_addr_t *))lv_func_ptr)(mac, ip);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcp_search_ip_on_mac_mpobj, 2, mp_dhcp_search_ip_on_mac, dhcp_search_ip_on_mac);
    

/*
 * espidf extension definition for:
 * void dhcps_dns_setserver(const ip_addr_t *dnsserver)
 */

STATIC mp_obj_t mp_dhcps_dns_setserver(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const ip_addr_t *dnsserver = (const ip_addr_t *)mp_write_ptr_ip_addr_t(mp_args[0]);
    ((void (*)(const ip_addr_t *))lv_func_ptr)(dnsserver);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_dns_setserver_mpobj, 1, mp_dhcps_dns_setserver, dhcps_dns_setserver);
    

/*
 * espidf extension definition for:
 * ip4_addr_t dhcps_dns_getserver(void)
 */

STATIC mp_obj_t mp_dhcps_dns_getserver(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    ip4_addr_t _res = ((ip4_addr_t (*)(void))lv_func_ptr)();
    return mp_read_ip4_addr_t(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_dns_getserver_mpobj, 0, mp_dhcps_dns_getserver, dhcps_dns_getserver);
    

/*
 * Function NOT generated:
 * Callback argument 'dhcps_cb_t cb' cannot be the first argument! We assume the first argument contains the user_data
 * dhcps_cb_t cb
 */
    

/*
 * espidf extension definition for:
 * void dhcps_set_new_lease_cb(dhcps_cb_t cb)
 */

STATIC mp_obj_t mp_dhcps_set_new_lease_cb(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    dhcps_cb_t cb = mp_to_ptr(mp_args[0]);
    ((void (*)(dhcps_cb_t))lv_func_ptr)(cb);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_dhcps_set_new_lease_cb_mpobj, 1, mp_dhcps_set_new_lease_cb, dhcps_set_new_lease_cb);
    

/*
 * Struct esp_netif_sta_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_sta_info_t_type();

STATIC inline void* mp_write_ptr_esp_netif_sta_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_sta_info_t_type()));
    return (esp_netif_sta_info_t*)self->data;
}

#define mp_write_esp_netif_sta_info_t(struct_obj) *((esp_netif_sta_info_t*)mp_write_ptr_esp_netif_sta_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_sta_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_sta_info_t_type(), field);
}

#define mp_read_esp_netif_sta_info_t(field) mp_read_ptr_esp_netif_sta_info_t(copy_buffer(&field, sizeof(esp_netif_sta_info_t)))
#define mp_read_byref_esp_netif_sta_info_t(field) mp_read_ptr_esp_netif_sta_info_t(&field)

STATIC void mp_esp_netif_sta_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_sta_info_t *data = (esp_netif_sta_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_mac: dest[0] = mp_arr_from_uint8_t___6__(data->mac); break; // converting from uint8_t [6];
            case MP_QSTR_ip: dest[0] = mp_read_byref_esp_ip4_addr_t(data->ip); break; // converting from esp_ip4_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_mac: memcpy((void*)&data->mac, mp_arr_to_uint8_t___6__(dest[1]), sizeof(uint8_t)*6); break; // converting to uint8_t [6];
                case MP_QSTR_ip: data->ip = mp_write_esp_ip4_addr_t(dest[1]); break; // converting to esp_ip4_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_sta_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_sta_info_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_sta_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_sta_info_t_type,
    MP_QSTR_esp_netif_sta_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_sta_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_sta_info_t_attr,
    locals_dict, &mp_esp_netif_sta_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_sta_info_t_type()
{
    return &mp_esp_netif_sta_info_t_type;
}
    

/*
 * Array convertors for esp_netif_sta_info_t [15]
 */

GENMPY_UNUSED STATIC esp_netif_sta_info_t *mp_arr_to_esp_netif_sta_info_t___15__(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    //TODO check dim!
    esp_netif_sta_info_t *lv_arr = (esp_netif_sta_info_t*)m_malloc(len * sizeof(esp_netif_sta_info_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = mp_write_esp_netif_sta_info_t(item);
    }
    return (esp_netif_sta_info_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_esp_netif_sta_info_t___15__(esp_netif_sta_info_t *arr)
{
    mp_obj_t obj_arr[15];
    for (size_t i=0; i<15; i++){
        obj_arr[i] = mp_read_esp_netif_sta_info_t(arr[i]);
    }
    return mp_obj_new_list(15, obj_arr); // TODO: return custom iterable object!
}


/*
 * Struct esp_netif_sta_list_t
 */

STATIC inline const mp_obj_type_t *get_mp_esp_netif_sta_list_t_type();

STATIC inline void* mp_write_ptr_esp_netif_sta_list_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_esp_netif_sta_list_t_type()));
    return (esp_netif_sta_list_t*)self->data;
}

#define mp_write_esp_netif_sta_list_t(struct_obj) *((esp_netif_sta_list_t*)mp_write_ptr_esp_netif_sta_list_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_esp_netif_sta_list_t(void *field)
{
    return lv_to_mp_struct(get_mp_esp_netif_sta_list_t_type(), field);
}

#define mp_read_esp_netif_sta_list_t(field) mp_read_ptr_esp_netif_sta_list_t(copy_buffer(&field, sizeof(esp_netif_sta_list_t)))
#define mp_read_byref_esp_netif_sta_list_t(field) mp_read_ptr_esp_netif_sta_list_t(&field)

STATIC void mp_esp_netif_sta_list_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED esp_netif_sta_list_t *data = (esp_netif_sta_list_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_sta: dest[0] = mp_arr_from_esp_netif_sta_info_t___15__(data->sta); break; // converting from esp_netif_sta_info_t [15];
            case MP_QSTR_num: dest[0] = mp_obj_new_int(data->num); break; // converting from int;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_sta: memcpy((void*)&data->sta, mp_arr_to_esp_netif_sta_info_t___15__(dest[1]), sizeof(esp_netif_sta_info_t)*15); break; // converting to esp_netif_sta_info_t [15];
                case MP_QSTR_num: data->num = (int)mp_obj_get_int(dest[1]); break; // converting to int;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_esp_netif_sta_list_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct esp_netif_sta_list_t");
}

STATIC const mp_obj_dict_t mp_esp_netif_sta_list_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_esp_netif_sta_list_t_type,
    MP_QSTR_esp_netif_sta_list_t,
    MP_TYPE_FLAG_NONE,
    print, mp_esp_netif_sta_list_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_esp_netif_sta_list_t_attr,
    locals_dict, &mp_esp_netif_sta_list_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_esp_netif_sta_list_t_type()
{
    return &mp_esp_netif_sta_list_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_get_sta_list(const wifi_sta_list_t *wifi_sta_list, esp_netif_sta_list_t *netif_sta_list)
 */

STATIC mp_obj_t mp_esp_netif_get_sta_list(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const wifi_sta_list_t *wifi_sta_list = (const wifi_sta_list_t *)mp_write_ptr_wifi_sta_list_t(mp_args[0]);
    esp_netif_sta_list_t *netif_sta_list = mp_write_ptr_esp_netif_sta_list_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const wifi_sta_list_t *, esp_netif_sta_list_t *))lv_func_ptr)(wifi_sta_list, netif_sta_list);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_get_sta_list_mpobj, 2, mp_esp_netif_get_sta_list, esp_netif_get_sta_list);
    

STATIC const mp_rom_map_elem_t mp_esp_netif_sta_list_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_sta_list_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_sta_list_t_locals_dict, mp_esp_netif_sta_list_t_locals_dict_table);
        

STATIC const mp_rom_map_elem_t mp_esp_netif_sta_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(esp_netif_sta_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_esp_netif_sta_info_t_locals_dict, mp_esp_netif_sta_info_t_locals_dict_table);
        
/* Reusing funcptr_shutdown_handler_t for tcpip_adapter_init */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_init_mpobj, 0, mp_funcptr_shutdown_handler_t, tcpip_adapter_init);
    

/*
 * espidf extension definition for:
 * tcpip_adapter_if_t tcpip_adapter_if_from_esp_netif(esp_netif_t *esp_netif)
 */

STATIC mp_obj_t mp_tcpip_adapter_if_from_esp_netif(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_t *esp_netif = mp_write_ptr_esp_netif_t(mp_args[0]);
    tcpip_adapter_if_t _res = ((tcpip_adapter_if_t (*)(esp_netif_t *))lv_func_ptr)(esp_netif);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_if_from_esp_netif_mpobj, 1, mp_tcpip_adapter_if_from_esp_netif, tcpip_adapter_if_from_esp_netif);
    

/*
 * Struct tcpip_adapter_ip_info_t
 */

STATIC inline const mp_obj_type_t *get_mp_tcpip_adapter_ip_info_t_type();

STATIC inline void* mp_write_ptr_tcpip_adapter_ip_info_t(mp_obj_t self_in)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(cast(self_in, get_mp_tcpip_adapter_ip_info_t_type()));
    return (tcpip_adapter_ip_info_t*)self->data;
}

#define mp_write_tcpip_adapter_ip_info_t(struct_obj) *((tcpip_adapter_ip_info_t*)mp_write_ptr_tcpip_adapter_ip_info_t(struct_obj))

STATIC inline mp_obj_t mp_read_ptr_tcpip_adapter_ip_info_t(void *field)
{
    return lv_to_mp_struct(get_mp_tcpip_adapter_ip_info_t_type(), field);
}

#define mp_read_tcpip_adapter_ip_info_t(field) mp_read_ptr_tcpip_adapter_ip_info_t(copy_buffer(&field, sizeof(tcpip_adapter_ip_info_t)))
#define mp_read_byref_tcpip_adapter_ip_info_t(field) mp_read_ptr_tcpip_adapter_ip_info_t(&field)

STATIC void mp_tcpip_adapter_ip_info_t_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest)
{
    mp_lv_struct_t *self = MP_OBJ_TO_PTR(self_in);
    GENMPY_UNUSED tcpip_adapter_ip_info_t *data = (tcpip_adapter_ip_info_t*)self->data;

    if (dest[0] == MP_OBJ_NULL) {
        // load attribute
        switch(attr)
        {
            case MP_QSTR_ip: dest[0] = mp_read_byref_ip4_addr_t(data->ip); break; // converting from ip4_addr_t;
            case MP_QSTR_netmask: dest[0] = mp_read_byref_ip4_addr_t(data->netmask); break; // converting from ip4_addr_t;
            case MP_QSTR_gw: dest[0] = mp_read_byref_ip4_addr_t(data->gw); break; // converting from ip4_addr_t;
            default: call_parent_methods(self_in, attr, dest); // fallback to locals_dict lookup
        }
    } else {
        if (dest[1])
        {
            // store attribute
            switch(attr)
            {
                case MP_QSTR_ip: data->ip = mp_write_ip4_addr_t(dest[1]); break; // converting to ip4_addr_t;
                case MP_QSTR_netmask: data->netmask = mp_write_ip4_addr_t(dest[1]); break; // converting to ip4_addr_t;
                case MP_QSTR_gw: data->gw = mp_write_ip4_addr_t(dest[1]); break; // converting to ip4_addr_t;
                default: return;
            }

            dest[0] = MP_OBJ_NULL; // indicate success
        }
    }
}

STATIC void mp_tcpip_adapter_ip_info_t_print(const mp_print_t *print,
    mp_obj_t self_in,
    mp_print_kind_t kind)
{
    mp_printf(print, "struct tcpip_adapter_ip_info_t");
}

STATIC const mp_obj_dict_t mp_tcpip_adapter_ip_info_t_locals_dict;

STATIC MP_DEFINE_CONST_OBJ_TYPE(
    mp_tcpip_adapter_ip_info_t_type,
    MP_QSTR_tcpip_adapter_ip_info_t,
    MP_TYPE_FLAG_NONE,
    print, mp_tcpip_adapter_ip_info_t_print,
    make_new, make_new_lv_struct,
    binary_op, lv_struct_binary_op,
    subscr, lv_struct_subscr,
    attr, mp_tcpip_adapter_ip_info_t_attr,
    locals_dict, &mp_tcpip_adapter_ip_info_t_locals_dict,
    buffer, mp_blob_get_buffer,
    parent, &mp_lv_base_struct_type
);

STATIC inline const mp_obj_type_t *get_mp_tcpip_adapter_ip_info_t_type()
{
    return &mp_tcpip_adapter_ip_info_t_type;
}
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_ip_info(tcpip_adapter_if_t tcpip_if, tcpip_adapter_ip_info_t *ip_info)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_ip_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    tcpip_adapter_ip_info_t *ip_info = mp_write_ptr_tcpip_adapter_ip_info_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, tcpip_adapter_ip_info_t *))lv_func_ptr)(tcpip_if, ip_info);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_ip_info_mpobj, 2, mp_tcpip_adapter_get_ip_info, tcpip_adapter_get_ip_info);
    

STATIC const mp_rom_map_elem_t mp_tcpip_adapter_ip_info_t_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR___SIZE__), MP_ROM_PTR(MP_ROM_INT(sizeof(tcpip_adapter_ip_info_t))) },
    
};

STATIC MP_DEFINE_CONST_DICT(mp_tcpip_adapter_ip_info_t_locals_dict, mp_tcpip_adapter_ip_info_t_locals_dict_table);
        

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_ip6_linklocal(tcpip_adapter_if_t tcpip_if, ip6_addr_t *if_ip6)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_ip6_linklocal(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    ip6_addr_t *if_ip6 = mp_write_ptr_ip6_addr_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, ip6_addr_t *))lv_func_ptr)(tcpip_if, if_ip6);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_ip6_linklocal_mpobj, 2, mp_tcpip_adapter_get_ip6_linklocal, tcpip_adapter_get_ip6_linklocal);
    
/* Reusing tcpip_adapter_get_ip6_linklocal for tcpip_adapter_get_ip6_global */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_ip6_global_mpobj, 2, mp_tcpip_adapter_get_ip6_linklocal, tcpip_adapter_get_ip6_global);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_dhcpc_get_status(tcpip_adapter_if_t tcpip_if, tcpip_adapter_dhcp_status_t *status)
 */

STATIC mp_obj_t mp_tcpip_adapter_dhcpc_get_status(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    tcpip_adapter_dhcp_status_t *status = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, tcpip_adapter_dhcp_status_t *))lv_func_ptr)(tcpip_if, status);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcpc_get_status_mpobj, 2, mp_tcpip_adapter_dhcpc_get_status, tcpip_adapter_dhcpc_get_status);
    

/*
 * espidf extension definition for:
 * bool tcpip_adapter_is_netif_up(tcpip_adapter_if_t tcpip_if)
 */

STATIC mp_obj_t mp_tcpip_adapter_is_netif_up(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    bool _res = ((bool (*)(tcpip_adapter_if_t))lv_func_ptr)(tcpip_if);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_is_netif_up_mpobj, 1, mp_tcpip_adapter_is_netif_up, tcpip_adapter_is_netif_up);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_netif(tcpip_adapter_if_t tcpip_if, void **netif)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_netif(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    void **netif = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, void **))lv_func_ptr)(tcpip_if, netif);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_netif_mpobj, 2, mp_tcpip_adapter_get_netif, tcpip_adapter_get_netif);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_create_ip6_linklocal(tcpip_adapter_if_t tcpip_if)
 */

STATIC mp_obj_t mp_tcpip_adapter_create_ip6_linklocal(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t))lv_func_ptr)(tcpip_if);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_create_ip6_linklocal_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_create_ip6_linklocal);
    
/* Reusing adc_digi_start for tcpip_adapter_set_default_eth_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_default_eth_handlers_mpobj, 0, mp_adc_digi_start, tcpip_adapter_set_default_eth_handlers);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_eth_input(void *buffer, uint16_t len, void *eb)
 */

STATIC mp_obj_t mp_tcpip_adapter_eth_input(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *buffer = mp_to_ptr(mp_args[0]);
    uint16_t len = (uint16_t)mp_obj_get_int(mp_args[1]);
    void *eb = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(void *, uint16_t, void *))lv_func_ptr)(buffer, len, eb);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_eth_input_mpobj, 3, mp_tcpip_adapter_eth_input, tcpip_adapter_eth_input);
    
/* Reusing tcpip_adapter_eth_input for tcpip_adapter_sta_input */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_sta_input_mpobj, 3, mp_tcpip_adapter_eth_input, tcpip_adapter_sta_input);
    
/* Reusing tcpip_adapter_eth_input for tcpip_adapter_ap_input */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_ap_input_mpobj, 3, mp_tcpip_adapter_eth_input, tcpip_adapter_ap_input);
    
/* Reusing adc_digi_start for tcpip_adapter_clear_default_wifi_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_clear_default_wifi_handlers_mpobj, 0, mp_adc_digi_start, tcpip_adapter_clear_default_wifi_handlers);
    
/* Reusing adc_digi_start for tcpip_adapter_clear_default_eth_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_clear_default_eth_handlers_mpobj, 0, mp_adc_digi_start, tcpip_adapter_clear_default_eth_handlers);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_dhcps_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcps_stop_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_dhcps_stop);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_dhcpc_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcpc_stop_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_dhcpc_stop);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_dhcps_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcps_start_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_dhcps_start);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_dhcpc_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcpc_start_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_dhcpc_start);
    
/* Reusing tcpip_adapter_dhcpc_get_status for tcpip_adapter_dhcps_get_status */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcps_get_status_mpobj, 2, mp_tcpip_adapter_dhcpc_get_status, tcpip_adapter_dhcps_get_status);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_dhcps_option(tcpip_adapter_dhcp_option_mode_t opt_op, tcpip_adapter_dhcp_option_id_t opt_id, void *opt_val, uint32_t opt_len)
 */

STATIC mp_obj_t mp_tcpip_adapter_dhcps_option(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_dhcp_option_mode_t opt_op = (int)mp_obj_get_int(mp_args[0]);
    tcpip_adapter_dhcp_option_id_t opt_id = (int)mp_obj_get_int(mp_args[1]);
    void *opt_val = mp_to_ptr(mp_args[2]);
    uint32_t opt_len = (uint32_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_dhcp_option_mode_t, tcpip_adapter_dhcp_option_id_t, void *, uint32_t))lv_func_ptr)(opt_op, opt_id, opt_val, opt_len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcps_option_mpobj, 4, mp_tcpip_adapter_dhcps_option, tcpip_adapter_dhcps_option);
    
/* Reusing tcpip_adapter_dhcps_option for tcpip_adapter_dhcpc_option */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_dhcpc_option_mpobj, 4, mp_tcpip_adapter_dhcps_option, tcpip_adapter_dhcpc_option);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_set_ip_info(tcpip_adapter_if_t tcpip_if, const tcpip_adapter_ip_info_t *ip_info)
 */

STATIC mp_obj_t mp_tcpip_adapter_set_ip_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    const tcpip_adapter_ip_info_t *ip_info = (const tcpip_adapter_ip_info_t *)mp_write_ptr_tcpip_adapter_ip_info_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, const tcpip_adapter_ip_info_t *))lv_func_ptr)(tcpip_if, ip_info);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_ip_info_mpobj, 2, mp_tcpip_adapter_set_ip_info, tcpip_adapter_set_ip_info);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_dns_info(tcpip_adapter_if_t tcpip_if, tcpip_adapter_dns_type_t type, tcpip_adapter_dns_info_t *dns)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_dns_info(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    tcpip_adapter_dns_type_t type = (int)mp_obj_get_int(mp_args[1]);
    tcpip_adapter_dns_info_t *dns = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, tcpip_adapter_dns_type_t, tcpip_adapter_dns_info_t *))lv_func_ptr)(tcpip_if, type, dns);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_dns_info_mpobj, 3, mp_tcpip_adapter_get_dns_info, tcpip_adapter_get_dns_info);
    
/* Reusing tcpip_adapter_get_dns_info for tcpip_adapter_set_dns_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_dns_info_mpobj, 3, mp_tcpip_adapter_get_dns_info, tcpip_adapter_set_dns_info);
    

/*
 * espidf extension definition for:
 * int tcpip_adapter_get_netif_index(tcpip_adapter_if_t tcpip_if)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_netif_index(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    int _res = ((int (*)(tcpip_adapter_if_t))lv_func_ptr)(tcpip_if);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_netif_index_mpobj, 1, mp_tcpip_adapter_get_netif_index, tcpip_adapter_get_netif_index);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_sta_list(const wifi_sta_list_t *wifi_sta_list, tcpip_adapter_sta_list_t *tcpip_sta_list)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_sta_list(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const wifi_sta_list_t *wifi_sta_list = (const wifi_sta_list_t *)mp_write_ptr_wifi_sta_list_t(mp_args[0]);
    tcpip_adapter_sta_list_t *tcpip_sta_list = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const wifi_sta_list_t *, tcpip_adapter_sta_list_t *))lv_func_ptr)(wifi_sta_list, tcpip_sta_list);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_sta_list_mpobj, 2, mp_tcpip_adapter_get_sta_list, tcpip_adapter_get_sta_list);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_eth_start(uint8_t *mac, tcpip_adapter_ip_info_t *ip_info, void *args)
 */

STATIC mp_obj_t mp_tcpip_adapter_eth_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *mac = mp_array_to_u8ptr(mp_args[0]);
    tcpip_adapter_ip_info_t *ip_info = mp_write_ptr_tcpip_adapter_ip_info_t(mp_args[1]);
    void *args = mp_to_ptr(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *, tcpip_adapter_ip_info_t *, void *))lv_func_ptr)(mac, ip_info, args);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_eth_start_mpobj, 3, mp_tcpip_adapter_eth_start, tcpip_adapter_eth_start);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_sta_start(uint8_t *mac, tcpip_adapter_ip_info_t *ip_info)
 */

STATIC mp_obj_t mp_tcpip_adapter_sta_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    uint8_t *mac = mp_array_to_u8ptr(mp_args[0]);
    tcpip_adapter_ip_info_t *ip_info = mp_write_ptr_tcpip_adapter_ip_info_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(uint8_t *, tcpip_adapter_ip_info_t *))lv_func_ptr)(mac, ip_info);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_sta_start_mpobj, 2, mp_tcpip_adapter_sta_start, tcpip_adapter_sta_start);
    
/* Reusing tcpip_adapter_sta_start for tcpip_adapter_ap_start */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_ap_start_mpobj, 2, mp_tcpip_adapter_sta_start, tcpip_adapter_ap_start);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_stop_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_stop);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_up */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_up_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_up);
    
/* Reusing tcpip_adapter_create_ip6_linklocal for tcpip_adapter_down */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_down_mpobj, 1, mp_tcpip_adapter_create_ip6_linklocal, tcpip_adapter_down);
    
/* Reusing tcpip_adapter_get_ip_info for tcpip_adapter_get_old_ip_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_old_ip_info_mpobj, 2, mp_tcpip_adapter_get_ip_info, tcpip_adapter_get_old_ip_info);
    
/* Reusing tcpip_adapter_set_ip_info for tcpip_adapter_set_old_ip_info */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_old_ip_info_mpobj, 2, mp_tcpip_adapter_set_ip_info, tcpip_adapter_set_old_ip_info);
    

/*
 * espidf extension definition for:
 * esp_interface_t tcpip_adapter_get_esp_if(void *dev)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_esp_if(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *dev = mp_to_ptr(mp_args[0]);
    esp_interface_t _res = ((esp_interface_t (*)(void *))lv_func_ptr)(dev);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_esp_if_mpobj, 1, mp_tcpip_adapter_get_esp_if, tcpip_adapter_get_esp_if);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_set_hostname(tcpip_adapter_if_t tcpip_if, const char *hostname)
 */

STATIC mp_obj_t mp_tcpip_adapter_set_hostname(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, const char *))lv_func_ptr)(tcpip_if, hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_hostname_mpobj, 2, mp_tcpip_adapter_set_hostname, tcpip_adapter_set_hostname);
    

/*
 * espidf extension definition for:
 * esp_err_t tcpip_adapter_get_hostname(tcpip_adapter_if_t tcpip_if, const char **hostname)
 */

STATIC mp_obj_t mp_tcpip_adapter_get_hostname(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    tcpip_adapter_if_t tcpip_if = (int)mp_obj_get_int(mp_args[0]);
    const char **hostname = (const char **)mp_write_ptr_C_Pointer(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(tcpip_adapter_if_t, const char **))lv_func_ptr)(tcpip_if, hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_get_hostname_mpobj, 2, mp_tcpip_adapter_get_hostname, tcpip_adapter_get_hostname);
    
/* Reusing adc_digi_start for tcpip_adapter_set_default_wifi_handlers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_tcpip_adapter_set_default_wifi_handlers_mpobj, 0, mp_adc_digi_start, tcpip_adapter_set_default_wifi_handlers);
    
/* Reusing adc_digi_start for esp_netif_init */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_init_mpobj, 0, mp_adc_digi_start, esp_netif_init);
    
/* Reusing adc_digi_start for esp_netif_deinit */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_deinit_mpobj, 0, mp_adc_digi_start, esp_netif_deinit);
    

/*
 * espidf extension definition for:
 * void esp_netif_action_start(void *esp_netif, esp_event_base_t base, int32_t event_id, void *data)
 */

STATIC mp_obj_t mp_esp_netif_action_start(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *esp_netif = mp_to_ptr(mp_args[0]);
    esp_event_base_t base = (char*)convert_from_str(mp_args[1]);
    int32_t event_id = (int32_t)mp_obj_get_int(mp_args[2]);
    void *data = mp_to_ptr(mp_args[3]);
    ((void (*)(void *, esp_event_base_t, int32_t, void *))lv_func_ptr)(esp_netif, base, event_id, data);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_start_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_start);
    
/* Reusing esp_netif_action_start for esp_netif_action_stop */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_stop_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_stop);
    
/* Reusing esp_netif_action_start for esp_netif_action_connected */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_connected_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_connected);
    
/* Reusing esp_netif_action_start for esp_netif_action_disconnected */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_disconnected_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_disconnected);
    
/* Reusing esp_netif_action_start for esp_netif_action_got_ip */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_got_ip_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_got_ip);
    
/* Reusing esp_netif_action_start for esp_netif_action_join_ip6_multicast_group */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_join_ip6_multicast_group_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_join_ip6_multicast_group);
    
/* Reusing esp_netif_action_start for esp_netif_action_leave_ip6_multicast_group */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_leave_ip6_multicast_group_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_leave_ip6_multicast_group);
    
/* Reusing esp_netif_action_start for esp_netif_action_add_ip6_address */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_add_ip6_address_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_add_ip6_address);
    
/* Reusing esp_netif_action_start for esp_netif_action_remove_ip6_address */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_action_remove_ip6_address_mpobj, 4, mp_esp_netif_action_start, esp_netif_action_remove_ip6_address);
    

/*
 * espidf extension definition for:
 * uint32_t esp_ip4addr_aton(const char *addr)
 */

STATIC mp_obj_t mp_esp_ip4addr_aton(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *addr = (const char *)(char*)convert_from_str(mp_args[0]);
    uint32_t _res = ((uint32_t (*)(const char *))lv_func_ptr)(addr);
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_ip4addr_aton_mpobj, 1, mp_esp_ip4addr_aton, esp_ip4addr_aton);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_str_to_ip4(const char *src, esp_ip4_addr_t *dst)
 */

STATIC mp_obj_t mp_esp_netif_str_to_ip4(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *src = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_ip4_addr_t *dst = mp_write_ptr_esp_ip4_addr_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const char *, esp_ip4_addr_t *))lv_func_ptr)(src, dst);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_str_to_ip4_mpobj, 2, mp_esp_netif_str_to_ip4, esp_netif_str_to_ip4);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_str_to_ip6(const char *src, esp_ip6_addr_t *dst)
 */

STATIC mp_obj_t mp_esp_netif_str_to_ip6(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *src = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_ip6_addr_t *dst = mp_write_ptr_esp_ip6_addr_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const char *, esp_ip6_addr_t *))lv_func_ptr)(src, dst);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_str_to_ip6_mpobj, 2, mp_esp_netif_str_to_ip6, esp_netif_str_to_ip6);
    

/*
 * espidf extension definition for:
 * esp_netif_t *esp_netif_get_handle_from_ifkey(const char *if_key)
 */

STATIC mp_obj_t mp_esp_netif_get_handle_from_ifkey(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *if_key = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_netif_t * _res = ((esp_netif_t *(*)(const char *))lv_func_ptr)(if_key);
    return mp_read_ptr_esp_netif_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_get_handle_from_ifkey_mpobj, 1, mp_esp_netif_get_handle_from_ifkey, esp_netif_get_handle_from_ifkey);
    

/*
 * espidf extension definition for:
 * size_t esp_netif_get_nr_of_ifs(void)
 */

STATIC mp_obj_t mp_esp_netif_get_nr_of_ifs(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    size_t _res = ((size_t (*)(void))lv_func_ptr)();
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_get_nr_of_ifs_mpobj, 0, mp_esp_netif_get_nr_of_ifs, esp_netif_get_nr_of_ifs);
    
/* Reusing funcptr_fn for esp_netif_netstack_buf_ref */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_netstack_buf_ref_mpobj, 1, mp_funcptr_fn, esp_netif_netstack_buf_ref);
    
/* Reusing funcptr_fn for esp_netif_netstack_buf_free */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_netstack_buf_free_mpobj, 1, mp_funcptr_fn, esp_netif_netstack_buf_free);
    

/*
 * Function NOT generated:
 * Callback argument 'esp_netif_callback_fn fn' cannot be the first argument! We assume the first argument contains the user_data
 * esp_netif_callback_fn fn
 */
    

/*
 * espidf extension definition for:
 * esp_err_t esp_netif_tcpip_exec(esp_netif_callback_fn fn, void *ctx)
 */

STATIC mp_obj_t mp_esp_netif_tcpip_exec(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_netif_callback_fn fn = mp_to_ptr(mp_args[0]);
    void *ctx = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_netif_callback_fn, void *))lv_func_ptr)(fn, ctx);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_netif_tcpip_exec_mpobj, 2, mp_esp_netif_tcpip_exec, esp_netif_tcpip_exec);
    
/* Reusing adc_digi_start for mdns_init */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_init_mpobj, 0, mp_adc_digi_start, mdns_init);
    
/* Reusing funcptr_shutdown_handler_t for mdns_free */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_free_mpobj, 0, mp_funcptr_shutdown_handler_t, mdns_free);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_hostname_set(const char *hostname)
 */

STATIC mp_obj_t mp_mdns_hostname_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(const char *))lv_func_ptr)(hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_hostname_set_mpobj, 1, mp_mdns_hostname_set, mdns_hostname_set);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_delegate_hostname_add(const char *hostname, const mdns_ip_addr_t *address_list)
 */

STATIC mp_obj_t mp_mdns_delegate_hostname_add(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[0]);
    const mdns_ip_addr_t *address_list = (const mdns_ip_addr_t *)mp_write_ptr_mdns_ip_addr_t(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const mdns_ip_addr_t *))lv_func_ptr)(hostname, address_list);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_delegate_hostname_add_mpobj, 2, mp_mdns_delegate_hostname_add, mdns_delegate_hostname_add);
    
/* Reusing mdns_hostname_set for mdns_delegate_hostname_remove */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_delegate_hostname_remove_mpobj, 1, mp_mdns_hostname_set, mdns_delegate_hostname_remove);
    

/*
 * espidf extension definition for:
 * bool mdns_hostname_exists(const char *hostname)
 */

STATIC mp_obj_t mp_mdns_hostname_exists(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[0]);
    bool _res = ((bool (*)(const char *))lv_func_ptr)(hostname);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_hostname_exists_mpobj, 1, mp_mdns_hostname_exists, mdns_hostname_exists);
    
/* Reusing mdns_hostname_set for mdns_instance_name_set */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_instance_name_set_mpobj, 1, mp_mdns_hostname_set, mdns_instance_name_set);
    

/*
 * Array convertors for mdns_txt_item_t []
 */

GENMPY_UNUSED STATIC mdns_txt_item_t *mp_arr_to_mdns_txt_item_t_____(mp_obj_t mp_arr)
{
    mp_obj_t mp_len = mp_obj_len_maybe(mp_arr);
    if (mp_len == MP_OBJ_NULL) return mp_to_ptr(mp_arr);
    mp_int_t len = mp_obj_get_int(mp_len);
    
    mdns_txt_item_t *lv_arr = (mdns_txt_item_t*)m_malloc(len * sizeof(mdns_txt_item_t));
    mp_obj_t iter = mp_getiter(mp_arr, NULL);
    mp_obj_t item;
    size_t i = 0;
    while ((item = mp_iternext(iter)) != MP_OBJ_STOP_ITERATION) {
        lv_arr[i++] = mp_write_mdns_txt_item_t(item);
    }
    return (mdns_txt_item_t *)lv_arr;
}

GENMPY_UNUSED STATIC mp_obj_t mp_arr_from_mdns_txt_item_t_____(mdns_txt_item_t *arr)
{
    return mp_read_ptr_mdns_txt_item_t((void*)arr);
}


/*
 * espidf extension definition for:
 * esp_err_t mdns_service_add(const char *instance_name, const char *service_type, const char *proto, uint16_t port, mdns_txt_item_t txt[], size_t num_items)
 */

STATIC mp_obj_t mp_mdns_service_add(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *instance_name = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    uint16_t port = (uint16_t)mp_obj_get_int(mp_args[3]);
    mdns_txt_item_t *txt = mp_arr_to_mdns_txt_item_t_____(mp_args[4]);
    size_t num_items = (size_t)mp_obj_get_int(mp_args[5]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, uint16_t, mdns_txt_item_t [], size_t))lv_func_ptr)(instance_name, service_type, proto, port, txt, num_items);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_add_mpobj, 6, mp_mdns_service_add, mdns_service_add);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_add_for_host(const char *instance_name, const char *service_type, const char *proto, const char *hostname, uint16_t port, mdns_txt_item_t txt[], size_t num_items)
 */

STATIC mp_obj_t mp_mdns_service_add_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *instance_name = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[3]);
    uint16_t port = (uint16_t)mp_obj_get_int(mp_args[4]);
    mdns_txt_item_t *txt = mp_arr_to_mdns_txt_item_t_____(mp_args[5]);
    size_t num_items = (size_t)mp_obj_get_int(mp_args[6]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, const char *, uint16_t, mdns_txt_item_t [], size_t))lv_func_ptr)(instance_name, service_type, proto, hostname, port, txt, num_items);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_add_for_host_mpobj, 7, mp_mdns_service_add_for_host, mdns_service_add_for_host);
    

/*
 * espidf extension definition for:
 * bool mdns_service_exists(const char *service_type, const char *proto, const char *hostname)
 */

STATIC mp_obj_t mp_mdns_service_exists(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    bool _res = ((bool (*)(const char *, const char *, const char *))lv_func_ptr)(service_type, proto, hostname);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_exists_mpobj, 3, mp_mdns_service_exists, mdns_service_exists);
    

/*
 * espidf extension definition for:
 * bool mdns_service_exists_with_instance(const char *instance, const char *service_type, const char *proto, const char *hostname)
 */

STATIC mp_obj_t mp_mdns_service_exists_with_instance(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *instance = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[3]);
    bool _res = ((bool (*)(const char *, const char *, const char *, const char *))lv_func_ptr)(instance, service_type, proto, hostname);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_exists_with_instance_mpobj, 4, mp_mdns_service_exists_with_instance, mdns_service_exists_with_instance);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_remove(const char *service_type, const char *proto)
 */

STATIC mp_obj_t mp_mdns_service_remove(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *))lv_func_ptr)(service_type, proto);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_remove_mpobj, 2, mp_mdns_service_remove, mdns_service_remove);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_remove_for_host(const char *service_type, const char *proto, const char *hostname)
 */

STATIC mp_obj_t mp_mdns_service_remove_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *))lv_func_ptr)(service_type, proto, hostname);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_remove_for_host_mpobj, 3, mp_mdns_service_remove_for_host, mdns_service_remove_for_host);
    
/* Reusing mdns_service_remove_for_host for mdns_service_instance_name_set */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_instance_name_set_mpobj, 3, mp_mdns_service_remove_for_host, mdns_service_instance_name_set);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_instance_name_set_for_host(const char *service_type, const char *proto, const char *hostname, const char *instance_name)
 */

STATIC mp_obj_t mp_mdns_service_instance_name_set_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *instance_name = (const char *)(char*)convert_from_str(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, const char *))lv_func_ptr)(service_type, proto, hostname, instance_name);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_instance_name_set_for_host_mpobj, 4, mp_mdns_service_instance_name_set_for_host, mdns_service_instance_name_set_for_host);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_port_set(const char *service_type, const char *proto, uint16_t port)
 */

STATIC mp_obj_t mp_mdns_service_port_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    uint16_t port = (uint16_t)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, uint16_t))lv_func_ptr)(service_type, proto, port);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_port_set_mpobj, 3, mp_mdns_service_port_set, mdns_service_port_set);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_port_set_for_host(const char *service_type, const char *proto, const char *hostname, uint16_t port)
 */

STATIC mp_obj_t mp_mdns_service_port_set_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    uint16_t port = (uint16_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, uint16_t))lv_func_ptr)(service_type, proto, hostname, port);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_port_set_for_host_mpobj, 4, mp_mdns_service_port_set_for_host, mdns_service_port_set_for_host);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_txt_set(const char *service_type, const char *proto, mdns_txt_item_t txt[], uint8_t num_items)
 */

STATIC mp_obj_t mp_mdns_service_txt_set(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    mdns_txt_item_t *txt = mp_arr_to_mdns_txt_item_t_____(mp_args[2]);
    uint8_t num_items = (uint8_t)mp_obj_get_int(mp_args[3]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, mdns_txt_item_t [], uint8_t))lv_func_ptr)(service_type, proto, txt, num_items);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_set_mpobj, 4, mp_mdns_service_txt_set, mdns_service_txt_set);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_txt_set_for_host(const char *service_type, const char *proto, const char *hostname, mdns_txt_item_t txt[], uint8_t num_items)
 */

STATIC mp_obj_t mp_mdns_service_txt_set_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    mdns_txt_item_t *txt = mp_arr_to_mdns_txt_item_t_____(mp_args[3]);
    uint8_t num_items = (uint8_t)mp_obj_get_int(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, mdns_txt_item_t [], uint8_t))lv_func_ptr)(service_type, proto, hostname, txt, num_items);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_set_for_host_mpobj, 5, mp_mdns_service_txt_set_for_host, mdns_service_txt_set_for_host);
    
/* Reusing mdns_service_instance_name_set_for_host for mdns_service_txt_item_set */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_set_mpobj, 4, mp_mdns_service_instance_name_set_for_host, mdns_service_txt_item_set);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_txt_item_set_with_explicit_value_len(const char *service_type, const char *proto, const char *key, const char *value, uint8_t value_len)
 */

STATIC mp_obj_t mp_mdns_service_txt_item_set_with_explicit_value_len(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *key = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *value = (const char *)(char*)convert_from_str(mp_args[3]);
    uint8_t value_len = (uint8_t)mp_obj_get_int(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, const char *, uint8_t))lv_func_ptr)(service_type, proto, key, value, value_len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_set_with_explicit_value_len_mpobj, 5, mp_mdns_service_txt_item_set_with_explicit_value_len, mdns_service_txt_item_set_with_explicit_value_len);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_txt_item_set_for_host(const char *service_type, const char *proto, const char *hostname, const char *key, const char *value)
 */

STATIC mp_obj_t mp_mdns_service_txt_item_set_for_host(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *key = (const char *)(char*)convert_from_str(mp_args[3]);
    const char *value = (const char *)(char*)convert_from_str(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, const char *, const char *))lv_func_ptr)(service_type, proto, hostname, key, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_set_for_host_mpobj, 5, mp_mdns_service_txt_item_set_for_host, mdns_service_txt_item_set_for_host);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_service_txt_item_set_for_host_with_explicit_value_len(const char *service_type, const char *proto, const char *hostname, const char *key, const char *value, uint8_t value_len)
 */

STATIC mp_obj_t mp_mdns_service_txt_item_set_for_host_with_explicit_value_len(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *hostname = (const char *)(char*)convert_from_str(mp_args[2]);
    const char *key = (const char *)(char*)convert_from_str(mp_args[3]);
    const char *value = (const char *)(char*)convert_from_str(mp_args[4]);
    uint8_t value_len = (uint8_t)mp_obj_get_int(mp_args[5]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, const char *, const char *, uint8_t))lv_func_ptr)(service_type, proto, hostname, key, value, value_len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_set_for_host_with_explicit_value_len_mpobj, 6, mp_mdns_service_txt_item_set_for_host_with_explicit_value_len, mdns_service_txt_item_set_for_host_with_explicit_value_len);
    
/* Reusing mdns_service_remove_for_host for mdns_service_txt_item_remove */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_remove_mpobj, 3, mp_mdns_service_remove_for_host, mdns_service_txt_item_remove);
    
/* Reusing mdns_service_instance_name_set_for_host for mdns_service_txt_item_remove_for_host */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_txt_item_remove_for_host_mpobj, 4, mp_mdns_service_instance_name_set_for_host, mdns_service_txt_item_remove_for_host);
    
/* Reusing adc_digi_start for mdns_service_remove_all */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_service_remove_all_mpobj, 0, mp_adc_digi_start, mdns_service_remove_all);
    

/*
 * Function NOT generated:
 * Callback function 'mdns_query_notify_t notifier' must receive a struct pointer with user_data member as its first argument!
 * mdns_query_notify_t notifier
 */
    
#define funcptr_mdns_query_notify_t NULL


/*
 * espidf extension definition for:
 * void mdns_query_notify_t(mdns_search_once_t *search)
 */

STATIC mp_obj_t mp_funcptr_mdns_query_notify_t(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    mdns_search_once_t *search = mp_write_ptr_mdns_search_once_t(mp_args[0]);
    ((void (*)(mdns_search_once_t *))lv_func_ptr)(search);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_funcptr_mdns_query_notify_t_mpobj, 1, mp_funcptr_mdns_query_notify_t, funcptr_mdns_query_notify_t);
    
STATIC inline mp_obj_t mp_lv_funcptr_mdns_query_notify_t(void *func){ return mp_lv_funcptr(&mp_funcptr_mdns_query_notify_t_mpobj, func, NULL, MP_QSTR_, NULL); }


/*
 * espidf extension definition for:
 * mdns_search_once_t *mdns_query_async_new(const char *name, const char *service_type, const char *proto, uint16_t type, uint32_t timeout, size_t max_results, mdns_query_notify_t notifier)
 */

STATIC mp_obj_t mp_mdns_query_async_new(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *name = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    uint16_t type = (uint16_t)mp_obj_get_int(mp_args[3]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[4]);
    size_t max_results = (size_t)mp_obj_get_int(mp_args[5]);
    mdns_query_notify_t notifier = mp_to_ptr(mp_args[6]);
    mdns_search_once_t * _res = ((mdns_search_once_t *(*)(const char *, const char *, const char *, uint16_t, uint32_t, size_t, mdns_query_notify_t))lv_func_ptr)(name, service_type, proto, type, timeout, max_results, notifier);
    return mp_read_ptr_mdns_search_once_t((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_async_new_mpobj, 7, mp_mdns_query_async_new, mdns_query_async_new);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_query(const char *name, const char *service_type, const char *proto, uint16_t type, uint32_t timeout, size_t max_results, mdns_result_t **results)
 */

STATIC mp_obj_t mp_mdns_query(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *name = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    uint16_t type = (uint16_t)mp_obj_get_int(mp_args[3]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[4]);
    size_t max_results = (size_t)mp_obj_get_int(mp_args[5]);
    mdns_result_t **results = mp_to_ptr(mp_args[6]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, uint16_t, uint32_t, size_t, mdns_result_t **))lv_func_ptr)(name, service_type, proto, type, timeout, max_results, results);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_mpobj, 7, mp_mdns_query, mdns_query);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_query_ptr(const char *service_type, const char *proto, uint32_t timeout, size_t max_results, mdns_result_t **results)
 */

STATIC mp_obj_t mp_mdns_query_ptr(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[1]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[2]);
    size_t max_results = (size_t)mp_obj_get_int(mp_args[3]);
    mdns_result_t **results = mp_to_ptr(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, uint32_t, size_t, mdns_result_t **))lv_func_ptr)(service_type, proto, timeout, max_results, results);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_ptr_mpobj, 5, mp_mdns_query_ptr, mdns_query_ptr);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_query_srv(const char *instance_name, const char *service_type, const char *proto, uint32_t timeout, mdns_result_t **result)
 */

STATIC mp_obj_t mp_mdns_query_srv(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *instance_name = (const char *)(char*)convert_from_str(mp_args[0]);
    const char *service_type = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *proto = (const char *)(char*)convert_from_str(mp_args[2]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[3]);
    mdns_result_t **result = mp_to_ptr(mp_args[4]);
    esp_err_t _res = ((esp_err_t (*)(const char *, const char *, const char *, uint32_t, mdns_result_t **))lv_func_ptr)(instance_name, service_type, proto, timeout, result);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_srv_mpobj, 5, mp_mdns_query_srv, mdns_query_srv);
    
/* Reusing mdns_query_srv for mdns_query_txt */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_txt_mpobj, 5, mp_mdns_query_srv, mdns_query_txt);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_query_a(const char *host_name, uint32_t timeout, esp_ip4_addr_t *addr)
 */

STATIC mp_obj_t mp_mdns_query_a(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *host_name = (const char *)(char*)convert_from_str(mp_args[0]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_ip4_addr_t *addr = mp_write_ptr_esp_ip4_addr_t(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(const char *, uint32_t, esp_ip4_addr_t *))lv_func_ptr)(host_name, timeout, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_a_mpobj, 3, mp_mdns_query_a, mdns_query_a);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_query_aaaa(const char *host_name, uint32_t timeout, esp_ip6_addr_t *addr)
 */

STATIC mp_obj_t mp_mdns_query_aaaa(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *host_name = (const char *)(char*)convert_from_str(mp_args[0]);
    uint32_t timeout = (uint32_t)mp_obj_get_int(mp_args[1]);
    esp_ip6_addr_t *addr = mp_write_ptr_esp_ip6_addr_t(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(const char *, uint32_t, esp_ip6_addr_t *))lv_func_ptr)(host_name, timeout, addr);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_query_aaaa_mpobj, 3, mp_mdns_query_aaaa, mdns_query_aaaa);
    

/*
 * espidf extension definition for:
 * esp_err_t mdns_handle_system_event(void *ctx, system_event_t *event)
 */

STATIC mp_obj_t mp_mdns_handle_system_event(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *ctx = mp_to_ptr(mp_args[0]);
    system_event_t *event = mp_to_ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(void *, system_event_t *))lv_func_ptr)(ctx, event);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_mdns_handle_system_event_mpobj, 2, mp_mdns_handle_system_event, mdns_handle_system_event);
    

/*
 * espidf extension definition for:
 * unsigned long http_parser_version(void)
 */

STATIC mp_obj_t mp_http_parser_version(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    
    unsigned long _res = ((unsigned long (*)(void))lv_func_ptr)();
    return mp_obj_new_int_from_uint(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_http_parser_version_mpobj, 0, mp_http_parser_version, http_parser_version);
    

/*
 * espidf extension definition for:
 * const char *http_method_str(enum http_method m)
 */

STATIC mp_obj_t mp_http_method_str(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    enum http_method m = (int)mp_obj_get_int(mp_args[0]);
    const char * _res = ((const char *(*)(enum http_method))lv_func_ptr)(m);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_http_method_str_mpobj, 1, mp_http_method_str, http_method_str);
    

/*
 * espidf extension definition for:
 * const char *http_errno_name(enum http_errno err)
 */

STATIC mp_obj_t mp_http_errno_name(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    enum http_errno err = (int)mp_obj_get_int(mp_args[0]);
    const char * _res = ((const char *(*)(enum http_errno))lv_func_ptr)(err);
    return convert_to_str((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_http_errno_name_mpobj, 1, mp_http_errno_name, http_errno_name);
    
/* Reusing http_errno_name for http_errno_description */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_http_errno_description_mpobj, 1, mp_http_errno_name, http_errno_description);
    

/*
 * espidf extension definition for:
 * void http_parser_url_init(struct http_parser_url *u)
 */

STATIC mp_obj_t mp_http_parser_url_init(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    struct http_parser_url *u = mp_to_ptr(mp_args[0]);
    ((void (*)(struct http_parser_url *))lv_func_ptr)(u);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_VAR(mp_http_parser_url_init_mpobj, 1, mp_http_parser_url_init, http_parser_url_init);
    

/*
 * espidf extension definition for:
 * int http_parser_parse_url(const char *buf, size_t buflen, int is_connect, struct http_parser_url *u)
 */

STATIC mp_obj_t mp_http_parser_parse_url(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    const char *buf = (const char *)(char*)convert_from_str(mp_args[0]);
    size_t buflen = (size_t)mp_obj_get_int(mp_args[1]);
    int is_connect = (int)mp_obj_get_int(mp_args[2]);
    struct http_parser_url *u = mp_to_ptr(mp_args[3]);
    int _res = ((int (*)(const char *, size_t, int, struct http_parser_url *))lv_func_ptr)(buf, buflen, is_connect, u);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_http_parser_parse_url_mpobj, 4, mp_http_parser_parse_url, http_parser_parse_url);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_perform(esp_http_client_handle_t client)
 */

STATIC mp_obj_t mp_esp_http_client_perform(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t))lv_func_ptr)(client);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_perform_mpobj, 1, mp_esp_http_client_perform, esp_http_client_perform);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_url(esp_http_client_handle_t client, const char *url)
 */

STATIC mp_obj_t mp_esp_http_client_set_url(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    const char *url = (const char *)(char*)convert_from_str(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, const char *))lv_func_ptr)(client, url);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_url_mpobj, 2, mp_esp_http_client_set_url, esp_http_client_set_url);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_post_field(esp_http_client_handle_t client, const char *data, int len)
 */

STATIC mp_obj_t mp_esp_http_client_set_post_field(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    const char *data = (const char *)(char*)convert_from_str(mp_args[1]);
    int len = (int)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, const char *, int))lv_func_ptr)(client, data, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_post_field_mpobj, 3, mp_esp_http_client_set_post_field, esp_http_client_set_post_field);
    

/*
 * espidf extension definition for:
 * int esp_http_client_get_post_field(esp_http_client_handle_t client, char **data)
 */

STATIC mp_obj_t mp_esp_http_client_get_post_field(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    char **data = mp_write_ptr_C_Pointer(mp_args[1]);
    int _res = ((int (*)(esp_http_client_handle_t, char **))lv_func_ptr)(client, data);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_post_field_mpobj, 2, mp_esp_http_client_get_post_field, esp_http_client_get_post_field);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_header(esp_http_client_handle_t client, const char *key, const char *value)
 */

STATIC mp_obj_t mp_esp_http_client_set_header(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    const char *key = (const char *)(char*)convert_from_str(mp_args[1]);
    const char *value = (const char *)(char*)convert_from_str(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, const char *, const char *))lv_func_ptr)(client, key, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_header_mpobj, 3, mp_esp_http_client_set_header, esp_http_client_set_header);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_get_header(esp_http_client_handle_t client, const char *key, char **value)
 */

STATIC mp_obj_t mp_esp_http_client_get_header(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    const char *key = (const char *)(char*)convert_from_str(mp_args[1]);
    char **value = mp_write_ptr_C_Pointer(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, const char *, char **))lv_func_ptr)(client, key, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_header_mpobj, 3, mp_esp_http_client_get_header, esp_http_client_get_header);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_get_username(esp_http_client_handle_t client, char **value)
 */

STATIC mp_obj_t mp_esp_http_client_get_username(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    char **value = mp_write_ptr_C_Pointer(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, char **))lv_func_ptr)(client, value);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_username_mpobj, 2, mp_esp_http_client_get_username, esp_http_client_get_username);
    
/* Reusing esp_http_client_set_url for esp_http_client_set_username */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_username_mpobj, 2, mp_esp_http_client_set_url, esp_http_client_set_username);
    
/* Reusing esp_http_client_get_username for esp_http_client_get_password */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_password_mpobj, 2, mp_esp_http_client_get_username, esp_http_client_get_password);
    
/* Reusing esp_http_client_set_url for esp_http_client_set_password */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_password_mpobj, 2, mp_esp_http_client_set_url, esp_http_client_set_password);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_authtype(esp_http_client_handle_t client, esp_http_client_auth_type_t auth_type)
 */

STATIC mp_obj_t mp_esp_http_client_set_authtype(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    esp_http_client_auth_type_t auth_type = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, esp_http_client_auth_type_t))lv_func_ptr)(client, auth_type);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_authtype_mpobj, 2, mp_esp_http_client_set_authtype, esp_http_client_set_authtype);
    

/*
 * espidf extension definition for:
 * int esp_http_client_get_errno(esp_http_client_handle_t client)
 */

STATIC mp_obj_t mp_esp_http_client_get_errno(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    int _res = ((int (*)(esp_http_client_handle_t))lv_func_ptr)(client);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_errno_mpobj, 1, mp_esp_http_client_get_errno, esp_http_client_get_errno);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_method(esp_http_client_handle_t client, esp_http_client_method_t method)
 */

STATIC mp_obj_t mp_esp_http_client_set_method(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    esp_http_client_method_t method = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, esp_http_client_method_t))lv_func_ptr)(client, method);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_method_mpobj, 2, mp_esp_http_client_set_method, esp_http_client_set_method);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_set_timeout_ms(esp_http_client_handle_t client, int timeout_ms)
 */

STATIC mp_obj_t mp_esp_http_client_set_timeout_ms(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    int timeout_ms = (int)mp_obj_get_int(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, int))lv_func_ptr)(client, timeout_ms);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_timeout_ms_mpobj, 2, mp_esp_http_client_set_timeout_ms, esp_http_client_set_timeout_ms);
    
/* Reusing esp_http_client_set_url for esp_http_client_delete_header */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_delete_header_mpobj, 2, mp_esp_http_client_set_url, esp_http_client_delete_header);
    
/* Reusing esp_http_client_set_timeout_ms for esp_http_client_open */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_open_mpobj, 2, mp_esp_http_client_set_timeout_ms, esp_http_client_open);
    

/*
 * espidf extension definition for:
 * int esp_http_client_write(esp_http_client_handle_t client, const char *buffer, int len)
 */

STATIC mp_obj_t mp_esp_http_client_write(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    const char *buffer = (const char *)(char*)convert_from_str(mp_args[1]);
    int len = (int)mp_obj_get_int(mp_args[2]);
    int _res = ((int (*)(esp_http_client_handle_t, const char *, int))lv_func_ptr)(client, buffer, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_write_mpobj, 3, mp_esp_http_client_write, esp_http_client_write);
    
/* Reusing esp_http_client_get_errno for esp_http_client_fetch_headers */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_fetch_headers_mpobj, 1, mp_esp_http_client_get_errno, esp_http_client_fetch_headers);
    

/*
 * espidf extension definition for:
 * bool esp_http_client_is_chunked_response(esp_http_client_handle_t client)
 */

STATIC mp_obj_t mp_esp_http_client_is_chunked_response(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    bool _res = ((bool (*)(esp_http_client_handle_t))lv_func_ptr)(client);
    return convert_to_bool(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_is_chunked_response_mpobj, 1, mp_esp_http_client_is_chunked_response, esp_http_client_is_chunked_response);
    

/*
 * espidf extension definition for:
 * int esp_http_client_read(esp_http_client_handle_t client, char *buffer, int len)
 */

STATIC mp_obj_t mp_esp_http_client_read(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    char *buffer = (char*)convert_from_str(mp_args[1]);
    int len = (int)mp_obj_get_int(mp_args[2]);
    int _res = ((int (*)(esp_http_client_handle_t, char *, int))lv_func_ptr)(client, buffer, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_read_mpobj, 3, mp_esp_http_client_read, esp_http_client_read);
    
/* Reusing esp_http_client_get_errno for esp_http_client_get_status_code */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_status_code_mpobj, 1, mp_esp_http_client_get_errno, esp_http_client_get_status_code);
    
/* Reusing esp_http_client_get_errno for esp_http_client_get_content_length */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_content_length_mpobj, 1, mp_esp_http_client_get_errno, esp_http_client_get_content_length);
    
/* Reusing esp_http_client_perform for esp_http_client_close */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_close_mpobj, 1, mp_esp_http_client_perform, esp_http_client_close);
    
/* Reusing esp_http_client_perform for esp_http_client_cleanup */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_cleanup_mpobj, 1, mp_esp_http_client_perform, esp_http_client_cleanup);
    

/*
 * espidf extension definition for:
 * esp_http_client_transport_t esp_http_client_get_transport_type(esp_http_client_handle_t client)
 */

STATIC mp_obj_t mp_esp_http_client_get_transport_type(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    esp_http_client_transport_t _res = ((esp_http_client_transport_t (*)(esp_http_client_handle_t))lv_func_ptr)(client);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_transport_type_mpobj, 1, mp_esp_http_client_get_transport_type, esp_http_client_get_transport_type);
    
/* Reusing esp_http_client_perform for esp_http_client_set_redirection */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_set_redirection_mpobj, 1, mp_esp_http_client_perform, esp_http_client_set_redirection);
    

/*
 * espidf extension definition for:
 * void esp_http_client_add_auth(esp_http_client_handle_t client)
 */

STATIC mp_obj_t mp_esp_http_client_add_auth(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    ((void (*)(esp_http_client_handle_t))lv_func_ptr)(client);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_add_auth_mpobj, 1, mp_esp_http_client_add_auth, esp_http_client_add_auth);
    
/* Reusing esp_http_client_is_chunked_response for esp_http_client_is_complete_data_received */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_is_complete_data_received_mpobj, 1, mp_esp_http_client_is_chunked_response, esp_http_client_is_complete_data_received);
    
/* Reusing esp_http_client_read for esp_http_client_read_response */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_read_response_mpobj, 3, mp_esp_http_client_read, esp_http_client_read_response);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_flush_response(esp_http_client_handle_t client, int *len)
 */

STATIC mp_obj_t mp_esp_http_client_flush_response(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    int *len = mp_array_to_i32ptr(mp_args[1]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, int *))lv_func_ptr)(client, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_flush_response_mpobj, 2, mp_esp_http_client_flush_response, esp_http_client_flush_response);
    

/*
 * espidf extension definition for:
 * esp_err_t esp_http_client_get_url(esp_http_client_handle_t client, char *url, const int len)
 */

STATIC mp_obj_t mp_esp_http_client_get_url(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    esp_http_client_handle_t client = mp_to_ptr(mp_args[0]);
    char *url = (char*)convert_from_str(mp_args[1]);
    const int len = (const int)(int)mp_obj_get_int(mp_args[2]);
    esp_err_t _res = ((esp_err_t (*)(esp_http_client_handle_t, char *, const int))lv_func_ptr)(client, url, len);
    return mp_obj_new_int(_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_url_mpobj, 3, mp_esp_http_client_get_url, esp_http_client_get_url);
    
/* Reusing esp_http_client_flush_response for esp_http_client_get_chunk_length */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_esp_http_client_get_chunk_length_mpobj, 2, mp_esp_http_client_flush_response, esp_http_client_get_chunk_length);
    
/* Reusing SPH0645_WORKAROUND for task_delay_ms */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_task_delay_ms_mpobj, 1, mp_SPH0645_WORKAROUND, task_delay_ms);
    

/*
 * espidf extension definition for:
 * void *spi_transaction_set_cb(mp_obj_t pre_cb, mp_obj_t post_cb)
 */

STATIC mp_obj_t mp_spi_transaction_set_cb(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    mp_obj_t pre_cb = (mp_obj_t)(mp_args[0]);
    mp_obj_t post_cb = (mp_obj_t)(mp_args[1]);
    void * _res = ((void *(*)(mp_obj_t, mp_obj_t))lv_func_ptr)(pre_cb, post_cb);
    return ptr_to_mp((void*)_res);
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_spi_transaction_set_cb_mpobj, 2, mp_spi_transaction_set_cb, spi_transaction_set_cb);
    
/* Reusing funcptr_transaction_cb_t for ex_spi_pre_cb_isr */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ex_spi_pre_cb_isr_mpobj, 1, mp_funcptr_transaction_cb_t, ex_spi_pre_cb_isr);
    
/* Reusing funcptr_transaction_cb_t for ex_spi_post_cb_isr */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ex_spi_post_cb_isr_mpobj, 1, mp_funcptr_transaction_cb_t, ex_spi_post_cb_isr);
    
/* Reusing funcptr_transaction_cb_t for ili9xxx_post_cb_isr */

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ili9xxx_post_cb_isr_mpobj, 1, mp_funcptr_transaction_cb_t, ili9xxx_post_cb_isr);
    

/*
 * espidf extension definition for:
 * void ili9xxx_flush(void *disp_drv, const void *area, void *color_p)
 */

STATIC mp_obj_t mp_ili9xxx_flush(size_t mp_n_args, const mp_obj_t *mp_args, void *lv_func_ptr)
{
    void *disp_drv = mp_to_ptr(mp_args[0]);
    const void *area = (const void *)mp_to_ptr(mp_args[1]);
    void *color_p = mp_to_ptr(mp_args[2]);
    ((void (*)(void *, const void *, void *))lv_func_ptr)(disp_drv, area, color_p);
    return mp_const_none;
}

 

STATIC MP_DEFINE_CONST_LV_FUN_OBJ_STATIC_VAR(mp_ili9xxx_flush_mpobj, 3, mp_ili9xxx_flush, ili9xxx_flush);
    

/*
 * Callback function esp_http_client_config_t_event_handler
 * esp_err_t http_event_handle_cb(esp_http_client_event_t *evt)
 */

GENMPY_UNUSED STATIC esp_err_t esp_http_client_config_t_event_handler_callback(esp_http_client_event_t *arg0)
{
    mp_obj_t mp_args[1];
    mp_args[0] = mp_read_ptr_esp_http_client_event_t((void*)arg0);
    mp_obj_t callbacks = get_callback_dict_from_user_data(arg0->user_data);
    _nesting++;
    mp_obj_t callback_result = mp_call_function_n_kw(mp_obj_dict_get(callbacks, MP_OBJ_NEW_QSTR(MP_QSTR_esp_http_client_config_t_event_handler)) , 1, 0, mp_args);
    _nesting--;
    return (int)mp_obj_get_int(callback_result);
}


/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t crt_bundle_attach(void *conf)
 * esp_err_t crt_bundle_attach(void *conf)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t phy_reg_read(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 * esp_err_t phy_reg_read(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t phy_reg_write(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 * esp_err_t phy_reg_write(esp_eth_mediator_t *eth, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t stack_input(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length)
 * esp_err_t stack_input(esp_eth_mediator_t *eth, uint8_t *buffer, uint32_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t on_state_changed(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args)
 * esp_err_t on_state_changed(esp_eth_mediator_t *eth, esp_eth_state_t state, void *args)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_mediator(esp_eth_mac_t *mac, esp_eth_mediator_t *eth)
 * esp_err_t set_mediator(esp_eth_mac_t *mac, esp_eth_mediator_t *eth)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t init(esp_eth_mac_t *mac)
 * esp_err_t init(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t deinit(esp_eth_mac_t *mac)
 * esp_err_t deinit(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t start(esp_eth_mac_t *mac)
 * esp_err_t start(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t stop(esp_eth_mac_t *mac)
 * esp_err_t stop(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t transmit(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length)
 * esp_err_t transmit(esp_eth_mac_t *mac, uint8_t *buf, uint32_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t receive(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length)
 * esp_err_t receive(esp_eth_mac_t *mac, uint8_t *buf, uint32_t *length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t read_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 * esp_err_t read_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t write_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 * esp_err_t write_phy_reg(esp_eth_mac_t *mac, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_addr(esp_eth_mac_t *mac, uint8_t *addr)
 * esp_err_t set_addr(esp_eth_mac_t *mac, uint8_t *addr)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t get_addr(esp_eth_mac_t *mac, uint8_t *addr)
 * esp_err_t get_addr(esp_eth_mac_t *mac, uint8_t *addr)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_speed(esp_eth_mac_t *mac, eth_speed_t speed)
 * esp_err_t set_speed(esp_eth_mac_t *mac, eth_speed_t speed)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_duplex(esp_eth_mac_t *mac, eth_duplex_t duplex)
 * esp_err_t set_duplex(esp_eth_mac_t *mac, eth_duplex_t duplex)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_link(esp_eth_mac_t *mac, eth_link_t link)
 * esp_err_t set_link(esp_eth_mac_t *mac, eth_link_t link)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_promiscuous(esp_eth_mac_t *mac, bool enable)
 * esp_err_t set_promiscuous(esp_eth_mac_t *mac, bool enable)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t enable_flow_ctrl(esp_eth_mac_t *mac, bool enable)
 * esp_err_t enable_flow_ctrl(esp_eth_mac_t *mac, bool enable)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_peer_pause_ability(esp_eth_mac_t *mac, uint32_t ability)
 * esp_err_t set_peer_pause_ability(esp_eth_mac_t *mac, uint32_t ability)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t del(esp_eth_mac_t *mac)
 * esp_err_t del(esp_eth_mac_t *mac)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_mediator(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator)
 * esp_err_t set_mediator(esp_eth_phy_t *phy, esp_eth_mediator_t *mediator)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t reset(esp_eth_phy_t *phy)
 * esp_err_t reset(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t reset_hw(esp_eth_phy_t *phy)
 * esp_err_t reset_hw(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t init(esp_eth_phy_t *phy)
 * esp_err_t init(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t deinit(esp_eth_phy_t *phy)
 * esp_err_t deinit(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t negotiate(esp_eth_phy_t *phy)
 * esp_err_t negotiate(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t get_link(esp_eth_phy_t *phy)
 * esp_err_t get_link(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t pwrctl(esp_eth_phy_t *phy, bool enable)
 * esp_err_t pwrctl(esp_eth_phy_t *phy, bool enable)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t set_addr(esp_eth_phy_t *phy, uint32_t addr)
 * esp_err_t set_addr(esp_eth_phy_t *phy, uint32_t addr)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t get_addr(esp_eth_phy_t *phy, uint32_t *addr)
 * esp_err_t get_addr(esp_eth_phy_t *phy, uint32_t *addr)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t advertise_pause_ability(esp_eth_phy_t *phy, uint32_t ability)
 * esp_err_t advertise_pause_ability(esp_eth_phy_t *phy, uint32_t ability)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t loopback(esp_eth_phy_t *phy, bool enable)
 * esp_err_t loopback(esp_eth_phy_t *phy, bool enable)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t del(esp_eth_phy_t *phy)
 * esp_err_t del(esp_eth_phy_t *phy)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t stack_input(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv)
 * esp_err_t stack_input(esp_eth_handle_t eth_handle, uint8_t *buffer, uint32_t length, void *priv)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t on_lowlevel_init_done(esp_eth_handle_t eth_handle)
 * esp_err_t on_lowlevel_init_done(esp_eth_handle_t eth_handle)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t on_lowlevel_deinit_done(esp_eth_handle_t eth_handle)
 * esp_err_t on_lowlevel_deinit_done(esp_eth_handle_t eth_handle)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t read_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 * esp_err_t read_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t *reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t write_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 * esp_err_t write_phy_reg(esp_eth_handle_t eth_handle, uint32_t phy_addr, uint32_t phy_reg, uint32_t reg_value)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t transmit(void *h, void *buffer, size_t len)
 * esp_err_t transmit(void *h, void *buffer, size_t len)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! esp_err_t transmit_wrap(void *h, void *buffer, size_t len, void *netstack_buffer)
 * esp_err_t transmit_wrap(void *h, void *buffer, size_t len, void *netstack_buffer)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! void driver_free_rx_buffer(void *h, void *buffer)
 * void driver_free_rx_buffer(void *h, void *buffer)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_cb(http_parser *)
 * int http_cb(http_parser *)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_data_cb(http_parser *, const char *at, size_t length)
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_data_cb(http_parser *, const char *at, size_t length)
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_data_cb(http_parser *, const char *at, size_t length)
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_data_cb(http_parser *, const char *at, size_t length)
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_cb(http_parser *)
 * int http_cb(http_parser *)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_data_cb(http_parser *, const char *at, size_t length)
 * int http_data_cb(http_parser *, const char *at, size_t length)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_cb(http_parser *)
 * int http_cb(http_parser *)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_cb(http_parser *)
 * int http_cb(http_parser *)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! int http_cb(http_parser *)
 * int http_cb(http_parser *)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! void transaction_cb_t(spi_transaction_t *trans)
 * void transaction_cb_t(spi_transaction_t *trans)
 */
    

/*
 * Function NOT generated:
 * Callback: user_data NOT FOUND! void transaction_cb_t(spi_transaction_t *trans)
 * void transaction_cb_t(spi_transaction_t *trans)
 */
    


/*
 * espidf module definitions
 */

STATIC const mp_rom_map_elem_t espidf_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_espidf) },
    
    { MP_ROM_QSTR(MP_QSTR_lldesc_get_required_num_constrained), MP_ROM_PTR(&mp_lldesc_get_required_num_constrained_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_timeout_from_offered), MP_ROM_PTR(&mp_timeout_from_offered_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_router_enabled), MP_ROM_PTR(&mp_dhcps_router_enabled_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_dns_enabled), MP_ROM_PTR(&mp_dhcps_dns_enabled_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_get_idf_version), MP_ROM_PTR(&mp_esp_get_idf_version_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_xPortGetCoreID), MP_ROM_PTR(&mp_xPortGetCoreID_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_uxTaskPriorityGet), MP_ROM_PTR(&mp_uxTaskPriorityGet_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_SPH0645_WORKAROUND), MP_ROM_PTR(&mp_SPH0645_WORKAROUND_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_get_ccount), MP_ROM_PTR(&mp_get_ccount_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_memcpy), MP_ROM_PTR(&mp_memcpy_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_memset), MP_ROM_PTR(&mp_memset_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_slowclk_cal_get), MP_ROM_PTR(&mp_esp_clk_slowclk_cal_get_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_slowclk_cal_set), MP_ROM_PTR(&mp_esp_clk_slowclk_cal_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_cpu_freq), MP_ROM_PTR(&mp_esp_clk_cpu_freq_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_apb_freq), MP_ROM_PTR(&mp_esp_clk_apb_freq_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_xtal_freq), MP_ROM_PTR(&mp_esp_clk_xtal_freq_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_rtc_time), MP_ROM_PTR(&mp_esp_clk_rtc_time_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_private_lock), MP_ROM_PTR(&mp_esp_clk_private_lock_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_clk_private_unlock), MP_ROM_PTR(&mp_esp_clk_private_unlock_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_err_to_name), MP_ROM_PTR(&mp_esp_err_to_name_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_err_to_name_r), MP_ROM_PTR(&mp_esp_err_to_name_r_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_init), MP_ROM_PTR(&mp_gpio_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_output_set), MP_ROM_PTR(&mp_gpio_output_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_output_set_high), MP_ROM_PTR(&mp_gpio_output_set_high_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_input_get), MP_ROM_PTR(&mp_gpio_input_get_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_input_get_high), MP_ROM_PTR(&mp_gpio_input_get_high_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_handler_register), MP_ROM_PTR(&mp_gpio_intr_handler_register_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_pending), MP_ROM_PTR(&mp_gpio_intr_pending_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_pending_high), MP_ROM_PTR(&mp_gpio_intr_pending_high_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_ack), MP_ROM_PTR(&mp_gpio_intr_ack_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_ack_high), MP_ROM_PTR(&mp_gpio_intr_ack_high_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pin_wakeup_enable), MP_ROM_PTR(&mp_gpio_pin_wakeup_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pin_wakeup_disable), MP_ROM_PTR(&mp_gpio_pin_wakeup_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_matrix_in), MP_ROM_PTR(&mp_gpio_matrix_in_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_matrix_out), MP_ROM_PTR(&mp_gpio_matrix_out_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_select_gpio), MP_ROM_PTR(&mp_gpio_pad_select_gpio_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_set_drv), MP_ROM_PTR(&mp_gpio_pad_set_drv_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_pullup), MP_ROM_PTR(&mp_gpio_pad_pullup_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_pulldown), MP_ROM_PTR(&mp_gpio_pad_pulldown_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_unhold), MP_ROM_PTR(&mp_gpio_pad_unhold_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pad_hold), MP_ROM_PTR(&mp_gpio_pad_hold_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_reset_pin), MP_ROM_PTR(&mp_gpio_reset_pin_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_set_intr_type), MP_ROM_PTR(&mp_gpio_set_intr_type_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_enable), MP_ROM_PTR(&mp_gpio_intr_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_intr_disable), MP_ROM_PTR(&mp_gpio_intr_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_set_level), MP_ROM_PTR(&mp_gpio_set_level_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_get_level), MP_ROM_PTR(&mp_gpio_get_level_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_set_direction), MP_ROM_PTR(&mp_gpio_set_direction_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_set_pull_mode), MP_ROM_PTR(&mp_gpio_set_pull_mode_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_wakeup_enable), MP_ROM_PTR(&mp_gpio_wakeup_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_wakeup_disable), MP_ROM_PTR(&mp_gpio_wakeup_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_isr_register), MP_ROM_PTR(&mp_gpio_isr_register_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pullup_en), MP_ROM_PTR(&mp_gpio_pullup_en_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pullup_dis), MP_ROM_PTR(&mp_gpio_pullup_dis_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pulldown_en), MP_ROM_PTR(&mp_gpio_pulldown_en_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_pulldown_dis), MP_ROM_PTR(&mp_gpio_pulldown_dis_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_install_isr_service), MP_ROM_PTR(&mp_gpio_install_isr_service_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_uninstall_isr_service), MP_ROM_PTR(&mp_gpio_uninstall_isr_service_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_isr_handler_add), MP_ROM_PTR(&mp_gpio_isr_handler_add_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_isr_handler_remove), MP_ROM_PTR(&mp_gpio_isr_handler_remove_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_set_drive_capability), MP_ROM_PTR(&mp_gpio_set_drive_capability_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_get_drive_capability), MP_ROM_PTR(&mp_gpio_get_drive_capability_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_hold_en), MP_ROM_PTR(&mp_gpio_hold_en_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_hold_dis), MP_ROM_PTR(&mp_gpio_hold_dis_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_deep_sleep_hold_en), MP_ROM_PTR(&mp_gpio_deep_sleep_hold_en_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_deep_sleep_hold_dis), MP_ROM_PTR(&mp_gpio_deep_sleep_hold_dis_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_iomux_in), MP_ROM_PTR(&mp_gpio_iomux_in_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_iomux_out), MP_ROM_PTR(&mp_gpio_iomux_out_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_sleep_sel_en), MP_ROM_PTR(&mp_gpio_sleep_sel_en_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_sleep_sel_dis), MP_ROM_PTR(&mp_gpio_sleep_sel_dis_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_sleep_set_direction), MP_ROM_PTR(&mp_gpio_sleep_set_direction_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_gpio_sleep_set_pull_mode), MP_ROM_PTR(&mp_gpio_sleep_set_pull_mode_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lldesc_setup_link_constrained), MP_ROM_PTR(&mp_lldesc_setup_link_constrained_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lldesc_get_received_len), MP_ROM_PTR(&mp_lldesc_get_received_len_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_initialize), MP_ROM_PTR(&mp_spi_bus_initialize_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_free), MP_ROM_PTR(&mp_spi_bus_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_add_device), MP_ROM_PTR(&mp_spi_bus_add_device_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_remove_device), MP_ROM_PTR(&mp_spi_bus_remove_device_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_queue_trans), MP_ROM_PTR(&mp_spi_device_queue_trans_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_get_trans_result), MP_ROM_PTR(&mp_spi_device_get_trans_result_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_transmit), MP_ROM_PTR(&mp_spi_device_transmit_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_polling_start), MP_ROM_PTR(&mp_spi_device_polling_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_polling_end), MP_ROM_PTR(&mp_spi_device_polling_end_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_polling_transmit), MP_ROM_PTR(&mp_spi_device_polling_transmit_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_acquire_bus), MP_ROM_PTR(&mp_spi_device_acquire_bus_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_release_bus), MP_ROM_PTR(&mp_spi_device_release_bus_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_cal_clock), MP_ROM_PTR(&mp_spi_cal_clock_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_get_actual_clock), MP_ROM_PTR(&mp_spi_get_actual_clock_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_get_timing), MP_ROM_PTR(&mp_spi_get_timing_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_get_freq_limit), MP_ROM_PTR(&mp_spi_get_freq_limit_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_get_max_transaction_len), MP_ROM_PTR(&mp_spi_bus_get_max_transaction_len_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_aligned_alloc), MP_ROM_PTR(&mp_multi_heap_aligned_alloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_malloc), MP_ROM_PTR(&mp_multi_heap_malloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_aligned_free), MP_ROM_PTR(&mp_multi_heap_aligned_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_free), MP_ROM_PTR(&mp_multi_heap_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_realloc), MP_ROM_PTR(&mp_multi_heap_realloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_get_allocated_size), MP_ROM_PTR(&mp_multi_heap_get_allocated_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_register), MP_ROM_PTR(&mp_multi_heap_register_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_set_lock), MP_ROM_PTR(&mp_multi_heap_set_lock_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_dump), MP_ROM_PTR(&mp_multi_heap_dump_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_check), MP_ROM_PTR(&mp_multi_heap_check_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_free_size), MP_ROM_PTR(&mp_multi_heap_free_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_minimum_free_size), MP_ROM_PTR(&mp_multi_heap_minimum_free_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_get_info), MP_ROM_PTR(&mp_multi_heap_get_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_register_failed_alloc_callback), MP_ROM_PTR(&mp_heap_caps_register_failed_alloc_callback_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_malloc), MP_ROM_PTR(&mp_heap_caps_malloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_free), MP_ROM_PTR(&mp_heap_caps_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_realloc), MP_ROM_PTR(&mp_heap_caps_realloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_aligned_alloc), MP_ROM_PTR(&mp_heap_caps_aligned_alloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_aligned_free), MP_ROM_PTR(&mp_heap_caps_aligned_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_aligned_calloc), MP_ROM_PTR(&mp_heap_caps_aligned_calloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_calloc), MP_ROM_PTR(&mp_heap_caps_calloc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_total_size), MP_ROM_PTR(&mp_heap_caps_get_total_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_free_size), MP_ROM_PTR(&mp_heap_caps_get_free_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_minimum_free_size), MP_ROM_PTR(&mp_heap_caps_get_minimum_free_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_largest_free_block), MP_ROM_PTR(&mp_heap_caps_get_largest_free_block_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_info), MP_ROM_PTR(&mp_heap_caps_get_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_print_heap_info), MP_ROM_PTR(&mp_heap_caps_print_heap_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_check_integrity_all), MP_ROM_PTR(&mp_heap_caps_check_integrity_all_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_check_integrity), MP_ROM_PTR(&mp_heap_caps_check_integrity_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_check_integrity_addr), MP_ROM_PTR(&mp_heap_caps_check_integrity_addr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_malloc_extmem_enable), MP_ROM_PTR(&mp_heap_caps_malloc_extmem_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_dump), MP_ROM_PTR(&mp_heap_caps_dump_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_dump_all), MP_ROM_PTR(&mp_heap_caps_dump_all_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_heap_caps_get_allocated_size), MP_ROM_PTR(&mp_heap_caps_get_allocated_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_rom_delay_us), MP_ROM_PTR(&mp_esp_rom_delay_us_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_rom_install_channel_putc), MP_ROM_PTR(&mp_esp_rom_install_channel_putc_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_rom_install_uart_printf), MP_ROM_PTR(&mp_esp_rom_install_uart_printf_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_rom_get_reset_reason), MP_ROM_PTR(&mp_esp_rom_get_reset_reason_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_level_set), MP_ROM_PTR(&mp_esp_log_level_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_level_get), MP_ROM_PTR(&mp_esp_log_level_get_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_set_vprintf), MP_ROM_PTR(&mp_esp_log_set_vprintf_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_timestamp), MP_ROM_PTR(&mp_esp_log_timestamp_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_system_timestamp), MP_ROM_PTR(&mp_esp_log_system_timestamp_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_early_timestamp), MP_ROM_PTR(&mp_esp_log_early_timestamp_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_buffer_hex_internal), MP_ROM_PTR(&mp_esp_log_buffer_hex_internal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_buffer_char_internal), MP_ROM_PTR(&mp_esp_log_buffer_char_internal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_log_buffer_hexdump_internal), MP_ROM_PTR(&mp_esp_log_buffer_hexdump_internal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_power_on), MP_ROM_PTR(&mp_adc_power_on_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_power_off), MP_ROM_PTR(&mp_adc_power_off_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_power_acquire), MP_ROM_PTR(&mp_adc_power_acquire_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_power_release), MP_ROM_PTR(&mp_adc_power_release_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc1_pad_get_io_num), MP_ROM_PTR(&mp_adc1_pad_get_io_num_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc1_config_channel_atten), MP_ROM_PTR(&mp_adc1_config_channel_atten_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc1_config_width), MP_ROM_PTR(&mp_adc1_config_width_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc1_get_raw), MP_ROM_PTR(&mp_adc1_get_raw_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_set_data_inv), MP_ROM_PTR(&mp_adc_set_data_inv_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_set_clk_div), MP_ROM_PTR(&mp_adc_set_clk_div_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_set_data_width), MP_ROM_PTR(&mp_adc_set_data_width_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc1_ulp_enable), MP_ROM_PTR(&mp_adc1_ulp_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc2_pad_get_io_num), MP_ROM_PTR(&mp_adc2_pad_get_io_num_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc2_config_channel_atten), MP_ROM_PTR(&mp_adc2_config_channel_atten_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc2_get_raw), MP_ROM_PTR(&mp_adc2_get_raw_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_vref_to_gpio), MP_ROM_PTR(&mp_adc_vref_to_gpio_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc2_vref_to_gpio), MP_ROM_PTR(&mp_adc2_vref_to_gpio_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_read_bytes), MP_ROM_PTR(&mp_adc_digi_read_bytes_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_start), MP_ROM_PTR(&mp_adc_digi_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_stop), MP_ROM_PTR(&mp_adc_digi_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_deinitialize), MP_ROM_PTR(&mp_adc_digi_deinitialize_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_hall_sensor_read), MP_ROM_PTR(&mp_hall_sensor_read_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_set_i2s_data_source), MP_ROM_PTR(&mp_adc_set_i2s_data_source_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_adc_i2s_mode_init), MP_ROM_PTR(&mp_adc_i2s_mode_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_pin), MP_ROM_PTR(&mp_i2s_set_pin_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_pdm_rx_down_sample), MP_ROM_PTR(&mp_i2s_set_pdm_rx_down_sample_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_pdm_tx_up_sample), MP_ROM_PTR(&mp_i2s_set_pdm_tx_up_sample_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_driver_install), MP_ROM_PTR(&mp_i2s_driver_install_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_driver_uninstall), MP_ROM_PTR(&mp_i2s_driver_uninstall_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_write), MP_ROM_PTR(&mp_i2s_write_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_write_expand), MP_ROM_PTR(&mp_i2s_write_expand_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_read), MP_ROM_PTR(&mp_i2s_read_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_sample_rates), MP_ROM_PTR(&mp_i2s_set_sample_rates_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_stop), MP_ROM_PTR(&mp_i2s_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_start), MP_ROM_PTR(&mp_i2s_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_zero_dma_buffer), MP_ROM_PTR(&mp_i2s_zero_dma_buffer_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_clk), MP_ROM_PTR(&mp_i2s_set_clk_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_get_clk), MP_ROM_PTR(&mp_i2s_get_clk_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_adc_mode), MP_ROM_PTR(&mp_i2s_set_adc_mode_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_adc_enable), MP_ROM_PTR(&mp_i2s_adc_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_adc_disable), MP_ROM_PTR(&mp_i2s_adc_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_i2s_set_dac_mode), MP_ROM_PTR(&mp_i2s_set_dac_mode_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_get_counter_value), MP_ROM_PTR(&mp_pcnt_get_counter_value_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_counter_pause), MP_ROM_PTR(&mp_pcnt_counter_pause_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_counter_resume), MP_ROM_PTR(&mp_pcnt_counter_resume_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_counter_clear), MP_ROM_PTR(&mp_pcnt_counter_clear_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_intr_enable), MP_ROM_PTR(&mp_pcnt_intr_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_intr_disable), MP_ROM_PTR(&mp_pcnt_intr_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_event_enable), MP_ROM_PTR(&mp_pcnt_event_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_event_disable), MP_ROM_PTR(&mp_pcnt_event_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_set_event_value), MP_ROM_PTR(&mp_pcnt_set_event_value_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_get_event_value), MP_ROM_PTR(&mp_pcnt_get_event_value_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_get_event_status), MP_ROM_PTR(&mp_pcnt_get_event_status_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_unregister), MP_ROM_PTR(&mp_pcnt_isr_unregister_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_register), MP_ROM_PTR(&mp_pcnt_isr_register_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_set_pin), MP_ROM_PTR(&mp_pcnt_set_pin_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_filter_enable), MP_ROM_PTR(&mp_pcnt_filter_enable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_filter_disable), MP_ROM_PTR(&mp_pcnt_filter_disable_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_set_filter_value), MP_ROM_PTR(&mp_pcnt_set_filter_value_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_get_filter_value), MP_ROM_PTR(&mp_pcnt_get_filter_value_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_set_mode), MP_ROM_PTR(&mp_pcnt_set_mode_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_handler_add), MP_ROM_PTR(&mp_pcnt_isr_handler_add_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_service_install), MP_ROM_PTR(&mp_pcnt_isr_service_install_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_service_uninstall), MP_ROM_PTR(&mp_pcnt_isr_service_uninstall_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_isr_handler_remove), MP_ROM_PTR(&mp_pcnt_isr_handler_remove_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_driver_uninstall), MP_ROM_PTR(&mp_esp_eth_driver_uninstall_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_start), MP_ROM_PTR(&mp_esp_eth_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_stop), MP_ROM_PTR(&mp_esp_eth_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_update_input_path), MP_ROM_PTR(&mp_esp_eth_update_input_path_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_transmit), MP_ROM_PTR(&mp_esp_eth_transmit_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_receive), MP_ROM_PTR(&mp_esp_eth_receive_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_ioctl), MP_ROM_PTR(&mp_esp_eth_ioctl_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_increase_reference), MP_ROM_PTR(&mp_esp_eth_increase_reference_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_decrease_reference), MP_ROM_PTR(&mp_esp_eth_decrease_reference_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_new_netif_glue), MP_ROM_PTR(&mp_esp_eth_new_netif_glue_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_del_netif_glue), MP_ROM_PTR(&mp_esp_eth_del_netif_glue_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_set_default_handlers), MP_ROM_PTR(&mp_esp_eth_set_default_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_clear_default_handlers), MP_ROM_PTR(&mp_esp_eth_clear_default_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_xt_clock_freq), MP_ROM_PTR(&mp_xt_clock_freq_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_vPortCleanUpTCB), MP_ROM_PTR(&mp_vPortCleanUpTCB_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_base_mac_addr_set), MP_ROM_PTR(&mp_esp_base_mac_addr_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_base_mac_addr_get), MP_ROM_PTR(&mp_esp_base_mac_addr_get_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_efuse_mac_get_custom), MP_ROM_PTR(&mp_esp_efuse_mac_get_custom_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_efuse_mac_get_default), MP_ROM_PTR(&mp_esp_efuse_mac_get_default_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_read_mac), MP_ROM_PTR(&mp_esp_read_mac_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_derive_local_mac), MP_ROM_PTR(&mp_esp_derive_local_mac_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_random), MP_ROM_PTR(&mp_esp_random_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_fill_random), MP_ROM_PTR(&mp_esp_fill_random_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_register_shutdown_handler), MP_ROM_PTR(&mp_esp_register_shutdown_handler_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_unregister_shutdown_handler), MP_ROM_PTR(&mp_esp_unregister_shutdown_handler_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_restart), MP_ROM_PTR(&mp_esp_restart_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_reset_reason), MP_ROM_PTR(&mp_esp_reset_reason_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_get_free_heap_size), MP_ROM_PTR(&mp_esp_get_free_heap_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_get_free_internal_heap_size), MP_ROM_PTR(&mp_esp_get_free_internal_heap_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_get_minimum_free_heap_size), MP_ROM_PTR(&mp_esp_get_minimum_free_heap_size_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_system_abort), MP_ROM_PTR(&mp_esp_system_abort_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcp_ip_addr_restore), MP_ROM_PTR(&mp_dhcp_ip_addr_restore_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcp_ip_addr_store), MP_ROM_PTR(&mp_dhcp_ip_addr_store_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcp_ip_addr_erase), MP_ROM_PTR(&mp_dhcp_ip_addr_erase_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sntp_get_sync_interval), MP_ROM_PTR(&mp_sntp_get_sync_interval_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sntp_set_system_time), MP_ROM_PTR(&mp_sntp_set_system_time_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_sntp_get_system_time), MP_ROM_PTR(&mp_sntp_get_system_time_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_htons), MP_ROM_PTR(&mp_lwip_htons_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_htonl), MP_ROM_PTR(&mp_lwip_htonl_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_itoa), MP_ROM_PTR(&mp_lwip_itoa_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_strnicmp), MP_ROM_PTR(&mp_lwip_strnicmp_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_stricmp), MP_ROM_PTR(&mp_lwip_stricmp_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_lwip_strnstr), MP_ROM_PTR(&mp_lwip_strnstr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ip4_addr_isbroadcast_u32), MP_ROM_PTR(&mp_ip4_addr_isbroadcast_u32_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ip4_addr_netmask_valid), MP_ROM_PTR(&mp_ip4_addr_netmask_valid_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ipaddr_addr), MP_ROM_PTR(&mp_ipaddr_addr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ip4addr_aton), MP_ROM_PTR(&mp_ip4addr_aton_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ip6addr_aton), MP_ROM_PTR(&mp_ip6addr_aton_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ipaddr_aton), MP_ROM_PTR(&mp_ipaddr_aton_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_err_to_errno), MP_ROM_PTR(&mp_err_to_errno_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_start), MP_ROM_PTR(&mp_dhcps_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_stop), MP_ROM_PTR(&mp_dhcps_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_option_info), MP_ROM_PTR(&mp_dhcps_option_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_set_option_info), MP_ROM_PTR(&mp_dhcps_set_option_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcp_search_ip_on_mac), MP_ROM_PTR(&mp_dhcp_search_ip_on_mac_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_dns_setserver), MP_ROM_PTR(&mp_dhcps_dns_setserver_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_dns_getserver), MP_ROM_PTR(&mp_dhcps_dns_getserver_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_dhcps_set_new_lease_cb), MP_ROM_PTR(&mp_dhcps_set_new_lease_cb_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_get_sta_list), MP_ROM_PTR(&mp_esp_netif_get_sta_list_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_init), MP_ROM_PTR(&mp_tcpip_adapter_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_if_from_esp_netif), MP_ROM_PTR(&mp_tcpip_adapter_if_from_esp_netif_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_ip_info), MP_ROM_PTR(&mp_tcpip_adapter_get_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_ip6_linklocal), MP_ROM_PTR(&mp_tcpip_adapter_get_ip6_linklocal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_ip6_global), MP_ROM_PTR(&mp_tcpip_adapter_get_ip6_global_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcpc_get_status), MP_ROM_PTR(&mp_tcpip_adapter_dhcpc_get_status_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_is_netif_up), MP_ROM_PTR(&mp_tcpip_adapter_is_netif_up_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_netif), MP_ROM_PTR(&mp_tcpip_adapter_get_netif_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_create_ip6_linklocal), MP_ROM_PTR(&mp_tcpip_adapter_create_ip6_linklocal_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_default_eth_handlers), MP_ROM_PTR(&mp_tcpip_adapter_set_default_eth_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_eth_input), MP_ROM_PTR(&mp_tcpip_adapter_eth_input_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_sta_input), MP_ROM_PTR(&mp_tcpip_adapter_sta_input_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_ap_input), MP_ROM_PTR(&mp_tcpip_adapter_ap_input_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_clear_default_wifi_handlers), MP_ROM_PTR(&mp_tcpip_adapter_clear_default_wifi_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_clear_default_eth_handlers), MP_ROM_PTR(&mp_tcpip_adapter_clear_default_eth_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcps_stop), MP_ROM_PTR(&mp_tcpip_adapter_dhcps_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcpc_stop), MP_ROM_PTR(&mp_tcpip_adapter_dhcpc_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcps_start), MP_ROM_PTR(&mp_tcpip_adapter_dhcps_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcpc_start), MP_ROM_PTR(&mp_tcpip_adapter_dhcpc_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcps_get_status), MP_ROM_PTR(&mp_tcpip_adapter_dhcps_get_status_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcps_option), MP_ROM_PTR(&mp_tcpip_adapter_dhcps_option_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_dhcpc_option), MP_ROM_PTR(&mp_tcpip_adapter_dhcpc_option_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_ip_info), MP_ROM_PTR(&mp_tcpip_adapter_set_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_dns_info), MP_ROM_PTR(&mp_tcpip_adapter_get_dns_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_dns_info), MP_ROM_PTR(&mp_tcpip_adapter_set_dns_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_netif_index), MP_ROM_PTR(&mp_tcpip_adapter_get_netif_index_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_sta_list), MP_ROM_PTR(&mp_tcpip_adapter_get_sta_list_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_eth_start), MP_ROM_PTR(&mp_tcpip_adapter_eth_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_sta_start), MP_ROM_PTR(&mp_tcpip_adapter_sta_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_ap_start), MP_ROM_PTR(&mp_tcpip_adapter_ap_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_stop), MP_ROM_PTR(&mp_tcpip_adapter_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_up), MP_ROM_PTR(&mp_tcpip_adapter_up_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_down), MP_ROM_PTR(&mp_tcpip_adapter_down_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_old_ip_info), MP_ROM_PTR(&mp_tcpip_adapter_get_old_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_old_ip_info), MP_ROM_PTR(&mp_tcpip_adapter_set_old_ip_info_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_esp_if), MP_ROM_PTR(&mp_tcpip_adapter_get_esp_if_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_hostname), MP_ROM_PTR(&mp_tcpip_adapter_set_hostname_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_get_hostname), MP_ROM_PTR(&mp_tcpip_adapter_get_hostname_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_set_default_wifi_handlers), MP_ROM_PTR(&mp_tcpip_adapter_set_default_wifi_handlers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_init), MP_ROM_PTR(&mp_esp_netif_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_deinit), MP_ROM_PTR(&mp_esp_netif_deinit_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_start), MP_ROM_PTR(&mp_esp_netif_action_start_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_stop), MP_ROM_PTR(&mp_esp_netif_action_stop_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_connected), MP_ROM_PTR(&mp_esp_netif_action_connected_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_disconnected), MP_ROM_PTR(&mp_esp_netif_action_disconnected_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_got_ip), MP_ROM_PTR(&mp_esp_netif_action_got_ip_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_join_ip6_multicast_group), MP_ROM_PTR(&mp_esp_netif_action_join_ip6_multicast_group_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_leave_ip6_multicast_group), MP_ROM_PTR(&mp_esp_netif_action_leave_ip6_multicast_group_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_add_ip6_address), MP_ROM_PTR(&mp_esp_netif_action_add_ip6_address_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_action_remove_ip6_address), MP_ROM_PTR(&mp_esp_netif_action_remove_ip6_address_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_ip4addr_aton), MP_ROM_PTR(&mp_esp_ip4addr_aton_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_str_to_ip4), MP_ROM_PTR(&mp_esp_netif_str_to_ip4_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_str_to_ip6), MP_ROM_PTR(&mp_esp_netif_str_to_ip6_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_get_handle_from_ifkey), MP_ROM_PTR(&mp_esp_netif_get_handle_from_ifkey_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_get_nr_of_ifs), MP_ROM_PTR(&mp_esp_netif_get_nr_of_ifs_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_netstack_buf_ref), MP_ROM_PTR(&mp_esp_netif_netstack_buf_ref_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_netstack_buf_free), MP_ROM_PTR(&mp_esp_netif_netstack_buf_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_tcpip_exec), MP_ROM_PTR(&mp_esp_netif_tcpip_exec_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_init), MP_ROM_PTR(&mp_mdns_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_free), MP_ROM_PTR(&mp_mdns_free_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_hostname_set), MP_ROM_PTR(&mp_mdns_hostname_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_delegate_hostname_add), MP_ROM_PTR(&mp_mdns_delegate_hostname_add_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_delegate_hostname_remove), MP_ROM_PTR(&mp_mdns_delegate_hostname_remove_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_hostname_exists), MP_ROM_PTR(&mp_mdns_hostname_exists_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_instance_name_set), MP_ROM_PTR(&mp_mdns_instance_name_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_add), MP_ROM_PTR(&mp_mdns_service_add_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_add_for_host), MP_ROM_PTR(&mp_mdns_service_add_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_exists), MP_ROM_PTR(&mp_mdns_service_exists_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_exists_with_instance), MP_ROM_PTR(&mp_mdns_service_exists_with_instance_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_remove), MP_ROM_PTR(&mp_mdns_service_remove_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_remove_for_host), MP_ROM_PTR(&mp_mdns_service_remove_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_instance_name_set), MP_ROM_PTR(&mp_mdns_service_instance_name_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_instance_name_set_for_host), MP_ROM_PTR(&mp_mdns_service_instance_name_set_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_port_set), MP_ROM_PTR(&mp_mdns_service_port_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_port_set_for_host), MP_ROM_PTR(&mp_mdns_service_port_set_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_set), MP_ROM_PTR(&mp_mdns_service_txt_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_set_for_host), MP_ROM_PTR(&mp_mdns_service_txt_set_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_set), MP_ROM_PTR(&mp_mdns_service_txt_item_set_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_set_with_explicit_value_len), MP_ROM_PTR(&mp_mdns_service_txt_item_set_with_explicit_value_len_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_set_for_host), MP_ROM_PTR(&mp_mdns_service_txt_item_set_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_set_for_host_with_explicit_value_len), MP_ROM_PTR(&mp_mdns_service_txt_item_set_for_host_with_explicit_value_len_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_remove), MP_ROM_PTR(&mp_mdns_service_txt_item_remove_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_txt_item_remove_for_host), MP_ROM_PTR(&mp_mdns_service_txt_item_remove_for_host_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_service_remove_all), MP_ROM_PTR(&mp_mdns_service_remove_all_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_async_new), MP_ROM_PTR(&mp_mdns_query_async_new_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query), MP_ROM_PTR(&mp_mdns_query_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_ptr), MP_ROM_PTR(&mp_mdns_query_ptr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_srv), MP_ROM_PTR(&mp_mdns_query_srv_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_txt), MP_ROM_PTR(&mp_mdns_query_txt_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_a), MP_ROM_PTR(&mp_mdns_query_a_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_query_aaaa), MP_ROM_PTR(&mp_mdns_query_aaaa_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_mdns_handle_system_event), MP_ROM_PTR(&mp_mdns_handle_system_event_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_parser_version), MP_ROM_PTR(&mp_http_parser_version_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_method_str), MP_ROM_PTR(&mp_http_method_str_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_errno_name), MP_ROM_PTR(&mp_http_errno_name_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_errno_description), MP_ROM_PTR(&mp_http_errno_description_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_parser_url_init), MP_ROM_PTR(&mp_http_parser_url_init_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_http_parser_parse_url), MP_ROM_PTR(&mp_http_parser_parse_url_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_perform), MP_ROM_PTR(&mp_esp_http_client_perform_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_url), MP_ROM_PTR(&mp_esp_http_client_set_url_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_post_field), MP_ROM_PTR(&mp_esp_http_client_set_post_field_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_post_field), MP_ROM_PTR(&mp_esp_http_client_get_post_field_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_header), MP_ROM_PTR(&mp_esp_http_client_set_header_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_header), MP_ROM_PTR(&mp_esp_http_client_get_header_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_username), MP_ROM_PTR(&mp_esp_http_client_get_username_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_username), MP_ROM_PTR(&mp_esp_http_client_set_username_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_password), MP_ROM_PTR(&mp_esp_http_client_get_password_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_password), MP_ROM_PTR(&mp_esp_http_client_set_password_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_authtype), MP_ROM_PTR(&mp_esp_http_client_set_authtype_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_errno), MP_ROM_PTR(&mp_esp_http_client_get_errno_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_method), MP_ROM_PTR(&mp_esp_http_client_set_method_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_timeout_ms), MP_ROM_PTR(&mp_esp_http_client_set_timeout_ms_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_delete_header), MP_ROM_PTR(&mp_esp_http_client_delete_header_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_open), MP_ROM_PTR(&mp_esp_http_client_open_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_write), MP_ROM_PTR(&mp_esp_http_client_write_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_fetch_headers), MP_ROM_PTR(&mp_esp_http_client_fetch_headers_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_is_chunked_response), MP_ROM_PTR(&mp_esp_http_client_is_chunked_response_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_read), MP_ROM_PTR(&mp_esp_http_client_read_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_status_code), MP_ROM_PTR(&mp_esp_http_client_get_status_code_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_content_length), MP_ROM_PTR(&mp_esp_http_client_get_content_length_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_close), MP_ROM_PTR(&mp_esp_http_client_close_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_cleanup), MP_ROM_PTR(&mp_esp_http_client_cleanup_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_transport_type), MP_ROM_PTR(&mp_esp_http_client_get_transport_type_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_set_redirection), MP_ROM_PTR(&mp_esp_http_client_set_redirection_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_add_auth), MP_ROM_PTR(&mp_esp_http_client_add_auth_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_is_complete_data_received), MP_ROM_PTR(&mp_esp_http_client_is_complete_data_received_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_read_response), MP_ROM_PTR(&mp_esp_http_client_read_response_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_flush_response), MP_ROM_PTR(&mp_esp_http_client_flush_response_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_url), MP_ROM_PTR(&mp_esp_http_client_get_url_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_get_chunk_length), MP_ROM_PTR(&mp_esp_http_client_get_chunk_length_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_task_delay_ms), MP_ROM_PTR(&mp_task_delay_ms_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_spi_transaction_set_cb), MP_ROM_PTR(&mp_spi_transaction_set_cb_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ex_spi_pre_cb_isr), MP_ROM_PTR(&mp_ex_spi_pre_cb_isr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ex_spi_post_cb_isr), MP_ROM_PTR(&mp_ex_spi_post_cb_isr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ili9xxx_post_cb_isr), MP_ROM_PTR(&mp_ili9xxx_post_cb_isr_mpobj) },
    { MP_ROM_QSTR(MP_QSTR_ili9xxx_flush), MP_ROM_PTR(&mp_ili9xxx_flush_mpobj) },
    
    { MP_ROM_QSTR(MP_QSTR_IP6), MP_ROM_PTR(&mp_lv_IP6_type_base) },
    { MP_ROM_QSTR(MP_QSTR_IPADDR_TYPE), MP_ROM_PTR(&mp_lv_IPADDR_TYPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_OFFER), MP_ROM_PTR(&mp_lv_OFFER_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HTTP), MP_ROM_PTR(&mp_lv_HTTP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_F), MP_ROM_PTR(&mp_lv_F_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HPE), MP_ROM_PTR(&mp_lv_HPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_UF), MP_ROM_PTR(&mp_lv_UF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SPI_DEVICE), MP_ROM_PTR(&mp_lv_ENUM_SPI_DEVICE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SPI_TRANS), MP_ROM_PTR(&mp_lv_ENUM_SPI_TRANS_type_base) },
    { MP_ROM_QSTR(MP_QSTR_MALLOC_CAP), MP_ROM_PTR(&mp_lv_ENUM_MALLOC_CAP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_TASK_PRIO), MP_ROM_PTR(&mp_lv_ENUM_ESP_TASK_PRIO_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_PORT), MP_ROM_PTR(&mp_lv_GPIO_PORT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_NUM), MP_ROM_PTR(&mp_lv_GPIO_NUM_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_INTR), MP_ROM_PTR(&mp_lv_GPIO_INTR_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_MODE), MP_ROM_PTR(&mp_lv_GPIO_MODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_PULLUP), MP_ROM_PTR(&mp_lv_GPIO_PULLUP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_PULLDOWN), MP_ROM_PTR(&mp_lv_GPIO_PULLDOWN_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO), MP_ROM_PTR(&mp_lv_GPIO_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_DRIVE_CAP), MP_ROM_PTR(&mp_lv_GPIO_DRIVE_CAP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_GPIO_PIN_INTR), MP_ROM_PTR(&mp_lv_GPIO_PIN_INTR_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PERIPH), MP_ROM_PTR(&mp_lv_PERIPH_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SPI_EV), MP_ROM_PTR(&mp_lv_SPI_EV_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SPI_CMD_HD), MP_ROM_PTR(&mp_lv_SPI_CMD_HD_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SPI_DMA), MP_ROM_PTR(&mp_lv_SPI_DMA_type_base) },
    { MP_ROM_QSTR(MP_QSTR_RESET_REASON), MP_ROM_PTR(&mp_lv_RESET_REASON_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_LOG), MP_ROM_PTR(&mp_lv_ESP_LOG_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_UNIT), MP_ROM_PTR(&mp_lv_ADC_UNIT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_CHANNEL), MP_ROM_PTR(&mp_lv_ADC_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_ATTEN), MP_ROM_PTR(&mp_lv_ADC_ATTEN_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_WIDTH), MP_ROM_PTR(&mp_lv_ADC_WIDTH_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_CONV), MP_ROM_PTR(&mp_lv_ADC_CONV_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_DIGI), MP_ROM_PTR(&mp_lv_ADC_DIGI_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_I2S_DATA_SRC), MP_ROM_PTR(&mp_lv_ADC_I2S_DATA_SRC_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC1_CHANNEL), MP_ROM_PTR(&mp_lv_ADC1_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC2_CHANNEL), MP_ROM_PTR(&mp_lv_ADC2_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ADC_ENCODE), MP_ROM_PTR(&mp_lv_ADC_ENCODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_BITS_PER_SAMPLE), MP_ROM_PTR(&mp_lv_I2S_BITS_PER_SAMPLE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_BITS_PER_CHAN), MP_ROM_PTR(&mp_lv_I2S_BITS_PER_CHAN_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_CHANNEL), MP_ROM_PTR(&mp_lv_I2S_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_COMM_FORMAT), MP_ROM_PTR(&mp_lv_I2S_COMM_FORMAT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_CHANNEL_FMT), MP_ROM_PTR(&mp_lv_I2S_CHANNEL_FMT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_MODE), MP_ROM_PTR(&mp_lv_I2S_MODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_CLK), MP_ROM_PTR(&mp_lv_I2S_CLK_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_MCLK_MULTIPLE), MP_ROM_PTR(&mp_lv_I2S_MCLK_MULTIPLE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_DAC_CHANNEL), MP_ROM_PTR(&mp_lv_I2S_DAC_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_PDM_DSR), MP_ROM_PTR(&mp_lv_I2S_PDM_DSR_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_PDM_SIG_SCALING), MP_ROM_PTR(&mp_lv_I2S_PDM_SIG_SCALING_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_NUM), MP_ROM_PTR(&mp_lv_I2S_NUM_type_base) },
    { MP_ROM_QSTR(MP_QSTR_I2S_EVENT), MP_ROM_PTR(&mp_lv_I2S_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_CHANNEL_LEVEL_ACTION), MP_ROM_PTR(&mp_lv_PCNT_CHANNEL_LEVEL_ACTION_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_CHANNEL_EDGE_ACTION), MP_ROM_PTR(&mp_lv_PCNT_CHANNEL_EDGE_ACTION_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_UNIT_COUNT_SIGN), MP_ROM_PTR(&mp_lv_PCNT_UNIT_COUNT_SIGN_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_PORT), MP_ROM_PTR(&mp_lv_PCNT_PORT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_UNIT), MP_ROM_PTR(&mp_lv_PCNT_UNIT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_CHANNEL), MP_ROM_PTR(&mp_lv_PCNT_CHANNEL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_PCNT_EVT), MP_ROM_PTR(&mp_lv_PCNT_EVT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_IF), MP_ROM_PTR(&mp_lv_ESP_IF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_MODE), MP_ROM_PTR(&mp_lv_WIFI_MODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_IF), MP_ROM_PTR(&mp_lv_WIFI_IF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_COUNTRY_POLICY), MP_ROM_PTR(&mp_lv_WIFI_COUNTRY_POLICY_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_AUTH), MP_ROM_PTR(&mp_lv_WIFI_AUTH_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_REASON), MP_ROM_PTR(&mp_lv_WIFI_REASON_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_SECOND_CHAN), MP_ROM_PTR(&mp_lv_WIFI_SECOND_CHAN_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_SCAN_TYPE), MP_ROM_PTR(&mp_lv_WIFI_SCAN_TYPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_CIPHER_TYPE), MP_ROM_PTR(&mp_lv_WIFI_CIPHER_TYPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_ANT), MP_ROM_PTR(&mp_lv_WIFI_ANT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI), MP_ROM_PTR(&mp_lv_WIFI_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_CONNECT_AP_BY), MP_ROM_PTR(&mp_lv_WIFI_CONNECT_AP_BY_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_PS), MP_ROM_PTR(&mp_lv_WIFI_PS_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_BW), MP_ROM_PTR(&mp_lv_WIFI_BW_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WPA3_SAE_PWE), MP_ROM_PTR(&mp_lv_WPA3_SAE_PWE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_STORAGE), MP_ROM_PTR(&mp_lv_WIFI_STORAGE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_VND_IE_TYPE), MP_ROM_PTR(&mp_lv_WIFI_VND_IE_TYPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_VND_IE_ID), MP_ROM_PTR(&mp_lv_WIFI_VND_IE_ID_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_PHY_MODE), MP_ROM_PTR(&mp_lv_WIFI_PHY_MODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_PKT), MP_ROM_PTR(&mp_lv_WIFI_PKT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_ANT_MODE), MP_ROM_PTR(&mp_lv_WIFI_ANT_MODE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_PHY_RATE), MP_ROM_PTR(&mp_lv_WIFI_PHY_RATE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_EVENT), MP_ROM_PTR(&mp_lv_WIFI_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_WPS_FAIL_REASON), MP_ROM_PTR(&mp_lv_WPS_FAIL_REASON_type_base) },
    { MP_ROM_QSTR(MP_QSTR_FTM_STATUS), MP_ROM_PTR(&mp_lv_FTM_STATUS_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_IP6_ADDR_IS), MP_ROM_PTR(&mp_lv_ESP_IP6_ADDR_IS_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_NETIF_DNS), MP_ROM_PTR(&mp_lv_ESP_NETIF_DNS_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_NETIF_DHCP), MP_ROM_PTR(&mp_lv_ESP_NETIF_DHCP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_NETIF_OP), MP_ROM_PTR(&mp_lv_ESP_NETIF_OP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_NETIF), MP_ROM_PTR(&mp_lv_ESP_NETIF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_IP_EVENT), MP_ROM_PTR(&mp_lv_IP_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_NETIF_IP_EVENT), MP_ROM_PTR(&mp_lv_ESP_NETIF_IP_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_EMAC_DATA_INTERFACE), MP_ROM_PTR(&mp_lv_EMAC_DATA_INTERFACE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_LINK), MP_ROM_PTR(&mp_lv_ETH_LINK_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_SPEED), MP_ROM_PTR(&mp_lv_ETH_SPEED_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_DUPLEX), MP_ROM_PTR(&mp_lv_ETH_DUPLEX_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_CHECKSUM), MP_ROM_PTR(&mp_lv_ETH_CHECKSUM_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_STATE), MP_ROM_PTR(&mp_lv_ETH_STATE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETH_CMD), MP_ROM_PTR(&mp_lv_ETH_CMD_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ETHERNET_EVENT), MP_ROM_PTR(&mp_lv_ETHERNET_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_EMAC_CLK), MP_ROM_PTR(&mp_lv_EMAC_CLK_type_base) },
    { MP_ROM_QSTR(MP_QSTR_EMAC), MP_ROM_PTR(&mp_lv_EMAC_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_MAC), MP_ROM_PTR(&mp_lv_ESP_MAC_type_base) },
    { MP_ROM_QSTR(MP_QSTR_CHIP), MP_ROM_PTR(&mp_lv_CHIP_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ESP_RST), MP_ROM_PTR(&mp_lv_ESP_RST_type_base) },
    { MP_ROM_QSTR(MP_QSTR_ERR), MP_ROM_PTR(&mp_lv_ERR_type_base) },
    { MP_ROM_QSTR(MP_QSTR_TCPIP_ADAPTER_IF), MP_ROM_PTR(&mp_lv_TCPIP_ADAPTER_IF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_MDNS_IP_PROTOCOL), MP_ROM_PTR(&mp_lv_MDNS_IP_PROTOCOL_type_base) },
    { MP_ROM_QSTR(MP_QSTR_MDNS_IF), MP_ROM_PTR(&mp_lv_MDNS_IF_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_EVENT), MP_ROM_PTR(&mp_lv_HTTP_EVENT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_TRANSPORT), MP_ROM_PTR(&mp_lv_HTTP_TRANSPORT_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_METHOD), MP_ROM_PTR(&mp_lv_HTTP_METHOD_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HTTP_AUTH_TYPE), MP_ROM_PTR(&mp_lv_HTTP_AUTH_TYPE_type_base) },
    { MP_ROM_QSTR(MP_QSTR_HttpStatus), MP_ROM_PTR(&mp_lv_HttpStatus_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SH2LIB_ERR), MP_ROM_PTR(&mp_lv_SH2LIB_ERR_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SH2LIB_NV_FLAG), MP_ROM_PTR(&mp_lv_SH2LIB_NV_FLAG_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SH2LIB_DATA_FLAG), MP_ROM_PTR(&mp_lv_SH2LIB_DATA_FLAG_type_base) },
    { MP_ROM_QSTR(MP_QSTR_SH2LIB_DATA_RECV), MP_ROM_PTR(&mp_lv_SH2LIB_DATA_RECV_type_base) },
    
    { MP_ROM_QSTR(MP_QSTR_C_Pointer), MP_ROM_PTR(&mp_C_Pointer_type) },
    { MP_ROM_QSTR(MP_QSTR__lv_mp_int_wrapper), MP_ROM_PTR(&mp__lv_mp_int_wrapper_type) },
    { MP_ROM_QSTR(MP_QSTR__lv_mp_char_ptr_wrapper), MP_ROM_PTR(&mp__lv_mp_char_ptr_wrapper_type) },
    { MP_ROM_QSTR(MP_QSTR_ip_addr_t), MP_ROM_PTR(&mp_ip_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_ip_addr_u_addr_t), MP_ROM_PTR(&mp_ip_addr_u_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_ip6_addr_t), MP_ROM_PTR(&mp_ip6_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_ip4_addr_t), MP_ROM_PTR(&mp_ip4_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_ip_addr_t), MP_ROM_PTR(&mp_esp_ip_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_ip_addr_u_addr_t), MP_ROM_PTR(&mp_esp_ip_addr_u_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_ip6_addr_t), MP_ROM_PTR(&mp_esp_ip6_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_ip4_addr_t), MP_ROM_PTR(&mp_esp_ip4_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_eth_phy_config_t), MP_ROM_PTR(&mp_eth_phy_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_config_t), MP_ROM_PTR(&mp_esp_http_client_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_http_client_event_t), MP_ROM_PTR(&mp_esp_http_client_event_t_type) },
    { MP_ROM_QSTR(MP_QSTR_spi_transaction_ext_t), MP_ROM_PTR(&mp_spi_transaction_ext_t_type) },
    { MP_ROM_QSTR(MP_QSTR_spi_transaction_t), MP_ROM_PTR(&mp_spi_transaction_t_type) },
    { MP_ROM_QSTR(MP_QSTR_gpio_config_t), MP_ROM_PTR(&mp_gpio_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_multi_heap_info_t), MP_ROM_PTR(&mp_multi_heap_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_init_config_t), MP_ROM_PTR(&mp_adc_digi_init_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_configuration_t), MP_ROM_PTR(&mp_adc_digi_configuration_t_type) },
    { MP_ROM_QSTR(MP_QSTR_adc_digi_pattern_config_t), MP_ROM_PTR(&mp_adc_digi_pattern_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_pcnt_config_t), MP_ROM_PTR(&mp_pcnt_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_mediator_t), MP_ROM_PTR(&mp_esp_eth_mediator_t_type) },
    { MP_ROM_QSTR(MP_QSTR_eth_mac_config_t), MP_ROM_PTR(&mp_eth_mac_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_eth_mac_clock_config_t), MP_ROM_PTR(&mp_eth_mac_clock_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_eth_mac_clock_config_mii_t), MP_ROM_PTR(&mp_eth_mac_clock_config_mii_t_type) },
    { MP_ROM_QSTR(MP_QSTR_eth_mac_clock_config_rmii_t), MP_ROM_PTR(&mp_eth_mac_clock_config_rmii_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_config_t), MP_ROM_PTR(&mp_esp_eth_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_mac_t), MP_ROM_PTR(&mp_esp_eth_mac_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_eth_phy_t), MP_ROM_PTR(&mp_esp_eth_phy_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_chip_info_t), MP_ROM_PTR(&mp_esp_chip_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_wifi_sta_list_t), MP_ROM_PTR(&mp_wifi_sta_list_t_type) },
    { MP_ROM_QSTR(MP_QSTR_wifi_sta_info_t), MP_ROM_PTR(&mp_wifi_sta_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_t), MP_ROM_PTR(&mp_esp_netif_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_config_t), MP_ROM_PTR(&mp_esp_netif_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_inherent_config_t), MP_ROM_PTR(&mp_esp_netif_inherent_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_ip_info_t), MP_ROM_PTR(&mp_esp_netif_ip_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_driver_ifconfig_t), MP_ROM_PTR(&mp_esp_netif_driver_ifconfig_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_netstack_config_t), MP_ROM_PTR(&mp_esp_netif_netstack_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_mdns_search_once_t), MP_ROM_PTR(&mp_mdns_search_once_t_type) },
    { MP_ROM_QSTR(MP_QSTR_mdns_result_t), MP_ROM_PTR(&mp_mdns_result_t_type) },
    { MP_ROM_QSTR(MP_QSTR_mdns_txt_item_t), MP_ROM_PTR(&mp_mdns_txt_item_t_type) },
    { MP_ROM_QSTR(MP_QSTR_mdns_ip_addr_t), MP_ROM_PTR(&mp_mdns_ip_addr_t_type) },
    { MP_ROM_QSTR(MP_QSTR_http_parser), MP_ROM_PTR(&mp_http_parser_type) },
    { MP_ROM_QSTR(MP_QSTR_http_parser_settings), MP_ROM_PTR(&mp_http_parser_settings_type) },
    { MP_ROM_QSTR(MP_QSTR_sh2lib_handle), MP_ROM_PTR(&mp_sh2lib_handle_type) },
    { MP_ROM_QSTR(MP_QSTR_nghttp2_session), MP_ROM_PTR(&mp_nghttp2_session_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_tls), MP_ROM_PTR(&mp_esp_tls_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_tls_cfg), MP_ROM_PTR(&mp_esp_tls_cfg_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_dns_info_t), MP_ROM_PTR(&mp_esp_netif_dns_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_sh2lib_nv), MP_ROM_PTR(&mp_sh2lib_nv_type) },
    { MP_ROM_QSTR(MP_QSTR_spi_bus_config_t), MP_ROM_PTR(&mp_spi_bus_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_spi_device_interface_config_t), MP_ROM_PTR(&mp_spi_device_interface_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_i2s_pin_config_t), MP_ROM_PTR(&mp_i2s_pin_config_t_type) },
    { MP_ROM_QSTR(MP_QSTR_i2s_pdm_tx_upsample_cfg_t), MP_ROM_PTR(&mp_i2s_pdm_tx_upsample_cfg_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_sta_list_t), MP_ROM_PTR(&mp_esp_netif_sta_list_t_type) },
    { MP_ROM_QSTR(MP_QSTR_esp_netif_sta_info_t), MP_ROM_PTR(&mp_esp_netif_sta_info_t_type) },
    { MP_ROM_QSTR(MP_QSTR_tcpip_adapter_ip_info_t), MP_ROM_PTR(&mp_tcpip_adapter_ip_info_t_type) },
    
    
    { MP_ROM_QSTR(MP_QSTR_esp_log_default_level), MP_ROM_PTR(&mp_esp_log_default_level) },
    { MP_ROM_QSTR(MP_QSTR_WIFI_EVENT), MP_ROM_PTR(&mp_WIFI_EVENT) },
    { MP_ROM_QSTR(MP_QSTR_IP_EVENT), MP_ROM_PTR(&mp_IP_EVENT) },
    { MP_ROM_QSTR(MP_QSTR_ETH_EVENT), MP_ROM_PTR(&mp_ETH_EVENT) },
    { MP_ROM_QSTR(MP_QSTR_ip_addr_any_type), MP_ROM_PTR(&mp_ip_addr_any_type) },
    { MP_ROM_QSTR(MP_QSTR_ip_addr_any), MP_ROM_PTR(&mp_ip_addr_any) },
    { MP_ROM_QSTR(MP_QSTR_ip_addr_broadcast), MP_ROM_PTR(&mp_ip_addr_broadcast) },
    { MP_ROM_QSTR(MP_QSTR_ip6_addr_any), MP_ROM_PTR(&mp_ip6_addr_any) },
    { MP_ROM_QSTR(MP_QSTR__nesting), MP_ROM_PTR(&mp__nesting) },
    
    { MP_ROM_QSTR(MP_QSTR_SPI_HOST), MP_ROM_PTR(MP_ROM_INT(ENUM_SPI_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_HSPI_HOST), MP_ROM_PTR(MP_ROM_INT(ENUM_HSPI_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_VSPI_HOST), MP_ROM_PTR(MP_ROM_INT(ENUM_VSPI_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_SPI1_HOST), MP_ROM_PTR(MP_ROM_INT(SPI1_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_SPI2_HOST), MP_ROM_PTR(MP_ROM_INT(SPI2_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_SPI3_HOST), MP_ROM_PTR(MP_ROM_INT(SPI3_HOST)) },
    { MP_ROM_QSTR(MP_QSTR_portMAX_DELAY), MP_ROM_PTR(MP_ROM_INT(ENUM_portMAX_DELAY)) },
    { MP_ROM_QSTR(MP_QSTR_I2S_PIN_NO_CHANGE), MP_ROM_PTR(MP_ROM_INT(ENUM_I2S_PIN_NO_CHANGE)) },
    
#ifdef LV_OBJ_T
    { MP_ROM_QSTR(MP_QSTR_LvReferenceError), MP_ROM_PTR(&mp_type_LvReferenceError) },
#endif // LV_OBJ_T
};


STATIC MP_DEFINE_CONST_DICT (
    mp_module_espidf_globals,
    espidf_globals_table
);

const mp_obj_module_t mp_module_espidf = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&mp_module_espidf_globals
};

MP_REGISTER_MODULE(MP_QSTR_espidf, mp_module_espidf);


