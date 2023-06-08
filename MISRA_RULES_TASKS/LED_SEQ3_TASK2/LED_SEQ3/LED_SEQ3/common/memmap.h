/*
 * memmap.h
 *
 * Created: 6/6/2023 9:54:57 AM
 *  Author: ebrahem
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_





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



//****************** TIMER_0 REGESTERS ******************//

#define TCCR0	(*(volatile unsigned char  *)0x53)
#define TCNT0	(*(volatile unsigned char  *)0x52)
#define TIFR	(*(volatile unsigned char  *)0x58)
#define TIMSK	(*(volatile unsigned char  *)0x59)
#define OCR0	(*(volatile unsigned char  *)0x5C)

// TCCR0
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

// TIFR
#define TOV0	0
#define OCF0	1
#define TOV1	2
#define OCF1B	3
#define OCF1A	4
#define ICF1	5
#define TOV2	6
#define OCF2	7



//****************** TIMER_1 REGESTERS ******************//

#define TCCR1A	(*(volatile unsigned char  *)0x4F)
#define TCCR1B	(*(volatile unsigned char  *)0x4E)
#define TCNT1H	(*(volatile unsigned char  *)0x4D)
#define TCNT1L	(*(volatile unsigned char  *)0x4C)
#define OCR1AH	(*(volatile unsigned char  *)0x4B)
#define OCR1AL	(*(volatile unsigned char  *)0x4A)
#define OCR1BH	(*(volatile unsigned char  *)0x49)
#define OCR1BL	(*(volatile unsigned char  *)0x48)
#define ICR1H	(*(volatile unsigned char  *)0x47)
#define ICR1L	(*(volatile unsigned char  *)0x46)




//****************** TIMER_2 REGESTERS ******************//
#define	TCCR2	(*(volatile unsigned char  *)0x45)
#define TCNT2	(*(volatile unsigned char  *)0x44)
#define OCR2	(*(volatile unsigned char  *)0x43)



#endif /* MEMMAP_H_ */