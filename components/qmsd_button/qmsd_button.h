#pragma once

#include "stdint.h"
#include "string.h"

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

#include "driver/adc.h"

typedef void *btn_handle_t;
typedef void (*btn_callback_t)(btn_handle_t handle, void* user_data);
typedef uint8_t (*btn_get_level_fun_t)(uint8_t scan_start, uint8_t wait_press, void* hardware_data);

typedef enum {
    BUTTON_PRESS_DOWN = 0,
    BUTTON_PRESS_UP,
    BUTTON_PRESS_REPEAT,
    BUTTON_SINGLE_CLICK,
    BUTTON_DOUBLE_CLICK,
    BUTTON_LONG_PRESS_START,
    BUTTON_LONG_PRESS_HOLD,
    BUTTON_EVENT_MAX,
    BUTTON_NONE_PRESS
} press_event_t;

typedef struct {
	uint8_t ticks_interval_ms;
	uint8_t debounce_ticks;
	uint16_t long_ticks;
	uint16_t short_ticks;
	struct {
		uint8_t en: 1;
		uint8_t priority: 7;
		int8_t core;
	} update_task;
} qmsd_button_config_t;

#ifdef __cplusplus
extern "C" {
#endif

void qmsd_button_init(qmsd_button_config_t* config);

btn_handle_t qmsd_button_create(btn_get_level_fun_t get_level, void* hardware_data, uint8_t active_level, void* user_data);

btn_handle_t qmsd_button_create_gpio(uint8_t gpio_num, uint8_t active_level, void* user_data);

btn_handle_t qmsd_button_create_adc(adc1_channel_t adc_channel, uint16_t middle_volt_mv, uint16_t diff_volt_mv, void* user_data);

void qmsd_button_register_cb(btn_handle_t handle, press_event_t event, btn_callback_t cb);

void qmsd_button_unregister_cb(btn_handle_t handle,  press_event_t event);

press_event_t qmsd_button_get_event(btn_handle_t handle);

uint8_t qmsd_button_get_repeat(btn_handle_t btn_handle);

uint8_t qmsd_button_get_level(btn_handle_t btn_handle);

int  qmsd_button_start(btn_handle_t handle);

void qmsd_button_stop(btn_handle_t handle);

void qmsd_button_update(void);

void qmsd_button_reset_event(btn_handle_t btn_handle);

bool qmsd_button_wait_event(btn_handle_t btn_handle, press_event_t event, uint32_t ticks_ms);

#ifdef __cplusplus
}
#endif
