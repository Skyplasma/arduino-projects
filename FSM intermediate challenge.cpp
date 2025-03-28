// C++ code
int ledOn = 8; 
int i = 7;
int leftButton = 3;
int rightButton = 2;
int STATE = 1;
int STATEWRITTEN[0] = ("Idle","Manual","Auto","On","Off");


void setup()
{
  Serial.begin(9600);
  for (int pinset=8;pinset == 14;pinset++){
  pinMode(pinset,OUTPUT);
  }
  pinMode (rightButton,INPUT);
  pinMode (leftButton,INPUT);
}
int Manual(){
  if (digitalRead(leftButton) == HIGH){
    for (ledOn;ledOn<=i;ledOn++){
      digitalWrite(ledOn,HIGH);
      delay(200);
    }
   i++;
  }
  if (digitalRead(rightButton) == HIGH){
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
 return;
}
void Wait(){
  Serial.print("Finished");
  Serial.println(STATEWRITTEN[STATE]); 
  Serial.print("Possible Inputs");
  for(int a = 0;a>=4;a++){
    Serial.print(STATEWRITTEN[a]);
  }
  Serial.println("Awaiting Input");
}
void serialEvent(){
  while (Serial.available()); {
    char incomingChar = Serial.read();
    Serial.print("Received: ");
    Serial.println(incomingChar);
    Serial.print("moving to");
    Serial.print(STATEWRITTEN[STATE--]);

  } 
}
void loop()
{
  Serial.print(i);
  Serial.println(ledOn);
  Serial.println("CHECKING STATE");
  Serial.println(STATE);
  void wait()
}
