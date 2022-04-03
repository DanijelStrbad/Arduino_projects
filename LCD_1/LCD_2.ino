#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

char txt[] = "This is some long text 123 abc 456 cde 789 efg 987 xyz";
char txt2[] = "69";


void printSideToSide(char *niz) {
  int i, last, n;
  lcd.clear();
  lcd.setCursor(16, 0);
  lcd.autoscroll();

  i=last=n=0;
  while(niz[i] != 0) {
    if(niz[i] == ' ') {
      if(((i-last) <= 4) && (n <= 0)) {
        delay(1000);
        n++;
      } else {
        delay(1000);
        n = 0;
      }
      last = i+1;
    }
    if((i-last) >= 10) {
      delay(750);
    }
    lcd.print(niz[i++]);
    delay(100);
  }
  
  lcd.noAutoscroll();
  delay(1000);
  //lcd.clear();
}


void loadString(char *niz, int sleep) {
  int i;
  char a=0;
  char txt[] = "Loading ...";
  lcd.clear();
  lcd.setCursor(0, 0);

  i=0;
  while(txt[i] != 0) {
    lcd.print(txt[i++]);
    delay(20);
  }

  lcd.setCursor(0, 1);
  for(int j=0, i=0; j<=15; j++) {
    if(niz[i] == 0) {
      i=0;
    }
    lcd.print(niz[i++]);
    delay(sleep);
  }

  delay(50);
  lcd.setCursor(15, 0);
  a=255;
  lcd.print(a);
  delay(1000);
  //lcd.clear();
}


void snow(int t) {
  int tc = 500, n = (t/tc%2)? t/tc : t/tc+1, dis = 0, row=0;
  lcd.clear();

  for(int i=0; i<n; i++) {
    for(int j=0; j<=15; j++) {
      if(dis%2 == 0) {
        lcd.setCursor(j, row%2);
        lcd.print("*");
      } else {
        lcd.setCursor(j, row%2);
        lcd.print(" ");
      }
      dis++;
    }
    row++;
    if(row%2 == 0) {
      dis++;
    }
    delay(tc);
    lcd.clear();
  }
  
  delay(1000);
  //lcd.clear();
}


void goodVibes(int t) {
  int i, tc = 500, n = (t/tc%2)? t/tc : t/tc+1, shift = 0, siz = 2;
  char txt[] = "Good vibes ...";
  char vibes[] = "_-";
  lcd.clear();
  lcd.setCursor(0, 0);

  i=0;
  while(txt[i] != 0) {
    lcd.print(txt[i++]);
    delay(20);
  }

  lcd.setCursor(0, 1);
  
  for(i=0; i<n; i++) {
    lcd.setCursor(0, 1);
    for(int j=0; j<=15; j++) {
      lcd.print(vibes[(j+shift)%siz]);
    }
    shift++;
    delay(tc);
  }
  
  delay(1000);
  lcd.clear();
}


void setup() {
  pinMode (11, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  delay(2500);
}


void loop() {
  //printSideToSide(txt);
  //loadString(txt2, 200);
  //snow(10000);
  goodVibes(10000);
  
  while(1) {
    delay(1000);
    if(digitalRead(11)==0) {
      break;
    }
  }
}
