#include <Stepper.h>

#define steps 2048
Stepper stepper(steps, 11, 9, 10, 8);

bool isFinished = 1;

void setup() {
  stepper.setSpeed(5); // 스텝모터 속도

  Serial.begin(9600);
 
}

void motor ()
{
  // 정면을 기준으로,
  stepper.step(-2390);  // 반시계방향으로 210도 회전
  delay(1000);
  stepper.step(2730);  // 시계방향으로 240도 회전
  delay(1000);
  stepper.step(-340);  // 반시계방향으로 30도 회전
  delay(2000);
  
}

void loop() {
  if ( isFinished == 1 )  // 고양이가 화장실 이용을 마침
    motor();
}
