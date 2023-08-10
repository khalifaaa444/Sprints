/*
 * app.h
 *
 * Created: 6/5/2023 12:48:23 PM
 *  Author: ebrahem
 */ 


#ifndef APP_H_
#define APP_H_




#include "../ecu/button/button.h"
#include "../ecu/led/led.h"


typedef enum 
{
	LED_ZERO,
	LED_ONE,
	LED_TWO,
	LED_THREE,	
}EN_LED_NUM_t;


void app_init();

void app_start();





#endif /* APP_H_ */