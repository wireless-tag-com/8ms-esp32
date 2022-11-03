#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "qmsd_api.h"

int qmsd_gpio_init(int pin, int dir, int pull_down_en, int pull_up_en)
{
    esp_err_t ret;
    gpio_config_t io_conf;

    io_conf.intr_type = GPIO_INTR_DISABLE;
    if (dir == QMSD_GPIO_IN)
        io_conf.mode = GPIO_MODE_INPUT;
    else
        io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1 << pin);
    io_conf.pull_down_en = pull_down_en;
    io_conf.pull_up_en = pull_up_en;
    ret = gpio_config(&io_conf);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_set_intr_type(int pin, int type)
{
    esp_err_t ret;
    ret = gpio_set_intr_type(pin, type);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_intr_enable(int pin)
{
    esp_err_t ret;
    ret = gpio_intr_enable(pin);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_intr_disable(int pin)
{
    esp_err_t ret;
    ret = gpio_intr_disable(pin);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_isr_init(int args)
{
    esp_err_t ret;
    ret = gpio_install_isr_service(args);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1; 
}

int qmsd_gpio_isr_uninit(void)
{
    gpio_uninstall_isr_service();
    return 0;
}

int qmsd_gpio_isr_handler_add(int pin, gpio_isr_t isr_handler, void *args)
{
    esp_err_t ret;
    ret = gpio_isr_handler_add(pin, isr_handler, args);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_isr_handler_remove(int pin)
{
    esp_err_t ret;
    ret = gpio_isr_handler_remove(pin);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_uninit(int pin)
{
    esp_err_t ret;
    ret = gpio_reset_pin(pin);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_set_dir(int pin, int dir)
{
    esp_err_t ret;
    ret = gpio_set_direction(pin, dir);
    if (ret == ESP_OK)
        return 0;
    else
	    return -1;
}

int qmsd_gpio_get_dir(int pin, int *dir)
{
    return -1;
}

int qmsd_gpio_read(int pin)
{
    return gpio_get_level(pin);
}

int qmsd_gpio_write(int pin, int value)
{
    gpio_set_level(pin, value);
    return 0;
}
