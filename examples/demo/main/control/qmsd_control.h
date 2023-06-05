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

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__QMSD_CONTROL_H
