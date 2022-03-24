#ifndef __QMSD_CONTROL_H
#define __QMSD_CONTROL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "esp_event.h"
#include <stdbool.h>
#include "cJSON.h"
#include "qmsd_mod.h"

void qmsd_control_init(void);
void qmsd_sync_call_back(cJSON *data);
void qmsd_asyn_call_back(cJSON *data, asyn_handler_event_t event_id);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__CONTROL_H
