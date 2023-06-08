/*
 * app.c
 *
 * Created: 6/6/2023 10:13:03 AM
 *  Author: ebrahem
 */ 


#include "app.h"


uint8_t LED_INDEX = LED_ZERO;	//using to select which led we want to access
uint8_t LED_ID=PIN0;        
st_Timer_req_t Timer_obj1;


void app_init()
{
	
	EN_STATUS_LED_t		ret_function_led;
	EN_STATUS_TIMER_t	ret_function_timer;
	EN_STATUS_BUTTON_t	ret_function_button;
	
	
	Timer_obj1.PrescalerSelect = PRESCALER_8;
	Timer_obj1.TimerID = TIMER_ZERO;
	Timer_obj1.TimerMode = NORMAL_MODE;
	
	
	
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
	sint8_t	LED_FOR_TIMER;
	uint8_t	counter_for_timer;
	sint8_t	num_of_loop_timer;
	EN_VOLTAGE_TYPE_t value;		//using to store value of button state (high or low)
	uint8_t	flag_for_leds=0;
	
	EN_STATUS_TIMER_t	ret_function_timer	;
	EN_STATUS_LED_t		ret_function_led	;
	EN_STATUS_BUTTON_t	ret_function_button ;
	
	
	Timer_obj1.DelayRequired = 50;
	DDRD = Timer_obj1.DelayRequired;
	
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
			flag_for_leds=1;
		}
		else 
		{
			flag_for_leds=0;
		}
		
	}
	else
	{
		// DO NOTHING
	}
	
	
	
	if(LED_INDEX >LED_ZERO)
	{
		LED_FOR_TIMER = LED_INDEX-1;
		num_of_loop_timer=0;
		while((num_of_loop_timer < 20)&&(value == LOW))
		{
			DDRD = Timer_obj1.DelayRequired;
			ret_function_timer	=	Timer_delay(&Timer_obj1);
			ret_function_timer	=	Timer_Stop(&Timer_obj1);
			
			num_of_loop_timer=num_of_loop_timer+1;
			buttonState(PORT_A,PIN0,&value);
			
		}
		
		
		while((LED_FOR_TIMER >= LED_ZERO)&&(value == LOW))
		{
			led_toggle(PORT_B,LED_FOR_TIMER);
			LED_FOR_TIMER--;
			buttonState(PORT_A,PIN0,&value);
		}
		
		
		
		
		
		
	}
	
	
		
}
