#ifndef __CATMOTOR_H__
#define __CATMOTOR_H__

#include <Stepper.h>

class CatMotor: public Stepper {
  public: 
    CatMotor(int, int, int, int, int);
    void setSpeed(long);
    void step(int);
    void rotateMotor();
};

#endif
