/*
** EPITECH PROJECT, 2022
** test_miniprintf
** File description:
** test_miniprintf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/struct.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (mini_printf, test1) {
    cr_redirect_stdout();
    cr_assert_eq(mini_printf("Hello %s", "World"), 11);
}

Test (mini_printf, test2, .init = redirect_all_std) {
    mini_printf("Hello %s name is Yani%c I'm %d years old", "my", 's', 18);
    cr_assert_stdout_eq_str("Hello my name is Yanis I'm 18 years old");
}

Test (mini_printf, test3) {
    cr_redirect_stdout();
    cr_assert_eq(mini_printf("Hello %y", "World"), -84);
}

Test (mini_printf, test4, .init = redirect_all_std) {
    mini_printf("Mult = %d * %d = %i", 5, -5, -25);
    cr_assert_stdout_eq_str("Mult = 5 * -5 = -25");
}

Test (mini_printf, test5, .init = redirect_all_std) {
    mini_printf("Mult = %d + %d = %i", -2147483648, -50, -50);
    cr_assert_stdout_eq_str("Mult = -2147483648 + -50 = -50");
}

Test (mini_printf, test6, .init = redirect_all_std) {
    mini_printf("Your coverage it's : %%100");
    cr_assert_stdout_eq_str("Your coverage it's : %100");
}
