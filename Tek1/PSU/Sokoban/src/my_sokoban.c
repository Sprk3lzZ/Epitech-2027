/*
** EPITECH PROJECT, 2022
** my_sokoban.c
** File description:
** my_sokoban.c
*/
#include "my.h"
#include <ncurses.h>

void help(void)
{
    my_printf("USAGE\n     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n     map  file representing the warehouse map, ");
    my_printf("containing '#' for walls,\n");
    my_printf("          'P' for the player, 'X' for boxes and 'O' for ");
    my_printf("storage locations.\n");
}

static void reading(int file, char *map, struct stat stats)
{
    int size = 0;
    while (size != stats.st_size)
        size += read(file, map, stats.st_size);
    close(file);

    map[stats.st_size] = '\0';
}

char *mapping(char **av)
{
    struct stat stats;
    stat(av[1], &stats);
    int file = open(av[1], O_RDONLY);
    if (file < 0)
        return NULL;
    char *map = malloc(sizeof(char) * stats.st_size + 1);
    reading(file, map, stats);

    return map;
}

void my_sokoban(char *map, char **av)
{
    int ch = '\0', pos = get_index_p(map);
    int *sizes = all_size_map(map), *pos_o = get_index_o(map);
    char *map_copy;
    init_game();
    while (ch != 'q') {
        end_game(map, pos_o, sizes);
        map_copy = mapping(av);
        if (ch == ' ') {
            map = map_copy;
            pos = get_index_p(map), pos_o = get_index_o(map);
        }
        clear();
        pos = get_index_p(map);
        printw("%s", map);
        ch = getch();
        replace(ch, pos, map, sizes);
        replace_o(map, pos_o);
        refresh();
    }
    endwin();
}

int main(int ac, char **av, char **env)
{
    if (ac != 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    if (!env[0])
        return 84;
    if (check_valid_map(av) != 0)
        return 84;
    char *map = mapping(av);
    if (check_map(map) != 0)
        return 84;
    my_sokoban(map, av);
}
