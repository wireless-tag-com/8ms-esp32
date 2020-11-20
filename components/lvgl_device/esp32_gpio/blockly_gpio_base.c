#include "blockly_gpio_base.h"

#define TAG "GPIO_BASE" // log输出的标签

/**
 * @brief Initializes the GPIO peripheral .
 * @param gpio_num Specifies the pins. This parameter can be a value of @ref gpio_num_t.
 * @param mode Specifies the operating mode for the selected pins. This parameter can be a value of @ref gpio_pinmode_t.
 */

void __pinMode(gpio_num_t gpio_num, gpio_pinmode_t mode)
{
    
    gpio_pad_select_gpio(gpio_num);
    switch (mode)
    {
    case OUTPUT:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT));
        break;
    case OUTPUT_OD:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_OUTPUT_OD));
        break;
    case INPUT_PULLUP:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num,GPIO_PULLUP_ONLY));
        break;
    case INPUT_PULLDOWN:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num,GPIO_PULLDOWN_ONLY));
        break;
    case INPUT_FLOATING:
        ESP_ERROR_CHECK(gpio_set_direction(gpio_num, GPIO_MODE_INPUT));
        ESP_ERROR_CHECK(gpio_set_pull_mode(gpio_num,GPIO_FLOATING));
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

gpio_action_t __digitalRead(gpio_num_t gpio_num)
{
    gpio_action_t action = gpio_get_level(gpio_num);
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

void __digitalWrite(gpio_num_t gpio_num, gpio_action_t level)
{
    ESP_ERROR_CHECK(gpio_set_level(gpio_num, level));
    ESP_LOGI(TAG, "num:%d level:%d\n",gpio_num, level);
}
