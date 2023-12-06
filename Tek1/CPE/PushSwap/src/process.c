/*
** EPITECH PROJECT, 2022
** process.c
** File description:
** process.c
*/

#include "context.h"

void process(context_t *ctx)
{
    if (ctx->l_a->length == 2)
        sort2(ctx);
    if (ctx->l_a->length == 3)
        sort3(ctx);
    if (ctx->l_a->length == 4 || ctx->l_a->length == 5)
        sort45(ctx);
    if (ctx->l_a->length > 5)
        radix_sort(ctx);
    print_operations(ctx);
}
