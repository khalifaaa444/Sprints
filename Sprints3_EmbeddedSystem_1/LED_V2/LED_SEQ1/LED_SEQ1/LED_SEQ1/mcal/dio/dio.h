/*
 * dio.h
 *
 * Created: 6/5/2023 10:20:22 AM
 *  Author: ebrahem
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../common/std_types.h"
#include "../../common/memmap.h"
#include "../../common/bit_math.h"




typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	NONE_PIN_NAME,
}EN_PIN_NAME_t;

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	NONE_PORT_NAME,
}EN_PORT_NAME_t;

typedef enum
{
	LOW,
	HIGH,
	NONE_VOLTAGE_TYPE,
}EN_VOLTAGE_TYPE_t;


typedef enum
{
	IN,
	OUT,
	NONE_PIN_STATE,
}EN_PIN_DIR_t;


typedef enum
{
	OK_DIO,
	ERROR_DIO,	
}EN_STATUS_DIO_t;


EN_STATUS_DIO_t DIO_init( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_PIN_DIR_t dir );
EN_STATUS_DIO_t DIO_write( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_VOLTAGE_TYPE_t value );
EN_STATUS_DIO_t DIO_toggle( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num );
EN_STATUS_DIO_t DIO_read( EN_PORT_NAME_t port_num, EN_PIN_NAME_t pin_num, EN_VOLTAGE_TYPE_t *value );



#endif /* DIO_H_ */