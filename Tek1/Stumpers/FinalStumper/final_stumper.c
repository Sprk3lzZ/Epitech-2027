/*
** EPITECH PROJECT, 2022
** final_stumper
** File description:
** final_stumper
*/

#include "my.h"
#include <unistd.h>

int get_x(char *str)
{
    int x = 0;

    for (int i = 0; str[i] != '\n'; i++)
        x++;
    return x;
}

int get_y(char *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            y++;
    return y;
}

int particular_types(int x, int y, char *symbol)
{
    if (x == 1 && y < 3) {
        symbol[0] = symbol[4];
        symbol[1] = symbol[5];
        symbol[2] = 0;
    }
    if (x == 1 && y > 2) {
        symbol[0] = symbol[4];
        symbol[1] = symbol[3];
        symbol[3] = 0;
    }
    if (x == 2 && y == 2) {
        symbol[1] = 'p';
        symbol[3] = 'p';
    }
}

int comparaison(char *str, char *sym)
{
    int i = 0;
    char *pattern[5][5] = {{"o", "opopoo", "o-o", "o|o", "o-o|oo"}, {"*", "/p\p\/", "***", "***", "/*\*\/"},
                           {"B", "ApApCC", "BBB", "BBB", "ABABCC"}, {"B", "ApCpAC", "BBB", "BBB", "ABCBAC"},
                           {"B", "ApCpCA", "BBB", "BBB", "ABCBCA"}};
    for (; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (my_strcmp(sym, pattern[i][j]) == 0) {
                my_putstr("[rush1-");
                my_put_nbr(i + 1);
                my_putstr("] ");
                my_put_nbr(get_x(str));
                my_putchar(' ');
                my_put_nbr(get_y(str));
            }
        }
    }
    return 0;
}

char rush3(char *str)
{
    int x = get_x(str);
    int y= get_y(str);
    char first_line = 1;
    int current_line = 0;
    int current_column = 0;
    char symbol[7] = {0, 0, 0, 0, 0, 0, 0, 0};

    symbol[0] = str[0];
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 1)
            symbol[1] = str[i];
        if (str[i] == '\n' && first_line) {
            symbol[2] = str[i - 1];
            first_line = 0;
        }
        if (str[i] == '\n') {
            current_column = 0;
            current_line++;
            continue;
        }
        if (current_line == y)
            break;
        if (current_column == 0 && current_line != 0 && current_line != y - 1)
            symbol[3] = str[i];
        if (current_line == y - 1 && current_column == 0)
            symbol[4] = str[i];
        if (current_line == y - 1 && current_column == x - 1)
            symbol[5] = str[i];
        current_column++;
    }
    particular_types(x, y, symbol);
    comparaison(str, symbol);
}

int main()
{
    /* char buff[30000 + 1];
    int offset = 0;
    int len;

    while ((len = read(0 , buff + offset , 30000 - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84); */
    rush3("AA\nCC\n");
    return (0);
}
