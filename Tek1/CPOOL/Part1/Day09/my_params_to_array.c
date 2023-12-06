/*
** EPITECH PROJECT, 2022
** my_params_to_array
** File description:
** my_params_to_array
*/

#include <stdlib.h>
#include "my.h"

struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *structure;

    structure = malloc(sizeof(struct info_param) * (ac + 1));
    while (i < ac) {
        structure[i].length = my_strlen(av[i]);
        structure[i].str = av[i];
        structure[i].copy = my_strdup(av[i]);
        structure[i].word_array = my_str_to_word_array(av[i]);
        i++;
    }
    structure[ac].str = 0;
    return structure;
}
