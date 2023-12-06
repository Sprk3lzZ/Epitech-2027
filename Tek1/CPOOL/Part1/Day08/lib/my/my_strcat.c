/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_size = my_strlen(dest);

    while (src[i] != '\0') {
        dest[dest_size + i] = src[i];
        i++;
    }
    dest[dest_size + i] = '\0';
    return dest;
}
