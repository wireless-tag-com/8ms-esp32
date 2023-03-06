
#include "qmsd_button.h"

#define BTN_EVENT_CB(ev) do { \
	xEventGroupSetBits(handle->event_group, 1 << ev);	\
	if(handle->cb[ev]) { \
		handle->cb[ev]((btn_handle_t)handle, handle->user_data); \
	} \
} while (0)

typedef struct _btn_data_t {
	uint16_t ticks;
	uint8_t  repeat;
	uint8_t  event;
	uint8_t  state : 3;
	uint8_t  debounce_cnt : 3;
	uint8_t  active_level : 1;
	uint8_t  button_level : 1;
	btn_get_level_fun_t get_level;
	void* hardware_data;
	void* user_data;
	btn_callback_t cb[BUTTON_EVENT_MAX];
	EventGroupHandle_t event_group;
	struct _btn_data_t* next;
} btn_data_t;

//button handle list head.
static btn_data_t* g_head_handle = NULL;
static qmsd_button_config_t* g_button_config = NULL;

static void qmsd_button_update_task(void *arg);

void qmsd_button_init(qmsd_button_config_t* config) {
	g_button_config = (qmsd_button_config_t *)calloc(1, sizeof(qmsd_button_config_t));
	memcpy(g_button_config, config, sizeof(qmsd_button_config_t));
	if (g_button_config->update_task.en) {
        xTaskCreatePinnedToCore(qmsd_button_update_task, "btn-update", 4 * 1024, NULL, g_button_config->update_task.priority, NULL, g_button_config->update_task.core);
    }
}

btn_handle_t qmsd_button_create(btn_get_level_fun_t get_level, void* hardware_data, uint8_t active_level, void* user_data)
{
	btn_data_t* handle = (btn_data_t *)calloc(1, sizeof(btn_data_t));
	handle->event = (uint8_t)BUTTON_NONE_PRESS;
	handle->get_level = get_level;
	handle->button_level = handle->get_level(1, handle->state == 0 || handle->state == 2, hardware_data);
	handle->hardware_data = hardware_data;
	handle->user_data = user_data;
	handle->active_level = active_level;
	handle->event_group = xEventGroupCreate();
	return (btn_handle_t)handle;
}

void qmsd_button_register_cb(btn_handle_t handle, press_event_t event, btn_callback_t cb)
{
	btn_data_t* btn = (btn_data_t*)handle;
	btn->cb[event] = cb;
}

void qmsd_button_unregister_cb(btn_handle_t handle,  press_event_t event)
{
	btn_data_t* btn = (btn_data_t*)handle;
	btn->cb[event] = NULL;
}

press_event_t qmsd_button_get_event(btn_handle_t btn_handle)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	return (press_event_t)(handle->event);
}

uint8_t qmsd_button_get_repeat(btn_handle_t btn_handle)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	return handle->repeat;
}

