/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : button
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

#define LED PORTB.0
#define BUTTON PINA.0

void main(void)
{
 
PORTA=0x00;
DDRA=0x00;

PORTB=0x00;
DDRB|=(1<<LED);
 
PORTC=0x00;
DDRC=0x00;

PORTD=0x00;
DDRD=0x00;

while (1)
      { 
      if(!BUTTON)
      {          
      //delay_ms(50);
      if(!BUTTON)
      {
        LED = ~LED;
        while(!BUTTON); 
        //LED = 0;
      }
      }
      }
}
