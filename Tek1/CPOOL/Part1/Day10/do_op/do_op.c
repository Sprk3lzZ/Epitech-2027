/*
** EPITECH PROJECT, 2022
** do-op
** File description:
** do-op
*/

#include <stdlib.h>
#include <unistd.h>
#include "../lib/my/my.h"

char get_op(char *str)
{
    int len = my_strlen(str);
    int i = 0;

    while (i < len) {
        char op = str[i];
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
            return op;
        }
        i++;
    }
    return 0;
}

int calculate2(char operator, int nbr1, int nbr2)
{
    if (operator == '+') {
        my_put_nbr(nbr1 + nbr2);
        my_putchar('\n');
        return 0;
    }
    if (operator == '-') {
        my_put_nbr(nbr1 - nbr2);
        my_putchar('\n');
        return 0;
    }
    if (operator == '*') {
        my_put_nbr(nbr1 * nbr2);
        my_putchar('\n');
        return 0;
    }
    my_putchar('0');
    my_putchar('\n');
    return 84;
}

int calculate1(char operator, int nbr1, int nbr2)
{
    if (operator == '%') {
        my_put_nbr(nbr1 % nbr2);
        my_putchar('\n');
        return 0;
    }
    if (operator == '/') {
        my_put_nbr(nbr1 / nbr2);
        my_putchar('\n');
        return 0;
    } else {
        return calculate2(operator, nbr1, nbr2);
    }
}

int do_op(int argc, char **argv)
{
    if (argc >= 4) {
        int nbr1 = my_getnbr(argv[1]);
        char operator = get_op(argv[2]);
        int nbr2 = my_getnbr(argv[3]);
        if (argv[2][0] == '/' && nbr2 == 0) {
            write(2, "Stop: division by zero\n", 23);
            return 84;
        }
        if (argv[2][0] == '%' && nbr2 == 0) {
            write(2, "Stop: modulo by zero\n", 21);
            return 84;
        }
        return calculate1(operator, nbr1, nbr2);
    }
    return 84;
}

int main(int argc, char **argv)
{
    int result = do_op(argc, argv);

    return result;
}
