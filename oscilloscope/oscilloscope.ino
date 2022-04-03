int sensorPin = A0;   // ulazni analogni pin
int sensorValue = 0;  // vrijednost ulaza

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  sensorValue=analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(10);
}

