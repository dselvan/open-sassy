#ifndef _SIGNALPROCESSING_
#define _SIGNALPROCESSING_

#define OUT

class SignalProcessing
{
public:
    static double diff(double signal_segment[5], double sampling_frequency);
    static void points_to_vector(int x[2], int y[2], OUT volatile double *mag, OUT volatile double *dir);
};

#endif
