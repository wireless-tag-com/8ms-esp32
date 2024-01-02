#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

#include "cJSON.h"
#include "lvgl.h"
#include "qmsd_gui_init.h"
#include "qmsd_ctrl.h"

#include "esp_wifi.h"
#include "esp_log.h"
#include "lwip/sockets.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"
#include "freertos/semphr.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "qmsd_msgque.h"
#define TAG "QMSD CTRL"

extern unsigned char* qmsd_get_efuse_encrypt(void);

static char g_topic_control[32];
static char g_topic_report[31];
static bool g_8ms_mqtt_connected=false;
esp_mqtt_client_handle_t g_client;


static __qmsd_get_screen g_qmsd_get_screen;
static __qmsd_get_widget g_qmsd_get_widget;
static __qmsd_get_img g_qmsd_get_img;
static __qmsd_get_font g_qmsd_get_font;

void qmsd_set_screen(__qmsd_get_screen get_screen)
{
	g_qmsd_get_screen = get_screen;
}

void qmsd_set_widget(__qmsd_get_widget get_widget)
{
	g_qmsd_get_widget = get_widget;
}

void qmsd_set_img(__qmsd_get_img get_img)
{
	g_qmsd_get_img = get_img;
}

void qmsd_set_font(__qmsd_get_font get_font)
{
	g_qmsd_get_font = get_font;
}

lv_img_src_t *qmsd_ctrl_get_img(const char *name)
{
	if (g_qmsd_get_img) {
		return g_qmsd_get_img(name);
	} else {
		return NULL;
	}
}

lv_font_t *qmsd_ctrl_get_font(const char *name)
{
	if (g_qmsd_get_font) {
		return g_qmsd_get_font(name);
	} else {
		return NULL;
	}
}

static char *__qmsd_ctrl_handle(lv_obj_t *lobj, const qmsd_ctrl_type type, const cJSON *attr)
{
	char *res = NULL;

	res = lv_obj_qmsd_call_ctrl_cb(lobj, type,  attr);

	return res;
}

static char *__qmsd_ctrl_json_make(int code)
{
	cJSON *result;
	char *res = NULL;
	result = cJSON_CreateObject();

	if (result) {
		cJSON_AddItemToObject(result, "code", cJSON_CreateNumber(code));
		res = cJSON_PrintUnformatted(result);
		cJSON_Delete(result);
	}

	return res;
}

int qmsd_ctrl_str(const char *json_str)
{
	cJSON *root = NULL;
	cJSON *wid = NULL;
	cJSON *cmd = NULL;
	lv_obj_t *screen;
	lv_obj_t *widget;
	int ret = -1;
	char *res = NULL;

	if (!g_qmsd_get_screen || !g_qmsd_get_widget)
		return -1;

	root = cJSON_Parse(json_str);
	if (!root) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	cmd = cJSON_GetObjectItem(root, QMSD_CTRL_CMD_NAME);
	if (!cmd) {
		goto err_out;
	}

	if (((cmd->type)&255) != cJSON_String) {
		goto err_out;
	}

	wid = cJSON_GetObjectItem(root, QMSD_CTRL_WID_NAME);
	if (!wid) {
		goto err_out;
	}

	if (((wid->type)&255) != cJSON_String) {
		goto err_out;
	}

	qmsd_gui_lock(portMAX_DELAY);

	screen = g_qmsd_get_screen(wid->valuestring);

	if (screen) {
		qmsd_gui_unlock();
		goto send_msg;
	}

	widget = g_qmsd_get_widget(wid->valuestring);
	if (!widget) {
		qmsd_gui_unlock();
		goto err_out;
	}

	qmsd_gui_unlock();

send_msg:
	res = cJSON_PrintUnformatted(root);
	cJSON_Delete(root);
	
	if (res) {
		ret = qmsd_msgque_send(res, strlen(res), portMAX_DELAY);
	}

	return ret;

err_out:
	if (root)
		cJSON_Delete(root);

	return ret;
}

