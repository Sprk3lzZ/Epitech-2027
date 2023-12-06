/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** my_str_isupper
*/

int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int i = 0;
    int occurence = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            occurence++;
        i++;
    }
    if (occurence == my_strlen(str))
        return 1;
    return 0;
}
