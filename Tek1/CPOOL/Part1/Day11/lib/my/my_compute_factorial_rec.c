/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec
** File description:
** my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return 1;
    if (nb < 0 || nb == 13)
        return 0;
    else
        return nb * my_compute_factorial_rec(nb -1);
}
