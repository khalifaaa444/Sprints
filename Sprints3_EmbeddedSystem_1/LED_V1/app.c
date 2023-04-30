/*
 * app.c
 *
 * Created: 4/10/2023 1:38:08 PM
 *  Author: ebrahem
 */ 

#include "app.h"

uint8_t i;
uint8_t count=0;

void app_init()
{
	
	button_init(PORT_A,0);
	for(i=0;i<4;i++)
	{
		led_init(PORT_B,i);
	}
	
	
}


void app_start()
{
	uint8_t value;
	buttonState(PORT_A,0,&value);
	
	if(value == 1)
	{
		
		led_toggle(PORT_B,count);
		count++;
		
		_delay_ms(500);
		
	}
	if(count == 4)
	{
		count=0;
	}
}

