#include "wifi_mqtt.h"
#include <Arduino.h>

const char* ssid = "XYZ";
const char* password = "45362573";
const char* mqtt_server = "192.168.29.151";
const char* topic_motion = "farm/motion";
const char* topic_env = "farm/environment";

WiFiClient espClient;
PubSubClient client(espClient);

void wifi_setup()
{
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
    Serial.println(WiFi.localIP());
}

void mqtt_setup()
{
    client.setServer(mqtt_server, 1883);
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.println("Connecting to MQTT...");
        if (client.connect("ESP32_PIR"))
        {
            Serial.println("MQTT Connected");
        }
        else
        {
            Serial.println("MQTT Failed. Retrying...");
            delay(2000);
        }
    }
}

void mqtt_loop()
{
    if (!client.connected())
    {
        reconnect();
    }
    client.loop();
}