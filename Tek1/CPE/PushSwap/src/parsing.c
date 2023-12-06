/*
** EPITECH PROJECT, 2022
** parsing.c
** File description:
** parsing.c
*/

#include "context.h"
#include "my.h"
#include <stdlib.h>

static unsigned int find_minimum(int *array, unsigned int length)
{
    unsigned int minimum = 0;

    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < array[minimum])
            minimum = i;
    }
    return minimum;
}

static void sort(int *array, unsigned int length)
{
    for (unsigned int i = 0; i + 1 < length; i++)
        swap(&array[i], &array[i + find_minimum(array + i, length - i)]);
}

static void find_index(context_t *ctx, int value, int *array,
    unsigned int length)
{
    for (unsigned int i = 0; i < length; i++) {
        if (array[i] == value) {
            append_list(ctx->l_a, i);
            return;
        }
    }
}

static void map(context_t *ctx, list_t *list, int *array, unsigned int length)
{
    for (node_t *node = list->begin; node != NULL; node = node->next)
        find_index(ctx, node->value, array, length);
}

int parse_arguments(context_t *ctx, int argc, char **argv)
{
    int value;
    int *array = malloc(sizeof(int) * (argc - 1));
    list_t *list = create_list();
    unsigned int length = 0;

    for (int i = 1; i < argc; i++) {
        if (my_getnbr(argv[i], &value) == 84) {
            free(array);
            destroy_list(list);
            return 84;
        }
        array[length] = value;
        append_list(list, value);
        length++;
    }
    sort(array, length);
    map(ctx, list, array, length);
    free(array);
    destroy_list(list);
    return 0;
}
