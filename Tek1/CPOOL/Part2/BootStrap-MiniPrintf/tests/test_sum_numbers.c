/*
** EPITECH PROJECT, 2022
** test sum_numbers
** File description:
** test sum_number
*/

#include <criterion/criterion.h>
#include "../includes/bsprintf.h"

Test(sum_numbers, return_sum_numbers)
{
    int ret = sum_numbers(3, 21, 25, -4);
    cr_assert_eq(ret, 42);
}
