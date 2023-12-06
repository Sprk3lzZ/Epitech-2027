/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** utils.c
*/

#include "cesar.h"

int open_file(char *filename)
{
    int infile = open(filename, O_RDONLY);

    if (infile == -1) {
        perror("Error opening file");
        exit(84);
    }
    return (infile);
}

void create_outputfile(int outfile)
{
    if (outfile == -1) {
        perror("Error creating file (Remove crypt file)");
        exit(84);
    }
}

void get_input_filesize(int infile, struct stat file_stat)
{
    if (fstat(infile, &file_stat) == -1) {
        perror("Error getting file size");
        exit(84);
    }
}

void close_files(int infile, int outfile)
{
    if (close(infile) == -1 || close(outfile) == -1) {
        perror("Error closing file");
        exit(84);
    }
}

void set_readonly_permissions(char *outfilename, mode_t mode)
{
    if (chmod(outfilename, mode) == -1) {
        perror("Error setting file permissions");
        exit(84);
    }
}
