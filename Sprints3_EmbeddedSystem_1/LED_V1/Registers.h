/*
 * Registers.h
 *
 * Created: 4/10/2023 7:17:34 AM
 *  Author: ebrahem
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_



typedef unsigned char uint8_t ;



#define DDRA  (*(volatile uint8_t  *)0x3A)
#define PORTA (*(volatile uint8_t  *)0x3B)
#define PINA  (*(volatile uint8_t  *)0x39)


#define DDRB  (*(volatile uint8_t  *)0x37)
#define PORTB (*(volatile uint8_t  *)0x38)
#define PINB  (*(volatile uint8_t  *)0x36)


#define DDRD  (*(volatile uint8_t  *)0x31)
#define PORTD (*(volatile uint8_t  *)0x32)
#define PIND  (*(volatile uint8_t  *)0x30)


#define DDRC  (*(volatile uint8_t  *)0x34)
#define PORTC (*(volatile uint8_t  *)0x35)
#define PINC  (*(volatile uint8_t  *)0x33)


//uint8_t arr_led[4]={0,1,2,3};


#endif /* REGISTERS_H_ */