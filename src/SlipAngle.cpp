#include "SlipAngle.h"
#include "OpticalSensor.h"
#include "SignalProcessing.h"

#define OUT

SlipAngle::SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle)
{
    this->os = &os;
    this->sampling_frequency = sampling_frequency;
    this->slip_angle = slip_angle;
}

void SlipAngle::start()
{
}

double getSlipAngle()
{
    SlipAngle::os->get_xydat(SlipAngle::xydat);

    // get xy data from OpticalSensor
    // convert it to slip SlipAngle
    // update SlipAngle pointer
}