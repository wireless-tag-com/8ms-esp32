/**
 * @file lv_clock.h
 *
 */

#ifndef QMSD_EFFECT_H
#define QMSD_EFFECT_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"
#include "../lv_core/lv_disp.h"
    enum QMSD_EFFECT_DIR
    {
        QMSD_TOP=1,
        QMSD_BOT,
        QMSD_LEFT,
        QMSD_RIGHT,
    };
    
    void qmsd_slide_in(lv_obj_t* in, uint16_t way, int time);
    void qmsd_slide_out(lv_obj_t* out, uint16_t way, int time);
    int qmsd_get_gesture();
    void qmsd_obj_set_pos_ori(lv_obj_t* obj,int x,int y);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CONT_H*/

