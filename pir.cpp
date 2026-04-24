#include "pir.h"
#include "servo.h"
#include "wifi_mqtt.h"
#include <Arduino.h>

int pir1 = 6;
int pir2 = 7;
int pir3 = 8;
int pirState1 = LOW;
int pirState2 = LOW;
int pirState3 = LOW;

void pir_init()
{
    pinMode(pir1, INPUT);
    pinMode(pir2, INPUT);
    pinMode(pir3, INPUT);
}

void pir_motion_detect()
{
    int val1 = digitalRead(pir1);
    int val2 = digitalRead(pir2);
    int val3 = digitalRead(pir3);
    if (val1 == HIGH && pirState1 == LOW)
    {
        Serial.println("Motion detected (PIR 1)");
        client.publish(topic_motion, "PIR1 MOTION");
        pirState1 = HIGH;
        servo_move(45, 90);
    }
    else if (val2 == HIGH && pirState2 == LOW)
    {
        Serial.println("Motion detected (PIR 2)");
        client.publish(topic_motion, "PIR2 MOTION");
        pirState2 = HIGH;
        servo_move(90, 90);
    }
    else if (val3 == HIGH && pirState3 == LOW)
    {
        Serial.println("Motion detected (PIR 3)");
        client.publish(topic_motion, "PIR3 MOTION");
        pirState3 = HIGH;
        servo_move(135, 90);
    }
    if (val1 == LOW) pirState1 = LOW;
    if (val2 == LOW) pirState2 = LOW;
    if (val3 == LOW) pirState3 = LOW;
}