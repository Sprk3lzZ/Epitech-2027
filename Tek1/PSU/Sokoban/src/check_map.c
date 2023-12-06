/*
** EPITECH PROJECT, 2022
** check_map
** File description:
** check_map
*/

#include "my.h"

int check_map(char *map)
{
    int i = 0;
    int x = 0;
    int o = 0;
    int p = 0;

    while (map[i] != '\0') {
        if (map[i] != 'X' && map[i] != 'O' && map[i] != 'P' && map[i] != '\n'
        && map[i] != '#' && map[i] != ' ')
            return 84;
        if (map[i] == 'X')
            x++;
        if (map[i] == 'O')
            o++;
        if (map[i] == 'P')
            p++;
        i++;
    }
    if (p != 1 || x < o || x > o)
        return 84;
    return 0;
}

int check_valid_map(char **argv)
{
    struct stat stats;
    stat(argv[1], &stats);
    int file = open(argv[1], O_RDONLY);
    if (file < 0)
        return 84;
    if (stats.st_size == 0)
        return 84;
    return 0;
}

int check_block(int ch, int pos, char *map, int *sizes)
{
    int s_l = get_line_p(map);
    int size_up = sizes[s_l] - (sizes[s_l] - sizes[s_l - 1]);
    int size_down = sizes[s_l];
    if (ch == KEY_LEFT) {
        if (map[pos - 1] == '#')
            return 1;
    }
    if (ch == KEY_RIGHT) {
        if (map[pos + 1] == '#')
            return 1;
    }
    if (ch == KEY_UP) {
        if (map[pos - size_up] == '#')
            return 1;
    }
    if (ch == KEY_DOWN) {
        if (map[pos + size_down] == '#')
            return 1;
    }
    return 0;
}

void check_win(char *map, int *pos_o)
{
    int i = 0;
    int win = 0;

    while (pos_o[i] != 0) {
        if (map[pos_o[i]] == 'X')
            win++;
        i++;
    }
    if (win == i) {
        clear();
        printw("%s", map);
        refresh();
        endwin();
        exit(0);
    }
}
