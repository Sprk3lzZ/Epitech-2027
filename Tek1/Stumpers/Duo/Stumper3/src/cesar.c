/*
** EPITECH PROJECT, 2023
** cesar.c
** File description:
** cesar.c
*/

#include "cesar.h"

char encrypt_char(char c, int key)
{
    if (c >= 'a' && c <= 'z') {
        c = ((c - 'a') + key) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
        c = ((c - 'A') + key) % 26 + 'A';
    }
    return (c);
}

int set_outfile(char *filename)
{
    int outfile;

    outfile = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
        S_IRUSR | S_IRGRP | S_IROTH);
    return (outfile);
}

void encrypt_file(char *filename, int key)
{
    char *outfilename = "crypt";
    int infile = open(filename, O_RDONLY);
    int outfile = set_outfile(outfilename);
    struct stat file_stat;
    mode_t mode = S_IRUSR | S_IRGRP | S_IROTH;
    char buf[1024];
    int bytes_read;

    create_outputfile(outfile);
    get_input_filesize(infile, file_stat);
    while ((bytes_read = read(infile, buf, sizeof(buf))) > 0) {
        for (int i = 0; i < bytes_read; i++)
            buf[i] = encrypt_char(buf[i], key);
        extract_condition(bytes_read, buf, outfile);
    }
    set_readonly_permissions(outfilename, mode);
    close_files(infile, outfile);
}

void encrypt_string(char *str, int key)
{
    char *outfilename = "crypt";
    int outfile;
    mode_t mode;
    char encrypted[strlen(str) + 1];

    for (int i = 0; i < (int)(strlen(str)); i++)
        encrypted[i] = encrypt_char(str[i], key);
    encrypted[strlen(str)] = '\0';
    outfile = set_outfile(outfilename);
    create_outputfile(outfile);
    extract_condition_string(encrypted, outfile);
    mode = S_IRUSR | S_IRGRP | S_IROTH;
    set_readonly_permissions(outfilename, mode);
    if (close(outfile) == -1) {
        perror("Error closing file");
        exit(84);
    }
}

int main(int argc, char **argv)
{
    int key;

    if (argc != 4 || (strcmp(argv[1], "-f") != 0 &&
        strcmp(argv[1], "-s") != 0)) {
        write(2,
        "Usage: ./cesar -f filename key OR ./cesar -s \"string\" key\n",
        59);
        exit(84);
    }
    key = atoi(argv[3]);
    if (key < 0)
        key = negative_key(key);
    else
        key = key % 26;
    if (strcmp(argv[1], "-f") == 0)
        encrypt_file(argv[2], key);
    else
        encrypt_string(argv[2], key);
    return 0;
}
