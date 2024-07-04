/*****************************************************************************
* File Name: debug.h
*
* Version 1.00
*
* Author: Ip_v1
* 
* Description:
*   Add a description like ... This file contains the code to 
*   
*****************************************************************************/

#ifndef DEBUG_H_
#define DEBUG_H_

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Included Headers
******************************************************************************/
#include "stdio.h"

/******************************************************************************
* Defines : Key Assignment Constants
*****************************************************************************/ 
#define DEV_DEBUG 1
#if DEV_DEBUG
	#define Debug(__info,...) printf("Debug : " __info,##__VA_ARGS__)
#else
	#define DEBUG(__info,...)
#endif

#ifdef __cplusplus
}
#endif

/*****************************************************************************
*   Function Prototypes
*****************************************************************************/


#endif /* DEBUG_H_ */

/****************************End of File*************************************/
