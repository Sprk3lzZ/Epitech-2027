/*
** EPITECH PROJECT, 2022
** my_getnbr_base2
** File description:
** my_getnbr_base2
*/

int is_in_base(char c, char const *base)
{
    int i = 0;
    while (base[i] != '\0') {
        if (c == base[i])
            return 1;
        i++;
    }
    return 0;
}

int get_base_indice(char c, char const *base)
{
    int i = 0;
    while (base[i] != '\0') {
        if (base[i] == c)
            return i;
        i++;
    }
    return;
}
