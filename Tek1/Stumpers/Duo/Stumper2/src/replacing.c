/*
** EPITECH PROJECT, 2022
** replacing.c
** File description:
** replacing.c
*/

#include "my.h"

int get_nb_o(char *map)
{
    int i = 0;
    int nb = 0;

    while (map[i] != '\0') {
        if (map[i] == 'O')
            nb++;
        i++;
    }
    return nb;
}

int *get_index_o(char *map)
{
    int i = 0;
    int j = 0;
    int *index = malloc(sizeof(int) * get_nb_o(map));

    while (map[i] != '\0') {
        if (map[i] == 'O') {
            index[j] = i;
            j++;
        }
        i++;
    }
    return index;
}

void replace_o(char *map, int *index)
{
    int i = 0;

    while (index[i] != '\0') {
        if (map[index[i]] == ' ')
            map[index[i]] = 'O';
        i++;
    }
}
