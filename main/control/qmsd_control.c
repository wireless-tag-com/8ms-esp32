#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "freertos/semphr.h"
#include "esp_system.h"
#include "esp_event.h"
#include "lvgl.h"
#include "qmsd_ctrl.h"
#include "qmsd_blockly.h"
#include "qmsd_control.h"

static esp_event_handler_instance_t g_qmsd_any_id;

const char *QMSD_CTRL_EVENT = "QMSD_CTRL_EVENT";

static void __qmsd_ctrl_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    /*
     * it is example for QMSD_CTRL event handle
     */
    switch (event_id) {
        case QMSD_CTRL_MOD_CALL:
            {
                qmsd_ctrl_mod_param *event = (qmsd_ctrl_mod_param*) event_data;
                if (event->json) {
                    printf("%s\n", cJSON_PrintUnformatted(event->json));
                    cJSON_Delete(event->json);
                }
            }
            break;
    }
}

int qmsd_ctrl_event_send(int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait)
{
    esp_err_t err;
    err = esp_event_post(QMSD_CTRL_EVENT, event_id, event_data, event_data_size, ticks_to_wait);
    if (err == ESP_OK) {
        return 0;
    } else {
        return -1;
    }
}

int qmsd_ctrl_event_isr_send(int32_t event_id, void *event_data, size_t event_data_size, BaseType_t *task_unblocked)
{
    esp_err_t err;
    err = esp_event_isr_post(QMSD_CTRL_EVENT, event_id, event_data, event_data_size, task_unblocked);
    if (err == ESP_OK) {
        return 0;
    } else {
        return -1;
    }
}

void qmsd_control_init(void)
{
    esp_event_loop_create_default();

    esp_event_handler_instance_register(QMSD_CTRL_EVENT, ESP_EVENT_ANY_ID, &__qmsd_ctrl_event_handler, NULL, &g_qmsd_any_id);
}
