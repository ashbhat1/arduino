#include<stdlib.h>
#include<stdio.h>
#include<avr/interrupt.h>
#include<avr/io.h> 
#include<util/delay.h>

#define FOSC 16000000 
#define BAUD 9600
#define MYUBRR  FOSC/16/BAUD-1 
//#define MYUBRR 103
#define SDA PORTC3
#define SCL PORTC2

void USART_init(unsigned int ubrr);
void USART_transmit(char data);
unsigned char USART_recieve(void);
void setup_PC2_PC3();
void connect_to_device();
void checkDevID();
void test_toggle_ports();

int main(){
 char data;//"Hello!";
 USART_init(MYUBRR);
 _delay_ms(15000);
 setup_PC2_PC3();
 USART_transmit('s');
 connect_to_device();
 USART_transmit('\n');
 checkDevID();
 USART_transmit('f');
 while(1){
 test_toggle_ports();
}
}

void test_toggle_ports(){
 DDRC = (1<<DDC3);
 PORTC = (1<<SDA)|(1<<SCL);//(1<<PORTC3)|(1<<PORTC2);
 //USART_transmit(PINC+65);
 _delay_ms(100);
 USART_transmit(PINC+65);
 DDRC = (0<<DDC3);
 PORTC = (0<<SDA);
 _delay_ms(100);
 USART_transmit(PINC+65);
 PORTC = (0<<SDA)|(0<<SCL);
 //USART_transmit(PORTC+65);
 _delay_ms(100);
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
  
void setup_PC2_PC3(){
 DDRC  = (1<<DDC3)|(1<<DDC2);
 PORTC = (0<<PORTC3)|(0<<PORTC2);
}

void start_bit(){
 PORTC = (1<<SDA);
 _delay_ms(10);
 PORTC = (1<<SCL);
 _delay_ms(10);
 PORTC = (0<<SDA);
 //PORTC = (0<<SDA)|(1<<SCL);
}

void senddata(unsigned char* data){
 unsigned char temp = 'a';
 unsigned int val = 0;
 while(temp){
  PORTC = (0<<SCL);
  _delay_ms(100);
  temp = *(data++);
  if (temp=='1'){
   USART_transmit('1');
   PORTC = (1<<SDA);
  }
  else{
   PORTC = (0<<SDA);
   USART_transmit('0');
  }
   
  PORTC = (1<<SCL);
  _delay_ms(10);
 }

}

void read_write_bit(unsigned int rw,char usart_char){
 USART_transmit('r');
 PORTC = (rw<<SDA);
 _delay_ms(100);
 USART_transmit(PINC+65);
 PORTC = (1<<SCL);
 _delay_ms(100);
 PORTC = (0<<SCL);
}

void ack_bit(char usart_char){
 USART_transmit(usart_char);
 //turning the port to in put
 DDRC = (0<<DDC3);
 PORTC = (0<<SCL);
 _delay_ms(100);
 USART_transmit(PINC+65); //adding by 65 incase I get 0 or 1 which will look weird in serial output
 _delay_ms(10);
 PORTC = (1<<SCL);
 _delay_ms(100);
 USART_transmit(PINC+65);
 PORTC = (0<<SCL);
 _delay_ms(100);
 USART_transmit(PINC+65);

}

void checkDevID(){
 senddata("00000000");
 ack_bit('a');
}

void connect_to_device(){
 char temp = 'a';
 unsigned char* data = "1010011";//this is binary for 0x53
 PORTC = (0<<SCL);
 senddata(data);
 //sending out read
 read_write_bit(0,'r');
 //getting ack
 ack_bit('a');
}
