#include "OpticalSensor.h"
#include "../lib/TeensyThreads/TeensyThreads.h"
#include <SPI.h>
#include <cstdint>

// create volitile data buffer
// create contract for

float sampling_frequency = 500; // frequency set in Hz
unsigned long time_now = 0;
int count = 0;

int main()
{
    // Thread mutex for locking on register read and write opperations
    Threads::Mutex thread_lock;

    OpticalSensor os(thread_lock); // needs a constructor for running frequency
    // create thread for slip angle calculation (needs to be greater than main loop)

    while (true)
    {
        // make sure all conditions fit within 1/Fs time
        if ((unsigned long)(millis() - time_now) > (1 / sampling_frequency))
        {
            time_now = millis();
            count++;
            if (count >= sampling_frequency)
            {
                Serial.println("Hit");
            }
            // output sig1 to serial
            // output sig2 to serial ...
            // output s1, s2, etc. to SD card
        }
        else
        {
            Serial.println(count);
            count = 0;
        }
    }
}