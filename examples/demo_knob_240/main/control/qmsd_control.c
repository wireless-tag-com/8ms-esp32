#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_log.h"
#include "qmsd_ctrl.h"
#include "qmsd_control.h"
#include "qmsd_msgque.h"
#include "qmsd_mod.h"
#include "mt8901.h"
#include "qmsd_button.h"

#define TAG "QMSD CTRL"

#define ECO_O(y) (y>0)? -1:1
#define ECO_STEP(x) x? ECO_O(x):0

void qmsd_control_init(void)
{
    mt8901_init(16, 17);
    qmsd_button_config_t config = {
        .ticks_interval_ms = 10,
        .debounce_ticks = 2,
        .short_ticks = 200 / 10,
        .long_ticks = 1000 / 10,
        .update_task = {
            .en = 1,
            .core = 1,
            .priority = 1,
        }};
    qmsd_button_init(&config);

    btn_handle_t *btn0 = qmsd_button_create_gpio(7, 1, NULL);
    qmsd_button_start(btn0);
    for (;;)
    {
        static int16_t cont_last = 0;
        int16_t cont_now = mt8901_get_count();
        int16_t enc_diff = ECO_STEP(cont_now - cont_last);
        cont_last = cont_now;
        if (enc_diff == 1)
        {
            // 右转
            qmsd_notifier_call(ENCODER_RIGHT,NULL);
        }
        else if(enc_diff == -1)
        {
            // 左转
            qmsd_notifier_call(ENCODER_LEFT,NULL);
        }
        else
        {
            qmsd_notifier_call(ENCODER_NONE,NULL);
        }

        if (qmsd_button_wait_event(btn0, BUTTON_SINGLE_CLICK, pdMS_TO_TICKS(0)))
        {
            // 短按
            qmsd_notifier_call(ENCODER_SHORT_CLICK,NULL);
        }
        if (qmsd_button_wait_event(btn0, BUTTON_LONG_PRESS_START, pdMS_TO_TICKS(0)))
        {
            // 长按
            qmsd_notifier_call(ENCODER_LONG_CLICK,NULL);
        }
        vTaskDelay(pdMS_TO_TICKS(20));
    }
}

