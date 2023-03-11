#include <stdio.h>
#include "string.h"

#include "driver/gpio.h"
#include "qmsd_button.h"

#define TAG "QMSD-BTN"

const char* press_event[] = {"PRESS_DOWN", "PRESS_UP", "PRESS_REPEAT", "SINGLE_CLICK", "DOUBLE_CLICK", "LONG_PRESS_START", "LONG_PRESS_HOLD", "BUTTON_EVENT_MAX", "NONE_PRESS"};
void btn_callback(btn_handle_t handle, void* user_data) {
    printf("BTN %s\r\n", press_event[qmsd_button_get_event(handle)]); 
}

void app_main(void)
{   
    qmsd_button_config_t config = {
        .ticks_interval_ms = 10,
        .debounce_ticks = 2,
        .short_ticks = 500 / 10,
        .long_ticks = 1500 / 10,
        .update_task = {
            .en = 1,
            .core = 1,
            .priority = 1,
        }
    };
    qmsd_button_init(&config);

    btn_handle_t* btn0 = qmsd_button_create_gpio(0, 0, NULL);
    qmsd_button_register_cb(btn0, BUTTON_PRESS_DOWN,       btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_PRESS_UP,         btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_PRESS_REPEAT,     btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_SINGLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_DOUBLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_LONG_PRESS_START, btn_callback);
	qmsd_button_register_cb(btn0, BUTTON_LONG_PRESS_HOLD,  btn_callback);
    qmsd_button_start(btn0);

    btn_handle_t* btn1 = qmsd_button_create_adc(ADC1_CHANNEL_1, 1630, 200, NULL);
    qmsd_button_register_cb(btn1, BUTTON_PRESS_DOWN,       btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_PRESS_UP,         btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_PRESS_REPEAT,     btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_SINGLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_DOUBLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_LONG_PRESS_START, btn_callback);
	qmsd_button_register_cb(btn1, BUTTON_LONG_PRESS_HOLD,  btn_callback);
    qmsd_button_start(btn1);

    btn_handle_t* btn2 = qmsd_button_create_adc(ADC1_CHANNEL_1, 2150, 200, NULL);
    qmsd_button_register_cb(btn2, BUTTON_PRESS_DOWN,       btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_PRESS_UP,         btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_PRESS_REPEAT,     btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_SINGLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_DOUBLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_LONG_PRESS_START, btn_callback);
	qmsd_button_register_cb(btn2, BUTTON_LONG_PRESS_HOLD,  btn_callback);
    qmsd_button_start(btn2);

    btn_handle_t* btn3 = qmsd_button_create_adc(ADC1_CHANNEL_1, 2570, 200, NULL);
    qmsd_button_register_cb(btn3, BUTTON_PRESS_DOWN,       btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_PRESS_UP,         btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_PRESS_REPEAT,     btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_SINGLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_DOUBLE_CLICK,     btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_LONG_PRESS_START, btn_callback);
	qmsd_button_register_cb(btn3, BUTTON_LONG_PRESS_HOLD,  btn_callback);
    qmsd_button_start(btn3);

    for (;;) {
        if (qmsd_button_wait_event(btn0, BUTTON_SINGLE_CLICK, portMAX_DELAY)) {
            printf("___ SINGLE_CLICK ___\r\n");
        }
    }
}
