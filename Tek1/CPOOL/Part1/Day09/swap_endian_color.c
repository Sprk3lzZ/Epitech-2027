/*
** EPITECH PROJECT, 2022
** swap_endian_color
** File description:
** swap_endian_color
*/

union byte_un {
    int color;
    char byte[4];
};

int swap_endian_color(int color)
{
    union byte_un color_swap1;
    union byte_un color_swap2;

    color_swap1.color = color;
    color_swap2.byte[0] = color_swap1.byte[3];
    color_swap2.byte[1] = color_swap1.byte[2];
    color_swap2.byte[2] = color_swap1.byte[1];
    color_swap2.byte[3] = color_swap1.byte[0];
    return color_swap2.color;
}
