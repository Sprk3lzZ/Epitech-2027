/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include "stdlib.h"

static int char_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;

}

static int char_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int number_word_found(char *str)
{
    int i = 0;
    char flag = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (!flag && (char_isalpha(str[i]) || char_isnum(str[i]))) {
            flag = 1;
            nb++;
        }
        if (flag && (!char_isalpha(str[i]) && !char_isnum(str[i]))) {
            flag = 0;
        }
        i++;
    }
    return nb;
}

static int word_size(char const *str, int i)
{
    int size_word = 0;

    for (i; char_isalpha(str[i]) == 1 || char_isnum(str[i]) == 1; i++)
        size_word++;
    return size_word;
}

char **my_str_to_word_array(char const *str)
{
    int i = 0, j = 0, k = 0;
    char **dest;
    char *temp;

    dest = malloc(sizeof(char *) * (my_strlen(str) + 1));
    for (i ; str[i] != '\0' && k < number_word_found(str); i++) {
        temp = malloc(sizeof(char) * (word_size(str, i) + 1));
        for (; char_isalpha(str[i]) == 1 || char_isnum(str[i]) == 1; j++) {
            temp[j] = str[i];
            i++;
        }
        if (j > 0) {
        temp[j] = '\0';
            dest[k] = temp;
            k++;
        }
        j = 0;
    }
    dest[k] = 0;
    return dest;
}
