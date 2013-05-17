/**
  @page SpeexVocoder_STM32-SK AN2812 SpeexVocoder_STM32-SK Readme File
  
  @verbatim
  ******************** (C) COPYRIGHT 2009 STMicroelectronics *******************
  * @file SpeexVocoder_STM32-SK/readme.txt 
  * @author   MCD Application Team
  * @version  V2.0.0
  * @date     04/27/2009
  * @brief    Description of the AN2812: Vocoder demonstration using a Speex 
  *           audio codec on STM32F101xx and STM32F103xx microcontrollers.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Description

This firmware has been developped on the IAR board STM32-SK. It gives the STM32 
Vocoder solution using the Speex codec. It provides a real time vocoder, a 
playback and a recorder & player demonstrations.

@par Directory contents 

  - inc: containing the user header files  
    - SpeexVocoder_STM32-SK/inc/stm32f10x_conf.h     Library Configuration files
    - SpeexVocoder_STM32-SK/inc/stm32f10x_it.h       Interrupt handlers header files
    - SpeexVocoder_STM32-SK/inc/main.h               main header file
    - SpeexVocoder_STM32-SK/inc/vocoder.h            vocoder header file
    - SpeexVocoder_STM32-SK/inc/voice.h              A sample voice encoded with Speex codec
    - SpeexVocoder_STM32-SK/inc/drv_hd44780.h        LCD header file, this file is a part of the IAR LCD driver
    - SpeexVocoder_STM32-SK/inc/drv_hd44780_l.h      LCD low level I/O function driver file, this file is a part of the IAR LCD driver
    - SpeexVocoder_STM32-SK/inc/drv_hd44780_cnfg.h   LCD driver common definitions file, this file is a part of the IAR LCD driver
    - SpeexVocoder_STM32-SK/inc/includes.h           LCD drievr header file
    
  - src: containg the user source files  
    - SpeexVocoder_STM32-SK/src/vocoder.c           Vocoder source file 
    - SpeexVocoder_STM32-SK/src/stm32f10x_it.c      Interrupt handlers
    - SpeexVocoder_STM32-SK/src/main.c              main program
    - SpeexVocoder_STM32-SK/src/drv_hd44780.c       STM32-SK board lcd driver developped by IAR 
    - SpeexVocoder_STM32-SK/src/drv_hd44780_l.c     STM32-SK board lcd low level I/O functions developped by IAR 
                                 
@par Hardware and Software environment 

    - This example runs on STM32F10x High-Density, STM32F10x Medium-Density and
      STM32F10x Low-Density Devices.
      
    - This example has been tested with STMicroelectronics IAR STM32-SK board.
    
    - Connect a microphone & a headphone to the IAR STM32-SK board to use the demo.
            
@par How to use it? 

In order to load the Speex Vocoder code, you have do the following:

 - RVMDK: 
    - Open the SpeexVocoder_IAR.Uv2 project project
    - Rebuild all files: Project->Rebuild all target files
    - Load project image: Debug->Start/Stop Debug Session
    - Run program: Debug->Run (F5)

    
 - EWARMv5 
    - Open the SpeexVocoder_IAR.eww workspace
    - Rebuild all files: Project->Rebuild all
    - Load project image: Project->Debug
    - Run program: Debug->Go(F5)

 - RIDE 
    - Open the SpeexVocoder_IAR.rprj project
    - Rebuild all files: Project->build project
    - Load project image: Debug->start(ctrl+D)
    - Run program: Debug->Run(ctrl+F9)  

@note
 - Low-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 16 and 32 Kbytes.
 - Medium-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 32 and 128 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.    

 * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
 */
