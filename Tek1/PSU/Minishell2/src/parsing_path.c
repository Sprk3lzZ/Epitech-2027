/*
** EPITECH PROJECT, 2023
** parsing_path.c
** File description:
** parsing_path.c
*/

#include "mysh.h"

char *parse_path(char **env)
{
    char *line = NULL;
    char *envi = NULL;
    int i = 0;

    while (env[i] != NULL) {
        envi = my_strdup(env[i]);
        line = strtok(envi, "=");
        if (!line)
            return NULL;
        if (my_strcmp(line, "PATH") == 0) {
            return strtok(NULL, "=");
        }
        i++;
    }
    return NULL;
}

char *get_path(char *path)
{
    return strtok(path, ":");
}

char *get_full_path(char *path, char *command)
{
    char *full_command = malloc(sizeof(char) *
    (my_strlen(path) + my_strlen(command) + 2));

    full_command = my_strcat(full_command, path);
    full_command = my_strcat(full_command, "/");
    full_command = my_strcat(full_command, command);

    return full_command;
}

int check_access(char *command, char **env)
{
    char *full_command = NULL;
    char *path = parse_path(env);
    char *path2 = get_path(path);

    while (path2 != NULL) {
        full_command = get_full_path(path2, command);
        full_command[my_strlen(full_command) - 1] = '\0';
        if (access(full_command, X_OK) == 0)
            return 0;
        path2 = get_path(NULL);
    }
    return 1;
}

char *get_path_for_exe(char *command, char **env)
{
    char *full_command = NULL;
    char *path = parse_path(env);
    char *path2 = get_path(path);

    while (path2 != NULL) {
        full_command = get_full_path(path2, command);
        full_command[my_strlen(full_command) - 1] = '\0';
        if (access(full_command, X_OK) == 0) {
            return full_command;
        }
        path2 = get_path(NULL);
    }
    return NULL;
}
