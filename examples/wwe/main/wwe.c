/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_wn_iface.h"
#include "esp_wn_models.h"
#include "dl_lib_coefgetter_if.h"
#include "esp_afe_sr_iface.h"
#include "esp_afe_sr_models.h"
#include "esp_mn_iface.h"
#include "esp_mn_models.h"
#include "driver/i2s.h"
#include "model_path.h"
#include "esp_log.h"

#define TAG "MAIN"

int detect_flag = 0;
static const esp_afe_sr_iface_t *afe_handle = NULL;
static int play_voice = -2;

extern int board_get_feed_channel(void);
extern esp_err_t board_get_feed_data(int16_t *buffer, int buffer_len);

static bool g_feed_flag = true;
static bool g_detect_flag = true;

void feed_Task(void *arg)
{
    esp_afe_sr_data_t *afe_data = arg;
    int audio_chunksize = afe_handle->get_feed_chunksize(afe_data);
    int feed_channel = board_get_feed_channel();
    uint32_t read_size = audio_chunksize * sizeof(int16_t) * feed_channel;
    int16_t* feed_buf = heap_caps_calloc(1, read_size, MALLOC_CAP_DEFAULT | MALLOC_CAP_INTERNAL);
    assert(feed_buf);
    while (g_feed_flag) {
        esp_err_t ret;
        ret = board_get_feed_data(feed_buf, read_size);
        if (ret == ESP_OK)
            afe_handle->feed(afe_data, feed_buf);
        else
            vTaskDelay(pdMS_TO_TICKS(150));
    }
    //afe_handle->destroy(afe_data);
    free(feed_buf);
    g_detect_flag = false;
    vTaskDelete(NULL);
}

int16_t* psram_buff = NULL;

void detect_Task(void *arg)
{
    esp_afe_sr_data_t *afe_data = arg;
    int afe_chunksize = afe_handle->get_fetch_chunksize(afe_data);
    int16_t *buff =  heap_caps_calloc(1, afe_chunksize * sizeof(int16_t), MALLOC_CAP_DEFAULT | MALLOC_CAP_INTERNAL);
    psram_buff = (int16_t *)heap_caps_calloc(1, 1000 * 1024 * 2, MALLOC_CAP_DEFAULT | MALLOC_CAP_SPIRAM);
    int16_t* ptr_now = NULL;
    assert(buff);
    static const esp_mn_iface_t *multinet = &MULTINET_MODEL;
    model_iface_data_t *model_data = multinet->create((model_coeff_getter_t *)&MULTINET_COEFF, 5760);
    int mu_chunksize = multinet->get_samp_chunksize(model_data);
    assert(mu_chunksize == afe_chunksize);

    while (g_detect_flag) {
        if (!g_feed_flag) {
            vTaskDelay(pdMS_TO_TICKS(20));
            continue;
        }

        int res = afe_handle->fetch(afe_data, buff);

        if (res == AFE_FETCH_WWE_DETECTED) {
            printf("wakeword detected\n");
            printf("-----------LISTENING-----------\n");
            ptr_now = psram_buff;
        }

        if (res == AFE_FETCH_CHANNEL_VERIFIED) {
            play_voice = -1;
            detect_flag = 1;
            afe_handle->disable_wakenet(afe_data);
        } 

        if (detect_flag) {
            memcpy(ptr_now, buff, afe_chunksize * sizeof(int16_t));
            ptr_now += afe_chunksize;
        }

        if (detect_flag == 1) {
            int command_id = multinet->detect(model_data, buff);
            if (command_id >= -2) {
                if (command_id > -1) {
                    play_voice = command_id;
                    printf("command_id: %d\n", command_id);
                    afe_handle->enable_wakenet(afe_data);
                    detect_flag = 0;
                    printf("\n-----------awaits to be waken up-----------\n");
                    ESP_LOGI(TAG, "Read len: %d", (ptr_now - psram_buff) *  2);
                }

                if (command_id == -2) {
                    afe_handle->enable_wakenet(afe_data);
                    detect_flag = 0;
                    printf("\n-----------awaits to be waken up-----------\n");
                }
            }
        }
    }
    afe_handle->destroy(afe_data);
    free(buff);
    free(psram_buff);
    vTaskDelete(NULL);
}

void wwe_init_model(void)
{
    srmodel_spiffs_init();
}

void wwe_init(void)
{
    afe_handle = &esp_afe_sr_2mic;
    afe_config_t afe_config = {
        .aec_init = false,
        .se_init = true,
        .vad_init = true,
        .wakenet_init = true,
        .vad_mode = 3,
        .wakenet_model = &WAKENET_MODEL,
        .wakenet_coeff = (model_coeff_getter_t *)&WAKENET_COEFF,
        .wakenet_mode = DET_MODE_2CH_90,
        .afe_mode = SR_MODE_LOW_COST,
        .afe_perferred_core = 0,
        .afe_perferred_priority = 5,
        .afe_ringbuf_size = 40,
        .alloc_from_psram = AFE_PSRAM_LOW_COST,
        .agc_mode = 3,
    };

    esp_afe_sr_data_t *afe_data = afe_handle->create_from_config(&afe_config);
    xTaskCreatePinnedToCore(&feed_Task, "feed", 4 * 1024, (void*)afe_data, 5, NULL, 0);
    xTaskCreatePinnedToCore(&detect_Task, "detect", 6 * 1024, (void*)afe_data, 5, NULL, 1);
}

void wwe_stop(void)
{
    g_feed_flag = false;
    vTaskDelay(pdMS_TO_TICKS(5));
}
