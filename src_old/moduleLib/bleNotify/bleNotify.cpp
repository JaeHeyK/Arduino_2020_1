#include <Arduino.h>
#include <string.h>
#include <RTClib.h>

#include "bleNotify.h"
//#include "../currentTime/curruentTime.h"

//char date[12] = {0};
char typeString[3] = {'u', 'c', 'e'};

void bleNotify(ActionType type) {
  char date[12] = "2006221120";
  //getTimeWithCharArray(getTime(rtc), date);
  date[10] = typeString[type];
  // DateTime(2020,6,22,11,20,3).toString("YYMMDDhhmm").toCharArray(ch, 10);
  // ch[11] = typeString[type];
  Serial1.write(date);
  date[12] = {0};
}
