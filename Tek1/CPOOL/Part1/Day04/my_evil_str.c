/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** my_evil_str
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int a;
    int b;
    char *rev_str = str;
    for (int i = 0; i < my_strlen(str) / 2; i++) {

        b = str[my_strlen(str) - i - 1];
        a = str[i];
        rev_str[i] = b;
        rev_str[my_strlen(str) - i - 1] = a;
    }
    return rev_str;
}
