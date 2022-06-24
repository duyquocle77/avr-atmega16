/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 22/05/2022
Author  : NeVaDa
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


#include <delay.h>

#define ADC_VREF_TYPE 0x40
#define LED  PORTD.0
#define LED7 PORTC
#define EN1  PORTB.0
#define EN2  PORTB.1
#define EN3  PORTB.2
#define EN4  PORTB.3

// Read the AD conversion result
unsigned int read_adc(unsigned char adc_input)
{
ADMUX=adc_input | (ADC_VREF_TYPE & 0xff);
// Delay needed for the stabilization of the ADC input voltage
delay_us(10);
// Start the AD conversion
ADCSRA|=0x40;
// Wait for the AD conversion to complete
while ((ADCSRA & 0x10)==1);
ADCSRA|=0x10;
return ADCW;
}

// Declare your global variables here

const unsigned char num[17] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0xBF};

void hienthiled7(unsigned int x)
{
unsigned int temp, a, b, c, d;
temp = x;
d = temp % 10;
temp = temp / 10;
c = temp % 10;
temp = temp / 10;
b = temp % 10;
a = temp / 10;

EN1 = 0;
LED7 = num[a];
delay_ms(1);
EN1 = 1; 
        
EN2 = 0;
LED7 = num[b];
delay_ms(1);
EN2 = 1;  

EN3 = 0;
LED7 = num[c];
delay_ms(1);
EN3 = 1; 
        
EN4 = 0;
LED7 = num[d];
delay_ms(1);
EN4 = 1;   
}

void main(void)
{

DDRB = 0xFF;
PORTB = 0xFF;

DDRC = 0xFF;
PORTC = 0xFF;

DDRD = 0x01;
PORTD = 0x00;

// ADC initialization
// ADC Clock frequency: 1000.000 kHz
// ADC Voltage Reference: AVCC pin
// ADC Auto Trigger Source: Free Running
ADMUX=ADC_VREF_TYPE & 0xff;
ADCSRA=0xA3;
SFIOR&=0x1F;

while (1)
      {
      hienthiled7(read_adc(0)); 
      while ((ADCSRA & 0x10)==1)
      {
      hienthiled7(read_adc(0));
      LED = 1;
      }       
      LED = 0;
      }
}
