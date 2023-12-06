/*
** EPITECH PROJECT, 2022
** Star Project
** File description:
** Star Project
*/

void my_putchar(char c);
void spaces(unsigned int size);

void space_between(unsigned int size)
{
    int space = 1;
    int side_space = size * 3 - 1;
    for (int i = 1; i < size; i++) {
        spaces(side_space - 1);
        my_putchar('*');
        spaces(space);
        space += 2;
        my_putchar('*');
        side_space -= 1;
        my_putchar('\n');
    }
}

void rev_space_between(unsigned int size)
{
    int space = size * 2 - 3;
    int side_space = size * 3 - 1;
    for (int i = 1; i < size; i++) {
        spaces(side_space - (size - 1));
        my_putchar('*');
        spaces(space);
        space -= 2;
        my_putchar('*');
        side_space += 1;
        my_putchar('\n');
    }
    spaces(size * 3 - 1);
    my_putchar('*');
    my_putchar('\n');
}

void first_crown(unsigned int size)
{
    int space = (1 +(2 * size - 1 - 2) + ( size * 2 - 1) * 2);
    int side_space = 1;
    for (int i = 0; i < size; i++) {
        spaces(side_space);
        my_putchar('*');
        spaces(space - 1);
        space -= 2;
        my_putchar('*');
        side_space += 1;
        my_putchar('\n');
    }
}

void second_crown(unsigned int size)
{
    int side_space = size - 1;
    int space = size * 4 - 1;
    for (int i = 0; i < size - 1; i++) {
        spaces(side_space);
        my_putchar('*');
        spaces(space);
        space += 2;
        my_putchar('*');
        side_space--;
        my_putchar('\n');
    }
}
