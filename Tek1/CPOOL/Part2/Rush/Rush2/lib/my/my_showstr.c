/*
** EPITECH PROJECT, 2022
** my_showstr
** File description:
** my_showstr
*/

int my_str_isprintable(char const *str);
int my_putchar(char c);
int my_putnbr_base(int nbr, char const *str);

static int conditional_bloc(char const *str, int i)
{
    if (str[i] < 16)
        my_putchar('0');
}

int my_showstr(char const *str)
{
    int i = 0;
    char *hexa_base = "0123456789abcdef";
    char k[2];
    k[1] = '\0';

    while (str[i] != '\0') {
        k[0] = str[i];
        if (!my_str_isprintable(k)) {
            my_putchar('\\');
            conditional_bloc(str, i);
            my_putnbr_base(str[i], hexa_base);
        } else
            my_putchar(str[i]);
        i++;
    }
    return 0;
}
