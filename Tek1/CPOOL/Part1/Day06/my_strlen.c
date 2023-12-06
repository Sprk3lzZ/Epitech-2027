/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int occurence = 0;
    for (int i = 0; str[i] != '\0'; i++)
        occurence++;
    return occurence;
}
