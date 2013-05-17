/********************************************************************************
 * FileName:       
 * Author:         YuanYin  Version: QXW-Summer-V1.x  Date: 2010-4-29
 * Description:    
 * Version:        
 * Function List:  
 *                 1.
 * History:        
 *     <author>   <time>    <version >   <desc>
 *      YuanYin       4-29         1.x   
*******************************************************************************/
/*****************************************************
 *  酷享科技		Q-Share We	快乐-开源-分享		
 *  						   	
 *  如果你对我们的产品有任何建议或不满，请联系我们! 	
 *						   	
 *  淘宝专营：Q-ShareWe.TaoBao.Com			
 *  技术论坛：Www.Q-ShareWe.Com				
 ****************************************************/
#include "Lcd.h"
#include "Lcd_font.h"
#include "stm32f10x_fsmc.h"

//LCD与FSMC地址的连接，这里的细节请参考"原材料/9.LCD"目录下《LCD与FSMC的连接原理》一文。
#define Bank1_LCD_D    ((uint32_t)0x60020000)    //disp Data ADDR
#define Bank1_LCD_C    ((uint32_t)0x60000000)	 //disp Reg ADDR

/*************************************************
函数名：LCD_WR_Reg
功能：对lcd寄存器，写命令
入口参数：寄存器地址和命令
返回值：无
*************************************************/
void LCD_WR_Reg(unsigned int index,unsigned int val)
{	
	*(__IO uint16_t *) (Bank1_LCD_C)= (index<<8)+val;	
}

/*************************************************
函数名：LCD_WR_Data
功能：对lcd写数据
入口参数：数据值
返回值：无
*************************************************/
void LCD_WR_Data(unsigned int val)
{   
	*(__IO uint16_t *) (Bank1_LCD_D)= val; 	
}

/*************************************************
函数名：LCD_RD_Data
功能：读lcd数据
入口参数：无
返回值：数据
*************************************************/
unsigned int LCD_RD_Data(void)
{
	return(*(__IO uint16_t *) (Bank1_LCD_D));	
}

/**********************************************
函数名：LCD_Delay
功能：用于LCD配置延时
入口参数：延时数
返回值：无
***********************************************/
void LCD_Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}

/**********************************************
函数名：LCD_Reset
功能：LCD复位
入口参数：延时数
返回值：无
***********************************************/ 
void LCD_Reset(void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    LCD_Delay(50);					   
    GPIO_SetBits(GPIOD, GPIO_Pin_13);		 	 
	LCD_Delay(50);	
}

/*************************************************
函数名：LCD_Set_XY
功能：设置lcd显示起始点
入口参数：xy坐标
返回值：无
*************************************************/
void LCD_Set_XY(unsigned int x,unsigned int y)
{
	LCD_WR_Reg(0x42,x);
	LCD_WR_Reg(0x43,y >> 8);
	LCD_WR_Reg(0x44,y & 0xff);	
}

/*************************************************
函数名：LCD_Set_Region
功能：设置lcd显示区域，在此区域写点数据自动换行
入口参数：xy起点和终点
返回值：无
*************************************************/
void LCD_Set_Region(unsigned int x_start,unsigned int y_start,unsigned int x_end,unsigned int y_end)
{		
	LCD_WR_Reg(0x05,0x10);
	
	LCD_WR_Reg(0x45,x_start);
	LCD_WR_Reg(0x46,x_end);

	LCD_WR_Reg(0x47,y_start >> 8);
	LCD_WR_Reg(0x48,y_start & 0xff);
	
	LCD_WR_Reg(0x49,y_end >> 8);
	LCD_WR_Reg(0x4a,y_end & 0xff);	

	LCD_Set_XY(x_start,y_start);
}

