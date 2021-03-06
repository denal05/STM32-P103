/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2007
 *
 *    File name   : main.c
 *    Description : Define main module
 *
 *    History :
 *    1. Date        : 19, July 2006
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *  This example project shows how to use the IAR Embedded Workbench
 * for ARM to develop code for the IAR STM32-SK board.
 *  It implements USB CDC (Communication Device Class) device and install
 * it like a Virtual COM port. UART3 is used for physical implementation
 * of the RS232 port.
 *
 *  Jumpers:
 *   PWR_SEL - depending of power source
 *
 *    $Revision: 1.1.2.1 $
 **************************************************************************/
#include "includes.h"
//#define DATA_LOGGING
#define UART  UART_2

#define LOOP_DLY_100US  450

Int32U CriticalSecCntr;

/*************************************************************************
 * Function Name: Clk_Init
 * Parameters: Int32U Frequency
 * Return: Int32U
 *
 * Description: Init clock system
 *
 *************************************************************************/
void Clk_Init (void)
{
  // 1. Clocking the controller from internal HSI RC (8 MHz)
  RCC_HSICmd(ENABLE);
  // wait until the HSI is ready
  while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY) == RESET);
  RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
  // 2. Enable ext. high frequency OSC
  RCC_HSEConfig(RCC_HSE_ON);
  // wait until the HSE is ready
  while(RCC_GetFlagStatus(RCC_FLAG_HSERDY) == RESET);
  // 3. Init PLL
  RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9); // 72MHz
  RCC_PLLCmd(ENABLE);
  // wait until the PLL is ready
  while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
  // 4. Set system clock dividers
  RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
  RCC_ADCCLKConfig(RCC_PCLK2_Div8);
  RCC_PCLK2Config(RCC_HCLK_Div1);
  RCC_PCLK1Config(RCC_HCLK_Div2);
  RCC_HCLKConfig(RCC_SYSCLK_Div1);
#ifdef EMB_FLASH
  // 5. Init Embedded Flash
  // Zero wait state, if 0 < HCLK 24 MHz
  // One wait state, if 24 MHz < HCLK 56 MHz
  // Two wait states, if 56 MHz < HCLK 72 MHz
  // Flash wait state
  FLASH_SetLatency(FLASH_Latency_2);
  // Half cycle access
  FLASH_HalfCycleAccessCmd(FLASH_HalfCycleAccess_Disable);
  // Prefetch buffer
  FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
#endif // EMB_FLASH
  // 5. Clock system from PLL
  RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
}

/*************************************************************************
 * Function Name: Dly100us
 * Parameters: Int32U Dly
 *
 * Return: none
 *
 * Description: Delay Dly * 100us
 *
 *************************************************************************/
void Dly100us(void *arg)
{
Int32U Dly = (Int32U)arg;
  while(Dly--)
  {
    for(volatile int i = LOOP_DLY_100US; i; i--);
  }
}

/*************************************************************************
https://my.st.com/public/STe2ecommunities/mcu/Lists/cortex_mx_stm32/Flat.aspx?RootFolder=%2Fpublic%2FSTe2ecommunities%2Fmcu%2FLists%2Fcortex_mx_stm32%2FSetting%20up%20RS232%20USART%20on%20STM32-P103&FolderCTID=0x01200200770978C69A1141439FE559EB459D7580009C4E14902C3CDE46A77F0FFD06506F5B&currentviews=712
*************************************************************************/

int putChar2 (int c)
{while (!(USART2->SR & USART_FLAG_TXE));
    USART2->DR = (c & 0xFF);

    return (c);
}

int putChar3 (int c)
{while (!(USART3->SR & USART_FLAG_TXE));
    USART3->DR = (c & 0xFF);

    return (c);
}

int getChar2 (void)
{while (!(USART2->SR & USART_FLAG_RXNE));

    return ((int)(USART2->DR & 0xFF));
}

void putS2(char *s)
{
    while(*s)
    {
        putChar2(*s);
        s++;
    }
}

void putS3(char *s)
{
    while(*s)
    {
        putChar3(*s);
        s++;
    }
}

int getS2(char *s)
{
    int character;
    int i=0;
    character = getChar2();
    while(character != -1)
    {
        s[i] = character;
        character = getChar2();
        i++;
    }
    s[i-2] = '\0'; // remove \r\n
    return i;
}

