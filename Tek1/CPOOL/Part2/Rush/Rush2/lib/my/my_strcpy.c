/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** my_strcpy
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int src_size = my_strlen(src);

    while (i < src_size) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
