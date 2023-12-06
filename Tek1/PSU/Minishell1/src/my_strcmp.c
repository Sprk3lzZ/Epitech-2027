/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "mysh.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int s1_size = my_strlen(s1);

    while (s1[i] == s2[i] && i < s1_size)
        i++;
    return s1[i] - s2[i];
}
