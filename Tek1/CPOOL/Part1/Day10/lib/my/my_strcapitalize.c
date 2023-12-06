/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** my_strcapitalize
*/

static char *my_strlowcase_char_only(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    str = my_strlowcase_char_only(str);
    if (str[i] >= 97 && str[i] <= 122)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (str[i - 1] > 31 && str[i - 1] < 48 && str[i] > 96 && str[i] < 123)
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}
