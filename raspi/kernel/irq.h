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
#ifndef	IRQ_H
#define	IRQ_H

/**
 * @brief Enable system interrupt controller
 */
void enable_interrupt_controller (void);

/**
 * @brief Initialize the Exception Vector table
 */
void exception_vector_init (void);

/**
 * @brief Enable IRQs
 */
void enable_irq (void);

/**
 * @brief Disable IRQs
 */
void disable_irq (void);

#endif
