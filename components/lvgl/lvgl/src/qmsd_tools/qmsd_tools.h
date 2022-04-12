/**
 * @file lv_clock.h
 *
 */

#ifndef QMSD_TOOLS_H
#define QMSD_TOOLS_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/
#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"
#include "../lv_core/lv_disp.h"

typedef enum 
{
    QMSD_TOP=1,
    QMSD_BOT,
    QMSD_LEFT,
    QMSD_RIGHT,
} qmsd_effect_dir_t;

/**
 * @brief gei x coords of an obj
 * 
 * @param obj 
 * @return int 
 */
int qmsd_obj_get_x_ori(lv_obj_t* obj);

/**
 * @brief Slide in a widget to screen active now
 * 
 * @param in obj to slide
 * @param way direction of animation
 * @param time duration of animation in ms
 */
void qmsd_slide_in(lv_obj_t* in, qmsd_effect_dir_t way, int time);

/**
 * @brief slide out a widget from screen active now
 * 
 * @param out obj to slide
 * @param way direction of animation
 * @param time duration of animation in ms
 */
void qmsd_slide_out(lv_obj_t* out, qmsd_effect_dir_t way, int time);

/**
 * @brief get dir pointer move
 * 
 * @return qmsd_effect_dir_t 
 */
qmsd_effect_dir_t qmsd_get_gesture(void);

/**
 * @brief set widgets' ori coords
 * 
 * @param obj 
 * @param x 
 * @param y 
 */
void qmsd_obj_set_pos_ori(lv_obj_t* obj,int x,int y);

/**
 * @brief 
 * 
 * @param bkl_pin 
 * @param time 
 * @param bkl_level 
 */
void qmsd_board_sleep_init(int bkl_pin,int time,int bkl_level);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CONT_H*/

