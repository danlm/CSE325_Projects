//*******************************************************************************************************
// DIP_lib.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A library for the DIP switch; if it is set to 0, the LED's will display a linear sequence for the
// game else they will display a random sequence (when set to 1).
//
// AUTHORS
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#include "DIP_lib.h"

void InitUserDIP(int DIP)
{
    //DIP can only pass numbers 1-4; state indicates whether switch is on or off
    DIP -= 1;
    //Set the pin to GPIO function; clear relevant bit of PDDPAR
    MCF_GPIO_PDDPAR &= ~(1 << (DIP+4));
    //Indicates the pin is an input; clear relevant bit of DDRDD
    MCF_GPIO_DDRDD &= ~(1 << (DIP+4));
}

int GetUserDIP(int DIP)
{
    DIP -= 1;
    //Checks the SETDD register for switch state: if on, it will return a 1, else it returns a 0
    return (MCF_GPIO_SETDD & (1 << (DIP+4))) ? 0 : 1;
}