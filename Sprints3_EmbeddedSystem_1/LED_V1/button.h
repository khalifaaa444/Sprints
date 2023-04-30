/*
 * button.h
 *
 * Created: 4/10/2023 1:11:16 PM
 *  Author: ebrahem
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "dio.h"

void button_init(uint8_t port_num , uint8_t pin_num);

void buttonState(uint8_t port_num , uint8_t pin_num , uint8_t* value);




#endif /* BUTTON_H_ */