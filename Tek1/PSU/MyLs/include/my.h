/*
** EPITECH PROJECT, 2022
** my h
** File description:
** my h
*/

#pragma once

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include "my_list.h"
#include <stdint.h>

// Outputing
int my_printf(char const *format, ...);

void my_putchar(char c);
int my_putnchar(char c, int n);
void my_putstr_err(char const *str);
void my_putnbr_base(int nbr, char const *base);
void my_putnbr_base_precision(intmax_t nbr, int precision, char const *base);
void my_putunbr_base_precision(uintmax_t nbr, int precision, char const *base);

// String
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);

// Memory
void *my_memmove(void *dest, void const *src, long n);
void *my_realloc(void *src, uint32_t new_length, uint32_t prev_length);

// Maths
intmax_t my_min(intmax_t a, intmax_t b);
intmax_t my_max(intmax_t a, intmax_t b);
intmax_t my_abs(intmax_t a);
intmax_t my_pow(intmax_t nb, intmax_t p);
int my_digit_count(intmax_t a);
int my_unsigned_digit_count(uintmax_t a, uintmax_t base);
intmax_t get_exponent(long double nbr);
long double get_base(long double nbr, int precision);

char *get_permission(struct stat stats);
void loop_parsing(char *str, char *str2, int i, int j);
char *parsing(char *str);
char *get_file_type(struct stat stats);
void print_file_info(char const *name);
void print_file_info_simple(char const *name);
void print_file_info_a(char const *name);
void print_simple_ls(DIR *d, struct dirent *dir);
void print_simple_ls_a(DIR *d, struct dirent *dir);
linked_list_t *my_params_to_list(int ac, char * const *av);
