// Date and time functions using RX8025 RTC connected via I2C and Wire lib

#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

//char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

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

unsigned long What_time ()
{
  
  DateTime now = rtc.now(); //get the current date-time

  unsigned long now_time;

  unsigned long now_day = now.day()*1000;
  now_time = (now.year()-2000)*100000000 + now.month()*1000000 + now_day*10 + now.hour()*100 + now.minute();
  delay(1000);

  return now_time; 
}

void loop ()
{
  unsigned long now_time = What_time();
  Serial.println(now_time);
  
}
