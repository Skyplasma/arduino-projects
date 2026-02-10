void setup(){
  for(int i = 6;i<=11;i++) pinMode(i,OUTPUT); 
}
void loop(){
  digitalWrite(map(analogRead(A0),0,1023,8,6),HIGH);
  digitalWrite(map(analogRead(A1),0,1023,9,11),HIGH);
  for(int i = 6; i <= 11; i++) digitalWrite(i, LOW);
}
