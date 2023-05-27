/*
 * utilise.h
 *
 * Created: 5/27/2023 7:40:58 AM
 *  Author: ebrahem
 */ 


#ifndef UTILISE_H_
#define UTILISE_H_



#define F_CPU  8000000
//#include <util/delay.h>



#define ReadBit(reg,bit)         (reg=reg>>bit & 1)
#define SetBit(reg,bit)          (reg|=(1<<bit))
#define ClearBit(reg,bit)          (reg&=~(1<<bit))
#define TogggleBit(reg,bit)          (reg=reg^(1<<bit))
#define WriteBit(reg,bit,val)    (reg=(reg&(~(1<<bit))) | (val<<bit))






#endif /* UTILISE_H_ */
