//*******************************************************************************************************
// PB_lib.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A library for the push buttons; this is for the user to either win or lose
// after the button is pressed at a certain time in the game.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#include "PB_lib.h"

void InitUserPB(int PB)
{
    //PB can only pass numbers 1-2; state indicates whether switch is on or off
    PB -= 1;
    //Set the pin to GPIO function; clear relevant bits of PTAPAR
    MCF_GPIO_PTAPAR &= ~(3 << (2*PB));
    //Indicates the pin is an input; clear relevant bit of DDRTA
    MCF_GPIO_DDRTA &= ~(1 << PB);
}

int GetUserPB(int PB)
{
    PB -= 1;
    //Checks the SETTA register for switch state: if on, it will return a 1, else it returns a 0
    return (MCF_GPIO_SETTA & (1 << PB)) ? 0 : 1;
}