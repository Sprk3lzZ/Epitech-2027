/*
** EPITECH PROJECT, 2022
** rush-1-2.c
** File description:
** rush-1-2
*/

#include <unistd.h>

void line_case(int x, int y);
void column_case(int x, int y);
void one_case(int x, int y);
void condition_special_case(int x, int y);
void my_putchar(char c);

void place_top(int x, int y)
{
    char top_corner1 = '/';
    char top_corner2 = '\\';
    char top_bot = '*';

    for (int i = 0; i <= x - 2; i++) {
        if (i == 0)
            my_putchar(top_corner1);
        if (i == x - 2) {
            my_putchar(top_corner2);
            my_putchar('\n');
        } else
            my_putchar(top_bot);
    }
}

void place_bottom(int x, int y)
{
    char bot_corner1 = '\\';
    char bot_corner2 = '/';
    char top_bot = '*';

    for (int i = 0; i <= x - 2; i++) {
        if (i == 0) {
            my_putchar(bot_corner1);
        }
        if (i == x - 2) {
            my_putchar(bot_corner2);
            my_putchar('\n');
        } else
            my_putchar(top_bot);
    }
}

void place_between(int x, int y)
{
    char sides = '*';

    for (int i = 0; i <= x - 2; i++) {
        if (i == 0)
            my_putchar(sides);
        if (i == x - 2) {
            my_putchar(sides);
            my_putchar('\n');
        } else
            my_putchar(' ');
    }
}

void rush(int x, int y)
{
    if (x > 1 && y > 1) {
        place_top(x, y);
        for (int i = 0; i < y - 2; i++) {
            place_between(x, y);
        }
        place_bottom(x, y);
    }
    if (x <= 0 || y <= 0)
        write(2, "Invalid size\n", 13);
    condition_special_case(x, y);
}


int main(void)
{
    rush(5, 3);
}
