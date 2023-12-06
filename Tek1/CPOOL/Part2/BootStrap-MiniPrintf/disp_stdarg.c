/*
** EPITECH PROJECT, 2022
** disp_stdarg
** File description:
** disp_stdarg
*/

#include <stdarg.h>
#include "includes/bsprintf.h"

void disp_stdarg(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'c')
            my_putchar((char)va_arg(list, int));
        if (s[i] == 's')
            my_putstr(va_arg(list, char const *));
        if (s[i] == 'i')
            my_put_nbr(va_arg(list, int));
        my_putchar('\n');
    }
    va_end(list);
}
