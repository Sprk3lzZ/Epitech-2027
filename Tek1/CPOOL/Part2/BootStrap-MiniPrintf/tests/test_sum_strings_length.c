/*
** EPITECH PROJECT, 2022
** test_sum_strings_length
** File description:
** test_sum_strings_length
*/

#include <criterion/criterion.h>
#include "../includes/bsprintf.h"

Test(sum_strings_length, return_str_lengths)
{
    int value = sum_strings_length(5, "Hello", "a", "toto", "", "plop");
    cr_assert_eq(value, 14);
}
