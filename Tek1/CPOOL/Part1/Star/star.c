/*
** EPITECH PROJECT, 2022
** Star Project
** File description:
** Star Project
*/

void my_putchar(char c);
void space_between(unsigned int size);
void first_crown(unsigned int size);
void rev_space_between(unsigned int size);
void second_crown(unsigned int size);
void my_putstr(char const *str);

void spaces(unsigned int size)
{
    for (int i = 0; i < size; i++)
        my_putchar(' ');
}

void branche(unsigned int size)
{
    spaces(size * 3 - 1);
    my_putchar('*');
    my_putchar('\n');
    space_between(size);
}

void line(unsigned int size)
{
    for (int i = 0; i <= size * 2; i++)
        my_putchar('*');
    spaces(size * 2 - 3);
    for (int i = 0; i <= size * 2; i++)
        my_putchar('*');
    my_putchar('\n');
}

void one_star(unsigned int size)
{
    my_putstr("   *");
    my_putchar('\n');
    my_putstr("*** ***");
    my_putchar('\n');
    my_putstr(" *   *");
    my_putchar('\n');
    my_putstr("*** ***");
    my_putchar('\n');
    my_putstr("   *");
    my_putchar('\n');
}

void star(unsigned int size)
{
    if (size == 1) {
        one_star(size);
    } else if (size == 0)
        return;
    else {
        branche(size);
        line(size);
        first_crown(size);
        second_crown(size);
        line(size);
        rev_space_between(size);
    }
}

int main(void)
{
    star(5);
}
