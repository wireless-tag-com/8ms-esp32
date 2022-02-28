#ifndef QMSD_BOARD_INIT
#define QMSD_BOARD_INIT

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"

scr_driver_t* qmsd_board_init(int buf_size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //QMSD_BOARD_INIT