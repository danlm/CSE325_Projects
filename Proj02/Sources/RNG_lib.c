//*******************************************************************************************************
// RNG_lib.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A library for the random number generator; this will be used after SW2 (trigger 1) is moved to the
// ON position for the user to play the game in a random sequence rather than a linear sequence.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#include "RNG_lib.h"

void InitUserRNG(void)
{
    //Set lower 5 bits of RNG's Control Register to start generating and suppress errors
    MCF_RNGA_RNGCR &= 0x0D; 
    MCF_RNGA_RNGCR |= 0x0D;
}
int GetUserRNG(int bits) // Specify the size of the random number you want, from 1 to 32 bits(entire register)
{
	// Make sure RNGOUT[OFL] is set first
    while(!(MCF_RNGA_RNGSR & 0x100)) {}
    return MCF_RNGA_RNGOUT & ((1 << bits) - 1);
}