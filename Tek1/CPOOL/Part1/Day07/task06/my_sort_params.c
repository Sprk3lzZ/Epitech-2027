/*
** EPITECH PROJECT, 2022
** my_sort_params.c
** File description:
** my_sort_params.c
*/


int get_minimum_index(char **array, int size, int offset)
{
    int index_minimum = offset;
    for (int position = offset; position < size; position++) {
        if (my_strcmp(array[position], array[index_minimum]) < 0)
            index_minimum = position;
    }
    return index_minimum;
}

void swap_in_array(char **array, int index1, int index2)
{
    char *temp = array[index1];

    array[index1] = array[index2];
    array[index2] = temp;
}

void my_sort_int_array(char **array, int size)
{
    if (size == 1)
        return;
    for (int i = 0; i < size; i++) {
        swap_in_array(array, get_minimum_index(array, size, i), i);
    }
}

int main(int argc, char **argv)
{
    my_sort_int_array(argv, argc);
    for (int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
