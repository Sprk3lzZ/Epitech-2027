/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "bsq.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static int bsq_pattern(char **argv)
{
    int size = my_getnbr(argv[1]);
    char *map;
    int *array;

    for (int i = 0; i < my_strlen(argv[2]); i++)
        if ((argv[2][i] != '.' && argv[2][i] != 'o') || size < 1)
            return 84;
    map = generate(size, argv[2]);
    if (map == NULL)
        return 84;
    array = algo_transformation_array_int(map, size);
    replace_map(array, map);
    write(1, map, my_strlen(map));
    free(array);
    free(map);
    return 0;
}

static int bsq_file(int argc, char **argv)
{
    int error = 0;
    int nb_lines;
    char *map;
    char *map_offset;
    int *array;

    map_offset = mapping(argc, argv, &nb_lines, &map);
    if (map_offset == 0)
        return 84;
    error = size_line_equal(map_offset) + error_handling(map_offset);
    if (!error) {
        array = algo_transformation_array_int(map_offset, nb_lines);
        replace_map(array, map_offset);
        write(1, map_offset, my_strlen(map_offset));
        free(array);
    }
    free(map);
    return error ? 84 : 0;
}

int main(int argc, char **argv)
{
    if (argc == 2)
        return bsq_file(argc, argv);
    if (argc == 3)
        return bsq_pattern(argv);
    return 84;
}
