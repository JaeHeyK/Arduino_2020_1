#include "weightCheck.h" 

WeightSensor scale;
 
void setup() 
{
  Serial.begin(9600);
  scale.setWeight();
}
 
void loop() 
{
  scale.checkWeight();
  if(scale.isBinJustFulled()) {
    Serial.println("Bin Fulled!!");
  }
}