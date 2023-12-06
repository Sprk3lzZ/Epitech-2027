/*
** EPITECH PROJECT, 2022
** moving_p.c
** File description:
** moving_p.c
*/

#include "my.h"
#include "ncurses.h"

void moving_up(int pos, char *map, int *sizes)
{
    int s_l = get_line_p(map);
    int size_up = sizes[s_l] - (sizes[s_l] - sizes[s_l - 1]);
    int size_up_up = size_up + sizes[s_l - 1] - (sizes[s_l - 1] -
        sizes[s_l - 2]);

    if (map[pos - size_up] == 'X') {
        if (map[pos - size_up_up] == 'X' || map[pos - size_up_up] == '#')
            return;
        map[pos - size_up_up] = 'X';
    }
    map[pos - size_up] = 'P';
    map[pos] = ' ';
}

void moving_down(int pos, char *map, int *sizes)
{
    int s_l = get_line_p(map);
    int size_down = sizes[s_l];
    int size_d_d = sizes[s_l] + sizes[s_l + 1];

    if (map[pos + size_down] == 'X') {
        if (map[pos + size_d_d] == 'X' || map[pos + size_d_d] == '#')
            return;
        map[pos + size_d_d] = 'X';
    }
    map[pos + size_down] = 'P';
    map[pos] = ' ';
}

void moving_right(int pos, char *map)
{
    if (map[pos + 1] == 'X') {
        if (map[pos + 2] == 'X' || map[pos + 2] == '#')
            return;
        map[pos + 2] = 'X';
    }
    map[pos + 1] = 'P';
    map[pos] = ' ';
}

void moving_left(int pos, char *map)
{
    if (map[pos - 1] == 'X') {
        if (map[pos - 2] == 'X' || map[pos - 2] == '#')
            return;
        map[pos - 2] = 'X';
    }
    map[pos - 1] = 'P';
    map[pos] = ' ';
}

void moving(int ch, int pos, char *map, int *sizes)
{
    if (check_block(ch, pos, map, sizes) != 0)
        return;
    if (ch == KEY_LEFT)
        moving_left(pos, map);
    if (ch == KEY_RIGHT)
        moving_right(pos, map);
    if (ch == KEY_UP)
        moving_up(pos, map, sizes);
    if (ch == KEY_DOWN)
        moving_down(pos, map, sizes);
}
