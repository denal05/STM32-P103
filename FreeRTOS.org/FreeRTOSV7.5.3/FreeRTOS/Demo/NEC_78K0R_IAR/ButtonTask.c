/*
    FreeRTOS V7.5.3 - Copyright (C) 2013 Real Time Engineers Ltd. 
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that has become a de facto standard.             *
     *                                                                       *
     *    Help yourself get started quickly and support the FreeRTOS         *
     *    project by purchasing a FreeRTOS tutorial book, reference          *
     *    manual, or both from: http://www.FreeRTOS.org/Documentation        *
     *                                                                       *
     *    Thank you!                                                         *
     *                                                                       *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>!AND MODIFIED BY!<< the FreeRTOS exception.

    >>! NOTE: The modification to the GPL is included to allow you to distribute
    >>! a combined work that includes FreeRTOS without being obliged to provide
    >>! the source code for proprietary components outside of the FreeRTOS
    >>! kernel.

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available from the following
    link: http://www.freertos.org/a00114.html

    1 tab == 4 spaces!

    ***************************************************************************
     *                                                                       *
     *    Having a problem?  Start by reading the FAQ "My application does   *
     *    not run, what could be wrong?"                                     *
     *                                                                       *
     *    http://www.FreeRTOS.org/FAQHelp.html                               *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org - Documentation, books, training, latest versions,
    license and Real Time Engineers Ltd. contact details.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.OpenRTOS.com - Real Time Engineers ltd license FreeRTOS to High
    Integrity Systems to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

/*
 * This file defines the button push task and ISR as described at the top of
 * main.c.  The ISR is called from a wrapper function defined in ButtonISR.s26.
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* The LED output used by the button push task. */
#define butLED1   P7_bit.no7

/* A short delay used for button debouncing. */
#define butDEBOUNCE_DELAY	( 200 / portTICK_RATE_MS )

/* The semaphore used to synchronise the button push task with the interrupt. */
static xSemaphoreHandle xButtonSemaphore;

/*
 * The definition of the button task itself.  See the comments at the top of
 * main.c.
 */
void vButtonTask( void *pvParameters )
{
	/* Ensure the semaphore is created before it gets used. */
	vSemaphoreCreateBinary( xButtonSemaphore );

	for( ;; )
	{
		/* Block on the semaphore to wait for an interrupt event.  The semaphore
		is 'given' from vButtonISRHandler() below.  Using portMAX_DELAY as the
		block time will cause the task to block indefinitely provided
		INCLUDE_vTaskSuspend is set to 1 in FreeRTOSConfig.h. */
		xSemaphoreTake( xButtonSemaphore, portMAX_DELAY );

		/* The button must have been pushed for this line to be executed.
		Simply toggle the LED. */
		butLED1 = !butLED1;
		
		/* Wait a short time then clear any pending button pushes as a crude
		method of debouncing the switch.  xSemaphoreTake() uses a block time of
		zero this time so it returns immediately rather than waiting for the
		interrupt to occur. */
		vTaskDelay( butDEBOUNCE_DELAY );
		xSemaphoreTake( xButtonSemaphore, 0 );
	}
}
/*-----------------------------------------------------------*/

/*
 * The C portion of the interrupt handler.  Interrupts are triggered by pushing
 * the button on the target board.  This interrupt can cause a context switch
 * so has an assembly file wrapper defined within ButtonISR.s26.
 */
void vButtonISRHandler( void )
{
short sHigherPriorityTaskWoken = pdFALSE;

	/* 'Give' the semaphore to unblock the button task. */
	xSemaphoreGiveFromISR( xButtonSemaphore, &sHigherPriorityTaskWoken );
	
	/* If giving the semaphore unblocked a task, and the unblocked task has a
	priority that is higher than the currently running task, then
	sHigherPriorityTaskWoken will have been set to pdTRUE.  Passing a pdTRUE
	value to portYIELD_FROM_ISR() will cause this interrupt to return directly
	to the higher priority unblocked task. */
	portYIELD_FROM_ISR( sHigherPriorityTaskWoken );
}
/*-----------------------------------------------------------*/
