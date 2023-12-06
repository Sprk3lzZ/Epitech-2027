/*
** EPITECH PROJECT, 2022
** creation
** File description:
** creation
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "bsq.h"

char *generate(int size, char *pattern)
{
    char *map = malloc(size * (size + 1) + 1);
    int length = my_strlen(pattern);
    int line_count = 0;

    if (length == 0) {
        free(map);
        return NULL;
    }
    for (int i = 0; i < size * (size + 1); i++) {
        if ((i + 1) % (size + 1) == 0) {
            map[i] = '\n';
            line_count++;
        } else {
            map[i] = pattern[(i - line_count) % length];
        }
    }
    map[size * (size + 1)] = '\0';
    return map;
}

static void reading(int file, char *map, struct stat stats)
{
    int size = 0;
    while (size != stats.st_size)
        size += read(file, map, stats.st_size);
    close(file);

    map[stats.st_size] = '\0';
}

char *mapping(int argc, char **argv, int *nblines, char **map1)
{
    struct stat stats;
    stat(argv[1], &stats);
    int file = open(argv[1], O_RDONLY);
    if (file < 0)
        return NULL;
    char *map = malloc(sizeof(char) * stats.st_size + 1);
    *map1 = map;
    reading(file, map, stats);
    *nblines = my_getnbr(map);
    int size_line = get_size_line(map);
    char *map2 = &map[size_line + 1];

    if (*nblines != get_nb_line(map2))
        return 0;
    return map2;
}
