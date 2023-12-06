/*
** EPITECH PROJECT, 2022
** sum_numbers
** File description:
** sum_numbers
*/

#include <stdarg.h>
#include "includes/bsprintf.h"

int sum_numbers(int n, ...)
{
    va_list list;
    int result = 0;

    va_start(list, n);
    for (int i = 0; i < n; i++)
        result += va_arg(list, int);
    va_end(list);
    return result;
}
