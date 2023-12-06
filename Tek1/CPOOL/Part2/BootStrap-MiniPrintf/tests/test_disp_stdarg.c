/*
** EPITECH PROJECT, 2022
** test disp_stdarg
** File description:
** test disp_strarg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsprintf.h"

Test(disp_stdarg, return_str_lengths, .init = cr_redirect_stdout)
{
    disp_stdarg("csiis", 'X', "hi", 10, -3, "plop");
    cr_assert_stdout_eq_str("X\nhi\n10\n-3\nplop\n");
}
