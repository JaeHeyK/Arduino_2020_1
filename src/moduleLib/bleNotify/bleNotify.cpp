#include <Arduino.h>
#include <string>

#include "bleNotify.h"
#include "src/currentTime/curruentTime.h"

string typeString[3] = {"u", "c", "e"};

void bleNotify(ActionType type) {
  Serial1.write(getTimeWithString()+typeString[type]);
}
