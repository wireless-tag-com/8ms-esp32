#include "qmsd_ui_entry.h"
#include "qmsd_ctrl.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *name;
    lv_img_src_t* img;
} qmsd_img_t;

typedef struct
{
    char *name;
    lv_font_t* font;
} qmsd_font_t;

/*
* includes
*/

/*
* declear screens
*/

qmsd_img_t g_qmsd_img[] = 
{
    {"clock_bg",&img1639365041009_png},
};

qmsd_font_t g_qmsd_font[] =
{
    //{"ali_font_16",&abashli_font_16},
    {"ali_font_58",&ali_font_58},
};

void qmsd_ui_entry(void)
{
     qmsd_screen_list_init(16);
    LV_FONT_DECLARE(ali_font_16);
    qmsd_set_screen(qmsd_search_screen);
    qmsd_set_widget(qmsd_search_widget);
    qmsd_set_img(qmsd_get_img);
    qmsd_set_font(qmsd_get_font);
    screen_main_build();
    screen_test_build();

    lv_scr_load(screen_main);
    qmsd_send_event_to_chill(screen_main, NULL,QMSD_EVENT_WIDGET_REFRESH);
    
    lv_obj_t* test = qmsd_search_widget("screen_main/screen_main_button_1");
    if (test)
    {
        printf("Found:%s  pointer:%p\n",test->qmsd_id,test);
    }
    test = qmsd_search_widget("screen_main/screen_main_label_1");
    if (test)
    {
        printf("Found:%s  pointer:%p\n",test->qmsd_id,test);
    }
    test = qmsd_search_widget("screen_main/qr_1");
    if (test)
    {
        printf("Found:%s  pointer:%p\n",test->qmsd_id,test);
    }
    test = qmsd_search_widget("screen_test_img_1");
    if (test)
    {
        printf("Found:%s  pointer:%p\n",test->qmsd_id,test);
    }
}

lv_img_src_t *qmsd_get_img(const char *w_name)
{
    int i = 0;

    for (i = 0; i < (sizeof(g_qmsd_img) / sizeof(g_qmsd_img[0])); i++)
    {
        if (!strcmp(w_name, g_qmsd_img[i].name))
        {
            if (g_qmsd_img[i].img) {
                return g_qmsd_img[i].img;
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}

lv_font_t *qmsd_get_font(const char *w_name)
{
    int i = 0;

    for (i = 0; i < (sizeof(g_qmsd_font) / sizeof(g_qmsd_font[0])); i++)
    {
        if (!strcmp(w_name, g_qmsd_font[i].name))
        {
            if (g_qmsd_font[i].font) {
                return g_qmsd_font[i].font;
            } else {
                return NULL;
            }
        }
    }

    return NULL;
}

