// C++ code
int i = 4;
int current = 1;
int increment = 1;
int ledShift = 3;
int digit = 1;
int difference;
void setup()
{
  Serial.begin(9600);
  for (i = 4;i <= 13;i++){ 
  pinMode(i,OUTPUT);
  }
  pinMode (2,INPUT);
  pinMode (3,INPUT);
}

void loop()
{
  
  Serial.print(current);
  Serial.print("  ");
  Serial.print(increment);
  Serial.print("  ");
  Serial.print(digit);
  Serial.print("  ");
  
  difference = increment - current;
  Serial.println(difference);
  if(difference > digit){
    digitalWrite(((increment/digit) + ledShift),LOW); 
    increment = increment - digit;
  }
  
  if(digitalRead(3) == HIGH){
    current++;
    delay(250);
    
  }
   if(digitalRead(2) == HIGH){
    current--;
    delay(250);
  }
  if(current == increment){
    digitalWrite(((increment/digit) + ledShift),HIGH);
    increment = increment + digit;
  }
  
  if(current == (digit*10)){
    for(int a=13;a>4;a--){
      digitalWrite(a,LOW);
    }
    digit = digit * 10;
    increment = digit;
  }
  if(current== digit-1){
    for(int b=4;b<13;b++){
      digitalWrite(b,HIGH);
    }
    digit = digit / 10;
    increment = digit;
  }
}