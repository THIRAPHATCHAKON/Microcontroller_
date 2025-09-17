const int dataPin = 2;   /* DS */
const int clockPin = 3;  /* SHCP */
const int latchPin = 4;  /* STCP */
const int Num7[10]
{
  0b00111111,   // 0
  0b00000110,   // 1
  0b01011011,   // 2
  0b01001111,   // 3
  0b01100110,   // 4
  0b01101101,   // 5
  0b01111101,   // 6
  0b00000111,   // 7
  0b01111111,   // 8
  0b01101111,   // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  int number = 97;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        for(int z=0;z<=9;z++){
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[z]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[k]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[j]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[i]);
  digitalWrite(latchPin, HIGH);
  delay(200);
        }
      }
    }
  }
}
