#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


//setting up TCCR1A control register
unsigned char COM1A1_val  = 0b10000000;
unsigned char COM1A0_val  = 0b01000000;
unsigned char COM1B1_val  = 0b00100000;
unsigned char COM1B0_val  = 0b00010000;
unsigned char COM1C1_val  = 0b00001000;
unsigned char COM1C0_val  = 0b00000100;
unsigned char WGM11_val   = 0b00000010;
unsigned char WGM10_val   = 0b00000001;

//setting up TCCR1B control register
unsigned char ICNC1_val  = 0b10000000;
unsigned char ICES1_val  = 0b01000000;
unsigned char WGM13_val  = 0b00010000;
unsigned char WGM12_val  = 0b00001000;
unsigned char CS12_val   = 0b00000100;
unsigned char CS11_val   = 0b00000010;
unsigned char CS10_val   = 0b00000001;




//Register variables

unsigned char OCR1AL_reg   = 0x88; //output compare low 8 bits for Counter 1
unsigned char OCR1AH_reg   = 0x89; //output compare high 8 bits for Counter 1

unsigned char TCCR1B_reg   = 0x81; //Timer/Counter0 Control Register B  
unsigned char TCCR1A_reg   = 0x80; //Timer/Counter0 Control Register A  

unsigned char TIMSK1_reg   = 0x6F; //Timer/Counter0 Interrupt Mask Register

unsigned char TIFR1_reg    = 0x36; //Timer/Counter0 Interrupt Flag Register

unsigned char TCNT1H_reg   = 0x85; //Timer/Counter0 Interrupt Flag Register
unsigned char TCNT1L_reg   = 0x84; //Timer/Counter0 Interrupt Flag Register

//setting up PB5
unsigned char DDRB_reg    = 0x24; //Sets up the DDR for Bank 5
unsigned char PORTB_reg   = 0x25; //sets up port B
unsigned char PINB_reg    = 0x23; //to be able to read PINB5

unsigned char SREG_reg     = 0x5F; //Status register used for disabling and enabling global interrupts

int stopeverything         = 0; 

void setup()
{

 Serial.begin(9600); //This pipes to the serial monitor

  //setting up PB5
 (*(volatile unsigned char *)(DDRB_reg))        = 0b00100000;
 (*(volatile unsigned char *)(PORTB_reg))       = 0b00100000;

  //resetting the Timer/Counter1
 (*(volatile unsigned char*)(TCNT1H_reg))         = 0;
 (*(volatile unsigned char*)(TCNT1L_reg))         = 0;  
 
 //disabling all global interrupts
 (*(volatile unsigned char *)(SREG_reg))         = 0b00000000;

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
 (*(volatile unsigned char *)(OCR1AH_reg))      = 0b00001111; //writing to high first which will write to a temp register first
 (*(volatile unsigned char *)(OCR1AL_reg))      = 0b01000010; //writing to low will write both high and low in the same clock cycle

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
 (*(volatile unsigned char *)(SREG_reg))         = 0b10000000;




}

/*ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
  //(*(volatile unsigned char *)(PORTB_reg)) = (*(volatile unsigned char *)(PORTB_reg)) ^ (1<<5);
  Serial.println("interrupt!");
  stopeverything=1;
}*/



void loop()
{
  //Serial.println(
  //  (*(volatile unsigned char*)TCNT1H_reg << 8) | (*(volatile unsigned char*)TCNT1L_reg),BIN);
  //Serial.println("");
  //if(stopeverything==1){
    //Serial.println("Coming from interrupt!!");
    //delay(2000);
    //stopeverything=0;
  //}
}
