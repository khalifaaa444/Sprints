/*
 * led.c
 *
 * Created: 4/10/2023 12:55:56 PM
 *  Author: ebrahem
 */ 


#include "led.h"

void led_init(uint8_t port_num , uint8_t pin_num)
{
	DIO_init(port_num , pin_num , 1);
}

void led_on(uint8_t port_num , uint8_t pin_num)
{
	DIO_write(port_num , pin_num , 1);
}	

void led_off(uint8_t port_num , uint8_t pin_num)
{
	DIO_write(port_num , pin_num , 0);	
}

void led_toggle(uint8_t port_num , uint8_t pin_num)
{
	DIO_toggle(port_num , pin_num);
}


