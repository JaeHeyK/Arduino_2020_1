// Date and time functions using RX8025 RTC connected via I2C and Wire lib

#include <Wire.h>
#include <RTClib.h>
#include "curruentTime.h"

RTC_DS3231 rtc;

void setup ()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
   if (! rtc.begin() )
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  if ( rtc.lostPower() )
  {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
}

void loop ()
{
  DateTime now = rtc.now();
  Serial.println(getTimeWithString(now));
  delay(1000);
}