/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;
    if (str == 0)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}
