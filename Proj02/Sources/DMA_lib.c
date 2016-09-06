//*******************************************************************************************************
// DMA_lib.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A library for the timer being used (DTMA0); this is for timing the sequences and speeding up the
// game until the user loses.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#include "DMA_lib.h"

void InitUserDMA(void)
{
    MCF_DTIM0_DTMR |= 0x0001;
    MCF_DTIM0_DTMR &= 0xFFFE;
    MCF_DTIM0_DTMR |= 0xFF02;
    MCF_DTIM0_DTXMR |= 0x40;
}

void SetUserDMA(int prescaler) //Must be between 1 and 256
{
    --prescaler;
    prescaler = prescaler << 8;
    MCF_DTIM0_DTMR |= prescaler;
    MCF_DTIM0_DTMR &= (prescaler + 0xFF);
    
}

int GetUserDMA(void)
{
    return ((MCF_DTIM0_DTMR & 0xFF00) >> 8);
}

// Delays execution for the specified number of microseconds
void dtim0_delay_us(uint32 u) {
    MCF_DTIM0_DTER = 0x03; // Clear Events
    MCF_DTIM0_DTCN = 0x00000000; // Clear Timer Counter
    MCF_DTIM0_DTRR = u-1;
    MCF_DTIM0_DTMR |= 0x0001;
    while ( !(MCF_DTIM0_DTER & 0x02)){}
}
