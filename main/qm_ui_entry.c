#include "qm_ui_entry.h"
#include <stdio.h>
#include <stdlib.h>
#include "lv_8ms_blockly.h"
#include "wtctrl.h"

lv_obj_t *main_screen;

#define BLOCKLY_init

typedef struct
{
    char *name;
    lv_obj_t **id;
} lv_widget_t;

typedef struct
{
    char *name;
    lv_obj_t **id;
    lv_widget_t *wids;
    int len;
} lv_screen_t;

/*
* includes
*/
/*
* declear screens
*/
lv_obj_t *main_screen;
lv_obj_t *p1;
lv_obj_t *p2;
lv_obj_t *p3;
lv_obj_t *s1;
lv_obj_t* btn1;
lv_obj_t* btn2;
lv_widget_t g_main_screen_ids[] =
{
    {"p2", &p2},
    {"s1", &s1},
    {"btn1",&btn1},
    {"btn2",&btn2},
};

lv_widget_t g_p1_screen_ids[] =
{
    {"p3", &p3},
};

lv_screen_t g_screens[] =
{
    {"main_screen", &main_screen, g_main_screen_ids, (sizeof(g_main_screen_ids) / sizeof(g_main_screen_ids[0]))},
    {"p1", &p1, g_p1_screen_ids, (sizeof(g_p1_screen_ids) / sizeof(g_p1_screen_ids[0]))},
};


static void
blockly_init()
{
    
}

#define BLOCKLY_loop

static void blockly_loop()
{
    //lv_8ms_uart_write(UART_NUM_1, "hello\n");
}
#define LV_8MS_EVENT

/**
 * @brief 
 * @param 
 * @return 
 */
void show_screen_main_screen()
{
    lv_scr_load(main_screen);
}

/**
 * @brief 
 * @param 
 * @return 
 */
void init_function()
{
#ifdef BLOCKLY_init
    blockly_init();
#endif
#ifdef LV_8MS_EVENT
    lv_8ms_event_handle_init();
#endif
}

/**
 * @brief 
 * @param 
 * @return 
 */
void lv_qm_ui_loop(void)
{
#ifdef BLOCKLY_loop
    blockly_loop();
#endif
}
#ifndef LV_8MS_PRESET_UART_QUEUE
void lv_8ms_uart_queue_ana(uint8_t* data,int size){   
    printf("ana:%s\n",wtctrl_json_parse((char *)data));
}
#endif
#ifndef CUSTOM_MQTT_PARSE
void lv_8ms_mqtt_received(const char* data)
{
    printf("custom:%s\n",data);
}
#endif
/**
 * @brief 
 * @param 
 * @return 
 */
void cb_1(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        lv_8ms_httprequest("api.8ms.xyz","80","/weather/");
    }
    
}
void cb_2(lv_obj_t* obj,lv_event_t event)
{
    if (event==LV_EVENT_CLICKED)
    {
        lv_8ms_httprequest("api.8ms.xyz","80","/common/time");
        lv_8ms_report("{\"test\":\"test\"}");
    }
}
void s1_test()
{
    printf("%d,%d\n",s1->coords.x1,s1->coords.y1);
}
void lv_qm_ui_entry(void)
{
    LV_FONT_DECLARE(ali_font_16);
    main_screen = lv_obj_create(NULL, NULL);
    lv_obj_set_style_local_bg_color(main_screen,NULL,LV_STATE_DEFAULT,LV_COLOR_WHITE);
    lv_obj_t* label=lv_label_create(main_screen,NULL);
    lv_label_set_text(label,"Hello world");
    lv_obj_align(label,NULL,LV_ALIGN_CENTER,0,0);
    lv_scr_load(main_screen);
    p2=lv_switch_create(main_screen,NULL);
    lv_obj_align(p2,NULL,LV_ALIGN_IN_BOTTOM_LEFT,0,0);
    s1=lv_switch_create(main_screen,NULL);
    lv_obj_align(s1,NULL,LV_ALIGN_IN_BOTTOM_RIGHT,0,0);
    init_function();

    //lv_8ms_gpio_app_init();
    lv_8ms_wifi_connect("test","12345678",3);
    
    
    //lv_8ms_httprequest("api.8ms.xyz","80","/weather/");
    btn1=lv_btn_create(main_screen,NULL);
    lv_obj_align(btn1,NULL,LV_ALIGN_IN_TOP_LEFT,0,0);
    lv_obj_set_event_cb(btn1,cb_1);
    btn2=lv_btn_create(main_screen,NULL);
    lv_obj_align(btn1,NULL,LV_ALIGN_IN_TOP_RIGHT,0,0);
    lv_obj_set_event_cb(btn2,cb_2);
    lv_8ms_uart_ctrl_init(0);
    //lv_8ms_uart_app_init(0);
    lv_8ms_slide_in(s1,LV_8MS_TOP,800);
    lv_8ms_slide_in(p2,LV_8MS_TOP,800);
    lv_8ms_slide_in(btn1,LV_8MS_RIGHT,800);
    lv_8ms_slide_in(btn2,LV_8MS_LEFT,800);
    //lv_task_create(s1_test,10,LV_TASK_PRIO_HIGHEST,NULL);
    //printf("%d,%d\n",LV_HOR_RES,LV_VER_RES_MAX);

}
lv_obj_t *lv_8ms_get_screen(char *name)
{
    int i = 0;
    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        if (!strcmp(name, g_screens[i].name))
        {
            return *(g_screens[i].id);
        }
    }
    return NULL;
}

lv_obj_t *lv_8ms_get_widget(char *w_name)
{
    int i = 0, j = 0;

    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        for (j = 0; j <  g_screens[i].len; j++)
        {
            if (!strcmp(w_name, g_screens[i].wids[j].name))
            {
                return *(g_screens[i].wids[j].id);
            }
        }
    }

    return NULL;
}

const char *lv_8ms_get_obj_name(lv_obj_t *obj)
{
    if (!obj) {
        return NULL;
    }

    int i = 0, j = 0;
    for (i = 0; i < (sizeof(g_screens) / sizeof(g_screens[0])); i++)
    {
        if (*(g_screens[i].id) == obj) {
            return g_screens[i].name;
        }

        for (j = 0; j <  g_screens[i].len; j++)
        {
            if (*(g_screens[i].wids[j].id) == obj)
            {
                return g_screens[i].wids[j].name;
            }
        }
    }

    return NULL;
}
