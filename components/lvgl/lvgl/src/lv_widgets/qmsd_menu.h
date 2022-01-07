#ifndef QMSD_MENU_H
#define QMSD_MENU_H

#include "../lv_conf_internal.h"
#include "../lv_core/lv_obj.h"
#include "lv_page.h"
#include "lv_cont.h"
#include "lv_label.h"
#include "qmsd_effect.h"
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
} lv_menu_ext_t;

lv_obj_t* qmsd_menu_create(lv_obj_t* par, const lv_obj_t* copy);
void qmsd_menu_init(lv_obj_t* menu,int w,int h);
void qmsd_menu_insert_obj(lv_obj_t* menu,lv_obj_t* obj);
void qmsd_menu_roll_left(lv_obj_t* menu);
void qmsd_menu_roll_right(lv_obj_t* menu);
#endif
