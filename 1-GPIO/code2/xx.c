#include <mega16.h>
#include <delay.h>

void T0delay();

void main(void)
{
	DDRB = 0xFF;		/* PORTB as output*/
	
    	while(1)  		/* Repeat forever*/
    	{
		PORTB=0xff;
		T0delay();  	/* Give some delay */  
        
		PORTB=0x00;
		T0delay();
        //delay_ms(60000);
    	}
}

void T0delay()
{
	TCCR0 = (1<<CS02) | (1<<CS00); /* Timer0, normal mode, /1024 prescalar */
	TCNT0 = 0xF8;  		/* Load TCNT0, count for 10ms */
	while((TIFR&0x01)==0);  /* Wait for TOV0 to roll over */
	TCCR0 = 0;
	TIFR = 0x1;  		/* Clear TOV0 flag */
}