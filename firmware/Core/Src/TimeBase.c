/*
 * TimeBase.c
 *
 *  Created on: Mar 14, 2024
 *      Author: gabrteta22
 */
#include "TimeBase.h"
#include "led.h"
#include "stm32l0xx_ll_tim.h"

void TimeBaseStartIT(void)
{
	LL_TIM_ClearFlag_UPDATE(TIM21);
	LedPulse();
}
