#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* scr_equipment;
lv_obj_t* ima_equ_re;
lv_obj_t* lab_equ_re;
lv_obj_t* ima_equ_load;
lv_obj_t* ima_equ_smi;
lv_obj_t* lab_equ_lab;
lv_obj_t* label_b479;


    
void qmsd_ima_equ_re_create()
{
    ima_equ_re = lv_img_create(scr_equipment, NULL);
    lv_img_set_src(ima_equ_re, &imgchoice_return_png);
#ifdef BLOCKLY_ima_equ_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_equ_re, __qmsd_ima_equ_re_cb);
#endif
    lv_obj_set_pos(ima_equ_re, 44, 42);
    lv_obj_set_click(ima_equ_re,true);
    lv_obj_set_style_local_image_recolor(ima_equ_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_equ_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_equ_re,"ima_equ_re");
}
    void qmsd_lab_equ_re_create()
{
	lab_equ_re = lv_label_create(scr_equipment, NULL);
	lv_label_set_long_mode(lab_equ_re,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_equ_re,true);
	lv_obj_set_size(lab_equ_re, 98, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_equ_re, "添加设备");
	lv_label_set_align(lab_equ_re, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_equ_re_EVENT_HANDLER
	lv_obj_set_event_cb(lab_equ_re, __qmsd_lab_equ_re_cb);
#endif
    lv_obj_set_click(lab_equ_re,true);    
	if(lab_equ_re->coords.x2-lab_equ_re->coords.x1<98)
	{
		int x_offset=(98-(lab_equ_re->coords.x2-lab_equ_re->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_equ_re->coords.y2-lab_equ_re->coords.y1<23)
	{
		int y_offset=(23-(lab_equ_re->coords.y2-lab_equ_re->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_equ_re,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_equ_re, 76, 42);
    qmsd_obj_set_id(lab_equ_re,"lab_equ_re");

	lv_obj_set_ext_click_area(lab_equ_re, 50, 20, 50, 20);
}
    
void qmsd_ima_equ_load_create()
{
    ima_equ_load = lv_img_create(scr_equipment, NULL);
    lv_img_set_src(ima_equ_load, &imgequipment_load_png);
#ifdef BLOCKLY_ima_equ_load_EVENT_HANDLER
    lv_obj_set_event_cb(ima_equ_load, __qmsd_ima_equ_load_cb);
#endif
    lv_obj_set_pos(ima_equ_load, 90, 159);
    qmsd_obj_set_id(ima_equ_load,"ima_equ_load");
}
    
void qmsd_ima_equ_smi_create()
{
    ima_equ_smi = lv_img_create(scr_equipment, NULL);
    lv_img_set_src(ima_equ_smi, &imgequipment_smile_png);
#ifdef BLOCKLY_ima_equ_smi_EVENT_HANDLER
    lv_obj_set_event_cb(ima_equ_smi, __qmsd_ima_equ_smi_cb);
#endif
    lv_obj_set_pos(ima_equ_smi, 178, 188);
    qmsd_obj_set_id(ima_equ_smi,"ima_equ_smi");
}
    void qmsd_lab_equ_lab_create()
{
	lab_equ_lab = lv_label_create(scr_equipment, NULL);
	lv_label_set_long_mode(lab_equ_lab,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_equ_lab,true);
	lv_obj_set_size(lab_equ_lab, 174, 19);
//set label style
	lv_obj_set_style_local_text_color(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_equ_lab, "小明正在搜索设备...");
	lv_label_set_align(lab_equ_lab, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_20);
#ifdef BLOCKLY_lab_equ_lab_EVENT_HANDLER
	lv_obj_set_event_cb(lab_equ_lab, __qmsd_lab_equ_lab_cb);
#endif
	if(lab_equ_lab->coords.x2-lab_equ_lab->coords.x1<174)
	{
		int x_offset=(174-(lab_equ_lab->coords.x2-lab_equ_lab->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_equ_lab->coords.y2-lab_equ_lab->coords.y1<19)
	{
		int y_offset=(19-(lab_equ_lab->coords.y2-lab_equ_lab->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_equ_lab,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_equ_lab, 156, 392);
    qmsd_obj_set_id(lab_equ_lab,"lab_equ_lab");
}
    void qmsd_label_b479_create()
{
	label_b479 = lv_label_create(scr_equipment, NULL);
	lv_label_set_long_mode(label_b479,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_b479,true);
	lv_obj_set_size(label_b479, 152, 18);
//set label style
	lv_obj_set_style_local_text_color(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_b479, "功能未开发，请返回");
	lv_label_set_align(label_b479, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_b479_EVENT_HANDLER
	lv_obj_set_event_cb(label_b479, __qmsd_label_b479_cb);
#endif
	if(label_b479->coords.x2-label_b479->coords.x1<152)
	{
		int x_offset=(152-(label_b479->coords.x2-label_b479->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_b479->coords.y2-label_b479->coords.y1<18)
	{
		int y_offset=(18-(label_b479->coords.y2-label_b479->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_b479,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_b479, 168, 85);
    qmsd_obj_set_id(label_b479,"label_b479");
}

static void scr_equipment_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_equ_re,qmsd_lang_get_trans("lab_equ_re","添加设备"));
    lv_label_set_text(lab_equ_lab,qmsd_lang_get_trans("lab_equ_lab","小明正在搜索设备..."));
    lv_label_set_text(label_b479,qmsd_lang_get_trans("label_b479","功能未开发，请返回"));
*/
#ifdef BLOCKLY_scr_equipment_SCREEN_INIT
    __qmsd_scr_equipment_init();
#endif
}

static void scr_equipment_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        scr_equipment=NULL;
        qmsd_screen_remove("scr_equipment");
    }
}

void scr_equipment_build(void)
{
    if(scr_equipment) return;
    scr_equipment = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(scr_equipment, scr_equipment_qmsd_cb);
    lv_obj_set_style_local_bg_color(scr_equipment,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_ima_equ_re_create();
    qmsd_lab_equ_re_create();
    qmsd_ima_equ_load_create();
    qmsd_ima_equ_smi_create();
    qmsd_lab_equ_lab_create();
    qmsd_label_b479_create();
    lv_obj_set_event_cb(scr_equipment,scr_equipment_del_cb);
    qmsd_screen_register(scr_equipment,"scr_equipment");
}

void scr_equipment_show(void)
{
    if(!scr_equipment)
    {
        scr_equipment_build();
    }
    lv_scr_load(scr_equipment);
}

void scr_equipment_delete(void)
{
    if(scr_equipment)
    {
        lv_obj_del(scr_equipment);
        scr_equipment = NULL;
    }
}
