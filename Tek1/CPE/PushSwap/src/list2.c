/*
** EPITECH PROJECT, 2022
** list2.c
** File description:
** list2.C
*/

#include "list.h"
#include <stddef.h>
#include <stdlib.h>

void pop_last_list(list_t *list)
{
    node_t *node = list->begin;

    if (list->length == 1) {
        free(list->begin);
        list->begin = NULL;
        list->end = NULL;
        list->length = 0;
    }
    if (list->length > 1) {
        free(list->end);
        for (unsigned int i = 0; i + 2 < list->length; i++)
            node = node->next;
        list->length--;
        list->end = node;
        list->end->next = NULL;
    }
}
