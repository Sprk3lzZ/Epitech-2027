/*
** EPITECH PROJECT, 2022
** my_print_comb
** File description:
** my_print_comb
*/

void my_putchar(char c);

void other_loop(char i, char j)
{
    for (char k = j + 1; k <= '9'; k++) {
        if ( i == '7' && k == '9') {
            my_putchar(i);
            my_putchar(j);
            my_putchar(k);
        } else {
            my_putchar(i);
            my_putchar(j);
            my_putchar(k);
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb(void)
{
    for (char i = '0'; i <= '7'; i++) {
        for (char j = i + 1; j <= '8'; j++) {
            other_loop(i, j);
        }
    }
    return 0;
}
