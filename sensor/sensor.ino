#include "DHT.h"

const int sensor = 7;
const int motorPin = 3;
DHT dht(sensor, DHT11);

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(motorPin, OUTPUT);
  dht.begin();
}

void loop()
{
  delay(1000);
  float t = dht.readTemperature();
  Serial.println(t);

  if (t < 24)
  {
    analogWrite(motorPin, 50);
  }
  else if (t < 30)
  {
    analogWrite(motorPin, 150);
  }
  else
  {
    analogWrite(motorPin, 255);
  }
}
