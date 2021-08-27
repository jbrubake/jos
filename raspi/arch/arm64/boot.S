/**************************************************************************
 * @file boot.S
 * @author Jeremy Brubaker
 * @brief Set things up and load the kernel
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

#include "arm/sysregs.h"
#include "mm.h"

.section ".text.boot"

.globl _start
_start:
    // Check processor id
	mrs     x0, mpidr_el1
	and     x0, x0, #0xFF   // check for processor 0
	cbz	    x0, master		// processor 0 runs the kernel
proc_hang: 
	b	    proc_hang       // hang processors 1-3

master:
    bl      get_el          // get current EL
    cmp     x0, #3         // EL3?
    beq     el3_entry
    cmp     x0, #2          // EL2?
    beq     el2_entry
    b       proc_hang

// TODO: Correctly set/clear register bits
el3_entry:
	ldr     x0, =(SCTLR1_RES | !SCTLR1_EE | !SCTLR1_I | !SCTLR1_C | !SCTLR1_M)
	msr     sctlr_el1, x0		

	ldr	    x0, =(HCR2_RW | HCR2_SWIO)
	msr	    hcr_el2, x0

    ldr     x0, =(SCR3_RES | SCR3_RW | SCR3_NS)
	msr	    scr_el3, x0

    ldr     x0, =(SPSR_D | SPSR_A | SPSR_I | SPSR_F | SPSR_EL1h)
	msr	    spsr_el3, x0

    // switch to EL1
	adr	    x0, el1_entry		
	msr	    elr_el3, x0
	eret				

el2_entry:
    // enable CNTP for EL1
    mrs     x0, cnthctl_el2
    orr     x0, x0, #CNTHCTL2_NOTRAP
    msr     cnthctl_el2, x0
    msr     cntvoff_el2, xzr

    // enable AArch64 in EL1
	ldr	    x0, =(HCR2_RW | HCR2_SWIO)
    msr     hcr_el2, x0

    // change execution level to EL1
    ldr     x0, =(SPSR_D | SPSR_A | SPSR_I | SPSR_F | SPSR_EL1h)
    msr     spsr_el2, x0

    // switch to EL1
    adr     x2, el1_entry
    msr     elr_el2, x2
    eret

el1_entry:
    // Zeroize bss
	adr	    x0, bss_begin
	adr	    x1, bss_end
	sub	    x1, x1, x0
	bl 	    memzero

	mov	    sp, #LOW_MEMORY // Initialize the stack
	bl	    kernel_main

	b 	    proc_hang		// should never come here