/*************************************************
函数名：LCD_Set_Partial_Display
功能：设置lcd的两个并行显示区域，实际没多大用
入口参数：第一个区域起点行和终点行，第二个区域起点行和终点行
返回值：无
*************************************************/
void LCD_Set_Partial_Display(unsigned int start1,unsigned int end1,unsigned int start2,unsigned int end2)
{
	LCD_WR_Reg(0x00,0x30);
	LCD_WR_Reg(0x34,0x00);

	LCD_WR_Reg(0x10,start1 >> 8);
	LCD_WR_Reg(0x11,start1 & 0xff);

	LCD_WR_Reg(0x14,(end1-start1) >> 8);
	LCD_WR_Reg(0x15,(end1-start1) & 0xff);

	LCD_WR_Reg(0x12,start2 >> 8);
	LCD_WR_Reg(0x13,start2 & 0xff);

	LCD_WR_Reg(0x16,(end2-start2) >> 8);
	LCD_WR_Reg(0x17,(end2-start2) & 0xff);
}

/*************************************************
函数名：LCD_Power_On
功能：LCD驱动序列
入口参数：无
返回值：无
*************************************************/
void LCD_Power_On(void)
{
	LCD_Reset();	 

	LCD_WR_Reg(0x01,0x00);		//Start oscillation
	LCD_WR_Reg(0x00,0x00);		//Standby mode cancel
	LCD_WR_Reg(0x03,0x01);		//Software reset operation
	LCD_Delay(10);
	LCD_WR_Reg(0x03,0x00);		//Software reset operation cancel
	LCD_WR_Reg(0x2B,0x00);		//Oscillator frequency adjust setting
	LCD_WR_Reg(0x28,0x18);		//DC/DC clock frequency adjust setting
	LCD_WR_Reg(0x1A,0x05);		//Step up circuit frequensy adjust setting
	LCD_WR_Reg(0x25,0x05);		//Step up factor in step up circuit 2 setting
	LCD_WR_Reg(0x19,0x00);		//VR1 and VR2 regulator factor setting
	LCD_WR_Reg(0x1C,0x73);		//Step up circuit operating current setting
	LCD_WR_Reg(0x24,0x74);		//V18 and VCOM regulator current setting
	LCD_WR_Reg(0x1E,0x01);		//Extra step up circuit1 operation
	LCD_WR_Reg(0x18,0xC1);		//VR1 and VR2 regulator on
	LCD_Delay(10);
	LCD_WR_Reg(0x18,0xE1);		//VCL turn on
	LCD_WR_Reg(0x18,0xF1);		//VGH and VGL turn on
	LCD_Delay(60);
	LCD_WR_Reg(0x18,0xF5);		//DDVDH turn on
	LCD_Delay(60);
	LCD_WR_Reg(0x1B,0x09);		//VS/VDH turn on and set
	LCD_Delay(10);	
	LCD_WR_Reg(0x1F,0x11);		//VCOM amplitude voltage setting
	LCD_WR_Reg(0x20,0x0E);		//VCOMH voltage setting
	LCD_WR_Reg(0x1E,0x81);		//VOCM operation start
	LCD_Delay(10);

	LCD_WR_Reg(0xC1,0x00);		//BRG bit = "0"
	
	LCD_WR_Reg(0x1D,0x08);		//Gate scan direction setting
	LCD_WR_Reg(0x86,0x00);
	LCD_WR_Reg(0x87,0x30);
	LCD_WR_Reg(0x88,0x02);
	LCD_WR_Reg(0x89,0x05);
	LCD_WR_Reg(0x8D,0x01);		//Register set-up mode for one line clock number
	LCD_WR_Reg(0x8B,0x30);		//One line SYSCLK number in one-line scan
	LCD_WR_Reg(0x33,0x01);		//N line inversion setting
	LCD_WR_Reg(0x37,0x01);		//Scanning method setting
	LCD_WR_Reg(0x76,0x00);

	LCD_WR_Reg(0x8F,0x10);
	LCD_WR_Reg(0x90,0x67);
	LCD_WR_Reg(0x91,0x07);
	LCD_WR_Reg(0x92,0x65);
	LCD_WR_Reg(0x93,0x07);
	LCD_WR_Reg(0x94,0x01);
	LCD_WR_Reg(0x95,0x76);
	LCD_WR_Reg(0x96,0x56);
	LCD_WR_Reg(0x97,0x00);
	LCD_WR_Reg(0x98,0x00);
	LCD_WR_Reg(0x99,0x00);
	LCD_WR_Reg(0x9A,0x00);

	LCD_WR_Reg(0x3B,0x01);
	
	LCD_WR_Reg(0x00,0x20);

	LCD_Set_Region(0,0,239,319);
}

