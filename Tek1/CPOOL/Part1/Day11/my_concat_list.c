/*
** EPITECH PROJECT, 2022
** my_concat_list
** File description:
** my_concat_list
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    linked_list_t *l_list = *begin1;

    if (*begin1 == 0 && begin2 != 0) {
        *begin1 = begin2;
        return;
    } else if (*begin1 != 0 && begin2 == 0)
        return;
    if (l_list->next)
        my_concat_list(&(l_list->next), begin2);
    else
        l_list->next = begin2;
}
