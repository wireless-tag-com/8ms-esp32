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

#define QMSD_TEST_PNG_FILE  "/img/test.png"

LV_FONT_DECLARE(ali_font_16);


/*
* declear screen_main
*/
extern lv_obj_t * screen_main;
extern lv_obj_t * label_7038;
void screen_main_build(void);
void screen_main_show(void);
void screen_main_delete(void);
void screen_show_png(char *filename);

extern lv_obj_t * g_kb;

void qmsd_ui_entry(void);
void qmsd_ui_loop(void);
lv_img_src_t *qmsd_get_img(const char *w_name);
lv_font_t *qmsd_get_font(const char *w_name);

void qmsd_update_7038(const char *str);

void g_create_kb_ifneeded(void);
void g_show_kb(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QM_UI_ENTRY_H*/
