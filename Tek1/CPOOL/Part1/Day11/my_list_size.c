/*
** EPITECH PROJECT, 2022
** my_list_size
** File description:
** my_list_size
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    if (begin == 0)
        return 0;
    if (begin->next != 0)
        return my_list_size(begin->next) + 1;
    return 1;
}
