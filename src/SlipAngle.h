#ifndef _SLIPANGLE_
#define _SLIPANGLE_

#define OUT

#include "OpticalSensor.h"
#include "../lib/TeensyThreads/TeensyThreads.h"

class SlipAngle
{
public:
    SlipAngle() = delete;
    SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle);
    SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle,
              Threads::Mutex &m);
    void start();

private:
    // Members
    OpticalSensor *os;
    double *slip_angle;
    Threads::Mutex &thread_lock;
    double sampling_frequency;
    int xydat[2];
    // Methods
    double getSlipAngle();
    int *getXYDat();
};

#endif
