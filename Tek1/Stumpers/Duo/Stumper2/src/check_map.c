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
        if (map[i] != '.' && map[i] != 'G' && map[i] != 'F' && map[i] != '\n'
        && map[i] != 'T')
            return 84;
        if (map[i] == 'G')
            p++;
        if (map[i] == 'T')
            o++;
        if (map[i] == 'F')
            x++;
        i++;
    }
    if (p != 1 && o > 0 && x > 0)
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
