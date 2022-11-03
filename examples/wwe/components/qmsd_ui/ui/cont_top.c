#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* cont_top;
lv_obj_t* image_e005;
lv_obj_t* label_0bb8;
lv_obj_t* image_top_home;
lv_obj_t* image_top_set;
lv_obj_t* image_top_mode;


    
void qmsd_image_e005_create()
{
    image_e005 = lv_img_create(cont_top, NULL);
    lv_img_set_src(image_e005, &imgwifi_3_png);
#ifdef BLOCKLY_image_e005_EVENT_HANDLER
    lv_obj_set_event_cb(image_e005, __qmsd_image_e005_cb);
#endif
    lv_obj_set_pos(image_e005, 15, 244);
    qmsd_obj_set_id(image_e005,"image_e005");
}
    void qmsd_label_0bb8_create()
{
	label_0bb8 = lv_label_create(cont_top, NULL);
	lv_label_set_long_mode(label_0bb8,LV_LABEL_LONG_EXPAND);
	lv_label_set_recolor(label_0bb8,true);
	lv_obj_set_size(label_0bb8, 100, 40);
//set label style
	lv_obj_set_style_local_text_color(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));

	lv_label_set_text(label_0bb8, "晴  21℃");
	lv_label_set_align(label_0bb8, LV_LABEL_ALIGN_CENTER);
	lv_obj_set_style_local_text_font(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
#ifdef BLOCKLY_label_0bb8_EVENT_HANDLER
	lv_obj_set_event_cb(label_0bb8, __qmsd_label_0bb8_cb);
#endif
	if(label_0bb8->coords.x2-label_0bb8->coords.x1<100)
	{
		int x_offset=(100-(label_0bb8->coords.x2-label_0bb8->coords.x1))/2;
		lv_obj_set_style_local_pad_left(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
		lv_obj_set_style_local_pad_right(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,x_offset);
	}
	if(label_0bb8->coords.y2-label_0bb8->coords.y1<40)
	{
		int y_offset=(40-(label_0bb8->coords.y2-label_0bb8->coords.y1))/2;
		lv_obj_set_style_local_pad_bottom(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
		lv_obj_set_style_local_pad_top(label_0bb8,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,y_offset);
	}
	lv_obj_set_pos(label_0bb8, 380, 238);
    qmsd_obj_set_id(label_0bb8,"label_0bb8");
}
    
void qmsd_image_top_home_create()
{
    image_top_home = lv_img_create(cont_top, NULL);
    lv_img_set_src(image_top_home, &imgtop_home_png);
#ifdef BLOCKLY_image_top_home_EVENT_HANDLER
    lv_obj_set_event_cb(image_top_home, __qmsd_image_top_home_cb);
#endif
    lv_obj_set_pos(image_top_home, 74, 90);
    lv_obj_set_click(image_top_home,true);
    lv_obj_set_style_local_image_recolor(image_top_home,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_top_home,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_top_home,"image_top_home");
}
    
void qmsd_image_top_set_create()
{
    image_top_set = lv_img_create(cont_top, NULL);
    lv_img_set_src(image_top_set, &imgtop_set_png);
#ifdef BLOCKLY_image_top_set_EVENT_HANDLER
    lv_obj_set_event_cb(image_top_set, __qmsd_image_top_set_cb);
#endif
    lv_obj_set_pos(image_top_set, 218, 88);
    lv_obj_set_click(image_top_set,true);
    lv_obj_set_style_local_image_recolor(image_top_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_top_set,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_top_set,"image_top_set");
}
    
void qmsd_image_top_mode_create()
{
    image_top_mode = lv_img_create(cont_top, NULL);
    lv_img_set_src(image_top_mode, &imgtop_mode_png);
#ifdef BLOCKLY_image_top_mode_EVENT_HANDLER
    lv_obj_set_event_cb(image_top_mode, __qmsd_image_top_mode_cb);
#endif
    lv_obj_set_pos(image_top_mode, 359, 90);
    lv_obj_set_click(image_top_mode,true);
    lv_obj_set_style_local_image_recolor(image_top_mode,LV_IMG_PART_MAIN,LV_STATE_PRESSED,LV_COLOR_BLACK);
    lv_obj_set_style_local_image_recolor_opa(image_top_mode,LV_IMG_PART_MAIN,LV_STATE_PRESSED,60);
    qmsd_obj_set_id(image_top_mode,"image_top_mode");
}

static void cont_top_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_label_set_text(label_0bb8,qmsd_lang_get_trans("label_0bb8","晴  21℃"));
*/
#ifdef BLOCKLY_cont_top_SCREEN_INIT
    __qmsd_cont_top_init();
#endif
}

void cont_top_cont_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        cont_top = NULL;
        qmsd_screen_remove("cont_top");
    }
#ifdef BLOCKLY_cont_top_EVENT_HANDLER
	__qmsd_cont_top_cb(obj,event);
#endif
}

lv_obj_t* cont_top_build(lv_obj_t* parent)
{
    if(!cont_top)
    {
        cont_top = lv_cont_create(parent, NULL);
        lv_obj_set_size(cont_top,480,278);
        lv_obj_set_pos(cont_top,0,0);
        lv_obj_set_event_cb(cont_top,cont_top_cont_cb);
        qmsd_image_e005_create();
        lv_page_glue_obj(image_e005,true);
        qmsd_label_0bb8_create();
        lv_page_glue_obj(label_0bb8,true);
        qmsd_image_top_home_create();
        lv_page_glue_obj(image_top_home,true);
        qmsd_image_top_set_create();
        lv_page_glue_obj(image_top_set,true);
        qmsd_image_top_mode_create();
        lv_page_glue_obj(image_top_mode,true);
        lv_obj_set_style_local_bg_color(cont_top,LV_PAGE_PART_BG,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));
        qmsd_screen_register(cont_top,"cont_top");
        return cont_top;
    }
    return NULL;
}

void cont_top_show(void)
{

}

void cont_top_delete(void)
{
    if(cont_top)
    {
        lv_obj_del(cont_top);
        cont_top = NULL;
    }
}
