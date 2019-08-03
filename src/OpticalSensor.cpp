#include "OpticalSensor.h"
#include "PMW3360Registers.h"
#include "PMW3360Firmware.h"
#include <SPI.h>
#include <avr/pgmspace.h>

OpticalSensor::OpticalSensor()
{
    spi_setup();
    sensor_startup();

    delay(5000);

    initComplete = true;
}

void OpticalSensor::com_begin()
{
    digitalWrite(ncs, LOW);
}

void OpticalSensor::com_end()
{
    digitalWrite(ncs, HIGH);
}

int8_t OpticalSensor::read_reg(int8_t reg_addr)
{
    com_begin();

    // send adress of the register, with MSBit = 0 to indicate it's a read
    SPI.transfer(reg_addr & 0x7f);
    delayMicroseconds(100); // tSRAD
    // read data
    int8_t data = SPI.transfer(0);

    delayMicroseconds(1); // tSCLK-NCS for read operation is 120ns
    com_end();
    delayMicroseconds(19); //  tSRW/tSRR (=20us) minus tSCLK-NCS

    return data;
}

void OpticalSensor::write_reg(int8_t reg_addr, int8_t data)
{
    com_begin();

    //send adress of the register, with MSBit = 1 to indicate it's a write
    SPI.transfer(reg_addr | 0x80);
    //sent data
    SPI.transfer(data);

    delayMicroseconds(20); // tSCLK-NCS for write operation
    com_end();
    delayMicroseconds(100); // tSWW/tSWR (=120us) minus tSCLK-NCS. Could be shortened, but is looks like a safe lower bound
}

void OpticalSensor::get_xydat(int32_t xydat[3])
{
    if (initComplete)
    {
        //write 0x01 to Motion register and read from it to freeze the motion values and make them available
        write_reg(Motion, 0x01);
        read_reg(Motion);

        xydat[0] = conv_twos_comp((int32_t)read_reg(Delta_X_L));
        xydat[1] = conv_twos_comp((int32_t)read_reg(Delta_Y_L));
        xydat[2] = conv_twos_comp((int32_t)read_reg(SQUAL));
    }
}

void OpticalSensor::upload_firmware()
{
    //Write 0 to Rest_En bit of Config2 register to disable Rest mode.
    write_reg(Config2, 0x20);

    // write 0x1d in SROM_enable reg for initializing
    write_reg(SROM_Enable, 0x1d);

    // wait for more than one frame period
    delay(10); // assume that the frame rate is as low as 100fps... even if it should never be that low

    // write 0x18 to SROM_enable to start SROM download
    write_reg(SROM_Enable, 0x18);

    // write the SROM file (=firmware data)
    com_begin();
    SPI.transfer(SROM_Load_Burst | 0x80); // write burst destination adress
    delayMicroseconds(15);

    // send all int8_ts of the firmware
    unsigned char c;
    for (int32_t i = 0; i < firmware_length; i++)
    {
        c = (unsigned char)pgm_read_byte(firmware_data + i);
        SPI.transfer(c);
        delayMicroseconds(15);
    }

    //Read the SROM_ID register to verify the ID before any other register reads or writes.
    read_reg(SROM_ID);

    //Write 0x00 to Config2 register for wired mouse or 0x20 for wireless mouse design.
    write_reg(Config2, 0x00);

    // set initial CPI resolution
    write_reg(Config1, 0x77);

    // Adjust Lift Cutoff Height to +3 mm
    //write_reg(Lift_Config, 0x03);

    com_end();
}

int32_t OpticalSensor::conv_twos_comp(int32_t b)
{
    //Convert from 2's complement
    if (b & 0x80)
    {
        b = -1 * ((b ^ 0xff) + 1);
    }
    return b;
}

void OpticalSensor::spi_setup()
{
    // Serial for monitor over USB, speed doesn't matter
    Serial.begin(9600);

    // Configure SPI slave select
    pinMode(ncs, OUTPUT);

    // Configure HW interupts
    pinMode(Motion_Interrupt_Pin, INPUT);
    digitalWrite(Motion_Interrupt_Pin, HIGH);
    // Disabled due to polling
    //attachInterrupt(digitalPinToInterrupt(9), get_xydat, FALLING);

    SPI.begin();
    SPI.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE3));
}

void OpticalSensor::sensor_startup()
{
    // Ensure serial port is reset
    com_end();
    com_begin();
    com_end();

    // Force reset
    write_reg(Power_Up_Reset, 0x5a);
    delay(50);

    // Clear Key Registers
    read_reg(Motion);
    read_reg(Delta_X_L);
    read_reg(Delta_X_H);
    read_reg(Delta_Y_L);
    read_reg(Delta_Y_H);

    // Upload SROM incase it's been cleared from frame capture
    upload_firmware();
    delay(10);
}