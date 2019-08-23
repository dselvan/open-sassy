#include "OpticalSensor.h"
#include "SlipAngle.h"
//#include "../lib/TeensyThreads.h"
#include <SPI.h>
#include <cstdint>
//#include "../lib/RingBuf.h"

// create volitile data buffer
// create contract for

float sampling_frequency = 50; // frequency set in Hz
unsigned long time_now = 0;
int count = 0;
volatile double slip_angle = 0;

//RingBuf<int, 5> rb;

int main()
{
    // Thread mutex for locking on register read and write opperations
    //Threads::Mutex thread_lock;

    //OpticalSensor os(thread_lock); // needs a constructor for running frequency
    OpticalSensor os;
    // create thread for slip angle calculation (needs to be greater than main loop)
    SlipAngle sa(os, sampling_frequency, &slip_angle);

    while (true)
    {
        // make sure all conditions fit within 1/Fs time
        if ((unsigned long)(millis() - time_now) > (1000 / sampling_frequency))
        {
            time_now = millis();
            count++;
            if (count <= sampling_frequency)
            {
                sa.getSlipAngle();
                Serial.print(slip_angle);
                Serial.print(" deg \n");
            }
            else
            {
                Serial.println("------------------------Hit min frequency-----------------------");
                count = 0;
            }
            // output sig1 to serial
            // output sig2 to serial ...
            // output s1, s2, etc. to SD card
        }
    }
}