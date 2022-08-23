#pragma once

#include "stdint.h"
#include "qmsd_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#define KEY_ANY -1

typedef const char* qmsd_event_base_t;

typedef void (*qmsd_notify_handler_t)(void* user_data, qmsd_event_base_t event_base, int32_t key, void* post_data);

qmsd_err_t qmsd_notify_init(uint32_t queue_size, uint32_t task_priority);

qmsd_err_t qmsd_notify_post(int32_t key, void* data, uint32_t length, uint32_t timeout_ticks);

qmsd_err_t qmsd_notify_callback_register(int32_t key, qmsd_notify_handler_t handler, void* user_data);

qmsd_err_t qmsd_notify_callback_unregister(int32_t key, qmsd_notify_handler_t handler);

#ifdef __cplusplus
}
#endif
