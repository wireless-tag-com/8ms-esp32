#include <stdio.h>
#include "esp_system.h"
#include "esp_log.h"
#include <time.h>
#include <sys/time.h>
#include "esp_timer.h"
#include "esp_sleep.h"

#include "qmsd_api.h"

static const char *TAG = "QMSD_BASE";

int qmsd_get_time(time_t *ts)
{
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);
    if (timeinfo.tm_year < (2020 - 1900))
    {
        ESP_LOGW(TAG, "Time is not set yet. need to obtain time by sntp.");
        return -1;
    }

    *ts = now;
    return 0;
}

void qmsd_set_tz(const char *tz)
{
    setenv("TZ", tz, 1);
    tzset();
}

char *qmsd_get_tz(void)
{
    return getenv("TZ");
}

esp_err_t qmsd_set_time(uint64_t time_s, uint64_t time_us)
{
    struct timeval tv = {
        .tv_sec = time_s,
        .tv_usec = time_us,
    };
    settimeofday(&tv, NULL);
    return ESP_OK;
}
