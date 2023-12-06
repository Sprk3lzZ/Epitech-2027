/*
** EPITECH PROJECT, 2022
** special_sort.c
** File description:
** special_sort.c
*/

#include "context.h"

static unsigned int find(context_t *ctx, unsigned int i)
{
    node_t *node = ctx->l_a->begin;

    for (; i != 0; i--)
        node = node->next;
    return node->value;
}

void sort2(context_t *ctx)
{
    if (ctx->l_a->begin->value > ctx->l_a->begin->next->value)
        do_sa(ctx);
}

static void sort3_extracted_chupapi(context_t *ctx)
{
    if (find(ctx, 0) < find(ctx, 1)
        && find(ctx, 1) > find(ctx, 2)
        && find(ctx, 2) > find(ctx, 0)) {
        do_sa(ctx);
        do_ra(ctx);
    }
    if (find(ctx, 0) > find(ctx, 1)
        && find(ctx, 1) < find(ctx, 2)
        && find(ctx, 2) > find(ctx, 0))
        do_sa(ctx);
    if (find(ctx, 0) > find(ctx, 1)
        && find(ctx, 1) < find(ctx, 2)
        && find(ctx, 2) < find(ctx, 0))
        do_ra(ctx);
}

void sort3(context_t *ctx)
{
    if (find(ctx, 0) < find(ctx, 1)
        && find(ctx, 1) > find(ctx, 2)
        && find(ctx, 2) < find(ctx, 1))
        do_rra(ctx);
    if (find(ctx, 0) > find(ctx, 1)
        && find(ctx, 1) > find(ctx, 2)
        && find(ctx, 2) < find(ctx, 0)) {
        do_sa(ctx);
        do_rra(ctx);
    }
    sort3_extracted_chupapi(ctx);
}

void sort45(context_t *ctx)
{
    do_pb(ctx);
    if (ctx->l_a->length == 4)
        do_pb(ctx);
    sort3(ctx);
    while (ctx->l_b->length != 0) {
        for (unsigned int i = 0;
            ctx->l_a->begin->value < ctx->l_a->begin->next->value;
            i++)
            do_ra(ctx);
        do_pa(ctx);
    }
    while (!is_sorted(ctx))
        do_ra(ctx);
}
