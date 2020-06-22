#include <Wire.h>
#include <RTClib.h>

#include "ultraSonicSensor.h"
#include "catMotor.h"
#include "weightCheck.h"
#include "curruentTime.h"
#include "bleNotify.h"
//#include "src_old/toiletLib/toiletState.h"

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
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);

  Serial.println("Hello!");
}

void loop() {
  catUS.checkUsing();
  catBin.checkWeight();
  //current = getTime(mainRTC);

  if (catUS.isUsingStart()) {
    bleNotify(current,USING);
  }
  
  if (catUS.isUsingFinish()) {
    bleNotify(current, CLEANING);
    catMotor.rotateMotor();
  }

  if (catBin.isBinJustFulled()) {
    Serial.println("Bin just fulled!!");
    bleNotify(current, EMPTYING);
  }

}
