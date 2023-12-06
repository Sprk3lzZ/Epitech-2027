/*
** EPITECH PROJECT, 2022
** struct
** File description:
** struct
*/

#include <stdarg.h>
#pragma once

struct l_struct
{
    int i;
    const char *format;
    va_list *list;
    int count;
    int error;
};
