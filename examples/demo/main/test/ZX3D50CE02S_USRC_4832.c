#include <sdkconfig.h>
#ifdef CONFIG_ZX3D50CE02S_USRC_4832
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
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "qmsd_api.h"

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
        .uart_tx_pin = 42,
        .uart_rx_pin = 1,
        .uart_rts_pin = 2,
        .uart_cts_pin = -1,
        .uart_mode = UART_MODE_RS485_HALF_DUPLEX,
    };
    qmsd_uart_start(UART_NUM_1, &uconfig);
}

static int qmsd_rs485_test(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("rs485 start\n");

    return 0;
}

static void qmsd_rs485_test_register(void)
{
    const esp_console_cmd_t rs485_cmd = {
        .command = "rs485",
        .help = "start rs485 test",
        .hint = NULL,
        .func = &qmsd_rs485_test,
    };

    qmsd_rs485_init();
    ESP_ERROR_CHECK(esp_console_cmd_register(&rs485_cmd));
}

static int __qmsd_nb_func(struct qmsd_notifier_block *nb, unsigned int action, void *data)
{
    if (action == QMSD_UART_EVENT_DATA) {
        struct qmsd_uart_rx_data *param = (struct qmsd_uart_rx_data *)data;
        qmsd_uart_write(param->uart_num, param->data, param->size);
    }

    return QMSD_NOTIFY_OK;
}

static struct qmsd_notifier_block g_nb = {
    .notifier_call = __qmsd_nb_func,
};

void qmsd_board_test_register(void)
{
    qmsd_notifier_register(&g_nb);
    qmsd_rs485_test_register();
    qmsd_lcd_test_register();
    qmsd_tp_test_register();
}

#endif
