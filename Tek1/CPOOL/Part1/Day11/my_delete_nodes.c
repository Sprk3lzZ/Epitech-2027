/*
** EPITECH PROJECT, 2022
** my_delete_nodes
** File description:
** my_delete_nodes
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int delete_one_node(linked_list_t *node_delete, linked_list_t *previous)
{
    if (node_delete->next) {
        previous->next = node_delete->next;
        node_delete->next = 0;
    } else
        previous->next = 0;
    if (node_delete != 0) {
        free(node_delete);
        node_delete = 0;
    }
    return 0;
}

int my_delete_nodes(linked_list_t **begin, void const *data_ref,
    int (*cmp)())
{
    linked_list_t *l_list = *begin;
    linked_list_t *temp = l_list;
    while (cmp(l_list->data, data_ref) == 0) {
        if (l_list->next) {
            *begin = l_list->next;
            l_list = l_list->next;
        } else {
            *begin = 0;
            return 0;
        }
    }
    while (l_list->next != 0) {
        temp = l_list->next;
        if (cmp(temp->data, data_ref) == 0) {
            delete_one_node(temp, l_list);
            temp = l_list;
        } else
            l_list = l_list->next;
    }
    return 0;
}
