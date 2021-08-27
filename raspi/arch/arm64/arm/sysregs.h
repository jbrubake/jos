/**************************************************************************
 * @file sysregs.h
 * @author Jeremy Brubaker
 * @brief Define ARM system registers
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
#ifndef A_SYSREGS_H
#define A_SYSREGS_H

// ***************************************
// CNTHCTL_EL2, Counter-timer Hypervisor Control Register (EL2), Page 2920 of AArch64-Reference-Manual.
// ***************************************

#define CNTHCTL2_RES    (0xffffff00)
#define CNTHCTL2_NOTRAP (0b0011 << 0) 

// ***************************************
// SCTLR_EL1, System Control Register (EL1), Page 2654 of AArch64-Reference-Manual.
// ***************************************

#define SCTLR1_RES (0x03 << 28) | (0x03 << 22) | (1 << 20) | (1 << 11)
#define SCTLR1_EE  (1 << 25)
#define SCTLR1_EOE (1 << 24)
#define SCTLR1_I   (1 << 12)
#define SCTLR1_C   (1 << 2)
#define SCTLR1_M   (1 << 0)

// ***************************************
// HCR_EL2, Hypervisor Configuration Register (EL2), Page 2487 of AArch64-Reference-Manual.
// ***************************************

#define HCR2_RW   (1 << 31) // Set EL1 to AArch64
#define HCR2_SWIO (1 << 1)  // SWIO hardwired on Pi3

// ***************************************
// SCR_EL3, Secure Configuration Register (EL3), Page 2648 of AArch64-Reference-Manual.
// ***************************************

#define SCR3_RES (3 << 4)
#define SCR3_RW  (1 << 10)
#define SCR3_NS  (1 << 0)

// ***************************************
// SPSR_EL2, Saved Program Status Register (EL2) Page 383 of AArch64-Reference-Manual.
// SPSR_EL3, Saved Program Status Register (EL3) Page 389 of AArch64-Reference-Manual.
// ***************************************

#define SPSR_D     (1 << 9)
#define SPSR_A     (1 << 8)
#define SPSR_I     (1 << 7)
#define SPSR_F     (1 << 6)
#define SPSR_EL0   (0b0000 << 0)
#define SPSR_EL1t  (0b0100 << 0)
#define SPSR_EL1h  (0b0101 << 0)
#define SPSR_EL2t  (0b1000 << 0)
#define SPSR_EL2h  (0b1001 << 0)
#define SPSR_EL3t  (0b1100 << 0)
#define SPSR_EL3h  (0b1101 << 0)

// ***************************************
// PSTSTE DAIF fields, Page 332 of AArch64-Reference-Manual.
// ***************************************
#define PSTATE_DAIF_D (1<<3)
#define PSTATE_DAIF_A (1<<2)
#define PSTATE_DAIF_I (1<<1)
#define PSTATE_DAIF_F (1<<0)

#endif
