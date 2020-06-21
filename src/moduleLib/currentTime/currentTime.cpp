#include <Arduino.h>
#include <RTClib.h>

void beginTime(const RTC_DS3231& rtc) {
  rtc.begin();
}

DateTime getTime(const RTC_DS3231& rtc) {
  DateTime now = rtc.now();
  return now;
}

int getTimegapWithMinute(DateTime after, DateTime before) {
  TimeSpan gap = after - before;
  int gapMinute = gap.totalseconds() / 60;
  return gapMinute;
}

String getTimeWithString(DateTime now) {
  now = now - TimeSpan(0,0,2,0);
  unsigned long now_day = now.day()*1000;
  unsigned long now_time = (now.year()-2000)*100000000 + now.month()*1000000 + now_day*10 + now.hour()*100 + now.minute();

  return String(now_time);
}