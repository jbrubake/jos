/**************************************************************************
 * @file exception.h
 * @author Jeremy Brubaker
 * @brief Exception vector defines
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
#ifndef INTERRUPT_H
#define INTERRUPT_H

#define S_FRAME_SIZE         256 // size of all saved registers 

#define SYNC_INVALID_EL1t    0 
#define IRQ_INVALID_EL1t     1 
#define FIQ_INVALID_EL1t     2 
#define ERROR_INVALID_EL1t   3 

#define SYNC_INVALID_EL1h    4 
#define IRQ_INVALID_EL1h     5 
#define FIQ_INVALID_EL1h     6 
#define ERROR_INVALID_EL1h   7 

#define SYNC_INVALID_EL0_64	 8 
#define IRQ_INVALID_EL0_64   9 
#define FIQ_INVALID_EL0_64   10 
#define ERROR_INVALID_EL0_64 11 

#define SYNC_INVALID_EL0_32  12 
#define IRQ_INVALID_EL0_32   13 
#define FIQ_INVALID_EL0_32   14 
#define ERROR_INVALID_EL0_32 15 

#endif
