#include <stdio.h>
#include "esp_system.h"
#include "esp_log.h"
#include <time.h>
#include <sys/time.h>
#include "esp_timer.h"
#include "esp_sleep.h"

#include "qmsd_api.h"

static const char *TAG = "QMSD_BASE";

#define OS_YEAR     ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
                                    + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))

#define OS_MONTH    (__DATE__ [2] == 'n' ? (__DATE__ [1] == 'a' ? 1 : 6) \
                                : __DATE__ [2] == 'b' ? 2 \
                                : __DATE__ [2] == 'r' ? (__DATE__ [0] == 'M' ? 3 : 4) \
                                : __DATE__ [2] == 'y' ? 5 \
                                : __DATE__ [2] == 'l' ? 7 \
                                : __DATE__ [2] == 'g' ? 8 \
                                : __DATE__ [2] == 'p' ? 9 \
                                : __DATE__ [2] == 't' ? 10 \
                                : __DATE__ [2] == 'v' ? 11 : 12)
#define OS_DAY      ((__DATE__ [4] == ' ' ? 0 : __DATE__ [4] - '0') * 10 \
                                + (__DATE__ [5] - '0'))
#define OS_HOUR     ((__TIME__ [0] - '0') * 10 + (__TIME__ [1] - '0'))
#define OS_MINUTE   ((__TIME__ [3] - '0') * 10 + (__TIME__ [4] - '0'))
#define OS_SECOND   ((__TIME__ [6] - '0') * 10 + (__TIME__ [7] - '0'))

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

void qmsd_use_buildtime(void)
{
    struct tm _tm;
    time_t tmp;
    _tm.tm_year = OS_YEAR - 1900;
    _tm.tm_mon = OS_MONTH - 1;
    _tm.tm_mday = OS_DAY;
    _tm.tm_sec = OS_SECOND;
    _tm.tm_hour = OS_HOUR;
    _tm.tm_min = OS_MINUTE;

    tmp = mktime(&_tm);
    qmsd_set_time(tmp, 0);
}