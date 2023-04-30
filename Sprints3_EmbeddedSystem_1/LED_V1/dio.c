/*
 * dio.c
 *
 * Created: 4/10/2023 4:27:16 AM
 *  Author: ebrahem
 */ 

#include "dio.h"

void DIO_init( uint8_t port_num, uint8_t pin_num, uint8_t dir )
{
	switch(port_num)
	{
		case PORT_A:
		if(dir == IN)
		{
			DDRA &= ~(1<<pin_num);
		}
		else if(dir == OUT)
		{
			DDRA |= (1<<pin_num);
		}
		else 
		{
			
		}
		break;
		
		case PORT_B:
		if(dir == IN)
		{
			DDRB &= ~(1<<pin_num);
		}
		else if(dir == OUT)
		{
			DDRB |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		case PORT_C:
		if(dir == IN)
		{
			DDRC &= ~(1<<pin_num);
		}
		else if(dir == OUT)
		{
			DDRC |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		
		case PORT_D:
		if(dir == IN)
		{
			DDRD &= ~(1<<pin_num);
		}
		else if(dir == OUT)
		{
			DDRD |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		default : ;
		
	}
}




void DIO_write( uint8_t port_num, uint8_t pin_num, uint8_t value )
{
	switch(port_num)
	{
		case PORT_A:
		if(value == LOW)
		{
			PORTA &= ~(1<<pin_num);
		}
		else if(value == HIGH)
		{
			PORTA |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			PORTB &= ~(1<<pin_num);
		}
		else if(value == HIGH)
		{
			PORTB |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			PORTC &= ~(1<<pin_num);
		}
		else if(value == HIGH)
		{
			PORTC |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		
		case PORT_D:
		if(value == LOW)
		{
			PORTD &= ~(1<<pin_num);
		}
		else if(value == HIGH)
		{
			PORTD |= (1<<pin_num);
		}
		else
		{
			
		}
		break;
		
		default :  ;
		
	}
}

void DIO_toggle( uint8_t port_num, uint8_t pin_num )
{
	switch(port_num)
	{
		case PORT_A:
		PORTA ^= (1<<pin_num);
		break;
		
		case PORT_B:
		PORTB ^= (1<<pin_num);
		break;
		
		case PORT_C:
		PORTC ^= (1<<pin_num);
		break;
		
		case PORT_D:
		PORTD ^= (1<pin_num);
		break;
		
		default: ;
		
	}	
}


void DIO_read( uint8_t port_num, uint8_t pin_num, uint8_t *value )
{
	
	switch(port_num)
	{
		case PORT_A:
		*value = (PINA &(1<<pin_num))>>pin_num;
		break;
		
		case PORT_B:
		*value = (PINA &(1<<pin_num))>>pin_num;
		break;
		
		case PORT_C:
		*value = (PINC &(1<<pin_num))>>pin_num;
		break;
		
		case PORT_D:
		*value = (PINA &(1<<pin_num))>>pin_num;
		break;
		
		default: ;
	}
	
}