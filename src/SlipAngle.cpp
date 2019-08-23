#include "SlipAngle.h"
#include "OpticalSensor.h"
#include "SignalProcessing.h"
//#include "../lib/CircularBuffer.h"

#define OUT

SlipAngle::SlipAngle(OpticalSensor &os, double sampling_frequency, OUT double *slip_angle)
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
    SlipAngle::x_buffer.push(SlipAngle::xydat[0]);
    SlipAngle::y_buffer.push(SlipAngle::xydat[1]);

    xdot = SignalProcessing::diff(SlipAngle::x_buffer, SlipAngle::sampling_frequency);
    //Serial.println(xdot);
    ydot = SignalProcessing::diff(SlipAngle::y_buffer, SlipAngle::sampling_frequency);
    //Serial.println(ydot);
    SignalProcessing::points_to_vector(0, xdot, 0, ydot,
                                       &mag, &dir);

    *SlipAngle::slip_angle = dir;
    // if ((dir > 0) && (dir < 180))
    // {
    //     *slip_angle = 90 - dir;
    // }
    // // else if ((dir > 90) && (dir < 180))
    // // {
    // //     *slip_angle = dir - 90;
    // // }
    // else
    // {
    //     *slip_angle = -999;
    // }
    // if 0 < dir < 90 then *slip_angle = 90 - d;
    // else if 90 < dir < 180 then *slip_angle = d - 90;
    // else *slip_angle = -999;
}