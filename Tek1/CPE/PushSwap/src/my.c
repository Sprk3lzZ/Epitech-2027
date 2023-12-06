/*
** EPITECH PROJECT, 2022
** my.c
** File description:
** my.c
*/

#include "my.h"

int my_getnbr(char *string, int *value)
{
    int sign = 1;
    unsigned int index = 0;

    *value = 0;
    if (string[index] == '-') {
        sign = -1;
        index++;
    }
    for (; string[index] >= '0' && string[index] <= '9'; index++)
        *value = *value * 10 + sign * (string[index] - '0');
    if (string[index] != '\0')
        return 84;
    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

unsigned int my_strlen(char const *str)
{
    unsigned int size = 0;

    while (str[size] != '\0')
        size++;
    return size;
}
