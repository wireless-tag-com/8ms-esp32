#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "sht20.h"
#include "i2c_device.h"

#define MEASUREMENT_DELAY_MS 1000

static float sht20_temperature = 0.0;
static float sht20_humidity = 0.0;

static I2CDevice_t sht20_device;
static SemaphoreHandle_t sht20_mutex;


static uint8_t sht20_check_crc(uint8_t* data, char bytes, char checksum) {
    char crc = 0;
    char bit = 0;
	
    for(uint8_t i = 0; i < bytes; i ++ ) {
        crc ^= (data[i]);
        for ( bit = 8; bit > 0; --bit) {
            if (crc & 0x80) {
                crc = (crc << 1) ^ 0x131;
            } else {
                crc = (crc << 1);
            }
        }
    }
    return checksum == crc;
}

static void sht20_read_task(void *arg) {
    uint8_t data[3];
    vTaskDelay(pdMS_TO_TICKS(200));
    for (;;) {
        i2c_write_byte(sht20_device, 0, 0xf3);
        vTaskDelay(pdMS_TO_TICKS(100));
        i2c_read_bytes(sht20_device, 0, data, 3);
        if (sht20_check_crc(data, 2, data[2])) {
            uint16_t temp = (data[0] << 8) | data[1];
            temp &= ~0x0003;
            xSemaphoreTake(sht20_mutex, portMAX_DELAY);
            sht20_temperature = -46.85 + 175.72 / 65536 * (float)temp;
            xSemaphoreGive(sht20_mutex);
        }

        i2c_write_byte(sht20_device, 0, 0xf5);
        vTaskDelay(pdMS_TO_TICKS(100));
        i2c_read_bytes(sht20_device, 0, data, 3);
        if (sht20_check_crc(data, 2, data[2])) {
            uint16_t temp = (data[0] << 8) | data[1];
            temp &= ~0x0003;
            xSemaphoreTake(sht20_mutex, portMAX_DELAY);
            sht20_humidity = -6.0 + 125.0 / 65536.0 * (float)temp;
            xSemaphoreGive(sht20_mutex);
        }
        vTaskDelay(pdMS_TO_TICKS(MEASUREMENT_DELAY_MS));
    }
}

void sht20_init(uint8_t sda, uint8_t scl) {
    sht20_device = i2c_malloc_device(I2C_NUM_0, sda, scl, 400000, SHT20_IIC_ADDR);
    i2c_device_set_reg_bits(sht20_device, I2C_NO_REG);
    sht20_reset();
    sht20_mutex = xSemaphoreCreateBinary();
    xSemaphoreGive(sht20_mutex);
    xTaskCreatePinnedToCore(sht20_read_task, "sht20", 4 * 1024, NULL, 4, NULL, 0);
}

void sht20_reset() {
    i2c_write_bytes(sht20_device, 0xfe, NULL, 0);
}

float sht20_get_temperature() {
    float stash = sht20_temperature;
    xSemaphoreTake(sht20_mutex, portMAX_DELAY);
    stash =  sht20_temperature;
    xSemaphoreGive(sht20_mutex);
    return stash;
}

float sht20_get_humidity() {
    float stash = sht20_temperature;
    xSemaphoreTake(sht20_mutex, portMAX_DELAY);
    stash =  sht20_humidity;
    xSemaphoreGive(sht20_mutex);
    return stash;
}
