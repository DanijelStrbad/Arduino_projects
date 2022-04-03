int i;

void setup()
{
  pinMode (13, OUTPUT);
}

void loop()
{
  for(i=1; i<=100; i++)
  {
    digitalWrite(13, 1);
    delay(1000/i);
    digitalWrite(13, 0);
    delay(1000/i);
  }
  delay(2500);
}
