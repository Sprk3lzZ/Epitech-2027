/*
** EPITECH PROJECT, 2022
** params
** File description:
** params
*/

#include <stdlib.h>
#include "my_list.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *my_list;

    if (ac <= 1)
        return 0;
    my_list = malloc(sizeof(*my_list));
    my_list->data = (void *) av[ac - 1];
    my_list->next = my_params_to_list(ac - 1, av);
    return my_list;
}
