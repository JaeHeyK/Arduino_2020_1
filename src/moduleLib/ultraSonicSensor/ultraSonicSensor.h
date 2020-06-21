#ifndef __ULTRASONICSENSOR_H__
#define __ULTRASONICSENSOR_H__

class CatSensor {
  private: 
    const int trig = 7;
    const int echo = 6;
    int enable_count = 0;
    int disable_count = 0;
    bool cur_sense;
    bool cat_state = false;
    unsigned long past_time, current_time;
    

  public:
    int checkInterval(bool, int);
    float measureDistance();
    void setUS();
    int checkUsing();
    bool isUsingStart();
    bool isUsingFinish();
};

#endif