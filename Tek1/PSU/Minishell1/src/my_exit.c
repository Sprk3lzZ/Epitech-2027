/*
** EPITECH PROJECT, 2023
** my_exit.c
** File description:
** my_exit.c
*/

#include "mysh.h"

void my_exit(char **arguments)
{
    int exit_code = 0;

    if (arguments[1] == NULL) {
        exit(0);
    }
    if (my_isnum(arguments[1]) == 0 || my_tablen(arguments) > 2) {
        write(2, "exit: Expression Syntax.\n", 25);
        return;
    }
    exit_code = my_getnbr(arguments[1]);
    exit(exit_code);
}

void print_exit(int status, int exit_status)
{
    if (status == -1) {
        if (isatty(0))
            write(1, "exit\n", 5);
        exit(exit_status);
    }
}
