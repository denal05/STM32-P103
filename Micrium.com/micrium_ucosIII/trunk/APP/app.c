/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "includes.h"     
#include "app_cfg.h"                       
#include "Lcd_font.h"

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/

#define White          0xFFFF
#define Black          0x0000
#define Grey           0xF7DE
#define Blue           0x001F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

const u16 Color[8]={Blue,Red,Green,Cyan,Magenta,Yellow,Grey,White};

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/
static  CPU_STK   App_TaskStart_Stk[APP_TASKSTART_STK_SIZE]; 
static  CPU_STK   App_Task1_Stk[APP_TASK1_STK_SIZE]; 
static  CPU_STK   App_Task2_Stk[APP_TASK2_STK_SIZE]; 
static  CPU_STK   Uart_Task_Stk[UART_TASK_STK_SIZE]; 


static  OS_TCB          AppTaskStartTCB; 
static  OS_TCB          AppTask1TCB; 
static  OS_TCB          AppTask2TCB; 
static  OS_TCB          AppTaskUART; 

static  CPU_CHAR       App_LCDLine0[21];
static  CPU_CHAR       App_LCDLine1[21];
static  CPU_CHAR       App_LCDLine2[21];
static  CPU_CHAR       App_LCDLine3[21];
static  CPU_CHAR       App_LCDLine4[21];
static  CPU_CHAR       App_LCDLine5[21];
static  CPU_CHAR       App_LCDLine6[21];
static  CPU_CHAR       App_LCDLine7[21];
static  CPU_CHAR       App_LCDLine8[21];
static  CPU_CHAR       App_LCDLine9[21];
static  CPU_CHAR       App_LCDLine10[21];

OS_SEM TouchSem;

/*
*********************************************************************************************************
*                                       EXTERN GLOBAL VARIABLES
*********************************************************************************************************
*/

extern u32 x_sum,y_sum;

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/
static void  App_TaskCreate(void);	
static void  App_TaskStart(void *p_arg);
static void  App_Task1(void *p_arg);
static void  App_Task2(void *p_arg);
static void  Task_Uart(void *p_arg);


static void  App_DispScr_SignOn(void);

void LCD_Fill(u16 x,u16 y,u16 b,u16 h,u16 Color);
void PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor);
void DisplayStringLine(u8 Line, u8 *ptr, u16 charColor, u16 bkColor);

static  void  App_FormatDec        (char  *pstr,
                                    CPU_INT32U   value,
                                    CPU_INT08U   digits);
