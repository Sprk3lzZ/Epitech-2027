/*
** EPITECH PROJECT, 2022
** bsq.h
** File description:
** Header of bsq.h
*/

#pragma once

int my_getnbr(char const *str);
int my_strlen(char const *str);
int get_size_line(char *map);
int get_nb_line(char *map);
int get_minimum(int a, int b, int c);
int get_maximum(int a, int b);
int get_index(int *array, char *map);
int my_putnbr(int nb);
int error_handling(char *map);
int size_line_equal(char *map);
char *generate(int size, char *pattern);
char *mapping(int argc, char **argv, int *nblines, char **map);
int *numerical_transformation(char *map, int nb_lines);
int *algo_transformation_array_int(char *map, int nb_lines);
void replace_map(int *array, char *map);
