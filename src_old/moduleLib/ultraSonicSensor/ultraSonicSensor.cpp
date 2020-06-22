#include <Arduino.h>
#include "ultraSonicSensor.h"

int CatSensor::checkInterval (bool state, int enable_count) {
   return (state || enable_count > 0 ? 200 : 2000);
}

float CatSensor::measureDistance() {
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
   
    unsigned long duration = pulseIn(echo, HIGH);
   
    return (duration / 29.0 / 2.0);
}

void CatSensor::setUS() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  past_time = millis();
}
 
void CatSensor::checkUsing() {
  current_time = millis();
  
  useState = 0;

  if(current_time - past_time > 500) {
    float distance = measureDistance();  
    cur_sense = distance < 8 ? true : false;
   
    if (cur_sense) {
      if(!cat_state) {
        if(enable_count < 5) {
          enable_count++;
        } else {
          enable_count = 0;
          cat_state = true;
          useState = 1;
        }
      } else {
       enable_count = 0;
      }
    } else {
      if(cat_state) {
        if(disable_count < 10) {
          disable_count++;
        } else {
          disable_count = 0;
          cat_state = false;
          useState = 2;
        }
      } else {
        disable_count = 0;
      }
      
    }
    past_time = current_time;
    Serial.print(cat_state);
    Serial.print("  ");
    Serial.print(enable_count);
    Serial.print("  ");
    Serial.print(disable_count);
    Serial.print("\n");
  }
}

bool CatSensor::isUsingStart() {
  return (useState == 1);
}

bool CatSensor::isUsingFinish() {
  return (useState == 2);
}