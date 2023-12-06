/*
** EPITECH PROJECT, 2023
** check_binary.c
** File description:
** check_binary.c
*/

#include "mysh.h"

void check_binary(char **arguments, char **env, char *pathname)
{
    if (execve(pathname, arguments, env) == -1) {
        if (errno == ENOEXEC) {
            write(2, arguments[0], my_strlen(arguments[0]));
            write(2, ": Exec format error. Wrong Architecture.\n", 41);
            exit(1);
        }
    }
}
