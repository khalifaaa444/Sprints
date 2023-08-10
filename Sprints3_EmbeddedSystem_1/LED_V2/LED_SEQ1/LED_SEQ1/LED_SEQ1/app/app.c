/*
 * led.c
 *
 * Created: 6/5/2023 12:49:12 PM
 *  Author: ebrahem
 */ 


#include "app.h"



EN_LED_NUM_t LED_INDEX = LED_ZERO;	//using to select which led we want to access  

void app_init()
{
	uint8_t LED_ID;        // using in for loop
	EN_STATUS_BUTTON_t	ret_function_button;
	EN_STATUS_LED_t		ret_function_led;
	
	
	ret_function_button = button_init(PORT_A,PIN0);
	
	
	if(ret_function_button == OK_BUTTON)
	{	
		// DO NOTHING	
	}	
	else 
	{
		// DO NOTHING
	}			
		for ( LED_ID=LED_ZERO ; LED_ID<=LED_THREE ; LED_ID++ )
		{
			ret_function_led = led_init(PORT_B,LED_ID);
			
			if(ret_function_led == OK_LED)
			{
				// DO NOTHING
			}
			else 
			{
				// DO NOTHING
			}
		}
}



void app_start()
{
	EN_VOLTAGE_TYPE_t value;		//using to store value of button state (high or low)
	
	
	
	
	EN_STATUS_BUTTON_t	ret_function_button ;
	
	EN_STATUS_LED_t		ret_function_led	;
	
	ret_function_button = buttonState(PORT_A,PIN0,&value);
	
	if(ret_function_button == OK_BUTTON)
	{
		if(value == HIGH)
		{
			ret_function_led = led_toggle(PORT_B,LED_INDEX);
			if(ret_function_led == OK_LED)
			{
				
				
				LED_INDEX++;
				
				while(value==HIGH)
				{
					buttonState(PORT_A,PIN0,&value);
				}
				
			}
			
				
		}
		if(LED_INDEX > LED_THREE)
		{
			LED_INDEX=LED_ZERO;
		}
	}
	else 
	{
		// DO NOTHING
	}
	
}
