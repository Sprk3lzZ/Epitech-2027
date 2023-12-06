/*
** EPITECH PROJECT, 2022
** my_print_combn
** File description:
** my_print_combn
*/

void my_putchar(char c);
void my_put_nbr(int nb);

int maxi_comb(int n)
{
    int power = 1;
    int result = 0;

    for (int i = 0; i < n - 1; ++i)
        power = power * 10;
    for (int i = 0; i < n; ++i) {
        result += power * (10 - n + i);
        power = power / 10;
    }
    return result;
}

int it_is_comb(int n)
{
    int last_digit = n % 10;
    int current_digit = 0;

    do {
        n /= 10;
        current_digit = n % 10;
        if (last_digit <= current_digit)
            return 0;
        last_digit = current_digit;
    } while (n > 0);
    return 1;
}

int mini_comb(int n)
{
    int power = 1;
    int result = 0;

    for (int i = 0; i < n; ++i) {
        result += ((n - 1) - i) * power;
        power = power * 10;
    }
    return result;
}

void display_comb(int n, int number, int maximum_range)
{
    int power = 1;

    for (int i = 1; i < n; ++i)
        power = power * 10;
    if (number < power)
        my_put_nbr(0);
    if (number > 0)
        my_put_nbr(number);
    if (number < maximum_range) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_combn(int n)
{
    int maximum = maxi_comb(n);
    int minimum = mini_comb(n);

    for (int i = minimum; i <= maximum; ++i) {
        if (n == 1 && i == 0) {
            my_putchar('0');
            my_putchar(',');
            my_putchar(' ');
        }
        if (it_is_comb(i))
            display_comb(n, i, maximum);
    }
    return 0;
}
