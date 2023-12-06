/*
** EPITECH PROJECT, 2022
** Test my_printf
** File description:
** Test my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, test_i, .init = redirect_all_std)
{
    int result = my_printf("I am %i years old", 18);

    cr_assert_stdout_eq_str("I am 18 years old");
    cr_assert_eq(result, 17);
}
