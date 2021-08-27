#include "console.h"

void
init_console (struct console *con)
{
    con->r = con->c = 0;
    con->attr = 0x0f;
}
