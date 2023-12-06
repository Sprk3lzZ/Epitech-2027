/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** my_revstr
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int a;
    int b;
    char *rev_str = str;
    int str_size = my_strlen(str);

    for (int i = 0; i < str_size / 2; i++) {

        b = str[str_size - i - 1];
        a = str[i];
        rev_str[i] = b;
        rev_str[str_size - i - 1] = a;
    }
    return rev_str;
}
