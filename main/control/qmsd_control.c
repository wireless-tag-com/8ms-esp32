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

#define TAG "QMSD CTRL"
void qmsd_control_init(void)
{
    while (1) {
        void *msg;
        unsigned int msglen;
        int ret_msg;
        ret_msg = qmsd_main_msgque_recv((void **)&msg, &msglen, pdMS_TO_TICKS(10));
        if (ret_msg == 0) {
            /*
             * handle ui cb event
             * qmsd_mod_call()
             * cmd will be deleted in mod cb
             */
            
            cJSON* cmd = cJSON_Parse(msg);
            esp_err_t ret;

            if (cmd)
                ret = qmsd_mod_call(cmd);
            
            if (ret != ESP_OK)
            {
                /* code */
            }

            free(msg);
            vTaskDelay(pdMS_TO_TICKS(10));
        } else {
            vTaskDelay(pdMS_TO_TICKS(30));
        }
    }
}

void qmsd_sync_call_back(cJSON *data)
{
    printf("-----------------------\r\n");
    char *p = cJSON_Print(data);
    printf("%s\r\n", p);
    free(p);
    cJSON_Delete(data);
    printf("-----------------------\r\n");
}

void qmsd_asyn_call_back(cJSON *data, asyn_handler_event_t event_id)
{
    printf("-----------------------\r\n");
    char *p = cJSON_Print(data);
    switch (event_id)
    {
    case ASYN_EVENT_WIFI_SCAN:
        printf("%s\r\n", p);
        ESP_LOGI(TAG, "ASYN_EVENT_WIFI_SCAN");
        break;
    case ASYN_EVENT_UDP_DATA:
        printf("%s\r\n", p);
        ESP_LOGI(TAG, "ASYN_EVENT_UDP_DATA");
        break;
    case ASYN_EVENT_TCP_CLIENT:
        printf("%s\r\n", p);
        ESP_LOGI(TAG, "ASYN_EVENT_TCP_CLIENT");
        break;
    case ASYN_EVENT_TCP_SERVER:
        printf("%s\r\n", p);
        ESP_LOGI(TAG, "ASYN_EVENT_TCP_SERVER");
        break;
    case ASYN_EVENT_MQTT_DATA:
        printf("%s\r\n", p);
        ESP_LOGI(TAG, "ASYN_EVENT_MQTT_DATA");
        break;
    default:
        break;
    }
    free(p);
    cJSON_Delete(data);
    printf("-----------------------\r\n");
}
