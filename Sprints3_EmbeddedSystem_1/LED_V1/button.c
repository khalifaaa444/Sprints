/*
 * button.c
 *
 * Created: 4/10/2023 1:15:15 PM
 *  Author: ebrahem
 */ 

#include "button.h"

void buttonState(uint8_t port_num , uint8_t pin_num , uint8_t* value)
{
	DIO_read(port_num , pin_num , value);
	
}


void button_init(uint8_t port_num , uint8_t pin_num)
{
	DIO_init(port_num,pin_num,0);
}
