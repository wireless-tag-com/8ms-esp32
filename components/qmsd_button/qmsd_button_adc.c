#include "driver/adc.h"
#include "esp_log.h"
#include "esp_adc_cal.h"
#include "qmsd_button.h"

#define TAG "BTN_ADC"

#define ADC_BUTTON_WIDTH        ADC_WIDTH_MAX-1
#define ADC_BUTTON_ATTEN        ADC_ATTEN_DB_11
#define ADC_BUTTON_ADC_UNIT     ADC_UNIT_1
#define ADC_DEFAULT_VREF        1100
#define ADC_NUM_OF_SAMPLES      1

typedef struct {
    esp_adc_cal_characteristics_t adc_chars;
    uint8_t is_configured;
    struct {
        uint8_t is_init;
        uint16_t volt_mv;
    } channel[ADC1_CHANNEL_MAX];
} adc_data_t;

typedef struct {
    uint8_t channel;
    uint16_t max_volt_mv;
    uint16_t min_volt_mv;
} btn_hw_info_t;

static adc_data_t g_btn = {0};

uint16_t get_volt_mv(adc1_channel_t channel) {
    uint32_t adc_reading = 0;

    for (int i = 0; i < ADC_NUM_OF_SAMPLES; i++) {
        adc_reading += adc1_get_raw(channel);
    }
    adc_reading /= ADC_NUM_OF_SAMPLES;

    //Convert adc_reading to voltage in mV
    uint32_t voltage = esp_adc_cal_raw_to_voltage(adc_reading, &g_btn.adc_chars);
    return voltage;
}

uint8_t qmsd_button_adc_read(uint8_t scan_start, uint8_t wait_press, void* hardware_data) {
    if (scan_start) {
        for (uint8_t i = 0; i < ADC1_CHANNEL_MAX; i++) {
            if (g_btn.channel[i].is_init) {
                g_btn.channel[i].volt_mv = get_volt_mv(i);
            }
        }
    }
    btn_hw_info_t* hw_info = hardware_data;
    return g_btn.channel[hw_info->channel].volt_mv > hw_info->max_volt_mv || g_btn.channel[hw_info->channel].volt_mv < hw_info->min_volt_mv;
}

// ESP32S3 only support ADC1: 10 channels: GPIO1 - GPIO10
btn_handle_t qmsd_button_create_adc(adc1_channel_t adc_channel, uint16_t middle_volt_mv, uint16_t diff_volt_mv, void* user_data) {
    if (g_btn.is_configured == 0) {
        //Configure ADC
        adc1_config_width(ADC_BUTTON_WIDTH);
        //Characterize ADC
        esp_adc_cal_value_t val_type = esp_adc_cal_characterize(ADC_BUTTON_ADC_UNIT, ADC_BUTTON_ATTEN, ADC_BUTTON_WIDTH, ADC_DEFAULT_VREF, &g_btn.adc_chars);
        if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) {
            ESP_LOGI(TAG, "Characterized using Two Point Value");
        } else if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) {
            ESP_LOGI(TAG, "Characterized using eFuse Vref");
        } else {
            ESP_LOGI(TAG, "Characterized using Default Vref");
        }
        g_btn.is_configured = 1;
    }

    if (g_btn.channel[adc_channel].is_init == 0) {
        adc1_config_channel_atten(adc_channel, ADC_BUTTON_ATTEN);
        g_btn.channel[adc_channel].is_init = 1;
    }
    btn_hw_info_t* hw_info = (btn_hw_info_t *)malloc(sizeof(btn_hw_info_t));
    hw_info->channel = adc_channel;
    hw_info->max_volt_mv = middle_volt_mv + diff_volt_mv;
    if (diff_volt_mv > middle_volt_mv) {
        hw_info->min_volt_mv = 0;    
    } else {
        hw_info->min_volt_mv = middle_volt_mv - diff_volt_mv;
    }

    return qmsd_button_create(qmsd_button_adc_read, (void *)hw_info, 0, user_data);
}
