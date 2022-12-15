#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_main;
lv_obj_t* image_base;
lv_obj_t* tileview_2093;
lv_obj_t* cont_link_f61c;


    
void qmsd_image_base_create()
{
    image_base = lv_img_create(screen_main, NULL);
#ifdef BLOCKLY_image_base_EVENT_HANDLER
    lv_obj_set_event_cb(image_base, __qmsd_image_base_cb);
#endif
    lv_obj_set_pos(image_base, 0, 0);
    qmsd_obj_set_id(image_base,"image_base");
}
    void qmsd_tileview_2093_create()
{
    tileview_2093 = lv_tileview_create(screen_main, NULL);
    lv_obj_set_size(tileview_2093, 480, 480);
    static lv_point_t tileview_2093_valid_pos[] = {{0,0},{1,0}};
    lv_tileview_set_valid_positions(tileview_2093, tileview_2093_valid_pos, 2);
    lv_tileview_set_edge_flash(tileview_2093, true);
	lv_obj_set_pos(tileview_2093, 0, 0);
    main_tile_1_build();
    main_tile_2_build();
    lv_obj_set_style_local_bg_opa(tileview_2093,LV_TILEVIEW_PART_SCROLLBAR,LV_STATE_DEFAULT,0);
    lv_tileview_set_tile_act(tileview_2093 , 0 , 0 , LV_ANIM_ON);
    qmsd_obj_set_id(tileview_2093,"tileview_2093");
}
    void qmsd_cont_link_f61c_create()
{
    cont_top_build(screen_main);
    cont_link_f61c = cont_top;
    lv_obj_set_parent(cont_link_f61c,screen_main);
    lv_obj_set_pos(cont_link_f61c,0,-230);
    lv_obj_set_size(cont_link_f61c, 480, 280);
}

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
    lv_obj_qmsd_call_cb(main_tile_1, LV_EVENT_SCREEN_LOAD , NULL);
    lv_obj_qmsd_call_cb(main_tile_2, LV_EVENT_SCREEN_LOAD , NULL);
*/
#ifdef BLOCKLY_screen_main_SCREEN_INIT
    __qmsd_screen_main_init();
#endif
}

static void screen_main_del_cb(lv_obj_t* obj,lv_event_t event)
{
    if(event == LV_EVENT_DELETE)
    {
        screen_main=NULL;
        qmsd_screen_remove("screen_main");
    }
}

void screen_main_build(void)
{
    if(screen_main) return;
    screen_main = lv_obj_create(NULL, NULL);
    lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);
    lv_obj_set_style_local_bg_color(screen_main,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_MAKE(0x00, 0x00, 0x00));

    qmsd_image_base_create();
    qmsd_tileview_2093_create();
    qmsd_cont_link_f61c_create();
    lv_obj_set_event_cb(screen_main,screen_main_del_cb);
    qmsd_screen_register(screen_main,"screen_main");
}

void screen_main_show(void)
{
    if(!screen_main)
    {
        screen_main_build();
    }
    lv_scr_load(screen_main);
}

void screen_main_delete(void)
{
    if(screen_main)
    {
        lv_obj_del(screen_main);
        screen_main = NULL;
    }
}
