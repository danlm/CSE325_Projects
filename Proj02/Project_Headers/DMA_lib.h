//*******************************************************************************************************
// DMA_lib.h
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A header file for the DMA0 timer library.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#ifndef DMA_LIB_H_
#define DMA_LIB_H_
#include "support_common.h"

void InitUserDMA(void);
void SetUserDMA(int prescaler);
int GetUserDMA(void);
void dtim0_delay_us(uint32 u);

#endif // DMA_LIB_H_