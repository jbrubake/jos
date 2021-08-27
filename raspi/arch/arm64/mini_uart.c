/**************************************************************************
 * @file mini_uart.c
 * @author Jeremy Brubaker
 * @brief Mini UART API
 *
 * This file is part of jos
 *
 * Copyright (c) 2020, Jeremy Brubaker
 ***************************************************************************
 * jos is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * jos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with jos.  If not, see <https://www.gnu.org/licenses/>.
 **************************************************************************/
#include <stdint.h>

#include "utils.h"
#include "peripherals/mini_uart.h"
#include "peripherals/gpio.h"

void
uart_send (char c)
{
    // Block until ready to send
    while (!(get32 (AUX_MU_LSR_REG) & 0x20))
        ;

	put32 (AUX_MU_IO_REG, c);
}

char
uart_recv (void)
{
    // Block until a byte is available
    while (!(get32 (AUX_MU_LSR_REG) & 0x01))
        ;

	return get32 (AUX_MU_IO_REG) & 0xFF;
}

int
uart_print (const char* s)
{
    int i = 0;
	for (; *s != '\0'; s++, i++) {
		uart_send (*s);
	}

    return i;
}

int
uart_init (void)
{
    // TODO: replace magic numbers

	uint32_t selector;

    // Attack gpio14 and gpio15 to the Mini UART
	selector = get32 (GPFSEL1);
	selector &= ~(7<<12);       // clean gpio14
	selector |=   2<<12;        // set alt5 for gpio14
	selector &= ~(7<<15);       // clean gpio15
	selector |=   2<<15;        // set alt5 for gpio15
	put32 (GPFSEL1, selector);

    // Remove pull-up/down states from gpio14 and gpio15
	put32 (GPPUD, 0);                     // select neither state
	delay (150);                          // required delay
	put32 (GPPUDCLK0, (1<<14) | (1<<15)); // set gpio14 and gpio15
	delay (150);                          // required delay
	put32 (GPPUDCLK0, 0);                 // remove the clock

	put32 (AUX_ENABLES, 1);       // enable Mini UART
	put32 (AUX_MU_CNTL_REG, 0);   // disable auto flow control, receiver and transmitter
	put32 (AUX_MU_IER_REG, 0);    // disable receive and transmit interrupts
	put32 (AUX_MU_LCR_REG, 3);    // enable 8-bit mode
	put32 (AUX_MU_MCR_REG, 0);    // set RTS line to be always high
	put32 (AUX_MU_BAUD_REG, 270); // set baud rate to 115200

	put32 (AUX_MU_CNTL_REG, 3); // enable transmitter and receiver

    return 0;
}
