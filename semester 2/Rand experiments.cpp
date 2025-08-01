// C++ code
//

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int LED4 = 6;
int LED5 = 5;
int LED6 = 3;
int dial = A0;
int dial2 = A1;

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(dial, INPUT);
  pinMode(dial, INPUT);
  Serial.begin(9600);
}

void loop(){
  analogWrite(LED1, Rand(dial, dial2));
  delay(50);
  analogWrite(LED2, Rand(dial, dial2));
  delay(50);
  analogWrite(LED3, Rand(dial, dial2));
  delay(50);
  analogWrite(LED4, Rand(dial, dial2));
  delay(50);
  analogWrite(LED5, Rand(dial, dial2));
  delay(50);
  analogWrite(LED6, Rand(dial, dial2));
  delay(50);
  Serial.println(reading(dial));
}

int Rand( int i, int e){
  return random(reading(i),reading(e));
}

int reading( int i){
  return map(analogRead(i),0,1023,0,255);
}
