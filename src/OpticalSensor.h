#ifndef _OPTICALSENSOR_
#define _OPTICALSENSOR_

#include <cstdint>
//#include "../lib/TeensyThreads.h"

#define OUT
// TODO: Move into a config file that's read from the SD card
// Set this to what pin your "INT0" hardware interrupt feature is on
#define Motion_Interrupt_Pin 0
// Set this to what pin SPI slave select is configured to
#define SPI_Slave_Select_Pin 10

class OpticalSensor
{
public:
    OpticalSensor();
    //OpticalSensor(Threads::Mutex &m);
    int8_t read_reg(int8_t reg_addr);
    void write_reg(int8_t reg_addr, int8_t data);
    void get_xydat(OUT int32_t xydat[3]);

private:
    // Private Members
    bool initComplete = false;
    const int32_t ncs = SPI_Slave_Select_Pin;
    //Threads::Mutex &thread_lock;
    // Methods
    void com_begin();
    void com_end();
    void upload_firmware();
    int32_t conv_twos_comp(int32_t b);
    void spi_setup();
    void sensor_startup();
};

#endif
