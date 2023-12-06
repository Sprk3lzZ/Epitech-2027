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
#include <string.h>

int check_map(char *map);
int get_size_line(char *map);
int get_nb_line(char *map);
int get_index_p(char *map);

int get_line_p(char *map);
int *all_size_map(char *map);
int get_line_i(char *map, int index_i);
int get_nb_movements(char **av, int ac);

void moving(int ch, int pos, char *map, int *sizes);
void moving_left(int pos, char *map);
void moving_right(int pos, char *map);
void moving_down(int pos, char *map, int *sizes);
void moving_up(int pos, char *map, int *sizes);


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
int get_nb_it(char *map, char item);
int *get_pos_it(char *map, char item);
void my_sort_int_array(int *tab, int size);

typedef struct {
    int flag_file;
    int flag_map;
    int file;
    int map;
    int nb_tokens;
}infos;

int moov_g2(char *map, infos *tokens, int nb_movements, int size_line);
