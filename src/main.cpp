#include "OpticalSensor.h"
#include "SlipAngle.h"
//#include "../lib/TeensyThreads.h"
#include <SPI.h>
#include <cstdint>
//#include "../lib/RingBuf.h"

int sampling_frequency = 100; // frequency set in Hz
unsigned long time_now = 0;
unsigned long t2 = 0;
volatile int count = 0;
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
        if ((unsigned long)(millis() - time_now) > (1000 / sampling_frequency))
        {
            time_now = millis();
            sa.getSlipAngle();
            count++;
            // output sig1 to serial
            // output sig2 to serial ...
            // output s1, s2, etc. to SD card
        }
        if ((unsigned long)(millis() - t2) > (unsigned long)(1000))
        {
            t2 = millis();
            Serial.print(slip_angle);
            Serial.print(" deg \n");
            Serial.println(count);
            count = 0;
        }
    }
}