char *qmsd_ctrl_str_sync(const char *json_str)
{
	cJSON *root = NULL;
	cJSON *wid = NULL;
	cJSON *cmd = NULL;
	lv_obj_t *screen;
	lv_obj_t *widget;
	char *res = NULL;
	qmsd_ctrl_type type;
	cJSON *attr = NULL;

	if (!g_qmsd_get_screen || !g_qmsd_get_widget)
		return NULL;

	root = cJSON_Parse(json_str);
	if (!root) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	cmd = cJSON_GetObjectItem(root, QMSD_CTRL_CMD_NAME);
	if (!cmd) {
		goto err_out;
	}

	if (((cmd->type)&255) != cJSON_String) {
		goto err_out;
	}

	wid = cJSON_GetObjectItem(root, QMSD_CTRL_WID_NAME);
	if (!wid) {
		goto err_out;
	}

	if (((wid->type)&255) != cJSON_String) {
		goto err_out;
	}

	attr = cJSON_GetObjectItem(root, QMSD_CTRL_ATTR_NAME);
	if (attr) {
		if (((attr->type)&255) != cJSON_Object) {
			res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
			goto err_out;
		}
	}

	if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SET_NAME)) {
		type = QMSD_CTRL_SET_STATUS;
	}
	else if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SET_STYLE))
	{
		type = QMSD_CTRL_SET_STYLE;
	}
	else if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SEND_EVENT))
	{
		type = QMSD_CTRL_SEND_EVENT;
	}
	else {
		type = QMSD_CTRL_GET;
	}

	qmsd_gui_lock(portMAX_DELAY);

	screen = g_qmsd_get_screen(wid->valuestring);

	if (screen) {
		res = __qmsd_ctrl_handle(screen, type, attr);
		qmsd_gui_unlock();
		goto err_out;
	}

	widget = g_qmsd_get_widget(wid->valuestring);
	if (!widget) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_WID_NOT_FOUND);
		qmsd_gui_unlock();
		goto err_out;
	}

	attr = cJSON_GetObjectItem(root, QMSD_CTRL_ATTR_NAME);
	if (attr) {
		if (((attr->type)&255) != cJSON_Object) {
			res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
			qmsd_gui_unlock();
			goto err_out;
		}
	}

	res = __qmsd_ctrl_handle(widget, type, attr);
	qmsd_gui_unlock();

	return res;


err_out:
	if (root)
		cJSON_Delete(root);

	return res;
}

char *qmsd_ctrl_str_gui(const char *json_str)
{
	cJSON *root = NULL;
	cJSON *wid = NULL;
	cJSON *cmd = NULL;
	cJSON *attr = NULL;
	lv_obj_t *screen;
	lv_obj_t *widget;
	char *res = NULL;
	qmsd_ctrl_type type;

	if (!g_qmsd_get_screen || !g_qmsd_get_widget)
		return NULL;

	root = cJSON_Parse(json_str);
	if (!root) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	attr = cJSON_GetObjectItem(root, QMSD_CTRL_ATTR_NAME);
	if (attr) {
		if (((attr->type)&255) != cJSON_Object) {
			res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
			goto err_out;
		}
	}

	cmd = cJSON_GetObjectItem(root, QMSD_CTRL_CMD_NAME);
	if (!cmd) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	if (((cmd->type)&255) != cJSON_String) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SET_NAME)) {
		type = QMSD_CTRL_SET_STATUS;
	}
	else if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SET_STYLE))
	{
		type = QMSD_CTRL_SET_STYLE;
	}
	else if (!strcmp(cmd->valuestring, QMSD_CTRL_CMD_SEND_EVENT))
	{
		type = QMSD_CTRL_SEND_EVENT;
	}
	 else {
		type = QMSD_CTRL_GET;
	}

	wid = cJSON_GetObjectItem(root, QMSD_CTRL_WID_NAME);

	if (!wid) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	if (((wid->type)&255) != cJSON_String) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_PARAM_ERROR);
		goto err_out;
	}

	screen = g_qmsd_get_screen(wid->valuestring);

	if (screen) {
		res = __qmsd_ctrl_handle(screen, type, attr);
		goto err_out;
	}

	widget = g_qmsd_get_widget(wid->valuestring);
	if (!widget) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_WID_NOT_FOUND);
		goto err_out;
	}
	res = __qmsd_ctrl_handle(widget, type, attr);

err_out:
	if (root)
		cJSON_Delete(root);

	return res;
}

int qmsd_ctrl_cjson_gui(const char *wid, qmsd_ctrl_type type, const cJSON *attr)
{
	int ret = 0;
	lv_obj_t *screen;
	lv_obj_t *widget;
	char *res = NULL;

	if (!g_qmsd_get_screen || !g_qmsd_get_widget)
		return -1;

	screen = g_qmsd_get_screen(wid);
	if (screen) {
		res = __qmsd_ctrl_handle(screen, type, attr);
		ret = -1;
		goto err_out;
	}

	widget = g_qmsd_get_widget(wid);
	if (!widget) {
		res = __qmsd_ctrl_json_make(QMSD_CTRL_CODE_WID_NOT_FOUND);
		ret = -1;
		goto err_out;
	}

	res = __qmsd_ctrl_handle(widget, type, attr);

err_out:
	if (res)
		free(res);

	return ret;
}