void UART_Demo( void )
{
  USART_InitTypeDef  UART_InitStructure, USART2_InitStructure, USART3_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM1_TimeBaseInitTypeDef TIM1_TimeBaseInitStruct;
  ////*NVIC_CCR = *NVIC_CCR | 0x200; // Set STKALIGN in NVIC
  
  // ENable clocks BEFORE using/configuring peripherals that expect them to be running
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

  // Configure PC.12 as output push-pull (LED)
  GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Configure USART2 Tx (PA.2) as alternate function push-pull
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // Configure USART2 Rx (PA.3) as input floating
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // Configure USART3 Tx (PB.10) as alternate function push-pull
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // enable UART peripheral by activating clock
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  /* There is a problem, possibly hardware bug, because although the UART word
     length (data bits) is set to 8 bits, the serial terminal will display
     correct data only if its data bits is set to 7 bits.
  */
  // USART2 configuration
  USART2_InitStructure.USART_BaudRate = 115200;
  USART2_InitStructure.USART_WordLength = USART_WordLength_8b;  //Word Length = 8 Bits
  USART2_InitStructure.USART_StopBits = USART_StopBits_1;  //Two Stop Bit
  USART2_InitStructure.USART_Parity = USART_Parity_No ;   //No parity
  USART2_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //Hardware flow control disabled (RTS and CTS signals)
  USART2_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  //Receive and transmit enabled

  // USART3 configuration
  USART3_InitStructure.USART_BaudRate = 115200;
  USART3_InitStructure.USART_WordLength = USART_WordLength_8b;  //Word Length = 8 Bits
  USART3_InitStructure.USART_StopBits = USART_StopBits_1;  //Two Stop Bit
  USART3_InitStructure.USART_Parity = USART_Parity_No ;   //No parity
  USART3_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //Hardware flow control disabled (RTS and CTS signals)
  USART3_InitStructure.USART_Mode = USART_Mode_Tx;  //Transmit enabled

  //Configure USARTs
  USART_Init(USART2,&USART2_InitStructure);
  USART_Init(USART3,&USART3_InitStructure);
       
  //Enable USARTs
  USART_Cmd(USART2, ENABLE);
  USART_Cmd(USART3, ENABLE);

  unsigned int i = 0;
  char str[] = "Welcome to wherever you are\r\n";

  while (1)
  {
    char *s = str;

    while(*s)
    {
      putChar2((char) *s ); // Send character from string to USART2 TX
      ////putChar3(getChar2()); // Send character from USART2 RX to USART3 TX
      putChar3((char) *s);
      putchar((char) *s);  // Send character from string to STDIO (terminal I/O)
      s++;
    }

    for(i=0; i<0xFFFFF; i++); // Wait
  }

}

/*************************************************************************
 * Function Name: main
 * Parameters: none
 *
 * Return: none
 *
 * Description: main
 *
 *************************************************************************/
