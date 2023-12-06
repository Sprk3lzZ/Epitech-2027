/*
** EPITECH PROJECT, 2023
** cesar.h
** File description:
** cesar.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void create_outputfile(int outfile);
void get_input_filesize(int infile, struct stat file_stat);
int open_file(char *filename);
void close_files(int infile, int outfile);
void set_readonly_permissions(char *outfilename, mode_t mode);

void extract_condition(int bytes_read, char *buf, int outfile);
void extract_condition_string(char *encrypted, int outfile);
int negative_key(int key);
