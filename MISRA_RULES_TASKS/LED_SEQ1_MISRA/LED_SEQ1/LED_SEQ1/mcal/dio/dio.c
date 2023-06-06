/*
 * dio.c
 *
 * Created: 6/5/2023 10:21:47 AM
 *  Author: ebrahem
 */ 


#include "dio.h"

EN_STATUS_DIO_t DIO_init( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_PIN_DIR_t dir )
{
	EN_STATUS_DIO_t ret_function= OK_DIO;    //use it in return of function
	
	switch(port_num)
	{
		case PORT_A:
		if(dir == IN)
		{
			CLR_BIT(DDRA,pin_num);
			
		}
		else if(dir == OUT)
		{
			SET_BIT(DDRA,pin_num);
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		case PORT_B:
		if(dir == IN)
		{
			CLR_BIT(DDRB,pin_num);
			
		}
		else if(dir == OUT)
		{
			SET_BIT(DDRB,pin_num);
			
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		case PORT_C:
		if(dir == IN)
		{
			CLR_BIT(DDRC,pin_num);
			
		}
		else if(dir == OUT)
		{
			SET_BIT(DDRC,pin_num);
			
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		
		case PORT_D:
		if(dir == IN)
		{
			CLR_BIT(DDRD,pin_num);
			
		}
		else if(dir == OUT)
		{
			SET_BIT(DDRD,pin_num);
			
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		default : ;	// do_nothing 
		
	}
	
	return ret_function;
}




EN_STATUS_DIO_t DIO_write( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_VOLTAGE_TYPE_t value )
{
	EN_STATUS_DIO_t ret_function= OK_DIO;    //use it in return of function
	
	switch(port_num)
	{
		case PORT_A:
		if(value == LOW)
		{
			CLR_BIT(PORTA,pin_num);
			
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTA,pin_num);
			
		}
		else
		{
			ret_function=ERROR_DIO;
		}
		break;
		
		case PORT_B:
		if(value == LOW)
		{
			CLR_BIT(PORTB,pin_num);
			
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTB,pin_num);
			
		}
		else
		{
			ret_function=ERROR_DIO;
		}
		break;
		
		case PORT_C:
		if(value == LOW)
		{
			CLR_BIT(PORTC,pin_num);
			
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTC,pin_num);
			
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		
		case PORT_D:
		if(value == LOW)
		{
			CLR_BIT(PORTD,pin_num);
			
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTD,pin_num);
			
		}
		else
		{
			ret_function = ERROR_DIO;
		}
		break;
		
		default :  ; //DO NOTHING
		
	}
	
	return ret_function;
}

EN_STATUS_DIO_t DIO_toggle( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num )
{
	EN_STATUS_DIO_t ret_function= OK_DIO;    //use it in return of function
	switch(port_num)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA,pin_num);
		
		break;
		
		case PORT_B:
		TOGGLE_BIT(PORTB,pin_num);
		
		break;
		
		case PORT_C:
		TOGGLE_BIT(PORTC,pin_num);
		
		break;
		
		case PORT_D:
		TOGGLE_BIT(PORTD,pin_num);
		
		break;
		
		default: ret_function= ERROR_DIO ;
		
	}
	
	return ret_function;
}


EN_STATUS_DIO_t DIO_read( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_VOLTAGE_TYPE_t *value )
{
	EN_STATUS_DIO_t	ret_function= OK_DIO;    //use it in return of function
	switch(port_num)
	{
		case PORT_A:
		*value = READ_BIT(PINA,pin_num);
		
		break;
		
		case PORT_B:
		*value = READ_BIT(PINB,pin_num);
		
		break;
		
		case PORT_C:
		*value = READ_BIT(PINC,pin_num);
		
		break;
		
		case PORT_D:
		*value = READ_BIT(PIND,pin_num);

		break;
		
		default:ret_function = ERROR_DIO ;
	}
	return ret_function;
}