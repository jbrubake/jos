/**************************************************************************
 * @file mini_uart.h
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
#ifndef	MINI_UART_H
#define	MINI_UART_H

#include <stdint.h>

/**
 * @brief Initialize the UART system
 *
 * @return -1 on failure
 */
int uart_init (void);
/**
 * @brief Read a byte from the UART
 *
 * @return Byte read
 */
char uart_recv (void);
/**
 * @brief Write a byte to the UART
 *
 * @param c Byte to write
 */
void uart_send (char c);
/**
 * @brief Write a string to the UART
 *
 * @param s String to write
 *
 * @return Number of characters written
 */
int uart_print (const char* s);

#endif
