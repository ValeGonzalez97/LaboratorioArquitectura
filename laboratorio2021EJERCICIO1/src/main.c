#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

void SysTick_Handler(void)
{
    HAL_IncTick();
}


void Iniciacion_GPIO_LEDS(void){
    GPIO_InitTypeDef GPIO_InitStruct;
        __HAL_RCC_GPIOD_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_PULLDOWN;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

        HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
}

int main(void)
{


	SysTick_Handler ();
	HAL_Init();
	Iniciacion_GPIO_LEDS ();


  while (1)
    {
	  // Encender LEDs
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12,RESET);

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13,RESET);

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14,RESET);

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,SET);
	  HAL_Delay(300);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15,RESET);




	}


}
