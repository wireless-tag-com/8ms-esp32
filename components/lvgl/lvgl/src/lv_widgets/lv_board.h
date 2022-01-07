/**
 * @file lv_clock.h
 *
 */

#ifndef LV_BOARD_H
#define LV_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

    /*********************
     *      INCLUDES
     *********************/

#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"
#include "lv_page.h"
#include "lv_cont.h"
#include "lv_label.h"
    typedef struct {
        /*New data for this type */
        int cont_max; //amount
        int cont_now; //now to be created
        int cont_h; 
        int cont_w;
        int board_limit; //num in per row/cow
        int inner_pad;
        int anime;
        lv_color_t color;

        lv_obj_t* page_in;
        lv_obj_t* cont[64];

    } lv_board_ext_t;

    int qmsd_board_get_index(lv_obj_t* board);
    void qmsd_board_set_cont_color(lv_obj_t* board,lv_color_t bg_color);
    lv_obj_t* qmsd_board_create(lv_obj_t* par, const lv_obj_t* copy);
    lv_obj_t* qmsd_board_add_cont(lv_obj_t* board);
    void qmsd_board_add_prepared_cont(lv_obj_t* board, lv_obj_t* cont);
    void qmsd_board_set_cont_size(lv_obj_t* board,int w,int h);
    lv_obj_t* qmsd_board_get_cont(lv_obj_t* board,int index);
    void qmsd_board_del_cont(lv_obj_t* board);
    lv_obj_t* qmsd_board_get_page(lv_obj_t* board);
    void qmsd_board_clean(lv_obj_t* board);
    void qmsd_board_set_break(lv_obj_t* board,int num);
    void qmsd_board_del_cont_index(lv_obj_t* board, int index);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif
