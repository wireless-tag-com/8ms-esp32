#ifndef QM_UI_ENTRY_H
#define QM_UI_ENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#include "lvgl/lvgl.h"
#include "qmsd_lang.h"
#include "qmsd_gui.h"
LV_FONT_DECLARE(ali_font_16);
LV_FONT_DECLARE(ali_font_12);


/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * label_554e;
extern lv_obj_t * button_5cb9;
extern lv_obj_t * __button_5cb9_label;
extern lv_obj_t * button_e490;
extern lv_obj_t * __button_e490_label;
extern lv_obj_t * label_b6b4;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);

extern lv_obj_t * g_kb;

void qmsd_ui_entry(void);
void qmsd_ui_loop(void);
lv_img_src_t *qmsd_get_img(const char *w_name);
lv_font_t *qmsd_get_font(const char *w_name);

void g_create_kb_ifneeded(void);
void g_show_kb(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/