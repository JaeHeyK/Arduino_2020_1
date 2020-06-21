#include <Arduino.h>
#include "catMotor.h"

CatMotor::CatMotor():Stepper::Stepper(2048, 11, 9, 10, 8) {};

void CatMotor::setMotor() {
	Stepper::setSpeed(5);
};

void CatMotor::rotateMotor() {
	Stepper::step(-2390);  // 210 degree turn counterclockwise
	delay(100);
	Stepper::step(2730);  // 240 degree turn clockwise
	delay(100);
	Stepper::step(-340); // 30 degree turn counterclockwise
	delay(1000);
};
