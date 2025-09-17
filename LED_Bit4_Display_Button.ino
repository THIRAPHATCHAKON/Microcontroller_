int sw = LOW;
int i = 0;
int pin[] = {7,8,12,13};

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  for(int i = 0; i < 4 ; i++){
    pinMode(pin[i] , OUTPUT);
  }
}

void loop() {
  if (digitalRead(2) == HIGH) {
    sw = !sw;
    i += 1;
    if(i > 15){
      i = 0;
    }
    
    digitalWrite(7, bitRead(i, 0));
    digitalWrite(8, bitRead(i, 1));
    digitalWrite(12, bitRead(i, 2));
    digitalWrite(13, bitRead(i, 3));

    Serial.println(i, BIN);
    
    delay(200);
    while (digitalRead(2) == HIGH);
  }
}
