//*******************************************************************************************************
// DIP_lib.h
// Lab 2: Press Your Luck! 
//
// DESCRIPTION:
// A header file for the DIP switch library.
//
// AUTHORS:
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
//********************************************************************************************************
#ifndef DIP_LIB_H_
#define DIP_LIB_H_
#include "support_common.h"

void InitUserDIP(int DIP);
int GetUserDIP(int DIP);

#endif // DIP_LIB_H_