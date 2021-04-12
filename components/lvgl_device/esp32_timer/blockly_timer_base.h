#ifndef BLOCKLY_TIMER_BASE_H
#define BLOCKLY_TIMER_BASE_H

#ifdef __cplusplus
extern "C"
{
#endif
    /*********************
     *      INCLUDES
     *********************/

#include "blockly_timer.h"

    /*********************
     *      DEFINES
     *********************/

    /**********************
     *      TYPEDEFS
     **********************/

    /**********************
     * GLOBAL PROTOTYPES
     **********************/

    /**********************
     *      MACROS
     **********************/

    esp_timer_handle_t *__lv_8ms_timer_init(char *name, esp_timer_cb_t call_back);
    void __lv_8ms_timer_start(esp_timer_handle_t *timer_handle, uint64_t timeout_us, timer_mode mode);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif