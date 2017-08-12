#include<stdio.h>
#include<stdlib.h>


//USART REGISTERS
#define UCSR0C ((*volatile unsigned char*)(0xC2))
#define UCSR0B ((*volatile unsigned char*)(0xC1))
#define UCSR0A ((*volatile unsigned char*)(0xC0))
#define UBRR0H ((*volatile unsigned char*)(0xC5))
#define UBRR0L ((*volatile unsigned char*)(0xC4))

//Register variables

#define OCR1AL (*(volatile unsigned char *)(0x88)) //output compare low 8 bits for Counter 1
#define OCR1AH (*(volatile unsigned char *)(0x89)) //output compare high 8 bits for Counter 1

#define TCCR1B (*(volatile unsigned char *)(0x81)) //Timer/Counter0 Control Register B  
#define TCCR1A (*(volatile unsigned char *)(0x80)) //Timer/Counter0 Control Register A  

#define TIMSK1 (*(volatile unsigned char *)(0x6F)) //Timer/Counter0 Interrupt Mask Register

#define TIFR1  (*(volatile unsigned char *)(0x36)) //Timer/Counter0 Interrupt Flag Register

#define TCNT1H (*(volatile unsigned char *)(0x85)) //Timer/Counter0 Interrupt Flag Register
#define TCNT1L (*(volatile unsigned char *)(0x84)) //Timer/Counter0 Interrupt Flag Register

//setting up PBn
#define DDRB   (*(volatile unsigned char *)(0x24)) //Sets up the DDR for B
#define PORTB  (*(volatile unsigned char *)(0x25)) //sets up port B
#define PINB   (*(volatile unsigned char *)(0x23)) //to be able to read PINB
#define PCICR  (*(volatile unsigned char *)(0x68))

//setting up the global interrupt register
#define SREG   (*(volatile unsigned char *)(0x5F)) //Status register used for disabling and enabling global interrupts

#define FCLK_atmega32u4 8000000 //clock speed

//USART register value
int UMSEL01  = 7;
int UMSEL00  = 6;
int UPMN11   = 5;
int UPMN10   = 4;
int USBS1    = 3;
int UCSZ11   = 2;
int UCSZ10   = 1;
int UCPOL1   = 0;


//setting up TCCR1A control register
int COM1A1   = 7;//0b10000000;
int COM1A0   = 6;//0b01000000;
int COM1B1   = 5;//0b00100000;
int COM1B0   = 4;//0b00010000;
int COM1C1   = 3;//0b00001000;
int COM1C0   = 2;//0b00000100;
int WGM11    = 1;//0b00000010;
int WGM10    = 0;//0b00000001;

//setting up TCCR1B control register
int ICNC1    = 7;//0b10000000;
int ICES1    = 6;//0b01000000;
int WGM13    = 4;//0b00010000;
int WGM12    = 3;//0b00001000;
int CS12     = 2;//0b00000100;
int CS11     = 1;//0b00000010;
int CS10     = 0;//0b00000001;


int Bit_0        = 0;
int Bit_1        = 1;
int Bit_2        = 2;
int Bit_3        = 3;
int Bit_4        = 4;
int Bit_5        = 5;
int Bit_6        = 6;
int Bit_7        = 7;

//setting up TIMSK1 register
int OCIE1A        = 1;
int ICIE1         = 5;

//unsigned char prescale_8   = CS11;
//unsigned char prescale_64  = CS10|CS11;
//unsigned char prescale_256 = CS12;
//unsigned char prescale_1024= CS12|CS10;

