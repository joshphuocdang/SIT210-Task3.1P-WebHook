#include <PietteTech_DHT.h>
#include <thingspeak-webhooks.h>

#define DHTPIN A4
#define DHTTYPE DHT22

PietteTech_DHT dht(DHTPIN, DHTTYPE);

float temp;
String temp_string;
int led = D7;

void setup()
{
    pinMode(led, OUTPUT);
    dht.begin();
}

void loop()
{
    digitalWrite(led, HIGH);   // Turn ON the LED
    temp = dht.readTemperature();//Read temperature
    temp_string = String(temp);
    
    Particle.publish("temp", temp_string, PRIVATE);//publish to thingspeak.com
    
    delay(30000);               // Wait for 30 seconds
    digitalWrite(led, LOW);    // Turn OFF the LED
    delay(30000);  

}