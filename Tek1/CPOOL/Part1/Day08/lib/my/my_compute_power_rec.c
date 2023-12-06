/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    else {
        int x = my_compute_power_rec(nb, p - 1);
        int y = x * nb;
        if (y != 0 && y / nb != x)
            return 0;
        return y;
    }
}
