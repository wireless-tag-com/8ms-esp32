
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "esp_system.h"
#include "esp_event.h"
#include "cJSON.h"


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "esp_log.h"
#include "qmsd_api.h"

#define MQTT_QOS    0
#define MQTT_URI "mqtt://test.mqtt:1883"
#define MQTT_USERNAME   "test"
#define MQTT_PWD    "pwd"
void qmsd_mqtt_app_start(void)
{
    esp_mqtt_client_config_t mqtt_cfg = {
        .uri = MQTT_URI,
        .keepalive = 60,
        .reconnect_timeout_ms = 5000,
        .username = MQTT_USERNAME,
        .password = MQTT_PWD,
    };

    qmsd_mqtt_start(&mqtt_cfg);
}

void qmsd_mqtt_handle_event(const char *topic, char *payload, int len)
{
    printf("topic: %s\n", topic);
}

void qmsd_mqtt_app_stop(void)
{
    qmsd_mqtt_stop();
}
