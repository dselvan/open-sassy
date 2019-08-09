#include "SignalProcessing.h"
#include <cstddef>
#include <math.h>

#define OUT

double SignalProcessing::diff(double signal_segment[5], double sampling_frequency)
{

    double firstDer = 0.0;
    double t = 1 / ((sampling_frequency > 0) ? sampling_frequency : 1);

    size_t i = 2;

    firstDer = (4.0 / 3.0 * (signal_segment[i + 1] - signal_segment[i - 1]) / (2.0 * t) -
                1.0 / 3.0 * (signal_segment[i + 2] - signal_segment[i - 2]) / (4.0 * t));

    return firstDer;
}

void SignalProcessing::points_to_vector(int x[2], int y[2], OUT volatile double *mag, OUT volatile double *dir)
{
    int x_dist = x[1] - x[0];
    int y_dist = y[1] - y[0];

    *mag = sqrt(pow((double)x_dist, 2) + pow((double)y_dist, 2));
    *dir = atan2((double)y_dist, (double)x_dist) * (180 / M_PI);
}