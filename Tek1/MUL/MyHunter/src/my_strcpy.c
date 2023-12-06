/*
** EPITECH PROJECT, 2022
** my_strcpy.c
** File description:
** my_strcpy.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int src_size = my_strlen(src);

    while (i < src_size) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
