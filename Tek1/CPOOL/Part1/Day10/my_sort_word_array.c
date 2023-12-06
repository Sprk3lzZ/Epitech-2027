/*
** EPITECH PROJECT, 2022
** my_sort_word_array
** File description:
** my_sort_word_array
*/

#include "lib/my/my.h"

static int size_array(char **tab)
{
    int array_size = 0;

    for (int i = 0; tab[i] != 0; i++) {
        array_size++;
    }
    return array_size;
}

static int get_minimum_index(char **array, int size, int offset)
{
    int index_minimum = offset;
    for (int position = offset; position < size; position++) {
        if (my_strcmp(array[position], array[index_minimum]) < 0)
            index_minimum = position;
    }
    return index_minimum;
}

static void swap_in_array(char **array, int index1, int index2)
{
    char *temp = array[index1];

    array[index1] = array[index2];
    array[index2] = temp;
}

static void my_sort_array(char **array, int size)
{
    if (size == 1)
        return;
    for (int i = 0; i < size; i++) {
        swap_in_array(array, get_minimum_index(array, size, i), i);
    }
}

int my_sort_word_array(char **tab)
{
    my_sort_array(tab, size_array(tab));
    return 0;
}
