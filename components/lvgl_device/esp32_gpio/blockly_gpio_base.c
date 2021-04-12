#include "blockly_gpio_base.h"

#define TAG "GPIO_BASE" // log tag

/**
 * @brief Initializes the GPIO peripheral .
 * @param gpio_num Specifies the pins. This parameter can be a value of @ref gpio_num_t.
 * @param mode Specifies the operating mode for the selected pins. This parameter can be a value of @ref lv_8ms_gpio_dir_t.
 */

void __lv_8ms_gpio_init(gpio_num_t gpio_num, lv_8ms_gpio_dir_t mode)
{

    gpio_pad_select_gpio(gpio_num);
    switch (mode)
    {
    case LV_8MS_GPIO_OUT:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT));
        break;
    case LV_8MS_GPIO_OUT_OD:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT_OD));
        break;
    case LV_8MS_GPIO_IN_UP:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num, GPIO_PULLUP_ONLY));
        break;
    case LV_8MS_GPIO_IN_DOWN:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num, GPIO_PULLDOWN_ONLY));
        break;
    case LV_8MS_GPIO_IN_FLOATING:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num, GPIO_FLOATING));
        break;
    default:
        break;
    }
}

/**
 * @brief Reads the specified input port pin.
 * @param gpio_num Specifies the pins. This parameter can be a value of @ref gpio_num_t.
 * @return The input port pin value.
 *  This parameter can be one of the BitAction enum values:
 *   @arg LOW: Low level.
 *   @arg HIGH: High level.
 */

lv_8ms_gpio_level_t __lv_8ms_gpio_read(gpio_num_t gpio_num)
{
    lv_8ms_gpio_level_t action = gpio_get_level(gpio_num);
    ESP_LOGI(TAG, "action:%d\n", action);
    return action;
}

/**
 * @brief Sets or clears the selected data port bit.
 * @param gpio_num Specifies the pins. This parameter can be a value of @ref gpio_num_t.
 * @param level  specifies the value to be written to the selected bit.
 *  This parameter can be one of the BitAction enum values:
 *   @arg LOW: Low level.
 *   @arg HIGH: High level.
 */

void __lv_8ms_gpio_write(gpio_num_t gpio_num, lv_8ms_gpio_level_t level)
{
    ESP_ERROR_CHECK(gpio_set_level(gpio_num, level));
    ESP_LOGI(TAG, "num:%d level:%d\n", gpio_num, level);
}
