#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_sntp.h"

#include "qmsd_api.h"

static const char *TAG = "QMSD_SNTP";

static void __qmsd_sntp_sync_cb(struct timeval *tv)
{
    ESP_LOGI(TAG, "sntp time sync over");
    qmsd_notifier_call_nolock(QMSD_SNTP_OK, NULL);
}

void qmsd_obtain_time(uint8_t time_s)
{
    if (time_s > 0)
    {
        int retry = 0;
        while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && ++retry < time_s)
        {
            ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, time_s);
            vTaskDelay(1500 / portTICK_PERIOD_MS);
        }
    }
}

void qmsd_sntp_start(const char *ser1, const char *ser2, const char *ser3)
{
    if (!sntp_enabled())
    {
        sntp_setoperatingmode(SNTP_OPMODE_POLL);
        if (ser1) {
            sntp_setservername(0, ser1);
        } else {
            sntp_setservername(0, "cn.pool.ntp.org");
        }

        if (ser2) {
            sntp_setservername(1, ser2);
        } else {
            sntp_setservername(1, "ntp1.aliyun.com");
        }

        if (ser3) {
            sntp_setservername(2, ser3);
        } else {
            sntp_setservername(2, "pool.ntp.org");
        }
    
        sntp_set_time_sync_notification_cb(__qmsd_sntp_sync_cb);
        sntp_init();
    }
}

void qmsd_sntp_stop(void)
{
    if (sntp_enabled())
    {
        sntp_stop();
    }
}
