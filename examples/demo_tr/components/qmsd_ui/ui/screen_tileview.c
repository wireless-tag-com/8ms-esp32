#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_tileview;
lv_obj_t* tile_main;
lv_obj_t* but_tile_left;
lv_obj_t * __but_tile_left_label;
lv_obj_t* but_tile_middle;
lv_obj_t * __but_tile_middle_label;
lv_obj_t* but_tile_right;
lv_obj_t * __but_tile_right_label;
lv_obj_t* contlink_main;


    void qmsd_tile_main_create()
{
    tile_main = lv_tileview_create(screen_tileview, NULL);
    lv_obj_set_size(tile_main, 480, 480);
    static lv_point_t tile_main_valid_pos[] = {{0,0},{1,0},{2,0}};
    lv_tileview_set_valid_positions(tile_main, tile_main_valid_pos, 3);
    lv_tileview_set_edge_flash(tile_main, true);
	lv_obj_set_pos(tile_main, 0, 0);
    screentileview1_build();
    screentileview2_build();
    screentileview3_build();
    lv_obj_set_style_local_bg_opa(tile_main,LV_TILEVIEW_PART_SCROLLBAR,LV_STATE_DEFAULT,0);
    lv_tileview_set_tile_act(tile_main , 0 , 0 , LV_ANIM_ON);
    qmsd_obj_set_id(tile_main,"tile_main");
}
    void qmsd_but_tile_left_create()
{
    but_tile_left = lv_btn_create(screen_tileview, NULL);
    __but_tile_left_label = lv_label_create(but_tile_left, NULL);
    lv_label_set_text(__but_tile_left_label,qmsd_lang_get_trans("but_tile_left",""));

    lv_obj_set_style_local_text_font(__but_tile_left_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile_left, 9, 9);
    lv_obj_set_pos(but_tile_left, 208, 453);
#ifdef BLOCKLY_but_tile_left_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile_left, __qmsd_but_tile_left_cb);
#endif


    lv_obj_t* obj = but_tile_left;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile_left,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile_left,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile_left,"but_tile_left");
}
    void qmsd_but_tile_middle_create()
{
    but_tile_middle = lv_btn_create(screen_tileview, NULL);
    __but_tile_middle_label = lv_label_create(but_tile_middle, NULL);
    lv_label_set_text(__but_tile_middle_label,qmsd_lang_get_trans("but_tile_middle",""));

    lv_obj_set_style_local_text_font(__but_tile_middle_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile_middle, 9, 9);
    lv_obj_set_pos(but_tile_middle, 236, 453);
#ifdef BLOCKLY_but_tile_middle_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile_middle, __qmsd_but_tile_middle_cb);
#endif


    lv_obj_t* obj = but_tile_middle;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile_middle,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile_middle,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile_middle,"but_tile_middle");
}
    void qmsd_but_tile_right_create()
{
    but_tile_right = lv_btn_create(screen_tileview, NULL);
    __but_tile_right_label = lv_label_create(but_tile_right, NULL);
    lv_label_set_text(__but_tile_right_label,qmsd_lang_get_trans("but_tile_right",""));

    lv_obj_set_style_local_text_font(__but_tile_right_label,LV_LABEL_PART_MAIN,LV_STATE_DEFAULT,&ali_font_16);
    lv_obj_set_size(but_tile_right, 9, 9);
    lv_obj_set_pos(but_tile_right, 264, 453);
#ifdef BLOCKLY_but_tile_right_EVENT_HANDLER
    lv_obj_set_event_cb(but_tile_right, __qmsd_but_tile_right_cb);
#endif


    lv_obj_t* obj = but_tile_right;
    int part = LV_BTN_PART_MAIN;
//设置正常样式
        lv_obj_set_style_local_radius(obj,part,LV_STATE_DEFAULT,10);
    lv_obj_set_style_local_border_color(obj,part,LV_STATE_DEFAULT,LV_COLOR_MAKE(0xff, 0xff, 0xff));
    lv_obj_set_style_local_border_opa(obj,part,LV_STATE_DEFAULT,0);
    lv_obj_set_style_local_shadow_width(obj,part,LV_STATE_DEFAULT,0);

//设置正常样式结束

//设置按下样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_PRESSED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置按下样式结束

//设置禁用样式
        lv_obj_set_style_local_border_color(obj,part,LV_STATE_DISABLED,LV_COLOR_MAKE(0xff, 0xff, 0xff));

//设置禁用样式结束
    lv_obj_set_style_local_outline_width(but_tile_right,LV_BTN_PART_MAIN,LV_STATE_DEFAULT,0);
	lv_obj_set_style_local_outline_width(but_tile_right,LV_BTN_PART_MAIN,LV_STATE_FOCUSED,0);
    qmsd_obj_set_id(but_tile_right,"but_tile_right");
}
    void qmsd_contlink_main_create()
{
    screen_cont_build(screen_tileview);
    contlink_main = screen_cont;
    lv_obj_set_parent(contlink_main,screen_tileview);
    lv_obj_set_pos(contlink_main,0,-338);
    lv_obj_set_size(contlink_main, 480, 378);
}

static void screen_tileview_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_obj_qmsd_call_cb(screentileview1, LV_EVENT_SCREEN_LOAD , NULL);
    lv_obj_qmsd_call_cb(screentileview2, LV_EVENT_SCREEN_LOAD , NULL);
    lv_obj_qmsd_call_cb(screentileview3, LV_EVENT_SCREEN_LOAD , NULL);
    lv_label_set_text(__but_tile_left_label,qmsd_lang_get_trans("but_tile_left",""));
    lv_label_set_text(__but_tile_middle_label,qmsd_lang_get_trans("but_tile_middle",""));
    lv_label_set_text(__but_tile_right_label,qmsd_lang_get_trans("but_tile_right",""));
*/
#ifdef BLOCKLY_screen_tileview_SCREEN_INIT
    __qmsd_screen_tileview_init();
#endif
}

static void screen_tileview_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_tileview=NULL;
        qmsd_screen_remove("screen_tileview");
    }
}

void screen_tileview_build(void)
{
    if(screen_tileview) return;
    screen_tileview = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_tileview, screen_tileview_qmsd_cb);

    qmsd_tile_main_create();
    qmsd_but_tile_left_create();
    qmsd_but_tile_middle_create();
    qmsd_but_tile_right_create();
    qmsd_contlink_main_create();
    lv_obj_set_event_cb(screen_tileview,screen_tileview_del_cb);
    qmsd_screen_register(screen_tileview,"screen_tileview");
}

void screen_tileview_show(void)
{
    if(!screen_tileview)
    {
        screen_tileview_build();
    }
    lv_scr_load(screen_tileview);
}

void screen_tileview_delete(void)
{
    if(screen_tileview)
    {
        lv_obj_del(screen_tileview);
        screen_tileview = NULL;
    }
}
