//*******************************************************************************************************
// main.c
// Lab 2: Press Your Luck!
//
// DESCRIPTION: 
// This code is for the game in Project 2; the user pushes the first button (SW1) after an LED is dis-
// played and wins if it is correct during a linear or random sequence. If the user pushes the button 
// when the sequence is playing and it is not the LED first shown, it is considered losing and it will
// restart the game. Every time the user wins, the sequence (linear or random) will speed up until the
// user loses.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************

#include "LED_lib.h"
#include "DIP_lib.h"
#include "PB_lib.h"
#include "RNG_lib.h"
#include "DMA_lib.h"
#include "support_common.h" /* includes peripheral declarations and more */
#include <stdio.h>

int main(void)
{	
	// Constants
    const int BASE_DELAY = 100000; // in microseconds
    const int TRUE = 1;
	
	//Variables
    int current, random, hasWon, delay;
	
	//Initializing board parts to be used
    int i = 0;
	for(i = 1; i < 5; i++)
	{
	    InitUserLED(i,0);
	}
	InitUserDIP(1);
	InitUserPB(1);
	InitUserRNG();
	InitUserDMA();
	
	// Actual game execution
	for(;;) 
	{	
	    // Initial settings for the beginning of the game
	    hasWon = TRUE;
	    delay = BASE_DELAY;
	    current = 1;
        while (hasWon == TRUE)
        {
            // Check winning light and game mode
			int winning = GetUserRNG(2); //random value
            SetUserLED(winning, 1);
            dtim0_delay_us(BASE_DELAY);
            //Check mode
            if (GetUserDIP(1) == 1)
                random = 1;
            else
                random = 0;
            SetUserLED(winning, 0);
            dtim0_delay_us(BASE_DELAY);
            
			// Change lights and wait for button press
            do
            {
                    
                if (random == 1)
                {
                    SetUserLED(current, 0);
                    current = GetUserRNG(2); //random
                    SetUserLED(current, 1);
                }
                else
                {
                    SetUserLED(current, 0);
                    ++current;
                    if(current < 5)
                    {
                      SetUserLED(current, 1);  
                       //turn on first
                    }
                    else
                    {
                      current = 1; //turn on first
                      SetUserLED(current, 1);
                    }
                }
                dtim0_delay_us(delay);
                //Insert delay
                
            }while (!GetUserPB(1));
            
            //Set speed back to normal
            if(current == winning)
            {
                int i = 0;
                int j = 0;
                for(i = 0; i <= 3; i++)
                {   
                    dtim0_delay_us(BASE_DELAY);
                    for(j = 1; j < 5; j++)
                    {
                        SetUserLED(j, 1);
                    }
                    //Delay
                    dtim0_delay_us(BASE_DELAY);
                    for(j = 1; j < 5; j++)
                    {
                        SetUserLED(j, 0);
                    }
                }
            }
            else
            {   
                int i = 0;
                int j = 0;
                hasWon = !TRUE; // Reset game after losing animation
                dtim0_delay_us(BASE_DELAY);
                for(j = 1; j < 5; j++)
                {
                   SetUserLED(j, 1);
                }
                dtim0_delay_us(BASE_DELAY);
                for(i = 1; i < 5; i++)
                {    
                    SetUserLED(i, 0);
                    dtim0_delay_us(BASE_DELAY);
                    //Delays?
                }
            }
            if(hasWon == TRUE)
            {
                delay /= 2; // Speed up light choosing
            }
            current = 1;
	    }
	}
}
