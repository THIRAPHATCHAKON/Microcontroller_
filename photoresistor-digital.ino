#include <LiquidCrystal_I2C.h>

#define LDR_PIN 2
#define LED_PIN 9
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(LDR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
