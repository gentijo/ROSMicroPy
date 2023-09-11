
#include "mp_uros_thread.h"

void init_ROS_Main_Task();

STATIC void *ros_thread_entry(void *args_in)
{
    printf("\r\nStarting ROS Thread");

    // Execution begins here for a new thread.  We do not have the GIL.
    ros_thread_entry_args_t *args = (ros_thread_entry_args_t *)args_in;

    mp_state_thread_t ts;
    mp_thread_set_state(&ts);

    mp_stack_set_top(&ts + 1); // need to include ts in root-pointer scan
    mp_stack_set_limit(args->stack_size);

#if MICROPY_ENABLE_PYSTACK
    // TODO threading and pystack is not fully supported, for now just make a small stack
    mp_obj_t mini_pystack[128];
    mp_pystack_init(mini_pystack, &mini_pystack[128]);
#endif

    // The GC starts off unlocked on this thread.
    ts.gc_lock_depth = 0;

    ts.mp_pending_exception = MP_OBJ_NULL;

    // set locals and globals from the calling context
    mp_locals_set(args->dict_locals);
    mp_globals_set(args->dict_globals);


    MP_THREAD_GIL_ENTER();

    // signal that we are set up and running
    mp_thread_start();

    // TODO set more thread-specific state here:
    //  cur_exception (root pointer)

    //DEBUG_printf("[thread] start ts=%p args=%p stack=%p\n", &ts, &args, MP_STATE_THREAD(stack_top));
    MP_THREAD_GIL_EXIT();

    //args->fun_ptr();
    //ROS_Main_Task_Loop();

    init_ROS_Main_Task();

    // signal that we are finished
    mp_thread_finish();

    return NULL;
}

mp_obj_t start_new_ROS_thread(void (*entry_point_fun)())
{   
    ros_thread_entry_args_t *th_args = malloc(sizeof(ros_thread_entry_args_t));

    // pass our locals and globals into the new thread
    th_args->dict_locals = mp_locals_get();
    th_args->dict_globals = mp_globals_get();

    // set the stack size to use
    th_args->stack_size = CONFIG_MICRO_ROS_APP_STACK;

    // set the function for thread entry
    th_args->fun_ptr = entry_point_fun;

    // spawn the thread!
    mp_thread_create(ros_thread_entry, th_args, &th_args->stack_size);

    return mp_const_none;
}

mp_obj_t init_ROS_System() {
 
	printf("\r\nInitializing ROS Stack\r\n");
	//init_ROS_Main_Task();
    start_new_ROS_thread(ROS_Main_Task_Loop);  
    return mp_const_none;
  
}


//  MP_THREAD_GIL_ENTER();
// nlr_buf_t nlr;
// if (nlr_push(&nlr) == 0)
// {
//     mp_call_function_n_kw(args->fun, args->n_args, args->n_kw, args->args);
//     nlr_pop();
// }
// else
// {
//     // uncaught exception
//     // check for SystemExit
//     mp_obj_base_t *exc = (mp_obj_base_t *)nlr.ret_val;
//     if (mp_obj_is_subclass_fast(MP_OBJ_FROM_PTR(exc->type), MP_OBJ_FROM_PTR(&mp_type_SystemExit)))
//     {
//         // swallow exception silently
//     }
//     else
//     {
//         // print exception out
//         mp_printf(MICROPY_ERROR_PRINTER, "Unhandled exception in thread started by ");
//         mp_obj_print_helper(MICROPY_ERROR_PRINTER, args->fun, PRINT_REPR);
//         mp_printf(MICROPY_ERROR_PRINTER, "\n");
//         mp_obj_print_exception(MICROPY_ERROR_PRINTER, MP_OBJ_FROM_PTR(exc));
//     }
// }
//  MP_THREAD_GIL_EXIT();