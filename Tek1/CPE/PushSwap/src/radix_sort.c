/*
** EPITECH PROJECT, 2022
** radix_sort.c
** File description:
** radix_sort.c
*/

#include "context.h"
#include <stddef.h>

static unsigned int count(unsigned int length)
{
    unsigned int i = 0;

    for (; length != 0; length /= 2)
        i++;
    return i;
}

static void sort(context_t *ctx, unsigned int iteration)
{
    unsigned int length = ctx->l_a->length;

    for (unsigned int i = 0; i < length; i++) {
        if ((ctx->l_a->begin->value & (1 << iteration)) == 0) {
            do_pb(ctx);
        } else {
            do_ra(ctx);
        }
    }
    while (ctx->l_b->length)
        do_pa(ctx);
}

void radix_sort(context_t *ctx)
{
    unsigned int iterations = count(ctx->l_a->length);

    for (unsigned int i = 0; i < iterations; i++) {
        if (is_sorted(ctx))
            break;
        sort(ctx, i);
    }
}
