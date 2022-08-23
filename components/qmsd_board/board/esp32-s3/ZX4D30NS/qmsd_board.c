#include "string.h"
#include "qmsd_board.h"
#include "qmsd_utils.h"
#include "screen_utility.h"
#include "esp_log.h"

#define TAG "QMSD_BOARD"

static scr_driver_t* g_lcd_driver;
static qmsd_board_config_t g_board_config;
static void screen_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);

void qmsd_board_init(qmsd_board_config_t* config) {
    memcpy(&g_board_config, config, sizeof(qmsd_board_config_t));
    if (BOARD_RESET_PIN > -1) {
        gpio_pad_select_gpio(BOARD_RESET_PIN);
        gpio_set_direction(BOARD_RESET_PIN, GPIO_MODE_OUTPUT);
        gpio_set_level(BOARD_RESET_PIN, 0);
        vTaskDelay(pdMS_TO_TICKS(2));
        gpio_set_level(BOARD_RESET_PIN, 1);
        vTaskDelay(pdMS_TO_TICKS(120));
    }
    qmsd_board_init_screen();
    qmsd_board_backlight_init(LCD_BL_PIN, 1, QMSD_SCREEN_BK_FREQ);
    qmsd_board_backlight_set(100);

    if (g_board_config.gui.en) {
        qmsd_board_init_gui();
    }
}

void qmsd_board_init_screen() {
    extern scr_driver_t qmsd_lcd_default_driver;
    g_lcd_driver = &qmsd_lcd_default_driver;
    g_lcd_driver->init(NULL);
}

scr_driver_t* qmsd_get_screen_driver() {
    return g_lcd_driver;
}

void qmsd_board_init_gui() {
    uint32_t buffer_size = QMSD_SCREEN_HIGHT * QMSD_SCREEN_WIDTH * 2;
    uint8_t* buffers[QMSD_GUI_MAX_BUFFER_NUM] = {0};
    if (g_board_config.board_dir != BOARD_ROTATION_0) {
        ESP_LOGW(TAG, "Only support BOARD_ROTATION_0");
        g_board_config.board_dir = BOARD_ROTATION_0;
    }
    if (g_board_config.gui.buffer_size != 0) {
        ESP_LOGW(TAG, "Only support full screen buffer, now: %d", g_board_config.gui.buffer_size);
    }
    if (g_board_config.gui.flags.full_refresh == 0) {
        g_board_config.gui.flags.full_refresh = 1;
        ESP_LOGW(TAG, "Only support gui full refresh now");
    }
    uint8_t buffer_num = 2;
    if (g_board_config.gui.flags.full_refresh == 0) {
        for (uint8_t i = 0; i < buffer_num; i++) {
            if (g_board_config.gui.flags.fb_in_psram) {
                buffers[i] = (uint8_t *)QMSD_MALLOC_PSRAM(buffer_size);
            } else {
                buffers[i] = (uint8_t *)QMSD_MALLOC(buffer_size);
            }
        }
    } else {
        qmsd_lcd_rgb_panel_get_frame_buffer(g_rgb_panel_handle, 2, (void **)&buffers[0], (void **)&buffers[1]);
    }

    qmsd_gui_config_t gui_config = {
        .width = (g_board_config.board_dir & 0x01) ? QMSD_SCREEN_HIGHT : QMSD_SCREEN_WIDTH,
        .hight = (g_board_config.board_dir & 0x01) ? QMSD_SCREEN_WIDTH : QMSD_SCREEN_HIGHT,
        .buffer_nums = buffer_num,
        .buffer_size = buffer_size,

        .refresh_task = {
            .en = g_board_config.gui.refresh_task.en,
            .core = g_board_config.gui.refresh_task.core,
            .priority = g_board_config.gui.refresh_task.priority,
        },

        .update_task = {
            .en = g_board_config.gui.update_task.en,
            .core = g_board_config.gui.update_task.core,
            .priority = g_board_config.gui.update_task.priority,
        },

        .flags = {
            .antialiasing = g_board_config.gui.flags.antialiasing,
            .direct_mode = g_board_config.gui.flags.direct_mode,
            .full_refresh = g_board_config.gui.flags.full_refresh,
        },
        
        .draw_bitmap = g_board_config.gui.en ? screen_draw_bitmap : NULL,
        .touch_read = NULL,
    };

    for (uint8_t i = 0; i < QMSD_GUI_MAX_BUFFER_NUM; i++) {
        gui_config.buffer[i] = buffers[i];
    }
    qmsd_gui_init(&gui_config);
}

static void screen_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap) {
    g_lcd_driver->draw_bitmap(x, y, w, h, bitmap);
}
