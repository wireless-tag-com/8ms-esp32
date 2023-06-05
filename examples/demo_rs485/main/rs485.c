#include <sdkconfig.h>
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "string.h"
#include "esp_log.h"
#include "esp_console.h"
#include "driver/uart.h"
#include "qmsd_api.h"
#include "qmsd_ui_entry.h"
#include "qmsd_ui_api.h"

extern void qmsd_tp_test_register(void);
extern void qmsd_lcd_test_register(void);
extern void qmsd_rs485_test_register(void);

static void qmsd_rs485_init(void)
{
    qmsd_uart_config_t uconfig = {
        .uart_buffer_size = 1024,
        .queue_size = 20,
        .uart_native_config = {
            .baud_rate = 115200,
            .data_bits = UART_DATA_8_BITS,
            .parity    = UART_PARITY_DISABLE,
            .stop_bits = UART_STOP_BITS_1,
            .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
            .rx_flow_ctrl_thresh = 0,
            .source_clk = UART_SCLK_APB,
        },
#ifdef CONFIG_ZX3D50CE02S_USRC_4832
        .uart_tx_pin = 42,
        .uart_rx_pin = 1,
        .uart_rts_pin = 2,
        .uart_cts_pin = -1,
#endif

#ifdef CONFIG_ZX4D30NE01S_UR_4827
        .uart_tx_pin = 0,
        .uart_rx_pin = 39,
        .uart_rts_pin = 38,
        .uart_cts_pin = -1,
#endif

        .uart_mode = UART_MODE_RS485_HALF_DUPLEX,
    };
    qmsd_uart_start(UART_NUM_1, &uconfig);
}

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if (action == QMSD_UART_EVENT_DATA) {
        int i;
        struct qmsd_uart_rx_data *param = (struct qmsd_uart_rx_data *)data;
        /*
         * dump uart rx data
         */
        for (i =0; i < param->size; i++) {
            printf("%02X ", param->data[i]);
        }
        printf("\n");

        /*
         * parse uart rx data
         */
        if (param->data[0] == 1) {
            /*
             * call ui api
             */
            screen_main_show();
        } else if (param->data[0] == 2) {
            /*
             * call ui api
             */
            screen_test_show();
        }
    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};

void qmsd_board_ext_init(void)
{
    qmsd_notifier_register(&g_nb);
	qmsd_rs485_init();
}

