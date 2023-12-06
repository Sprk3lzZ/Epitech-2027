/*
** EPITECH PROJECT, 2022
** my_compute_power_it
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nb, int p)
{
    int result = 1;
    int x;

    if (p < 0)
        return 0;
    for (int i = 1; i <= p; i++) {
        x = result * nb;
        if (result != 0 && x / result != nb)
            return 0;
        result *= nb;
    }
    return result;
}
