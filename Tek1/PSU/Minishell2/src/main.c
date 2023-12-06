/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "mysh.h"

int extract_program(int status, char *not_found)
{
    if (my_strcmp(not_found, "env") == 0 || my_strcmp(not_found, "exit") == 0)
        return 0;
    if (status != 0) {
        write(1, not_found, my_strlen(not_found));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
}

void error_handling(int status, char **arguments)
{
    if (!WIFSIGNALED(status))
        return;
    if (WTERMSIG(status) == SIGSEGV)
        write(2, "Segmentation fault", 18);
    if (WTERMSIG(status) == SIGFPE)
        write(2, "Floating exception", 18);
    if (WCOREDUMP(status))
        write(2, " (core dumped)", 14);
    write(2, "\n", 1);
}

int program(char **arguments, char **env, char *pathname, int status)
{
    pid_t cpid;
    char *not_found = my_strdup(arguments[0]);
    not_found[my_strlen(not_found) - 1] = '\0';
    cpid = fork();
    if (cpid != 0) {
        wait(&status);
        error_handling(status, arguments);
    } else {
        status = access(pathname, F_OK);
        extract_program(status, not_found);
        check_binary(arguments, env, pathname);
        exit(1);
    }
    if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);
    return WEXITSTATUS(status);
}

int hawaw(char **arguments, char **env, int status)
{
    if (access(arguments[0], F_OK) == 0) {
        return program(arguments, env, arguments[0], status);
    } else {
        arguments[0] = my_strcat(arguments[0], "\n");
        return program(arguments, env,
            get_path_for_exe(arguments[0], env), status);
    }
}

int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    size_t len = 0;
    char **arguments = NULL;
    int status = NULL;
    int exit_status = 0;
    while (1) {
        if (isatty(0))
            write(1, "$> ", 3);
        status = getline(&line, &len, stdin);
        print_exit(status, exit_status);
        if (my_strcmp(line, "\n") == 0)
            continue;
        arguments = my_str_to_word_array(line);
        if (arguments[0] == NULL)
            continue;
        extract_condition(arguments);
        builtin(arguments, env);
        exit_status = hawaw(arguments, env, status);
    }
    return 0;
}
