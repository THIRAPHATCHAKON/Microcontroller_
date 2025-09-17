int bitnumber[4];
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7 , OUTPUT);
  pinMode(8 , OUTPUT);
  pinMode(12 , OUTPUT);
  pinMode(13 , OUTPUT);
}

void loop() {
  for(int i = 0 ; i < 16 ; i++){
    count = i;
    for(int j = 0 ; j < 4 ; j++){
      bitnumber[j] = count % 2;
      count = count / 2;
    }
    delay(1000);
    if(bitnumber[0] == 1){
        digitalWrite(7, HIGH);
    }else{
      digitalWrite(7, LOW);
    }

    if(bitnumber[1] == 1){
        digitalWrite(8, HIGH);
    }else{
      digitalWrite(8, LOW);
    }

    if(bitnumber[2] == 1){
        digitalWrite(12, HIGH);
    }else{
      digitalWrite(12, LOW);
    }

    if(bitnumber[3] == 1){
        digitalWrite(13, HIGH);
    }else{
      digitalWrite(13, LOW);
    }
  }
}
