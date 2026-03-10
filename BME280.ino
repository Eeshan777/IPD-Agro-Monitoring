#include "DFRobot_BME280.h"

DFRobot_BME280 bme(0x77);

void setup()
{
    Serial.begin(115200);
    Wire.setSCL(19);
    Wire.setSDA(18);
    Wire.begin();
    bme.begin();
}
void loop()
{
    float temp=bme.getTemperature()/100.0;
    float pr=bme.getPressure()/100.0;
    float hum=bme.getHumidity()/1000.0;
}