/*
** EPITECH PROJECT, 2023
** my_sokoban2.c
** File description:
** my_sokoban2.c
*/

#include "my.h"

int moove_g(char *map, infos *tokens, int nb_movement, int size_line)
{
    int pos = get_index_p(map);

    if (map[pos - 1] == 'T' || map[pos - 1] == 'F') {
        map[pos - 1] = 'G';
        if (map[pos - 1] == 'T') {
            tokens->nb_tokens++;
        } else {
            return 1;
        }
    }
    if (map[pos + 1] == 'T') {
        map[pos + 1] = 'G';
        if (map[pos + 1] == 'T') {
            tokens->nb_tokens++;
        } else {
            return 1;
        }
    }
}

int moov_g2(char *map, infos *tokens, int nb_movement, int size_line)
{
    int pos = get_index_p(map);
    map[pos] = '.';
    if (moove_g(map, tokens, nb_movement, size_line) == 1)
        return 1;
    if (map[pos + size_line + 1] == 'T' || map[pos + size_line + 1] == 'F') {
        map[pos + size_line + 1] = 'G';
        if (map[pos + size_line + 1] == 'T') {
            tokens->nb_tokens++;
        } else
            return 1;
    }
    if (map[pos - size_line - 1] == 'T' || map[pos - size_line - 1] == 'F') {
        map[pos - size_line - 1] = 'G';
        if (map[pos - size_line - 1] == 'T') {
            tokens->nb_tokens++;
        } else {
            return 1;
        }
    }
    return 0;
}
