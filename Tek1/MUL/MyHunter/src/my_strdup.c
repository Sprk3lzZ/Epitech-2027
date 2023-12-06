/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int size_src = my_strlen(src);

    dest = malloc(sizeof(char) * (size_src + 1));
    return my_strcpy(dest, src);
}
