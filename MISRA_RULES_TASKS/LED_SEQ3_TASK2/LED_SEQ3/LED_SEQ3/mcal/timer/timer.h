/*
 * timer.h
 *
 * Created: 6/6/2023 10:29:05 AM
 *  Author: ebrahem
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../common/std_types.h"
#include "../../common/memmap.h"
#include "../../common/bit_math.h"



#define	PRESCALER_0		1.0
#define	PRESCALER_8		8.0
#define PRESCALER_64	64.0
#define PRESCALER_256	256.0
#define PRESCALER_1024	1024.0


typedef enum 
{
	
	NORMAL_MODE,
	CTC_MODE,
	FAST_PWM_MODE,
	PHASE_CORRECT_MODE,
	NONE_MODE,
	
}EN_TIMER_MODE_t;

typedef enum
{
	TIMER_ZERO,
	TIMER_ONE,
	TIMER_TWO,
	NONE_TIMER,
	
}EN_TIMER_ID_t;


typedef enum
{
	OK_TIMER,
	ERROR_TIMER,
	
}EN_STATUS_TIMER_t;



typedef struct
{
	EN_TIMER_ID_t		TimerID;
	EN_TIMER_MODE_t		TimerMode;
	uint32_t			PrescalerSelect;
	uint64_t			DelayRequired;
	
}st_Timer_req_t;


EN_STATUS_TIMER_t Timer_Init(st_Timer_req_t *TimerReq);
EN_STATUS_TIMER_t Timer_delay(st_Timer_req_t *TimerReq);
EN_STATUS_TIMER_t Timer_Stop(st_Timer_req_t *TimerReq);



#endif /* TIMER_H_ */