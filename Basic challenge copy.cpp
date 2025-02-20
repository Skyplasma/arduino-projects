// C++ code
int ledOn = 8; 
int i = 7;
void setup()
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode (2,INPUT);
  pinMode (3,INPUT);
}
void manual(){
  if (digitalRead(3)==HIGH){
    for (ledOn;ledOn<=i;ledOn++){
      digitalWrite(ledOn,HIGH);
      delay(200);
    }
   i++;
  }
  if (digitalRead(2)==HIGH){
    for (i;i<=ledOn;ledOn--){
      digitalWrite(ledOn,LOW);
      delay(200);
    }
    i--;
  }
  if(ledOn >= 14){
    for (i;i>=8;i--){
      digitalWrite(i,LOW);
    }
   ledOn = 8;
  }
  if(ledOn == 6){
    for (i;i<=12;i++){
      digitalWrite(i,HIGH); 
    }
    ledOn = 13;
  }
}
void loop()
{
  Serial.print(i);
  Serial.println(ledOn);
  void manual()
}