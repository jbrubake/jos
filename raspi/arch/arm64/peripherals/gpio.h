/**************************************************************************
 * @file gpio.h
 * @author Jeremy Brubaker
 * @brief GPIO defines
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
#ifndef	P_GPIO_H
#define	P_GPIO_H

#include "peripherals/base.h"

/** @defgroup GPIO GPIO
 *
 * @{ */
#define GPFSEL1     (PBASE+0x00200004)
#define GPSET0      (PBASE+0x0020001C)
#define GPCLR0      (PBASE+0x00200028)
#define GPPUD       (PBASE+0x00200094)
#define GPPUDCLK0   (PBASE+0x00200098)
/** @} */

#endif
