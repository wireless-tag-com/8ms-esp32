/**
 * @file lv_clock.h
 *
 */

#ifndef LV_8MS_EFFECT_H
#define LV_8MS_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"
#include "../lv_core/lv_disp.h"
    enum LV_8MS_EFFECT_DIR
    {
        LV_8MS_TOP=1,
        LV_8MS_BOT,
        LV_8MS_LEFT,
        LV_8MS_RIGHT,
    };
    
    void lv_8ms_slide_in(lv_obj_t* in, uint16_t way, int time);
    void lv_8ms_slide_out(lv_obj_t* out, uint16_t way, int time);
    int lv_8ms_get_gesture();
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CONT_H*/

