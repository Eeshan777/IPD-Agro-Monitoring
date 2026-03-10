#include<Servo.h>

Servo sm;

void setup()
{
    sm.attach(37);
    sm.write(0);
}
void loop()
{
    sm.write(90);
    delay(1000);
    sm.write(45);
    delay(1000);
    sm.write(0);
    delay(1000);
    sm.write(90);
    delay(1000);
}