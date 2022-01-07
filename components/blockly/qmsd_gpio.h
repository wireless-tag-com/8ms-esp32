#ifndef __QMSD_GPIO_H
#define __QMSD_GPIO_H

typedef enum {
	QMSD_GPIO_OUT = 0,      /**< Output. A Mode can also be set */
	QMSD_GPIO_IN = 1,       /**< Input */
	QMSD_GPIO_OUT_HIGH = 2, /**< Output. Init High */
	QMSD_GPIO_OUT_LOW = 3   /**< Output. Init Low */
} qmsd_gpio_dir_t;

typedef void (*qmsd_gpio_isr_t)(void *);

int qmsd_gpio_init(int pin, int dir, int pull_down_en, int pull_up_en);
int qmsd_gpio_uninit(int pin);
int qmsd_gpio_set_intr_type(int pin, int type);
int qmsd_gpio_intr_enable(int pin);
int qmsd_gpio_intr_disable(int pin);
int qmsd_gpio_isr_init(int args);
int qmsd_gpio_isr_uninit(void);
int qmsd_gpio_isr_handler_add(int pin, qmsd_gpio_isr_t isr_handler, void *args);
int qmsd_gpio_isr_handler_remove(int pin);
int qmsd_gpio_set_dir(int pin, int dir);
int qmsd_gpio_get_dir(int pin, int *dir);
int qmsd_gpio_read(int pin);
int qmsd_gpio_write(int pin, int value);

#endif