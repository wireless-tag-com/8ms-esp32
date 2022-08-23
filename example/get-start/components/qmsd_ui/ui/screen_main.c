#include "qmsd_ui_entry.h"
#include "qmsd_internal_ui_cb.h"
#include"qmsd_top_gui.h"
lv_obj_t* screen_main;
lv_obj_t* screen_main_label_1;
lv_obj_t* screen_main_button_1;
lv_obj_t* screen_main_button_1_label;
static int screen_main_button_1_create(qmsd_gui_widget_t* widget,void* user_data);
static int screen_main_label_1_create(qmsd_gui_widget_t* widget,void* user_data);

char* teststr1 = "{\"wid\":\"screen_main_button_1\",\"cmd\":\"set_public\",\"attr\":{\"action\":\"set_size\",\"w\":300,\"h\":100}}";

qmsd_gui_widget_t screen_main_button_1_obj ={
    .name = "screen_main_button_1",
    .type = QMSD_WIDGET_ARC,
    .build = screen_main_button_1_create,
};

qmsd_gui_widget_t screen_main_label_1_obj ={
    .name = "screen_main_label_1",
    .type = QMSD_WIDGET_ARC,
    .build = screen_main_label_1_create,
};

qmsd_gui_screen_t screen_main_obj = {
    .build = screen_main_build,
    .name = "screen_main",
    .remove = screen_main_delete,
    
};
qmsd_gui_screen_t screen_main_obj2 = {
    .build = screen_main_build,
    .name = "screen_main",
    .remove = screen_main_delete,
    
};

static int screen_main_button_1_create(qmsd_gui_widget_t* widget,void* user_data)
{
    screen_main_button_1_obj.widget = qmsd_widget_button_create(screen_main_obj.screen);
    if (screen_main_button_1_obj.widget) {
        screen_main_button_1_label = qmsd_widget_label_create(screen_main_button_1_obj.widget);
        if (screen_main_button_1_label) {
            lv_label_set_text(screen_main_button_1_label, qmsd_lang_get_trans("screen_main_button_1", "BTNM"));
        } else {
            lv_obj_del(screen_main_button_1_obj.widget);
            screen_main_button_1_obj.widget = NULL;
            return -1;
        }

        //lv_obj_align(screen_main_button_1_obj.widget, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
        //lv_obj_set_event_cb(screen_main_button_1_obj.widget, __qmsd_main_button_1_cb);
        //qmsd_obj_set_id(screen_main_button_1_obj.widget,"screen_main_button_1_obj.widget");
        //printf("origin:%p,id:%s\n",screen_main_button_1_obj.widget,screen_main_button_1_obj.widget->qmsd_id);
        qmsd_widget_set_port_cb(screen_main_button_1);
        qmsd_err_t err = qmsd_gui_ctrl_entry(teststr1,QMSD_GUI_CTRL_DIRECTLY);
        printf("err:%d\n",err);
        return 0;
    }
    return -1;
}

static int screen_main_label_1_create(qmsd_gui_widget_t* widget,void* user_data)
{
    screen_main_label_1_obj.widget = qmsd_widget_label_create(screen_main_obj.screen);
    if (screen_main_label_1_obj.widget) {
        //lv_obj_align(screen_main_label_1_obj.widget, NULL, LV_ALIGN_CENTER, 0, 0);
        //qmsd_obj_set_id(screen_main_label_1_obj.widget,"screen_main_label_1_obj.widget");
        return 0;
    }

    return -1;
}

//static void screen_main_qr_1_create()
//{
    //char *url="https://8ms.xyz";
    //lv_obj_t* obj=lv_qrcode_create(screen_main_obj.screen,100,LV_COLOR_YELLOW,LV_COLOR_BLUE);
    //lv_qrcode_update(obj,url,strlen(url));
    //lv_obj_align(obj,NULL,LV_ALIGN_IN_BOTTOM_MID,0,0);
    //qmsd_obj_set_id(obj,"qr_1");
//}

int screen_main_build(qmsd_gui_screen_t* screen,void* user_data)
{
    screen_main_obj.screen = qmsd_screen_create();
    lv_scr_load(screen_main_obj.screen);
    printf("-------%p\n-------%p\n-------%p\n",screen_main_obj2.screen,screen_main_obj.screen,(screen_main_obj.screen));
    if (screen_main_obj.screen) {
        qmsd_widget_ll_insert(&(screen_main_obj.child),&screen_main_button_1_obj);
        qmsd_widget_ll_insert(&(screen_main_obj.child),&screen_main_label_1_obj);

        qmsd_widget_style_set_bg_color(screen_main_obj.screen,QMSD_PART_MAIN,LV_STATE_DEFAULT,QMSD_COLOR_RGB(0,0XFF,0));
    }

    return -1;
}

int screen_main_delete(qmsd_gui_screen_t* screen,void* user_data)
{
    if (screen_main_obj.screen) {
        lv_obj_del(screen_main_obj.screen);
        return 0;
    }
    return QMSD_ERR_FAIL;
}

int screen_main_show(void)
{
    screen_main_build(NULL,NULL);
    return 0;
}