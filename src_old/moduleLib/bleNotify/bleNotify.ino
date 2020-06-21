#include "bleNotify.h"
#include <string.h>

void setup() {  
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial1.begin(9600);
}

void loop() {
  if (Serial.available()) {
    bleNotify(Serial.read()-'1');
  }
}
