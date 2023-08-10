/*
 * memmap.h
 *
 * Created: 6/5/2023 10:02:59 AM
 *  Author: ebrahem
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

#include "std_types.h"

#define DDRA  (*(volatile unsigned char  *)0x3A)
#define PORTA (*(volatile unsigned char  *)0x3B)
#define PINA  (*(volatile unsigned char  *)0x39)


#define DDRB  (*(volatile unsigned char  *)0x37)
#define PORTB (*(volatile unsigned char  *)0x38)
#define PINB  (*(volatile unsigned char  *)0x36)


#define DDRD  (*(volatile unsigned char  *)0x31)
#define PORTD (*(volatile unsigned char  *)0x32)
#define PIND  (*(volatile unsigned char  *)0x30)


#define DDRC  (*(volatile unsigned char  *)0x34)
#define PORTC (*(volatile unsigned char  *)0x35)
#define PINC  (*(volatile unsigned char  *)0x33)


/* _______  INTERRUPT _______	*/

#define SREG	(*(volatile unsigned char *)0x5F)
#define I_BIT	7 


#define MCUCR	(*(volatile unsigned char *)0x55)
#define MCUCSR	(*(volatile unsigned char *)0x54)
#define GIFR	(*(volatile unsigned char *)0x5A)
#define GICR	(*(volatile unsigned char *)0x5B)


#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3
#define ISC2	6

#define INT1	7
#define INT0	6
#define INT2	5

#define INTF0	6
#define	INTF1	7
#define INTF2	5



#endif /* MEMMAP_H_ */