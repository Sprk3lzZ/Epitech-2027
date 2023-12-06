/*
** EPITECH PROJECT, 2022
** cat
** File description:
** cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

static int my_strlen(char const *str)
{
    int occurence = 0;
    for (int i = 0; str[i] != '\0'; i++)
        occurence++;
    return occurence;
}

int errors(char *name, int error_type)
{
    write(2, "cat: ", 5);
    write(2, name, my_strlen(name));
    if (error_type == 21)
        write(2, ": Is a directory\n", 17);
    if (error_type == 2)
        write(2, ": No such file or directory\n", 28);
    return 84;
}

int bufferisation (int i, char **av, char *buffer, int file)
{
    long len = -1;

    while (len != 0) {
            len = read(file, buffer, 10000);
            if (errno != 0) {
                close(file);
                return errors(av[i], errno);
            }
            write(1, buffer, len);
    }
}

int read_files(int ac, char **av, char *buffer)
{
    int file;
    long len = -1;
    int i = 1;
    int error = 0;

    while (i < ac) {
        file = open(av[i], O_RDONLY);
        if (errno == 11)
            errno = 0;
        if (errno != 0) {
            error += errors(av[i], errno);
            i++;
            errno = 0;
            continue;
        }
        bufferisation(i, av, buffer, file);
        close(file);
        i++;
    }
    return error ? 84 : 0;
}
