/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** list.h
*/

#pragma once

typedef struct node_s {
    int value;
    struct node_s *next;
} node_t;

typedef struct {
    node_t *begin;
    node_t *end;
    unsigned int length;
} list_t;

list_t *create_list(void);
void destroy_list(list_t *list);
void prepend_list(list_t *list, int value);
void append_list(list_t *list, int value);
void pop_list(list_t *list);
void pop_last_list(list_t *list);
