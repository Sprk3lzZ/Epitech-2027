/*
** EPITECH PROJECT, 2023
** my_tablen.c
** File description:
** my_tablen.c
*/

#include "mysh.h"

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i;
}

bool is_folder(char const *program)
{
    struct stat stats;

    stat(program, &stats);
    return S_ISDIR(stats.st_mode);
}

void extract_condition(char **arguments)
{
    if (is_folder(arguments[0])) {
        write(1, arguments[0], my_strlen(arguments[0]));
        write(2, ": Permission denied.\n", 21);
    }
}
