#include "arduino_pin_header.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

 (*(volatile unsigned char *)(DDRB_reg))        = Bit_5;
 (*(volatile unsigned char *)(PORTB_reg))       = Bit_5;

  //resetting the Timer/Counter1
 (*(volatile unsigned char*)(TCNT1H_reg))         = 0;
 (*(volatile unsigned char*)(TCNT1L_reg))         = 0;  
 
 //disabling all global interrupts
 (*(volatile unsigned char *)(SREG_reg))         = 0;

 //defining prescalar
 //(*(volatile unsigned char *)(TCCR1B_reg))      = ICES1_val|WGM13_val|WGM12_val|CS12_val|CS10_val;//0b01001101; //the last 3 bits set to 101 will make the clock scalar 1024;
 //(*(volatile unsigned char *)(TCCR1B_reg))      = ICES1_val|CS12_val;//0b01001101; //the last 3 bits set to 101 will make the clock scalar 1;
 (*(volatile unsigned char *)(TCCR1B_reg))        = 0;
 (*(volatile unsigned char *)(TCCR1B_reg))        = CS11_val;

 //setting up PWM mode
 (*(volatile unsigned char *)(TCCR1A_reg))      = 0; //this is for waveform generation and CTC setting up mode;
 (*(volatile unsigned char *)(TCCR1A_reg))      = COM1A1_val|WGM10_val; //this is for waveform generation and CTC setting up mode;

 //defining the output compare value which is calculated to be 3906 assuming 8MHz clock speed: OCRNA = (fClk_I/O)/(2*N*fOCRNA) where N is the prescalar fOCRNA is the compare value and fClk_I/O is the clock speed
 //the value calculated for fOCRNA to be 1Hz is ~3096
 (*(volatile unsigned char *)(OCR1AH_reg))      = Bit_3|Bit_2|Bit_1|Bit_0;//0b00001111; //writing to high first which will write to a temp register first
 (*(volatile unsigned char *)(OCR1AL_reg))      = Bit_6|Bit_1;//0b01000010; //writing to low will write both high and low in the same clock cycle

  //using output value of 300
  
 //(*(volatile unsigned char *)(OCR1AH_reg))      = 0b00000001; //writing to high first which will write to a temp register first
 //(*(volatile unsigned char *)(OCR1AL_reg))      = 0b00000100; //writing to low will write both high and low in the same clock cycle

 //using compare value of 30
 
 //(*(volatile unsigned char *)(OCR1AH_reg))      = 0b00000000; //writing to high first which will write to a temp register first
 //(*(volatile unsigned char *)(OCR1AL_reg))      = 0b00000110; //writing to low will write both high and low in the same clock cycle
 
 //using compare value of 1
 
 //(*(volatile unsigned char *)(OCR1AH_reg))      = 0b00000000; //writing to high first which will write to a temp register first
 //(*(volatile unsigned char *)(OCR1AL_reg))      = 0b00000001; //writing to low will write both high and low in the same clock cycle


 (*(volatile unsigned char *)(TIMSK1_reg))      = 0;//0b00100010; //writing so that output compare A is set up



 //enable global interrupts
 (*(volatile unsigned char *)(SREG_reg))         = Bit_7;



}


