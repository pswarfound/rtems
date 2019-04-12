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

#include <libchip/sersupp.h>

#include <bsp.h>
#include <bsp/io.h>
#include <bsp/rcc.h>
#include <bsp/irq.h>
#include <libchip/serial.h>
#undef CR1
#undef CR2
#undef CR3
#include <bsp/stm32f7-hal/stm32f7xx_hal.h>

static USART_HandleTypeDef hwnd_usart;

void HAL_USART_MspInit(USART_HandleTypeDef *husart)
{
    //GPIO端口设置
	GPIO_InitTypeDef GPIO_Initure;

	if(husart->Instance==USART2)//如果是串口1，进行串口1 MSP初始化
	{
		__HAL_RCC_GPIOA_CLK_ENABLE();                   //使能GPIOA时钟
		__HAL_RCC_USART2_CLK_ENABLE();                  //使能USART1时钟

		GPIO_Initure.Pin=GPIO_PIN_2;                    //PA9
		GPIO_Initure.Mode=GPIO_MODE_AF_PP;              //复用推挽输出
		GPIO_Initure.Pull=GPIO_PULLUP;                  //上拉
		GPIO_Initure.Speed=GPIO_SPEED_FAST;             //高速
		GPIO_Initure.Alternate=GPIO_AF7_USART2; //复用为USART1
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);             //初始化PA9

		GPIO_Initure.Pin=GPIO_PIN_3;                    //PA10
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);             //初始化PA10

#if EN_USART1_RX
		HAL_NVIC_EnableIRQ(USART1_IRQn);                                //使能USART1中断通道
		HAL_NVIC_SetPriority(USART1_IRQn,3,3);                  //抢占优先级3，子优先级3
#endif
	}
}

void usart_initialize(int minor)
{
  const console_tbl *ct = Console_Port_Tbl [minor];

  hwnd_usart.Instance = USART2;
  USART_InitTypeDef *init = &hwnd_usart.Init;
  init->BaudRate = 115200;
  init->WordLength = UART_WORDLENGTH_8B;
  init->StopBits = UART_STOPBITS_1;
  init->Parity = UART_PARITY_NONE;
  init->Mode = UART_MODE_TX_RX;
  HAL_USART_Init(&hwnd_usart);
}

static int usart_first_open(int major, int minor, void *arg)
{
  rtems_libio_open_close_args_t *oc = (rtems_libio_open_close_args_t *) arg;
  struct rtems_termios_tty *tty = (struct rtems_termios_tty *) oc->iop->data1;
  const console_tbl *ct = Console_Port_Tbl [minor];
  console_data *cd = &Console_Port_Data [minor];

  cd->termios_data = tty;
  rtems_termios_set_initial_baud(tty, ct->ulClock);

  return 0;
}

static int usart_last_close(int major, int minor, void *arg)
{
  return 0;
}

static int usart_read_polled(int minor)
{
  const console_tbl *ct = Console_Port_Tbl [minor];

  if (__HAL_USART_GET_FLAG(&hwnd_usart, USART_FLAG_RXNE)) {
	char c;
	if (HAL_OK != HAL_USART_Receive(&hwnd_usart, &c, 1, 1000)) {
		return -1;
	}
    return c;
  } else {
    return -1;
  }
}

static void usart_write_polled(int minor, char c)
{
  const console_tbl *ct = Console_Port_Tbl [minor];

  while (!__HAL_USART_GET_FLAG(&hwnd_usart, USART_FLAG_TC)) {
    /* Wait */
  }
  HAL_USART_Transmit(&hwnd_usart, (uint8_t*)&c, 1, 1000);
}

static ssize_t usart_write_support_polled(
  int minor,
  const char *s,
  size_t n
)
{
  ssize_t i = 0;

  for (i = 0; i < n; ++i) {
    usart_write_polled(minor, s [i]);
  }

  return n;
}

static int usart_set_attributes(int minor, const struct termios *term)
{
  return -1;
}

const console_fns stm32f4_usart_fns = {
  .deviceProbe = libchip_serial_default_probe,
  .deviceFirstOpen = usart_first_open,
  .deviceLastClose = usart_last_close,
  .deviceRead = usart_read_polled,
  .deviceWrite = usart_write_support_polled,
  .deviceInitialize = usart_initialize,
  .deviceWritePolled = usart_write_polled,
  .deviceSetAttributes = usart_set_attributes,
  .deviceOutputUsesInterrupts = false
};

