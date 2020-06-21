#include <Arduino.h>
#include "catMotor.h"

CatMotor::CatMotor(int steps, int in1, int in2, int in3, int in4):Stepper::Stepper(steps, in1, in2, in3, in4) {};

void CatMotor::setSpeed(long speed) {
	Stepper::setSpeed(speed);
};

void CatMotor::step(int steps) {
	Stepper::step(steps);
};

void CatMotor::rotateMotor() {
	this->step(-2390);  // 210 degree turn counterclockwise
	delay(100);
	this->step(2730);  // 240 degree turn clockwise
	delay(100);
	this->step(-340);  // 30 degree turn counterclockwise
};
