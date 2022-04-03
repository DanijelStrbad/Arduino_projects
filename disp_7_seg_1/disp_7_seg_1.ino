int disp1[7]  = {2, 3, 4, 5, 6, 7, 8};
/*               A  B  C  D  E  F  G   */
int digit1[4] = {9, 10, 11, 12};
/*              D1  D2  D3  D4   */
int i, j;

void circle(int disp1[], int digit1[], int numOfCircs, int waitT) {
  int i, j;

  allOff(disp1, digit1);
  
  for(i=0; i<numOfCircs; i++) {
    
    digitalWrite(disp1[0], 1);
    digitalWrite(digit1[0], 0);
    delay(waitT);
    digitalWrite(digit1[0], 1);
    digitalWrite(digit1[1], 0);
    delay(waitT);
    digitalWrite(digit1[1], 1);
    digitalWrite(digit1[2], 0);
    delay(waitT);
    digitalWrite(digit1[2], 1);
    digitalWrite(digit1[3], 0);
    delay(waitT);
    digitalWrite(digit1[3], 1);
    digitalWrite(disp1[0], 0);

    digitalWrite(digit1[3], 0);
    digitalWrite(disp1[1], 1);
    delay(waitT);
    digitalWrite(disp1[1], 0);
    digitalWrite(disp1[2], 1);
    delay(waitT);
    digitalWrite(disp1[2], 0);
    digitalWrite(digit1[3], 1);

    digitalWrite(disp1[3], 1);
    digitalWrite(digit1[3], 0);
    delay(waitT);
    digitalWrite(digit1[3], 1);
    digitalWrite(digit1[2], 0);
    delay(waitT);
    digitalWrite(digit1[2], 1);
    digitalWrite(digit1[1], 0);
    delay(waitT);
    digitalWrite(digit1[1], 1);
    digitalWrite(digit1[0], 0);
    delay(waitT);
    digitalWrite(digit1[0], 1);
    digitalWrite(disp1[3], 0);

    digitalWrite(digit1[0], 0);
    digitalWrite(disp1[4], 1);
    delay(waitT);
    digitalWrite(disp1[4], 0);
    digitalWrite(disp1[5], 1);
    delay(waitT);
    digitalWrite(disp1[5], 0);
    digitalWrite(digit1[0], 1);
  }

  allOff(disp1, digit1);
  delay(waitT*2);
}


void allOff(int disp1[], int digit1[]) {
  int i;
  for(i=0; i<7; i++) {
    digitalWrite(disp1[i], 0);
  }
  for(i=0; i<4; i++) {
    digitalWrite(digit1[i], 1);
  }
}

void allOn(int disp1[], int digit1[]) {
  int i;
  for(i=0; i<7; i++) {
    digitalWrite(disp1[i], 1);
  }
  for(i=0; i<4; i++) {
    digitalWrite(digit1[i], 0);
  }
}

void printNumDisp(int a, int b, int c, int d, int col) {
  int i;
}

void setup() 
{
  for(i=0; i<7; i++) {
    pinMode (disp1[i], OUTPUT);
  }
  for(i=0; i<4; i++) {
    pinMode (digit1[i], OUTPUT);
  }
}

void loop() 
{
  circle(disp1, digit1, 4, 250);
  while(1){
    delay(2500);
  }
}
