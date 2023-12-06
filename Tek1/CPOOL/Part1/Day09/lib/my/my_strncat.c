/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int	i = 0;
    int	dest_size = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[dest_size + i] = src[i];
        i++;
    }
    dest[dest_size + i] = '\0';
    return dest;
}
