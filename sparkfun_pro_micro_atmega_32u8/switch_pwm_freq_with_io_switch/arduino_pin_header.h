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

#define USBINT_reg (*(volatile unsigned char *)(0xDA))
#define USBSTA_reg (*(volatile unsigned char *)(0xD9))
#define USBCON_reg (*(volatile unsigned char *)(0xD8))
#define UHWCON_reg (*(volatile unsigned char *)(0xD7))
#define PLLCSR_reg (*(volatile unsigned char *)(0x49))
#define UDINT_reg (*(volatile unsigned char *)(0xE1))
#define UDIEN_reg (*(volatile unsigned char *)(0xE2))



//setting up USB registers
int USBE_val     = 7;
int FRZCLK_val   = 5;
int UVREGE_val   = 0;
int PINDIV_val   = 4;
int OTGPADE_val  = 4;
int WAKEUPI_val  = 4;
int SUSPI_val    = 0;
int EORSTE_val   = 3;
int SOFE_val     = 2;
int SUSPE_val    = 0;
int PCIE0_val    = 0;


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


unsigned char Bit_0        = 0b00000001;
unsigned char Bit_1        = 0b00000010;
unsigned char Bit_2        = 0b00000100;
unsigned char Bit_3        = 0b00001000;
unsigned char Bit_4        = 0b00010000;
unsigned char Bit_5        = 0b00100000;
unsigned char Bit_6        = 0b01000000;
unsigned char Bit_7        = 0b10000000;

//unsigned char prescale_8   = CS11_val;
//unsigned char prescale_64  = CS10_val|CS11_val;
//unsigned char prescale_256 = CS12_val;
//unsigned char prescale_1024= CS12_val|CS10_val;

