/*
** EPITECH PROJECT, 2022
** my_find_nodes
** File description:
** my_find_nodes
*/

#include "my.h"
#include "mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin,
    void const *data_ref, int (*cmp)())
{
    linked_list_t const *temp = begin;

    while (temp) {
        if (cmp(temp->data, data_ref) == 0)
            return (linked_list_t *)temp;
        temp = temp->next;
    }
    return 0;
}
