#ifndef __QMSD_CONTROL_H
#define __QMSD_CONTROL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_event.h"
#include <stdbool.h>

const char *QMSD_CTRL_EVENT;

typedef enum {
    QMSD_CTRL_WIFI_STA_SET_CONFIG,               /* set sta wifi sta config(ssid/password) in nvs */
    QMSD_CTRL_WIFI_CLEAR_CONFIG,              /* clear wifi config(nvs) */
    QMSD_CTRL_WIFI_STA_START,              /* start wifi connect */
    QMSD_CTRL_WIFI_STA_STOP,         /* stop wifi */
    QMSD_CTRL_WIFI_STA_SCAN,                  /* start wifi scan */
    QMSD_CTRL_GPIO_ISR,           /* gpio isr */
} qmsd_ctrl_event_t;

typedef struct {
    const char *ssid;
    const char *password;
    uint8_t enable;
} qmsd_ctrl_event_wifi_config;

void qmsd_control_init(void);

int qmsd_ctrl_event_send(int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait);
int qmsd_ctrl_event_isr_send(int32_t event_id, void *event_data, size_t event_data_size, BaseType_t *task_unblocked);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__CONTROL_H
