/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** my_print_alpha
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    for (char i = 'a'; i <= 'z'; i++) {
        my_putchar(i);
    }
    return 0;
}
