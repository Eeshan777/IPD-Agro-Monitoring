int pirState=LOW;
const int pirPin=6;

void setup()
{
    Serial.begin(115200);
    pinMode(pirPin,INPUT);
    Serial.println("Warming up PIR sensor...");
    delay(45000);
    Serial.println("Ready to detect motion!");
}
void loop()
{
    int val=digitalRead(pirPin);
    if(val==HIGH)
    {
        Serial.println("Motion detected!");
    }
    else
    {
        Serial.println("Motion ended!");
    }
    pirState=val;
}