#include<stdio.h>
#include<stdlib.h>


//Register variables

#define OCR1AL_reg (*(volatile unsigned char *)(0x88)) //output compare low 8 bits for Counter 1
#define OCR1AH_reg (*(volatile unsigned char *)(0x89)) //output compare high 8 bits for Counter 1

#define TCCR1B_reg (*(volatile unsigned char *)(0x81)) //Timer/Counter0 Control Register B  
#define TCCR1A_reg (*(volatile unsigned char *)(0x80)) //Timer/Counter0 Control Register A  

#define TIMSK1_reg (*(volatile unsigned char *)(0x6F)) //Timer/Counter0 Interrupt Mask Register

#define TIFR1_reg  (*(volatile unsigned char *)(0x36)) //Timer/Counter0 Interrupt Flag Register

#define TCNT1H_reg (*(volatile unsigned char *)(0x85)) //Timer/Counter0 Interrupt Flag Register
#define TCNT1L_reg (*(volatile unsigned char *)(0x84)) //Timer/Counter0 Interrupt Flag Register

//setting up PBn
#define DDRB_reg   (*(volatile unsigned char *)(0x24)) //Sets up the DDR for B
#define PORTB_reg  (*(volatile unsigned char *)(0x25)) //sets up port B
#define PINB_reg   (*(volatile unsigned char *)(0x23)) //to be able to read PINB
#define PCICR_reg  (*(volatile unsigned char *)(0x68))

//setting up the global interrupt register
#define SREG_reg   (*(volatile unsigned char *)(0x5F)) //Status register used for disabling and enabling global interrupts

#define FCLK_atmega32u4 8000000 //clock speed


//setting up TCCR1A control register
int COM1A1_val   = 7;//0b10000000;
int COM1A0_val   = 6;//0b01000000;
int COM1B1_val   = 5;//0b00100000;
int COM1B0_val   = 4;//0b00010000;
int COM1C1_val   = 3;//0b00001000;
int COM1C0_val   = 2;//0b00000100;
int WGM11_val    = 1;//0b00000010;
int WGM10_val    = 0;//0b00000001;

//setting up TCCR1B control register
int ICNC1_val    = 7;//0b10000000;
int ICES1_val    = 6;//0b01000000;
int WGM13_val    = 4;//0b00010000;
int WGM12_val    = 3;//0b00001000;
int CS12_val     = 2;//0b00000100;
int CS11_val     = 1;//0b00000010;
int CS10_val     = 0;//0b00000001;


int Bit_0        = 0;
int Bit_1        = 1;
int Bit_2        = 2;
int Bit_3        = 3;
int Bit_4        = 4;
int Bit_5        = 5;
int Bit_6        = 6;
int Bit_7        = 7;

//setting up TIMSK1 register
int OCIE1A_val        = 1;
int ICIE1_val         = 5;

//unsigned char prescale_8   = CS11_val;
//unsigned char prescale_64  = CS10_val|CS11_val;
//unsigned char prescale_256 = CS12_val;
//unsigned char prescale_1024= CS12_val|CS10_val;

