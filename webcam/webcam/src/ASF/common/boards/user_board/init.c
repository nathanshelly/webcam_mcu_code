/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>
#include "camera.h"

void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	
	wdt_disable(WDT);
	
	ioport_init();
		
	gpio_configure_pin(LED_PIN, LED_FLAGS);
	gpio_configure_pin(LED0_GPIO, LED0_FLAGS);
	
	/* Set output direction on the given LED IOPORTs */
	ioport_set_pin_dir(LED_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED_PIN, false);
	
	
	// configure MCU RTS as a gpio and drive it low
	gpio_configure_pin(RTS_LOW, RTS_LOW_FLAGS);
	gpio_configure_pin(RTS_LOW_GPIO, RTS_LOW_GPIO_FLAGS);
	ioport_set_pin_dir(RTS_LOW, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(RTS_LOW, false);
	
	gpio_configure_pin(CAM_RST, CAM_RST_FLAGS);
	ioport_set_pin_dir(CAM_RST, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(CAM_RST, false);

	// configure network status pin
	gpio_configure_pin(NET_PIN, NET_PIN_FLAGS);
	ioport_set_pin_dir(NET_PIN, IOPORT_DIR_INPUT);
	ioport_set_pin_mode(NET_PIN, IOPORT_MODE_PULLUP);

	gpio_configure_pin(PIN_PCK1, PIN_PCK1_FLAGS);
	gpio_configure_pin(TWI0_DATA_GPIO, TWI0_DATA_FLAGS);
	gpio_configure_pin(TWI0_CLK_GPIO, TWI0_CLK_FLAGS);
	
	///* Configure UART pins */
	//#ifdef CONF_BOARD_UART_CONSOLE
	//gpio_configure_group(PINS_UART_PIO, PINS_UART, PINS_UART_FLAGS);
	//#endif
	
	gpio_configure_pin(PIN_USART0_RXD_IDX, PIN_USART0_RXD_FLAGS);
	gpio_configure_pin(PIN_USART0_TXD_IDX, PIN_USART0_TXD_FLAGS);
	gpio_configure_pin(PIN_USART0_CTS_IDX, PIN_USART0_CTS_FLAGS);
	//gpio_configure_pin(PIN_USART0_RTS_IDX, PIN_USART0_RTS_FLAGS);
	
	//gpio_configure_pin(OV_SW_OVT_GPIO, OV_SW_OVT_FLAGS);
	//gpio_configure_pin(OV_RST_GPIO, OV_RST_FLAGS);
	//gpio_configure_pin(OV_FSIN_GPIO, OV_FSIN_FLAGS);
	gpio_configure_pin(OV_HSYNC_GPIO, OV_HSYNC_FLAGS);
	gpio_configure_pin(OV_VSYNC_GPIO, OV_VSYNC_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D2, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D3, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D4, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D5, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D6, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D7, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D8, OV_DATA_BUS_FLAGS);
	gpio_configure_pin(OV_DATA_BUS_D9, OV_DATA_BUS_FLAGS);
}
