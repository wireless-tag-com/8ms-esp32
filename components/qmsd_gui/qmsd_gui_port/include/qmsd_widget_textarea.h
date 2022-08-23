#ifndef _QMSD_WIDGET_TEXTAREA_H_
#define _QMSD_WIDGET_TEXTAREA_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_textarea_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_textarea_set_title(qmsd_widget_t* textarea,const char* title);

qmsd_err_t qmsd_widget_textarea_set_text(qmsd_widget_t* textarea,const char* text);

qmsd_err_t qmsd_widget_textarea_set_one_line(qmsd_widget_t* textarea,bool enable);

qmsd_err_t qmsd_widget_textarea_set_pwd_mode(qmsd_widget_t* textarea,bool enable);

qmsd_err_t qmsd_widget_textarea_set_cursor_pos(qmsd_widget_t* textarea,int32_t pos);

qmsd_err_t qmsd_widget_textarea_add_char(qmsd_widget_t* textarea,char c);

qmsd_err_t qmsd_widget_textarea_set_char_list(qmsd_widget_t* textarea,const char* list);

qmsd_err_t qmsd_widget_textarea_set_max_length(qmsd_widget_t* textarea,uint32_t length);

qmsd_err_t qmsd_widget_textarea_set_keyboard(qmsd_widget_t* textarea,qmsd_widget_t* kb);

qmsd_err_t qmsd_widget_textarea_get_text(qmsd_widget_t* textarea);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_TEXTAREA_H_