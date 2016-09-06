//*******************************************************************************************************
// LED_lib.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A library to light the LED's; they will be displayed in a linear or random sequence which depends on
// the setting of the DIP, and they will flash different sequences when the user wins or loses. 
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#include "LED_lib.h"

void InitUserLED(int LED, int state)
{
    //LED can only pass numbers 1-4; state indicates whether light is on or off
    LED -= 1;
    //set the pin to GPIO function; clear relevant bits of PTCPAR
    MCF_GPIO_PTCPAR &= ~(3 << (2*LED));
    //indicates the pin is an output; set relevant bits of DDRTC
    MCF_GPIO_DDRTC |= (1 << LED);
    //set the port to the desired state
    if(state == 1)
    {
        MCF_GPIO_PORTTC |= (1 << LED);
    }
    else
    {
        MCF_GPIO_PORTTC &= ~(1 << LED);
    }
}

void SetUserLED(int LED, int state)
{
    LED -= 1;
    if(state == 1)
    {
        MCF_GPIO_PORTTC |= (1 << LED);
    }
    else
    {
        MCF_GPIO_PORTTC &= ~(1 << LED);
    }
}

int GetUserLED(int LED)
{
    LED -= 1;
    return MCF_GPIO_SETTC & (1 << LED);
}