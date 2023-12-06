/*
** EPITECH PROJECT, 2023
** my_isnum.c
** File description:
** my_isnum.c
*/

#include "mysh.h"

int my_isnum(char *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
