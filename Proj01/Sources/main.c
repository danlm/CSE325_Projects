//**************************************************************************************************************
// FILE: main.c
//
// DECRIPTION
// A first TWR-MCF5225X program. Uses the GPIO module and Port TC to flash the LED's to count from 0-15 
// on the TWR-MCF5225x microcontroller board.
//
// AUTHORS
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//**************************************************************************************************************
#include "support_common.h"
#define forever for(;;)
//**************************************************************************************************************
// FUNCTION: busy_delay()
//
// DESCRIPTION
// Implements a very sleazy busy delay which just kills time. The main problem with this technique is that it is
// not entirely clear what the value of p_delay should be to delay for n microseconds or m milliseconds. The
// other issue is that while this busy delay is busy delaying, the processor cannot do anything else more pro-
// ductive. We will see a better way to do this later on using the DMA timers (DTIM module).
//**************************************************************************************************************
static void busy_delay(int p_delay)
{
    int x = 1;
    int i = 0;
    for (i = 0; i < p_delay; ++i) {
        x = x * 2 + 1;
    }
}
/***************************************************************************************************************
// FUNCTION: led_off()
//
// DESCRIPTION
// Turns LED 1, 2, 3, or 4 off.
//
// INPUTS
// p_led should be 1, 2, 3, or 4.
//*************************************************************************************************************/
static void led_off(int p_led)
{
MCF_GPIO_CLRTC = (uint8)(~(1 << (p_led - 1)));
}
/***************************************************************************************************************
// FUNCTION: led_on()
//
// DESCRIPTION
// Turns LED 1, 2, 3, or 4 on.
//
// INPUTS
// p_led should be 1, 2, 3, or 4.
//*************************************************************************************************************/
static void led_on(int p_led)
{
MCF_GPIO_SETTC = (uint8)(1 << (p_led - 1));
}
/***************************************************************************************************************
// FUNCTION: main()
//
// DESCRIPTION
// Flashes LED's 1 and 3 on and off at about a 2 Hz rate.
//
// __declspace(noreturn) tells the compiler that even though main() returns an int, don't complain about the
// fact that we do not have a return statement at the end of the function. The C language specification states
// very clearly that main() must return an int. But, this program will never end, so we forgo the return state-
// ment.
//*************************************************************************************************************/
__declspec(noreturn) int main()
{
    // Program Port TC Pin Assignment Register (PTCPAR) so pins 0, 1, 2, and 3 are configured for the general-
    // purpose I/O (GPIO) function.
    MCF_GPIO_PTCPAR = MCF_GPIO_PTCPAR_PTCPAR0(MCF_GPIO_PTCPAR_DTIN0_GPIO) |
    MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN1_GPIO) |
    MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN2_GPIO) |
    MCF_GPIO_PTCPAR_PTCPAR1(MCF_GPIO_PTCPAR_DTIN3_GPIO);
    // Program Port TC Data Direction Register (DDRTC) so pins 0, 1, 2, and 3 are configured as output pins.
    MCF_GPIO_DDRTC = MCF_GPIO_DDRTC_DDRTC0 |
    MCF_GPIO_DDRTC_DDRTC1 |
    MCF_GPIO_DDRTC_DDRTC2 |
    MCF_GPIO_DDRTC_DDRTC3;
    // Turn off all LED's.
    led_off(1); led_off(2); led_off(3); led_off(4);
    forever {
    int i = 0; // counter for all binary numbers (0-15) with 4 bits
    int j = 0; // counter for the LEDS (1-4)
    for(i = 0; i < 16; ++i)
    {
        int k = 1; // counter for binary place value - only 1 bit is high for each round 
        for(j = 1; j <= 4; ++j) // for each value of i, determine which LED's should be turned on
        {
            if(i & k) // Use AND to see if i has a 1 in the same place as k does
            {
                led_on(j);
            }
            else
            {
                led_off(j);
            }
            k = k * 2; // Set the next place value high
        }
        // Delay so that you can see the lights flash
        busy_delay(500000);
        // Clear for next number
        led_off(1); led_off(2); led_off(3); led_off(4);
        busy_delay(500000);
    }
    }
}