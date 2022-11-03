#include <sdkconfig.h>
#ifdef CONFIG_ZX3D95CE01S_AR_4848
#include <stdio.h>
#include "esxxx_common.h"
#include "audio_hal.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "driver/i2c.h"
#include "driver/i2s.h"
#include "zx_es8388.h"

#define DEVICE_RST        (-1)

// I2S
#define BOARD_I2S_NUM      (I2S_NUM_1)
#define I2S_SCLK_PIN       (GPIO_NUM_48)
#define I2S_LRCK_PIN       (GPIO_NUM_47)
#define I2S_MCLK_PIN       (GPIO_NUM_38)
#define I2S_SDIN_PIN       (GPIO_NUM_21)
#define I2S_DOUT_PIN       (GPIO_NUM_39)

// CodeC IIC
#define CODEC_IIC_SCL   6
#define CODEC_IIC_SDA   7

#define TOUCH_IIC_SCL   6
#define TOUCH_IIC_SDA   7

#define RS485_TX        4
#define RS485_RX        5

#define CODEC_ADC_SAMPLE_RATE 16000
#define CODEC_ADC_BITS_PER_SAMPLE I2S_BITS_PER_SAMPLE_32BIT

#define I2S_CONFIG_DEFAULT() { \
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_RX),      \
    .sample_rate = CODEC_ADC_SAMPLE_RATE,                                   \
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,                           \
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,                           \
    .communication_format = I2S_COMM_FORMAT_STAND_I2S,                      \
    .intr_alloc_flags = ESP_INTR_FLAG_LOWMED | ESP_INTR_FLAG_IRAM | ESP_INTR_FLAG_SHARED, \
    .dma_buf_count = 3,                                                     \
    .dma_buf_len = 160,                                                     \
    .use_apll = true,                                                       \
    .tx_desc_auto_clear = true,                                             \
    .fixed_mclk = 0                                                         \
}

#define AUDIO_CODEC_DEFAULT_CONFIG() {                   \
        .adc_input  = AUDIO_HAL_ADC_INPUT_DIFFERENCE,   \
        .dac_output = AUDIO_HAL_DAC_OUTPUT_LINE1,       \
        .codec_mode = AUDIO_HAL_CODEC_MODE_BOTH,        \
        .i2s_iface = {                                  \
            .mode = AUDIO_HAL_MODE_SLAVE,               \
            .fmt = AUDIO_HAL_I2S_NORMAL,                \
            .samples = CODEC_ADC_SAMPLE_RATE,           \
            .bits = AUDIO_HAL_BIT_LENGTH_16BITS,        \
        },                                              \
};

static bool g_audio_init;

audio_hal_func_t* audio_hal;
extern audio_hal_func_t AUDIO_CODEC_ZX_ES8388_DEFAULT_HANDLE;

#define ADC_I2S_CHANNEL 4

esp_err_t board_get_feed_data(int16_t *buffer, int buffer_len)
{
    esp_err_t ret = ESP_OK;
    if (g_audio_init) {
        size_t bytes_read;
        int audio_chunksize = buffer_len / (sizeof(int16_t) * ADC_I2S_CHANNEL);
        ret = i2s_read(BOARD_I2S_NUM, buffer, buffer_len, &bytes_read, portMAX_DELAY);
        for (int i = 0; i < audio_chunksize; i++) {
            buffer[3 * i + 0] = buffer[4 * i + 1];
            buffer[3 * i + 1] = buffer[4 * i + 3];
            buffer[3 * i + 2] = 0;
        }
        return ret;
    } else {
        return ESP_FAIL;
    }
}

esp_err_t board_codec_init(void)
{
    esp_err_t ret = 0;

    zx_es8388_i2c_init(I2C_NUM_0, 7, 6);

    audio_hal = &AUDIO_CODEC_ZX_ES8388_DEFAULT_HANDLE;
    audio_hal_codec_config_t audio_codec_cfg = AUDIO_CODEC_DEFAULT_CONFIG();
    ret = audio_hal->audio_codec_initialize(&audio_codec_cfg);
    ret |= audio_hal->audio_codec_config_iface(audio_codec_cfg.codec_mode, &audio_codec_cfg.i2s_iface);
    ret |= audio_hal->audio_codec_set_volume(AUDIO_HAL_VOL_DEFAULT);

    audio_hal->handle = audio_hal;

    g_audio_init = true;
    return ret;
}

esp_err_t board_i2s_init(void)
{
    esp_err_t ret_val = ESP_OK;
    i2s_pin_config_t pin_config = {
        .bck_io_num = I2S_SCLK_PIN,
        .ws_io_num = I2S_LRCK_PIN,
        .data_out_num = I2S_DOUT_PIN,
        .data_in_num = I2S_SDIN_PIN,
        .mck_io_num = I2S_MCLK_PIN,
    };
    i2s_config_t i2s_config = I2S_CONFIG_DEFAULT();
    i2s_config.sample_rate = CODEC_ADC_SAMPLE_RATE;
    i2s_config.bits_per_sample = CODEC_ADC_BITS_PER_SAMPLE;
    i2s_config.use_apll = false;
    ret_val |= i2s_driver_install(BOARD_I2S_NUM, &i2s_config, 0, NULL);
    ret_val |= i2s_set_pin(BOARD_I2S_NUM, &pin_config);
    return ret_val;
}

int board_get_feed_channel(void)
{
    return ADC_I2S_CHANNEL;
}

#define ECHO_UART_BAUD_RATE     (115200)
#define ECHO_TASK_STACK_SIZE    (4 * 1024)

#define BUF_SIZE (1024)

void rs485_init(void)
{
    uart_config_t uart_config = {
        .baud_rate = ECHO_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    int intr_alloc_flags = 0;
    intr_alloc_flags = ESP_INTR_FLAG_SHARED;
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM_1, BUF_SIZE * 2, 0, 0, NULL, intr_alloc_flags));
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, RS485_TX, RS485_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}

void board_init(void)
{
    rs485_init();
    board_codec_init();
    board_i2s_init();
}
#endif