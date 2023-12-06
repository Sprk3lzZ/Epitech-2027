/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/

int my_strlen(char const *str);

static char found(char *str, char const *to_find, int i)
{
    for (unsigned int j = 0; to_find[j] != '\0'; j++) {
        if (str[i] != to_find[j])
            return 0;
        i++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    if (my_strlen(to_find) == 0)
        return str;
    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if (found(str, to_find, i))
            return &str[i];
    }
    return 0;
}
