#ifndef __QMSD_INTERNEL_UI_CB_H
#define __QMSD_INTERNEL_UI_CB_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  

#define BLOCKLY_ima_tile1_mi_EVENT_HANDLER
void __qmsd_ima_tile1_mi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile1_mi__EVENT_HANDLER
void __qmsd_ima_tile1_mi__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile1_le_EVENT_HANDLER
void __qmsd_ima_tile1_le_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_tile1_le_EVENT_HANDLER
void __qmsd_lab_tile1_le_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_tile1_mi_EVENT_HANDLER
void __qmsd_lab_tile1_mi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile1_le__EVENT_HANDLER
void __qmsd_ima_tile1_le__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_one_EVENT_HANDLER
void __qmsd_ima_tile2_one_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile1_ri_EVENT_HANDLER
void __qmsd_ima_tile1_ri_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_two_EVENT_HANDLER
void __qmsd_ima_tile2_two_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_cont_EVENT_HANDLER
void __qmsd_screen_cont_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile1_ri__EVENT_HANDLER
void __qmsd_ima_tile1_ri__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_thr_EVENT_HANDLER
void __qmsd_ima_tile2_thr_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_tile1_ri_EVENT_HANDLER
void __qmsd_lab_tile1_ri_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_fou_EVENT_HANDLER
void __qmsd_ima_tile2_fou_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_main_SCREEN_INIT
void __qmsd_screen_main_init(void);

#define BLOCKLY_screentileview3_EVENT_HANDLER
void __qmsd_screentileview3_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screentileview1_EVENT_HANDLER
void __qmsd_screentileview1_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_cu_EVENT_HANDLER
void __qmsd_ima_tile2_cu_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_pr_EVENT_HANDLER
void __qmsd_ima_tile2_pr_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_op_EVENT_HANDLER
void __qmsd_ima_cur_op_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_ai_EVENT_HANDLER
void __qmsd_ima_tile2_ai_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_co_EVENT_HANDLER
void __qmsd_ima_air_co_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_op__EVENT_HANDLER
void __qmsd_ima_cur_op__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_saver_SCREEN_INIT
void __qmsd_screen_saver_init(void);

#define BLOCKLY_ima_tile2_ne_EVENT_HANDLER
void __qmsd_ima_tile2_ne_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screentileview2_EVENT_HANDLER
void __qmsd_screentileview2_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_sun_EVENT_HANDLER
void __qmsd_ima_air_sun_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_cl_EVENT_HANDLER
void __qmsd_ima_cur_cl_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_re_EVENT_HANDLER
void __qmsd_ima_air_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_but_tile2_pr_EVENT_HANDLER
void __qmsd_but_tile2_pr_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_lo_EVENT_HANDLER
void __qmsd_ima_air_lo_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cho_re_EVENT_HANDLER
void __qmsd_ima_cho_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_air_re_EVENT_HANDLER
void __qmsd_lab_air_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_mi_EVENT_HANDLER
void __qmsd_ima_air_mi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_cho_re_EVENT_HANDLER
void __qmsd_lab_cho_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_le_EVENT_HANDLER
void __qmsd_ima_tile2_le_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_cl__EVENT_HANDLER
void __qmsd_ima_cur_cl__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_re_EVENT_HANDLER
void __qmsd_ima_cur_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_air_hi_EVENT_HANDLER
void __qmsd_ima_air_hi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_but_tile2_ne_EVENT_HANDLER
void __qmsd_but_tile2_ne_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_ri_EVENT_HANDLER
void __qmsd_ima_tile2_ri_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_cur_le_EVENT_HANDLER
void __qmsd_lab_cur_le_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_swi_air_swi_EVENT_HANDLER
void __qmsd_swi_air_swi_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_st_EVENT_HANDLER
void __qmsd_ima_tile2_st_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_image_saver_bot_EVENT_HANDLER
void __qmsd_image_saver_bot_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_cur_ri_EVENT_HANDLER
void __qmsd_lab_cur_ri_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_on_EVENT_HANDLER
void __qmsd_ima_cur_on_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_swi_tile2_ai_EVENT_HANDLER
void __qmsd_swi_tile2_ai_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile2_stb_EVENT_HANDLER
void __qmsd_ima_tile2_stb_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_on__EVENT_HANDLER
void __qmsd_ima_cur_on__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_con_re_EVENT_HANDLER
void __qmsd_ima_con_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_con_re_EVENT_HANDLER
void __qmsd_lab_con_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_st_EVENT_HANDLER
void __qmsd_ima_cur_st_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_con_set_EVENT_HANDLER
void __qmsd_ima_con_set_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_wif_re_EVENT_HANDLER
void __qmsd_lab_wif_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_con_set_EVENT_HANDLER
void __qmsd_lab_con_set_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_tileview_SCREEN_INIT
void __qmsd_screen_tileview_init(void);

#define BLOCKLY_ima_tile3_mo_EVENT_HANDLER
void __qmsd_ima_tile3_mo_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_cur_st__EVENT_HANDLER
void __qmsd_ima_cur_st__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_set_re_EVENT_HANDLER
void __qmsd_ima_set_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_tile3_mo__EVENT_HANDLER
void __qmsd_ima_tile3_mo__cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_ima_con_mor_EVENT_HANDLER
void __qmsd_ima_con_mor_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_tile3_mo_EVENT_HANDLER
void __qmsd_lab_tile3_mo_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_lab_con_mor_EVENT_HANDLER
void __qmsd_lab_con_mor_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_choice_SCREEN_INIT
void __qmsd_screen_choice_init(void);

#define BLOCKLY_scr_curtain_ti1_SCREEN_INIT
void __qmsd_scr_curtain_ti1_init(void);

#define BLOCKLY_screen_air_SCREEN_INIT
void __qmsd_screen_air_init(void);

#define BLOCKLY_ima_equ_re_EVENT_HANDLER
void __qmsd_ima_equ_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_screen_set_SCREEN_INIT
void __qmsd_screen_set_init(void);

#define BLOCKLY_lab_equ_re_EVENT_HANDLER
void __qmsd_lab_equ_re_cb(lv_obj_t* obj,lv_event_t event);

#define BLOCKLY_scr_equipment_SCREEN_INIT
void __qmsd_scr_equipment_init(void);

#define BLOCKLY_screen_wifi_set_SCREEN_INIT
void __qmsd_screen_wifi_set_init(void);

#define BLOCKLY_screen_input_SCREEN_INIT
void __qmsd_screen_input_init(void);


extern float get_tem_data;
extern float get_hum_data;


// lv_task_t* tileview1_tem_hum;
// void tileview1_tem_hum_cb(lv_task_t* t);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_INTERNEL_UI_CB_H