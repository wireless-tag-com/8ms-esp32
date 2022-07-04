#ifndef __QMSD_API_H__
#define __QMSD_API_H__
#include <time.h>
#include <sys/time.h>
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "lwip/ip4_addr.h"
#include "esp_smartconfig.h"
#include "esp_wifi.h"
#include "mqtt_client.h"
#include "qmsd_wifi.h"
#include "qmsd_notifier.h"

/* qmsd base */
enum
{
    QMSD_SYSTEM_RESTART_EVENT = 1000,
    QMSD_SYSTEM_FACTORY_EVENT = 1001
};

int qmsd_get_time(time_t *ts);
esp_err_t qmsd_set_time(uint64_t time_s, uint64_t time_us);
void qmsd_set_tz(const char *tz);
char *qmsd_get_tz(void);
void qmsd_use_buildtime(void);

/* qmsd sntp */
enum
{
    QMSD_SNTP_OK = 2000
};
void qmsd_obtain_time(uint8_t time_s);
void qmsd_sntp_start(const char *ser1, const char *ser2, const char *ser3);
void qmsd_sntp_stop(void);

/* qmsd ota */
enum
{
    QMSD_SYSTEM_OTA_OK = 3000,
    QMSD_SYSTEM_OTA_FAIL = 3001
};
int qmsd_ota_start(const char *url);
void qmsd_ota_stop(void);
void qmsd_ota_set_pem(char *pem);
int qmsd_http_ota_status(void);

/*!< qmsd nvs */
void qmsd_nvs_init(void);
esp_err_t qmsd_nvs_set_blob(const char *namespace, const char *key, void *data, size_t length);
esp_err_t qmsd_nvs_get_blob(const char *namespace, const char *key, void *data, size_t length);
esp_err_t qmsd_nvs_set_u8(const char *namespace, const char *key, uint8_t value);
esp_err_t qmsd_nvs_get_u8(const char *namespace, const char *key, uint8_t *value);
esp_err_t qmsd_nvs_set_i8(const char *namespace, const char *key, int8_t value);
esp_err_t qmsd_nvs_get_i8(const char *namespace, const char *key, int8_t *value);
esp_err_t qmsd_nvs_get_u16(const char*namespace, const char* key, uint16_t *value);
esp_err_t qmsd_nvs_set_u16(const char*namespace, const char* key, uint16_t input);
esp_err_t qmsd_nvs_get_i16(const char*namespace, const char* key, int16_t *value);
esp_err_t qmsd_nvs_set_i16(const char*namespace, const char* key, int16_t input);
esp_err_t qmsd_nvs_get_u32(const char*namespace, const char* key, uint32_t *value);
esp_err_t qmsd_nvs_set_u32(const char*namespace, const char* key, uint32_t input);
esp_err_t qmsd_nvs_get_i32(const char*namespace, const char* key, int32_t *value);
esp_err_t qmsd_nvs_set_i32(const char*namespace, const char* key, int32_t input);
esp_err_t qmsd_nvs_get_u64(const char*namespace, const char* key, uint64_t *value);
esp_err_t qmsd_nvs_set_u64(const char*namespace, const char* key, uint64_t input);
esp_err_t qmsd_nvs_get_i64(const char*namespace, const char* key, int64_t *value);
esp_err_t qmsd_nvs_set_i64(const char*namespace, const char* key, int64_t input);
esp_err_t qmsd_nvs_get_str_size(const char*namespace, const char* key, size_t *str_size);
esp_err_t qmsd_nvs_get_str(const char*namespace, const char* key,char *output, size_t size);
esp_err_t qmsd_nvs_set_str(const char*namespace, const char* key,char* input);
esp_err_t qmsd_nvs_clear_namespace(const char*namespace);
esp_err_t qmsd_nvs_clear_key(const char*namespace, const char* key);
esp_err_t qmsd_nvs_clear_all(void);

/* qmsd uart */
enum
{
    QMSD_UART_EVENT_DATA = 4000,
};

struct qmsd_uart_rx_data
{
    int uart_num;
    char *data;
    int size;
};

typedef struct {
    uint32_t uart_buffer_size;
    uint32_t queue_size;             
    uart_config_t uart_native_config;
    int uart_tx_pin;
    int uart_rx_pin;
    int uart_rts_pin;
    int uart_cts_pin;
    uart_mode_t uart_mode; 
} qmsd_uart_config_t;

