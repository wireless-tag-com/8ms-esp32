#ifndef QMSD_MENU_H
#define QMSD_MENU_H
#include "base_widget_type.h"
#include "qmsd_top_gui.h"
typedef struct {
    /*New data for this type */
    lv_obj_t* icons[32];
    int8_t icon_visable_amount;
    int8_t icon_registed;//Amount of icon inuse
    int8_t type;
    int interval;

    float a;//arg for icon's moving edge
    float b;
    float c;

    int8_t anime_left;
    int8_t anime_right;
    int8_t anime_mid;
} lv_menu_ext_t;

qmsd_widget_t* qmsd_widget_menu_create(qmsd_widget_t* par);
void qmsd_menu_init(lv_obj_t* menu,int w,int h);
void qmsd_menu_insert_obj(lv_obj_t* menu,lv_obj_t* obj);
void qmsd_menu_roll_left(lv_obj_t* menu);
void qmsd_menu_roll_right(lv_obj_t* menu);
#endif
