/*
 * gpio.c
 *
 *  Created on: Mar 30, 2016
 *      Author: Ivy
 */

#include "stm32f30x.h"
#include "main.h"
#include "stm32f30x_gpio.h"

void gpioInit()
{
	RCC->APB2ENR |= (1<<6);//RCC_AHBENR_GPIOEEN; //GPIOE Clock Enable

	//GPIOE-> |= (1<<1);
	GPIO_InitTypeDef* initGPIOE; //instantiate gpio init struct
	initGPIOE->GPIO_Pin = 9; //set pin 9
	initGPIOE->GPIO_Mode=GPIO_Mode_OUT;//set gpio to output
	initGPIOE->GPIO_OType=GPIO_OType_PP; //set to push/pull
	initGPIOE->GPIO_PuPd=GPIO_PuPd_NOPULL; //set to no push/pull
	initGPIOE->GPIO_Speed=GPIO_Speed_2MHz; //set speed to medium(2MHZ)

	GPIO_Init(GPIOE,initGPIOE); //call initialization macro with GPIOE and struct

	//interact with pins using GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
}
