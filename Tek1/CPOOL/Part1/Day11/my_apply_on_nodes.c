/*
** EPITECH PROJECT, 2022
** my_apply_on_nodes
** File description:
** my_apply_on_nodes
*/

#include "my.h"
#include "mylist.h"

int my_apply_on_nodes(linked_list_t *begin, int(*f)(void *))
{
    linked_list_t *temp = begin;

    while (temp != 0) {
        (*f)(temp->data);
        temp = temp->next;
    }
}
