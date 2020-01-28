#ifndef CONTROL_RF69_h
#define CONTROL_RF69_h
#include <stdint.h>
#include <stdbool.h>


#define HIGH 1
#define LOW  0



void noInterrupts(void);                // function to disable interrupts
void interrupts(void);                  // function to enable interrupts
void RFM69_SetCSPin(bool);          // function to control the GPIO tied to RFM69 chip select (parameter HIGH or LOW)
bool RFM69_ReadDIO0Pin(void);       // function to read GPIO connected to RFM69 DIO0 (RFM69 interrupt signalling)
uint8_t SPI_transfer8(uint8_t);     // function to transfer 1byte on SPI with readback
void Serialprint(char*);            // function to print to serial port a string
bool Timeout_IsTimeout1(void);      // function for timeout handling, checks if previously set timeout expired
void Timeout_SetTimeout1(uint16_t); // function for timeout handling, sets a timeout, parameter is in milliseconds (ms)

#endif

