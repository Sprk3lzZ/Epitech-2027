/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** my_strncpy
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int src_size = my_strlen(src);

    while (i < src_size && i < n) {
        dest[i] = src[i];
        i++;
    }
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
