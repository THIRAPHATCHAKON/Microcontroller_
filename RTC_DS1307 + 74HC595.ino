#include "RTClib.h"

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

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

void setup () {
  Serial.begin(115200);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
}

void loop () {
  DateTime now = rtc.now();
  int year_sib = (now.year() / 10) % 10;
  int year_num = now.year() % 10;
  int month_sib = now.month() / 10;
  int month_num = now.month() % 10;
  int day_sib = now.day() / 10;
  int day_num = now.day() % 10;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[day_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[day_sib]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[month_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[month_sib]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[year_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[year_sib]);
  digitalWrite(latchPin, HIGH);
  Serial.print("Current time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(10000);

for(int i = 0 ; i <= 5 ; i++){
  DateTime now = rtc.now();
  int hour_sib = now.hour() / 10;
  int hour_num = now.hour() % 10;
  int minute_sib = now.minute() / 10;
  int minute_num = now.minute() % 10;
  int second_sib = now.second() / 10;
  int second_num = now.second() % 10;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[second_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[second_sib]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[minute_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[minute_sib]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[hour_num]);
  shiftOut(dataPin, clockPin,MSBFIRST,Num7[hour_sib]);
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
}
