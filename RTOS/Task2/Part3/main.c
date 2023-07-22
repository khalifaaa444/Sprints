/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include "semphr.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )


uint32_t	DataMailBox = 0;
uint8_t	button_1_flag=0;
uint8_t button_2_flag=0;


TaskHandle_t	UARTTask_Handler = NULL;
TaskHandle_t	FallingEdge_Handler = NULL;
TaskHandle_t	RisingEdge_Handler = NULL;
TaskHandle_t	RestTasks_Handler = NULL;

#define BUTTON_1_RISING			1
#define BUTTON_1_FALLLING		2
#define BUTTON_2_RISING			3
#define	BUTTON_2_FALLING		4


/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/


/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
/*Semaphore object*/
/*1. Binary Semaphore*/

//SemaphoreHandle_t userInput;



/*2. Counting Semaphore*/

/*SemaphoreHandle_t	multipleInstances;*/


/*3. mutex */
/*SemaphoreHandle_t mutex;*/

/*Task_1_normal*/


/*Task_1_binary Semaphore*/

void Rising_Edge (void* PvParameters)
{
	for( ; ;)
	{
		/*Task code goes here*/
		if(GPIO_read(PORT_0, PIN0)==PIN_IS_HIGH && button_1_flag==1)
		{
			DataMailBox=1;
			button_1_flag=0;
			xTaskNotify(UARTTask_Handler,DataMailBox,eSetValueWithOverwrite);
		}
		 if (GPIO_read(PORT_0, PIN1)==PIN_IS_HIGH && button_2_flag==1)
		{
			DataMailBox=2;
			button_2_flag=0;
			xTaskNotify(UARTTask_Handler,DataMailBox,eSetValueWithOverwrite);
		}
		vTaskDelay(100);
	}
}

void Falling_Edge (void* PvParameters)
{
	for( ; ;)
	{
		if(GPIO_read(PORT_0, PIN0)==PIN_IS_LOW && button_1_flag==0)
		{
			DataMailBox=3;
			button_1_flag=1;
			xTaskNotify(UARTTask_Handler,DataMailBox,eSetValueWithOverwrite);
		}
		 if (GPIO_read(PORT_0, PIN0)==PIN_IS_LOW && button_2_flag==0)
		{
			DataMailBox=4;
			button_2_flag=1;
			xTaskNotify(UARTTask_Handler,DataMailBox,eSetValueWithOverwrite);
		}
		vTaskDelay(100);
	}
}



void UART(void * pvParameters)
{
	uint32_t DataReceived=0;
	for( ; ;)
	{

		xTaskNotifyWait
		                (0x00,
		                 0xff,
		                 &DataReceived,
		                 portMAX_DELAY);
		if (DataReceived==BUTTON_1_FALLLING)
		{
			DataReceived = 0 ;
			vSerialPutString("BUTTON_1_FALLLING",21);
			DataMailBox=0;
		}
		else if (DataReceived==BUTTON_1_RISING)
		{
			DataReceived=0;
			vSerialPutString("BUTTON_1_RISING",21);
			DataMailBox=0;
		}
		else if (DataReceived==BUTTON_2_FALLING)
		{
			DataReceived=0;
			vSerialPutString("BUTTON_2_FALLING",21);
			DataMailBox=0;
		}
		else if (DataReceived==BUTTON_2_RISING)
		{
			DataReceived=0;
			vSerialPutString("BUTTON_2_RISING",21);
			DataMailBox=0;
		}
		else if (DataReceived==5)
		{
			vSerialPutString("Task5",8);
			DataReceived=0;
		}
		else if (DataReceived==6)
		{
			vSerialPutString("Task6",8);
			DataReceived=0;
		}
		else if (DataReceived==7)
		{
			vSerialPutString("Task7",8);
			DataReceived=0;
		}
		else if (DataReceived==8)
		{
			vSerialPutString("Task8",8);
			DataReceived=0;
		}
		else if (DataReceived==9)
		{
			vSerialPutString("Task9",8);
			DataReceived=0;
		}
		else if (DataReceived==10)
		{
			vSerialPutString("Task10",8);
			DataReceived=0;
		}
		else if (DataReceived==11)
		{
			vSerialPutString("Task11",8);
			DataReceived=0;
		}
		else if (DataReceived==12)
		{
			vSerialPutString("Task12",8);
			DataReceived=0;
		}
		else if (DataReceived==13)
		{
			vSerialPutString("Task13",8);
			DataReceived=0;
		}
		else if (DataReceived==14)
		{
			vSerialPutString("Task14",8);
			DataReceived=0;
		}
	}
}

void Rest_of_Tasks (void* PvParameters)
{
	uint8_t count=0;
	for( ; ;)
	{
		  for (count=5;count<15;count++)
		{
			xTaskNotify(UARTTask_Handler,count,eSetValueWithOverwrite);
			vTaskDelay(100);
		}
		count=5;

	}
}


/*Task_1 Counting Semaphore*/

/*
void vTask1(void * pvParameters)
{
	int data =0;
	
	for( ;; )
	{
		if(xSemaphoreTake(multipleInstances,(TickType_t)0)== pdTRUE)
		{
			//getUserInput(&data);
			//doSamething(data);
			
			xSemaphoreGive(multipleInstances);
		}
	}
}
*/

/*Task_1 Mutex*/
/*
void vTask1(void * pvParameters)
{
	int data =0;
	
	for( ;; )
	{
		if(xSemaphoreTake(mutex,(TickType_t)0)== pdTRUE)
		{
			//getUserInput(&data);
			//doSamething(data);
			
			xSemaphoreGive(mutex);
		}
	}
}
*/

int main()
{
	/**/
	//userInput = xSemaphoreCreateBinary();
	/**/
	//xSemaphoreGive(userInput);
	/**/
	/*multipleInstances = xSemaphoreCreateCounting(3,3);*/ /*(size , initial value)*/
	/**/
	
	/**/
	/*mutex = xSemaphoreCreateMutex();*/
	/**/
	
	/* Setup the hardware for use with the Keil demo board. */



	prvSetupHardware();

	
    /* Create Tasks here */
		xTaskCreate(
								UART,					/*Function Name*/
								"UART_1",				/*Text name*/
								100,							/*Stack Size*/
								(void * ) NULL,			/*Parameter Passed*/
								1,								/*Priority*/
								&UARTTask_Handler
								);
		xTaskCreate(
								Falling_Edge,					/*Function Name*/
								"Falling_Edge",				/*Text name*/
								100,							/*Stack Size*/
								(void * ) NULL,			/*Parameter Passed*/
								1,								/*Priority*/
								&FallingEdge_Handler
								);
		xTaskCreate(
								Rising_Edge,					/*Function Name*/
								"Rising_Edge",				/*Text name*/
								100,							/*Stack Size*/
								(void * ) NULL,			/*Parameter Passed*/
								1,								/*Priority*/
								&RisingEdge_Handler
								);
		xTaskCreate(
								Rest_of_Tasks,					/*Function Name*/
								"Rest_of_Tasks",				/*Text name*/
								100,							/*Stack Size*/
								(void * ) NULL,			/*Parameter Passed*/
								1,								/*Priority*/
								&RestTasks_Handler
								);
		
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


