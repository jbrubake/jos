/**************************************************************************
 * @file kernel_main.c
 * @author Jeremy Brubaker
 * @brief Kernel entry point
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
#include "irq.h"
#include "mini_uart.h"
#include "printk.h"
#include "timer.h"
#include "utils.h"

void
kernel_main(void)
{
	uart_init ();

    printk ("Exception Level: %d\r\n", get_el ());

    exception_vector_init ();
    timer_init (1000);
    enable_interrupt_controller ();
    enable_irq ();

	while (1) {
		uart_send (uart_recv ());
	}
}
