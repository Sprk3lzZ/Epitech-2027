/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** BSQ
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "bsq.h"

int *numerical_transformation(char *map, int nb_lines)
{
    int i = 0;
    int j = 0;
    int *array_int = malloc(sizeof(int) * (my_strlen(map) - nb_lines));

    while (map[i] != '\0') {
        if (map[i] == '\n')
            i++;
        if (map[i] == 'o') {
            array_int[j] = 0;
            j++;
            i++;
        }
        if (map[i] == '.') {
            array_int[j] = 1;
            j++;
            i++;
        }
    }
    return array_int;
}

int *algo_transformation_array_int(char *map, int nb_lines)
{
    int *ar = numerical_transformation(map, nb_lines);
    int i = 0;
    int size = get_size_line(map);
    int current_col = 0;
    char is_first_line = 1;
    int iteration = my_strlen(map) - nb_lines;

    while (i < iteration) {
        if (!is_first_line && current_col != 0 && ar[i] != 0) {
            ar[i] += get_minimum(ar[i - 1], ar[i - size], ar[i - size - 1]);
        }
        current_col++;
        if (current_col == size) {
            is_first_line = 0;
            current_col = 0;
        }
        i++;
    }
    return ar;
}

void replace_map(int *array, char *map)
{
    int size = get_size_line(map);
    int index_square = get_index(array, map) +
    get_index(array, map) / (size);
    int size_square = array[index_square -
    get_index(array, map) / (size)];

    for (int i = 0; i < size_square; i++) {
        for (int j = 0; j < size_square; j++) {
            map[index_square - j] = 'x';
        }
        index_square -= size + 1;
    }
}
