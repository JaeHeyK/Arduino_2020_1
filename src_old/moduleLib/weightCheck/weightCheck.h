#ifndef __WEIGHTCHECK_H__
#define __WEIGHTCHECK_H__

#include <HX711.h>

class WeightSensor: public HX711 {
  private:
    const int LOADCELL_DOUT_PIN = 2;
    const int LOADCELL_SCK_PIN = 3;
    float calib_factor = 2000;
    double past_time, curr_time;
    long offset_weight = 0.0;
    int interval = 2000;
    float weight = 0.0;
    float fullWeight = 300;
    bool prevFullState = false, currFullState = false;

  public:
    WeightSensor();
    void setWeight();
    void checkWeight();
    bool isBinJustFulled();
    bool isBinFulled();
};

#endif
