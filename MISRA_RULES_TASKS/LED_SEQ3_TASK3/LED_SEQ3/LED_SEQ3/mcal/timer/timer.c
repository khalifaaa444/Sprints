/*
 * timer.c
 *
 * Created: 6/6/2023 11:54:52 AM
 *  Author: ebrahem
 */ 
#include "timer.h"
void static (*CallBack)(void);


EN_STATUS_TIMER_t Timer_Init(st_Timer_req_t *TimerReq)
{
	
	EN_STATUS_TIMER_t	ret_function = OK_TIMER;
	if(TimerReq->TimerID == TIMER_ZERO)
	{
		if(TimerReq->TimerMode == NORMAL_MODE)
		{
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
		}
		else if(TimerReq->TimerMode == CTC_MODE)
		{
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
		else if(TimerReq->TimerMode == FAST_PWM_MODE)
		{
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
		}
		else if(TimerReq->TimerMode == PHASE_CORRECT_MODE)
		{
			SET_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
		}
		else 
		{
			ret_function = ERROR_TIMER;
		}
	}
	else if(TimerReq->TimerID == TIMER_ONE)
	{
		
	}
	else if (TimerReq->TimerID == TIMER_TWO)
	{
		
	}
	else
	{
		ret_function = ERROR_TIMER;
	}
	
	return	ret_function;
}

EN_STATUS_TIMER_t Timer_delay(st_Timer_req_t *TimerReq)
{
	EN_STATUS_TIMER_t	ret_function = OK_TIMER;
	uint32_t			N_OVERFLOW;
	f32_t				T_tick;
	f32_t				T_MaxDelay;
	f32_t				T_init;
	
	(TimerReq->DelayRequired) *= 1000;
	
	if(TimerReq->TimerID == TIMER_ZERO)
	{
		if(TimerReq->TimerMode == NORMAL_MODE)
		{
			T_tick = (f32_t)(TimerReq->PrescalerSelect) / F_CPU;
			//DDRC= T_tick;
			T_MaxDelay = T_tick * 256.0;
			
			if(TimerReq->DelayRequired <= T_MaxDelay)
			{
				T_init	=	(T_MaxDelay - TimerReq->DelayRequired)/(T_tick);
				//T_init	=	(256 - TimerReq->DelayRequired)/(1);
			}
			else
			{
				N_OVERFLOW = TimerReq->DelayRequired/T_MaxDelay;   
				T_init = 256 - ((TimerReq->DelayRequired / T_tick)/N_OVERFLOW);		
			}
			
			TCNT0 = T_init;
			//DDRD  = T_init;
			if(TimerReq->PrescalerSelect == PRESCALER_0)
			{
				
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
			}
			else if(TimerReq->PrescalerSelect == PRESCALER_8)
			{
				CLR_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
			}
			else if(TimerReq->PrescalerSelect == PRESCALER_64)
			{
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLR_BIT(TCCR0,CS02);
			}
			else if(TimerReq->PrescalerSelect == PRESCALER_256)
			{
				CLR_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
			}
			else if(TimerReq->PrescalerSelect == PRESCALER_1024)
			{
				SET_BIT(TCCR0,CS00);
				CLR_BIT(TCCR0,CS01);
				SET_BIT(TCCR0,CS02);
			}
			else 
			{
				ret_function = ERROR_TIMER;
			}
			//N_OVERFLOW=2000;
			//DDRC=N_OVERFLOW;
			//SET_BIT(DDRA,7);
			while(N_OVERFLOW!=0)
			{
				
				while((TIFR & (1<<TOV0))==0);
				N_OVERFLOW--;
				SET_BIT(TIFR,TOV0);
			}			
			//SET_BIT(DDRA,6);
		}
		else if(TimerReq->TimerMode == CTC_MODE)
		{
			
		}
		else if(TimerReq->TimerMode == FAST_PWM_MODE)
		{
			
		}
		else if(TimerReq->TimerMode == PHASE_CORRECT_MODE)
		{
			
		}
		else 
		{
			ret_function = ERROR_TIMER;
		}
	}
	else if(TimerReq->TimerID == TIMER_ONE)
	{
		
	}
	else if(TimerReq->TimerID == TIMER_TWO)
	{
		
	}
	else 
	{
		ret_function = ERROR_TIMER;
	}
	(TimerReq->DelayRequired) /= 1000;
	return	ret_function;
}

EN_STATUS_TIMER_t Timer_Stop(st_Timer_req_t *TimerReq)
{
	EN_STATUS_TIMER_t ret_function=OK_TIMER;
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	return ret_function;
}
