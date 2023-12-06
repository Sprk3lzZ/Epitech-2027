/*
** EPITECH PROJECT, 2022
** getter.c
** File description:
** getter.c
*/

#include "bsq.h"

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

int get_minimum(int a, int b, int c)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int get_maximum(int a, int b)
{
    int max = a;

    if (b > max)
        max = b;
    return max;
}

int get_index(int *array, char *map)
{
    int j = 0;
    int i = 0;
    int max = array[0];
    int iteratif = my_strlen(map) - get_nb_line(map);

    while (i < iteratif) {
        if (array[i] > max) {
            max = array[i];
            j = i;
        }
        i++;
    }
    return j;
}
