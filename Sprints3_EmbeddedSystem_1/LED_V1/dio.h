/*
 * dio.h
 *
 * Created: 4/10/2023 4:13:57 AM
 *  Author: ebrahem
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "Registers.h"

#define HIGH 1
#define LOW 0
#define IN 0
#define OUT 1


#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

void DIO_init( uint8_t port_num, uint8_t pin_num, uint8_t dir );
void DIO_write( uint8_t port_num, uint8_t pin_num, uint8_t value );
void DIO_toggle( uint8_t port_num, uint8_t pin_num );
void DIO_read( uint8_t port_num, uint8_t pin_num, uint8_t *value );



#endif /* DIO_H_ */