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

#if (defined CONFIG_WT32_SC01)
#define BOARD_BKL_PIN 23
#elif (defined CONFIG_WT_86_32_3ZW1) || (defined CONFIG_WT240_C3SI1)
#define BOARD_BKL_PIN 0
#elif (defined CONFIG_WT154_C3SI1)
#define BOARD_BKL_PIN 10
#elif (defined CONFIG_WT_0_S2_240MW1)
#define BOARD_BKL_PIN 35
#elif (defined CONFIG_WT154_S2MI1)
#define BOARD_BKL_PIN 39
#elif (defined CONFIG_WT280_S2MX1)
#define BOARD_BKL_PIN 16
#else
#define BOARD_BKL_PIN -1
#endif

extern scr_driver_t *g_lcd;
extern touch_panel_driver_t g_touch;
extern uint32_t g_dis_buf_size;

void qmsd_board_init(qmsd_screen_rotation_t dir);
esp_err_t lvgl_display_init(int w, int h, void * buf1, void * buf2, uint32_t size_in_px_cnt);
esp_err_t lvgl_indev_init(touch_panel_driver_t *driver);
void qmsd_bkl_ctrl(int level);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //QMSD_BOARD_INIT