/*
 * led.h
 *
 * Created: 4/10/2023 12:52:29 PM
 *  Author: ebrahem
 */ 


#ifndef LED_H_
#define LED_H_
#include "dio.h"

void led_init(uint8_t port_num , uint8_t pin_num);

void led_on(uint8_t port_num , uint8_t pin_num);

void led_off(uint8_t port_num , uint8_t pin_num);

void led_toggle(uint8_t port_num , uint8_t pin_num);




#endif /* LED_H_ */