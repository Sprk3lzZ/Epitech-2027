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
#include <stdint.h>
#include <unistd.h>
#include <ncurses.h>

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

// Sokoban
int check_map(char *map);
int get_size_line(char *map);
int get_nb_line(char *map);
int get_index_p(char *map);

int get_line_p(char *map);
int *all_size_map(char *map);
int get_line_i(char *map, int index_i);

void moving(int ch, int pos, char *map, int *sizes);
void moving_left(int pos, char *map);
void moving_right(int pos, char *map);
void moving_down(int pos, char *map, int *sizes);
void moving_up(int pos, char *map, int *sizes);

int check_block(int ch, int pos, char *map, int *sizes);
int check_valid_map(char **argv);

void replace_o(char *map, int *index);
int *get_index_o(char *map);
int get_nb_o(char *map);

void check_win(char *map, int *pos_o);
int check_arround(int *sizes, char *map);


void replace(int ch, int pos, char *map, int *sizes);
void init_game(void);
void end_game(char *map, int *pos_o, int *sizes);
void is_lose(int *sizes, char *map);
