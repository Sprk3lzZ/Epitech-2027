/*
** EPITECH PROJECT, 2022
** context.c
** File description:
** context.c
*/

#include "context.h"
#include <stdlib.h>

context_t *create_context(void)
{
    context_t *ctx = malloc(sizeof(context_t));

    ctx->l_a = create_list();
    ctx->l_b = create_list();
    ctx->operations = create_operation_list();
    return ctx;
}

void destroy_context(context_t *ctx)
{
    destroy_list(ctx->l_a);
    destroy_list(ctx->l_b);
    destroy_operation_list(ctx->operations);
    free(ctx);
}
