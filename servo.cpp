#include "servo.h"
#include <ESP32Servo.h>
#include <Arduino.h>

Servo pan;
Servo tilt;

void servo_init()
{
    pan.attach(40);
    tilt.attach(42);
    pan.write(90);
    tilt.write(90);
}
void servo_move(int panPos, int tiltPos)
{
    pan.write(panPos);
    tilt.write(tiltPos);
    delay(500);
}