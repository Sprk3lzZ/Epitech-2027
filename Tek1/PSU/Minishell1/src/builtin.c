/*
** EPITECH PROJECT, 2023
** builtin.c
** File description:
** builtin.c
*/

#include "mysh.h"

void builtin(char **arguments, char **env_cpy)
{
    if (my_strcmp(arguments[0], "env") == 0 && my_tablen(arguments) == 1)
        print_env(env_cpy);
    if (my_strcmp(arguments[0], "exit") == 0)
        my_exit(arguments);
}
