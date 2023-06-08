/*
 * led.c
 *
 * Created: 6/6/2023 10:09:59 AM
 *  Author: ebrahem
 */ 


#include "led.h"



EN_STATUS_LED_t led_init(uint8_t port_num , uint8_t pin_num)
{
	
	EN_STATUS_LED_t ret_function = DIO_init(port_num , pin_num , OUT);
	return ret_function;
}

EN_STATUS_LED_t led_on(uint8_t port_num , uint8_t pin_num)
{
	
	EN_STATUS_LED_t ret_function=DIO_write(port_num , pin_num , HIGH);
	return ret_function;
}

EN_STATUS_LED_t led_off(uint8_t port_num , uint8_t pin_num)
{
	EN_STATUS_LED_t ret_function=DIO_write(port_num , pin_num , LOW);
	return ret_function;
}

EN_STATUS_LED_t led_toggle(uint8_t port_num , uint8_t pin_num)
{
	
	EN_STATUS_LED_t ret_function=DIO_toggle(port_num , pin_num);
	return ret_function;
}
