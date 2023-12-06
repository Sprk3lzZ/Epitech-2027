/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int s1_size = my_strlen(s1);

    if (n == 0)
        return 0;
    while (s1[i] == s2[i] && i < s1_size && i < n - 1)
        i++;
    return s1[i] - s2[i];
}
