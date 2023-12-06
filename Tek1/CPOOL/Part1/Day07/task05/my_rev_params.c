/*
** EPITECH PROJECT, 2022
** my_print_params
** File description:
** my_print_params
*/

void my_putchar(char c);
int my_putstr(char const *str);

int main(int argc, char **argv)
{
    int i = argc - 1;

    while (i >= 0) {
        my_putstr(argv[i]);
        my_putchar('\n');
        i--;
    }
    return 0;
}