/*************************************************
函数名：LCD_Power_Off
功能：LCD关闭序列
入口参数：无
返回值：无
*************************************************/
void LCD_Power_Off(void)
{
	LCD_WR_Reg(0x1e,0x01);
	LCD_WR_Reg(0x1b,0x00);
	LCD_WR_Reg(0x18,0xc0);
	LCD_Delay(10);
	LCD_WR_Reg(0x1c,0x30);
}

/*************************************************
函数名：LCD_Display_On
功能：LCD显示开启序列
入口参数：无
返回值：无
*************************************************/
void LCD_Display_On(void)
{
	LCD_WR_Reg(0x00,0x80);
	LCD_WR_Reg(0x3b,0x01);
	LCD_Delay(100);
	LCD_WR_Reg(0x00,0x20);
}

/*************************************************
函数名：LCD_Display_Off
功能：LCD显示关闭序列
入口参数：无
返回值：无
*************************************************/
void LCD_Display_Off(void)
{
	LCD_WR_Reg(0x00,0x80);
	LCD_Delay(100);
	LCD_WR_Reg(0x3b,0x00);	
}

/**********************************************
函数名：FSMC_LCD_Init
功能：用于FSMC配置
入口参数：无
返回值：无
***********************************************/
void LCD_FSMC_Init(void)
{
  FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef  p;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE); 
  
  p.FSMC_AddressSetupTime = 0x02;
  p.FSMC_AddressHoldTime = 0x00;
  p.FSMC_DataSetupTime = 0x05;
  p.FSMC_BusTurnAroundDuration = 0x00;
  p.FSMC_CLKDivision = 0x00;
  p.FSMC_DataLatency = 0x00;
  p.FSMC_AccessMode = FSMC_AccessMode_B;

  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;	  

  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

  /* Enable FSMC Bank1_SRAM Bank */
  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  
}

/**********************************************
函数名：LCD_Configuration
功能：用于LCD的IO配置
入口参数：延时数
返回值：无
***********************************************/
void LCD_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD |RCC_APB2Periph_GPIOE, ENABLE); 	

  //LCD 背光控制,	  驱动ic背光控制
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;		  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
  //LCD Reset
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;		  
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
  //FSMC的GPIOD管脚
  GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_14 	//D0
  												| GPIO_Pin_15 		//D1
  												| GPIO_Pin_0		//D2
  												| GPIO_Pin_1		//D3
  												| GPIO_Pin_8 		//D13
  												| GPIO_Pin_9 		//D14
  												| GPIO_Pin_10 		//D15  		
  												| GPIO_Pin_7		//NE1
  												| GPIO_Pin_11		//RS
  												| GPIO_Pin_4		//nRD
  												| GPIO_Pin_5;		//nWE
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  //FSMC的GPIOE管脚
  GPIO_InitStructure.GPIO_Pin =   GPIO_Pin_7		//D4
  												| GPIO_Pin_8 		//D5
  												| GPIO_Pin_9 		//D6
  												| GPIO_Pin_10 		//D7
  												| GPIO_Pin_11 		//D8
  												| GPIO_Pin_12 		//D9
  												| GPIO_Pin_13		//D10
  												| GPIO_Pin_14 		//D11
  												| GPIO_Pin_15; 	//D12  												
  GPIO_Init(GPIOE, &GPIO_InitStructure); 
}

