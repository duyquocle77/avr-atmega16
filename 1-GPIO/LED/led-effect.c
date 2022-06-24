/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : led-effect
Version : 
Date    : 17/05/2022
Author  : LeDuyQuoc
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

#define LED PORTD

void main(void)
{

unsigned char i;

PORTA=0x00;
DDRA=0x00;

PORTB=0x00;
DDRB=0x00;

PORTC=0x00;
DDRC=0x00;

PORTD=0x00;
DDRD=0xFF;

while (1)
      {
      // 8 led nhap nhay lien tuc C1
      LED = ~LED;
      delay_ms(10);
      /*
	  // 8 led nhap nhay lien tuc C2
	  LED = 0x00;
	  delay_ms(100);
	  LED = 0xFF;
	  delay_ms(100);
      
	  // 8 led nhap nhay xen ke nhau
	  LED = 0x55;
	  delay_ms(100);
	  LED = 0xAA;
	  delay_ms(100);

	  // 8 led sang duoi nhau C1
	  LED = 0x01;
	  for(i = 0; i < 8; i++)
	  {
		  LED = LED << 1;
		  delay_ms(100);	
	  }    

	  // 8 led sang dan C1
	  LED = 0x80;
	  for(i = 0; i < 8; i++)
	  {
	        LED = LED >> 1;
		    delay_ms(100);	
	  }

	  // 8 led sang dan C2
	  LED = 0x00;
	  for(i = 0; i < 8; i++)
	  {
		    LED = LED << 1;
		    LED = LED | 1;
		    delay_ms(100);	
	  }   */
}
}