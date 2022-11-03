#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_main;
lv_obj_t* screen_main_label_1;
lv_obj_t* screen_main_button_1;
lv_obj_t* screen_main_button_1_label;

static int screen_main_button_1_create(void)
{
    screen_main_button_1 = lv_btn_create(screen_main, NULL);
    if (screen_main_button_1) {
        screen_main_button_1_label = lv_label_create(screen_main_button_1, NULL);
        if (screen_main_button_1_label) {
            lv_label_set_text(screen_main_button_1_label, qmsd_lang_get_trans("main_button_1", "BTNM"));
        } else {
            lv_obj_del(screen_main_button_1);
            screen_main_button_1 = NULL;
            return -1;
        }

        lv_obj_align(screen_main_button_1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
        lv_obj_set_event_cb(screen_main_button_1, __qmsd_main_button_1_cb);
        qmsd_obj_set_id(screen_main_button_1,"screen_main_button_1");
        printf("origin:%p,id:%s\n",screen_main_button_1,screen_main_button_1->qmsd_id);
        return 0;
    }

    return -1;
}

static int screen_main_label_1_create(void)
{
    screen_main_label_1 = lv_label_create(screen_main, NULL);
    if (screen_main_label_1) {
        lv_obj_align(screen_main_label_1, NULL, LV_ALIGN_CENTER, 0, 0);
        qmsd_obj_set_id(screen_main_label_1,"screen_main_label_1");
        return 0;
    }

    return -1;
}

static void screen_main_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{
    if (event == LV_EVENT_SCREEN_LOAD) {
        if (screen_main_button_1_label) {
            lv_label_set_text(screen_main_button_1_label, qmsd_lang_get_trans("main_button_1", "BTNM"));
        }
    }
}

static void screen_main_qr_1_create()
{
    char *url="https://8ms.xyz";
    lv_obj_t* obj=lv_qrcode_create(screen_main,100,LV_COLOR_YELLOW,LV_COLOR_BLUE);
    lv_qrcode_update(obj,url,strlen(url));
    lv_obj_align(obj,NULL,LV_ALIGN_IN_BOTTOM_MID,0,0);
    qmsd_obj_set_id(obj,"qr_1");
}

int screen_main_build(void)
{
    screen_main = lv_obj_create(NULL, NULL);
    if (screen_main) {
        lv_obj_set_style_local_bg_color(screen_main,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_BLACK);

        screen_main_button_1_create();
        lv_obj_qmsd_set_cb(screen_main, screen_main_qmsd_cb);
        qmsd_screen_register(screen_main,"screen_main");
        qmsd_call_ui_event_cb("main", screen_main, LV_EVENT_SCREEN_CREATE);
    }

    return -1;
}

void screen_main_delete(void)
{
    if (screen_main) {
        lv_obj_del(screen_main);
    }
}