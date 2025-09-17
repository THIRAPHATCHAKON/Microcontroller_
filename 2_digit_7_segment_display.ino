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
int Map7 [7]={4,5,6,7,8,9,10};// a,b,c,d,e,f,g
const int digit1 = 2;
const int digit2 = 3;
int number_add , sib , nuay = 0;
int time = 10;
void setup() {
  for(int i=0;i<=6;i++)
  {
    pinMode(Map7[i], OUTPUT);
  }
  pinMode(digit1 , OUTPUT);
  pinMode(digit2 , OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  display();
}

void calculate(int number_add){
  nuay = number_add % 10;
  sib = number_add / 10;
}

void display_digit(int number){
  for(int j=6;j>=0;j--)
  {
    Serial.print(bitRead(Num7[number],j));
    digitalWrite(Map7[j],bitRead(Num7[number],j));
  }
  for(int j=6;j>=0;j--)
  {
    digitalWrite(Map7[j],LOW);
  }
}

void display(){
  for(int i = 0 ; i <= 99 ; i++){
  calculate(i);
  for(int round = 1 ; round <= 20 ; round++){
  Serial.print(">>>>");
  Serial.println(nuay);
  digitalWrite(digit1 , LOW);
  Serial.println("digit1 on");
  delay(time);
  display_digit(nuay);
  digitalWrite(digit1 , HIGH);
  Serial.println("digit1 off");
  delay(time);
  
  Serial.print(">>>> ");
  Serial.println(sib);
  digitalWrite(digit2 , LOW);
  Serial.println("digit2 on");
  delay(time);
  display_digit(sib);
  digitalWrite(digit2 , HIGH);
  Serial.println("digit2 off");
  delay(time);
  }
  }
}
  