int qmsd_uart_flush(int unum);
int qmsd_uart_flush_input(int unum);
int qmsd_uart_flush_output(int unum);
int qmsd_uart_write(int unum, const char *buf, size_t len);
int qmsd_uart_read(int unum, char *buf, size_t len, int timeout);
int qmsd_uart_start(int unum, qmsd_uart_config_t *config);
void qmsd_uart_stop(int unum);

/* qmsd gpio */
typedef enum {
    QMSD_GPIO_OUT = 0,      /**< Output. A Mode can also be set */
    QMSD_GPIO_IN = 1,       /**< Input */
    QMSD_GPIO_OUT_HIGH = 2, /**< Output. Init High */
    QMSD_GPIO_OUT_LOW = 3   /**< Output. Init Low */
} qmsd_gpio_dir_t;

int qmsd_gpio_init(int pin, int dir, int pull_down_en, int pull_up_en);
int qmsd_gpio_uninit(int pin);
int qmsd_gpio_set_intr_type(int pin, int type);
int qmsd_gpio_intr_enable(int pin);
int qmsd_gpio_intr_disable(int pin);
int qmsd_gpio_isr_init(int args);
int qmsd_gpio_isr_uninit(void);
int qmsd_gpio_isr_handler_add(int pin, gpio_isr_t isr_handler, void *args);
int qmsd_gpio_isr_handler_remove(int pin);
int qmsd_gpio_set_dir(int pin, int dir);
int qmsd_gpio_get_dir(int pin, int *dir);
int qmsd_gpio_read(int pin);
int qmsd_gpio_write(int pin, int value);

/* qmsd pwm */
int qmsd_pwm_start(int timer_num, int channel, int gpio, uint32_t freq_hz, uint32_t duty);
int qmsd_pwm_stop(int channel, uint32_t idle_level);
int qmsd_pwm_set_freq(int timer_num, uint32_t freq_hz);
int qmsd_pwm_set_duty(int channel, uint32_t duty);

/* qmsd http */
enum
{
    QMSD_HTTP_CONNECTED = 5000,
    QMSD_HTTP_DATA = 5001,
    QMSD_HTTP_FINISH = 5002,
    QMSD_HTTP_DIS = 5003,
};

struct qmsd_http_get_data
{
    char *data;
    int size;
};

esp_err_t qmsd_http_get(const char *url, const char *header, const char *user_agent);
esp_err_t qmsd_http_post(char *url, const char *post_data, int post_len);
esp_err_t qmsd_http_post_json(char *url, const char *post_data, int post_len);
esp_err_t qmsd_http_post_img(char *url, const char *post_data, int post_len);

/* qmsd wifi */
enum
{
    QMSD_WIFI_STA_DISCONNECT = 6000,
    QMSD_WIFI_STA_GOT_IP = 6001,
    QMSD_WIFI_SCAN_DONE = 6002,
};

struct qmsd_wifi_scan_res
{
    wifi_ap_record_t *ap_info;
    uint16_t number;
};

/* qmsd ble */
enum
{
    QMSD_BLUFI_RCV_STA_SSID = 7001,
    QMSD_BLUFI_RCV_STA_PWD = 7002,
    QMSD_BLUFI_CONNECT_TO_AP = 7003,
    QMSD_BLUFI_STA_GOT_IP = 7004,
};
void qmsd_blufi_start(void);
void qmsd_blufi_stop(void);
int qmsd_blufi_status(void);

/* qmsd mqtt */
enum
{
    QMSD_MQTT_EVENT_CONNECTED = 8000,
    QMSD_MQTT_EVENT_DISCONNECTED = 8001,
    QMSD_MQTT_EVENT_DATA = 8002,
    QMSD_MQTT_EVENT_ERROR = 8003,
};

int qmsd_mqtt_status(void);
int qmsd_mqtt_start(esp_mqtt_client_config_t *config);
int qmsd_mqtt_stop(void);
int qmsd_mqtt_pub(const char *topic, const char *data, int len, const int qos, const int retain);
int qmsd_mqtt_sub(const char *topic, int qos);
int qmsd_mqtt_unsub(const char *topic);

#endif
