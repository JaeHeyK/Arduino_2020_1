#include "main.h"

int StepperMotor()
{
	Stepper stepper(2048, 11, 9, 10, 8);
	stepper.setSpeed(15); // motor speed
	Serial.begin(9600);
	
	stepper.step(1195);  // 210 degree turn counterclockwise
	delay(1000);
	stepper.step(-1365);  // 240 degree turn clockwise
	delay(1000);
	stepper.step(170);  // 30 degree turn counterclockwise
	delay(2000);
 
}
