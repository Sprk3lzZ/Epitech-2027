/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** my_str_islower
*/

int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;
    int occurence = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            occurence++;
        i++;
    }
    if (occurence == my_strlen(str))
        return 1;
    return 0;
}
