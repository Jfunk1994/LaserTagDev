/*
 * timers.c
 *
 *  Created on: Mar 23, 2016
 *      Author: Ivy
 */

#include "main.h"
#include "stm32f30x.h"

int onOffBit = 0;

void timerInit(){

	RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_Cmd(TIM2,DISABLE);
	TIM_TimeBaseInitTypeDef* timerInit;
	TIM_TimeBaseStructInit(timerInit);
	timerInit->TIM_Period=1;
	TIM_TimeBaseInit(TIM2,timerInit);
	TIM_ITConfig(TIM2,28,ENABLE);
	TIM_Cmd(TIM2,ENABLE);

	TIM_TimeBaseInit(TIM2,timerInit);
	/*
	//GPIOB_PSOR |= (1 << 20); //Toggle SI on
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //enable timer 2
	TIM2->CR1 &= (0 << 0); //Counter disabled
	TIM2->DIER |= (1<<6); //Trigger interrupt enable
	NVIC_EnableIRQ(TIM2_IRQn); //enable TIM2 global Interrupts
	TIM2->CNT = 0; // starting value for counter
	TIM2->ARR = TIM2_CNT_VALUE; //set overflow value
	//set alignment?
	//set debug operation?
	//divide clock?
	//set clock source?
	//set duty cycle?
	TIM2->CR1 |= (1<<0);//enable counter
	*/
}

void TIM2_IRQHandler(){

	TIM_ClearFlag(TIM2,0);
	TIM_ClearFlag(TIM2,6);
	//TIM2->SR &=(0<<6);//clear interrupt flag
	//TIM2->SR &=(0<<0);//clear update interrupt flag

	//interact with pins using GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)

	// do stuff

	if(onOffBit==1)
	{
		GPIO_WriteBit(GPIOE,9,0);
		onOffBit=0;
	}
	else
	{
		GPIO_WriteBit(GPIOE,9,1);
		onOffBit=1;
	}


}


