/*
 * led.c
 *
 *  Created on: Feb 29, 2024
 *      Author: gabrteta22
 */
#include "led.h"
#include "stm32l0xx_ll_tim.h"

typedef struct
{
	int current_value;
	int increment_val;
} Led_info;

static Led_info info = {.current_value = 0, .increment_val = 1};

void LedStart(void)
{
	LL_TIM_EnableCounter(TIM2);
	LL_TIM_CC_EnableChannel(TIM2,LL_TIM_CHANNEL_CH1);
	LL_TIM_EnableCounter(TIM21);
	LL_TIM_EnableIT_UPDATE(TIM21);

}

// value entre 0 et 255
void LedSetValue(uint8_t value)
{
	LL_TIM_OC_SetCompareCH1(TIM2,(uint32_t)value);
	info.current_value = value;
}

void LedPulse(void)
{
	info.current_value += info.increment_val;
	if(info.current_value == 255) info.increment_val = -1;
	else if(info.current_value == 0) info.increment_val = 1;
	LedSetValue(info.current_value);
}
