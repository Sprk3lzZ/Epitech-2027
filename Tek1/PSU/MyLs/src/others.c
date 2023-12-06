/*
** EPITECH PROJECT, 2022
** others
** File description:
** others
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>

char *get_permission(struct stat stats)
{
    char *permission = malloc(sizeof(char) * 11);

    permission[0] = (S_ISDIR(stats.st_mode)) ? 'd' : '-';
    permission[1] = (stats.st_mode & S_IRUSR) ? 'r' : '-';
    permission[2] = (stats.st_mode & S_IWUSR) ? 'w' : '-';
    permission[3] = (stats.st_mode & S_IXUSR) ? 'x' : '-';
    permission[4] = (stats.st_mode & S_IRGRP) ? 'r' : '-';
    permission[5] = (stats.st_mode & S_IWGRP) ? 'w' : '-';
    permission[6] = (stats.st_mode & S_IXGRP) ? 'x' : '-';
    permission[7] = (stats.st_mode & S_IROTH) ? 'r' : '-';
    permission[8] = (stats.st_mode & S_IWOTH) ? 'w' : '-';
    permission[9] = (stats.st_mode & S_IXOTH) ? 'x' : '-';
    permission[10] = '\0';
    return permission;
}

void loop_parsing(char *str, char *str2, int i, int j)
{
    while (str[i] != '\0') {
        str2[j] = str[i];
        i++;
        j++;
    }
}

char *parsing(char *str)
{
    int i = 0;
    int j = 0;
    char *str2 = malloc(sizeof(char) * 100);

    while (str[i] != '\0') {
        if (str[i] == '-') {
            i++;
            loop_parsing(str, str2, i, j);
        }
        i++;
    }
    return str2;
}

char *get_file_type(struct stat stats)
{
    if (S_ISREG(stats.st_mode))
        return "-";
    if (S_ISDIR(stats.st_mode))
        return "d";
    if (S_ISCHR(stats.st_mode))
        return "c";
    if (S_ISBLK(stats.st_mode))
        return "b";
    if (S_ISFIFO(stats.st_mode))
        return "p";
    if (S_ISLNK(stats.st_mode))
        return "l";
    if (S_ISSOCK(stats.st_mode))
        return "s";
    return "?";
}
