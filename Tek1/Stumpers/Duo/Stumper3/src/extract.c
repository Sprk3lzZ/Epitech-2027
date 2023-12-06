/*
** EPITECH PROJECT, 2023
** extract.c
** File description:
** extract.c
*/

#include "cesar.h"

void extract_condition(int bytes_read, char *buf, int outfile)
{
    if (write(outfile, buf, bytes_read) == -1) {
        perror("Error writing to file");
        exit(84);
    }
}

void extract_condition_string(char *encrypted, int outfile)
{
    if (write(outfile, encrypted, strlen(encrypted)) == -1) {
        perror("Error writing to file");
        exit(84);
    }
}

int negative_key(int key)
{
    while (key < 0) {
        key = 26 + (key % 26);
    }
    return (key);
}
