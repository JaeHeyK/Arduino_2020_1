#ifndef __STATUSLED_H__
#define __STATUSLED_H__

typedef enum _Status {
  OFF,
  ON
} Status;

void setLED();
void usingLED(Status state);
void weightLED(Status state);

#endif
