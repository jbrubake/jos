/**************************************************************************
 * @file irq.h
 * @author Jeremy Brubaker
 * @brief IRQ related functions
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
#include "peripherals/irq.h"
#include "printk.h"
#include "timer.h"
#include "utils.h"

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void
enable_interrupt_controller (void)
{
	put32 (ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1);
}

void
show_invalid_entry_message (int type, unsigned long esr, unsigned long addr)
{
	printk ("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, addr);
}

void
handle_irq (void)
{
    unsigned int irq = 0;
	while ((irq = get32 (IRQ_PENDING_1)))
    {
        switch (irq)
        {
            case (SYSTEM_TIMER_IRQ_1):
                handle_timer_irq ();
                break;
            default:
                printk ("Unknown pending irq: %x\r\n", irq);
        }
    }
}
