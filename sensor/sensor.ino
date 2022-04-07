#include "DHT.h"

const int sensor = 7;
const int motorPin = 3;
const int ledPin = 8;
const int ldrPin = A0;
float backup = 0.0f;
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
  delay(2000);
  float t = dht.readTemperature();
  int brightness = analogRead(ldrPin);
  if(!isnan(t))
  {
    backup = t;
  }
  else
  {
    t = backup;
  }

  if (t < 22)
  {
    Serial.print(t);
    Serial.println(" 1");
    analogWrite(motorPin, 50);
  }
  else if (t < 28)
  {
    Serial.print(t);
    Serial.println(" 2");
    analogWrite(motorPin, 100);
  }
  else if (t < 35)
  {
    Serial.print(t);
    Serial.println(" 3");
    analogWrite(motorPin, 150);
  }
  else if (t < 40)
  {
    Serial.print(t);
    Serial.println(" 4");
    analogWrite(motorPin, 200);
  }
  else
  {
    Serial.print(t);
    Serial.println(" 5");
    analogWrite(motorPin, 255);
  }


  if (brightness < 300)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
