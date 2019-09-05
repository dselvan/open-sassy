#include "SignalProcessing.h"
#include "../lib/RingBuf.h"
#include <cstddef>
#include <math.h>

#define OUT

double SignalProcessing::diff(RingBuf<int, 5> &signal_buffer, int sampling_frequency)
{

    double firstDer = 0.0;
    double t = 1.0 / ((sampling_frequency > 0) ? sampling_frequency : 1);

    firstDer = (4.0 / 3.0 * (double)(signal_buffer[3] - signal_buffer[1]) / (2.0 * t) -
                1.0 / 3.0 * (double)(signal_buffer[4] - signal_buffer[0]) / (4.0 * t));

    return firstDer;
}

void SignalProcessing::points_to_vector(int x1, int x2, int y1, int y2,
                                        OUT volatile double *mag, OUT volatile double *dir)
{
    int x_dist = x2 - x1;
    int y_dist = y2 - y1;

    *mag = sqrt(pow((double)x_dist, 2) + pow((double)y_dist, 2));
    *dir = atan2((double)y_dist, (double)x_dist) * (180 / M_PI);
}