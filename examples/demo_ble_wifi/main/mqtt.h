
#ifndef __MQTT_H
#define __MQTT_H

void qmsd_mqtt_app_set_uri(char *uri);

void qmsd_mqtt_app_start(void);
void qmsd_mqtt_app_stop(void);

void qmsd_mqtt_handle_event(const char *topic, char *payload, int len);

#endif

