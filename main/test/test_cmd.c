/* Console example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "driver/uart.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"

#define PROMPT_STR "ZX"

static int qmsd_test_start(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("start ok\n");

    return 0;
}

static int qmsd_test_lcdr(int argc, char **argv)
{
    /*
     * start LCD red test
     */

    printf("lcdr start\n");

    return 0;
}

static int qmsd_test_lcdg(int argc, char **argv)
{
    /*
     * start LCD green test
     */

    printf("lcdg start\n");

    return 0;
}

static int qmsd_test_lcdb(int argc, char **argv)
{
    /*
     * start LCD black test
     */

    printf("lcdb start\n");

    return 0;
}

static int qmsd_test_rs485(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("rs485 start\n");

    return 0;
}

static int qmsd_test_tp(int argc, char **argv)
{
    /*
     * start LCD test
     */

    printf("tp start\n");

    return 0;
}

static void register_qmsd_test(void)
{
    const esp_console_cmd_t start_cmd = {
        .command = "start",
        .help = "start qmsd test",
        .hint = NULL,
        .func = &qmsd_test_start,
    };

    const esp_console_cmd_t lcdr_cmd = {
        .command = "lcdr",
        .help = "start lcd red test",
        .hint = NULL,
        .func = &qmsd_test_lcdr,
    };

    const esp_console_cmd_t lcdg_cmd = {
        .command = "lcdg",
        .help = "start lcd green test",
        .hint = NULL,
        .func = &qmsd_test_lcdg,
    };

    const esp_console_cmd_t lcdb_cmd = {
        .command = "lcdb",
        .help = "start lcd black test",
        .hint = NULL,
        .func = &qmsd_test_lcdb,
    };

    const esp_console_cmd_t rs485_cmd = {
        .command = "rs485",
        .help = "start rs485 test",
        .hint = NULL,
        .func = &qmsd_test_rs485,
    };

    const esp_console_cmd_t tp_cmd = {
        .command = "tp",
        .help = "start tp test",
        .hint = NULL,
        .func = &qmsd_test_tp,
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&start_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdr_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdg_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&lcdb_cmd));
    ESP_ERROR_CHECK(esp_console_cmd_register(&rs485_cmd));
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
    register_qmsd_test();

    ESP_ERROR_CHECK(esp_console_new_repl_uart(&uart_config, &repl_config, &repl));

    ESP_ERROR_CHECK(esp_console_start_repl(repl));
}
