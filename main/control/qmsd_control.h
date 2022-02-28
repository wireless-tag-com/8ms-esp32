#ifndef __QMSD_CONTROL_H
#define __QMSD_CONTROL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_event.h"
#include <stdbool.h>
#include "cJSON.h"

const char *QMSD_CTRL_EVENT;

typedef enum {
    QMSD_CTRL_MOD_CALL,         /* call qmsd */
} qmsd_ctrl_event_t;

typedef struct {
    cJSON *json;
} qmsd_ctrl_mod_param;

void qmsd_control_init(void);

int qmsd_ctrl_event_send(int32_t event_id, void *event_data, size_t event_data_size, TickType_t ticks_to_wait);
int qmsd_ctrl_event_isr_send(int32_t event_id, void *event_data, size_t event_data_size, BaseType_t *task_unblocked);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__CONTROL_H
