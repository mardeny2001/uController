#include <Arduino.h>
// Mario's Ideas
//MAX7219 - using SPI library to display 8x8 bitmap
#include   <SPI.h>
#define CS 7

// MAX7219 Control registers

#define DECODE_MODE   9 
#define INTENSITY 0x0A
#define SCAN_LIMIT 0x0B 
#define SHUTDOWN 0x0C
#define DISPLAY_TEST 0x0F

byte Apple [8]={B00011000,B00001000,B01111110,B11111111,B11111111,B11111111,B01111110,B00111100};

void   SendData(uint8_t address, uint8_t value) {  
  digitalWrite(CS, LOW);   
   
  SPI.transfer(address);      // Send address.
  SPI.transfer(value);        //   Send the value.

  digitalWrite(CS, HIGH); // Finish transfer.
}

void setup()   {
  pinMode(CS, OUTPUT);  
  SPI.setBitOrder(MSBFIRST);   // Most significant   bit first 
  SPI.begin();                 // Start SPI
  SendData(DISPLAY_TEST,   0x01);       // Run test - All LED segments lit.
  delay(1000);
  SendData(DISPLAY_TEST,   0x00);           // Finish test mode.
  SendData(DECODE_MODE, 0x00);            //   Disable BCD mode. 
  SendData(INTENSITY, 0x02);              // Use lowest intensity.   
  SendData(SCAN_LIMIT, 0x0f);             // Scan all digits.
  SendData(SHUTDOWN,   0x01);               // Turn on chip.
}

void loop()  {

for (int i=1;i<9;i++)   SendData(i, Apple[i-1]);

}