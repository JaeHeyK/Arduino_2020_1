#include <Arduino.h>
#include "weightCheck.h"

  WeightSensor::WeightSensor() {}

void WeightSensor::setWeight() {
  HX711::begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  HX711::set_scale(calib_factor);
  HX711::set_offset(offset_weight);
  //Reset the HX711:: to 0
  HX711::tare();
 
  //Get a baseline reading
  long zero_factor = HX711::read_average(); 
  
  past_time = millis();
}

void WeightSensor::checkWeight() {
  curr_time = millis();
  if(curr_time-past_time > interval) {
    float _weight = HX711::get_units()*1000;
    weight = (_weight > 0.0 ? _weight : 0.0) ;
    past_time = curr_time;
    Serial.println(weight);
  }
}

bool WeightSensor::isBinJustFulled() {
  bool justFulled = false;
  currFullState = (weight >= fullWeight ? true : false);
  if(!prevFullState && currFullState ) {
    justFulled = true;
  }
  prevFullState = currFullState;
  return justFulled;
}

bool WeightSensor::isBinFulled() {
  return (weight >= fullWeight ? true : false);
}