/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr
*/

void my_putchar(char c);

void my_minimum(void)
{
    my_putchar('2');
    my_putchar('1');
    my_putchar('4');
    my_putchar('7');
    my_putchar('4');
    my_putchar('8');
    my_putchar('3');
    my_putchar('6');
    my_putchar('4');
    my_putchar('8');
}

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
        return 1;
    }
    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_minimum();
            return 11;
        }
        return 1 + my_put_nbr(-nb);
    }
    count += my_put_nbr(nb / 10);
    return count + my_put_nbr(nb % 10);
}
