#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screentileview3;
lv_obj_t* image_21da;
lv_obj_t* swi_tile3_swi;
lv_obj_t* lab_tile3_rob;
lv_obj_t* ima_tile3_mo;
lv_obj_t* ima_tile3_mo_;
lv_obj_t* lab_tile3_mo;


    
void qmsd_image_21da_create()
{
    image_21da = lv_img_create(screentileview3, NULL);
    lv_img_set_src(image_21da, &imgtileview3_robot_png);
#ifdef BLOCKLY_image_21da_EVENT_HANDLER
    lv_obj_set_event_cb(image_21da, __qmsd_image_21da_cb);
#endif
    lv_obj_set_pos(image_21da, 32, 42);
    // lv_obj_set_click(image_21da,true);
    lv_obj_set_click(image_21da,false);
    lv_obj_set_style_local_image_recolor(image_21da,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_21da,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_21da,"image_21da");
}
    void qmsd_swi_tile3_swi_create()
{
    swi_tile3_swi = lv_switch_create(screentileview3, NULL);
    lv_obj_set_size(swi_tile3_swi, 40, 21);
    lv_obj_set_pos(swi_tile3_swi, 64, 120);
    if(0 == 0) {
    lv_switch_off(swi_tile3_swi, LV_ANIM_OFF);
    } else {
    lv_switch_on(swi_tile3_swi, LV_ANIM_OFF);
    }
    //set switch bg style
    lv_obj_set_style_local_bg_color(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_bg_grad_color(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xCC, 0xCC, 0xCC));
    lv_obj_set_style_local_pad_top(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile3_swi,LV_SWITCH_PART_BG,LV_STATE_DEFAULT,0);
    //set switch indic style
    lv_obj_set_style_local_bg_color(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_bg_grad_color(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x4a, 0x90, 0xe2));
    lv_obj_set_style_local_radius(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
    lv_obj_set_style_local_pad_top(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_bottom(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_left(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_pad_right(swi_tile3_swi,LV_SWITCH_PART_INDIC,LV_STATE_DEFAULT,0);
    //set switch knob style
    lv_obj_set_style_local_radius(swi_tile3_swi,LV_SWITCH_PART_KNOB,LV_STATE_DEFAULT,LV_RADIUS_CIRCLE);
#ifdef BLOCKLY_swi_tile3_swi_EVENT_HANDLER
    lv_obj_set_event_cb(swi_tile3_swi, __qmsd_swi_tile3_swi_cb);
#endif
    qmsd_obj_set_id(swi_tile3_swi,"swi_tile3_swi");

    lv_obj_set_ext_click_area(swi_tile3_swi, 20, 20, 20, 20);
}
    void qmsd_lab_tile3_rob_create()
{
	lab_tile3_rob = lv_label_create(screentileview3, NULL);
	lv_label_set_long_mode(lab_tile3_rob,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile3_rob,true);
	lv_obj_set_size(lab_tile3_rob, 86, 17);
//set label style
	lv_obj_set_style_local_text_color(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile3_rob, "扫地机器人");
	lv_label_set_align(lab_tile3_rob, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_17);
#ifdef BLOCKLY_lab_tile3_rob_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile3_rob, __qmsd_lab_tile3_rob_cb);
#endif
	if(lab_tile3_rob->coords.x2-lab_tile3_rob->coords.x1<86)
	{
		int x_offset=(86-(lab_tile3_rob->coords.x2-lab_tile3_rob->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile3_rob->coords.y2-lab_tile3_rob->coords.y1<17)
	{
		int y_offset=(17-(lab_tile3_rob->coords.y2-lab_tile3_rob->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile3_rob,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile3_rob, 59, 61);
    qmsd_obj_set_id(lab_tile3_rob,"lab_tile3_rob");
}
    
void qmsd_ima_tile3_mo_create()
{
    ima_tile3_mo = lv_img_create(screentileview3, NULL);
    lv_img_set_src(ima_tile3_mo, &imgtileview3_button_more_png);
#ifdef BLOCKLY_ima_tile3_mo_EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile3_mo, __qmsd_ima_tile3_mo_cb);
#endif
    lv_obj_set_pos(ima_tile3_mo, 273, 40);
    lv_obj_set_click(ima_tile3_mo,true);
    lv_obj_set_style_local_image_recolor(ima_tile3_mo,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile3_mo,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile3_mo,"ima_tile3_mo");
}
    
void qmsd_ima_tile3_mo__create()
{
    ima_tile3_mo_ = lv_img_create(screentileview3, NULL);
    lv_img_set_src(ima_tile3_mo_, &imgtileview3_more_png);
#ifdef BLOCKLY_ima_tile3_mo__EVENT_HANDLER
    lv_obj_set_event_cb(ima_tile3_mo_, __qmsd_ima_tile3_mo__cb);
#endif
    lv_obj_set_pos(ima_tile3_mo_, 346, 78);
    lv_obj_set_click(ima_tile3_mo_,true);
    lv_obj_set_style_local_image_recolor(ima_tile3_mo_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_tile3_mo_,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_tile3_mo_,"ima_tile3_mo_");
}
    void qmsd_lab_tile3_mo_create()
{
	lab_tile3_mo = lv_label_create(screentileview3, NULL);
	lv_label_set_long_mode(lab_tile3_mo,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_tile3_mo,true);
	lv_obj_set_size(lab_tile3_mo, 53, 13);
//set label style
	lv_obj_set_style_local_text_color(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_tile3_mo, "添加设备");
	lv_label_set_align(lab_tile3_mo, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_13);
#ifdef BLOCKLY_lab_tile3_mo_EVENT_HANDLER
	lv_obj_set_event_cb(lab_tile3_mo, __qmsd_lab_tile3_mo_cb);
#endif
    lv_obj_set_click(lab_tile3_mo,true);    
	if(lab_tile3_mo->coords.x2-lab_tile3_mo->coords.x1<53)
	{
		int x_offset=(53-(lab_tile3_mo->coords.x2-lab_tile3_mo->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_tile3_mo->coords.y2-lab_tile3_mo->coords.y1<13)
	{
		int y_offset=(13-(lab_tile3_mo->coords.y2-lab_tile3_mo->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_tile3_mo,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_tile3_mo, 332, 118);
    qmsd_obj_set_id(lab_tile3_mo,"lab_tile3_mo");
}

static void screentileview3_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_tile3_rob,qmsd_lang_get_trans("lab_tile3_rob","扫地机器人"));
    lv_label_set_text(lab_tile3_mo,qmsd_lang_get_trans("lab_tile3_mo","添加设备"));
*/
#ifdef BLOCKLY_screentileview3_SCREEN_INIT
    __qmsd_screentileview3_init();
#endif
}

void screentileview3_tileview_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screentileview3 = NULL;
        qmsd_screen_remove("screentileview3");
    }
}

void screentileview3_build(void)
{
    if(screentileview3) return;
    screentileview3 = lv_obj_create(tile_main,NULL);
    lv_obj_qmsd_set_cb(screentileview3, screentileview3_qmsd_cb);
    lv_obj_set_size(screentileview3,480,480);
    lv_obj_set_pos(screentileview3,2*LV_HOR_RES,0*LV_VER_RES);
    lv_obj_set_event_cb(screentileview3,screentileview3_tileview_cb);
    lv_obj_set_style_local_bg_color(screentileview3,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));
    lv_obj_set_style_local_border_width(screentileview3,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_radius(screentileview3,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,0);
    qmsd_image_21da_create();
    lv_tileview_add_element(tile_main, image_21da);
    qmsd_swi_tile3_swi_create();
    lv_tileview_add_element(tile_main, swi_tile3_swi);
    qmsd_lab_tile3_rob_create();
    lv_tileview_add_element(tile_main, lab_tile3_rob);
    qmsd_ima_tile3_mo_create();
    lv_tileview_add_element(tile_main, ima_tile3_mo);
    qmsd_ima_tile3_mo__create();
    lv_tileview_add_element(tile_main, ima_tile3_mo_);
    qmsd_lab_tile3_mo_create();
    lv_tileview_add_element(tile_main, lab_tile3_mo);
    lv_tileview_add_element(tile_main, screentileview3);
    qmsd_screen_register(screentileview3,"screentileview3");
}

void screentileview3_show(void)
{
    lv_tileview_set_tile_act(tile_main,2,0,LV_ANIM_ON);
}


void screentileview3_delete(void)
{

}
