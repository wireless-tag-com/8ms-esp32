#ifndef __LV_8MS_GPIO_H
#define __LV_8MS_GPIO_H

typedef enum {
	LV_8MS_GPIO_OUT = 0,      /**< Output. A Mode can also be set */
	LV_8MS_GPIO_IN = 1,       /**< Input */
	LV_8MS_GPIO_OUT_HIGH = 2, /**< Output. Init High */
	LV_8MS_GPIO_OUT_LOW = 3   /**< Output. Init Low */
} lv_8ms_gpio_dir_t;

typedef void (*lv_8ms_gpio_isr_t)(void *);

int lv_8ms_gpio_init(int pin, int dir, int pull_down_en, int pull_up_en);
int lv_8ms_gpio_uninit(int pin);
int lv_8ms_gpio_set_intr_type(int pin, int type);
int lv_8ms_gpio_intr_enable(int pin);
int lv_8ms_gpio_intr_disable(int pin);
int lv_8ms_gpio_isr_init(int args);
int lv_8ms_gpio_isr_uninit(void);
int lv_8ms_gpio_isr_handler_add(int pin, lv_8ms_gpio_isr_t isr_handler, void *args);
int lv_8ms_gpio_isr_handler_remove(int pin);
int lv_8ms_gpio_set_dir(int pin, int dir);
int lv_8ms_gpio_get_dir(int pin, int *dir);
int lv_8ms_gpio_read(int pin);
int lv_8ms_gpio_write(int pin, int value);

#endif