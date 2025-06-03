int enableA 13;
int enableB 8;
int in1 12;
int in2 11;
int in3 10;
int in4 9;

int speed;

void setup(){
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    speed = 255;
}
void loop(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    for(int i = 0,i <= 123,i++){
        analogWrite(enableA,(speed--i));
        analogWrite(enableB,speed);
        Wait(50);
    }
    for(int i = 0,i <= 123,i++){
        analogWrite(enableA,speed);
        analogWrite(enableB,speed--i);
        Wait(100);
    }
    for(int = 123,i<=0,i--){
        analogWrite(enableA,(speed--i));
        analogWrite(enableB,speed);
        Wait(50);
    }
}