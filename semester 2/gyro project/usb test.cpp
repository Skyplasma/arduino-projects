#include <Keyboard.h>
#include <Mouse.h>
#include <Wire.h>
#include <ADXL345.h>

ADXL345 adxl;

int

	float XRotationRaw;
float YRotationRaw;
float XVelocityRaw;
float YVelocityRaw;
float ZVelocityRaw;

void setup()
{
	//
	Keyboard.begin();
	Mouse.begin();
	Serial.begin(9600);
	adxl.powerOn();

	//gravity offset
	adxl.setAxisOffset(64,0,0)

	// Thresholds: each increment is 62.5mg per increment
	adxl.setActivityThreshold(75);
	adxl.setInactivityThreshold(75);

	// Axis activate the thresholds true
	adxl.setActivityX(1);
	adxl.setActivityY(1);
	adxl.setActivityZ(1);
	adxl.setInactivityX(1);
	adxl.setInactivityY(1);
	adxl.setInactivityZ(1);

	// look of tap movement on this axes - 1 == on; 0 == off
	adxl.setTapDetectionOnX(0);
	adxl.setTapDetectionOnY(0);
	adxl.setTapDetectionOnZ(1);

	// set values for what is a tap, and what is a double tap (0-255)
	adxl.setTapThreshold(50);	  // 62.5mg per increment
	adxl.setTapDuration(15);	  // 625us per increment
	adxl.setDoubleTapLatency(80); // 1.25ms per increment
	adxl.setDoubleTapWindow(200); // 1.25ms per increment

	// set values for what is considered freefall (0-255)
	adxl.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
	adxl.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment

	// setting all interrupts to take place on int pin 1
	// I had issues with int pin 2, was unable to reset it
	adxl.setInterruptMapping(ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_DOUBLE_TAP_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_FREE_FALL_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_ACTIVITY_BIT, ADXL345_INT1_PIN);
	adxl.setInterruptMapping(ADXL345_INT_INACTIVITY_BIT, ADXL345_INT1_PIN);
}

void loop()
{
}





/*
float NetAcceleration[3]()
{
	float xyz[3];
	adxl.getAcceleration(xyz[]);
	float ax = xyz[0];
	float ay = xyz[1];
	float az = xyz[2];
	float DegreeXYPlane; //0 forwards, 90 right, 180 back, 270 left
	float DegreeXZPlane; //0 forwards, 90 up, 180 back, 270 down
	float totalvelocity;
}
	*/