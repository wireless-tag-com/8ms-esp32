#include <sdkconfig.h>
#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "driver/uart.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"

#define PROMPT_STR "ZX"

extern void qmsd_board_test_register(void);

int qmsd_start_test(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("tp start\n");

    qmsd_board_test_register();

    return 0;
}

void qmsd_start_test_register(void)
{
    const esp_console_cmd_t tp_cmd = {
        .command = "start",
        .help = "start test",
        .hint = NULL,
        .func = &qmsd_start_test,
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&tp_cmd));
}

void qmsd_test_init(void)
{
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = {
        .max_history_len = 5,
        .history_save_path = NULL,
        .task_stack_size = 4096,
        .task_priority = 2,
        .prompt = NULL,
        .max_cmdline_length = 0,
    };

    esp_console_dev_uart_config_t uart_config = {
        .channel = 0,
        .baud_rate = 115200,
        .tx_gpio_num = -1,
        .rx_gpio_num = -1,
    };

    /* Prompt to be printed before each line.
     * This can be customized, made dynamic, etc.
     */
    repl_config.prompt = PROMPT_STR ">";
    repl_config.max_cmdline_length = 64;

    /* Register commands */
    esp_console_register_help_command();
    qmsd_start_test_register();

    ESP_ERROR_CHECK(esp_console_new_repl_uart(&uart_config, &repl_config, &repl));

    ESP_ERROR_CHECK(esp_console_start_repl(repl));
}
