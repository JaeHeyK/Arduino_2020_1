#include <Wire.h>
#include <RTClib.h>
#include <string.h>

#include "ultraSonicSensor.h"
#include "catMotor.h"
#include "weightCheck.h"
#include "curruentTime.h"
#include "bleNotify.h"
#include "statusLED.h"

RTC_DS3231 mainRTC;
CatSensor catUS;
CatMotor catMotor;
WeightSensor catBin;
DateTime current = DateTime(2020,6,23,11,30,0);

void setup() {  
  Serial.begin(9600);
  Serial1.begin(9600);
  Wire.begin();
  catUS.setUS();
  catMotor.setMotor();
  catBin.setWeight();
  beginTime(mainRTC);
  setLED();

  Serial.println("Hello!");
}

void loop() {
  catUS.checkUsing();
  catBin.checkWeight();
  current = getTime(mainRTC);
  char timeStr[12] = {0};
  Serial.println(getTimeWithCharArray(current, timeStr));
  //Serial.println("hello");

  if (catUS.isUsingStart()) {
    usingLED(ON);
    bleNotify(current,USING);
  }
  
  if (catUS.isUsingFinish()) {
    usingLED(OFF);
    bleNotify(current, CLEANING);
    catMotor.rotateMotor();
  }

  if (catBin.isBinJustFulled()) {
    bleNotify(current, EMPTYING);
  }

  if(catBin.isBinFulled()) {
    weightLED(ON);
  } else {
    weightLED(OFF);
  }

}
