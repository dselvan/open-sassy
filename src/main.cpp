#include "OpticalSensor.h"
#include <SPI.h>
#include <cstdint>

byte testctr = 0;
unsigned long currTime;
unsigned long timer;
unsigned long pollTimer;
volatile int32_t xydat[2];

int main()
{
    OpticalSensor *os = new OpticalSensor();

    while (true)
    {
        currTime = millis();

        if (currTime > timer)
        {
            Serial.println(testctr++);
            timer = currTime + 2000;
        }

        if (currTime > pollTimer)
        {
            os->get_xydat(xydat);
            if (xydat[0] != 0 || xydat[1] != 0)
            {
                Serial.print("x = ");
                Serial.print(xydat[0]);
                Serial.print(" | ");
                Serial.print("y = ");
                Serial.println(xydat[1]);
            }
            pollTimer = currTime + 20;
        }
    }
}