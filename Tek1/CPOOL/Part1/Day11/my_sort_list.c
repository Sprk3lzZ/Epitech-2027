/*
** EPITECH PROJECT, 2022
** my_sort_list
** File description:
** my_sort_list
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

void list_swap(linked_list_t *l_list, int (*cmp)())
{
    void *temp = 0;

    if (cmp(l_list->data, l_list->next->data) > 0) {
        temp = l_list->data;
        l_list->data = l_list->next->data;
        l_list->next->data = temp;
    }
}

void my_sort_list(linked_list_t **begin, int (*cmp)())
{
    linked_list_t *l_list1 = *begin;
    linked_list_t *l_list2 = *begin;
    int list_size = my_list_size(l_list1);
    int i = 0;
    int j = 0;

    while (i < list_size) {
        l_list2 = l_list1;
        while (j < list_size - i - 1) {
            list_swap(l_list2, cmp);
            l_list2 = l_list2->next;
            j++;
        }
        i++;
    }
}
