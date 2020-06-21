#ifndef __CURRENTTIME_H__
#define __CURRENTTIME_H__


void beginTime(const RTC_DS3231& rtc);
DateTime getTime(const RTC_DS3231& rtc);
int getTimeGapWithMinute(DateTime after, DateTime before);
String getTimeWithString(DateTime time);

#endif