static void button_handler(uint8_t scan_start, btn_data_t* handle)
{
	uint8_t read_gpio_level = handle->get_level(scan_start, handle->state == 0 || handle->state == 2, handle->hardware_data);

	//ticks counter working..
	if((handle->state) > 0) handle->ticks++;

	/*------------button debounce handle---------------*/
	if(read_gpio_level != handle->button_level) { //not equal to prev one
		//continue read 3 times same new level change
		if(++(handle->debounce_cnt) >= g_button_config->debounce_ticks) {
			handle->button_level = read_gpio_level;
			handle->debounce_cnt = 0;
		}
	} else { //level not change ,counter reset.
		handle->debounce_cnt = 0;
	}

	/*-----------------State machine-------------------*/
	switch (handle->state) {
		case 0:
			if(handle->button_level == handle->active_level) {	//start press down
				handle->event = (uint8_t)BUTTON_PRESS_DOWN;
				BTN_EVENT_CB(BUTTON_PRESS_DOWN);
				handle->ticks = 0;
				handle->repeat = 1;
				handle->state = 1;
			} else {
				handle->event = (uint8_t)BUTTON_NONE_PRESS;
			}
			break;

		case 1:
			if(handle->button_level != handle->active_level) { //released press up
				handle->event = (uint8_t)BUTTON_PRESS_UP;
				BTN_EVENT_CB(BUTTON_PRESS_UP);
				handle->ticks = 0;
				handle->state = 2;

			} else if(handle->ticks > g_button_config->long_ticks) {
				handle->event = (uint8_t)BUTTON_LONG_PRESS_START;
				BTN_EVENT_CB(BUTTON_LONG_PRESS_START);
				handle->state = 5;
			}
			break;

		case 2:
			if(handle->button_level == handle->active_level) { //press down again
				handle->event = (uint8_t)BUTTON_PRESS_DOWN;
				BTN_EVENT_CB(BUTTON_PRESS_DOWN);
				handle->repeat++;
				handle->event = (uint8_t)BUTTON_PRESS_REPEAT;
				BTN_EVENT_CB(BUTTON_PRESS_REPEAT); // repeat hit
				handle->ticks = 0;
				handle->state = 3;
			} else if(handle->ticks > g_button_config->short_ticks) { //released timeout
				if(handle->repeat == 1) {
					handle->event = (uint8_t)BUTTON_SINGLE_CLICK;
					BTN_EVENT_CB(BUTTON_SINGLE_CLICK);
				} else if(handle->repeat == 2) {
					handle->event = (uint8_t)BUTTON_DOUBLE_CLICK;
					BTN_EVENT_CB(BUTTON_DOUBLE_CLICK); // repeat hit
				}
				handle->state = 0;
			}
			break;

		case 3:
			if(handle->button_level != handle->active_level) { //released press up
				handle->event = (uint8_t)BUTTON_PRESS_UP;
				BTN_EVENT_CB(BUTTON_PRESS_UP);
				if(handle->ticks < g_button_config->short_ticks) {
					handle->ticks = 0;
					handle->state = 2; //repeat press
				} else {
					handle->state = 0;
				}
			} else if(handle->ticks > g_button_config->long_ticks){ // long press up
				handle->state = 1;
			}
			break;

		case 5:
			if(handle->button_level == handle->active_level) {
				//continue hold trigger
				handle->event = (uint8_t)BUTTON_LONG_PRESS_HOLD;
				BTN_EVENT_CB(BUTTON_LONG_PRESS_HOLD);
			} else { //released
				handle->event = (uint8_t)BUTTON_PRESS_UP;
				BTN_EVENT_CB(BUTTON_PRESS_UP);
				handle->state = 0; //reset
			}
			break;
		default:
			handle->state = 0; //reset
			break;
	}
}

uint8_t qmsd_button_get_level(btn_handle_t btn_handle) {
	btn_data_t* handle = (btn_data_t*)btn_handle;
	if (g_button_config && g_button_config->update_task.en && handle->next) {
		return handle->button_level;
	}

	return handle->get_level(1, handle->state == 0 || handle->state == 2, handle->hardware_data);
}

int qmsd_button_start(btn_handle_t btn_handle)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	btn_data_t* target = g_head_handle;
	while(target) {
		if(target == handle) return -1;	//already exist.
		target = target->next;
	}
	handle->next = g_head_handle;
	g_head_handle = handle;
	return 0;
}

void qmsd_button_stop(btn_handle_t btn_handle)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	btn_data_t** curr;
	for(curr = &g_head_handle; *curr; ) {
		btn_data_t* entry = *curr;
		if (entry == handle) {
			*curr = entry->next;
			return; //glacier add 2021-8-18
		} else {
			curr = &entry->next;
		}
	}
}

void qmsd_button_update()
{
	btn_data_t* target;
	for(target = g_head_handle; target; target = target->next) {
		button_handler(target == g_head_handle, target);
	}
}

void qmsd_button_reset_event(btn_handle_t btn_handle)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	xEventGroupClearBits(handle->event_group, 0xffffff);
}

bool qmsd_button_wait_event(btn_handle_t btn_handle, press_event_t event, uint32_t ticks_ms)
{
	btn_data_t* handle = (btn_data_t*)btn_handle;
	EventBits_t wait_bits = 1 << event;

	return (xEventGroupWaitBits(handle->event_group, wait_bits, true, false, pdMS_TO_TICKS(ticks_ms)) & wait_bits) > 0x00;
}

static void qmsd_button_update_task(void *arg)
{
	for (;;) {
		qmsd_button_update();
		vTaskDelay(pdMS_TO_TICKS(g_button_config->ticks_interval_ms));
	}
}
