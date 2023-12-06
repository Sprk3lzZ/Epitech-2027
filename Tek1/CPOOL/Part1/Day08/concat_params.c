/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** concat_params
*/

#include <stdlib.h>
#include "my.h"

char *concat_params(int argc, char **argv)
{
    int total_length = argc;
    int i = 0;
    char *str;

    for (int i = 0; i < argc; i++)
        total_length += my_strlen(argv[0]);
    str = malloc(sizeof(char) * total_length);
    i = 0;
    for (int c = 0; c < argc; c++) {
        int length = my_strlen(argv[c]);
        for (int j = 0; j < length; j++) {
            str[i] = argv[c][j];
            i++;
        }
        str[i] = '\n';
        i++;
    }
    str[i - 1] = '\0';
    return str;
}
