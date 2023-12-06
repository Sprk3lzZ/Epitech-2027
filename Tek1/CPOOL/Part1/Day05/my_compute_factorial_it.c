/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;
    int value;
    if (nb < 0 || nb == 13)
        return 0;
    for (int value = 1; value <= nb; value++)
        result *= value;
    return result;
}
