#include<stdlib.h>
#include<stdio.h>
#include<avr/interrupt.h>
#include<avr/io.h> 
#include<util/delay.h>

#define FOSC 16000000 
#define BAUD 9600
#define MYUBRR  FOSC/16/BAUD-1 
//#define MYUBRR 103
//PORTD2 is the input SDA
//PORTD4 is the output SCL


void USART_init(unsigned int ubrr);
void USART_transmit(char data);
unsigned char USART_recieve(void);
void writeAddress(char* data);
int getack();
void stopbit();
void convertToBinary(int num);

int main(){
 char data;//"Hello!";
 USART_init(MYUBRR);
 _delay_ms(10000);
 DDRD = 0;
 PORTD = 0;
 DDRD  = (0<<DDD2)|(1<<DDD7)|(1<<DDD4);
 PORTD = (0<<PORTD2)|(1<<PORTD7)|(1<<PORTD4);
 _delay_ms(10);
convertToBinary(11);
// writeAddress("00000000");
// int ack = getack();
// USART_transmit((char)(ack));
// _delay_ms(10);
// stopbit();
 while(1){
 /*_delay_ms(10);
 PORTD |= (1<<PORTD4);
 _delay_ms(10);
 PORTD ^= (1<<PORTD4);
 _delay_ms(10);
 USART_transmit(PIND+65);
 _delay_ms(5000);
 if ((PIND)&(1<<PIND2)){
  USART_transmit('i');
  _delay_ms(10);
  PORTD ^= (1<<PORTD7);*/
 }
 //USART_transmit(97);
 //data =  USART_recieve();
 //USART_transmit(data);
 //_delay_ms(1000);
}

void convertToBinary(int num){
 int rem=1;
 char* binstr = "00000000";
 int idx = 0;
 while(num/2!=0){
  rem   = num%2; 
  //USART_transmit(num/2);
  num   = num/2;
  _delay_ms(10);
  USART_transmit(rem);
  _delay_ms(10);
  binstr[idx] = rem;
  idx++;
 }
 rem = num%2;
 //USART_transmit(num/2);
 _delay_ms(10);
 USART_transmit(rem);
 _delay_ms(10);
 binstr[idx]=rem;
}

void writeAddress(char* data){
 char temp = 'a';
 int val = 0;
 USART_transmit(0x01);
 int i = 0;
 //sending start bit
 DDRD  = (1<<DDD2)|(1<<DDD4);
 PORTD = (1<<PORTD2)|(1<<PORTD4);
 _delay_ms(10);
 PORTD = (0<<PORTD2)|(1<<PORTD4); 
 _delay_ms(10);
 //sending data
 for(i=0;i<8;i++){
  temp = *(data++);
  val  = (int)(temp-'0');
  USART_transmit(val);
  _delay_ms(30);
  PORTD = (val<<PORTD2)|(1<<PORTD4);
  _delay_ms(10);
  PORTD = (val<<PORTD2)|(0<<PORTD4);
  _delay_ms(10);
 }
}

int getack(){
 int ack = 0;
 DDRD = (0<<DDD2)|(1<<DDD4);
 PORTD = (0<<PORTD2)|(1<<PORTD4);
 _delay_ms(10);
 USART_transmit(0x02);
 _delay_ms(10);
 USART_transmit(PIND);
 if((PIND)&(1<<PIND2)){
  USART_transmit(0x03);
  _delay_ms(10);
  ack = 1;
 }
 PORTD = (0<<PORTD2)|(0<<PORTD4);
 _delay_ms(10);
 return ack;
}

void stopbit(){
 USART_transmit(0x04);
 _delay_ms(10);
 DDRD = (1<<DDD2)|(1<<PORTD4);
 PORTD = (0<<DDD2)|(1<<PORTD4);
 _delay_ms(10);
 PORTD = (1<<DDD2)|(1<<PORTD4);
 _delay_ms(10);
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
  
