
#include <LiquidCrystal_I2C.h>

#define SENSOR_PIN 2
#define LCD_PIN 3

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {
  Serial.begin(9600);
  pinMode(LCD_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);  
  lcd.init();              
  lcd.backlight();           
}

void loop() {
  lcd.clear();
  int sensorValue = digitalRead(SENSOR_PIN);
  if (sensorValue == HIGH)
  {
    
    digitalWrite(LCD_PIN, HIGH);  
    lcd.setCursor(0,0);
    lcd.print("LED: ");
    lcd.print("ON");
  }
  else
  {
    digitalWrite(LCD_PIN, LOW);    
    lcd.setCursor(0,0);
    lcd.print("LED: ");
    lcd.print("OFF");
  }
  Serial.println(sensorValue);
  delay(500); 
}
