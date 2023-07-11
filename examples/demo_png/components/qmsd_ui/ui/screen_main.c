#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"
#include "qmsd_api.h"

lv_obj_t *screen_main;
lv_obj_t *png_img;

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{/*
    char *trans;
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

    lv_obj_set_event_cb(screen_main,screen_main_del_cb);
    qmsd_screen_register(screen_main,"screen_main");
    screen_show_png(QMSD_TEST_PNG_FILE);
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

void screen_show_png(char *filename)
{
    struct stat st;

    if (stat(filename, &st) == 0)
    {
        if (st.st_size != 0) {
            if (screen_main) {
                if (!png_img)
                    png_img = lv_img_create(screen_main, NULL);
                lv_img_set_src(png_img, filename);
            }
        }
    }
}