void main(void)
{  
  // Init clock system
  Clk_Init();  
  
  /* There is a problem, possibly hardware bug, because although the UART word
     length (data bits) is set to 8 bits, the serial terminal will display
     correct data only if its data bits is set to 7 bits.
  */
  UART_Demo();
  
/*
  // https://www.olimex.com/dev/soft/arm/ST/STM32-P103/EW-ARM5_41%20STM32-P103.zip
Int8U Buffer[100];
pInt8U pBuffer;
Int32U Size,TranSize;
Boolean UpdateLineState = TRUE;
#ifdef DEBUG
 debug();
#endif

#if CDC_DEVICE_SUPPORT_LINE_CODING > 0
CDC_LineCoding_t CDC_LineCoding;
USART_InitTypeDef UartLineCoding;
#endif // CDC_DEVICE_SUPPORT_LINE_CODING > 0
#if CDC_DEVICE_SUPPORT_LINE_STATE > 0
UartLineEvents_t      UartLineEvents;
SerialState_t   SerialState = {0};
#endif // CDC_DEVICE_SUPPORT_LINE_STATE > 0

  ENTR_CRT_SECTION();

  // Init clock system
  Clk_Init();

  // NVIC init
#ifndef  EMB_FLASH
  // Set the Vector Table base location at 0x20000000
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
#else  // VECT_TAB_FLASH
  // Set the Vector Table base location at 0x08000000
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
#endif
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);

  // Enable timer counting
  TIM1_Cmd(ENABLE);

  // Init UART 3
 UartInit(UART,3);

  // CDC USB
  UsbCdcInit();

  // Soft connection enable
  USB_ConnectRes(TRUE);

  EXT_CRT_SECTION();
  //
  //// LCD Init
  //HD44780_PowerUpInit();

  //// Backlight On
  //LCD_LIGHT_ON();
  //// Show messages on LCD
  //HD44780_StrShow(1, 1,  "  IAR Systems   ");
  //HD44780_StrShow(1, 2,  "Virtual COM Port");

  SerialState.bRxCarrier = 1;
  SerialState.bTxCarrier = 1;
  while(1)
  {
    if (IsUsbCdcConfigure())
    {
      // Data from USB
      Size = UsbCdcRead(Buffer,sizeof(Buffer)-1);
      if(Size)
      {
    #ifdef DATA_LOGGING
        Buffer[Size] = 0;
        printf("> %s\n",Buffer);
    #endif // DATA_LOGGING
        TranSize = 0;
        pBuffer = Buffer;
        do
        {
          Size -= TranSize;
          pBuffer += TranSize;
          TranSize = UartWrite(UART,pBuffer,Size);
        }
        while(Size != TranSize);
      }

//========================================================================
      // Data from UART
      Size = UartRead(UART,Buffer,sizeof(Buffer)-1);
      if(Size)
      {
    #ifdef DATA_LOGGING
        Buffer[Size] = 0;
        printf("< %s\n",Buffer);
    #endif  // DATA_LOGGING
        while(!UsbCdcWrite(Buffer,Size));
      }
      // Get line and modem events from UART
    #if CDC_DEVICE_SUPPORT_LINE_STATE > 0
      // Get line events - BI, FE, PE, OE
      UartLineEvents = UartGetUartLineEvents(UART);
      if(UartLineEvents.Data | UpdateLineState)
      {
        UpdateLineState = FALSE;
        // Line events report BI, PE, FE and OE
        SerialState.bBreak = UartLineEvents.bBI;
        SerialState.bFraming = UartLineEvents.bFE;
        SerialState.bOverRun = UartLineEvents.bOE;
        SerialState.bParity = UartLineEvents.bPE;
        // Send events
        UsbCdcReportSerialCommState(SerialState);
      }
    #endif // CDC_DEVICE_SUPPORT_LINE_STATE > 0
    // UART line coding - Baud rate, number of the stop bits,
    // number of bits of the data word and parity type
    #if CDC_DEVICE_SUPPORT_LINE_CODING > 0
      if(UsbCdcIsNewLineCodingSettings())
      {
        CDC_LineCoding = UsbCdcGetLineCodingSettings();
        // Update the baud rate
        UartLineCoding.USART_BaudRate = CDC_LineCoding.dwDTERate;
        // Update the stop bits number
        switch(CDC_LineCoding.bCharFormat)
        {
        case 0:
          UartLineCoding.USART_StopBits = USART_StopBits_1;
          break;
        case 1:
          UartLineCoding.USART_StopBits = USART_StopBits_1_5;
          break;
        case 2:
          UartLineCoding.USART_StopBits = USART_StopBits_2;
          break;
        }
        // Update the parity type
        switch(CDC_LineCoding.bParityType)
        {
        case ODDPARITY:
          UartLineCoding.USART_Parity = USART_Parity_Odd;
          break;
        case EVENPARITY:
          UartLineCoding.USART_Parity = USART_Parity_Even;
          break;
        default:
          UartLineCoding.USART_Parity = USART_Parity_No;
        }
        // Update the word width
        UartLineCoding.USART_WordLength = USART_WordLength_8b;
        // Set UART line coding
        UartSetLineCoding(UART,UartLineCoding);
      }
    #endif // CDC_DEVICE_SUPPORT_LINE_CODING > 0
      // Get line and modem events from USB
    #if CDC_DEVICE_SUPPORT_BREAK > 0
      // Break event
      UartSetUartLineState(UART,UsbCdcGetBreakState());
    #endif // CDC_DEVICE_SUPPORT_BREAK > 0
    }
  }
*/
  
}

#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif