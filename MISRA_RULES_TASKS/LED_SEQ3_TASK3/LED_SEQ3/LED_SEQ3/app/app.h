/*
 * app.h
 *
 * Created: 6/6/2023 10:12:21 AM
 *  Author: ebrahem
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ecu/button/button.h"
#include "../ecu/led/led.h"
#include "../mcal/timer/timer.h"

extern st_Timer_req_t Timer_obj1;


typedef enum
{
	NONE_LEDS=-1,
	LED_ZERO=0,
	LED_ONE,
	LED_TWO,
	LED_THREE,
}EN_LED_NUM_t;



void app_init();

void app_start();





#endif /* APP_H_ */