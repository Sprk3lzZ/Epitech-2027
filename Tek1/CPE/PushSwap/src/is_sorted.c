/*
** EPITECH PROJECT, 2022
** is_sorted.c
** File description:
** is_sorted.c
*/

#include "context.h"
#include <stddef.h>

int is_sorted(context_t *ctx)
{
    if (ctx->l_b->begin != NULL)
        return 0;
    for (node_t *node = ctx->l_a->begin; node != NULL; node = node->next) {
        if (node->next == NULL)
            break;
        if (node->value > node->next->value)
            return 0;
    }
    return 1;
}
