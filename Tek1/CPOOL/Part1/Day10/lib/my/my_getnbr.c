/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

void my_putchar(char c);
int my_strlen(char const *str);

static int get_first_digit_position(char const *str)
{
    unsigned int position = 0;
    int length = my_strlen(str);
    unsigned int i;

    for (i = 0; i <= length; i++) {
        if (str[i] == '-' || str[i] == '+')
            position++;
        else
            break;
    }
    for (; i <= length; i++) {
        if (str[i] == '0')
            position++;
        else
            break;
    }
    return position;
}

static int get_digit_count(char const *str)
{
    unsigned int count = 0;
    unsigned int pos = get_first_digit_position(str);

    for (unsigned int i = pos; str[i] <= '9' && str[i] >= '0'; i++)
        count++;
    return count;
}

static char test_overflow(char const *str, int sign)
{
    char *max = "2147483648";
    unsigned int digit_count = get_digit_count(str);
    unsigned int pos = get_first_digit_position(str);

    if (sign % 2 == 0)
        max = "2147483647";
    if (digit_count > 10)
        return 1;
    for (unsigned int i = 0; i < 10; i++) {
        if (str[pos + i] > max[i])
            return 1;
    }
    return 0;
}

static int get_sign_count(char const *str)
{
    unsigned int negative_sign_count = 0;
    int length = my_strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '-')
            negative_sign_count++;
        if (str[i] != '+' && str[i] != '-')
            break;
    }
    return negative_sign_count;
}

int my_getnbr(char const *str)
{
    int number = 0;
    unsigned int negative_sign_count = get_sign_count(str);
    unsigned int digit_count = get_digit_count(str);
    unsigned int pos = get_first_digit_position(str);

    for (int i = pos; str[i] <= '9' && str[i] >= '0'; i++) {
        number *= 10;
        if (negative_sign_count % 2 == 0)
            number += (str[i] - 48);
        else
            number -= (str[i] - 48);
    }
    if (digit_count >= 10 && test_overflow(str, negative_sign_count))
        return 0;
    return number;
}
