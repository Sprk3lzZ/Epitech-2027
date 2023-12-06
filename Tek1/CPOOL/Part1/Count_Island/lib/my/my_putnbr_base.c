/*
** EPITECH PROJECT, 2022
** my_putnbr_base
** File description:
** my_putnbr_base
*/

void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int size_base = my_strlen(base);

    if (size_base <= 1)
        return 0;
    if (nbr >= 0 && nbr <= size_base - 1) {
        my_putchar(base[nbr]);
        return 0;
    }
    if (nbr < 0) {
        my_putchar('-');
        if (nbr == -2147483648) {
            my_putnbr_base(-(nbr / size_base), base);
            return my_putnbr_base(-(nbr % size_base), base);
        }
        return my_putnbr_base(-nbr, base);
    }
    my_putnbr_base(nbr / size_base, base);
    return my_putnbr_base(nbr % size_base, base);
}
