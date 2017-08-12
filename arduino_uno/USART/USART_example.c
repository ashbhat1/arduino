#include<stdlib.h>
#include<stdio.h>
#include<avr/interrupt.h>
#include<avr/io.h> 
#include<util/delay.h>

#define FOSC 16000000 
#define BAUD 9600
#define MYUBRR  FOSC/16/BAUD-1 
//#define MYUBRR 103

void USART_init(unsigned int ubrr);
void USART_transmit(char data);
unsigned char USART_recieve(void);

int main(){
 char data;//"Hello!";
 USART_init(MYUBRR);
 while(1){
 //USART_transmit(97);
 data =  USART_recieve();
 USART_transmit(data);
 //_delay_ms(1000);
}
}

void USART_init(unsigned int ubrr){
 UCSR0B = (1<<TXEN0)|(1<<RXEN0);

 //choose asynchronous mode
 UCSR0C = 0;
 UCSR0C = (0<<UMSEL01)|(0<<UMSEL00);
 UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
 UCSR0C |= (1<<USBS0);
 /*//setting UBRR TO 103 for 9600 baudrate
 UBRR0H = 0;
 UBRR0L = 0b01100111; */
 UBRR0H = (unsigned char)(ubrr>>8);
 UBRR0L = (unsigned char)ubrr;
}

void USART_transmit(char data){
 char temp='a';//initialize to a certain character
 //while(temp){
  //temp = *(data++);//go through each character one by one until all the data has been put out
  while( !(UCSR0A & (1<<UDRE0)) ) //
  ;
  //UDR0 = temp;
  UDR0 = data;
  //}
}

unsigned char USART_recieve(void){
 /*wait for data to be recieved, this is important because the data register has to get filled up and a flag gets created when a stop bit is set high*/
 while(!(UCSR0A & (1<<RXC0) ))
 ;
 //once the stop bit is set high then read directly from UDRN
 return UDR0;
}
  
