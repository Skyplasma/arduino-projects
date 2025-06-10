#include "MotorController.h"

int enableA = 13;
int enableB = 8;
int in1 = 12;
int in2 = 11;
int in3 = 10;
int in4 = 9;

DCMotorController motorA = DCMotorController(enableA,in1,in2);//pwmPin, in1, in2
DCMotorController motorB = DCMotorController(enableB,in3,in4);//pwmPin, in1, in2


void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {

motorA.write(onwards(100));
motorB.write(onwards(100));
delay(2000);
motorA.write(onwards(-100));
motorB.write(onwards(-100));
delay(2000);

}

int onwards(int i){
return map(i,-100,100,-255,255);
}
