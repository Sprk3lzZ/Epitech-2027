/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <unistd.h>
#include "rush3.h"
#define BUFF_SIZE 30000

int main()
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;

    while ((len = read(0 , buff + offset , BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    printf("%s", buff);
    return (0);
}
