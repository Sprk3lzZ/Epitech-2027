/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int read_files(int ac, char **av, char *buffer);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int main(int ac, char **av)
{
    char buffer[10000];

    if (ac == 1) {
        while (read(0, buffer, 10000) > 0)
            my_putstr(buffer);
    } else
        return read_files(ac, av, buffer);
    return 0;
}
