#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();              
  lcd.backlight();   
}

void loop() {
  delay(2000);
  lcd.clear();  // เพิ่มวงเล็บ () เพื่อเรียกใช้งานฟังก์ชัน
  float temperature = dht.readTemperature();  // อ่านค่าอุณหภูมิ


   if (isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed to read");  // เปลี่ยนจาก println เป็น print
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");  // แสดงหน่วยองศาเซลเซียส
  }
}