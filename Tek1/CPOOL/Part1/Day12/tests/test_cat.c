/*
** EPITECH PROJECT, 2022
** test cat
** File description:
** test cat
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int read_stdin(void);
int read_files(int ac, char **av, char *buffer);

void redirect_all_std(void)
{
    cr_redirect_stdin();
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(read_files, test_one, .init = redirect_all_std) {
    int err = 0;
    int argc = 2;
    char buffer[10000];
    char *argv[] = {"./cat", "../tests/text.txt"};

    err = read_files(argc, argv, buffer);
    cr_assert_eq(err, 0);
    cr_assert_stdout_eq_str("Hello World How are you ?\n");
}

Test(read_files, test_two, .init = redirect_all_std) {
    int argc = 2;
    char buffer[10000];
    char *argv[] = { "./cat", "../tests/test.txt" };
    int err = read_files(argc, argv, buffer);

    cr_assert_eq(err, 84);
    cr_assert_stderr_eq_str("cat: ../tests/test.txt: No such file or directory\n");
    //cr_assert_stdout_eq_str("This is a test used by Criterion !\n");
}
