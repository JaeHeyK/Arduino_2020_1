#include <Arduino.h>
#include <Stepper.h>
#include "catMotor.h"

void StepperMotor()
{
	Stepper stepper(2048, 11, 9, 10, 8);
	stepper.setSpeed(5); // motor speed
	
	stepper.step(-2390);  // 210 degree turn counterclockwise
	delay(100);
	stepper.step(2730);  // 240 degree turn clockwise
	delay(100);
	stepper.step(-340);  // 30 degree turn counterclockwise
}
