#include "MotorController.h"


DCMotorController motor1 = DCMotorController(13, 12, 11); // pwmPin, in1, in2
DCMotorController motor2 = DCMotorController(8, 10, 9); // pwmPin, in1, in2


void setup(){
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

  motor1.forward(goNess(100));
  motor2.forward(goNess(70));
  Serial.println(goNess(100));
  delay(2500);

  motor1.reverse(goNess(50));
  motor2.forward(goNess(50));
  Serial.println(goNess(80));
  delay(175);

  motor1.forward(goNess(100));
  motor2.forward(goNess(70));
  Serial.println(goNess(60));
  delay(1000);

  motor1.reverse(goNess(30));
  motor2.forward(goNess(30));
  Serial.println(goNess(80));
  delay(110);

  motor1.forward(goNess(100));
  motor2.forward(goNess(70));
  Serial.println(goNess(60));
  delay(1500);
}


void loop()
{
  

}

int goNess(int blah){
  return map(blah, 0, 100, 0, 255);
}
