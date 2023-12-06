/*
** EPITECH UNIT TESTS, 2022
** Authors : Ximaz
** File description :
** Unit tests to test the my_sort_list function.
*/

#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/mylist.h"
#include <criterion/criterion.h>

linked_list_t *my_params_to_list(int ac, char *const *av);
void my_sort_list(linked_list_t **begin, int (*cmp)());

Test(my_sort_list, works)
{
    char *const av[] = { "3", "1", "2", "0" };
    linked_list_t *params = my_params_to_list(4, av);

    my_sort_list(&params, my_strcmp);
    cr_assert_str_eq(params->data, "0");
    params = params->next;
    cr_assert_str_eq(params->data, "1");
    params = params->next;
    cr_assert_str_eq(params->data, "2");
    params = params->next;
    cr_assert_str_eq(params->data, "3");
}

Test(my_sort_list, empty)
{
    char *const av[] = { };
    linked_list_t *params = my_params_to_list(0, av);

    my_sort_list(&params, my_strcmp);
    cr_assert_eq(params, 0);
}
