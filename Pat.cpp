#include "MotorController.h"


DCMotorController motor1 = DCMotorController(13, 12, 11); // pwmPin, in1, in2
DCMotorController motor2 = DCMotorController(8, 10, 9); // pwmPin, in1, in2


void setup(){
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}


void loop()
{
  
  motor1.write(goNess(100));
  delay(1000);

  motor1.write(goNess(90));
  delay(1000);

  motor1.write(goNess(80));
  delay(1000);

  motor1.write(goNess(-100));
  delay(1000);

  motor2.write(goNess(100));
  delay(3000);

  motor2.write(goNess(-100));
  delay(1000);

  
}

int goNess(int blah){
  return map(blah, -100, 100, -255, 255);
}
