#include "stdlib.h"
#include "qmsd_8ms_ad_ui_data.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/timers.h"

static cJSON* g_8ms_ui_data=NULL;
static SemaphoreHandle_t xGuiDataSemaphore = NULL;

int qmsd_8ms_gui_data_lock(void)
{
    if (pdTRUE == xSemaphoreTake(xGuiDataSemaphore, portMAX_DELAY)) {
        return 0;
    } else {
        return -1;
    }
}

void qmsd_8ms_gui_data_unlock(void)
{
    xSemaphoreGive(xGuiDataSemaphore);
}

void qmsd_8ms_ui_storage_init(void)
{
    g_8ms_ui_data = qmsd_ui_storage_init("qmsd_ui_data", true); 
    xGuiDataSemaphore = xSemaphoreCreateMutex();
}

int qmsd_8ms_ui_storage_set_int(const char* key,int value)
{
    if(!g_8ms_ui_data)
        return -2;
    int ret = -1;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_set_int(g_8ms_ui_data,key,value);
        qmsd_8ms_gui_data_unlock();
    }
    
    return ret;
}

int qmsd_8ms_ui_storage_get_int(const char* key,int def_val)
{
    if(!g_8ms_ui_data)
        return def_val;
    int ret=1;
    int val=0;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_get_int(g_8ms_ui_data,key,&val);
        qmsd_8ms_gui_data_unlock();
    }

    if (ret)
    {
        return def_val;
    }
    else
    {
        return val;
    }
}

int qmsd_8ms_ui_storage_set_str(const char* key,const char* value)
{
    if(!g_8ms_ui_data)
        return -2;
    int ret = -1;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_set_str(g_8ms_ui_data,key,value);
        qmsd_8ms_gui_data_unlock();
    }
    return ret;
}

char* qmsd_8ms_ui_storage_get_str(const char* key,const char* def_val)
{
    if(!g_8ms_ui_data)
        return def_val;
    char* ret =NULL;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_get_str(g_8ms_ui_data,key);
        qmsd_8ms_gui_data_unlock();
    }
    if(ret)
        return ret;
    else
        return def_val;
}

int qmsd_8ms_ui_storage_set_bool(const char* key,bool value)
{
    if(!g_8ms_ui_data)
        return -2;
    int ret =false;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_set_bool(g_8ms_ui_data,key,value);
        qmsd_8ms_gui_data_unlock();
    }
    return ret;
}

bool qmsd_8ms_ui_storage_get_bool(const char* key,bool def_val)
{
    if(!g_8ms_ui_data)
        return def_val;
    bool ret;
    int res = -1;
    if (!qmsd_8ms_gui_data_lock())
    {
        res = qmsd_ui_storage_get_bool(g_8ms_ui_data,key,&ret);
        qmsd_8ms_gui_data_unlock();
    }
    if (res)
    {
        return def_val;
    }
    else
    {
        return ret;
    }
}

int qmsd_8ms_ui_storage_save()
{
    int ret = -1;
    if (!qmsd_8ms_gui_data_lock())
    {
        ret = qmsd_ui_storage_save(g_8ms_ui_data,"qmsd_ui_data");
        qmsd_8ms_gui_data_unlock();
    }
    return ret;
}

void qmsd_8ms_ui_storage_deinit()
{
    qmsd_ui_storage_deinit(g_8ms_ui_data);
}