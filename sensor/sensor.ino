#include "DHT.h"

const int sensor = A0;
DHT dht(sensor, DHT11);

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  dht.begin();
}

void loop()
{
  delay(1000);
  float t = dht.readTemperature();
  Serial.println(t);
}
