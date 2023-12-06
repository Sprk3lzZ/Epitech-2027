/*
** EPITECH PROJECT, 2022
** rush2
** File description:
** rush2
*/

#include "my.h"

int char_lowcase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int get_number_letter(char *str)
{
    int nb_letter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            nb_letter++;
    }
    return nb_letter;
}

int occurence_letter(char c, char *str)
{
    int occurence = 0;
    char low = char_lowcase(c);

    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == low)
            occurence++;
    }
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(occurence);
    return occurence;
}

int ret_occurence_letter(char c, char *str)
{
    int occurence = 0;
    char low = char_lowcase(c);

    my_strlowcase(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == low)
            occurence++;
    }
    return occurence;
}

int ret_percentage(char c, char *str)
{
    float percentage = 0;
    int occurence = ret_occurence_letter(c, str);
    int nb_letter = get_number_letter(str);

    percentage = ((float)occurence / (float)nb_letter) * 100.0f;

    return percentage;
}
