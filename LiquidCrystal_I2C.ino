#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4
int buzzer_1 = 2;
bool led1State = false;    
bool led2State = false;    

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup() {
  Serial.begin(9600);
  lcd.init();              
  lcd.backlight();         
  pinMode(7, INPUT);       
  pinMode(8, INPUT);    
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); 
  pinMode(2, OUTPUT); 

  Display();
}

void loop() {
  if (digitalRead(7) == LOW) {
    digitalWrite(buzzer_1, HIGH);
    led1State = !led1State;  
    Display();  
    DisplayLED();  
    while (digitalRead(7) == LOW);  
    delay(100);        
  }
  digitalWrite(buzzer_1, LOW);

  if (digitalRead(8) == LOW) {
    digitalWrite(buzzer_1, HIGH);
    led2State = !led2State;  
    Display();  
    DisplayLED();
    while (digitalRead(8) == LOW);  
    delay(100);              
  }
  digitalWrite(buzzer_1, LOW);
}

void Display() {
  lcd.clear();
  lcd.setCursor(1, 0);
  if(led1State == false){
    lcd.print("1.LED1 OFF");
  }
  else{
    lcd.print("1.LED1 ON");
  }
  lcd.setCursor(1, 1);
  if(led2State == false){
    lcd.print("2.LED2 OFF");
  }
  else{
    lcd.print("2.LED2 ON");
  }
}

void DisplayLED() {
  if(led1State == false){
    digitalWrite(12, LOW);
  }
  else{
    digitalWrite(12, HIGH);
  }
  if(led2State == false){
    digitalWrite(13, LOW);
  }
  else{
    digitalWrite(13, HIGH);
  }
}

