#include "bme280.h"
#include "wifi_mqtt.h"
#include <Wire.h>
#include "DFRobot_BME280.h"
#include <Arduino.h>

DFRobot_BME280_IIC bme(&Wire, 0x77);

void bme_init()
{
    Wire.begin(18, 19);
    Wire.setClock(100000);
    bme.begin();
}

void bme_read_publish()
{
    float temp = bme.getTemperature();
    float pressure = bme.getPressure();
    float humidity = bme.getHumidity();
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" C ");
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.print(" hPa ");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    String payload =
        String(temp) + "," +
        String(pressure) + "," +
        String(humidity);
    client.publish(topic_env, payload.c_str());
    delay(500);
}