/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*********************************************************************************************************
*/
int main(void)
{
 	OS_ERR  err;  
																	
	OSInit(&err);                                                  		
																	
	BSP_Init();                                                 	
	
        CPU_Init();

        SystemInit();
        
        OSSemCreate(&TouchSem, "Touch Semaphore", 1, &err);
        
	OSSchedRoundRobinCfg((CPU_BOOLEAN)DEF_TRUE, 
                     	 (OS_TICK    )10,
                     	 (OS_ERR    *)&err);

	OSTaskCreate((OS_TCB     *)&AppTaskStartTCB, /* Create the start task */
                 (CPU_CHAR   *)"App Task Start",
                 (OS_TASK_PTR )App_TaskStart, 
                 (void       *)0,
                 (OS_PRIO     )APP_TASKSTART_PRIO,
                 (CPU_STK    *)&App_TaskStart_Stk[0],
                 (CPU_STK_SIZE)APP_TASKSTART_STK_SIZE / 10,
                 (CPU_STK_SIZE)APP_TASKSTART_STK_SIZE,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
				 																                                     

    OSStart(&err);

	return (0);
}

/*
*********************************************************************************************************
*  开始任务，用于环境初始化及创建其他任务
*********************************************************************************************************
*/
void App_TaskStart(void *p_arg)
{
	CPU_INT32U  cpu_clk_freq;
        CPU_INT32U  cnts;
	OS_ERR      err;

	(void)p_arg;

        // Initialize LCD
        ////LCD_Init();
        COM2_Init();
        SPI_Touch_Init();
        
	cpu_clk_freq = BSP_CPU_ClkFreq();
    cnts         = cpu_clk_freq / (CPU_INT32U)OSCfg_TickRate_Hz;
	OS_CPU_SysTickInit(cnts);

#if OS_CFG_STAT_TASK_EN > 0u
    OSStatTaskCPUUsageInit(&err); /* Compute CPU capacity w no task running */
#endif

	CPU_IntDisMeasMaxCurReset();

        ////App_DispScr_SignOn();
        
	App_TaskCreate();

	OSTaskDel((OS_TCB     *)&AppTaskStartTCB,
			  &err);
}


/*
*********************************************************************************************************
*  Task1
*********************************************************************************************************
*/
void App_Task1(void *p_arg)
{
	OS_ERR      err;

	while (1) {
          OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
          App_DispScr_SignOn();
          OSTimeDlyHMSM(0, 0, 1, 0, OS_OPT_TIME_HMSM_STRICT, &err);
	}
	
}

/*
*********************************************************************************************************
*  Task2
*********************************************************************************************************
*/
void App_Task2(void *p_arg)
{
  	OS_ERR      err;
        long i;
        CPU_CHAR       App_LCDLine[21];
        
	while (1) {
          OSTimeDlyHMSM(0, 0, 0, 500, OS_OPT_TIME_HMSM_STRICT, &err);

          
          OSSemPend (&TouchSem, 0, OS_OPT_PEND_BLOCKING, (CPU_TS*)0, &err);
                    App_DispScr_SignOn();
          App_FormatDec(&App_LCDLine[2], x_sum, 8);
          App_FormatDec(&App_LCDLine[10], y_sum, 8);
          DisplayStringLine(20*10, App_LCDLine, White, Blue);
          
          x_sum = 0; y_sum = 0;
          OSTimeDlyHMSM(0, 0, 0, 200, OS_OPT_TIME_HMSM_STRICT, &err);
	}
}
/*
*********************************************************************************************************
*  Task3
*********************************************************************************************************
*/
void Task_Uart(void *p_arg)
{
  	OS_ERR      err;
        
	while (1) {
          Debug("Hello from UART task\n\r");
          OSTimeDlyHMSM(0, 0, 0, 200, OS_OPT_TIME_HMSM_STRICT, &err);
	}
}




/*
*********************************************************************************************************
*                                            App_TaskCreate()
*
* Description : Create the application tasks.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : App_TaskStart().
*
* Note(s)     : none.
*********************************************************************************************************
*/

void App_TaskCreate(void)
{
    OS_ERR  err; 
/*    
	OSTaskCreate((OS_TCB     *)&AppTask1TCB,               
                 (CPU_CHAR   *)"App Task1",
                 (OS_TASK_PTR )App_Task1, 
                 (void       *)0,
                 (OS_PRIO     )APP_TASK1_PRIO,
                 (CPU_STK    *)&App_Task1_Stk[0],
                 (CPU_STK_SIZE)APP_TASK1_STK_SIZE / 10,
                 (CPU_STK_SIZE)APP_TASK1_STK_SIZE,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);

	OSTaskCreate((OS_TCB     *)&AppTask2TCB,               
                 (CPU_CHAR   *)"App Task2",
                 (OS_TASK_PTR )App_Task2, 
                 (void       *)0,
                 (OS_PRIO     )APP_TASK2_PRIO,
                 (CPU_STK    *)&App_Task2_Stk[0],
                 (CPU_STK_SIZE)APP_TASK2_STK_SIZE / 10,
                 (CPU_STK_SIZE)APP_TASK2_STK_SIZE,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
        */
	OSTaskCreate((OS_TCB     *)&AppTaskUART,               
                 (CPU_CHAR   *)"Task UART",
                 (OS_TASK_PTR )Task_Uart, 
                 (void       *)0,
                 (OS_PRIO     )UART_TASK_PRIO,
                 (CPU_STK    *)&Uart_Task_Stk[0],
                 (CPU_STK_SIZE)UART_TASK_STK_SIZE / 10,
                 (CPU_STK_SIZE)UART_TASK_STK_SIZE,
                 (OS_MSG_QTY  )0,
                 (OS_TICK     )0,
                 (void       *)0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);      
}

void LCD_Fill(u16 x,u16 y,u16 b,u16 h,u16 Color)
{
	u32 temp;  
	
	LCD_SetRegion(x,y,x+b-1,y+h-1,FALSE);
	LCD_SetXY(x,y);  

	LCD_BlukWriteDataStart();
	for (temp = 0; temp < b*h; temp++)
	{
		LCD_BulkWriteData(Color);
	} 
}

void PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor)
{
  u16 i=0;
  u16 j=0;  
  u8 temp=0;

  LCD_SetRegion(0,0,239,319,FALSE);
  
  for (i=0;i<16;i++)
  {
    temp=ascii_8x16[((c-0x20)*16)+i];
    for (j=0;j<8;j++)
    {
      if ( (temp >> 7-j) & 0x01 == 0x01)
        {
          LCD_DrawPoint(x+j,y+i,charColor); // 字符颜色
        }
        else
        {
          LCD_DrawPoint(x+j,y+i,bkColor); // 背景颜色
        }
    }
  }
}

void DisplayStringLine(u8 Line, u8 *ptr, u16 charColor, u16 bkColor)
{
  u32 i = 0;
  u16 refcolumn = 0;

  LCD_SetRegion(0,0,239,319,FALSE);
  
  while ((*ptr != 0) & (i < 40))
  {
    PutChar(refcolumn, Line, *ptr, charColor, bkColor);
    refcolumn += 8;
    ptr++;
    i++;
  }
}

