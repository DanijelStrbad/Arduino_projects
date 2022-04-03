#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int s, s2, m1, m2, m12;

/*==================================================*/

int distance(int out, int in)
{
  int t, s;
  digitalWrite(out,1);
  delayMicroseconds(10);
  digitalWrite(out,0);
  t=pulseIn(in,1,14868); /* ~ 510 [cm] */
  t=t/2;
  s=t*(0.0343);
  return s;
}

/*==================================================*/

void setup()
{
  int i, reset=0;
  pinMode (8, OUTPUT);
  pinMode (9, INPUT);
  pinMode (11, INPUT_PULLUP);
  
  lcd.begin(16, 2);
  lcd.clear();
  delay(50);
  lcd.print("Arduino distance");
  lcd.setCursor(0,1);
  lcd.print("meter");
  delay(5000);
  lcd.clear();
  delay(50);

  if(digitalRead(11)==0)
  {
    reset=1;
    EEPROM.write(1,0);
    EEPROM.write(2,0);
    delay(100);
    lcd.print("EEPROM {1,2}");
    lcd.setCursor(0,1);
    delay(50);
    lcd.print("reset");
    delay(5000);
    lcd.clear();
  }

  m1=EEPROM.read(1);
  m2=EEPROM.read(2);
  m12=m1+m2;
  delay(50);
  lcd.print("Max s= ");
  lcd.print(m12);
  if(reset)
    delay(2000);
  else
    delay(5000);
  
  lcd.setCursor(0,0);
  for(i=0;i<32;i++)
  {
    lcd.print("*");
    if(i==15) lcd.setCursor(0,1);
    delay(50);
  }
  delay(500);
  lcd.clear();
}

/*==================================================*/

void loop()
{
  s=distance(8, 9);
  s2=s+12;
  
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("s=");
  lcd.setCursor(4,1);
  lcd.print("s2=");
  
  if (s!=0)
  {
    lcd.setCursor(7,0);
    lcd.print(s);
    lcd.print(" cm");
    lcd.setCursor(7,1);
    lcd.print(s2);
    lcd.print(" cm");

    if(s>m12)
    {
      delay(500);
      m12=m2=s;
      if(s>255)
      {
        m1=m2-255;
        m2=m12-m1;
      }
      EEPROM.write(1,m1);
      EEPROM.write(2,m2);
      delay(100);
      lcd.clear();
      lcd.print("Max s= ");
      lcd.print(m12);
      delay(1000);
    }
  }
  else
  {
    lcd.setCursor(7,0);
    lcd.print(" ? error");
    lcd.setCursor(7,1);
    lcd.print(" ? error");
  }
  delay(500);
}
