byte num[] ={
  0b00111111,   // 0
  0b00000110,   // 1
  0b01011011,   // 2 
  0b01001111,   // 3
  0b01100110,   // 4
  0b01101101,   // 5
  0b01111101,   // 6
  0b00000111,   // 7
  0b01111111,   // 8
  0b01100111,   // 9
};
int pin[] = {2,3,4,5,6,7,8};

void setup() {
Serial.begin(9600);
for(int i = 0 ; i < 8 ; i++){
  pinMode(pin[i], OUTPUT);
}
  

}

void loop() {


  for(int k=0;k<=9;k++)
  {
    for(int j=6;j>=0;j--)
    {
      Serial.print(bitRead(num[k],j));
      digitalWrite(pin[j], bitRead(num[k],j));
    }
    delay(1000);
    Serial.println("");
  }
}