/*
*********************************************************************************************************
*                                          App_DispScr_SignOn()
*
* Description : Display uC/OS-III system information on the LCD.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : App_TaskUserIF().
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  App_DispScr_SignOn (void)
{
    CPU_INT32U  value;
    OS_ERR  err;

    OS_TCB      *ptcb;
    CPU_CHAR    *line;
    
    ptcb = OSTCBCurPtr;
    
    Str_Copy(App_LCDLine0, "  Micrium uC/OS-III  ");
    Str_Copy(App_LCDLine1, "ST STM32 (Cortex-M3)");

    Str_Copy(App_LCDLine2, "                    ");
    Str_Copy(App_LCDLine3, "                    ");
    Str_Copy(App_LCDLine3, "  uC/OS-III: Vx.yy  ");
    value            = (CPU_INT16U)OSVersion(&err);
    App_LCDLine3[14] =  value / 10000 + '0';
    App_LCDLine3[16] = (value % 10000) / 1000 + '0';
    App_LCDLine3[17] = (value %  1000) / 100 + '0';

    Str_Copy(App_LCDLine4, "  TickRate:   xxxx  ");
    value = (CPU_INT32U)OSCfg_TickRate_Hz;
    App_FormatDec(&App_LCDLine4[14], value, 4);

    Str_Copy(App_LCDLine5, "  CPU Usage:xx %    ");
    value            = (CPU_INT32U)OSStatTaskCPUUsage;
    App_LCDLine5[12] = (value / 100) + '0';
    App_LCDLine5[13] = (value % 10) + '0';

    Str_Copy(App_LCDLine6, "  CPU Speed:xx MHz  ");
    value            = (CPU_INT32U)BSP_CPU_ClkFreq() / 1000000L;
    App_LCDLine6[12] = (value / 10) + '0';
    App_LCDLine6[13] = (value % 10) + '0';

    Str_Copy(App_LCDLine7, "  #Ticks: xxxxxxxx  ");
    value = (CPU_INT32U)OSTickCtr;
    App_FormatDec(&App_LCDLine7[10], value, 8);

    Str_Copy(App_LCDLine8, "  #CtxSw: xxxxxxxx  ");
    value = (CPU_INT32U)OSTaskCtxSwCtr;
    App_FormatDec(&App_LCDLine8[10], value, 8);
     
    Str_Copy(App_LCDLine9, "                    ");

    line = App_LCDLine10;
    
    value = ptcb->Prio; 
    
    line[0] = ' ';
    line[1] = ' ';
    line[2] = ' ';
    line[3] = value / 10 + '0';
    line[4] = value % 10 + '0';
    line[5] = ' ';
    
    Str_Copy_N(line + 6, ptcb->NamePtr, 14);
    
    DisplayStringLine(0*10, App_LCDLine0, White, Blue);
    DisplayStringLine(1*15, App_LCDLine1, White, Blue);    
    DisplayStringLine(2*15, App_LCDLine2, White, Blue);
    DisplayStringLine(3*15, App_LCDLine3, White, Blue);
    DisplayStringLine(4*15, App_LCDLine4, White, Blue);
    DisplayStringLine(5*15, App_LCDLine5, White, Blue);
    DisplayStringLine(6*15, App_LCDLine6, White, Blue);
    DisplayStringLine(7*15, App_LCDLine7, White, Blue);
    DisplayStringLine(8*15, App_LCDLine8, White, Blue);
    DisplayStringLine(9*15, App_LCDLine9, White, Blue);
    DisplayStringLine(10*15, App_LCDLine10, White, Blue);    
}

/*
*********************************************************************************************************
*                                      App_FormatDec()
*
* Description : Convert a decimal value to ASCII (without leading zeros).
*
* Argument(s) : pstr            Pointer to the destination ASCII string.
*
*               value           Value to convert (assumes an unsigned value).
*
*               digits          The desired number of digits.
*
* Return(s)   : none.
*
* Caller(s)   : various.
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  App_FormatDec (char *pstr, CPU_INT32U value, CPU_INT08U digits)
{
    char   i;
    CPU_INT32U   mult;
    CPU_BOOLEAN  found;
    CPU_INT32U   nbr;


    found = DEF_NO;
    mult  = 1;
    for (i = 0; i < (digits - 1); i++) {
        mult *= 10;
    }
    while (mult > 0) {
        nbr = value / mult;
        if (found == DEF_NO) {
            if (nbr != 0) {
                found = DEF_YES;
                *pstr = nbr + '0';
            } else{
                if (mult == 1) {
                    *pstr = '0';
                } else {
                    *pstr = ' ';
                }
            }
        } else {
            *pstr = nbr + '0';
        }
        pstr++;
        value %= mult;
        mult  /= 10;
    }
}