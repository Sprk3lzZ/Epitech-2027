/*
** EPITECH PROJECT, 2022
** getter.c
** File description:
** getter.c
*/

#include "my.h"

int get_size_line(char *map)
{
    int size;
    size = 0;

    if (map[0] == '\0')
        return 84;
    while (map[size] != '\n')
        size++;
    return size;
}

int get_index_p(char *map)
{
    int index;
    index = 0;

    while (map[index] != '\0') {
        if (map[index] == 'G')
            return index;
        index++;
    }
    return 0;
}

int get_nb_it(char *map, char item)
{
    int nb;
    nb = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == item)
            nb++;
    return nb;
}

int *get_pos_it(char *map, char item)
{
    int *size;
    int j;
    size = malloc(sizeof(int) * get_nb_it(map, item) + 1);
    j = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == item) {
            size[j] = i;
            j++;
        }
    }
    size[get_nb_it(map, item)] = 0;
    return size;
}

int get_nb_movements(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
        if (atoi(av[i]) != 0)
            return (atoi(av[i]));
}
