/*
** EPITECH PROJECT, 2022
** case_rush
** File description:
** case_rush
*/

void my_putchar(char c);

void line_case(int x, int y)
{
    my_putchar('o');
    for (int i = 0; i < x - 2; i++)
        my_putchar('-');
    my_putchar('o');
    my_putchar('\n');
}

void column_case(int x, int y)
{
    my_putchar('o');
    my_putchar('\n');
    for (int i = 0; i < y - 2; i++) {
        my_putchar('|');
        my_putchar('\n');
    }
    my_putchar('o');
    my_putchar('\n');
}

void one_case(int x, int y)
{
    my_putchar('o');
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
