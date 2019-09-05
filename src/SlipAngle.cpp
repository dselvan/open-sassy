#include "SlipAngle.h"
#include "OpticalSensor.h"
#include "SignalProcessing.h"
//#include "../lib/CircularBuffer.h"

#define OUT

SlipAngle::SlipAngle(OpticalSensor &os, int sampling_frequency, OUT double *slip_angle)
{
    this->os = &os;
    this->sampling_frequency = sampling_frequency;
    this->slip_angle = slip_angle;

    //set ring buffers to 0 for initial reads before 5 data points have been taken in
    for (int i = 0; i < 5; i++)
    {
        SlipAngle::x_buffer.push(0);
        SlipAngle::y_buffer.push(0);
    }
}

void SlipAngle::start()
{
}

void SlipAngle::getSlipAngle()
{
    int data = 0;
    double xdot = 0;
    double ydot = 0;
    double mag = 0;
    double dir = 0;

    SlipAngle::os->get_xydat(SlipAngle::xydat);

    SlipAngle::x_buffer.pop(data);
    SlipAngle::y_buffer.pop(data);
    if (SlipAngle::xydat[2] > 0)
    {
        SlipAngle::x_buffer.push(SlipAngle::xydat[0]);
        SlipAngle::y_buffer.push(SlipAngle::xydat[1]);
    }
    else
    {
        SlipAngle::x_buffer.push(0);
        SlipAngle::y_buffer.push(0);
    }

    xdot = SignalProcessing::diff(SlipAngle::x_buffer, SlipAngle::sampling_frequency);
    ydot = SignalProcessing::diff(SlipAngle::y_buffer, SlipAngle::sampling_frequency);
    SignalProcessing::points_to_vector(0, xdot, 0, ydot,
                                       &mag, &dir);

    *SlipAngle::slip_angle = dir;
}