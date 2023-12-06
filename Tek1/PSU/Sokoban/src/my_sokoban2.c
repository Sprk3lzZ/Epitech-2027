/*
** EPITECH PROJECT, 2022
** my_sokoban2.c
** File description:
** my_sokoban2.c
*/

#include "my.h"

void replace(int ch, int pos, char *map, int *sizes)
{
    if (check_block(ch, pos, map, sizes) == 0)
        moving(ch, pos, map, sizes);
}

void init_game(void)
{
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void end_game(char *map, int *pos_o, int *sizes)
{
    check_win(map, pos_o);
    is_lose(sizes, map);
}
