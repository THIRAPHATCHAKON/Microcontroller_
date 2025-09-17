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
int i = 0;
int hour,minute,sec = 0;
int nuay , sib , roi = 0;
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
if(sec >= 60){
  sec = 0;
  minute++;
  if(minute >= 60){
    minute = 0;
    hour++;
    if(hour >= 24){
      hour = 0;
    }
  }
}
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[sec%10]);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[sec/10]);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[minute%10]);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[minute/10]);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[hour%10]);
shiftOut(dataPin, clockPin,MSBFIRST,Num7[hour/10]);
digitalWrite(latchPin, HIGH);
delay(1);
sec++;
}
