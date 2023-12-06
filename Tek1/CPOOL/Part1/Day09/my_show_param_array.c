/*
** EPITECH PROJECT, 2022
** my_show_param_array
** File description:
** my_show_param_array
*/

#include "my.h"

int my_show_param_array(struct info_param const *par)
{
    int i = 0;

    while (par[i].str != 0) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        i++;
    }
    return 0;
}
