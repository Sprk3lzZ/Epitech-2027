/*
** EPITECH PROJECT, 2022
** case_rush
** File description:
** case_rush
*/

void my_putchar(char c);

void line_case(int x, int y)
{
    for (int i = 0; i < x; i++)
        my_putchar('B');
    my_putchar('\n');
}

void column_case(int x, int y)
{
    for (int i = 0; i < y; i++) {
        my_putchar('B');
        my_putchar('\n');
    }
}

void one_case(int x, int y)
{
    my_putchar('B');
    my_putchar('\n');
}

void condition_special_case(int x, int y)
{
    if (y == 1) {
        line_case(x, y);
        return;
    }
    if (x == 1) {
        column_case(x, y);
        return;
    }
    if (x == 1 && y == 1) {
        one_case(x, y);
        return;
    }
}
