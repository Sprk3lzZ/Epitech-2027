/*
** EPITECH PROJECT, 2022
** miniprintf
** File description:
** miniprintf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/struct.h"

void print_place_holder(struct l_struct *l_s)
{
    char *temp;
    switch (l_s->format[l_s->i]) {
        case 'd': case 'i':
            l_s->count += my_put_nbr(va_arg(*l_s->list, int));
            return;
        case 's':
            temp = va_arg(*l_s->list, char *);
            l_s->count += my_strlen(temp);
            my_putstr(temp);
            return;
        case 'c':
            (l_s->count)++;
            my_putchar((char)va_arg(*l_s->list, int));
            return;
        case '%':
            (l_s->count)++;
            my_putchar('%');
            return;
    }
    l_s->error = 1;
}

static void processing(struct l_struct *l_s)
{
    if (l_s->format[l_s->i] == '%') {
        while (l_s->format[++l_s->i] == ' ');
        print_place_holder(l_s);
    } else {
        l_s->count++;
        my_putchar(l_s->format[l_s->i]);
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    struct l_struct l_s = { 0, format, &list, 0, 0 };

    va_start(list, format);
    for (; format[l_s.i]; l_s.i++)
        processing(&l_s);
    va_end(list);
    return l_s.error ? -84 : l_s.count;
}
