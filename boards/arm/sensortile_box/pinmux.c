/*
 * Copyright (c) 2019 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/pinmux.h>
#include <sys/sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* pin assignments for SensorTile.box board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_1
	{STM32_PIN_PA9,  STM32L4X_PINMUX_FUNC_PA9_USART1_TX},
	{STM32_PIN_PA10, STM32L4X_PINMUX_FUNC_PA10_USART1_RX},
#endif	/* CONFIG_UART_1 */
#ifdef CONFIG_UART_2
	{STM32_PIN_PA2, STM32L4X_PINMUX_FUNC_PA2_USART2_TX},
	{STM32_PIN_PA3, STM32L4X_PINMUX_FUNC_PA3_USART2_RX},
#endif	/* CONFIG_UART_2 */
#ifdef CONFIG_I2C_1
	{STM32_PIN_PB6, STM32L4X_PINMUX_FUNC_PB6_I2C1_SCL},
	{STM32_PIN_PB7, STM32L4X_PINMUX_FUNC_PB7_I2C1_SDA},
#endif /* CONFIG_I2C_1 */
#ifdef CONFIG_I2C_3
	{STM32_PIN_PG7, STM32L4X_PINMUX_FUNC_PG7_I2C3_SCL},
	{STM32_PIN_PG8, STM32L4X_PINMUX_FUNC_PG8_I2C3_SDA},
#endif /* CONFIG_I2C_3 */
#ifdef CONFIG_SPI_1
	{STM32_PIN_PE12, STM32L4X_PINMUX_FUNC_PE12_SPI1_NSS},
	{STM32_PIN_PE13, STM32L4X_PINMUX_FUNC_PE13_SPI1_SCK},
	{STM32_PIN_PE14, STM32L4X_PINMUX_FUNC_PE14_SPI1_MISO},
	{STM32_PIN_PE15, STM32L4X_PINMUX_FUNC_PE15_SPI1_MOSI},
#endif /* CONFIG_SPI_1 */
#ifdef CONFIG_SPI_2
	/* SPI2 on the ST Morpho Connector CN10 pins 16, 30, 28, 26*/
	{STM32_PIN_PB12, STM32L4X_PINMUX_FUNC_PB12_SPI2_NSS},
	{STM32_PIN_PB13, STM32L4X_PINMUX_FUNC_PB13_SPI2_SCK},
	{STM32_PIN_PB14, STM32L4X_PINMUX_FUNC_PB14_SPI2_MISO},
	{STM32_PIN_PB15, STM32L4X_PINMUX_FUNC_PB15_SPI2_MOSI},
#endif /* CONFIG_SPI_1 */
#ifdef CONFIG_SPI_3
	{STM32_PIN_PA15, STM32L4X_PINMUX_FUNC_PA15_SPI3_NSS},
	{STM32_PIN_PB3, STM32L4X_PINMUX_FUNC_PB3_SPI3_SCK},
	{STM32_PIN_PB4, STM32L4X_PINMUX_FUNC_PB4_SPI3_MISO},
	{STM32_PIN_PB5, STM32L4X_PINMUX_FUNC_PB5_SPI3_MOSI},
#endif /* CONFIG_SPI_3 */
#ifdef CONFIG_USB_DC_STM32
	{STM32_PIN_PA11, STM32L4X_PINMUX_FUNC_PA11_OTG_FS_DM},
	{STM32_PIN_PA12, STM32L4X_PINMUX_FUNC_PA12_OTG_FS_DP},
#endif	/* CONFIG_USB_DC_STM32 */
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
	 CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
