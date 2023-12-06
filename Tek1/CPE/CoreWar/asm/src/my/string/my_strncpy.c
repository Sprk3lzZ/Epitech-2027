/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include "my/string.h"

char *my_strncpy(char *dest, const char *src, size_t bytes)
{
    size_t i = 0;

    for (; i < bytes && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < bytes; i++)
        dest[i] = '\0';
    return dest;
}
