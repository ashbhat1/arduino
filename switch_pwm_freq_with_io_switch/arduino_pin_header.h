#include<stdio.h>
#include<stdlib.h>


//setting up TCCR1A control register
unsigned char COM1A1_val   = 0b10000000;
unsigned char COM1A0_val   = 0b01000000;
unsigned char COM1B1_val   = 0b00100000;
unsigned char COM1B0_val   = 0b00010000;
unsigned char COM1C1_val   = 0b00001000;
unsigned char COM1C0_val   = 0b00000100;
unsigned char WGM11_val    = 0b00000010;
unsigned char WGM10_val    = 0b00000001;

//setting up TCCR1B control register
unsigned char ICNC1_val    = 0b10000000;
unsigned char ICES1_val    = 0b01000000;
unsigned char WGM13_val    = 0b00010000;
unsigned char WGM12_val    = 0b00001000;
unsigned char CS12_val     = 0b00000100;
unsigned char CS11_val     = 0b00000010;
unsigned char CS10_val     = 0b00000001;

//Register variables

unsigned char OCR1AL_reg   = 0x88; //output compare low 8 bits for Counter 1
unsigned char OCR1AH_reg   = 0x89; //output compare high 8 bits for Counter 1

unsigned char TCCR1B_reg   = 0x81; //Timer/Counter0 Control Register B  
unsigned char TCCR1A_reg   = 0x80; //Timer/Counter0 Control Register A  

unsigned char TIMSK1_reg   = 0x6F; //Timer/Counter0 Interrupt Mask Register

unsigned char TIFR1_reg    = 0x36; //Timer/Counter0 Interrupt Flag Register

unsigned char TCNT1H_reg   = 0x85; //Timer/Counter0 Interrupt Flag Register
unsigned char TCNT1L_reg   = 0x84; //Timer/Counter0 Interrupt Flag Register

//setting up PBn
unsigned char DDRB_reg     = 0x24; //Sets up the DDR for B
unsigned char PORTB_reg    = 0x25; //sets up port B
unsigned char PINB_reg     = 0x23; //to be able to read PINB


//setting up the global interrupt register
unsigned char SREG_reg     = 0x5F; //Status register used for disabling and enabling global interrupts

unsigned char Bit_0        = 0b00000001;
unsigned char Bit_1        = 0b00000010;
unsigned char Bit_2        = 0b00000100;
unsigned char Bit_3        = 0b00001000;
unsigned char Bit_4        = 0b00010000;
unsigned char Bit_5        = 0b00100000;
unsigned char Bit_6        = 0b01000000;
unsigned char Bit_7        = 0b10000000;
