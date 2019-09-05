#include "../includes/filler_includes.h"

int nt_getchar(void)
{
        static char buff[BUFF_SIZE];
        static char *buff_tmp;
        static int i;

        i = 0;
        buff_tmp = buff;
        if (i == 0)
        {
                i = read(0, buff, 1);
                buff_tmp = buff;
        }
        if ( --i >= 0 )
        {
                return  (*buff_tmp++);
        }
        return EOF;
}
