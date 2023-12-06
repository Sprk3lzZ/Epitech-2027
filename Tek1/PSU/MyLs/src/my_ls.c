/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls
*/

#include "my.h"

int error(char *parsing)
{
    for (int i = 0; parsing[i] != '\0'; i++) {
        if (parsing[i] != 'l' && parsing[i] != 'd' && parsing[i] != 'R'
        && parsing[i] != 'r' && parsing[i] != 't' && parsing[i] != 'a')
        return 84;
    }
    return 0;
}

char *print_file_name(char *file_name)
{
    for (char *ptr = file_name; *ptr && ptr[1]; ptr++)
        file_name += (*ptr == '/' && ptr[1] && ptr[1] != '/') *
            (ptr - file_name + 1);
    return file_name;
}

int size_stblock(char const *name)
{
    DIR *dir = opendir(name);
    struct dirent *file;
    struct stat stats;
    int total = 0;

    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.') {
            stat(file->d_name, &stats);
            total += stats.st_blocks;
        }
    }
    closedir(dir);
    return total / 2;
}

static void free_params(linked_list_t *list)
{
    linked_list_t *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int main(int ac, char **av)
{
    for (int i = 2; i < ac; i++) {
        if (av[1][0] == '-' && av[1][1] == 'l' && av[i][0] != '-')
            print_file_info_simple(av[i]);
    }
    if (ac == 1)
        print_simple_ls(opendir("."), NULL);
    if (ac == 2 && (av[1][1] == 'l' && av[1][2] != 'a'))
        print_file_info(".");
    if (ac == 2 && av[1][1] == 'a' && av[1][2] != 'l')
        print_simple_ls_a(opendir("."), NULL);
    if (ac == 2 && av[1][1] == 'a' && av[1][2] == 'l')
        print_file_info_a(".");
    if (ac == 2 && av[1][1] == 'l' && av[1][2] == 'a')
        print_file_info_a(".");
    if (ac == 3 && av[1][1] == 'a' && av[2][1] == 'l')
        print_file_info_a(".");
    if (ac == 3 && av[1][1] == 'l' && av[2][1] == 'a')
        print_file_info_a(".");
    return 0;
}
