/*
** EPITECH PROJECT, 2022
** my_getnbr_base
** File description:
** my_getnbr_base
*/

void my_putchar(char c);
int my_strlen(char const *str);
int is_in_base(char c, char const *base);
int get_base_indice(char c, char const *base);

int get_first_indice(char const *str, char const *base)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_in_base(str[i], base))
            return i;
        i++;
    }
    return 0;
}

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    else {
        int x = my_compute_power_rec(nb, p - 1);
        int y = x * nb;
        if (y != 0 && y / nb != x)
            return 0;
        return y;
    }
}

unsigned int get_digit_count(char const *str, char const *base)
{
    unsigned int count = 0;
    unsigned int pos = get_first_indice(str, base);

    while (is_in_base(str[pos], base)) {
            count++;
            pos++;
        }
    return count;
}

unsigned int get_sign_count(char const *str, char const *base)
{
    unsigned int negative_sign_count = 0;
    int base_size = my_strlen(base);
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '-')
            negative_sign_count++;
        if (str[i] != '+' && str[i] != '-')
            break;
    }
    return negative_sign_count;
}

int my_getnbr_base(char const *str, char const *base)
{
    int number = -1;
    int i = 0;
    int base_size = my_strlen(base);
    unsigned int negative_sign_count = get_sign_count(str, base);
    unsigned int digit_count = get_digit_count(str, base);
    unsigned int pos = get_first_indice(str, base);

    while (i < digit_count) {
        int power = my_compute_power_rec(base_size, digit_count - 1 - i);
        number -= get_base_indice(str[pos], base) * power;
        i++;
        pos++;
    }
    if (negative_sign_count % 2 == 0)
        return -number - 1;
    return number + 1;
}
