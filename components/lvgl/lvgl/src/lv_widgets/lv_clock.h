/**
 * @file lv_clock.h
 *
 */

#ifndef LV_CLOCK_H
#define LV_CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"

     /*Data of arc*/
    typedef struct {
        /*New data for this type */
        uint16_t smooth_move;
        uint16_t skey_x_offset;
        uint16_t skey_y_offset;
        uint16_t mkey_x_offset;
        uint16_t mkey_y_offset;
        uint16_t hkey_x_offset;
        uint16_t hkey_y_offset;

        uint16_t fps;

        uint16_t hour_count;
        uint16_t min_count;
        uint16_t sec_count;

        lv_obj_t* base;
        lv_obj_t* sec_pin;
        lv_obj_t* min_pin;
        lv_obj_t* hour_pin;

        lv_task_t* spin_task;
    } lv_clock_ext_t;

    enum 
    {
        QMSD_CLOCK_SMOOTH,
        QMSD_CLOCK_TIK,
    };
    lv_obj_t* lv_clock_create(lv_obj_t* par, const lv_obj_t* copy);
    void lv_clock_set_time(lv_obj_t* obj, int hour, int min, int sec);
    void lv_clock_init(lv_obj_t* clock, const void* bg, const void* sec, const void* min, const void* hour, int s_x, int s_y, int m_x, int m_y, int h_x, int h_y);
    void lv_clock_set_mode(lv_obj_t* obj, uint8_t mode);
    void lv_clock_run(lv_obj_t* obj);
    void lv_clock_stop(lv_obj_t* obj);
    bool lv_clock_get_state(lv_obj_t* obj);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CONT_H*/
