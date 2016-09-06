//*******************************************************************************************************
// RNG_lib.h
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A header file for the Random Number Generator library.
//
// AUTHORS
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#ifndef RNG_LIB_H_
#define RNG_LIB_H_
#include "support_common.h"

void InitUserRNG(void);
int GetUserRNG(int bits);

#endif // RNG_LIB_H_