static esp_err_t mqtt_event_handler_cb(esp_mqtt_event_handle_t event)
{
    esp_mqtt_client_handle_t client = event->client;
    int msg_id;
    // your_context_t *context = event->context;
    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
			g_8ms_mqtt_connected=true;
            ESP_LOGI(TAG, "MQTT_EVENT_CONNECTED");
            msg_id = esp_mqtt_client_publish(client, g_topic_report, "Connected", 0, 0, 0);
            ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);

            msg_id = esp_mqtt_client_subscribe(client, g_topic_control, 2);
            ESP_LOGI(TAG, "sent subscribe successful, msg_id=%d", msg_id);
            break;
        case MQTT_EVENT_DISCONNECTED:
			g_8ms_mqtt_connected = false;
            ESP_LOGI(TAG, "MQTT_EVENT_DISCONNECTED");
            break;

        case MQTT_EVENT_SUBSCRIBED:
            /*
			ESP_LOGI(TAG, "MQTT_EVENT_SUBSCRIBED, msg_id=%d", event->msg_id);
            msg_id = esp_mqtt_client_publish(client, "/topic/qos0", "data", 0, 0, 0);
            
            ESP_LOGI(TAG, "sent publish successful, msg_id=%d", msg_id);
            */
			break;
        case MQTT_EVENT_UNSUBSCRIBED:
            ESP_LOGI(TAG, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_PUBLISHED:
            ESP_LOGI(TAG, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_DATA:
            ESP_LOGI(TAG, "MQTT_EVENT_DATA");
            printf("TOPIC=%.*s\r\n", event->topic_len, event->topic);
            printf("DATA=%.*s\r\n", event->data_len, event->data);
			qmsd_ctrl_str(event->data);
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGI(TAG, "MQTT_EVENT_ERROR");
            break;
        default:
            ESP_LOGI(TAG, "Other event id:%d", event->event_id);
            break;
    }
    return ESP_OK;
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data) {
    ESP_LOGD(TAG, "Event dispatched from event loop base=%s, event_id=%d", base, event_id);
    mqtt_event_handler_cb(event_data);
}


void mqtt_app_start(void *pvParameters)
{
	esp_netif_init();
	wifi_ap_record_t ap;
	esp_wifi_sta_get_ap_info(&ap);
	int i=0;
	while (!strlen((char *)ap.ssid))
	{
		esp_wifi_sta_get_ap_info(&ap);
   	 	
		if (i>30)
		{
			esp_netif_deinit();
			vTaskDelete(NULL);
		}
		vTaskDelay(100);
		//printf("%d\n",i);
		i++;
	}
	uint8_t mac[6];
	esp_read_mac(mac, ESP_MAC_WIFI_STA);
	unsigned char * mac_encrypted=qmsd_get_efuse_encrypt();
	//char url_test[128]={"mqtt://840D8EE08A88:f2f49f563100b9ca@mqtt.8ms.xyz:1883"};
	#ifdef CONFIG_WT_86_32_3ZW1
	sprintf(g_topic_control, "/86box/%02X%02X%02X%02X%02X%02X/control", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	sprintf(g_topic_report, "/86box/%02X%02X%02X%02X%02X%02X/report", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	#else
	sprintf(g_topic_control, "/wtesp32/%02X%02X%02X%02X%02X%02X/control", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	sprintf(g_topic_report, "/wtesp32/%02X%02X%02X%02X%02X%02X/report", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	#endif
	char mqtt_url[128];
	char client[13];
	sprintf(client,"%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	sprintf(mqtt_url,"mqtt://%02X%02X%02X%02X%02X%02X:%02x%02x%02x%02x%02x%02x%02x%02x@mqtt.8ms.xyz:1883",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5],mac_encrypted[0],mac_encrypted[1],mac_encrypted[2],mac_encrypted[3],mac_encrypted[4],mac_encrypted[5],mac_encrypted[6],mac_encrypted[7]);
	printf("%s\n",mqtt_url);
    printf("%s\n",g_topic_control);
	printf("%s\n",g_topic_report);
    esp_mqtt_client_config_t mqtt_cfg = {
		.client_id = client,
        .uri = mqtt_url ,
    };
	g_client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(g_client, ESP_EVENT_ANY_ID, mqtt_event_handler, g_client);
    esp_mqtt_client_start(g_client);
	vTaskDelete(NULL);
}

