/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "context.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    context_t *ctx = create_context();
    if (parse_arguments(ctx, argc, argv) == 84) {
        destroy_context(ctx);
        return 84;
    }
    process(ctx);
    destroy_context(ctx);
    return 0;
}
