//*******************************************************************************************************
// PB_lib.h
// Lab 2: Press Your Luck!
//
// DESCRIPTION:
// A header file for the push button library.
//
// AUTHORS
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#ifndef PB_LIB_H_
#define PB_LIB_H_
#include "support_common.h"

void InitUserPB(int PB);
int GetUserPB(int PB);

#endif // PB_LIB_H_