// C++ code
//

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int LED4 = 8;
int LED5 = 7;
int LED6 = 6;
int dial = A0;
int dial2 = A1;

void setup(){
  for(int i = LED6;i<=LED1;i++){
   pinMode(i,OUTPUT); 
  }
  pinMode(dial, INPUT);
  pinMode(dial2, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(map(analogRead(dial),0,1023,LED4,LED6),HIGH);
  digitalWrite(map(analogRead(dial2),0,1023,LED3,LED1),HIGH);
  for(int i = LED6; i <= LED1; i++){
    digitalWrite(i, LOW);
  }
}
