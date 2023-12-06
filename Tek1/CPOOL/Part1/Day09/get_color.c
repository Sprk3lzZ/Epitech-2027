/*
** EPITECH PROJECT, 2022
** get_color
** File description:
** get_color
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int color = 0;

    color += red << 16;
    color += green << 8;
    color += blue;
    return color;
}
