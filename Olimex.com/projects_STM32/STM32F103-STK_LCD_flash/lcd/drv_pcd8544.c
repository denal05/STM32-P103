#include "drv_pcd8544.h"

/*************************************************************************
 * Function Name: PCD8544_PowerUp
 * Parameters: const Int8U * pData
 *
 * Return: none
 *
 * Description: Power up initialization
 *
 *************************************************************************/
void PCD8544_PowerUp (const Int8U * pData)
{
	Int32U i;

  // Init Peripherals and reset LCD
  PCD8544_Init();
  // function set PD = 0 and V = 0, select extended instruction set (H = 1 mode)
  PCD8544_WrCmd(0x21);
  // // Set LCD Voltage to about 7V.
  PCD8544_WrCmd(0xC8);
  // Adjust voltage bias.
  PCD8544_WrCmd(0x13);
  // function set PD = 0 and V = 0, select normal instruction set (H = 0 mode)
  PCD8544_WrCmd(0x20);
  // Init DDRAM
  if(pData == NULL)
  {
    for(i = 0; i < (X_PIX_SIZE * Y_PIX_SIZE)/8; i++)
    {
      PCD8544_WrData(0x00);
    }
  }
  else
  {
    for(i = 0; i < (X_PIX_SIZE * Y_PIX_SIZE)/8; i++)
    {
      PCD8544_WrData(*pData++);
    }
  }
  // display control set normal mode (D = 1 and E = 0)
  PCD8544_WrCmd(0x0C);

  // initialize font
  Lucida_Console_6_8_6.H_Size = 6;
  Lucida_Console_6_8_6.V_Size = 8;
  Lucida_Console_6_8_6.CharacterOffset = 0;
  Lucida_Console_6_8_6.CharactersNuber = 255;
  Lucida_Console_6_8_6.pFontStream = (pInt8U)TextStream0;
  Lucida_Console_6_8_6.pFontDesc = "Lucida Console 6 (8x6)";
}


/*************************************************************************
 * Function Name: PCD8544_StrShow
 * Parameters: Int8U X, Int8U Y, const Int8U * pData
 *
 * Return: none
 *
 * Description: Show zero terminate string
 *
 *************************************************************************/
void PCD8544_StrShow (Int8U X, Int8U Y, const Int8U * pData)
{
pInt8U pFontData;
Int32U ch;
Int32U i;
  // parameter check
  assert(pData);
  // Set Address
  X *= FONT.H_Size;
  PCD8544_SetAddr(X,Y);
  // Fill LCD Data memory
  while(*pData)
  {
    // find character start address
    assert(*pData >= FONT.CharacterOffset);
    assert(*pData <  FONT.CharactersNuber + FONT.CharacterOffset);
    ch = *pData - FONT.CharacterOffset;
    pData++;
    pFontData = FONT.pFontStream + (ch * ((FONT.H_Size * FONT.V_Size)/8));
    for(i = FONT.H_Size; i; --i)
    {
      // print character
      PCD8544_WrData(*pFontData++);
    }
  }
}

/*************************************************************************
 * Function Name: PCD8544_LoadData
 * Parameters: Int8U X, Int8U Y, Int32U Size, const Int8U * pData
 *
 * Return: none
 *
 * Description: Load raw data in the LDC data memory
 *
 *************************************************************************/
void PCD8544_LoadData (Int8U X, Int8U Y, Int32U Size, const Int8U * pData)
{
  // parameter check
  assert(pData);
  // Set Address
  PCD8544_SetAddr(X,Y);
  // Fill LCD Data memory
  while(Size--)
  {
    PCD8544_WrData(*pData++);
  }
}

/*************************************************************************
 * Function Name: PCD8544_SetAddr
 * Parameters: Int8U X, Int8U Y
 *
 * Return: none
 *
 * Description: Set X and Y address of RAM
 *
 *************************************************************************/
static void PCD8544_SetAddr (Int8U X, Int8U Y)
{
  assert(Y < (Y_PIX_SIZE/8));
  assert(X < (X_PIX_SIZE/8));
  // Set Y address
  PCD8544_WrCmd(0x40 | Y);
  // Set X address
  PCD8544_WrCmd(0x80 | X);
}

