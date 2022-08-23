#include "string.h"
#include "qmsd_board.h"
#include "qmsd_utils.h"
#include "screen_utility.h"
#include "esp_log.h"

#define TAG "QMSD_BOARD"

static scr_driver_t* g_lcd_driver;
static qmsd_board_config_t g_board_config;
static void screen_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap);
static void touch_read(uint8_t* press, uint16_t* x, uint16_t* y);

extern scr_driver_t lcd_st7796_default_driver;
extern esp_err_t qmsd_lcd_reg_config(void);

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

    if (g_board_config.touch.en) {
        qmsd_board_init_touch();
    }
    if (g_board_config.gui.en) {
        qmsd_board_init_gui();
    }
}

void qmsd_board_init_screen() {
    scr_dir_t screen_dir[] = { QMSD_SCREEN_DIR_0, QMSD_SCREEN_DIR_90, QMSD_SCREEN_DIR_180, QMSD_SCREEN_DIR_270};
    i2s_lcd_config_t i2s_lcd_cfg = {
        .data_width = 8,
        .pin_data_num = {
            LCD_D0_PIN,
            LCD_D1_PIN,
            LCD_D2_PIN,
            LCD_D3_PIN,
            LCD_D4_PIN,
            LCD_D5_PIN,
            LCD_D6_PIN,
            LCD_D7_PIN,
        },
        .pin_num_cs = LCD_CS_PIN,
        .pin_num_wr = LCD_WR_PIN,                          
        .pin_num_rs = LCD_RS_PIN,
        .clk_freq = QMSD_SCREEN_CLK_SPEED,
        .i2s_port = I2S_NUM_0,
        .buffer_size = QMSD_SCREEN_DRIVER_CACHE_SIZE,
        .swap_data = true,
    };

    scr_interface_driver_t *iface_drv;
    scr_interface_create(SCREEN_IFACE_8080, &i2s_lcd_cfg, &iface_drv);

    lcd_st7796_default_driver.init_reg = qmsd_lcd_reg_config;
    g_lcd_driver = &lcd_st7796_default_driver;
    scr_controller_config_t lcd_cfg = {
        .interface_drv = iface_drv,
        .pin_num_rst = LCD_RST_PIN,
        .pin_num_bckl = -1,
        .rst_active_level = 0,
        .bckl_active_level = 1,
        .offset_hor = 0,
        .offset_ver = 0,
        .width = QMSD_SCREEN_WIDTH,
        .height = QMSD_SCREEN_HIGHT,
        .rotate = screen_dir[g_board_config.board_dir],
    };
    g_lcd_driver->init(&lcd_cfg);
}

void qmsd_board_init_touch() {
    touch_panel_dir_t touch_dir[] = {QMSD_TOUCH_DIR_0, QMSD_TOUCH_DIR_90, QMSD_TOUCH_DIR_180, QMSD_TOUCH_DIR_270};
    touch_panel_config_t touch_config = {
        .sda_pin = TOUCH_IIC_SDA_PIN,
        .scl_pin = TOUCH_IIC_SCL_PIN,
        .rst_pin = TOUCH_IIC_RST_PIN,
        .intr_pin = TOUCH_IIC_INT_PIN,
        .i2c_num = I2C_NUM_0,
        .i2c_freq = g_board_config.touch.i2c_freq,
        .task_en = g_board_config.touch.update_task.en,
        .task_priority = g_board_config.touch.update_task.priority,
        .task_core = g_board_config.touch.update_task.core,
        .width = QMSD_SCREEN_WIDTH,
        .height = QMSD_SCREEN_HIGHT,
        .direction = touch_dir[g_board_config.board_dir],
    };
    touch_init(&touch_ft5x06_driver, &touch_config);
}

void qmsd_board_init_gui() {
    uint32_t buffer_size = QMSD_SCREEN_HIGHT * QMSD_SCREEN_WIDTH * 2;
    uint8_t* buffers[QMSD_GUI_MAX_BUFFER_NUM] = {0};
    if (g_board_config.gui.buffer_size != 0) {
        buffer_size = g_board_config.gui.buffer_size;
    }
    uint8_t buffer_num = g_board_config.gui.flags.double_fb ? 2 : 1;
    if (buffer_num == 1 && g_board_config.gui.refresh_task.en == 1) {
        ESP_LOGW(TAG, "refresh only enable in double buffer");
        g_board_config.gui.refresh_task.en = 0;
    }

    for (uint8_t i = 0; i < buffer_num; i++) {
        if (g_board_config.gui.flags.fb_in_psram) {
            buffers[i] = (uint8_t *)QMSD_MALLOC_PSRAM(buffer_size);
        } else {
            buffers[i] = (uint8_t *)QMSD_MALLOC(buffer_size);
        }
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
        .touch_read = g_board_config.touch.en ? touch_read : NULL,
    };

    for (uint8_t i = 0; i < QMSD_GUI_MAX_BUFFER_NUM; i++) {
        gui_config.buffer[i] = buffers[i];
    }
    qmsd_gui_init(&gui_config);
}

scr_driver_t* qmsd_get_screen_driver() {
    return g_lcd_driver;
}

static void screen_draw_bitmap(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap) {
    g_lcd_driver->draw_bitmap(x, y, w, h, bitmap);
}

static void touch_read(uint8_t* press, uint16_t* x, uint16_t* y) {
    touch_panel_points_t points;
    touch_read_points(&points);
    *press = points.event == TOUCH_EVT_PRESS;
    *x = points.curx[0];
    *y = points.cury[0];
}
