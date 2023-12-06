/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** my_str_isprintable
*/

int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int i = 0;
    int occurence = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32)
            occurence++;
        i++;
    }
    if (occurence == my_strlen(str))
        return 1;
    return 0;
}
