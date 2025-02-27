/*****************************************************************************
 * File Name: dev_config.c
 *
 * Version 1.00
 *
 * Author: Ip_v1
 *
 * Description:
 *   Add a description like ... This file contains the code to
 *
 *****************************************************************************/

/******************************************************************************
 * Included headers
 ******************************************************************************/
#include "dev_config.h"

/*****************************************************************************
 *   Extern Global Variables
 ******************************************************************************/
extern SPI_HandleTypeDef hspi1;

extern TIM_HandleTypeDef htim3;

/*****************************************************************************
 *   Global Variables
 ******************************************************************************/

/******************************************************************************
 *   Function Code
 ******************************************************************************/

void DEV_delay_ms(uint16_t xms)
{
	HAL_Delay(xms);
}

void DEV_SPI_WRITE(UBYTE _dat)
{
	HAL_SPI_Transmit(&hspi1, (uint8_t*) &_dat, 1, 500);
}

int DEV_Module_Init(void)
{
	DEV_Digital_Write(DEV_DC_PIN, 1);
	DEV_Digital_Write(DEV_CS_PIN, 1);
	DEV_Digital_Write(DEV_RST_PIN, 1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
	return 0;
}

void DEV_Module_Exit(void)
{
	DEV_Digital_Write(DEV_DC_PIN, 0);
	DEV_Digital_Write(DEV_CS_PIN, 0);
	DEV_Digital_Write(DEV_RST_PIN, 0);
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_2);
}
