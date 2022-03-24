#ifndef QMSD_BOARD_INIT
#define QMSD_BOARD_INIT

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include "touch_panel.h"

typedef enum {
    SCREEN_ORIGIN,
    SCREEN_180,
    SCREEN_90,
    SCREEN_270,
}qmsd_screen_rotation_t;

extern scr_driver_t *g_lcd;
extern touch_panel_driver_t g_touch;
extern uint32_t g_dis_buf_size;

void qmsd_board_init(qmsd_screen_rotation_t dir);
esp_err_t lvgl_display_init(int w, int h, void * buf1, void * buf2, uint32_t size_in_px_cnt);
esp_err_t lvgl_indev_init(touch_panel_driver_t *driver);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //QMSD_BOARD_INIT