/*
** EPITECH PROJECT, 2022
** operation_list.c
** File description:
** operation_list.c
*/

#include "context.h"
#include <stdlib.h>

operation_list_t *create_operation_list(void)
{
    operation_list_t *list = malloc(sizeof(operation_list_t));

    list->begin = NULL;
    list->end = NULL;
    return list;
}

void destroy_operation_list(operation_list_t *list)
{
    operation_t *current = list->begin;
    operation_t *next;

    for (; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
    free(list);
}

void append_operation_list(operation_list_t *list, char const *operation)
{
    operation_t *node;

    node = malloc(sizeof(node_t));
    node->operation = operation;
    node->next = NULL;
    if (list->end != NULL) {
        list->end->next = node;
    } else {
        list->begin = node;
    }
    list->end = node;
}
