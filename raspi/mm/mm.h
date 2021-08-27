/**************************************************************************
 * @file mm.h
 * @author Jeremy Brubaker
 * @brief Memory management functions
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
#ifndef	MM_H
#define	MM_H

/** @defgroup MM Meory Management
 * @{ */
#define PAGE_SHIFT    12
#define TABLE_SHIFT   9
#define SECTION_SHIFT (PAGE_SHIFT + TABLE_SHIFT)

#define PAGE_SIZE     (1 << PAGE_SHIFT)	
#define SECTION_SIZE  (1 << SECTION_SHIFT)	

/** @brief Bottom of the stack */
#define LOW_MEMORY    (2 * SECTION_SIZE)
/** @} */

#ifndef __ASSEMBLER__

#include <stdint.h>

/**
 * @brief Zeroize a block of memory
 *
 * @param s Address of beginning of block
 * @param n Block size
 */
void memzero(uint64_t s, uint64_t n);
#endif

#endif
