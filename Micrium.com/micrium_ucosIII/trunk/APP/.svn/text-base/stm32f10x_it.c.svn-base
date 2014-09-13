/**
  ******************************************************************************
  * @file    Project/Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.0.0
  * @date    04/06/2009
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "includes.h"
#include "stm32f10x_it.h"
#include "Uart.h"
#include "SpiTouch.h"

u32 x_sum=0,y_sum=0;

extern OS_SEM TouchSem;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
void EXTI15_10_IRQHandler(void)
{ 
  OS_ERR      err;
  
  u16 local_x[18],local_y[18],x_min=0xffff,x_max=0,y_min=0xffff,y_max=0;
  u32 local_x_sum=0,local_y_sum=0;
  u8 num=0;
  
  if(EXTI_GetITStatus(EXTI_Line12) != RESET)
  {	
  		GetTouchX(); GetTouchY();


		while(!GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_12))
		{
			local_x[num]=GetTouchX();
			local_y[num]=GetTouchY();
			
			if(x_min>local_x[num]) x_min=local_x[num];
			if(x_max<local_x[num]) x_max=local_x[num];

			if(y_min>local_y[num]) y_min=local_y[num];
			if(y_max<local_y[num]) y_max=local_y[num];

			local_x_sum+=local_x[num];
			local_y_sum+=local_y[num];

			if(num++==18) 
			{
				local_x_sum=(local_x_sum-(x_min+x_max))>>4;
				local_y_sum=(local_y_sum-(y_min+y_max))>>4;

                                OSSemPost (&TouchSem, OS_OPT_POST_ALL, &err);
                                
				Debug("x:%4d,y:%4d\n\r\n\r",local_x_sum,local_y_sum);
			        x_sum = local_x_sum;
                                y_sum = local_y_sum;
                                
				EXTI_ClearITPendingBit(EXTI_Line12);
				return;
			}
		}
		EXTI_ClearITPendingBit(EXTI_Line12);
  }
}


/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
