#include <Arduino.h>
#include "statusLED.h"

void setLED() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void usingLED(Status state) {
  digitalWrite(12, state);
}

void weightLED(Status state) {
  digitalWrite(13, state);
}
