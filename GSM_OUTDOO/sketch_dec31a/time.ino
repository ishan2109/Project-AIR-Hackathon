#include "time.h"

#include <Wire.h>  // for I2C with RTC module

#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

String get_timestamp_str() {

  DateTime now = rtc.now();

  unsigned long hours = (now.hour(), DEC);
  String hoursStr = hours ;

  unsigned long minutes = ((timestamp + timeoffset) % 3600) / 60;
  String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);

  unsigned long seconds = (timestamp + timeoffset) % 60;
  String secondStr = seconds < 10 ? "0" + String(seconds) : String(seconds);

  return hoursStr + ":" + minuteStr + ":" + secondStr;
}
