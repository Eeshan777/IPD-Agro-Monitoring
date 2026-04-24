#include "wifi_mqtt.h"
#include "pir.h"
#include "servo.h"
#include "bme280.h"

void setup()
{
    Serial.begin(115200);
    wifi_setup();
    mqtt_setup();
    servo_init();
    pir_init();
    bme_init();
    Serial.println("Warming up PIR sensors...");
    delay(45000);
    Serial.println("Ready to detect motion!");
}

void loop()
{
    mqtt_loop();
    bme_read_publish();
    pir_motion_detect();
}