/**************************************************************************
 * @file utils.S
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

.globl put32
put32:
	str     w1,[x0]
	ret

.globl get32
get32:
	ldr     w0,[x0]
	ret

.globl delay
delay:
	subs    x0, x0, #1
	bne     delay
	ret

.globl get_el
get_el:
    mrs     x0, CurrentEl
    and     x0, x0, #0xFF
    lsr     x0, x0, #2
    ret
