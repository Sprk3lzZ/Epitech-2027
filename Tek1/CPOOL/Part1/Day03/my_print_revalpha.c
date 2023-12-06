/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** my_print_revalpha
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char i = 'z'; i >= 'a'; i--) {
        my_putchar(i);
    }
    return 0;
}
