#include <Wire.h>
#include <RTClib.h>

// #include "src/moduleLib/ultraSonicSensor/ultraSonicSensor.h"
// #include "src/moduleLib/catMotor/catMotor.h"
// #include "src/moduleLib/weightCheck/weightCheck.h"
// #include "src/moduleLib/currentTime/curruentTime.h"
// #include "src/moduleLib/bleNotify/bleNotify.h"
// #include "src/toiletLib/toiletState.h"

#include "ultraSonicSensor.h"
#include "catMotor.h"
#include "weightCheck.h"
#include "curruentTime.h"
#include "bleNotify.h"
#include "src_old/toiletLib/toiletState.h"

RTC_DS3231 mainRTC;
CatSensor catUS;
CatMotor catMotor;
WeightSensor catBin;
DateTime current;

void setup() {  
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  catUS.setUS();
  catMotor.setMotor();
  catBin.setWeight();

  Serial.println("Hello!");
}

void loop() {
  catUS.checkUsing();
  catBin.checkWeight();
  current = getTime(mainRTC);
  

  if (catUS.isUsingStart()) {
    bleNotify(current, USING);
  } else if (catUS.isUsingFinish()) {
    lastUsingTime = current;
  }

  // if((getTimeGapWithSecond(current, lastUsingTime) > 30)) {
  //   bleNotify(current, CLEANING);
  //   catMotor.rotateMotor();
  //   lastUsingTime = NULL;
  // }

  if (catBin.isBinJustFulled()) {
    bleNotify(current, EMPTYING);
  }

}