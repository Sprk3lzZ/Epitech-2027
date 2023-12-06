/*
** EPITECH PROJECT, 2022
** rush-1-2.c
** File description:
** rush 1-2
*/

void my_putchar(char c);

void line_case(int x, int y)
{
    for (int i = 0; i < x; i++)
        my_putchar('*');
    my_putchar('\n');
}

void column_case(int x, int y)
{
    for (int i = 0; i < y; i++) {
        my_putchar('*');
        my_putchar('\n');
    }
}

void one_case(int x, int y)
{
    my_putchar('*');
    my_putchar('\n');
}

void condition_special_case(int x, int y)
{
    if (y == 1 && x > 1) {
        line_case(x, y);
        return;
    }
    if (x == 1 && y > 1) {
        column_case(x, y);
        return;
    }
    if (x == 1 && y == 1) {
        one_case(x, y);
        return;
    }
}
