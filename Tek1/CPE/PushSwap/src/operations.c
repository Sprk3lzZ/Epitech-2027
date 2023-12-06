/*
** EPITECH PROJECT, 2022
** operations.c
** File description:
** operations.c
*/

#include "context.h"
#include <stddef.h>

void do_pa(context_t *ctx)
{
    if (ctx->l_b->begin != NULL) {
        prepend_list(ctx->l_a, ctx->l_b->begin->value);
        pop_list(ctx->l_b);
        append_operation_list(ctx->operations, "pa");
    }
}

void do_pb(context_t *ctx)
{
    if (ctx->l_a->begin != NULL) {
        prepend_list(ctx->l_b, ctx->l_a->begin->value);
        pop_list(ctx->l_a);
        append_operation_list(ctx->operations, "pb");
    }
}

void do_sa(context_t *ctx)
{
    int value;

    if (ctx->l_a->begin != ctx->l_b->end) {
        value = ctx->l_a->begin->value;
        ctx->l_a->begin->value = ctx->l_a->begin->next->value;
        ctx->l_a->begin->next->value = value;
        append_operation_list(ctx->operations, "sa");
    }
}

void do_ra(context_t *ctx)
{
    if (ctx->l_a->begin != NULL) {
        append_list(ctx->l_a, ctx->l_a->begin->value);
        pop_list(ctx->l_a);
        append_operation_list(ctx->operations, "ra");
    }
}

void do_rra(context_t *ctx)
{
    if (ctx->l_a->begin != NULL) {
        prepend_list(ctx->l_a, ctx->l_a->end->value);
        pop_last_list(ctx->l_a);
        append_operation_list(ctx->operations, "rra");
    }
}
