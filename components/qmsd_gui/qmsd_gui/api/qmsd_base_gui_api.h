/**
 * @file base_widget_api.h
 *
 */

#ifndef QMSD_BASE_GUI_API_H
#define QMSD_BASE_GUI_API_H

#include "qmsd_gui_obj.h"

#ifdef __cplusplus
extern "C" {
#endif

void qmsd_gui_lock_init(void);
int qmsd_gui_lock(uint32_t timeout);
void qmsd_gui_unlock(void);


void qmsd_img_res_init(qmsd_img_t* list ,uint16_t num);

void qmsd_font_res_init(qmsd_font_t* list ,uint16_t num);

const qmsd_font_bitmap_t *qmsd_get_font(const char *w_name);

const qmsd_img_bitmap_t *qmsd_get_img(const char *w_name);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*QMSD_BASE_GUI_API_H*/
