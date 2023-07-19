
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "driver/uart.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "qmsd_api.h"
#include "qmsd_ctrl.h"

#define PROMPT_STR "ZX"

#define TAG "test"

typedef struct {
    struct arg_str *url;
    struct arg_end *end;
} ota_args_t;

typedef struct {
    struct arg_str *ssid;
    struct arg_str *password;
    struct arg_end *end;
} wifi_args_t;

typedef struct {
    struct arg_str *json;
    struct arg_end *end;
} ui_args_t;

static ota_args_t ota_args;
static wifi_args_t sta_args;
static ui_args_t ui_args;

static int __qmsd_ota_start(int argc, char **argv)
{
    int nerrors = arg_parse(argc, argv, (void **) &ota_args);
    if (nerrors != 0) {
        arg_print_errors(stderr, ota_args.end, argv[0]);
        return 1;
    }

    printf("start ota %s\n", ota_args.url->sval[0]);
    qmsd_ota_low_start(ota_args.url->sval[0]);

    return 0;
}

static bool wifi_cmd_sta_join(const char *ssid, const char *pass)
{
    qmsd_wifi_set_mode(WIFI_MODE_STA);
    qmsd_wifi_sta_config(ssid, pass, NULL);

    return true;
}

static int wifi_cmd_sta(int argc, char **argv)
{
    int nerrors = arg_parse(argc, argv, (void **) &sta_args);

    if (nerrors != 0) {
        arg_print_errors(stderr, sta_args.end, argv[0]);
        return 1;
    }

    ESP_LOGI(TAG, "sta connecting to '%s'", sta_args.ssid->sval[0]);
    wifi_cmd_sta_join(sta_args.ssid->sval[0], sta_args.password->sval[0]);
    return 0;
}

static int ui_cmd_sta(int argc, char **argv)
{
    int nerrors = arg_parse(argc, argv, (void **) &ui_args);
    char *res;
    if (nerrors != 0) {
        arg_print_errors(stderr, ui_args.end, argv[0]);
        return 1;
    }

    res = qmsd_ctrl_str_sync(ui_args.json->sval[0]);
    if (res)
        printf("res: %s\n", res);

    return 0;
}

static void register_qmsd_test(void)
{
    ota_args.url = arg_str0(NULL, NULL, "<url>", "url for ota");
    ota_args.end = arg_end(1);

    const esp_console_cmd_t ota_cmd = {
        .command = "ota",
        .help = "start qmsd ota test",
        .hint = NULL,
        .func = &__qmsd_ota_start,
        .argtable = &ota_args,
    };

    ESP_ERROR_CHECK(esp_console_cmd_register(&ota_cmd));

    sta_args.ssid = arg_str1(NULL, NULL, "<ssid>", "SSID of AP");
    sta_args.password = arg_str0(NULL, NULL, "<pass>", "password of AP");
    sta_args.end = arg_end(2);

    const esp_console_cmd_t sta_cmd = {
        .command = "sta",
        .help = "WiFi is station mode, join specified soft-AP",
        .hint = NULL,
        .func = &wifi_cmd_sta,
        .argtable = &sta_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&sta_cmd) );

    ui_args.json = arg_str1(NULL, NULL, "<json>", "8ms ui ctrl json str");
    ui_args.end = arg_end(1);

    const esp_console_cmd_t ui_cmd = {
        .command = "8ms",
        .help = "8ms json",
        .hint = NULL,
        .func = &ui_cmd_sta,
        .argtable = &ui_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&ui_cmd) );
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
    repl_config.max_cmdline_length = 512;

    /* Register commands */
    esp_console_register_help_command();
    register_qmsd_test();

    ESP_ERROR_CHECK(esp_console_new_repl_uart(&uart_config, &repl_config, &repl));

    ESP_ERROR_CHECK(esp_console_start_repl(repl));
}
