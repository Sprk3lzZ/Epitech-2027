/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int s1_size = my_strlen(s1);

    while (s1[i] == s2[i] && i < s1_size)
        i++;
    return s1[i] - s2[i];
}
