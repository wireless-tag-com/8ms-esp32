#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"

lv_obj_t* screen_test;
lv_obj_t* screen_test_button_1;
lv_obj_t* screen_test_button_1_label;
lv_obj_t* screen_test_img_1;

static int screen_test_button_1_create(void)
{
    screen_test_button_1 = lv_btn_create(screen_test,NULL);
    if (screen_test_button_1) {
        screen_test_button_1_label = lv_label_create(screen_test_button_1,NULL);
        if (screen_test_button_1_label) {
            lv_label_set_text(screen_test_button_1_label, qmsd_lang_get_trans("test_button_1", "BTNT"));
        } else {
            lv_obj_del(screen_test_button_1);
            screen_test_button_1 = NULL;
            return -1;
        }
    
        lv_obj_align(screen_test_button_1,NULL,LV_ALIGN_IN_TOP_RIGHT,0,0);
        lv_obj_set_event_cb(screen_test_button_1,__qmsd_test_button_1_cb);
        qmsd_obj_set_id(screen_test_button_1,"screen_test_button_1");
        return 0;
    }

    return -1;
}

static int screen_test_img_1_create(void)
{
    screen_test_img_1 =lv_img_create(screen_test,NULL);
    if (screen_test_img_1) {
        lv_img_set_src(screen_test_img_1,qmsd_get_img("clock_bg"));
        lv_obj_align(screen_test_img_1,NULL,LV_ALIGN_IN_BOTTOM_LEFT,0,0);
        qmsd_obj_set_id(screen_test_img_1,"screen_test_img_1");
        return 0;
    }
    
    return -1;
}

static void screen_test_qmsd_cb(lv_obj_t * obj, lv_event_t event, void *data)
{
    if (event == LV_EVENT_SCREEN_LOAD) {
        if (screen_test_button_1_label) {
            lv_label_set_text(screen_test_button_1_label, qmsd_lang_get_trans("test_button_1", "BTNT"));
        }
    }
}

int screen_test_build(void)
{
    screen_test = lv_obj_create(NULL, NULL);
    if (screen_test) {
        lv_obj_set_style_local_bg_color(screen_test,LV_OBJ_PART_MAIN,LV_STATE_DEFAULT,LV_COLOR_BLUE);
        screen_test_button_1_create();
        screen_test_img_1_create();
        qmsd_screen_register(screen_test,"screen_test");
        lv_obj_qmsd_set_cb(screen_test, screen_test_qmsd_cb);
        qmsd_call_ui_event_cb("test", screen_test, LV_EVENT_SCREEN_CREATE);

        return 0;
    }

    return -1;
}

void screen_test_delete(void)
{
    if (screen_test) {
        lv_obj_del(screen_test);
    }
}