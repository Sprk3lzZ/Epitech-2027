/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *dest;
    int size_src = my_strlen(src);

    dest = malloc(sizeof(char) * (size_src + 1));
    return my_strcpy(dest, src);
}
