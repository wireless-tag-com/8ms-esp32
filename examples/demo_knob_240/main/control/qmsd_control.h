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

enum
{
    ENCODER_NONE = 100,
    ENCODER_LEFT,
    ENCODER_RIGHT,
    ENCODER_SHORT_CLICK,
    ENCODER_LONG_CLICK,
};

void qmsd_control_init(void);
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //__CONTROL_H
