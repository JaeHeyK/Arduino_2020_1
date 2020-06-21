#include <Arduino.h>
#include <string.h>
#include <RTClib.h>

#include "bleNotify.h"
#include "curruentTime.h"

char date[12] = {0};
char typeString[3] = {'u', 'c', 'e'};

void bleNotify(DateTime now, ActionType type) {
  //char date[12] = "2006221120";
  getTimeWithCharArray(now, date);
  date[10] = typeString[type];

  Serial1.write(date);
  date[12] = {0};
}
