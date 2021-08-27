#ifndef CONSOLE_H
#define CONSOLE_H

#define VIDEO_MEM 0xb8000

struct console {
    short r, c;
    char attr;
    volatile char* mem;
};

void init_console (struct console *);

#endif
