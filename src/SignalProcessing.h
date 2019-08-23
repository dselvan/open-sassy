#ifndef _SIGNALPROCESSING_
#define _SIGNALPROCESSING_

#include "../lib/RingBuf.h"

#define OUT

class SignalProcessing
{
public:
    SignalProcessing() = delete;
    SignalProcessing(SignalProcessing const &) = delete;
    void operator=(SignalProcessing const &) = delete;

    static double diff(RingBuf<int, 5> &signal_buffer, double sampling_frequency);
    static void points_to_vector(int x1, int x2, int y1, int y2,
                                 OUT volatile double *mag, OUT volatile double *dir);
};

#endif
