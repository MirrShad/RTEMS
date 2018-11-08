/*
 * Copyright (c) 2018 Andy Wu.  All rights reserved.
 *
 */

#include "stm32f4xx.h"
#include "DIO.h"

void DIO_init( void )
{
  uint32_t RCC_AHB1Periphx;
  GPIO_InitTypeDef GPIO_InitStructure;
	
  /* LED config */
//bug!!!! may be more than 2 led, try to use macro to fix this bug

  RCC_AHB1Periphx = RCC_AHB1Periph_GPIOA<< (((uint32_t)GPIOG-(uint32_t)GPIOA)/0x400);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periphx, ENABLE);

  RCC_AHB1Periphx = RCC_AHB1Periph_GPIOA<< (((uint32_t)GPIOG-(uint32_t)GPIOA)/0x400);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periphx, ENABLE);

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
  GPIO_Init(GPIOG, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; 
  GPIO_Init(GPIOG, &GPIO_InitStructure);

#ifdef USE_STDPERIPH_DRIVER 
  GPIO_SetBits(GPIOG,GPIO_Pin_9);
  GPIO_SetBits(GPIOG,GPIO_Pin_10);
#endif
}

