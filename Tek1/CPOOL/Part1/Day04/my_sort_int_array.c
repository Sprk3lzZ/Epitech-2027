/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** my_sort_int_array
*/

int get_minimum_index(int *array, int size, int offset)
{
    int index_minimum = offset;
    for (int position = offset; position < size; position++) {
        if (array[position] < array[index_minimum])
            index_minimum = position;
    }
    return index_minimum;
}

void swap_in_array(int *array, int index1, int index2)
{
    int temp = array[index1];

    array[index1] = array[index2];
    array[index2] = temp;
}

void my_sort_int_array(int *array, int size)
{
    if (size == 1)
        return;
    for (int i = 0; i < size; i++) {
        swap_in_array(array, get_minimum_index(array, size, i), i);
    }
}
