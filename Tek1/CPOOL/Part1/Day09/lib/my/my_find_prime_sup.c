/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i;

    for (i = nb; !my_is_prime(i); i++) {
        continue;
    }
    return i;
}
