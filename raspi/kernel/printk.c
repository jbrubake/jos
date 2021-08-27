/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.
 * http://www.strudel.org.uk/itoa/
 */
/**************************************************************************
 * @file printk.c
 * @author Jeremy Brubaker
 * @brief Print kernel messages
 *
 * This file is part of jos
 *
 * Copyright (c) 2020, Jeremy Brubaker
 *
 * itoa function is Copyright (c) Lukás Chmela (http://www.strudel.org.uk/itoa/)
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
#include <stdarg.h>

#include "printk.h"
#include "mini_uart.h"

/**
 * @brief Convert an integer to an ASCII string
 *
 * @param v Integer to convert
 * @param r Buffer to return string in
 * @param radix Radix to use in coversion. Supports 2-16 
 *
 * @return Pointer to converted string
 */
char* 
itoa(int v, char* r, int radix) {

    static char digits[] = "fedcba9876543210123456789abcdef";

    // return null-string if radix is invalid
    if (radix < 2 || radix > 16) { *r= '\0'; return r; }

    char* p  = r;
    char* p1 = r;
    char  tc;
    int   tv;

    do {
        tv = v;
        v /= radix;
        *p++ = digits[15 + (tv - v * radix)];
    } while (v);

    // Apply negative sign
    if (tv < 0) *p++ = '-';

    *p-- = '\0';

    // reverse the result
    while (p1 < p)
    {
        tc = *p;
        *p--= *p1;
        *p1++ = tc;
    }

    return r;
}

int
printk (const char *fmt, ...)
{
    va_list ap;

    // TODO: Replace printk buffer with dynamic string
    char buf[1000];
    char *bp = (char *)&buf;

    va_start(ap, fmt);
    for (; *fmt; fmt++)
    {
        if (*fmt != '%') // copy next if not a format specifier
        {
            *bp++ = *fmt;
            continue;
        }
        switch (*++fmt)
        {
            int ival;
            unsigned int uival;

            case 'i': // signed decimal
            case 'd':
                ival = va_arg (ap, int);
                itoa (ival, bp, 10);
                for (; *bp; bp++) // go to new end of buffer
                    ;
                break;
            case 'u': // unsigned decimal
                uival = va_arg (ap, unsigned int);
                itoa (uival, bp, 10);
                for (; *bp; bp++) // go to new end of buffer
                    ;
                break;
            case 'x': // unsigned hexadecimal
                uival = va_arg (ap, unsigned int);
                itoa (uival, bp, 16);
                for (; *bp; bp++) // go to new end of buffer
                    ;
                break;
            case 's': // string
                for (char *s = va_arg (ap, char *); *s; s++)
                    *bp++ = *s;
                break;
            case '%': // literal %
                *bp++ = '%';
                break;
            default: // copy an invalid specifier
                *bp++ = '%';
                *bp++ = *fmt;
        }
    }
    va_end (ap);

    *bp = '\0'; // terminate buffer

    return uart_print (buf);
}
