/*
** EPITECH PROJECT, 2022
** check_lose.c
** File description:
** check_lose.c
*/

#include "my.h"

int get_nb_x(char *map)
{
    int i = 0;
    int nb = 0;

    while (map[i] != '\0') {
        if (map[i] == 'X')
            nb++;
        i++;
    }
    return nb;
}

int *get_index_x(char *map)
{
    int i = 0;
    int j = 0;
    int *index = malloc(sizeof(int) * get_nb_x(map));

    while (map[i] != '\0') {
        if (map[i] == 'X') {
            index[j] = i;
            j++;
        }
        i++;
    }
    return index;
}

int check_arround(int *sizes, char *map)
{
    int s_l = get_line_p(map);
    int i = 0;
    int *index = get_index_x(map);
    int size_down = sizes[s_l];
    int size_up = sizes[s_l] - (sizes[s_l] - sizes[s_l - 1]);
    int block = 0;
    while (i < get_nb_x(map)) {
        if (((map[index[i] - 1] == '#' && (map[index[i] - size_up] == '#' ||
            map[index[i] - size_up] == 'X')) || (map[index[i] + 1] == '#' &&
            (map[index[i] - size_up] == '#' || map[index[i] - size_up] == 'X'))
            || (map[index[i] - 1] == '#' && (map[index[i] + size_down] == '#'
            || map[index[i] + size_down] == 'X')) || (map[index[i] + 1] == '#'
            && (map[index[i] + size_down] == '#' ||
            map[index[i] + size_down] == 'X'))))
                block++;
        i++;
    }

    return block == get_nb_x(map) ? 1 : 0;
}

void is_lose(int *sizes, char *map)
{
    if (check_arround(sizes, map) == 1) {
        clear();
        printw("%s", map);
        refresh();
        endwin();
        exit(1);
    }
}
