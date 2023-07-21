#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_set;
lv_obj_t* lab_set_set;
lv_obj_t* ima_set_re;


    void qmsd_lab_set_set_create()
{
	lab_set_set = lv_label_create(screen_set, NULL);
	lv_label_set_long_mode(lab_set_set,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(lab_set_set,true);
	lv_obj_set_size(lab_set_set, 48, 23);
//set label style
	lv_obj_set_style_local_text_color(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(lab_set_set, "设置");
	lv_label_set_align(lab_set_set, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_24);
#ifdef BLOCKLY_lab_set_set_EVENT_HANDLER
	lv_obj_set_event_cb(lab_set_set, __qmsd_lab_set_set_cb);
#endif
	if(lab_set_set->coords.x2-lab_set_set->coords.x1<48)
	{
		int x_offset=(48-(lab_set_set->coords.x2-lab_set_set->coords.x1))/2;
		lv_obj_set_style_local_pad_left(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(lab_set_set->coords.y2-lab_set_set->coords.y1<23)
	{
		int y_offset=(23-(lab_set_set->coords.y2-lab_set_set->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(lab_set_set,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(lab_set_set, 40, 32);
    qmsd_obj_set_id(lab_set_set,"lab_set_set");
}
    
void qmsd_ima_set_re_create()
{
    ima_set_re = lv_img_create(screen_set, NULL);
    lv_img_set_src(ima_set_re, &imglist_delete_png);
#ifdef BLOCKLY_ima_set_re_EVENT_HANDLER
    lv_obj_set_event_cb(ima_set_re, __qmsd_ima_set_re_cb);
#endif
    lv_obj_set_pos(ima_set_re, 428, 30);
    lv_obj_set_click(ima_set_re,true);
    lv_obj_set_style_local_image_recolor(ima_set_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(ima_set_re,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(ima_set_re,"ima_set_re");
}

static void screen_set_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(lab_set_set,qmsd_lang_get_trans("lab_set_set","设置"));
*/
#ifdef BLOCKLY_screen_set_SCREEN_INIT
    __qmsd_screen_set_init();
#endif
}

static void screen_set_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_set=NULL;
        qmsd_screen_remove("screen_set");
    }
}

void screen_set_build(void)
{
    if(screen_set) return;
    screen_set = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_set, screen_set_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_set,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x20, 0x20, 0x20));

    qmsd_lab_set_set_create();
    qmsd_ima_set_re_create();
    lv_obj_set_event_cb(screen_set,screen_set_del_cb);
    qmsd_screen_register(screen_set,"screen_set");
}

void screen_set_show(void)
{
    if(!screen_set)
    {
        screen_set_build();
    }
    lv_scr_load(screen_set);
}

void screen_set_delete(void)
{
    if(screen_set)
    {
        lv_obj_del(screen_set);
        screen_set = NULL;
    }
}
