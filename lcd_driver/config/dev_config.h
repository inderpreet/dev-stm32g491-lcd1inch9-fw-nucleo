/*****************************************************************************
* File Name: dev_config.h
*
* Version 1.00
*
* Author: Ip_v1
* 
* Description:
*   Add a description like ... This file contains the code to 
*   
*****************************************************************************/

#ifndef DEV_CONFIG_H_
#define DEV_CONFIG_H_

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Included Headers
******************************************************************************/
#include <stdint.h>
#include <stdio.h>

#include "Debug.h"
#include "main.h"

/******************************************************************************
* Defines : Key Assignment Constants
*****************************************************************************/ 
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/*
 * RST -> PA9
 * DC->PA8
 * CS->PB6
 * BL->PC7
 */
#define DEV_RST_PIN     RST_GPIO_Port,RST_Pin
#define DEV_DC_PIN      DC_GPIO_Port,DC_Pin
#define DEV_CS_PIN			CS_GPIO_Port,CS_Pin
#define DEV_BL_PIN			TIM3->CCR2

#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) HAL_GPIO_ReadPin(_pin)

#define DEV_Delay_ms(__xms) HAL_Delay(__xms)

#define DEV_Set_PWM(_Value)     DEV_BL_PIN= _Value

/*****************************************************************************
*   Function Prototypes
*****************************************************************************/
void DEV_SPI_WRITE(UBYTE _dat);
int DEV_Module_Init(void);
void DEV_Module_Exit(void);

#ifdef __cplusplus
}
#endif

#endif /* DEV_CONFIG_H_ */

/****************************End of File*************************************/
