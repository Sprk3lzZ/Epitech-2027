/*
** EPITECH PROJECT, 2022
** create_list.c
** File description:
** create_list.c
*/

#include "list.h"
#include <stdlib.h>

list_t *create_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->begin = NULL;
    list->end = NULL;
    list->length = 0;
    return list;
}

void destroy_list(list_t *list)
{
    node_t *current = list->begin;
    node_t *next;

    for (; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
    free(list);
}

void prepend_list(list_t *list, int value)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    node->value = value;
    node->next = list->begin;
    list->begin = node;
    if (list->end == NULL)
        list->end = node;
    list->length++;
}

void append_list(list_t *list, int value)
{
    node_t *node;

    node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    if (list->end != NULL) {
        list->end->next = node;
    } else {
        list->begin = node;
    }
    list->end = node;
    list->length++;
}

void pop_list(list_t *list)
{
    node_t *next;

    if (list->length != 0)
        list->length--;
    if (list->begin == list->end && list->begin != NULL) {
        free(list->begin);
        list->begin = NULL;
        list->end = NULL;
    } else {
        next = list->begin->next;
        free(list->begin);
        list->begin = next;
    }
}
