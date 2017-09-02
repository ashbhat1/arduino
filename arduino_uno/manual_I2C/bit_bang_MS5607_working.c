#include<stdlib.h>
#include<stdio.h>
#include<avr/interrupt.h>
#include<avr/io.h> 
#include<util/delay.h>

#define FOSC 16000000 
#define BAUD 9600
#define MYUBRR  FOSC/16/BAUD-1 
//#define MYUBRR 103
#define SCL PORTD7
#define SDA PORTD6

void USART_init(unsigned int ubrr);
void USART_transmit(char data);
unsigned char USART_recieve(void);
unsigned int getAck();
void sendStart();
void sendStop();
void checkAck(unsigned int ack);
void sendData(unsigned char data);
void sendStr(char data[8]);
void morepininfo();

int main(){
 //char data={"0000000"};//"Hello!";
 /*  String addrstr  = "11101100";
  String addrstr1 = "11000010";
  String addrstr2 = "00000010";
 */


 char* addrstr  = "11101100";
 char* addrstr1 = "11000010";
 char* addrstr2 = "10101010";
 unsigned int ack;
 USART_init(MYUBRR);
 _delay_ms(10000);
 DDRD = 0;
 PORTD = 0;
 //DDRD  = (0<<DDD6)|(1<<DDD7)|(1<<DDD4);
 DDRD = (1<<DDD6)|(1<<DDD7)|(1<<DDD4);
 //PORTD = (0<<SDA)|(1<<SCL)|(1<<PORTD4);
 PORTD = (1<<SDA)|(1<<SCL)|(1<<PORTD4);
 //first address
 sendStop();
 sendStart();
 sendStr(addrstr1);
 USART_transmit('D');
 ack = getAck();
 checkAck(ack);
 sendStop();
 //second address
 DDRD = 0;
 PORTD = 0;
 //DDRD  = (0<<DDD6)|(1<<DDD7)|(1<<DDD4);
 DDRD = (1<<DDD6)|(1<<DDD7)|(1<<DDD4);
 //PORTD = (0<<SDA)|(1<<SCL)|(1<<PORTD4);
 PORTD = (1<<SDA)|(1<<SCL)|(1<<PORTD4);
 //morepininfo();
 sendStop();
 sendStart();
 sendStr(addrstr);
 USART_transmit('D');
 ack=getAck();
 checkAck(ack);
 sendStop();
 USART_transmit('E'); 
 USART_transmit('E');
 USART_transmit('E');
 USART_transmit('E');

 while(1){
 _delay_ms(10);
 PORTD |= (1<<PORTD4);
 _delay_ms(10);
 PORTD ^= (1<<PORTD4);
 _delay_ms(10);
 USART_transmit(PIND+65);
 _delay_ms(5000);
 if ((PIND)&(1<<SDA)){
  USART_transmit('i');
  _delay_ms(10);
  PORTD ^= (1<<SCL);
 }
 //USART_transmit(97);
 //data =  USART_recieve();
 //USART_transmit(data);
 //_delay_ms(1000);
}
}

void morepininfo(){
 USART_transmit('p');
 USART_transmit(PORTD);
 USART_transmit(DDRD);
 USART_transmit('p');
}

void checkAck(unsigned int ack){
 if(ack == 0){
  USART_transmit('S');
 }
 else{
  USART_transmit('F');
 }
}

void sendStr(char addr[8]){
 int i = 0;
 for(i=0;i<8;i++){
  sendData(addr[i]);
 }
}

void sendStart(){
 USART_transmit('t');
 USART_transmit(PIND);
 PORTD |= (1<<SCL); //setting scl low
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (0<<SDA)|(1<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (0<<SDA)|(0<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 USART_transmit('t');
}

void sendStop(){
 USART_transmit('u');
 USART_transmit(PIND);
 PORTD = (0<<SCL)|(1<<SDA);
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (0<<SDA)|(0<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (1<<SDA)|(0<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (1<<SDA)|(1<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 USART_transmit('u');
}


void sendData(unsigned char data){
  USART_transmit('d');
  int val = data-'0';
  USART_transmit(val);
  USART_transmit(PIND);
  PORTD = (val<<SDA)|(0<<SCL);
  _delay_ms(10);
  USART_transmit(PIND);
  PORTD = (val<<SDA)|(1<<SCL);
  _delay_ms(10);
  USART_transmit(PIND);
  PORTD = (val<<SDA)|(0<<SCL);
  _delay_ms(10);
  USART_transmit(PIND);
  USART_transmit('d');
}

unsigned int getAck(){
 USART_transmit('a');
 unsigned int ack=1;
 _delay_ms(10);
 USART_transmit(PIND);
 //convert PIND6 to input
 DDRD  = (0<<DDD6)|(1<<DDD7)|(1<<DDD4);
 //PORTD = (1<<SDA)|(1<<SCL)|(1<<PORTD4); 
 PORTD = (1<<SDA)|(1<<SCL);
 USART_transmit(DDRD);
 USART_transmit(PORTD);
 _delay_ms(10);
 PORTD |= (1<<SCL);
 //_delay_ms(10000);
 USART_transmit(PIND);
 _delay_ms(10);
 USART_transmit(PIND);
 if(~(PIND)&(1<<SDA)){
  ack = 0;}
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD |= (1<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 PORTD = (0<<SCL);
 _delay_ms(10);
 USART_transmit(PIND);
 //set pin6 to output
 DDRD = (1<<DDD6)|(1<<DDD7)|(1<<DDD4);
 PORTD = (1<<SDA)|(1<<SCL)|(1<<PORTD4);
 _delay_ms(10);
 USART_transmit(DDRD);
 USART_transmit(PORTD);
 USART_transmit('a');
 return ack;
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
  _delay_ms(10);
}

unsigned char USART_recieve(void){
 /*wait for data to be recieved, this is important because the data register has to get filled up and a flag gets created when a stop bit is set high*/
 while(!(UCSR0A & (1<<RXC0) ))
 ;
 //once the stop bit is set high then read directly from UDRN
 return UDR0;
}
  
