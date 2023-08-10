/*
 * bit_math.h
 *
 * Created: 6/5/2023 10:03:34 AM
 *  Author: ebrahem
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)	(reg|=(1<<bit))
#define CLR_BIT(reg,bit)	(reg&=~(1<<bit))
#define READ_BIT(reg,bit)	((reg & (1<<bit))>>bit)  
#define TOGGLE_BIT(reg,bit)	(reg^=(1<<bit))


#endif /* BIT_MATH_H_ */