/**************************************************************************
 * @file printk.h
 * @author Jeremy Brubaker
 * @brief Print kernel messages
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
#ifndef	PRINTK_H
#define	PRINTK_H

/**
 * @brief Print a string to the kernel's default output
 *
 * @param fmt Format string
 * @param ... Format parameters
 *
 * @return Number of characters written
 */
int printk (const char *fmt, ...);

#endif
