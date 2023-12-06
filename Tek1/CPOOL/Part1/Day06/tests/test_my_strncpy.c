/*
** EPITECH PROJECT, 2022
** test_my_strncpy
** File description:
** test_my_strncpy
*/

#include <string.h>
#include <criterion/criterion.h>

char my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, test_one)
{
    char dest[6];
    my_strncpy(dest, "HelloWorld", 2);
    cr_assert_str_eq(dest, "He");
}

Test(my_strncpy, test_two)
{
    char my_dest[1];
    char dest[1];
    my_strncpy(my_dest, "", 0);
    strncpy(dest, "", 0);
    cr_assert_arr_eq(my_dest, dest, 0);
}

Test(my_strncpy, test_three)
{
    char my_dest[13];
    char dest[13];
    my_strncpy(my_dest, "MyNameIsYanis", 13);
    strncpy(dest, "MyNameIsYanis", 13);
    cr_assert_arr_eq(my_dest, dest, 13);
}

Test(my_strncpy, test_four)
{
    char my_dest[11];
    char dest[11];
    my_strncpy(my_dest, "HelloWorld", 11);
    strncpy(dest, "HelloWorld", 11);
    cr_assert_arr_eq(my_dest, dest, 11);
}

Test(my_strncpy, test_six)
{
    char my_dest[1];
    char dest[1];
    my_strncpy(my_dest, "HelloWorld", 0);
    strncpy(dest, "HelloWorld", 0);
    cr_assert_arr_eq(my_dest, dest, 0);
}

Test(my_strncpy, test_seven)
{
    char my_dest[10];
    char dest[10];
    my_strncpy(my_dest, "HelloWorld", 10);
    strncpy(dest, "HelloWorld", 10);
    cr_assert_arr_eq(my_dest, dest, 10);
}

Test(my_strncpy, test_eight)
{
    char my_dest[50];
    char dest[50];
    my_strncpy(my_dest, "HelloWorld", 60);
    strncpy(dest, "HelloWorld", 60);
    cr_assert_arr_eq(my_dest, dest, 60);
}
