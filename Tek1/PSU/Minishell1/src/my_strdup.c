/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** my_strdup.c
*/

#include "mysh.h"

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

char *my_strdup(char const *src)
{
    char *dest;
    int size_src = my_strlen(src);

    dest = malloc(sizeof(char) * (size_src + 1));
    return my_strcpy(dest, src);
}
