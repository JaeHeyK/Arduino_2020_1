#include <Arduino.h>
#include <RTClib.h>

void beginTime(const RTC_DS3231& rtc) {
  rtc.begin();
}

DateTime getTime(const RTC_DS3231& rtc) {
  DateTime now = rtc.now();
  return now;
}

int getTimeGapWithSecond(DateTime after, DateTime before) {
  if(before == NULL) {
    return 0;
  }
  TimeSpan gap = after - before;
  int gapMinute = gap.totalseconds();
  return gapMinute;
}

char* getTimeWithCharArray(DateTime now, char* dateBuffer) {
  now = now - TimeSpan(0,0,2,0);
  dateBuffer[0] = (now.year()-2000)/10 + 48;
  dateBuffer[1] = (now.year()-2000)%10 + 48;
  dateBuffer[2] = now.month()/10 + 48;
  dateBuffer[3] = now.month()%10 + 48;
  dateBuffer[4] = now.day()/10 + 48;
  dateBuffer[5] = now.day()%10 + 48;
  dateBuffer[6] = now.hour()/10 + 48;
  dateBuffer[7] = now.hour()%10 + 48;
  dateBuffer[8] = now.minute()/10 + 48;
  dateBuffer[9] = now.minute()%10 + 48;
  
  return dateBuffer;
}