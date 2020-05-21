#include <Stepper.h>      // 스테핑 모터 라이브러리 정의 

int stepsPerRev = 2048; // 한바퀴(360): 2048 , 반 바퀴(180) : 1024
Stepper stepper (stepsPerRev, 11,9,10,8); // ( IN4,IN2,IN3,IN1) 

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(20);   // 스텝모터의 스피드 설정
}

void loop()
{
  
  stepper.step(stepsPerRev);  // 한 바퀴 회전 명령
  delay(1000); 
  stepper.step(-stepsPerRev);  // 반대 방향으로 한 바퀴 회전
  delay(1000);
}