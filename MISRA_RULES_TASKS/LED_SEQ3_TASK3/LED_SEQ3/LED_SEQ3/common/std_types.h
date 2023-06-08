/*
 * std_types.h
 *
 * Created: 6/6/2023 9:56:19 AM
 *  Author: ebrahem
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


#define F_CPU	8


// unsigned integers
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;

//signed	integers
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

//floating
typedef	float f32_t;


typedef enum
{
	FALSE,
	TRUE
}EN_BOOL_t;

#define  NULL               0
#define  NULLPTR           ((void*)0)




#endif /* STD_TYPES_H_ */