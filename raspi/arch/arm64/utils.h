/**************************************************************************
 * @file utils.h
 * @author Jeremy Brubaker
 * @brief Low-level support functions
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
#ifndef	UTILS_H
#define	UTILS_H

#include <stdint.h>

/**
 * @brief Write an 8-bit value to an address
 *
 * @param addr Address to write
 * @param val 32-bit value to write
 */
extern void put32 (uint64_t addr, uint32_t c);
/**
 * @brief Read a 32-bit value from an address
 *
 * @param addr Address to read
 *
 * @return 32-bit value read
 */
extern unsigned int get32 (uint64_t addr);

/**
 * @brief Spin for a number of CPU cycles
 *
 * @param n Cycles to spin
 */
extern void delay (uint64_t n);

/**
 * @brief Get current Exception Level
 *
 * @return Current Exception Level
 */
extern int get_el (void);

#endif