/**********************************************
函数名：LCD_Clear
功能：将Lcd整屏擦为指定颜色
入口参数：color 指定Lcd全屏颜色 RGB(5-6-5)
返回值：无
***********************************************/
void LCD_Clear(u16 Color)
{
	u32 temp;  
	
	LCD_Set_XY(0,0);  
	for (temp = 0; temp < 320*240; temp++)
	{
		LCD_WR_Data(Color);
	} 
}

/****************************************************************************
* 名    称：Fill
* 功    能：填充一块颜色
* 入口参数：填充起始点，填充的长宽，填充颜色
* 出口参数：无
****************************************************************************/
void LCD_Fill(u16 x,u16 y,u16 b,u16 h,u16 Color)
{
	u32 temp;  
	
	LCD_Set_Region(x,y,x+b-1,y+h-1);
	LCD_Set_XY(x,y);  
	
	for (temp = 0; temp < b*h; temp++)
	{
		LCD_WR_Data(Color);
	} 
}

/*************************************************
函数名：LCD_Init
功能：初始化启动lcd
入口参数：无
返回值：无
*************************************************/
void LCD_Init(void)
{	
	LCD_FSMC_Init();
	LCD_Delay(500);	 
	LCD_Configuration();
	LCD_HX8312_On();
	LCD_Delay(0xfffff);
	LCD_Light_On();
	LCD_Power_On();
	
}

/************************************************
函数名：DrawPixel
功能：在某个坐标上绘制一点
入口参数：xy坐标和颜色
返回值：无
************************************************/
void DrawPixel(u16 x, u16 y, u16 Color)
{
	LCD_Set_XY(x,y);  
	LCD_WR_Data(Color);
}

/************************************************
函数名：PutChar
功能：在某个坐标上写一个ASCII表内的字符
入口参数：xy坐标，字和颜色
返回值：无
************************************************/
void PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor)
{
  u16 i=0;
  u16 j=0;  
  u8 temp=0;

  LCD_Set_Region(0,0,239,319);
  
  for (i=0;i<16;i++)
  {
    temp=ascii_8x16[((c-0x20)*16)+i];
    for (j=0;j<8;j++)
    {
      if ( (temp >> 7-j) & 0x01 == 0x01)
        {
          DrawPixel(x+j,y+i,charColor); // 字符颜色
        }
        else
        {
          DrawPixel(x+j,y+i,bkColor); // 背景颜色
        }
    }
  }
}
/****************************************************************************
* 名    称：DisplayStringLine
* 功    能：显示最多40个字符一行在LCD上
* 入口参数：Line 行数 *ptr指向字符串的指针 charColor字符颜色 bkColor背景颜色
* 出口参数：无
****************************************************************************/
void DisplayStringLine(u8 Line, u8 *ptr, u16 charColor, u16 bkColor)
{
  u32 i = 0;
  u16 refcolumn = 0;

  LCD_Set_Region(0,0,239,319);
  
  while ((*ptr != 0) & (i < 40))
  {
    PutChar(refcolumn, Line, *ptr, charColor, bkColor);
    refcolumn += 8;
    ptr++;
    i++;
  }
}

/****************************************************************************
* 名    称：void Show_Bmp16bit(u16 x,u16 y,u16 b,u16 h,bu16 *addr)
* 功    能：显示16位数据的bmp图片
* 入口参数：显示的起始xy坐标，图片长宽，数据地址
* 出口参数：无  
****************************************************************************/
void Show_Bmp16bit(u16 x,u16 y,u16 b,u16 h,u8 *addr)
{
	u16 low,hig;
	u16 a,c;

	LCD_Set_Region(0,0,239,319);
	
	for(c=y;c<y+h;c++)
	{
		for(a=x;a<x+b;a++)
		{
			low=*addr++;
			hig=*addr++;
			hig=hig<<8;
			low=low+hig;		
			DrawPixel(a,c,low);
		}	
	}
}




