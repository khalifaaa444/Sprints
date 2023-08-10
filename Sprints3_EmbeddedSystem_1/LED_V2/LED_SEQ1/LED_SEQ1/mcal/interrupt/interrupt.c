/*
 * interrupt.c
 *
 * Created: 8/3/2023 2:44:57 AM
 *  Author: ebrahem
 */ 


#include "interrupt.h"

void sei()
{
	SET_BIT(SREG,I_BIT);
}

void cle()
{
	CLR_BIT(SREG,I_BIT);
}

uint8_t choose_interrupt(INT_Num* int_fun)
{
	if(int_fun->No_Of_INT == INT_0)
	{
		if(int_fun->Type_INT == RISING)
		{
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
		}
		else if(int_fun->Type_INT == FALLING)
		{
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
		}
		SET_BIT(GICR,INT0);
	}
	else if(int_fun->No_Of_INT == INT_1)
	{
		if(int_fun->Type_INT == RISING)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if(int_fun->Type_INT == FALLING)
		{
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		
		SET_BIT(GICR,INT1);
	}
}	
	

static void (*pf_INT0)(void)= NULLPTR;
static void (*pf_INT1)(void)= NULLPTR;
static void (*pf_INT2)(void)= NULLPTR;


void EX_INT_SET_CALLBACK (uint8_t int_num,void *ptrfun(void))
{
	if(int_num == INT_0)
	{
		ptrfun = pf_INT0;
	}
	
	else if(int_num == INT_1)
	{
		ptrfun = pf_INT1;
	}
	else if(int_num == INT_2)
	{
		ptrfun = pf_INT2;
	}
}


ISR (INT0_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT0();
	}
}

ISR (INT1_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT1();
	}
}

ISR (INT2_vect)
{
	if (pf_INT0!=NULLPTR)
	{
		pf_INT2();
	}
}
