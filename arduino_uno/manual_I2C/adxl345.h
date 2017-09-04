#include<stdio.h>

#define POWER_CTL (*(volatile unsigned char)0x2D)
#define MEASUREBIT 3 //this bit needs to be set to 0 to go to standby mode and to 1 for measurement mode
#define ADXLADDR 0x53
#define ADXLWRITE 0xA6
#define ADXLREAD  0xA7

