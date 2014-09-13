/**
  ******************************************************************************
  * @file SpeexVocoder_STM32F103-STK/inc/voice.h 
  * @author  MCD Application Team
  * @version  V2.0.0
  * @date  04/27/2009
  * @brief  This is a male voice sample encoded with Speex @ 8kbps
  *            The original file has the following properities:
  *               - audio sample rate : 8 kHz
  *               - audio sample size : 16 bit
  *               - channels          : 1 (mono)
  *               - audio format      : PCM
  *               - length            : 6 s
  *               The compression rate is @ 16kbps
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __VOICE_H
#define __VOICE_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

const uint8_t male_voice[] = {
	0x1b,0x98,0x89,
	0xd0,0x00,0x39,0xce,0x70,0x10,0x52,0xc4,
	0x38,0xbc,0x4e,0xcb,0x9c,0x07,0xc7,0x39,
	0xce,0x1b,0x89,0x66,0x63,0x80,0xa1,0x0a,
	0x51,0xf2,0x94,0x90,0x59,0x1b,0x45,0x43,
	0xfe,0x43,0x8b,0x41,0x00,0x1d,0xdd,0xe4,
	0x5b,0x3c,0xc8,0x2a,0x07,0xae,0x31,0x63,
	0xa7,0xf7,0x39,0x2c,0x60,0xf3,0x98,0xa9,
	0x5b,0x1b,0x8c,0xa6,0x58,0xdc,0x08,0x9f,
	0x47,0x1e,0x67,0x44,0xb4,0x20,0xea,0xa8,
	0x1a,0x27,0x8d,0x93,0xe0,0x1b,0x99,0x6e,
	0x50,0x7c,0xe3,0xdf,0x45,0x7e,0x6d,0xb4,
	0x22,0x2f,0x0c,0x00,0x1e,0x2b,0x94,0x20,
	0x00,0x1d,0xcc,0xa4,0x58,0x9c,0x03,0xff,
	0xc1,0x9e,0x68,0x3f,0xa3,0xef,0x0d,0xfa,
	0x04,0x2d,0x30,0xa5,0xe0,0x1d,0xdf,0x74,
	0x53,0x5c,0xc1,0x69,0xec,0x8e,0x58,0xac,
	0x2a,0xef,0x33,0x79,0xff,0x83,0x83,0xe2,
	0xd7,0x19,0xde,0xe6,0x5a,0x5c,0x81,0x65,
	0x43,0x4e,0x6c,0x83,0x2f,0x20,0xe9,0x8a,
	0x41,0xd3,0x84,0x00,0x1f,0x1d,0xc6,0xe4,
	0x5a,0xfc,0xdf,0x8a,0x3a,0x8e,0x78,0x0b,
	0xa4,0x77,0x2d,0x01,0xc1,0x3f,0x97,0xbf,
	0xa0,0x1b,0xdd,0xc2,0x64,0x03,0x1c,0xe8,
	0x0c,0xce,0x72,0x55,0x29,0xaf,0x1f,0x02,
	0x6d,0x1f,0x9c,0x22,0x40,0x1b,0xde,0xc2,
	0x7f,0xbc,0x7e,0x43,0x79,0xfe,0x55,0x2c,
	0x42,0x5f,0x23,0x02,0xd3,0x6b,0x9d,0x21,
	0x56,0x1e,0xde,0x00,0x91,0x43,0x2e,0x98,
	0x44,0x54,0x8c,0xfb,0x08,0x3c,0x4a,0xa6,
	0x41,0x03,0x96,0xbd,0x5f,0x1f,0x23,0x87,
	0x1d,0x3c,0x1b,0x2e,0x72,0xeb,0x34,0x72,
	0x38,0x58,0x45,0x33,0xb3,0x16,0x13,0x4a,
	0xc8,0x1c,0xd8,0x45,0x5a,0x9c,0x1d,0x32,
	0x14,0x48,0x5c,0xe9,0xad,0xc7,0x1f,0x02,
	0x93,0x7b,0x95,0x65,0xd3,0x1c,0xc4,0x6d,
	0x79,0x30,0x2d,0x0f,0xd8,0xb1,0x05,0x61,
	0x5a,0x55,0xb8,0x5e,0x6d,0x2f,0x64,0xef,
	0xa3,0x19,0xf2,0x59,0x69,0x57,0x87,0x36,
	0xb3,0x0e,0x3e,0xb4,0x6e,0x67,0x88,0x3e,
	0x66,0x7f,0x09,0x34,0x6b,0x19,0x28,0xd7,
	0x4c,0x51,0x28,0x2e,0x5c,0x9d,0xaa,0x17,
	0x8a,0x53,0xd8,0x28,0x5d,0x23,0x6e,0xc9,
	0x27,0x19,0x21,0xd7,0x48,0xd8,0x0a,0x21,
	0x74,0x6d,0xdc,0xe6,0xb2,0x31,0xc6,0x37,
	0x47,0x15,0x61,0x85,0x90,0x19,0x21,0xd7,
	0x38,0xa6,0x7d,0x42,0x8c,0x33,0x66,0xee,
	0x76,0x27,0xcf,0xa8,0xeb,0x0b,0x65,0x28,
	0x5e,0x18,0xa0,0xcb,0x58,0x67,0x0d,0xfd,
	0xcc,0x1b,0x91,0x0c,0x92,0x11,0xdb,0x10,
	0xd6,0xfa,0x14,0xa1,0xd5,0x1c,0xcf,0xc1,
	0x90,0x46,0x25,0x40,0x6b,0xa8,0x00,0xac,
	0x25,0x5f,0x16,0x05,0x54,0xdf,0xb5,0xa9,
	0xea,0x1e,0xc9,0xa9,0xb6,0xe4,0x1c,0x7c,
	0x13,0x62,0x0e,0x40,0x85,0xb7,0xdc,0x0f,
	0x1c,0xd6,0xc2,0x49,0x23,0x1e,0xdb,0xb9,
	0xb6,0x96,0x0b,0x58,0xa3,0x45,0x07,0xcd,
	0xbb,0xcd,0x15,0x9b,0x52,0x1c,0x00,0x1c,
	0x4e,0x1f,0xb7,0xcd,0xce,0xfb,0x6c,0x53,
	0x5b,0x25,0x0c,0xa7,0x11,0x57,0x09,0x00,
	0xba,0xc9,0x41,0xe7,0xb0,0x1f,0xb3,0x91,
	0xa7,0xa9,0x44,0x29,0x8b,0x3b,0x9d,0x5c,
	0x7d,0xa9,0x85,0xf8,0xb0,0xcd,0xd9,0x0b,
	0x42,0x1d,0x97,0xef,0xa6,0x96,0xe5,0xd4,
	0xd7,0xbd,0xad,0xe2,0x39,0xad,0x09,0x35,
	0xd3,0xf7,0x63,0xe1,0x0e,0x1c,0x82,0x07,
	0xa6,0xdf,0x10,0x63,0x34,0xef,0x0c,0xe7,
	0x5d,0xba,0xd0,0x34,0x4e,0xe5,0x80,0xa2,
	0xda,0x1c,0x91,0xe3,0x95,0x6d,0x74,0xd5,
	0x43,0xbf,0xbf,0xa3,0xd9,0x6f,0x0a,0x6a,
	0xd4,0xf8,0xc5,0x8f,0x38,0x1f,0x89,0xdb,
	0x67,0xe7,0xd2,0xdb,0x34,0x67,0x8f,0x5e,
	0x11,0xc2,0x42,0x82,0xcb,0x2b,0xce,0x3b,
	0x2c,0x1f,0x8c,0x73,0x2a,0x3e,0xcb,0x98,
	0x85,0xe8,0xbc,0x99,0x20,0xcf,0x9a,0x72,
	0xcb,0x7a,0x60,0x96,0xd2,0x1f,0x8f,0xf3,
	0x23,0x9e,0x01,0xca,0x5c,0xd7,0x19,0x2c,
	0x2f,0x39,0x26,0x02,0x4f,0x8f,0x74,0x93,
	0x8b,0x19,0x88,0x63,0x4e,0x8d,0xae,0x87,
	0xc6,0x1d,0xfd,0xe1,0x32,0x5f,0x09,0x12,
	0xd3,0x5b,0x18,0x8d,0xf8,0x1f,0x47,0xe3,
	0x3a,0xfb,0x74,0x08,0xf9,0xb4,0xad,0x10,
	0x26,0x9f,0xef,0x8e,0x7d,0x50,0xe9,0x64,
	0xf6,0x1f,0x4e,0x07,0x3a,0x86,0xbd,0xc7,
	0x55,0x47,0xb3,0x04,0x2a,0xab,0xc2,0xf3,
	0x73,0x5e,0x6f,0x76,0x59,0x1f,0x5e,0x63,
	0x1a,0xcf,0x6f,0x23,0xdd,0x99,0xe0,0x3c,
	0x2e,0xc1,0xc1,0x12,0x52,0x00,0x49,0x00,
	0xaa,0x1c,0x6a,0x51,0x1b,0x5b,0xbd,0x5d,
	0xed,0xa5,0x93,0x99,0x67,0x44,0x57,0xdc,
	0x31,0x64,0xd5,0xd2,0x19,0x1a,0x72,0x11,
	0x39,0x3c,0x24,0xee,0x55,0x89,0x56,0xec,
	0xc1,0x87,0x28,0x02,0x7e,0x15,0x00,0x4c,
	0x40,0x1a,0x62,0xb3,0x6a,0xb2,0x7a,0xf1,
	0xec,0x7e,0x32,0xe7,0x38,0x66,0x62,0x1e,
	0x00,0xc7,0x94,0x1c,0xc9,0x1a,0x66,0x81,
	0x62,0xbe,0x2c,0xea,0x74,0x5e,0x52,0xdb,
	0x2c,0x50,0x89,0x48,0x93,0x3b,0xb6,0xfa,
	0x0e,0x1c,0xc8,0x0f,0x69,0xfd,0x31,0xef,
	0xe9,0x49,0xdf,0x5b,0xa6,0x3b,0x76,0x50,
	0x11,0x8f,0xce,0x42,0x17,0x1f,0xa4,0x49,
	0x59,0xce,0xb2,0x0c,0x4c,0x98,0x96,0x25,
	0x07,0xc0,0x83,0x76,0x5d,0x60,0x07,0x39,
	0xce,0x1f,0x64,0xa2,0xa3,0xed,0xd9,0x3f,
	0x43,0xe4,0x6c,0xb7,0xa1,0xa2,0x52,0x61,
	0xde,0xa9,0xee,0xd8,0xf6,0x1f,0xce,0x2e,
	0x76,0x89,0xc7,0x0d,0x01,0x31,0xac,0xa4,
	0x43,0x13,0x68,0x8a,0xf1,0x1f,0x8c,0xbe,
	0xa9,0x1c,0x1d,0xb6,0x81,0xdc,0xa2,0xa1,
	0xf2,0xfd,0xd1,0x64,0xab,0xa7,0x28,0x3a,
	0x40,0x3f,0x94,0x2b,0x1f,0x1a,0x14,0xa7,
	0x47,0x7c,0xb9,0xcd,0xf3,0x1e,0x50,0x01,
	0x9c,0xd3,0xc6,0xe6,0xf9,0x05,0xa9,0xfd,
	0xfb,0x18,0x04,0x57,0x37,0x57,0x4a,0x0a,
	0x2b,0xe7,0x50,0x7d,0x1c,0x40,0xea,0xad,
	0xc5,0xb1,0xbf,0x93,0xf0,0x1c,0x14,0x6f,
	0x43,0x89,0x42,0x01,0x8c,0x9e,0x26,0x0f,
	0xa6,0x15,0xc7,0x4e,0x3f,0xd5,0xb5,0xba,
	0x16,0x1f,0xbd,0xb3,0x5b,0x81,0x7a,0x10,
	0x5e,0x96,0xb9,0xac,0x2d,0xb5,0x49,0x78,
	0xd7,0x15,0xb6,0xc2,0x49,0x1f,0xbf,0x4b,
	0x8e,0xbc,0x2a,0x8e,0x75,0x86,0xf9,0x39,
	0x2a,0x02,0x4d,0x5e,0x30,0xe2,0x5b,0x81,
	0x45,0x1f,0xb6,0xcb,0xbf,0xdb,0x39,0xce,
	0x73,0x99,0x60,0x12,0x39,0xc9,0x99,0x51,
	0x9c,0xe6,0xce,0xf1,0x76,0x1a,0x76,0x4b,
	0x87,0xed,0x81,0x46,0x42,0x46,0x92,0x08,
	0x25,0xf9,0x0a,0x40,0xbc,0xff,0xef,0x9f,
	0xed,0x19,0x33,0xd5,0x77,0xf7,0xe6,0xc3,
	0xa2,0x9e,0x55,0x6c,0xe6,0x19,0xdd,0x83,
	0x7a,0xef,0x86,0xa0,0x11,0x1a,0x66,0x3b,
	0x48,0xfe,0xdb,0xbe,0x54,0x8f,0x44,0xb5,
	0x1e,0xb4,0x51,0x73,0x8f,0x34,0x0e,0xcf,
	0x75,0x1c,0x74,0x80,0xc5,0xfe,0xfd,0x00,
	0x40,0xa8,0xb0,0x74,0x9c,0x50,0x51,0x7c,
	0x72,0xee,0x2b,0x2a,0x3e,0x1f,0xbf,0x38,
	0xbd,0x66,0x2d,0x31,0x53,0x2e,0x22,0xa5,
	0xa2,0x57,0x80,0x7a,0x87,0xef,0x56,0xb5,
	0x58,0x1b,0xdf,0x5a,0xce,0xf0,0xa5,0x80,
	0x7d,0xc3,0x94,0x35,0xb9,0x44,0x4e,0x52,
	0xa5,0xaf,0xc0,0xb9,0x18,0x1d,0xc6,0xee,
	0x8f,0xfe,0xdc,0xe2,0x3f,0xe1,0xe4,0x1f,
	0x1d,0x93,0xef,0x00,0xe7,0xd0,0x65,0x47,
	0x91,0x1b,0xde,0x96,0x61,0x43,0x89,0x2f,
	0x40,0xa8,0xc2,0x6c,0x7c,0x67,0x20,0xfa,
	0xd1,0x97,0x9f,0xab,0xa5,0x1a,0x00,0xc7,
	0x61,0x9b,0x39,0xce,0x71,0x78,0x5a,0x4d,
	0xf3,0xdf,0x35,0x0b,0x6a,0x69,0x20,0xed,
	0xb0,0x1e,0x15,0x3d,0x31,0x1e,0xdb,0x83,
	0x13,0x30,0x8c,0x41,0x3d,0xaa,0x41,0x09,
	0x4d,0xa5,0x2d,0x27,0x58,0x1f,0x9d,0x8c,
	0xdb,0x22,0xc1,0x91,0x25,0x90,0x53,0x0b,
	0xd9,0x32,0x40,0xb6,0x2d,0x72,0x25,0x11,
	0x4e,0x1b,0xd8,0xfc,0x90,0x2d,0x8b,0xdf,
	0xa4,0xdf,0x60,0x7b,0x97,0x64,0x4c,0x00,
	0x12,0x20,0x5b,0xe0,0xe0,0x1b,0xc8,0x80,
	0x84,0x8e,0xc2,0x19,0xd0,0x4d,0xb0,0x05,
	0xda,0x17,0x16,0x38,0x5f,0x0f,0x84,0x28,
	0x6c,0x1d,0xdc,0xd6,0x7c,0xf1,0x7c,0x42,
	0x55,0x41,0xea,0xd4,0xeb,0xcb,0x76,0x5c,
	0x85,0x0b,0x94,0x49,0x4c,0x1b,0xb1,0x3e,
	0xc1,0xfc,0xe6,0xaf,0x50,0x04,0x80,0x04,
	0x2a,0x41,0xeb,0xeb,0x3d,0x76,0x54,0x61,
	0x0b,0x1c,0xc4,0x4f,0x67,0x7c,0x0b,0x24,
	0xb5,0x3e,0x11,0xf4,0xaa,0x3c,0x89,0xf8,
	0xf0,0xeb,0x95,0xa8,0x08,0x19,0xfb,0xdd,
	0x88,0x72,0x58,0x54,0x1b,0xae,0x7e,0x8b,
	0x46,0x68,0xd6,0x51,0x9d,0x1a,0x72,0x24,
	0x99,0x19,0xfb,0xe1,0x39,0x1e,0x89,0x00,
	0x14,0xc0,0x29,0x9b,0x26,0x20,0x84,0x5a,
	0xf0,0xc6,0x29,0x1f,0x22,0x1f,0x24,0x2e,
	0xc2,0x29,0xfd,0xf0,0x06,0x51,0x52,0x81,
	0xac,0x14,0xff,0xc7,0xd1,0x57,0xdb,0x2e,
	0x01,0x1f,0x38,0x02,0x9a,0xf3,0xd9,0x2a,
	0xbd,0x87,0xe1,0x8a,0xbe,0xb9,0xc7,0x54,
	0x51,0xe6,0x3d,0x56,0x6a,0x19,0xdc,0x86,
	0x8b,0x6e,0xbc,0x10,0xce,0xf4,0xd1,0x8f,
	0x65,0x98,0xd9,0x4b,0xdf,0x3c,0x45,0x24,
	0xe5,0x1f,0x91,0x26,0x9e,0xbc,0x25,0x03,
	0xfc,0xf9,0x54,0xb5,0x03,0x07,0x29,0x42,
	0x07,0xea,0x10,0x23,0x18,0x19,0x84,0x27,
	0x5c,0xfc,0x65,0xd9,0x70,0x20,0x1d,0x9c,
	0xb1,0x84,0x1f,0x9a,0x80,0xca,0x54,0x29,
	0x2d,0x19,0x9b,0xa7,0x86,0x50,0x23,0xe7,
	0x44,0x1b,0x4f,0x1a,0xb2,0x0c,0xac,0xe7,
	0x2d,0x08,0x9b,0x71,0x50,0x1c,0x93,0x27,
	0x86,0xa3,0xa6,0x4b,0x4c,0x4f,0x18,0x97,
	0x25,0xbb,0x7e,0x50,0x3b,0x40,0x0b,0x6e,
	0x39,0x1f,0x47,0xa7,0x78,0x4f,0x91,0x37,
	0x3d,0x31,0x85,0xa3,0xf2,0x37,0x96,0xba,
	0x55,0x59,0x2a,0xa7,0x3d,0x1f,0x5e,0x63,
	0x28,0xae,0xb5,0x12,0xa8,0x00,0x60,0x04,
	0x7c,0xf8,0x95,0xe3,0x3d,0x2b,0xcd,0x09,
	0x39,0x1c,0x7d,0x14,0xb5,0x1e,0xa0,0xeb,
	0x04,0xef,0x50,0x9b,0x20,0xe3,0x91,0x4e,
	0x47,0x60,0x65,0x9c,0xe9,0x1c,0x6e,0x30,
	0xa4,0x90,0xa9,0x67,0xb6,0x91,0xec,0x7f,
	0xe2,0x71,0xef,0x55,0xac,0x12,0x25,0xa3,
	0x00,0x1d,0x7e,0xdc,0x99,0xe7,0xc6,0x64,
	0x4d,0x17,0x95,0x0c,0x66,0x79,0xca,0x7d,
	0xd7,0x39,0xe5,0x59,0x41,0x1d,0x7a,0x90,
	0x89,0xee,0xdd,0x28,0xa5,0x13,0x70,0xb0,
	0xc7,0x2f,0x36,0x02,0xd5,0x4e,0xfb,0x65,
	0x8a,0x1d,0xdc,0x58,0x9a,0xa5,0xa5,0x77,
	0x60,0x88,0xd1,0x88,0x82,0xc1,0xeb,0xc6,
	0x79,0x68,0xe3,0xd4,0xa8,0x1d,0xcc,0x10,
	0x60,0xe9,0xda,0xc0,0x5b,0xe8,0xd0,0xa4,
	0x91,0x2b,0xaf,0x13,0x6e,0x18,0x44,0x89,
	0x4a,0x1a,0x1c,0xdf,0x61,0xdc,0x39,0xce,
	0x73,0xee,0x1c,0xe7,0x38,0x0b,0x6e,0x74,
	0x7a,0x0d,0x9f,0xa6,0xa4,0x18,0x1f,0x9d,
	0x6a,0x63,0x74,0xe6,0x4a,0x1c,0xd3,0x81,
	0x68,0xea,0xcd,0x15,0x3c,0x0e,0x67,0xd8,
	0x18,0x1e,0xd9,0xd7,0x40,0x65,0x3e,0x8f,
	0xb2,0x24,0x41,0x14,0x59,0x58,0x55,0x59,
	0x98,0xef,0x09,0x26,0x30,0x1e,0xd0,0x15,
	0x42,0x8e,0x25,0x42,0xab,0xff,0x57,0xce,
	0x40,0x34,0x47,0x47,0xef,0xff,0x9b,0x2b,
	0x57,0x1c,0xcc,0xa1,0x67,0x92,0x22,0x08,
	0x9b,0xa9,0x17,0x83,0xf9,0xe4,0x91,0xd9,
	0x54,0xf4,0xa5,0x41,0x7e,0x1d,0xac,0xd5,
	0x97,0xa4,0x55,0xce,0x93,0xc9,0x11,0x97,
	0x51,0xec,0xb9,0x73,0x86,0xf6,0x58,0x08,
	0xd3,0x1d,0xb1,0x51,0xa7,0xf4,0xc5,0xce,
	0x23,0xfa,0x4e,0x21,0x4a,0x0e,0xd2,0xe2,
	0xf7,0x0b,0x05,0x3d,0x46,0x1d,0xb1,0x1b,
	0x98,0x97,0x25,0xb9,0xc4,0x43,0x65,0xc5,
	0x2f,0x7f,0x86,0x1a,0x37,0x17,0x72,0x48,
	0x4e,0x1c,0xd4,0x9d,0x91,0x7e,0x38,0x5c,
	0x04,0x64,0x1f,0x26,0xda,0x29,0xcb,0x43,
	0x33,0x18,0xc6,0x72,0x33,0x1c,0xd4,0x81,
	0x88,0xc6,0x3f,0x59,0xd4,0x7c,0x73,0x2c,
	0xea,0x39,0xd4,0x30,0xcd,0x26,0xe9,0x58,
	0x45,0x1d,0xa7,0x29,0x89,0x2e,0x61,0x9c,
	0xca,0x8f,0x1c,0x4a,0xba,0x5f,0xd3,0xb5,
	0x97,0x9f,0xcb,0xa7,0x91,0x1e,0xcc,0xdb,
	0x69,0xef,0x2e,0x71,0x05,0x91,0x20,0xb2,
	0xab,0xb8,0x19,0x1d,0x39,0x51,0xc5,0x41,
	0x0b,0x18,0x1c,0xbd,0x41,0xa0,0x25,0x0d,
	0x84,0x70,0x67,0xb8,0x04,0x00,0x36,0x4e,
	0xb6,0x1c,0x33,0x3c,0xd4,0x19,0x06,0x3d,
	0x55,0x56,0x8d,0xc7,0xe4,0x3b,0x75,0xc2,
	0x0d,0x28,0x73,0xf3,0x30,0x26,0x33,0xb0,
	0x41,0x1d,0x19,0x47,0x53,0xe5,0x34,0xbd,
	0xf9,0x4b,0xe5,0xf4,0x66,0xe6,0x38,0x93,
	0x5f,0xa8,0x90,0x84,0x24,0x19,0x06,0x47,
	0x50,0x62,0xf6,0x16,0x92,0x51,0xf4,0xde,
	0xf5,0xf0,0x92,0xfa,0xbb,0x20,0x0c,0xb9,
	0xe8,0x1f,0x96,0x44,0xe3,0x8f,0xdd,0xed,
	0x50,0xf8,0xac,0x93,0x9d,0x80,0x82,0xfb,
	0xbf,0x0c,0x07,0x39,0xce,0x1e,0xd1,0xc4,
	0xc8,0x31,0x2c,0x7b,0x40,0x28,0x7c,0x97,
	0x80,0x08,0x8d,0x58,0x1c,0xc8,0x65,0x23,
	0x3b,0x19,0xbd,0x4d,0x04,0xb3,0x39,0xce,
	0x74,0x2e,0x1c,0xe7,0x3b,0x4c,0x4e,0x73,
	0x9c,0x96,0x1c,0x26,0x09,0x18,0x01,0x27,
	0x1d,0x1c,0x9d,0x2f,0x43,0x68,0xb5,0x71,
	0x0d,0x44,0x48,0x69,0x9d,0x49,0xcb,0x64,
	0x79,0x1f,0x9e,0x78,0xc4,0xb1,0xac,0x9c,
	0xef,0xcf,0x48,0xba,0xa0,0x14,0x48,0x2a,
	0xd3,0x4f,0x85,0x00,0x00,0x1f,0x9d,0x3c,
	0x9b,0x51,0xc0,0x9d,0xed,0x4f,0x5a,0xb6,
	0xf2,0xcc,0x66,0x8d,0x85,0x0f,0x94,0x31,
	0x18,0x1a,0x1f,0x06,0xa3,0x9c,0x4a,0xea,
	0x16,0xb4,0xe8,0xa2,0x6f,0xff,0x29,0x45,
	0xa3,0x3d,0x3b,0xd9,0x13,0x1c,0x15,0xe4,
	0xe8,0xc9,0x05,0xa5,0xf1,0xac,0xbd,0x4a,
	0xed,0xd6,0xac,0xc5,0x06,0x89,0x37,0xc6,
	0x6f,0x1e,0xc3,0x61,0x26,0x50,0x55,0x47,
	0x82,0x76,0xd5,0x3d,0x46,0x8b,0x45,0xfc,
	0x4e,0x93,0x87,0xe0,0x0f,0x1d,0xef,0x43,
	0x20,0x11,0x59,0x68,0x1b,0xa8,0x57,0xf4,
	0x1c,0x2f,0x91,0x54,0x4f,0x41,0x01,0x0c,
	0x89,0x1d,0xef,0x43,0x3a,0x05,0x20,0x18,
	0x00,0x5f,0x93,0x14,0xae,0xa1,0xc1,0xb2,
	0x07,0x57,0x44,0x84,0xce,0x1d,0xeb,0x43,
	0x11,0xe3,0x8e,0xce,0x45,0xa4,0x5a,0x21,
	0x5a,0x1b,0xdf,0xfc,0x05,0x7b,0xc5,0xa8,
	0x40,0x1d,0xeb,0x43,0x0b,0xf3,0xdb,0xe7,
	0x51,0xcf,0x26,0xbc,0x27,0x2e,0x09,0xce,
	0x27,0x95,0xec,0xe6,0x10,0x1d,0x6e,0xa4,
	0xf0,0xbd,0xa5,0x67,0xb1,0x8b,0xe2,0x3b,
	0x43,0x7f,0x69,0x48,0x32,0x17,0xcf,0xa9,
	0x0d,0x1d,0xeb,0x42,0xe0,0x51,0x45,0x09,
	0x4f,0x97,0xd6,0x77,0xeb,0xc4,0xef,0xca,
	0x2c,0x11,0xcb,0x9e,0xc7,0x1d,0xec,0xc2,
	0xe5,0x9e,0xda,0xf7,0xbd,0x6e,0x41,0x6f,
	0x82,0xb7,0x12,0xc5,0x46,0x5b,0xc8,0xb5,
	0xae,0x1d,0xfc,0xd2,0xf0,0x45,0x3b,0x6e,
	0x20,0x09,0x5a,0xf2,0xc6,0x2c,0x29,0xfa,
	0x4a,0x30,0x46,0xa8,0x16,0x1a,0xc9,0x46,
	0xf2,0xf3,0x46,0x26,0x0c,0xa8,0x84,0xe7,
	0x39,0x24,0x39,0xb2,0x8f,0x46,0x18,0xa9,
	0x27,0x1a,0x12,0x37,0x1b,0xfc,0x2d,0x5a,
	0xec,0x53,0x0b,0x4e,0x88,0x60,0xbd,0xe6,
	0xfa,0xb0,0xc9,0x7c,0xbc,0x1f,0x16,0x47,
	0x17,0x15,0x84,0x75,0xd9,0x7d,0x27,0x06,
	0xf2,0x5e,0x73,0x95,0x61,0x70,0xba,0xa6,
	0xc2,0x19,0x06,0x47,0x20,0x5b,0xd6,0x4a,
	0x2b,0xcc,0xe4,0x5e,0x77,0xae,0x71,0x90,
	0x8c,0x6f,0x35,0x9a,0xa5,0x19,0x06,0xc7,
	0x33,0x01,0xd7,0x95,0x4d,0xd1,0xba,0x18,
	0x6a,0x62,0xfb,0xf5,0x24,0x48,0xb7,0x96,
	0x13,0x1e,0x12,0xb7,0x4a,0x05,0x18,0x5e,
	0x3d,0xf5,0xcc,0x17,0xeb,0x83,0x7b,0xd5,
	0x62,0x5e,0xfb,0x70,0xd7,0x1e,0x12,0x37,
	0x32,0xf9,0xc3,0x06,0x60,0x7b,0x67,0x86,
	0x95,0xa8,0x70,0x6f,0x4e,0xb0,0x31,0xec,
	0x27,0x1e,0x12,0x47,0x21,0x13,0xd2,0x31,
	0xd6,0xa4,0xef,0x81,0x62,0x00,0xf5,0x64,
	0x35,0x35,0x26,0x0e,0xd5,0x1a,0x12,0x46,
	0xf3,0x83,0xf8,0xfd,0x4e,0x28,0xdf,0xad,
	0x70,0x2c,0xe6,0x4c,0x34,0x12,0x30,0xb5,
	0xad,0x1d,0x9e,0xf6,0xb1,0x31,0xc4,0xa5,
	0xc3,0x40,0xc5,0x1d,0xbe,0x2f,0x0b,0xf2,
	0xd4,0x37,0x81,0x2a,0xf3,0x1d,0xd2,0xd6,
	0x83,0xf1,0x90,0x03,0x49,0xbe,0x54,0xbb,
	0xcd,0xc3,0xd4,0x8d,0x79,0x64,0x68,0xa1,
	0x2b,0x1b,0xdf,0x28,0x6f,0x71,0x81,0x58,
	0xb0,0xc6,0x86,0xc4,0x5b,0xca,0x7e,0x3d,
	0x26,0x36,0x35,0x3d,0x40,0x1b,0xc8,0xc2,
	0x68,0x5c,0x24,0x17,0xc0,0x91,0xcb,0x31,
	0x22,0x2f,0x06,0x80,0x61,0xdb,0x84,0x7f,
	0x16,0x1d,0xd3,0xce,0x6d,0xbc,0xbc,0xf5,
	0xba,0xb6,0x94,0x08,0x26,0x17,0x36,0x66,
	0x51,0xd0,0x65,0x2b,0xe8,0x1b,0xc1,0x3a,
	0x68,0x3c,0x2c,0x1d,0xc2,0x9e,0x1e,0x75,
	0x82,0x1a,0x55,0x00,0x16,0x27,0x84,0x07,
	0xe0,0x1d,0xc6,0xf4,0x6f,0xfc,0x1c,0x2f,
	0x50,0xb4,0x98,0x85,0xce,0x17,0x00,0xb2,
	0x25,0xef,0x82,0xa1,0x07,0x1b,0xdf,0x48,
	0x68,0x9c,0xcd,0x79,0x86,0xbe,0x15,0x53,
	0x28,0xd7,0x08,0x02,0x52,0xb8,0x6f,0x8b,
	0x3f,0x1d,0xc6,0xc4,0x68,0x7c,0x5c,0x11,
	0x47,0xa4,0xad,0xf7,0xa5,0x57,0x0a,0x3d,
	0x6e,0xb9,0x32,0x61,0x18,0x1d,0xc6,0xa4,
	0x68,0x3c,0x1c,0x09,0x4b,0x6e,0x1e,0x8c,
	0x51,0x6f,0x00,0x78,0x31,0x0d,0xa4,0x40,
	0x1c,0x1b,0xdf,0x10,0x68,0x3c,0x56,0x00,
	0x5f,0xae,0x6f,0x83,0xde,0x17,0x11,0xb0,
	0x13,0xe7,0x9c,0x71,0x46,0x1b,0xc7,0xc2,
	0x6a,0xfc,0xdc,0xb2,0x5a,0x0c,0xb8,0x75,
	0x2b,0xcf,0x20,0x03,0x60,0x32,0x35,0x29,
	0x40,0x1b,0xcf,0x10,0x61,0x5c,0x25,0x29,
	0x41,0xee,0x3e,0x02,0xf1,0x07,0x02,0x8e,
	0x67,0xe3,0x9e,0xa3,0xe7,0x1b,0xc1,0x3a,
	0x6c,0xbc,0x4b,0xe8,0x9c,0x2e,0x11,0x85,
	0x7c,0x30,0xd1,0xb1,0xd7,0x07,0x84,0x20,
	0xe7,0x1d,0xc2,0xce,0x61,0x0d,0x1d,0x08,
	0x54,0x3e,0x44,0x1e,0xb3,0xc7,0x0a,0xd9,
	0xff,0xe3,0x84,0x1d,0x46,0x1d,0xc6,0xd0,
	0x68,0xfc,0x89,0x7f,0x51,0xee,0x3f,0x78,
	0x58,0xe7,0x25,0x8a,0xa1,0xdf,0x8c,0x20,
	0x12,0x1b,0xc1,0x3a,0x6d,0x6d,0xa3,0x7e,
	0xe5,0x7e,0x11,0x04,0x4a,0xc8,0xcc,0x08,
	0x97,0x93,0x8f,0xa3,0xc8,0x1b,0xdf,0x3a,
	0x6f,0x3c,0xbe,0xeb,0xc4,0x2e,0x54,0xa4,
	0x61,0x17,0x04,0x5d,0x85,0xa3,0x84,0x2c,
	0x1f,0x1d,0xdc,0x10,0x63,0xa3,0xda,0x23,
	0x6f,0x5e,0x14,0x2c,0xa4,0x52,0x40,0x00,
	0x11,0x4b,0x8b,0x7c,0x89,0x1b,0xc1,0x10,
	0x68,0x4d,0xac,0x07,0x8e,0x81,0x80,0x71,
	0xa0,0xef,0x11,0x06,0x4a,0x2c,0x45,0x2b,
	0xe0,0x1b,0xdf,0x3a,0x68,0x5c,0x7c,0xfe,
	0xd3,0xee,0x14,0xa3,0xff,0xc7,0x3f,0xf5,
	0xaf,0xaf,0x95,0x21,0x14,0x1b,0xdd,0x3a,
	0x53,0xbc,0xae,0xc8,0x57,0xee,0x79,0x04,
	0xac,0x50,0x6a,0x3a,0x96,0xef,0x9f,0x37,
	0xeb,0x1d,0xd3,0x9c,0x59,0x5c,0xed,0x78,
	0x84,0xce,0x70,0x87,0xb1,0x77,0x2b,0x95,
	0x51,0x7b,0x96,0xa8,0xb7,0x1d,0xc6,0x84,
	0x5c,0x5c,0xdf,0xf2,0xf8,0xc1,0xfe,0x30,
	0xa7,0x82,0x6a,0x62,0xd2,0xbb,0x94,0x37,
	0x3f,0x1b,0x99,0x22,0x55,0x5c,0x9d,0x29,
	0x45,0x6e,0x78,0x05,0x26,0xa7,0x27,0xad,
	0xc0,0xdb,0x84,0xfd,0x09,0x1b,0x87,0x22,
	0x42,0x29,0x82,0xb7,0xc7,0xfe,0x7e,0x04,
	0xa5,0xe3,0x60,0xa0,0x29,0xef,0x94,0x35,
	0xea,0x1b,0x9f,0x5c,0x4d,0x5c,0xa1,0x2b,
	0x7b,0x2e,0x70,0xac,0x12,0x07,0x31,0x3a,
	0x65,0x47,0x8e,0x1d,0x60,0x1b,0x99,0x6e,
	0x43,0xdc,0xa3,0xff,0xa8,0xde,0x40,0x06,
	0xa2,0xaf,0x36,0x52,0x40,0x53,0x9a,0x7e,
	0x09,0x1b,0xdd,0x10,0x58,0x1c,0x1d,0x40,
	0x5b,0x6e,0x51,0x64,0x12,0x97,0x38,0x92,
	0x11,0x3b,0x94,0x9e,0x29,0x1d,0xcf,0x84,
	0x4d,0xbc,0xa3,0xe4,0x55,0x5e,0x7c,0x15,
	0x80,0xf7,0x28,0x5f,0x96,0xc5,0xb5,0xa7,
	0x08,0x19,0xdf,0x66,0x50,0x9c,0xc9,0x08,
	0x01,0x0e,0x68,0xb5,0x26,0x57,0x2f,0xac,
	0x91,0x0c,0x7c,0xa9,0x1f,0x1d,0xcc,0xf4,
	0x51,0x29,0xae,0xc8,0x51,0x2e,0x4e,0x94,
	0xdd,0xf8,0xcf,0xca,0x8e,0x6f,0x88,0xab,
	0x0a,0x19,0xde,0xa2,0x58,0x9c,0x03,0xf8,
	0x56,0xde,0x40,0x75,0x23,0x1f,0x36,0x02,
	0x41,0xcf,0x95,0x46,0x10,0x1d,0xcb,0xa4,
	0x5a,0xa3,0x2d,0x07,0x80,0x2e,0x73,0xa0,
	0x28,0x27,0x2a,0xb8,0x12,0x4f,0x9c,0xb5,
	0x3c,0x1d,0xc6,0x84,0x57,0x5c,0xf1,0x20,
	0x57,0xce,0x76,0x03,0xe3,0xb7,0x2a,0x98,
	0x0e,0x1c,0x08,0xa5,0x09,0x1b,0xac,0xd8,
	0x7c,0xdc,0x19,0x65,0xfe,0x8e,0x0e,0x5f,
	0x20,0xcf,0x09,0x58,0x11,0x27,0x9a,0x9f,
	0xca,0x1d,0xd3,0xec,0x7b,0xbc,0x35,0x4a,
	0x2a,0x3e,0x42,0x0a,0x5b,0xd7,0x10,0xd0,
	0x0f,0x10,0x31,0xa6,0x58,0x1e,0xd8,0x42,
	0xe3,0xdc,0x65,0xce,0x75,0xdc,0x9c,0xe7,
	0x38,0x6f,0x3e,0xb0,0xef,0x9b,0x99,0x1d,
	0x6a,0x1f,0x33,0xa3,0x55,0x9c,0x3b,0x00,
	0x42,0xf8,0x00,0x80,0x22,0x2c,0x39,0x73,
	0x1e,0x01,0xcb,0x2d,0x53,0x1e,0xdb,0x8b,
	0x98,0xe9,0xb9,0xce,0x62,0x78,0x53,0xc5,
	0xe6,0x3c,0x8a,0x50,0xdd,0x43,0xbc,0xc1,
	0xa4,0x1f,0xa4,0xd9,0x61,0xc0,0x47,0x10,
	0x4d,0x65,0x45,0x99,0xbe,0x36,0xe0,0x50,
	0x12,0x92,0x25,0x59,0x81,0x1c,0x09,0xef,
	0x61,0xb2,0xe6,0x73,0x00,0x50,0x28,0x50,
	0x0c,0x16,0x6a,0x72,0x65,0x5d,0xd4,0x2b,
	0xd4,0x1c,0x03,0xeb,0x6e,0xf9,0x01,0xf7,
	0x28,0x66,0xc4,0x5e,0xcf,0x2e,0x73,0x9b,
	0x41,0xf3,0xff,0xa6,0x74,0x1c,0x09,0xb9,
	0x74,0xcd,0xbe,0x78,0x65,0xc5,0x8a,0xd3,
	0x4e,0x87,0x2c,0x7a,0x85,0xaf,0xaf,0xb4,
	0xc1,0x1c,0x00,0x6b,0x75,0x17,0xa2,0x46,
	0x28,0x40,0x24,0xd3,0xa4,0x28,0x32,0xa4,
	0x5e,0x12,0x24,0x20,0x08,0x1c,0x04,0x0b,
	0x87,0xb8,0x99,0xd3,0x6b,0xd4,0x55,0x95,
	0xee,0x87,0x39,0xb8,0x0d,0x61,0xe5,0x83,
	0x18,0x1c,0x00,0x1b,0xc6,0xf2,0x2a,0x48,
	0x3b,0x63,0x9c,0x17,0x39,0xb4,0x33,0xa8,
	0x9c,0xd7,0xa8,0x88,0xbf,0x1c,0xcb,0xaf,
	0xa6,0xae,0xd7,0x1a,0x77,0xc5,0x8c,0x5f,
	0xc0,0x30,0x1a,0xaa,0xd4,0xd9,0xe6,0xd6,
	0xdf,0x18,0xa2,0xcf,0x66,0xef,0xda,0x46,
	0x3b,0x59,0xcf,0x64,0x00,0x68,0x0a,0x53,
	0x9c,0xa8,0x01,0xd5,0xce,0x1b,0xac,0xba,
	0xff,0x20,0xac,0xa8,0x3b,0x0c,0xf0,0x7f,
	0x87,0x8f,0x85,0x85,0x96,0xe5,0xe6,0x98,
	0x6b,0x18,0xb6,0x3a,0xa6,0xa7,0xa0,0xa9,
	0xff,0xef,0x44,0x05,0x0d,0xbf,0xa6,0x42,
	0x97,0x78,0x40,0xeb,0x31,0x1b,0xdf,0x42,
	0x81,0x83,0xa1,0x05,0xfe,0x28,0xf6,0x05,
	0xa2,0xa3,0x76,0x16,0x54,0x63,0x84,0x32,
	0x16,0x18,0xbf,0x3a,0x97,0xed,0x16,0x4c,
	0x5f,0xae,0x32,0x97,0xc0,0xfe,0xe9,0x54,
	0xd1,0xdf,0x84,0xc5,0xe8,0x1d,0xc4,0xe4,
	0x7d,0xa3,0xf8,0x8b,0xf8,0x81,0xc6,0x0f,
	0x28,0x4a,0x68,0xa5,0xa3,0x23,0x80,0x27,
	0xc2,0x1f,0x9f,0x1e,0xe8,0x5c,0x39,0xce,
	0xc8,0xb6,0xb2,0xe7,0x39,0xf4,0x8e,0x73,
	0x9d,0x1b,0x99,0x3c,0xe9,0x18,0x2d,0x19,
	0x0a,0xf0,0x21,0x8b,0x55,0x66,0x83,0xf1,
	0x95,0xf4,0xc6,0x15,0xa1,0xed,0x3c,0x44,
	0x91,0x18,0x21,0xc3,0x64,0x90,0x21,0x6a,
	0x5b,0x88,0x23,0x6a,0xcd,0xac,0x2b,0xc2,
	0xf0,0xf2,0x53,0xa3,0x27,0x18,0x39,0xc3,
	0x96,0x3c,0xbd,0x82,0x0b,0xc9,0x1e,0x11,
	0xc5,0x87,0x26,0xfc,0x54,0xf2,0xd1,0x1b,
	0x30,0x18,0x3b,0xf7,0x97,0x7b,0xaa,0x3a,
	0x9b,0xcd,0x38,0x6c,0x09,0xdb,0xb1,0xb8,
	0x58,0xf3,0x59,0x3b,0x69,0x1c,0xc8,0x03,
	0x96,0x7c,0x30,0x4a,0xc3,0xb3,0x78,0xe2,
	0xb6,0x83,0x9c,0x02,0xb8,0xe8,0xdb,0x64,
	0x31,0x18,0x23,0xcf,0x87,0x67,0x32,0xb5,
	0xbb,0xa4,0x24,0xfc,0x62,0x20,0xd9,0x62,
	0x0e,0xe5,0xfb,0x8a,0x4d,0x18,0x3d,0x77,
	0x67,0x47,0x60,0xb1,0x42,0x4b,0xd3,0x10,
	0x01,0xc3,0x88,0x3a,0x00,0xb5,0x37,0xd3,
	0x22,0x1c,0xcf,0x03,0x67,0x0b,0xa8,0x70,
	0xab,0x9d,0x83,0x04,0xa1,0xbf,0x61,0x13,
	0x5a,0xe4,0xeb,0x1c,0xd5,0x1b,0xa1,0x19,
	0x67,0x1d,0xad,0xba,0x53,0x93,0xa2,0x2b,
	0x29,0xd7,0xc8,0x10,0x2d,0x24,0x68,0xa7,
	0xa3,0x1c,0xb6,0x59,0x57,0x88,0xca,0x6d,
	0xb4,0xb1,0xa3,0x11,0xdd,0xf3,0x80,0x7b,
	0xd9,0x04,0xa0,0x99,0xce,0x19,0x21,0x65,
	0x48,0x4b,0xe8,0xc3,0x0c,0x27,0x9e,0xa8,
	0xf2,0x3a,0xca,0x1a,0xaf,0x59,0xaa,0xa1,
	0x62,0x1b,0xee,0xc5,0x49,0x84,0xa8,0x75,
	0x4b,0x4e,0x3e,0x05,0x7d,0x34,0x52,0xb4,
	0x45,0x41,0xd7,0xbf,0xef,0x1f,0x27,0x7d,
	0x42,0x0d,0x29,0x8b,0x2d,0x42,0x74,0xb3,
	0x26,0x4b,0x6b,0x4c,0x92,0x88,0x64,0xc9,
	0xf5,0x1f,0x3c,0x7d,0x5a,0xbb,0xcf,0x0b,
	0xe0,0x37,0x14,0x65,0x42,0xff,0x31,0xae,
	0x6d,0x60,0xd8,0xb9,0x7d,0x1a,0xc0,0x3d,
	0x3b,0x27,0x45,0xfa,0x45,0xc7,0x55,0xbb,
	0x75,0xae,0xc0,0x5e,0x1d,0xeb,0xd7,0x2e,
	0xd4,0x1a,0xd9,0xbd,0x3b,0x09,0xa8,0x21,
	0x46,0x37,0x16,0x34,0x37,0x14,0xdb,0xe9,
	0x7b,0x77,0x9a,0x61,0x31,0x1a,0x0f,0x47,
	0x4d,0x2f,0x33,0x88,0xe5,0xc5,0x64,0xc7,
	0x6b,0x76,0x38,0xa9,0x45,0x89,0x34,0x48,
	0x7d,0x1a,0x16,0x47,0x68,0x59,0xf3,0x62,
	0x60,0x56,0xc4,0xd2,0xe9,0x0d,0xe6,0xf8,
	0x04,0x7c,0x28,0xd4,0x10,0x1f,0x8c,0x9f,
	0x4f,0xfc,0xdd,0x85,0x5d,0x1e,0x22,0xd4,
	0x91,0xe7,0x98,0x4e,0x2b,0x77,0xc0,0xc1,
	0x75,0x18,0xbd,0xa5,0x0d,0x62,0xbd,0xe8,
	0x55,0x50,0xfb,0x18,0x1a,0x7b,0x6a,0xff,
	0xd6,0x08,0x04,0xa2,0xcb,0x1d,0xfd,0xd3,
	0x0b,0x67,0x46,0x04,0x04,0x96,0x9f,0x55,
	0xa8,0x30,0x90,0xa1,0xdf,0x5b,0x12,0xd9,
	0x11,0x1d,0xe6,0x21,0x1c,0x6d,0x2d,0x7e,
	0x54,0xf2,0x77,0x99,0x9e,0x84,0x29,0x5a,
	0x42,0x83,0xdc,0xaf,0x18,0x1d,0xe6,0x53,
	0x39,0x7b,0xd9,0xf0,0x88,0x8f,0x14,0x35,
	0x2e,0x54,0xb6,0xb4,0x0e,0x17,0xc5,0xa8,
	0x40,0x19,0xf7,0x71,0x79,0x3b,0x09,0xd7,
	0x84,0x79,0x33,0x15,0xa2,0x77,0x39,0x80,
	0xff,0x1e,0x54,0x2a,0xaf,0x19,0xf7,0x3b,
	0x88,0xbb,0x58,0x5a,0xbc,0x6c,0x40,0x28,
	0xe6,0x23,0x1e,0x86,0xa7,0x14,0xf2,0xfa,
	0x3f,0x19,0xe4,0xbb,0x8b,0x63,0x12,0xb9,
	0x84,0x5e,0xcd,0x5f,0x24,0x32,0x51,0x40,
	0x11,0x17,0x74,0xe2,0xfb,0x19,0xe4,0xd9,
	0x80,0xa2,0x25,0x7f,0xc4,0x4d,0x44,0xb6,
	0x92,0x26,0x0b,0x72,0x57,0x13,0x6b,0x53,
	0x9b,0x19,0xe4,0xd9,0x88,0x8b,0x1a,0x0f,
	0xe4,0x4f,0x84,0x6c,0xf2,0x19,0x86,0x68,
	0x75,0x0d,0x47,0x37,0xb4,0x19,0xe4,0xd9,
	0x88,0x78,0xf0,0x3d,0xec,0x37,0xb6,0xe1,
	0xee,0x1f,0xf4,0x53,0x89,0x0c,0xa8,0xb4,
	0xce,0x19,0xee,0xd9,0x98,0x78,0x14,0x86,
	0x2c,0x2e,0x9d,0x23,0x66,0x15,0x8a,0x9c,
	0x3d,0x0b,0x6b,0xc5,0x63,0x1a,0x20,0xfb,
	0x98,0x58,0xe6,0x0e,0x26,0x0f,0x23,0x61,
	0x06,0x09,0x8e,0x1c,0x45,0x05,0xc1,0xc4,
	0x4e,0x1e,0x3c,0xd5,0x88,0x3f,0xee,0x63,
	0x6c,0x03,0x99,0xee,0x46,0x0f,0xfd,0xc4,
	0x67,0x77,0xc7,0xfa,0x09,0x1c,0xd4,0xd9,
	0x88,0x1b,0x42,0xf1,0x53,0xf3,0xdb,0x67,
	0x4a,0x01,0xba,0x71,0xe4,0x14,0x46,0x83,
	0xe9,0x1c,0xdc,0x59,0x88,0x18,0xb9,0xd2,
	0x88,0x40,0x1a,0x04,0x26,0x02,0x2a,0x77,
	0xb0,0x10,0x06,0x82,0x22,0x1c,0xdb,0x6d,
	0x97,0xeb,0x3b,0x32,0x7c,0x74,0xaa,0x06,
	0x09,0xf5,0x2a,0x71,0x4b,0x39,0xcf,0x01,
	0x00,0x19,0x22,0xc9,0x87,0xda,0x6c,0x55,
	0x43,0x96,0xac,0x06,0x09,0xed,0xca,0x48,
	0xd1,0x05,0x07,0xec,0xe3,0x19,0x23,0xf9,
	0x77,0xb7,0x98,0xf6,0x9b,0x74,0x9e,0x2d,
	0xfd,0xeb,0x86,0xa8,0x51,0x2a,0x28,0xd0,
	0x66,0x18,0xac,0x3b,0x08,0x7e,0xff,0xff,
	0x06,0x90,0x12,0x74,0xa0,0x92,0x47,0x9d,
	0xd2,0xd5,0xa6,0x86,0x2e,0x1a,0x1c,0xa7,
	0x37,0xc7,0x39,0xce,0x70,0xde,0x1c,0xec,
	0xa2,0x0c,0x9f,0x73,0x9c,0x22,0x17,0x30,
	0x50,0x19,0x90,0xa7,0x32,0x15,0x84,0x57,
	0x0f,0x61,0xb4,0x1d,0xf7,0xfc,0x93,0x06,
	0x3f,0x74,0x0f,0x21,0xc1,0x1c,0xd8,0x59,
	0x4b,0x2c,0x51,0x56,0xfe,0x5e,0x13,0xf5,
	0xfc,0x80,0x96,0x0e,0x67,0x71,0x9b,0x39,
	0xe2,0x1f,0x2a,0x23,0x29,0xed,0x01,0x37,
	0x48,0xd1,0xec,0xe9,0xa7,0x14,0xf6,0x0a,
	0x40,0xff,0x88,0xd5,0x1b,0x1f,0x33,0x87,
	0x4d,0x03,0x1b,0x2d,0x86,0x02,0x46,0xdf,
	0xd8,0x64,0x48,0x1f,0xd7,0x63,0x75,0x46,
	0xbc,0x19,0x2f,0xf9,0x59,0xfc,0x23,0xf4,
	0xb1,0x5f,0x0c,0xe1,0x0e,0x71,0x38,0x89,
	0x8b,0x5d,0xa3,0xfa,0xa8,0x19,0x37,0x93,
	0x58,0xb4,0xd7,0x6d,0x1b,0xde,0x3c,0xf9,
	0xa2,0x1e,0x0b,0xb0,0x21,0x38,0x63,0xc9,
	0x49,0x19,0x21,0xdb,0x38,0x9e,0x87,0x7f,
	0x94,0xb7,0x0e,0xb5,0xfe,0x2e,0xa0,0x75,
	0xfd,0x11,0xe4,0xae,0x2a,0x1c,0x3d,0x17,
	0x28,0xef,0x89,0x1b,0x9c,0x77,0xc4,0x15,
	0xc0,0x00,0x92,0x1a,0xcd,0x21,0xc3,0xa8,
	0x42,0x1c,0x22,0x16,0xeb,0x11,0x25,0x1b,
	0x50,0x36,0x5e,0x2b,0x4d,0xf2,0x5f,0x46,
	0x94,0xb4,0x4a,0x0f,0x3a,0x1c,0x2e,0x74,
	0x91,0x6e,0xa0,0x16,0xfd,0xdf,0x12,0x0b,
	0x44,0x04,0x4a,0x51,0xc3,0x06,0x23,0x2d,
	0x59,0x1d,0xd7,0x64,0x71,0xb1,0xd3,0x18,
	0x88,0xa8,0x81,0x11,0x22,0xbf,0x36,0x66,
	0x1a,0xbb,0x84,0xae,0x28,0x19,0x19,0x47,
	0x87,0x9c,0x39,0xce,0x75,0xfc,0xdc,0x4e,
	0x68,0x65,0xd2,0x6a,0x43,0x74,0xa5,0xa7,
	0x43,0x1e,0x1e,0x3d,0x64,0x39,0xf4,0x3b,
	0xd0,0x2e,0x68,0x92,0xa7,0x3e,0xad,0x02,
	0x0d,0x17,0x3a,0xa7,0xdd,0x18,0x0d,0x3d,
	0x71,0x81,0xf7,0x54,0x0b,0xc0,0xf5,0x6b,
	0x31,0x85,0x72,0x37,0xbd,0xcc,0x2c,0x4e,
	0xf7,0x1f,0xa7,0x9d,0x64,0xf1,0x71,0x2c,
	0x09,0xd4,0xd8,0xc0,0x63,0x8b,0x5a,0x7e,
	0x3c,0xb7,0x75,0x63,0x6b,0x1f,0xa1,0x9d,
	0x84,0x9c,0x2b,0x32,0xc3,0xae,0x1a,0xbc,
	0xe5,0x84,0x33,0xc0,0xcc,0xbe,0x15,0x38,
	0xfa,0x1f,0xa1,0x83,0x9d,0xe4,0x2b,0xd8,
	0x56,0xda,0x4f,0xe4,0xd5,0x7e,0x89,0x6b,
	0x31,0xbb,0x11,0x78,0x87,0x1f,0xa1,0xe1,
	0x86,0x57,0xe4,0xb0,0x63,0x2d,0x87,0x15,
	0xc5,0xae,0x89,0x22,0x44,0xd7,0x0a,0xbd,
	0xd6,0x1f,0xa1,0xe1,0x86,0xbf,0x47,0xaa,
	0x53,0x73,0x9f,0x1d,0xb1,0xba,0x85,0xca,
	0x8c,0xeb,0x48,0x08,0x43,0x1f,0xa1,0xe1,
	0x77,0x5f,0x55,0x9c,0xdb,0xba,0xaa,0x59,
	0x9d,0xde,0x1e,0x0a,0xdc,0xf2,0xe3,0x33,
	0x1c,0x1c,0xd9,0x8b,0x57,0x8e,0xe0,0x2d,
	0x1b,0xf9,0xe9,0xc4,0xfa,0x5c,0x51,0x56,
	0x45,0x18,0x05,0x3b,0x27,0x18,0x28,0x3a,
	0xe7,0xa3,0xa1,0xb0,0x0a,0x38,0x9e,0x81,
	0xf1,0x97,0x15,0xdd,0x81,0x09,0xcd,0xb9,
	0x4a,0x1c,0x23,0xca,0xb9,0x8e,0x9f,0x08,
	0x04,0xdf,0x16,0xb4,0xa2,0x1f,0x96,0xbc,
	0x4f,0x4a,0x78,0x9f,0xce,0x19,0xbe,0x91,
	0x0d,0x2d,0x19,0xc3,0x75,0xc7,0x32,0xe3,
	0xe4,0x27,0x78,0x3b,0xda,0x38,0x7f,0xac,
	0x2d,0x18,0x1e,0xa7,0x3b,0x26,0x29,0xce,
	0x70,0x51,0x06,0x21,0x8a,0x7a,0x75,0xbf,
	0xa4,0x30,0xe2,0x05,0xed,0x1c,0x08,0xc5,
	0x45,0xd7,0x4a,0x52,0xa6,0xcc,0xc2,0x6f,
	0x56,0xfe,0x7b,0x72,0x9f,0xad,0xbb,0x4b,
	0x10,0x1f,0xa8,0xa1,0x53,0xed,0x2a,0x28,
	0x96,0x76,0xd2,0x82,0x90,0xfe,0xcd,0xc3,
	0x40,0x42,0x67,0x49,0x44,0x18,0x39,0x8f,
	0x77,0xec,0x5b,0x07,0x53,0xca,0x18,0x26,
	0xc9,0xe9,0x11,0xb2,0xd0,0xed,0x93,0x09,
	0x15,0x1d,0xa5,0x0f,0x87,0x52,0xc8,0xed,
	0x73,0xaa,0x6b,0x45,0x2d,0xd1,0x2c,0x62,
	0x58,0xea,0x9f,0x43,0x51,0x1d,0xa5,0x67,
	0x97,0x44,0xab,0x69,0xcb,0xbc,0x45,0xbb,
	0xc5,0xd6,0xea,0x13,0x58,0xf1,0x53,0x4e,
	0xd2,0x1f,0xb1,0xe1,0x99,0x23,0x2d,0xf6,
	0x93,0xd5,0x57,0x0d,0x15,0x9f,0x00,0x4a,
	0x1a,0xf4,0xdc,0xdf,0x46,0x1f,0xb5,0x61,
	0x67,0xae,0xfd,0xf3,0xb3,0xf9,0xf8,0x80,
	0xb2,0x0f,0x8f,0xbe,0x5f,0x0b,0xcd,0x97,
	0xed,0x1c,0x23,0x98,0xf5,0xe0,0xa6,0xaf,
	0x46,0x70,0x00,0x9b,0x80,0xcf,0x02,0x18,
	0x0e,0x87,0xc5,0x33,0x39,0x18,0xa3,0xd4,
	0x9e,0xbe,0xc5,0x07,0x94,0xa1,0xec,0x8f,
	0x8d,0x6a,0x61,0x8c,0xd4,0x94,0xed,0x24,
	0xff,0x1f,0x91,0xa1,0x02,0x9c,0x39,0xce,
	0x71,0x69,0x32,0xe7,0x24,0x62,0x2e,0x08,
	0xfd,0x77,0x98,0x81,0x0e,0x1c,0x19,0xdd,
	0x2e,0xdc,0x01,0xed,0x3c,0xde,0x75,0xa6,
	0xc3,0xcc,0xa3,0x12,0x75,0xc7,0x28,0xc5,
	0x32,0x1d,0x80,0x73,0x37,0x5b,0x3e,0x7e,
	0x10,0x08,0x94,0x05,0xaa,0x1c,0xbe,0xf4,
	0xdf,0x45,0xa5,0x00,0x69,0x1d,0x98,0x29,
	0x11,0x9e,0x14,0x0e,0xfc,0x3f,0x4a,0xa7,
	0x5e,0x81,0x29,0x93,0x63,0xf7,0x85,0x30,
	0x0b,0x1f,0x42,0x46,0xf3,0xd1,0xbb,0x76,
	0xb7,0x77,0xd7,0x20,0xf7,0x43,0x4d,0x42,
	0x57,0xe5,0xe4,0xad,0xee,0x1f,0x42,0x7c,
	0xfc,0x51,0xc9,0xbd,0xaf,0x96,0xfe,0x20,
	0x33,0xc7,0x08,0xff,0xf2,0x00,0x04,0x7c,
	0xf8,0x1f,0x5e,0x7c,0xef,0xb1,0xba,0x7b,
	0x91,0x3e,0x4d,0xaa,0xa3,0xf9,0xc0,0xaa,
	0x9c,0x47,0xcb,0x45,0xce,0x19,0x44,0x58,
	0xa3,0xf1,0x7e,0x69,0x73,0x3c,0xfe,0xef,
	0x33,0x3c,0x72,0xe1,0x27,0x1f,0x92,0x89,
	0x40,0x1b,0xca,0xe4,0xa0,0x69,0xa5,0x1f,
	0x02,0x56,0x92,0x0c,0x2a,0x4c,0x48,0x65,
	0x0f,0xeb,0xcf,0x94,0x80,0x1d,0x5a,0xc4,
	0xa1,0x02,0x8c,0xd7,0x43,0x6a,0x4c,0x1a,
	0x27,0x1b,0x48,0xf8,0x2c,0x31,0x33,0x8f,
	0x08,0x1e,0x6d,0x96,0xa9,0xad,0x61,0xa9,
	0x39,0x0f,0x04,0x27,0x83,0x1b,0x62,0x42,
	0x2b,0x90,0x65,0xfd,0x68,0x1b,0xbd,0x4e,
	0x9f,0x61,0x7e,0x57,0xcc,0x7c,0xad,0x52,
	0x2c,0x9b,0x4a,0x1c,0x6c,0x6b,0x91,0xb5,
	0x22,0x1e,0xc3,0x10,0x9e,0x5c,0xbc,0xeb,
	0x51,0x92,0xbe,0x23,0xff,0x10,0xd3,0x48,
	0x55,0x23,0x85,0xb3,0xc0,0x1d,0xd6,0x6e,
	0x76,0xaf,0xbd,0x3e,0x46,0xce,0x31,0x6b,
	0xf7,0x3a,0x6a,0x43,0x6d,0xa3,0x88,0xad,
	0x1f,0x1d,0xc6,0xdc,0x6b,0xe9,0xc6,0xa8,
	0x36,0x1e,0x41,0x84,0x5a,0x5f,0x29,0x56,
	0xe2,0xa5,0x24,0x13,0x8f,0x1d,0xd3,0xae,
	0x68,0x63,0xc5,0x38,0xfe,0x0e,0x7e,0xb8,
	0xbf,0x6f,0x16,0x82,0x53,0xdb,0x88,0x81,
	0x6f,0x19,0xde,0xee,0x69,0xa3,0x23,0xe8,
	0xfe,0xfe,0x74,0xb4,0x46,0x0f,0x0a,0x01,
	0xd2,0x00,0x48,0xa1,0xe8,0x1b,0xdf,0x28,
	0x61,0xbc,0x2b,0x00,0x43,0x1e,0x3e,0xd8,
	0x84,0x67,0x29,0x42,0x4f,0xaf,0x88,0xa7,
	0xf1,0x1b,0xdd,0x3a,0x68,0x23,0x4a,0x4a,
	0xb3,0x4e,0x26,0xc9,0x1a,0x17,0x0a,0xb8,
	0x05,0xeb,0x91,0x30,0xca,0x1b,0xdf,0x3a,
	0x68,0x4d,0xfa,0xc7,0xfc,0x2e,0x16,0x98,
	0x22,0x1f,0x16,0x46,0x20,0xf3,0x8f,0x9e,
	0xe9,0x1b,0xce,0x10,0x58,0x5c,0x5d,0xea,
	0xfd,0x26,0xd6,0x0f,0xeb,0x27,0x09,0xf8,
	0x95,0x13,0x94,0xa7,0x18,0x1d,0xd6,0x84,
	0x5f,0x5c,0x5b,0x03,0x04,0x0e,0x40,0x06,
	0xab,0x4f,0x36,0x51,0xec,0x77,0x98,0x27,
	0x93,0x1b,0xcf,0x3a,0x67,0x5c,0xb5,0x82,
	0xaf,0x8e,0x16,0x74,0xa3,0x37,0x1f,0x47,
	0x81,0x5f,0x85,0x83,0xeb,0x1d,0xdb,0x4e,
	0x6d,0x03,0x5c,0xc9,0x17,0x8e,0x06,0x8f,
	0xa8,0x04,0x4a,0xf8,0x33,0x0c,0x65,0xd5,
	0x27,0x1d,0xd3,0xd0,0x6f,0xad,0x20,0xa2,
	0xcc,0x3e,0x2a,0xb1,0x3f,0xf7,0x2a,0xc0,
	0x17,0x07,0x84,0xac,0x5e,0x1b,0xc1,0x3a,
	0x6f,0x4d,0xe3,0x2d,0x5c,0x3e,0x01,0xf4,
	0x23,0xf3,0x48,0x38,0x01,0x07,0x8b,0xc1,
	0x16,0x1d,0xd3,0xa4,0x68,0x7c,0x99,0x08,
	0xb4,0x2e,0x00,0x00,0x1c,0x6f,0x36,0x64,
	0x01,0xeb,0x83,0x9d,0x3f,0x1d,0xdc,0x44,
	0x61,0xad,0x22,0xcf,0x57,0x91,0x96,0xf5,
	0xd3,0xd7,0x08,0xb7,0xff,0x0b,0x88,0xac,
	0xf0,0x1d,0xc6,0x90,0x68,0x29,0x3d,0x12,
	0x61,0xce,0x3f,0xfb,0x5d,0xff,0x29,0xfc,
	0x43,0xe3,0x8b,0x3d,0x0a,0x1d,0xd3,0xce,
	0x6a,0xfc,0x02,0x2a,0xfa,0xce,0x00,0xfc,
	0x3e,0x27,0x1f,0x41,0xe9,0x82,0x25,0xce,
	0xd1,0x1d,0xdc,0x04,0x5c,0x9c,0xfd,0x0a,
	0xa6,0x91,0xff,0x7b,0xa4,0x6f,0x0a,0xfd,
	0x00,0x5f,0x99,0x1a,0x2b,0x19,0xde,0xe6,
	0x5b,0xdc,0xfd,0xb6,0x86,0xb1,0xe0,0xa9,
	0xf7,0x87,0x33,0xf2,0x4f,0x67,0x93,0xa1,
	0x07,0x1b,0xce,0x10,0x50,0xc2,0x80,0x8a,
	0xfb,0x8e,0x15,0x45,0x2d,0xf7,0x0f,0xef,
	0xc8,0x17,0x95,0xd5,0x22,0x1d,0xc2,0x04,
	0x46,0x3c,0xfc,0x15,0xc3,0x9e,0x54,0xf5,
	0xa1,0x67,0x2a,0x55,0x98,0x5b,0x94,0xb5,
	0x49,0x1b,0x9d,0x22,0x42,0x5c,0xd4,0xd2,
	0x39,0xde,0x4e,0xa3,0x22,0xc7,0x28,0xb8,
	0xd3,0x2f,0x98,0x82,0x13,0x1b,0x8e,0x6e,
	0x40,0x1c,0xa8,0x09,0x47,0x1e,0x51,0xf5,
	0x54,0x5f,0x24,0x3d,0x96,0x47,0x95,0x2e,
	0xc0,0x1d,0xc2,0x04,0x4f,0x5c,0xcd,0x18,
	0xff,0x9e,0x6a,0x72,0x26,0x7f,0x28,0xc1,
	0xea,0x5b,0x95,0x49,0x92,0x1d,0xd3,0xc4,
	0x55,0x7c,0x2f,0xe8,0x07,0x1e,0x6b,0xa4,
	0x2b,0x27,0x2a,0x00,0x13,0x98,0x75,0xa9,
	0xef,0x1b,0x93,0x66,0x52,0x9c,0x25,0x49,
	0x46,0xde,0x56,0x05,0xa0,0x47,0x2f,0x57,
	0xf0,0x4d,0xa4,0x31,0x78,0x1b,0x87,0x2c,
	0x55,0x5c,0x00,0x09,0xfa,0x5e,0x21,0x5a,
	0xf0,0x9f,0x0a,0xc3,0x24,0x5b,0x80,0x3e,
	0x88,0x1b,0x87,0x6e,0x42,0x1c,0xa9,0x16,
	0x3b,0x8e,0x53,0xeb,0x2b,0x37,0x29,0x57,
	0xeb,0xc3,0x94,0x2b,0xe1,0x1b,0x8c,0xc2,
	0x43,0x9c,0xb1,0x2c,0x06,0xf1,0xf2,0x84,
	0x78,0x57,0x28,0x54,0xc0,0xf7,0x90,0x55,
	0x0a,0x1b,0x8e,0x72,0x47,0xdc,0xe3,0x28,
	0x42,0xfe,0x56,0xb1,0x6b,0x3f,0x38,0x6d,
	0x88,0x13,0x98,0x1e,0xbe,0x1b,0x8c,0xaa,
	0x57,0xfc,0xa1,0xe9,0x5a,0x6e,0x01,0xb4,
	0xe3,0xef,0x0a,0x78,0x01,0xeb,0x8f,0x5e,
	0x2a,0x1b,0x9f,0x42,0x44,0xbc,0xd8,0xe0,
	0x2e,0x9e,0x4b,0x5f,0xdb,0x3f,0x27,0x44,
	0xee,0x57,0x9d,0xa5,0x38,0x1b,0x93,0x66,
	0x46,0xfc,0xa8,0xa9,0x78,0xbe,0x4e,0x0e,
	0xa8,0x9f,0x28,0x02,0xc1,0x6d,0xbf,0xa1,
	0x19,0x19,0xca,0xe6,0x44,0x3c,0xac,0xe3,
	0x46,0x8e,0x13,0xf4,0x88,0x77,0x29,0x86,
	0x00,0xf3,0x95,0xd9,0x2a,};

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /*__VOICE_H */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
