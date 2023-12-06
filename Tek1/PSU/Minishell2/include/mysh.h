/*
** EPITECH PROJECT, 2023
** mysh.h
** File description:
** mysh.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdbool.h>

char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
void my_putchar(char c);
int my_isnum(char *str);
int my_getnbr(char const *str);
int my_tablen(char **tab);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *get_path_for_exe(char *command, char **env);
int check_access(char *command, char **env);
char *get_full_path(char *path, char *command);
char *get_path(char *path);
char *parse_path(char **env);
void print_exit(int status, int exit_status);
void check_binary(char **arguments, char **env, char *pathname);

void print_env(char **env);
void my_exit(char **arguments);
void builtin(char **arguments, char **env);
bool is_folder(char const *program);
void extract_condition(char **arguments);
