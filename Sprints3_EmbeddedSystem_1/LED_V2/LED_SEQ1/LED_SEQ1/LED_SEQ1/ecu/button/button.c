/*
 * button.c
 *
 * Created: 6/5/2023 12:35:17 PM
 *  Author: ebrahem
 */ 


#include "button.h"

EN_STATUS_BUTTON_t buttonState(uint8_t port_num , uint8_t pin_num , uint8_t* value)
{	
	EN_STATUS_BUTTON_t ret_function ;
	
	if(value == NULL)
	{
		ret_function = ERROR_BUTTON;
	}
	else 
	{
		ret_function= DIO_read(port_num , pin_num , value);
	}
	
	return ret_function;
}


EN_STATUS_BUTTON_t button_init(uint8_t port_num , uint8_t pin_num)
{
	EN_STATUS_BUTTON_t ret_function = DIO_init(port_num,pin_num,IN);
	
	return ret_function;
}