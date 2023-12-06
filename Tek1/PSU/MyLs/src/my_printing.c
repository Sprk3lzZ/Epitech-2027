/*
** EPITECH PROJECT, 2022
** printing
** File description:
** printing
*/

#include "my.h"
#include "my_list.h"

void print_file_info(char const *name)
{
    int total = size_stblock(name);
    DIR *d = opendir(name);
    struct dirent *dir;
    struct stat stats;
    char *permission;
    my_printf("total %d\n", total);
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.') {
            stat(dir->d_name, &stats);
            char *time = &ctime(&stats.st_mtime)[4];
            time[12] = '\0';
            struct passwd *pwd = getpwuid(stats.st_uid);
            permission = get_permission(stats);
            my_printf("%s %ld %s %s %ld ", permission,
            stats.st_nlink, pwd->pw_name, pwd->pw_name, stats.st_size);
            my_printf("%s %s\n",time, dir->d_name);
            free(permission);
        }
    }
    closedir(d);
}

void print_file_info_simple(char const *name)
{
    struct stat stats;
    char *permission;

    stat(name, &stats);
    char *time = &ctime(&stats.st_mtime)[4];
    time[12] = '\0';
    struct passwd *pwd = getpwuid(stats.st_uid);
    permission = get_permission(stats);
    my_printf("%s %ld %s %s %ld ", permission,
    stats.st_nlink, pwd->pw_name, pwd->pw_name, stats.st_size);
    my_printf("%s %s\n", time, name);
    free(permission);
}

void print_file_info_a(char const *name)
{
    int total = size_stblock(name);
    DIR *d = opendir(name);
    struct dirent *dir;
    struct stat stats;
    char *permission;
    my_printf("total %d\n", total);
    while ((dir = readdir(d)) != NULL) {
            stat(dir->d_name, &stats);
            char *time = &ctime(&stats.st_mtime)[4];
            time[12] = '\0';
            struct passwd *pwd = getpwuid(stats.st_uid);
            permission = get_permission(stats);
            my_printf("%s %ld %s %s %ld ", permission,
            stats.st_nlink, pwd->pw_name, pwd->pw_name, stats.st_size);
            my_printf("%s %s\n",time, dir->d_name);
            free(permission);
    }
    closedir(d);
}

void print_simple_ls(DIR *d, struct dirent *dir)
{
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] != '.')
            my_printf("%s\n", dir->d_name);
    }
}

void print_simple_ls_a(DIR *d, struct dirent *dir)
{
    while ((dir = readdir(d)) != NULL)
            my_printf("%s\n", dir->d_name);
}
