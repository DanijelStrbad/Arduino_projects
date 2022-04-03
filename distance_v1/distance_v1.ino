#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int s, out=8, in=9;

int udaljenost(int out, int in)
{
  int t, s;
  digitalWrite(out,1);
  delayMicroseconds(10);
  digitalWrite(out,0);
  t=pulseIn(in,1,30000);
  t=t/2;
  s=t*(0.0343);
  return s;
}



void setup()
{
  Serial.begin(115200);
  pinMode (8, OUTPUT);
  pinMode (9, INPUT);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Arduino mjerac");
  lcd.setCursor(0,1);
  lcd.print("udaljenosti");
  delay(5000);
  lcd.clear();
  Serial.println("Distances:");
  delay(100);
}



void loop()
{
  s=udaljenost(out, in);
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("s=");
  lcd.setCursor(7,0);
  if (s!=0)
  {
    lcd.print(s);
    lcd.print(" cm  ");
  }
  else
  {
    lcd.print("??? error");
  }
  Serial.println(s);
  delay(250);
}
