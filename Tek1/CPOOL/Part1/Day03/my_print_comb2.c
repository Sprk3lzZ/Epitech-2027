/*
** EPITECH PROJECT, 2022
** my_print_comb2
** File description:
** my_print_comb2
*/

void my_putchar(char c);

void my_print_number(int number)
{
    my_putchar(number / 10 + 48);
    my_putchar(number % 10 + 48);
}

void condition(int i, int j)
{
    if (i == 98 && j == 99) {
        my_print_number(i);
        my_putchar(' ');
        my_print_number(j);
    } else {
        my_print_number(i);
        my_putchar(' ');
        my_print_number(j);
        my_putchar(',');
        my_putchar(' ');

    }
}

int my_print_comb2(void)
{
    for (int i = 0; i <= 98; i++) {
        for (int j = i + 1; j <= 99; j++) {
            condition(i, j);
        }
    }
    return 0;
}
