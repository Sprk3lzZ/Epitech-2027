/*
** EPITECH PROJECT, 2022
** context.h
** File description:
** context.h
*/

#pragma once

#include "list.h"

typedef struct operation_s {
    const char *operation;
    struct operation_s *next;
} operation_t;

typedef struct {
    operation_t *begin;
    operation_t *end;
} operation_list_t;

typedef struct {
    list_t *l_a;
    list_t *l_b;
    operation_list_t *operations;
} context_t;

operation_list_t *create_operation_list(void);
void destroy_operation_list(operation_list_t *list);
void append_operation_list(operation_list_t *list, char const *operation);

void do_pa(context_t *ctx);
void do_pb(context_t *ctx);
void do_sa(context_t *ctx);
void do_ra(context_t *ctx);
void do_rra(context_t *ctx);

context_t *create_context(void);
void destroy_context(context_t *ctx);

int parse_arguments(context_t *ctx, int argc, char **argv);
int is_sorted(context_t *ctx);
void sort2(context_t *ctx);
void sort3(context_t *ctx);
void sort45(context_t *ctx);
void radix_sort(context_t *ctx);
void print_operations(context_t *ctx);
void process(context_t *ctx);
