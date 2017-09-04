#include<stdio.h>
#include<stdlib.h>
#include<avr/interrupt.h>
#include<avr/io.h>


int main(){


 DDRB        = 0;
 PORTB       = 0;
 DDRB        = (1<<5);
 PORTB       = (0<<5);

  //resetting the Timer/Counter1
 TCNT1H         = 0;
 TCNT1L         = 0;  
 
 //disabling all global interrupts
 SREG         = 0;

 //defining prescalar

 //TCCR1B: ICNC1 ICES1 – WGM13 WGM12 CS12 CS11 CS10
 TCCR1B = 0;
 //TCCR1B_reg = CS11_val; WORKING SETTINGS
 TCCR1B = 0b00000101;//(1<<CS10_val)|(1<<CS12_val);

 //setting up PWM mode

 //TCCR1A: COM1A1 COM1A0 COM1B1 COM1B0 COM1C1 COM1C0 WGM11 WGM10
 TCCR1A      = 0; //this is for waveform generation and CTC setting up mode;
 //TCCR1A      = 0b10000000;//(1<<COM1A1_val);
 TCCR1A      = COM1A1;


 OCR1AH      = 0b10011100;//0b00000000;
 OCR1AL      = 0b01000000;//0b01000000;
 
 TIMSK1      = 0b00100010;//(1<<ICIE1_val)|(1<<OCIE1A_val);//0b00100010; //writing so that output compare A is set up



 //enable global interrupts
 SREG         = (1<<7);
 while(1){}

 return 0;

}

ISR(TIMER1_COMPA_vect){
  PORTB = PORTB^(1<<5);
}


