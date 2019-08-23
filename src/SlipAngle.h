#ifndef _SLIPANGLE_
#define _SLIPANGLE_

#define OUT

#include "OpticalSensor.h"
#include "../lib/TeensyThreads.h"
#include "../lib/RingBuf.h"

class SlipAngle
{
public:
    SlipAngle() = delete;
    SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle);
    // SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle,
    //           Threads::Mutex &m);
    void start();
    void getSlipAngle();

private:
    // Members
    OpticalSensor *os;
    double *slip_angle;
    //Threads::Mutex &thread_lock;
    double sampling_frequency;
    int xydat[2];
    RingBuf<int, 5> x_buffer;
    RingBuf<int, 5> y_buffer;
    // Methods
};

#endif
