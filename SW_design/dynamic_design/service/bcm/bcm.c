#include "bcm.h"

void bcm_init()
{
    uart_init(Baudrate9600,Normal_Speed,Asynchronous,No_Parity,StopBit_1,DataBit_8,TR);
    
}



void bcm_send(u8* str)
{
  uart_transmitString(str); 
  
}
