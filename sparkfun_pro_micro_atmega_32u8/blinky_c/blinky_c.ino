/* Pro Micro Test Code
   by: Nathan Seidle
   modified by: Jim Lindblom
   SparkFun Electronics
   date: September 16, 2013
   license: Public Domain - please use this code however you'd like.
   It's provided as a learning tool.

   This code is provided to show how to control the SparkFun
   ProMicro's TX and RX LEDs within a sketch. It also serves
   to explain the difference between Serial.print() and
   Serial1.print().
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//int RXLED = 17;  // The RX LED has a defined Arduino pin
// The TX LED was not so lucky, we'll need to use pre-defined
// macros (TXLED1, TXLED0) to control that.
// (We could use the same macros for the RX LED too -- RXLED1,
//  and RXLED0.)

void setup()
{
 //pinMode(RXLED, OUTPUT);  // Set RX LED as an output
 //setting up PBO
 (*(volatile unsigned char *)(0x24)) = 0x1; //setting the 0th bit in DDRB to 1 so that it can set up for output
 (*(volatile unsigned char *)(0x25)) = 0x0; //setting the 0th bit in PortB to 0 so that it can set output low

 //setting up PD5
 (*(volatile unsigned char *)(0x2A)) = 0x20; //setting the 5th bit in DDRB to 1 so that it can set up for output
 (*(volatile unsigned char *)(0x2B)) = 0x0; //setting the 5th bit in PortB to  so that it can set output low

 

 // TX LED is set as an output behind the scenes

 Serial.begin(9600); //This pipes to the serial monitor
 Serial1.begin(9600); //This is the UART, pipes to sensors attached to board
}

void loop()
{
 //Serial.println("Hello world");  // Print "Hello World" to the Serial Monitor
 Serial1.println("Hello!");  // Print "Hello!" over hardware UART

 
 //digitalWrite(RXLED, LOW);   // set the LED on
 (*(volatile unsigned char *)(0x25)) = 0x0;
 //Serial.println((*(volatile unsigned char *)(0x23)));
 
 (*(volatile unsigned char *)(0x2B)) = 0x20; //setting the 5th bit in PortB to  so that it can set output high
 //TXLED0; //TX LED is not tied to a normally controlled pin

 delay(1000);              // wait for a second
//
 //digitalWrite(RXLED, HIGH);    // set the LED off
 (*(volatile unsigned char *)(0x2B)) = 0x0; //setting the 5th bit in PortB to  so that it can set output low
 
 //TXLED1;
 (*(volatile unsigned char *)(0x25)) = 0x1;
 //Serial.println((*(volatile unsigned char *)(0x23)));

 
 delay(1000);              // wait for a second

 
}
