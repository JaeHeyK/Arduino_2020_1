#include "catMotor.h"

int steps = 2048;
CatMotor motor(steps, 11, 9, 10, 8);

bool isFinished = 1;

void setup() {
  motor.setSpeed(5); // 스텝모터 속도
  Serial.begin(9600);
}

void loop() {
  if ( isFinished == 1 )  // 고양이가 화장실 이용을 마침
    motor.rotateMotor();
  delay(1000);
}
