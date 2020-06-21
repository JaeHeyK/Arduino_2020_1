#include <Arduino.h>
#include <string.h>
#include <RTClib.h>

#include "bleNotify.h"
//#include "../currentTime/curruentTime.h"

char* typeString[3] = {'u', 'c', 'e'};

void bleNotify(int type) {
  //Serial1.write(typeString[type]);
  char ch[12] = "2006221120";
  ch[10] = typeString[type];
  // DateTime(2020,6,22,11,20,3).toString("YYMMDDhhmm").toCharArray(ch, 10);
  // ch[11] = typeString[type];
  Serial1.write(ch);
}

// void bleNotify(ActionType type) {
//   Serial1.write(getTimeWithString()+typeString[type]);
// }
