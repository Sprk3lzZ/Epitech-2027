/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban.c
*/

#include "my.h"

int get_index_map(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
        if (atoi(av[i]) == 0 && av[i][0] != '-')
            return i;
}

static void reading(int file, char *map, struct stat stats)
{
    int size;
    size = 0;

    while (size != stats.st_size)
        size += read(file, map, stats.st_size);
    close(file);
    map[stats.st_size] = '\0';
}

char *mapping(char **av, int ac)
{
    struct stat stats;
    stat(av[get_index_map(av, ac)], &stats);
    int file;
    file = open(av[get_index_map(av, ac)], O_RDONLY);

    if (file < 0)
        return NULL;
    char *map = malloc(sizeof(char) * stats.st_size + 1);
    reading(file, map, stats);
    return map;
}

int check_args(int ac, char **av)
{
    infos args_info;
    args_info.flag_map = 0;
    args_info.flag_file = 0;
    args_info.map = 0;
    args_info.file = 0;

    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-f") == 0 && args_info.flag_file == 0)
            args_info.flag_file = 1;
        if (strcmp(av[i], "-m") == 0 && args_info.flag_map == 0)
            args_info.flag_map = 1;
        if (atoi(av[i]) != 0 && args_info.map == 0)
            args_info.map = 1;
        if (atoi(av[i]) == 0 && args_info.file == 0)
            args_info.file = 1;
    }
    if (args_info.flag_map + args_info.flag_file +
        args_info.map + args_info.file == 4)
        return 0;
    return 84;
}

int main(int ac, char **av)
{
    char *map = mapping(av, ac);
    int *items_pos = get_pos_it(map, 'T');
    int movements;
    int nb_movements = 0;
    int token = get_nb_it(map, 'T');
    infos *tokens = malloc(sizeof(infos) + 1);

    if (ac != 5 || check_args(ac, av) == 84)
        return 84;
    movements = get_nb_movements(av, ac);
    while (nb_movements != -1) {
        printf("Tokens: %d/%d\n", tokens->nb_tokens, token);
        printf("Movement points: %d\n", nb_movements);
        printf("%s\n\n", map);
        nb_movements += moov_g2(map, tokens, movements,
                                get_size_line(map)) * movements;
        nb_movements--;
    }
    free(tokens);
}
