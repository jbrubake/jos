#include "drivers/console.h"

void
main ()
{
    struct console con;
    init_console (&con);
    con.mem = (char *)VIDEO_MEM;

    *con.mem = 'X';
}
