#include "ultraSonicSensor.h"

CatSensor catUS;

void setup() {
  Serial.begin(9600);
  catUS.setUS();
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행됩니다.
void loop() {
  //Serial.println(catUS.measureDistance());
  int useState = catUS.checkUsing();
  if (useState == 1) {
    Serial.println("Start using");
  } else if (useState == -1) {
    Serial.println("Finish using");
  }
}
