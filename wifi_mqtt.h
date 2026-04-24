#ifndef WIFI_MQTT_H
#define WIFI_MQTT_H

#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient espClient;
extern PubSubClient client;

void wifi_setup();
void mqtt_setup();
void mqtt_loop();
void reconnect();

extern const char* topic_motion;
extern const char* topic_env;

#endif