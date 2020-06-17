#include "src/HX711.h" 
 
#define LOADCELL_DOUT_PIN 2
#define LOADCELL_SCK_PIN 3
 
HX711 scale;
 
//-7050 worked for my 440lb max scale setup
float calibration_factor = 10000;
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from scale");
  Serial.println("After readings begin, place known weight on scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
 
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  //Reset the scale to 0
  scale.tare();
 
  //Get a baseline reading
  long zero_factor = scale.read_average(); 
  //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
}
 
void loop() 
{
  //Adjust to this calibration factor
  scale.set_scale(calibration_factor);
 
  Serial.print("Reading: ");
  Serial.print(scale.get_units()*1000, 1);
  //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
  //기존 예제가 파운드(lbs) 기준이지만 우리는 킬로그램(kg)을 쓸것이므로 'kg'로 바꿉시다.
  Serial.print(" g"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
 
  if(Serial.available())
  {
    char temp = Serial.read();
 
    //변경 : 보정값 범위 설정 가능하도록 변경
    switch(temp)
    {
      case '1':
        calibration_factor += 10;
        break;
      case '2':
        calibration_factor += 50;
        break;
      case '3':
        calibration_factor += 100;
        break;
      case '4':
        calibration_factor += 1000;
        break;
 
      case 'a':
        calibration_factor -= 10;
        break;
      case 's':
        calibration_factor -= 50;
        break;
      case 'd':
        calibration_factor -= 100;
        break;
      case 'f':
        calibration_factor -= 1000;
        break;
    }
  }
  
}
