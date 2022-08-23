#ifndef _QMSD_WIDGET_PAGE_H_
#define _QMSD_WIDGET_PAGE_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_container_create(qmsd_widget_t* parent);

qmsd_err_t qmsd_widget_container_set_scrollable(qmsd_widget_t* container,bool enable);

qmsd_err_t qmsd_widget_container_glue_obj(qmsd_widget_t* container);

qmsd_err_t qmsd_widget_container_set_scrl_size(qmsd_widget_t* container,uint16_t w,uint16_t h);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_PAGE_H_