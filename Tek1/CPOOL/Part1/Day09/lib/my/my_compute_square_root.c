/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** my_compute_square_root
*/

static int my_square_prime(int nb)
{
    int i = 0;
    int j = 0;

    for (; i * i > nb; i++)
        j = i * i;
    if (j >= nb)
        return 1;
    return 0;
}

int my_compute_square_root(int nb)
{
    int i = 0;

    for (; i * i != nb; i++) {
        if (i * i > nb || nb < 0 || my_square_prime(nb))
            return 0;
    }
    return i;
}
