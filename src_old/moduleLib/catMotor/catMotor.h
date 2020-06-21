#ifndef __CATMOTOR_H__
#define __CATMOTOR_H__

#include <Stepper.h>

class CatMotor: public Stepper {
  public: 
    CatMotor();
    void setMotor();
    void step(int);
    void rotateMotor();
};

#endif
