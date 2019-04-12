/*
 * Copyright (c) 2012 Sebastian Huber.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Obere Lagerstr. 30
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#include <bsp.h>
#include <bsp/io.h>
#include <bsp/irq.h>
#include <bsp/bootcard.h>
#include <bsp/irq-generic.h>
#include <assert.h>
#include <bsp/stm32f4.h>
#include <bsp/stm32f7-hal/stm32f7xx_hal.h>

#define BLINK_GPIOx(_N)                 ((GPIO_TypeDef *)(GPIOA_BASE + (GPIOB_BASE-GPIOA_BASE)*(_N)))
#define BLINK_PIN_MASK(_N)              (1 << (_N))
#define BLINK_RCC_MASKx(_N)             (RCC_AHB1ENR_GPIOAEN << (_N))


#define BLINK_PORT_NUMBER               (1)
#define BLINK_PIN_NUMBER                (1)
#define BLINK_ACTIVE_LOW                (1)


inline void
__attribute__((always_inline))
blink_led_off(void)
{
#if (BLINK_ACTIVE_LOW)
    HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
        BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_SET);
#else
    HAL_GPIO_WritePin(BLINK_GPIOx(BLINK_PORT_NUMBER),
        BLINK_PIN_MASK(BLINK_PIN_NUMBER), GPIO_PIN_RESET);
#endif
}

uint32_t SystemCoreClock = 216000000;
const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8] = {0, 0, 0, 0, 1, 2, 3, 4};

void bsp_start( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;

	// Configure pin in output push/pull mode
	GPIO_InitStructure.Pin = BLINK_PIN_MASK(BLINK_PIN_NUMBER);
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(BLINK_GPIOx(BLINK_PORT_NUMBER), &GPIO_InitStructure);
	usart_initialize(0);
	// Start with led turned off
	blink_led_off();

  bsp_interrupt_initialize();
}
