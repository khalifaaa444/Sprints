/*
 * interrupt.h
 *
 * Created: 8/3/2023 2:44:38 AM
 *  Author: ebrahem
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "../../common/bit_math.h"
#include "../../common/memmap.h"
#include "../../common/std_types.h"

typedef struct INTERRUPT
	{
		uint8_t No_Of_INT;
		uint8_t Type_INT;
	}INT_Num;

typedef enum {
	INT_0,
	INT_1,
	INT_2,
	}en_INT_NUM_t;
	
typedef enum {
	RISING,
	FALLING,
	}en_INT_SENCE_t;


void sei();

void cle();

uint8_t choose_interrupt(INT_Num* int_fun);

void EX_INT_SET_CALLBACK (uint8_t int_num,void *ptrfun(void));


/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)



#endif /* INTERRUPT_H_ */