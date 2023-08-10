/*
 * led.c
 *
 * Created: 6/5/2023 12:49:12 PM
 *  Author: ebrahem
 */ 


#include "app.h"



EN_LED_NUM_t LED_INDEX = LED_ZERO;	//using to select which led we want to access  


static void Button_Press(void);

uint8_t flag_button=0;


void app_init()
{
		uint8_t LED_ID;        // using in for loop
		EN_STATUS_LED_t		ret_function_led;
		INT_Num My_INT;

		My_INT.No_Of_INT=INT_0;
		My_INT.Type_INT=RISING;

		for ( LED_ID=LED_ZERO ; LED_ID<=LED_THREE ; LED_ID++ )
		{
			ret_function_led = led_init(PORT_B,LED_ID);
		}
		sei();
		choose_interrupt(&My_INT);
		button_init(PORT_D,PIN2);
		EX_INT_SET_CALLBACK (INT_0,Button_Press);
}



void app_start()
{
	EN_STATUS_LED_t		ret_function_led;
	
	if(flag_button == 1)
	{
		led_on(PORT_B, LED_ZERO);
	}
	else if(flag_button == 2)
	{
		led_on(PORT_B, LED_ONE);
	}
	else if(flag_button == 3)
	{
		led_on(PORT_B, LED_TWO);
	}
	else if(flag_button == 4)
	{
		led_on(PORT_B, LED_THREE);
	}
	else if(flag_button == 5)
	{
		led_off(PORT_B, LED_ZERO);
	}
	else if(flag_button == 6)
	{
		led_off(PORT_B, LED_ONE);
	}
	else if(flag_button == 7)
	{
		led_off(PORT_B, LED_TWO);
	}
	else if(flag_button == 8)
	{
		led_off(PORT_B, LED_THREE);
	}

}


static void Button_Press(void)
{
	flag_button++;
	if (flag_button==9)
	{
		flag_button=1;
	}
}