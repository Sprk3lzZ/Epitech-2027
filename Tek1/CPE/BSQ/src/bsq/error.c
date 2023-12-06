/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/

#include "bsq.h"
#include <stddef.h>

int size_line_equal(char *map)
{
    if (map[0] == '\0')
        return 84;
    int default_size_line = get_size_line(map);
    int size_line = -1;
    int i = 0;

    while (map[i] != '\0') {
        size_line++;
        if (map[i] == '\n' && size_line != default_size_line ||
        size_line == default_size_line && map[i] != '\n')
            return 84;
        if (map[i] == '\n')
            size_line = -1;
        i++;
    }
    return 0;
}

int error_handling(char *map)
{
    int error = 0;
    int nb_l = get_nb_line(map);
    int i = 0;
    int iteratif = my_strlen(map) - nb_l;

    while (i < iteratif) {
        if ((map[i] != '.' && map[i] != 'o' && map[i] != '\n') || nb_l == 0)
            error = 1;
        i++;
    }
    return error;
}
