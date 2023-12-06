/*
** EPITECH PROJECT, 2023
** cleanstr.c
** File description:
** cleanstr.c
*/

#include "my.h"

int check_error(int ac)
{
    if (ac == 1) {
        my_putchar('\n');
        return 1;
    }
    return 0;
}

void extract_condition(int spaces, int i)
{
    if (spaces != 0 && i - spaces != 0)
        my_putchar(' ');
}

void clean_str(char *av)
{
    int space = 0;
    int i = 0;

    while (av[i] != '\0') {
        if (av[i] == '\t' || av[i] == ' ')
            space++;
        else {
            extract_condition(space, i);
            my_putchar(av[i]);
            space = 0;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (check_error(ac))
        return 0;
    if (ac != 2)
        return 84;
    clean_str(av[1]);
    my_putchar('\n');
    return 0;
}
