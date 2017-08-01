#include "arduino_pin_header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void setOCRnxRegisters(unsigned int OCnumber);
void setPWMFrequency(double PWMFrequency);


int main(){

 DDRB_reg        = Bit_5;
 PORTB_reg       = Bit_5;

  //resetting the Timer/Counter1
 TCNT1H_reg         = 0;
 TCNT1L_reg         = 0;  
 
 //disabling all global interrupts
 SREG_reg         = 0;

 //defining prescalar

 //TCCR1B: ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
 TCCR1B_reg = 0;
 //TCCR1B_reg = CS11_val; WORKING SETTINGS
 TCCR1B_reg = WGM13_val;

 //setting up PWM mode

 //TCCR1A: COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
 TCCR1A_reg      = 0; //this is for waveform generation and CTC setting up mode;
 TCCR1A_reg      = WGM10_val|COM1A0_val;
 //TCCR1A_reg      = COM1A1_val|WGM10_val; //this is for waveform generation and CTC setting up mode; WORKING SETTINGS

 //defining the output compare value which is calculated to be 3906 assuming 8MHz clock speed: OCRNA = (fClk_I/O)/(2*N*fOCRNA) where N is the prescalar fOCRNA is the compare value and fClk_I/O is the clock speed
 //the value calculated for fOCRNA to be 1Hz is ~3096
 //100Hz  = 10011 10001000
 //10kHz  = 110010
 //100kHz = 
 // (*(volatile unsigned char *)(OCR1AH_reg))      = Bit_3|Bit_2|Bit_1|Bit_0;//0b00001111; //writing to high first which will write to a temp register first
 //OCR1AH_reg      = 0;//0b0001100;//0b00001111; //writing to high first which will write to a temp register first
 // (*(volatile unsigned char *)(OCR1AL_reg))      = Bit_6|Bit_1;//0b01000010; //writing to low will write both high and low in the same clock cycle
 //OCR1AL_reg      = 0b11001110;//0b01000010; //writing to low will write both high and low in the same clock cycle DEFAULT WORKING SETTINGS
 //OCR1AL_reg = 0b00000101;

 setPWMFrequency(100000); 

 TIMSK1_reg      = 0;//0b00100010; //writing so that output compare A is set up



 //enable global interrupts
 SREG_reg         = Bit_7;

 return 0;

}

void setPWMFrequency(double PWMFrequency){
 //focn = fclk/(2*N*TOP) where N is the prescalar
 //TOP = fclk/(2*N*focn)
 printf("Frequency of interest is %.2f\n",PWMFrequency);
 //defining a bunch of prescalars
 int prescalar[5] = {1,8,64,256,1024};
 unsigned char prescalers[5]= {CS10_val,CS11_val,CS10_val|CS11_val,CS12_val,CS12_val|CS10_val};

 int x = 0;
 unsigned int OCnumber=0;
 for(x=0;x<5;x++){
  OCnumber = FCLK_atmega32u4/(2*prescalar[x]*PWMFrequency);
  if(OCnumber <= pow(2,16)-1){
   printf("The OC number is %d\n",OCnumber);
   TCCR1B_reg |= prescalers[x];
   printf("Prescalar chose is %d\n",prescalers[x]);
   
   break;
   }
 }
 setOCRnxRegisters(OCnumber); 
}

void setOCRnxRegisters(unsigned int OCnumber){
 //convert a 16bit number into 2 8 bit numbers
 uint8_t binarylow  = OCnumber & 0xff;
 uint8_t binaryhigh = (OCnumber >> 8);
 OCR1AH_reg = binaryhigh;
 OCR1AL_reg = binarylow;
}

