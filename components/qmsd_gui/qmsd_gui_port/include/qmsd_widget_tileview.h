#ifndef _QMSD_WIDGET_TILEVIEW_H_
#define _QMSD_WIDGET_TILEVIEW_H_

#include "base_widget_type.h"

#ifdef __cplusplus
extern "C" {
#endif

qmsd_widget_t* qmsd_widget_tileview_create(qmsd_widget_t* parent);

qmsd_widget_t* qmsd_widget_tileview_add_tile(qmsd_widget_t* tileview,int16_t x,int16_t y);

qmsd_err_t qmsd_widget_tileview_set_tile_act(qmsd_widget_t* tileview,int16_t x, int16_t y ,bool anime);

qmsd_err_t qmsd_widget_tileview_get_tile_act(qmsd_widget_t* tileview,int16_t* x,int16_t* y);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif // _QMSD_WIDGET_TILEVIEW_H_