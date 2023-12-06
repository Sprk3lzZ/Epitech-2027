/*
** EPITECH PROJECT, 2023
** my_env.c
** File description:
** my_env.c
*/

#include "mysh.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}
