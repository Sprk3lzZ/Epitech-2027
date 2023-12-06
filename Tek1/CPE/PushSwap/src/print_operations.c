/*
** EPITECH PROJECT, 2022
** print_operations.c
** File description:
** print_operations.c
*/

#include "context.h"
#include "my.h"
#include <unistd.h>

void print_operations(context_t *ctx)
{
    for (operation_t *op = ctx->operations->begin; op != NULL; op = op->next) {
        write(1, op->operation, my_strlen(op->operation));
        if (op->next != NULL)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}
