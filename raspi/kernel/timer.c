/**************************************************************************
 * @file timer.c
 * @author Jeremy Brubaker
 * @brief Timer IRQ
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
#include "timer.h"
#include "peripherals/timer.h"
#include "printk.h"
#include "utils.h"

unsigned int TIMER_IRQ_INTERVAL = 0;
unsigned int TIMER_CURRENT = 0;

void
timer_init (unsigned long t)
{
    TIMER_IRQ_INTERVAL = t;
	TIMER_CURRENT = get32 (TIMER_CLO);
	TIMER_CURRENT += TIMER_IRQ_INTERVAL;
	put32 (TIMER_C1, TIMER_CURRENT);
}

void
handle_timer_irq (void) 
{
	TIMER_CURRENT += TIMER_IRQ_INTERVAL;
	put32 (TIMER_C1, TIMER_CURRENT);
	put32 (TIMER_CS, TIMER_CS_M1);
	printk ("Timer interrupt received\n\r");
}
