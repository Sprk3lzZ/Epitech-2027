#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern void rush(int x, int y);

void init(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(rush, test_one, .init = init)
{
    rush(5, 3);
    cr_assert_stdout_eq_str("ABBBC\nB   B\nABBBC\n");
}

Test(rush, test_two, .init = init)
{
    rush(5, 1);
    cr_assert_stdout_eq_str("BBBBB\n");
}

Test(rush, test_three, .init = init)
{
    rush(1, 1);
    cr_assert_stdout_eq_str("B\n");
}

Test(rush, test_four, .init = init)
{
    rush(1, 5);
    cr_assert_stdout_eq_str("B\nB\nB\nB\nB\n");
}

Test(rush, test_five, .init = init)
{
    rush(4, 4);
    cr_assert_stdout_eq_str("ABBC\nB  B\nB  B\nABBC\n");
}

Test(rush, test_six, .init = init)
{
    rush(0, 0);
    cr_assert_stderr_eq_str("Invalid size\n");
}

Test(rush, test_seven, .init = init)
{
    rush(-10, 1);
    cr_assert_stderr_eq_str("Invalid size\n");
}

Test(rush, test_eight, .init = init)
{
    rush(-10, 0);
    cr_assert_stderr_eq_str("Invalid size\n");
}

Test(rush, test_nine, .init = init)
{
    rush(0, -10);
    cr_assert_stderr_eq_str("Invalid size\n");
}

Test(rush, test_ten, .init = init)
{
    rush(1, -10);
    cr_assert_stderr_eq_str("Invalid size\n");
}
