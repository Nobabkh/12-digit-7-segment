/*
 * proteus.c
 *
 * Created: 4/21/2021 11:08:26 AM
 * Author : nirob
 */ 
#define OFF PORTB = 0X00
#include <avr/io.h>
//#include <avr/delay.h>
#include <util/delay.h>
//#include "7segment.h"

#ifndef F_CPU // if F_CPU was not defined in Project -> Properties
#define F_CPU 16000000UL // define it now as 16 MHz unsigned long
#endif


void prints(int i)
{
	int zero = 0X7E >> 1;
	if(i == 0){
		//GOFF;
		OFF;
		PORTB= zero;
	}
	else if(i == 1){
		OFF;
		PORTB = 0X30;
	}
	else if(i == 2){
		OFF;
		PORTB = 0X5B;
		//GON;
	}
	else if(i ==3){
		OFF;
		PORTB = 0X4F;
		//GON;
	}
	else if(i == 4){
		OFF;
		PORTB = 0X66;
		//GON;
	}
	else if(i == 5){
		OFF;
		PORTB = 0X6D;
		//GON;
	}
	else if(i == 6){
		OFF;
		PORTB = 0X7D;
		//GON;
	}
	else if(i == 7){
		//GOFF;
		OFF;
		PORTB = 0X07;
	}
	else if(i == 8){
		OFF;
		PORTB = 0xFF;
		//GON;
	}
	else if(i == 9){
		OFF;
		PORTB = 0X6F;
	}
	else {
		PORTB = 0X00;
		//continue;
	}
}


int main(void)
{
	int s0 = 0, s1 = 0, i = 0, m1 = 0, m0 = 0, h1 = 0, h0 = 0;
	DDRB |= (0XFF << PORTB);
	DDRC |= (0XFF << PORTC);
    while (1) 
    {
		if(1 > 99)
		{
			i= 0;
			s0++;
			if(s0 > 9)
			{
				s0 = 0;
				s1++;
				if(s1 > 5)
				{
					s1 = 0;
					m0++;
					if(m0 > 9)
					{
						m0 = 0;
						m1++;
						if(m1 > 5)
						{
							m1 = 0;
							h0++;
							if(h0 > 9)
							{
								h0 = 0;
								h1++;
								if(h1 > 12)
								{
									h1 = 0;
								}
							}
						}
					}
				}
			}
		}
		
		PORTC = 0X00;
		prints(h1);
		_delay_ms(5);
		prints(11);
		PORTC = 0X01;
		prints(h0);
		_delay_ms(5);
		prints(11);
		PORTC = 0X02;
		prints(m1);
		_delay_ms(5);
		prints(11);
		PORTC = 0X03;
		prints(m0);
		_delay_ms(5);
		prints(11);
		PORTC = 0X04;
		prints(s1);
		_delay_ms(5);
		prints(11);
		PORTC = 0X05;
		prints(s0);
		_delay_ms(5);
		prints(11);
		
		

		
		_delay_ms(1);
		i++;
    }
	return 0;
}

