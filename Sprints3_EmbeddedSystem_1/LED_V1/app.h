/*
 * app.h
 *
 * Created: 4/10/2023 1:35:34 PM
 *  Author: ebrahem
 */ 


#ifndef APP_H_
#define APP_H_


#define F_CPU 8000000UL

#include <util/delay.h>



#include "button.h"
#include "led.h"

void app_init();

void app_start();



#endif /* APP_H_ */