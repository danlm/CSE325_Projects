//*******************************************************************************************************
// LED_lib.h
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A header file for the LED library.
//
// AUTHORS
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#ifndef LED_LIB_H_
#define LED_LIB_H_
#include "support_common.h"

void InitUserLED(int LED, int state);
void SetUserLED(int LED, int state);
int GetUserLED(int LED);

#endif // LED_LIB_H_