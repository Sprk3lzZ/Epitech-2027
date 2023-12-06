/*
** EPITECH PROJECT, 2022
** getter.c
** File description:
** getter.c
*/

#include "my.h"

int get_size_line(char *map)
{
    int size = 0;

    if (map[0] == '\0')
        return 84;
    while (map[size] != '\n')
        size++;
    return size;
}

int get_nb_line(char *map)
{
    int nb_line = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n')
            nb_line++;
    }
    return nb_line;
}

int get_index_p(char *map)
{
    int index = 0;

    while (map[index] != '\0') {
        if (map[index] == 'P')
            return index;
        index++;
    }
    return 0;
}

int *all_size_map(char *map)
{
    int nb_lines = get_nb_line(map);
    int *size = malloc(sizeof(int) * nb_lines + 1);

    for (int i = 0; i < nb_lines; i++) {
        size[i] = get_size_line(map) + 1;
        map += get_size_line(map) + 1;
    }
    size[nb_lines] = 0;
    return size;
}

int get_line_p(char *map)
{
    int line = 0;
    int index = 0;

    while (map[index] != '\0') {
        if (map[index] == '\n')
            line++;
        if (map[index] == 'P')
            return line;
        index++;
    }
    return 0;
}
