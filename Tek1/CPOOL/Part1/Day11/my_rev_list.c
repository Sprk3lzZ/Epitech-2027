/*
** EPITECH PROJECT, 2022
** my_rev_list
** File description:
** my_rev_list
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *temp1 = 0;
    linked_list_t *temp2 = 0;
    linked_list_t *list = *begin;

    while (list != 0) {
        temp1 = list->next;
        list->next = temp2;
        temp2 = list;
        list = temp1;
    }
    *begin = temp2;
}
